#version 430

/*
	This shader program transforms a bit vector histogram
	produced by rmdup-1.glsl and transforms it into an 
	unordered sequence of integers with no duplicates.
*/

layout(local_size_x = 128) in;

layout(location = 0) uniform uint size;

layout(binding = 0, offset = 0) atomic_uint output_size;

// Result buffer
layout(binding = 0) writeonly buffer OutputBuffer
{
	uint values[];
};
layout(binding = 1) readonly buffer Histogram
{
	uint bitvals[];
};

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	// Extract bit
	uint bit = bitvals[gl_GlobalInvocationID.x / 32] & (1 << (gl_GlobalInvocationID.x % 32));

	// Check if there is a value at the current index
	if (bit != 0)
	{
		uint index = atomicCounterIncrement(output_size);
		values[index] = glGlobalInvocationID.x;
	}
}
