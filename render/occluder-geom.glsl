#version 430

#define NVERTS 24
#define NTRIS (NVERTS / 3)

layout(points) in;
layout(triangle_strip, max_vertices = NVERTS) out;

layout(location = 0) uniform vec3 forward;
layout(location = 1) uniform vec3 up;
layout(location = 2) uniform dmat4 vp;

in VertexData
{
	dvec3 position;
	double radius;
} result[];

// Rotates a around b by theta radians
dvec3 rotate(dvec3 a, dvec3 b, float theta)
{
	dvec3 parallel = (dot(a, b) / dot(b, b)) * b;
	dvec3 perpendicular = a - parallel;
	dvec3 w = cross(b, perpendicular);
	double len = length(perpendicular);

	return len * ((cos(theta) / len) * perpendicular + (sin(theta) / length(w)) * w) + parallel;
}

#define PI 3.1415926535897932385

const float dtheta = 2 * PI / NTRIS;

void main()
{
	// Calculate radius from the radius of the circle
	const double radius = result[0].radius / cos(PI / NTRIS);
	float theta = 0.0;
	dvec3 start = up * radius;

	for (uint i = 0; i < NTRIS; ++i)
	{
		gl_Position = vec4(vp * dvec4(result[0].position, 1.0));
		EmitVertex();
		gl_Position = vec4(vp * dvec4(rotate(start, forward, theta) + result[0].position, 1.0));
		EmitVertex();
		theta += dtheta;
		gl_Position = vec4(vp * dvec4(rotate(start, forward, theta) + result[0].position, 1.0));
		EmitVertex();
		EndPrimitive();
	}
}
