#version 430

layout(local_size_x = 128) in;

layout(location = 0) uniform uint SIDE_LEN;

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
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};

const dvec3 pos = _pos.xyz;
const dvec3 nwc = _nwc.xyz;
const dvec3 nec = _nec.xyz;
const dvec3 swc = _swc.xyz;
const dvec3 sec = _sec.xyz;
const double planet_radius = _pos.w;
const double skirt_depth = _nwc.w;
const double scale = _nec.w;
const double INTERP = (1.0 / double(SIDE_LEN - 1));
// Array size in the x and y direction
const uint array_size = SIDE_LEN + 2;
// Total array size
const uint size = array_size * array_size;

const uint WorkGroupIndex = gl_WorkGroupID.z * gl_NumWorkGroups.x * gl_NumWorkGroups.y
+ gl_WorkGroupID.y * gl_NumWorkGroups.x + gl_WorkGroupID.x;
const uint GlobalInvocationIndex = WorkGroupIndex * gl_WorkGroupSize.x * gl_WorkGroupSize.y
* gl_WorkGroupSize.z + gl_LocalInvocationIndex;

dvec3 to_sphere(in dvec3 v)
{
	return planet_radius * normalize(v);
}

vec4 read(in uvec2 idx)
{
	return vertices[idx.y * array_size + idx.x];
}

vec3 calc_normal(in uvec2 idx, in vec3 v)
{
	uvec2 actual = idx + uvec2(1);

	// Order N, E, S, W
	vec3 vs[4] = {
		v - read(actual - uvec2(0, 1)).xyz,
		v - read(actual + uvec2(1, 0)).xyz,
		v - read(actual + uvec2(0, 1)).xyz,
		v - read(actual - uvec2(1, 0)).xyz
	};

	vec3 nrm = vec3(0.0);

	nrm += cross(vs[0], vs[1]);
	nrm += cross(vs[1], vs[2]);
	nrm += cross(vs[2], vs[3]);
	nrm += cross(vs[3], vs[0]);

	return normalize(nrm);
}

void main()
{
#define STRIDE 8

	const uint index = GlobalInvocationIndex;

	if (index >= size)
		return;

	vec3 vertex;
	vec3 normal;
	float displacement;

	if (index < SIDE_LEN * SIDE_LEN)
	{
		uvec2 p = uvec2(index / SIDE_LEN, index % SIDE_LEN);

		vec4 result = read(p + uvec2(1));

		normal = calc_normal(p, result.xyz);
		vertex = result.xyz;
		displacement = result.w;
	}
	else
	{
		dvec3 vtx;
		if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN)
			vtx = to_sphere(mix(nwc, swc, INTERP * double(index - (SIDE_LEN * SIDE_LEN))));
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 2)
			vtx = to_sphere(mix(swc, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN))));
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 3)
			vtx = to_sphere(mix(nec, sec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 2))));
		else
			vtx = to_sphere(mix(nwc, nec, INTERP * double(index - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 3))));

		dvec3 nrm = normalize(vtx);
		vtx -= nrm * skirt_depth + pos;

		vertex = vec3(vtx);
		normal = vec3(nrm);
		displacement = float(-skirt_depth);
	}

	values[index * STRIDE + 0] = vertex.x;
	values[index * STRIDE + 1] = vertex.y;
	values[index * STRIDE + 2] = vertex.z;
	values[index * STRIDE + 3] = normal.x;
	values[index * STRIDE + 4] = normal.y;
	values[index * STRIDE + 5] = normal.z;
	values[index * STRIDE + 6] = displacement;
}
