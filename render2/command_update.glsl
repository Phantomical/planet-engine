#version 430

layout(local_size_x = 128) in;

struct LoadCommand
{
	uint source;
	uint dest;
	uint is_new;
};

layout (location = 0) uniform uint size;

layout (binding = 0, std430) buffer CommandBuffer
{
	uint commands[];
};
layout (binding = 1, std430) buffer InputBuffer
{
	uint inputs[];
};
layout (binding = 2, std430) buffer OutputBuffer
{
	uint outputs[];
};

void main()
{
	const uint GlobalInvokationIndex = gl_GlobalInvokationID.x;

	if (GlobalInvokationIndex >= size)
		return;

	LoadCommand cmd;
	cmd.source = commands[GlobalInvocationIndex * 3];
	cmd.dest =   commands[GlobalInvocationIndex * 3 + 1];
	cmd.is_new = commands[GlobalInvocationIndex * 3 + 2];

	if (is_new != 0)
		// The value is a new draw command
	{
		outputs[cmd.dest * 5]     = inputs[cmd.source * 5];
		outputs[cmd.dest * 5 + 1] = inputs[cmd.source * 5 + 1];
		outputs[cmd.dest * 5 + 2] = inputs[cmd.source * 5 + 2];
		outputs[cmd.dest * 5 + 3] = inputs[cmd.source * 5 + 3];
		outputs[cmd.dest * 5 + 4] = inputs[cmd.source * 5 + 4];
	}
	else
		// Just zeroing out a command
	{
		outputs[cmd.dest * 5]     = 0;
		outputs[cmd.dest * 5 + 1] = 0;
		outputs[cmd.dest * 5 + 2] = 0;
		outputs[cmd.dest * 5 + 3] = 0;
		outputs[cmd.dest * 5 + 4] = 0;
	}
}
