#version 430

layout(local_size_x = 4) in;

#include "patch_data.glsl"

layout(location = 0) uniform dvec3 cam_pos;
layout(location = 1) uniform uint num_parents;

/*
	2 to_generate - generates a new patch and adds it to LeafPatches
	3 to_delete   - deletes the patch completely and removes it from LeafPatches
	4 leaf_add
	5 leaf_remove
	6 parent_add
	7 parent_remove

	to_generate take a patch_data to generate
	to_delete takes the global index within the patch buffer

	*_remove operations take the index of the patch within the current buffer
	*_add operations take the index of the patch within the global buffer
*/

layout(binding = 0) uniform atomic_uint to_generate_size;
layout(binding = 0) uniform atomic_uint to_delete_size;
layout(binding = 0) uniform atomic_uint leaf_add_size;
layout(binding = 0) uniform atomic_uint leaf_remove_size;
layout(binding = 0) uniform atomic_uint parent_add_size;
layout(binding = 0) uniform atomic_uint parent_remove_size;

layout(binding = 0, std430) readonly restrict buffer Parents
{
	uint parents[];
};
layout(binding = 1, std430) readonly restrict buffer Patches
{
	patch_data patches[];
};
layout(binding = 2, std430) writeonly restrict buffer ToGenerate
{
	patch_data to_generate[];
};
layout(binding = 3, std430) writeonly restrict buffer ToDelete
{
	uint to_delete[];
};
layout(binding = 4, std430) writeonly restrict buffer LeafsToAdd
{
	uint leaf_add[];
};
layout(binding = 5, std430) writeonly restrict buffer LeafsToRemove
{
	uint leaf_remove[];
};
layout(binding = 6, std430) writeonly restrict buffer ParentAdd
{
	uint parent_add[];
};
layout(binding = 7, std430) writeonly restrict buffer ParentRemove
{
	uint parent_remove[];
};

bool is_patch(uint idx)
{
	return idx < patches.length() && patches[idx].level != INVALID_LEVEL;
}

double length2(dvec3 v)
{
	return dot(v, v);
}
double side_length(uint idx)
{
	dvec3 diff = abs(patch[idx].nwc - patch[idx].nec);
	return max(max(diff.x, diff.y), diff.z);
}
bool should_subdivide(uint idx)
{
	double dis = patches[idx].farthest_vertex;
	if (farthest_vertex == FLT_MAX)
		dis = side_length(idx);
	return patches[idx].level < MAX_LEVEL &&
		length2(cam_pos - patches[idx].actual_pos) * MULT < dis * dis;
}
bool should_merge(uint idx)
{
	double dis = patches[idx].farthest_vertex;
	if (farthest_vertex == FLT_MAX)
		dis = side_length(idx);
	return length2(cam_pos - patches[idx].actual_pos) * MULT > dis * dis;
}

void main()
{
	if (gl_GlobalInvocationID.x >= num_parents)
		return;

	uint index = parents[gl_GlobalInvocationID.x];

	if (should_merge(index)
	{
		uint nwidx = atomicCounterIncrement(to_delete_size);
		uint neidx = atomicCounterIncrement(to_delete_size);
		uint swidx = atomicCounterIncrement(to_delete_size);
		uint seidx = atomicCounterIncrement(to_delete_size);

		uint idx5 = atomicCounterIncrement(leaf_add_size);
		uint idx6 = atomicCounterIncrement(parent_remove_size);
		uint idx7 = atomicCounterIncrement(parent_add_size)

		if (seidx >= to_delete.length()
			|| idx5 >= leaf_add.length()
			|| idx6 >= parent_remove.length()
			|| idx7 >= parent_add.length())
			return;

		to_delete[nwidx] = patches[index].nw;
		to_delete[neidx] = patches[index].ne;
		to_delete[swidx] = patches[index].sw;
		to_delete[seidx] = patches[index].se;

		leaf_add[idx5] = index;
		parent_remove[idx6] = gl_GlobalInvocationID.x;
		parent_add[idx7] = patches[index].parent;
	}
}
