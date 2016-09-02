#version 430

layout(binding = 0, std430) buffer VisibilityOutput
{
	uint visible[];
};

flat in uint bufferOffset;

void main()
{
	atomicExchange(visible[bufferOffset], 1);
}
