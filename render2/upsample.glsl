#version 430

layout(local_size_x = 128) in;

layout(location = 0) uniform uint SIDE_LEN;

layout(binding = 0, std140) uniform GeneratorInputs
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};
layout(binding = 1, std140) uniform SubPositions
{
	// Order: NW, NE, SW, SE
	dvec4 positions[4];
};

layout(binding = 0) writeonly restrict buffer Output
{
	float values[];
};
layout(binding = 1) readonly restrict buffer Submesh
{
	float values[];
} meshes[4]; // Order NW, NE, SW, SE

const uint size = SIDE_LEN * SIDE_LEN + 4 * SIDE_LEN;
const uint hsl = SIDE_LEN / 2;

const dvec3 pos = _pos.xyz;
const dvec3 nwc = _nwc.xyz;
const dvec3 nec = _nec.xyz;
const dvec3 swc = _swc.xyz;
const dvec3 sec = _sec.xyz;
const double planet_radius = _pos.w;
const double skirt_depth = _nwc.w;
const double scale = _nec.w;
const double INTERP = (1.0 / double(SIDE_LEN - 1));

const uint WorkGroupIndex = gl_WorkGroupID.z * gl_NumWorkGroups.x * gl_NumWorkGroups.y
+ gl_WorkGroupID.y * gl_NumWorkGroups.x + gl_WorkGroupID.x;
const uint GlobalInvocationIndex = WorkGroupIndex * gl_WorkGroupSize.x * gl_WorkGroupSize.y
* gl_WorkGroupSize.z + gl_LocalInvocationIndex;

struct Vertex
{
	vec3 vertex;
	vec3 normal;
	float displacement;
};

#define STRIDE 8

Vertex array_access(in uvec2 index, in uint arrayID)
{
	uint idx = dot(index, uvec2(STRIDE, SIDE_LEN * STRIDE));

	Vertex vtx;
	vtx.vertex = vec3(dvec3(
		meshes[arrayID].values[idx],
		meshes[arrayID].values[idx + 1],
		meshes[arrayID].values[idx + 2])
		+ positions[arrayID].xyz - pos);
	vtx.normal = vec3(
		meshes[arrayID].values[idx + 3],
		meshes[arrayID].values[idx + 4],
		meshes[arrayID].values[idx + 5]);
	vtx.displacement =
		meshes[arrayID].values[idx + 6];
	return vtx;
}
Vertex access_value(in uvec2 index)
{
	uint cond = (index.x < hsl) + (index.y < hsl) * 2;

	switch (cond)
	{
	case 0: // NW Quadrant
		return array_access(index * 2, 0);
	case 1: // NE Quadrant
		return array_access((index - uvec2(hsl, 0)) * 2, 1);
	case 2: // SW Quadrant
		return array_access((index - uvec2(0, hsl)) * 2, 2);
	case 3:
		return array_access((index - uvec2(hsl)) * 2, 3);
	}
}

void main()
{
	const uint SL2 = SIDE_LEN * SIDE_LEN;
	const uint index = GlobalInvokationIndex;

	Vertex vtx;

	if (index < SL2)
		// Get the values from the subpatches of this patch
	{
		uvec2 loc = uvec2(index / SIDE_LEN, index % SIDE_LEN);

		vtx = access_value(loc);
	}
	else
		// Calculate the skirt as normal
	{
		dvec3 vertex;
		if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN)
			vertex = to_sphere(mix(nwc, swc, INTERP * double(index - (SL2))));
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 2)
			vertex = to_sphere(mix(swc, sec, INTERP * double(index - (SL2 + SIDE_LEN))));
		else if (index < SIDE_LEN * SIDE_LEN + SIDE_LEN * 3)
			vertex = to_sphere(mix(nec, sec, INTERP * double(index - (SL2 + SIDE_LEN * 2))));
		else
			vertex = to_sphere(mix(nwc, nec, INTERP * double(index - (SL2 + SIDE_LEN * 3))));

		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		vtx.vertex = vec3(vertex);
		vtx.normal = vec3(normal);
		vtx.displacement = float(-skirt_depth);
	}
}
