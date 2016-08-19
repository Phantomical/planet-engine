#version 430

layout(local_size_x = 1) in;

#include "patch_data.h"
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

const dvec3 pos = _pos.xyz;
const dvec3 nwc = _nwc.xyz;
const dvec3 nec = _nec.xyz;
const dvec3 swc = _swc.xyz;
const dvec3 sec = _sec.xyz;
const double planet_radius = _pos.w;
const double skirt_depth = _nwc.w;
const double scale = _nec.w;

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	dvec3 nrm = normalize(patches[gl_GlobalInvocationID.x].pos);
	actual_pos = nrm * (noise(nrm) + planet_radius);
}
