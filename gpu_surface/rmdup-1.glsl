#version 430

/* 
	This shader program computes a histogram 
	from values in a shader so that a second
	stage can reassemble them without duplicates.

	This is implemented using a modified
	countingsort algorithm. Instead of counting
	the number of occurences it only indicates
	whether an occurence was found in the
	histogram. The second stage uses this to
	reassemble a vector of elements with the
	duplicate elements removed.
*/

layout(local_size_x = 128) in;

layout(location = 0) uniform uint size;

layout(binding = 0) readonly buffer InputBuffer
{
	uint values[];
};
// A histogram off all the values in the array
layout(binding = 2) buffer Histogram
{
	uint bitvals[];
};

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	uint value = values[gl_GlobalInvocationID.x];

	atomicOr(bitvals[value / 32], 1 << (value % 32));
}
