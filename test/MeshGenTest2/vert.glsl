#version 330

#extension GL_ARB_explicit_uniform_location : enable

layout(location = 0) in vec3 Vertex;
layout(location = 1) in vec3 Normal;

layout(location = 0) uniform mat4 MVP;

smooth out float displacement;
smooth out vec3 normal;

void main()
{
	vec3 vtx = Vertex;
	vtx.y = pow(vtx.y, 1);
	gl_Position = MVP * vec4(vtx, 1.0);
	//gl_Position /= gl_Position.w;
	displacement = vtx.y;
	normal = Normal;
}