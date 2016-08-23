#version 430

layout(location = 0) in dvec3 position;
layout(location = 1) in double radius;

out VertexData
{
	dvec3 position;
	double radius;
} result;

void main()
{
	result.position = position;
	result.radius = radius;
}
