#include "shader.h"
#include "appbase.h"
#include "load_file.h"

using namespace planet_engine::util;

class FanGenTest : public AppBase
{
public:
	typedef double scalar;

	static constexpr size_t bounds = 96;
	static constexpr size_t size = bounds * bounds * bounds;
	GLuint pt;
	GLuint program;

	void GenShaders()
	{
		shader prg = shader(false);
		prg.vertex(read_file("vertex.glsl"));
		prg.geometry(read_file("geometry.glsl"));
		prg.fragment(read_file("fragment.glsl"));

		prg.link();

		prg.check_errors({ GL_GEOMETRY_SHADER,GL_FRAGMENT_SHADER }, false);
		program = prg.program();
	}

	void OnLoad() override
	{
		GenShaders();

		scalar* pts = new scalar[size * 4];

		for (size_t i = 0; i < size * 4; i += 4)
		{
			size_t ctr = i / 4;

			glm::dvec4 tmp;

			pts[i + 0] = tmp.x = (ctr / (bounds * bounds));
			pts[i + 1] = tmp.y = (ctr % (bounds * bounds)) / bounds;
			pts[i + 2] = tmp.z = (ctr % (bounds));
			pts[i + 3] = tmp.w = 0.5;
		}

		glGenBuffers(1, &pt);
		glBindBuffer(GL_ARRAY_BUFFER, pt);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(scalar) * 4, pts, GL_STATIC_DRAW);

		delete[] pts;

		FarZ = 10000.0;
	}
	void OnUnload() override
	{
		glDeleteProgram(program);
		glDeleteBuffers(1, &pt);
	}

	void OnRenderFrame() override
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glUseProgram(program);

		glBindBuffer(GL_ARRAY_BUFFER, pt);

		glm::mat3 camrot = (glm::mat3)(glm::quat)CamRot;

		glm::vec3 forward = camrot * glm::vec3(0.0, 0.0, 1.0);
		glm::vec3 up = camrot * glm::vec3(0.0, 1.0, 0.0);

		glm::mat4 mat = GetVPMatrix();
		glUniformMatrix4fv(2, 1, GL_FALSE, &mat[0][0]);

		glUniform3fv(0, 1, &forward[0]);
		glUniform3fv(1, 1, &up[0]);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glVertexAttribLPointer(0, 3, GL_DOUBLE, sizeof(scalar) * 4, (void*)0);
		glVertexAttribLPointer(1, 1, GL_DOUBLE, sizeof(scalar) * 4, (void*)(sizeof(scalar) * 3));

		glDrawArrays(GL_POINTS, 0, size);
	}
	void OnUpdateFrame() override
	{
		HandleInput(0.75);
	}

	void OnShaderRecompile() override
	{
		glDeleteProgram(program);
		GenShaders();
	}

	FanGenTest() :
		AppBase("Fan Gen Test")
	{
		CamPos = glm::dvec3(0.0, 0.0, -1.0);
	}
};

void main()
{
	glfwInit();

	FanGenTest test;

	test.Run();

	glfwTerminate();
}
