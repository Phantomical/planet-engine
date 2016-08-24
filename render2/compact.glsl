#version 430

layout(local_size_x = 16) in;

layout(location = 0) uniform uint size;
layout(location = 1) uniform uint scale;

layout(binding = 0) buffer Inputs
{
	float inputs[];
};
layout(binding = 1) buffer Outputs
{
	float outputs[];
};

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	outputs[gl_GlobalInvocationID.x] = inputs[gl_GlobalInvocationID.x * scale];
}
