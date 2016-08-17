#version 430

// TODO: Find a more portable way to get this info
#extension GL_ARB_shader_draw_parameters : enable

layout(binding = 0, std140) buffer Matrices
{
	mat4 matrices[];
};

#define DrawID gl_DrawIDARB

layout(location = 0) in vec3 in_vertex;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in float in_displacement;
layout(location = 3) in vec3 in_outdir;

//layout(location = 0) uniform uint DrawID;

smooth out vec3 normal;

void main()
{
	mat4 mvp = matrices[DrawID];

	gl_Position = mvp * vec4(in_vertex, 1.0);
	normal = in_normal;
}
