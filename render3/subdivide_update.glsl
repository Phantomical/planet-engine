#version 430

layout(local_size_x = 1) in;

#include "patch_data.glsl"

layout(binding = 0, offset = 0) uniform atomic_uint add_size;
layout(binding = 0, offset = 4) uniform atomic_uint remove_size;

layout(location = 0) uniform dvec3 cam_pos;

layout(binding = 0, std430) readonly restrict buffer Patches
{
	patch_data patches[];
};
layout(binding = 1, std430) readonly restrict buffer LeafPatches
{
	uint leaves[];
};
layout(binding = 2, std430) writeonly restrict buffer ToGenerate
{
	patch_data to_add[];
};
layout(binding = 3, std430) writeonly restrict buffer ToRemove
{
	uint to_remove[];
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
	if (gl_GlobalInvocationID.x >= leaves.length())
		return;

	uint index = leaves[gl_GlobalInvocationID.x];
	if (should_subdivide(index))
	{
		uint nidx = atomicCounterIncrement(remove_size);
		uint nwidx = atomicCounterIncrement(add_size);
		uint neidx = atomicCounterIncrement(add_size);
		uint swidx = atomicCounterIncrement(add_size);
		uint seidx = atomicCounterIncrement(add_size);

		if (nidx > to_generate.length())
			return;
		if (seidx > to_generate.length())
			return;

		to_remove[nidx] = index;

		patch_data newdat = {
			INVALID_INDEX,
			INVALID_INDEX,
			INVALID_INDEX,
			INVALID_INDEX,
			dvec3(),
			dvec3(),
			dvec3(),
			dvec3(),
			patches[index].level + 1,
			index,
			FLT_MAX
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
		to_add[nwidx] = newdat;

		newdat.nwc = (nwc + nec) * 0.5;
		newdat.nec = nec;
		newdat.swc = (nwc + swc) * 0.5;
		newdat.sec = centre;
		to_add[neidx] = newdat;

		newdat.nwc = (nwc + swc) * 0.5;
		newdat.nec = centre;
		newdat.swc = swc;
		newdat.sec = (swc + sec) * 0.5;
		to_add[swidx] = newdat;

		newdat.nwc = centre;
		newdat.nec = (nec + sec) * 0.5;
		newdat.swc = (swc + sec) * 0.5;
		newdat.sec = sec;
		to_add[seidx] = newdat;
	}
}
