#version 430

layout(local_size_x = 128) in;

#include "stride.h"

layout(location = 0) uniform uint size;
layout(location = 1) uniform uint offset_mul;

layout(binding = 0, std140) uniform Positions
{
	vec4 positions[256];
};
layout(binding = 1, std140) uniform Offsets
{
	uint offsets[256];
};

layout(binding = 0, std430) buffer MeshData
{
	float values[];
};
layout(binding = 1, std430) buffer Lengths
{
	float lengths[];
};

void main()
{
	if (gl_GlobalInvocationID.x < size)
	{
		uint baseindex = offsets[gl_GlobalInvocationID.y] * offset_mul 
			+ gl_GlobalInvocationID.x * STRIDE;

		vec3 vertex = vec3(
			values[baseindex + 0],
			values[baseindex + 1],
			values[baseindex + 2]);

		lengths[gl_GlobalInvocationID.y * size + gl_GlobalInvocationID.x] 
			= distance(positions[gl_GlobalInvocationID.y].xyz, vertex);
	}
}
