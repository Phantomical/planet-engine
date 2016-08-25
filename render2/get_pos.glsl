#version 430

layout(local_size_x = 1) in;

struct PatchInfo
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};

layout(binding = 0, std140) uniform GeneratorInputs
{
	PatchInfo infos[256];
};
layout(binding = 0, std430) buffer PositionOutput
{
	dvec3 actual_pos[];
};

#include "noise.glsl"

const dvec3 pos = infos[gl_GlobalInvocationID.y]._pos.xyz;
const dvec3 nwc = infos[gl_GlobalInvocationID.y]._nwc.xyz;
const dvec3 nec = infos[gl_GlobalInvocationID.y]._nec.xyz;
const dvec3 swc = infos[gl_GlobalInvocationID.y]._swc.xyz;
const dvec3 sec = infos[gl_GlobalInvocationID.y]._sec.xyz;
const double planet_radius = infos[gl_GlobalInvocationID.y]._pos.w;
const double skirt_depth = infos[gl_GlobalInvocationID.y]._nwc.w;
const double scale = infos[gl_GlobalInvocationID.y]._nec.w;

void main()
{
	dvec3 nrm = normalize(pos);
	actual_pos[gl_GlobalInvocationID.y] = nrm * (noise(nrm) + planet_radius);
}
