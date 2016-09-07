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
		&& distance2(cam_pos, POS(patch) + dvec3(patch.pos_offset)) * planet.multiplier
		< patch.farthest_vertex * patch.farthest_vertex - length(cam_vel);
}
bool should_merge(in patch_data patch)
{
	return distance2(cam_pos, POS(patch) + dvec3(patch.pos_offset)) * planet.multiplier
		> patch.farthest_vertex * patch.farthest_vertex - length(cam_vel);
}

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	uint index = leaves[gl_GlobalInvocationID.x];
	patch_data patch = patches[index];

	if (should_subdivide(patch))
	{
		uint nidx = atomicCounterIncrement(subdivide_size);

		to_subdivide[nidx] = index;
	}
}
