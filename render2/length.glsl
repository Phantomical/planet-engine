#version 430

layout (local_size_x = 128) in;

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
#define STRIDE 8

	if (GlobalInvocationIndex < size)
	{
		vec3 vertex = vec3(
			values[GlobalInvocationIndex * 8 + 0],
			values[GlobalInvocationIndex * 8 + 1],
			values[GlobalInvocationIndex * 8 + 2]);

		lengths[GlobalInvocationIndex] = distance(pos, vertex);
	}
}
