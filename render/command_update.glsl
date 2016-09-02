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

const uint WorkGroupIndex = gl_WorkGroupID.z * gl_NumWorkGroups.x * gl_NumWorkGroups.y
+ gl_WorkGroupID.y * gl_NumWorkGroups.x + gl_WorkGroupID.x;
const uint GlobalInvocationIndex = WorkGroupIndex * gl_WorkGroupSize.x * gl_WorkGroupSize.y
* gl_WorkGroupSize.z + gl_LocalInvocationIndex;

void main()
{
	if (GlobalInvocationIndex >= size)
		return;

	LoadCommand cmd;
	cmd.source = commands[GlobalInvocationIndex * 3];
	cmd.dest =   commands[GlobalInvocationIndex * 3 + 1];
	cmd.is_new = commands[GlobalInvocationIndex * 3 + 2];

	if (cmd.is_new == 1)
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
