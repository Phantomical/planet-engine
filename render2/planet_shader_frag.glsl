#version 430

layout(location = 1) uniform vec3 LightDir;

smooth in vec3 normal;
smooth in float displacement;

out vec3 Colour;

void main()
{
	vec3 col = vec3(1.0);
	if (displacement <= 0.0)
		col = vec3(0.0, 0.0, 1.0);

	Colour = col * clamp(dot(normal, -LightDir), 0.0, 1.0);
}
