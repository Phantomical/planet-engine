#version 430

layout(location = 0) in vec3 vertex;
layout(location = 1) in mat4 MVP;

flat out uint bufferOffset;

void main()
{
	gl_Position = MVP * vec4(vertex, 1.0);
	bufferOffset = gl_InstanceID;
}