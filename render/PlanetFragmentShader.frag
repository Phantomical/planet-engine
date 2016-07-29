#version 330

smooth in float height;

out vec3 colour;

void main()
{
	colour = vec3(height, 0.0, 0.0);
}
