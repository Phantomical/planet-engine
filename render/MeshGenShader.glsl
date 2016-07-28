#version 430

layout(std140, binding = 0) uniform GeneratorInputs
{
	dvec4 pos;
	dvec4 nwc;
	dvec4 nec;
	dvec4 swc;
	dvec4 sec;
	double planet_radius;
	double skirt_depth;
	double scale;
};

layout(location = 0) in float unused;

#include "noise.glsl"

out vec3 out_vertex;
out vec3 out_normal;
out float out_displacement;

dvec3 to_sphere(dvec3 v)
{
	return planet_radius * normalize(v);
}

#define pos GeneratorInputs.pos.xyz
#define nwc GeneratorInputs.nwc.xyz
#define nec GeneratorInputs.nec.xyz
#define swc GeneratorInputs.swc.xyz
#define sec GeneratorInputs.sec.xyz
#define planet_radius GeneratorInputs.planet_radius
#define skirt_depth GeneratorInputs.skirt_depth
#define scale GeneratorInputs.scale

void main()
{
#define SIDE_LEN 129
#define INTERP (1.0 / (SIDE_LEN - 1))
	
	if (gl_VertexID < SIDE_LEN * SIDE_LEN)
	{
		double interp = INTERP * double(gl_VertexID / SIDE_LEN);
		dvec3 v1 = mix(nwc, nec, interp);
		dvec3 v2 = mix(swc, sec, interp);
		dvec3 vtx = to_sphere(lerp(v1, v2, INTERP * double(gl_VertexID % SIDE_LEN)));
		dvec3 normal = normalize(vtx);
		double displacement = noise(vtx) * scale;
		vtx += normal * displacement - pos;

		out_vertex = vec3(vtx);
		out_normal = vec3(normal);
		out_displacement = float(displacement);
	}
	else if (gl_VertexID < SIDE_LEN * SIDE_LEN + SIDE_LEN)
	{
		dvec3 vertex = to_sphere(lerp(nwc, swc, INTERP * (gl_VertexID - (SIDE_LEN * SIDE_LEN))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		out_vertex = vec3(vertex);
		out_normal = vec3(normal);
		out_displacement = float(-skirt_depth);
	}
	else if (gl_VertexID < SIDE_LEN * SIDE_LEN + SIDE_LEN * 2)
	{
		dvec3 vertex = to_sphere(lerp(swc, sec, INTERP * (gl_VertexID - (SIDE_LEN * SIDE_LEN + SIDE_LEN))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		out_vertex = vec3(vertex);
		out_normal = vec3(normal);
		out_displacement = float(-skirt_depth);
	}
	else if (gl_VertexID < SIDE_LEN * SIDE_LEN + SIDE_LEN * 3)
	{
		dvec3 vertex = to_sphere(lerp(nec, sec, INTERP * (gl_VertexID - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 2))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		out_vertex = vec3(vertex);
		out_normal = vec3(normal);
		out_displacement = float(-skirt_depth);
	}
	else
	{
		dvec3 vertex = to_sphere(lerp(nwc, nec, INTERP * (gl_VertexID - (SIDE_LEN * SIDE_LEN + SIDE_LEN * 3))));
		dvec3 normal = normalize(vertex);
		vertex -= normal * skirt_depth + pos;

		out_vertex = vec3(vertex);
		out_normal = vec3(normal);
		out_displacement = float(-skirt_depth);
	}
}
