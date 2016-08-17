#version 430

layout(local_size_x = 1) in;

layout(binding = 0, std140) uniform GeneratorInputs
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};
layout(binding = 0, std140) buffer PositionOutput
{
	dvec3 actual_pos;
};

#include "noise.glsl"

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
	dvec3 nrm = normalize(pos);
	actual_pos = nrm * (noise(nrm) + planet_radius);
}
