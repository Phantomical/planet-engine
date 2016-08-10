#version 430

layout(location = 1) uniform vec3 LightDir;

smooth in vec3 normal;

out vec3 Colour;

void main()
{
	Colour = vec3(clamp(dot(normal, -LightDir), 0.0, 1.0));
}
