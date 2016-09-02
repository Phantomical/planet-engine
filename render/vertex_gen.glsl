#version 440

layout(local_size_x = 8, local_size_y = 8) in;

layout(location = 0) uniform uint SIDE_LEN;

struct PatchInfo
{
	dvec4 _pos;
	dvec4 _nwc;
	dvec4 _nec;
	dvec4 _swc;
	dvec4 _sec;
};

layout(binding = 0, std430) writeonly buffer Output
{
	vec4 vertices[];
};

layout(binding = 0, std140) uniform GeneratorInputs
{
	PatchInfo infos[256];
};

#include "noise.glsl"

const dvec3 pos            = infos[gl_GlobalInvocationID.z]._pos.xyz;
const dvec3 nwc            = infos[gl_GlobalInvocationID.z]._nwc.xyz;
const dvec3 nec            = infos[gl_GlobalInvocationID.z]._nec.xyz;
const dvec3 swc            = infos[gl_GlobalInvocationID.z]._swc.xyz;
const dvec3 sec            = infos[gl_GlobalInvocationID.z]._sec.xyz;
const double planet_radius = infos[gl_GlobalInvocationID.z]._pos.w;
const double skirt_depth   = infos[gl_GlobalInvocationID.z]._nwc.w;
const double scale         = infos[gl_GlobalInvocationID.z]._nec.w;
const double INTERP        = (1.0 / double(SIDE_LEN - 1));
const uint array_size      = SIDE_LEN + 2;

dvec3 to_sphere(in dvec3 v)
{
	return planet_radius * normalize(v);
}

void calc_vertex(in ivec2 p, out vec3 vertex, out float displacement)
{
	double interp = INTERP * double(p.x);
	dvec3 v1 = mix(nwc, nec, interp);
	dvec3 v2 = mix(swc, sec, interp);
	dvec3 vtx = to_sphere(mix(v1, v2, INTERP * double(p.y)));
	dvec3 nrm = normalize(vtx);
	double disp = noise(nrm) * scale;
	vtx += nrm * disp - pos;

	vertex = vec3(vtx);
	displacement = float(disp);
}

void write(in uvec2 idx, in vec4 val)
{
	vertices[gl_GlobalInvocationID.z * array_size * array_size + idx.y * array_size + idx.x] = val;
}

void main()
{
	if (gl_GlobalInvocationID.x > SIDE_LEN + 2 || gl_GlobalInvocationID.y > SIDE_LEN + 2)
		// This shader doesn't have an output (it is out of bounds)
		return;

	ivec2 p = ivec2(gl_GlobalInvocationID.xy) - ivec2(1);

	vec3 vertex;
	float displacement;

	calc_vertex(p, vertex, displacement);

	write(gl_GlobalInvocationID.xy, vec4(vertex, displacement));
}
