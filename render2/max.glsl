#version 430

// The size of the workgroup
// this must be a power of 2
#define SIZE 128

layout (local_size_x = SIZE) in;

// The total size of the computation
layout(location = 0) uniform uint size;
layout(location = 1) uniform uint stride;

layout(binding = 0, std430) buffer Values
{
	float values[];
};

shared float temp[SIZE];

void main()
{
	uint index = gl_GlobalInvocationID.x;

	if (index < size)
		temp[gl_LocalInvocationIndex] = values[gl_GlobalInvocationID.y * stride + index];
	else
		temp[gl_LocalInvocationIndex] = 0.0;

	memoryBarrierShared();
	barrier();

	for (uint s = (gl_WorkGroupSize.x >> 1); s > 0; s >>= 1)
	{
		if (gl_LocalInvocationIndex < s)
		{
			temp[gl_LocalInvocationIndex] = max(temp[gl_LocalInvocationIndex], temp[gl_LocalInvocationIndex + s]);
		}

		memoryBarrierShared();
		barrier();
	} 

	if (gl_LocalInvocationIndex == 0)
	{
		values[gl_WorkGroupID.x] = temp[0];
	}
}

