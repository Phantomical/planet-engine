#version 430

layout(local_size_x = 16) in;

#include "patch_data.h"

layout(location = 0) uniform uint size;

layout(binding = 0, offset = 0) atomic_uint subdivide_size;
layout(binding = 0, offset = 4) atomic_uint merge_size;

layout(binding = 0) uniform PlanetData
{
	double radius;
	double skirt_depth;
	double scale;
	uint max_level;
	// Distance multiplier to scale planet subdivision
	float multiplier;
} planet;
layout(binding = 1) uniform CameraData
{
	dvec3 cam_pos;
	dvec3 cam_vel;
};
layout(binding = 2) uniform Ranges
{
	double ranges[128];
};

layout(binding = 0) buffer Patches
{
	patch_data patches[];
};
layout(binding = 1) buffer Leaves
{
	uint leaves[];
};
layout(binding = 2) buffer Parents
{
	uint parents[];
};
layout(binding = 3) buffer ToSubdivide
{
	uint to_subdivide[];
};
layout(binding = 4) buffer ToMerge
{
	uint to_merge[];
}

double length2(in dvec3 a)
{
	return dot(a, a);
}
double distance2(in dvec3 a, in dvec3 b)
{
	return length2(a - b);
}

bool should_subdivide(in patch_data patch)
{
	return patch.level < planet.max_level
		&& distance2(vec3(cam_pos - POS(patch)), dvec3(patch.pos_offset))
		- patch.farthest_vertex < ranges[patch.level];
}
bool should_merge(in patch_data patch)
{
	return patch.level < planet.max_level
		&& distance2(vec3(cam_pos - POS(patch)), dvec3(patch.pos_offset))
		- patch.farthest_vertex > ranges[patch.level];
}

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	uint index = parents[gl_GlobalInvocationID.x];
	patch_data patch = patches[index];

	if (should_merge(patch))
	{
		uint nidx = atomicCounterIncrement(merge_size);

		to_subdivide[nidx] = index;
	}
}
