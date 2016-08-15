#version 330

#extension GL_ARB_explicit_uniform_location : enable

layout(location = 1) uniform vec3 LightDir;

in float displacement;
in vec3 normal;

out vec3 Colour;

void main()
{
	Colour = vec3(clamp( dot( normal, -LightDir ), 0.0,1.0 ));
}