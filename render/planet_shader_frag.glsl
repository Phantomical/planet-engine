#version 430

layout(location = 1) uniform vec3 LightDir;
layout(location = 2) uniform float angle;

smooth in vec3 normal;
smooth in float displacement;
smooth in vec3 outdir;

out vec3 Colour;

void main()
{
	vec3 col = vec3(1.0);
	if (displacement <= 0.0)
		col = vec3(0.0, 0.0, 1.0);

	Colour = col * (dot(normal, -LightDir) + sin(angle));
	Colour *= clamp((dot(outdir, -LightDir) + sin(angle + 0.2)) * 5.0, 0.0, 1.0);
}
