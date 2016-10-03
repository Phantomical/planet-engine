#version 430

layout(local_size_x = 128) in;

struct CopyCommand
{
	uint source;
	uint dest;
};
struct DrawCommand
{
	uint count;
	uint instanceCount;
	uint firstIndex;
	uint baseVertex;
	uint baseInstance;
};

layout(binding = 0, std430) readonly restrict buffer CommandBuffer
{
	CopyCommand commands[];
};
layout(binding = 1, std430) readonly restrict buffer SourceBuffer
{
	DrawCommand inputs[];
};
layout(binding = 2, std430) writeonly restrict buffer OutputBuffer
{
	DrawCommand outputs[];
};

layout(location = 0) uniform uint size;

void main()
{
	if (gl_GlobalInvocationID.x >= size)
		return;

	CopyCommand cmd = commands[gl_GlobalInvocationID.x];

	outputs[cmd.dest] = inputs[cmd.source];
}
