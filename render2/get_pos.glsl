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
	vec4 pos_offset[];
};

#include "noise.glsl"

const dvec3 pos = infos[gl_GlobalInvocationID.y]._pos.xyz;

void main()
{
	dvec3 nrm = normalize(pos);
	pos_offset[gl_GlobalInvocationID.y].xyz = vec3(nrm * noise(nrm));
}
