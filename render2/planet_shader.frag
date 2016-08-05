#version 430

smooth in displacement;

out vec3 colour;

void main()
{
	colour = vec3(displacement, 1.0 - displacement, 0.0);
}
