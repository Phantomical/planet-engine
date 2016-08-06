#version 430

// TODO: Find a more portable way to get this info
#extension GL_ARB_shader_draw_parameters : enable

layout(binding = 0, std140) buffer Matrices
{
	mat4 matrices[];
};

#define DrawID gl_DrawIDARB

layout (location = 0) in vec3 in_vertex;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in float in_displacement;

smooth out float displacement;

void main()
{
	mat4 mvp = matrices[DrawID];

	displacement = in_displacement;
	gl_Position = mvp * vec4(in_vertex, 1.0);
}
