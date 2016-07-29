#version 430

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 texcoord;
layout(location = 2) in float displacement;

smooth out float height;

layout(location = 0) uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(vertex, 1.0);
	height = displacement;
}
