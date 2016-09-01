#version 430

#include "stride.h"

layout(local_size_x = 128) in;

layout(location = 0) uniform uint SIDE_LEN;
layout(location = 1) uniform uint offset;
layout(location = 2) uniform uint InvocationIndex;
layout(location = 3) uniform uint block_size;

struct PatchInfo
{
	dvec3 pos;
	double planet_radius;
	dvec3 nwc;
	double skirt_depth;
	dvec3 nec;
	double scale;
	dvec3 swc;
	dvec3 sec;
};


layout(binding = 0, std430) readonly buffer GeneratorOutputs
{
	vec4 vertices[];
};
layout(binding = 1, std430) writeonly buffer Results
{
	float values[];
};

layout(binding = 0, std140) uniform GeneratorInputs
{
	PatchInfo infos[256];
};
layout(binding = 1, std140) uniform Offsets
{
	uvec4 offsets[64];
};

const dvec3 pos            = infos[InvocationIndex].pos;
const dvec3 nwc            = infos[InvocationIndex].nwc;
const dvec3 nec            = infos[InvocationIndex].nec;
const dvec3 swc            = infos[InvocationIndex].swc;
const dvec3 sec            = infos[InvocationIndex].sec;
const double planet_radius = infos[InvocationIndex].planet_radius;
const double skirt_depth   = infos[InvocationIndex].skirt_depth;
const double scale         = infos[InvocationIndex].scale;
const double INTERP        = (1.0 / double(SIDE_LEN - 1));
// Array size in the x and y direction
const uint array_size      = SIDE_LEN + 2;
// Total array size
const uint num_vertices    = SIDE_LEN * SIDE_LEN + 4 * SIDE_LEN;

dvec3 to_sphere(in dvec3 v)
{
	return planet_radius * normalize(v);
}

vec4 read(in uvec2 idx)
{
	return vertices[InvocationIndex * array_size * array_size + idx.y * array_size + idx.x];
}

vec3 calc_normal(in uvec2 idx, in vec3 v)
{
	uvec2 actual = idx + uvec2(1);

	// Order N, E, S, W
	vec3 vs[] = {
		v - read(actual - uvec2(0, 1)).xyz,
		v - read(actual + uvec2(1, 0)).xyz,
		v - read(actual + uvec2(0, 1)).xyz,
		v - read(actual - uvec2(1, 0)).xyz
	};

	vec3 nrm = vec3(0.0);

	nrm += cross(vs[0], vs[1]);
	nrm += cross(vs[1], vs[2]);
	nrm += cross(vs[2], vs[0]);

	return normalize(nrm);
}

void main()
{
	const uint index = gl_GlobalInvocationID.x;

	if (!(index < num_vertices))
		return;

	vec3 vertex;
	vec3 normal;
	vec3 outdir;
	float displacement;

	if (index < SIDE_LEN * SIDE_LEN)
	{
		uvec2 p = uvec2(index / SIDE_LEN, index % SIDE_LEN);

		vec4 result = read(p + uvec2(1));

		normal = calc_normal(p, result.xyz);
		vertex = result.xyz;
		displacement = result.w;

		outdir = vec3(normalize(dvec3(vertex) + pos));
	}
	else
	{
		uvec2 p;

		dvec3 vtx;
		if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN)
		{
			vtx = to_sphere(mix(nwc, swc, INTERP * double(index - (SIDE_LEN * SIDE_LEN))));
			p = uvec2(0, index - SIDE_LEN * SIDE_LEN);
		}
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 2)
		{
			vtx = to_sphere(mix(swc, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN))));
			p = uvec2(index - SIDE_LEN * SIDE_LEN - SIDE_LEN, SIDE_LEN);
		}
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 3)
		{
			vtx = to_sphere(mix(nec, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 2))));
			p = uvec2(SIDE_LEN, (SIDE_LEN * SIDE_LEN + 2 * SIDE_LEN - index));
		}
		else
		{
			vtx = to_sphere(mix(nwc, nec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 3))));
			p = uvec2(SIDE_LEN * SIDE_LEN + 3 * SIDE_LEN - index, SIDE_LEN);
		}

		dvec3 nrm = normalize(vtx);
		vtx -= nrm * (planet_radius / 4) + pos;

		vertex = vec3(vtx);
		normal = vec3(nrm);
		outdir = normal;
		displacement = float(-skirt_depth * scale);
	}

	uint outindex = offsets[InvocationIndex / 4][InvocationIndex % 4] * block_size + index * STRIDE;

	values[outindex + 0] = vertex.x;
	values[outindex + 1] = vertex.y;
	values[outindex + 2] = vertex.z;
	values[outindex + 3] = normal.x;
	values[outindex + 4] = normal.y;
	values[outindex + 5] = normal.z;
	values[outindex + 6] = displacement;
	values[outindex + 7] = outdir.x;
	values[outindex + 8] = outdir.y;
	values[outindex + 9] = outdir.z;
}
