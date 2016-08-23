#version 430

layout(local_size_x = 4) in;

#include "patch_data.glsl"

layout(location = 0) uniform dvec3 cam_pos;
layout(location = 1) uniform uint num_leaves;

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

layout(binding = 0, std430) readonly restrict buffer Leaves
{
	uint leaves[];
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
	if (gl_GlobalInvocationID.x >= num_leaves)
		return;

	uint index = leaves[gl_GlobalInvocationID.x];

	if (index == INVALID_INDEX)
		return;

	if (should_subdivide(index))
	{
		uint nidx = atomicCounterIncrement(to_remove_size);
		uint pidx = atomicCounterIncrement(parent_add_size);
		uint ridx = atomicCounterIncrement(parent_remove_size);

		uint nwidx = atomicCounterIncrement(to_generate_size);
		uint neidx = atomicCounterIncrement(to_generate_size);
		uint swidx = atomicCounterIncrement(to_generate_size);
		uint seidx = atomicCounterIncrement(to_generate_size);

		if (nidx >= to_generate.length()
			|| seidx >= to_generate.length()
			|| pidx >= parent_add.length()
			|| ridx >= parent_remove.length())
			return;

		leaf_remove[nidx] = gl_GlobalInvocationID.x;
		parent_add[pidx] = index;
		parent_remove[ridx] = patches[patches[index].parent].index;

		patch_data newdat = {
			dvec3(),
			dvec3(),
			dvec3(),
			dvec3(),
			INVALID_INDEX,
			INVALID_INDEX,
			INVALID_INDEX,
			INVALID_INDEX,
			patches[index].level + 1,
			index,
			FLT_MAX,
			INVALID_INDEX
		};

		dvec3 centre = (nwc + nec + swc + sec) * 0.25;
		dvec3 nwc = patches[index].nwc;
		dvec3 nec = patches[index].nec;
		dvec3 swc = patches[index].swc;
		dvec3 sec = patches[index].sec;

		newdat.nwc = nec;
		newdat.nec = (nec + nec) * 0.5;
		newdat.swc = (nwc + swc) * 0.5;
		newdat.sec = centre;
		to_generate[nwidx] = newdat;

		newdat.nwc = (nwc + nec) * 0.5;
		newdat.nec = nec;
		newdat.swc = (nwc + swc) * 0.5;
		newdat.sec = centre;
		to_generate[neidx] = newdat;

		newdat.nwc = (nwc + swc) * 0.5;
		newdat.nec = centre;
		newdat.swc = swc;
		newdat.sec = (swc + sec) * 0.5;
		to_generate[swidx] = newdat;

		newdat.nwc = centre;
		newdat.nec = (nec + sec) * 0.5;
		newdat.swc = (swc + sec) * 0.5;
		newdat.sec = sec;
		to_generate[seidx] = newdat;
	}
}
