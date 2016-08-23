#version 430

layout(local_size_x = 4) in;

#include "patch_data.glsl"
#include "noise.glsl"

layout(binding = 0, std430) buffer Patches
{
	patch_data patches[];
};
layout(binding = 1, std430) buffer Inputs
{
	uint indices[];
};

layout(location = 0) uint size;

#define index gl_GlobalInvocationID.x

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	dvec3 nrm = normalize(patches[index].pos);
	patches[index].pos = nrm * (noise(nrm) + patches[index].planet_radius);
}
