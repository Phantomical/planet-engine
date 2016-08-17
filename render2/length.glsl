#version 430

layout (local_size_x = 128) in;

#include "stride.h"

const uint WorkGroupIndex = 
          gl_WorkGroupID.z * gl_NumWorkGroups.x * gl_NumWorkGroups.y +
          gl_WorkGroupID.y * gl_NumWorkGroups.x + 
          gl_WorkGroupID.x;
const uint GlobalInvocationIndex = 
		WorkGroupIndex * gl_WorkGroupSize.x * 
		gl_WorkGroupSize.y * gl_WorkGroupSize.z + 
		gl_LocalInvocationIndex;

layout(location = 0) uniform uint size;
layout(location = 1) uniform vec3 pos;
layout(location = 2) uniform uint offset;

layout (binding = 0, std430) buffer MeshData
{
	float values[];
};
layout (binding = 1, std430) buffer Lengths
{
	float lengths[];
};

void main()
{
	if (GlobalInvocationIndex < size)
	{
		vec3 vertex = vec3(
			values[offset + GlobalInvocationIndex * STRIDE + 0],
			values[offset + GlobalInvocationIndex * STRIDE + 1],
			values[offset + GlobalInvocationIndex * STRIDE + 2]);

		lengths[GlobalInvocationIndex] = distance(pos, vertex);
	}
}
