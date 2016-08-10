#include "shader.h"
#include "gl_core.h"
#include <cassert>

#pragma warning (disable : 4267)

namespace planet_engine
{
	namespace util
	{
		constexpr size_t GetTypeIndex(GLenum stage)
		{
			return
				stage == GL_VERTEX_SHADER ? 0 :
				stage == GL_FRAGMENT_SHADER ? 1 :
				stage == GL_GEOMETRY_SHADER ? 2 :
				stage == GL_TESS_CONTROL_SHADER ? 3 :
				stage == GL_TESS_EVALUATION_SHADER ? 4 :
				stage == GL_COMPUTE_SHADER ? 5 :
				std::numeric_limits<size_t>::max();
		}

		template<GLenum type>
		struct shader_type_index
		{
			static constexpr size_t index = GetTypeIndex(type);
		};

		template<GLuint idx>
		struct sti : shader_type_index<idx> { };

		shader::shader() :
			_destroy(false),
			_program(0)
		{
			std::memset(_shaders, 0, sizeof(_shaders));
			std::memset(_statuses, 0, sizeof(_statuses));
		}
		shader::shader(bool owns) :
			_destroy(owns),
			_program(glCreateProgram())
		{
			std::memset(_shaders, 0, sizeof(_shaders));
			std::memset(_statuses, 0, sizeof(_statuses));
		}
		shader::shader(shader&& sh) :
			_program(sh._program),
			_destroy(sh._destroy),
			_linker_log(std::move(sh._linker_log))
		{
			for (size_t i = 0; i < 6; ++i)
			{
				_logs[i] = std::move(sh._logs[i]);
				_shaders[i] = sh._shaders[i];
				_statuses[i] = sh._statuses[i];
				sh._shaders[i] = 0;
			}

			sh._program = 0;
		}
		shader::~shader()
		{
			if (valid())
			{
				for (size_t i = 0; i < 6; ++i)
				{
					GLuint shader = _shaders[i];
					if (shader == 0)
						continue;
					glDetachShader(_program, shader);
					glDeleteShader(shader);
				}

				if (_destroy)
				{
					glDeleteProgram(_program);
				}
			}
		}

		void shader::vertex(const std::string& source)
		{
			return vertex(source.c_str());
		}
		void shader::fragment(const std::string& source)
		{
			return fragment(source.c_str());
		}
		void shader::tess_control(const std::string& source)
		{
			return tess_control(source.c_str());
		}
		void shader::tess_evaluation(const std::string& source)
		{
			return tess_evaluation(source.c_str());
		}
		void shader::compute(const std::string& source)
		{
			return compute(source.c_str());
		}

		void shader::vertex(const char* source)
		{
			return stage(GL_VERTEX_SHADER, source);
		}
		void shader::fragment(const char* source)
		{
			return stage(GL_FRAGMENT_SHADER, source);
		}
		void shader::tess_control(const char* source)
		{
			return stage(GL_TESS_CONTROL_SHADER, source);
		}
		void shader::tess_evaluation(const char* source)
		{
			return stage(GL_TESS_EVALUATION_SHADER, source);
		}
		void shader::compute(const char* source)
		{
			return stage(GL_COMPUTE_SHADER, source);
		}

		void shader::stage(GLenum stage, const std::string& source)
		{
			return this->stage(stage, source.c_str());
		}
		void shader::stage(GLenum stage, const char* source)
		{
			const size_t index = GetTypeIndex(stage);

			assert(_shaders[index] == 0);

			GLuint shader = glCreateShader(stage);

			glShaderSource(shader, 1, &source, nullptr);
			glCompileShader(shader);

			glAttachShader(_program, shader);
			_shaders[index] = shader;

			GLint status = 0;

			glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

			if (status == GL_FALSE)
			{
				_statuses[index] = false;
				GLint maxlength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxlength);

				_logs[index].resize(maxlength);
				glGetShaderInfoLog(shader, maxlength, &maxlength, &_logs[index][0]);
				_logs[index].resize(maxlength);
			}
			else
			{
				_statuses[index] = true;
			}
		}

		void shader::transform_feedback_varyings(size_t count, const char** varyings, GLenum bufferMode)
		{
			glTransformFeedbackVaryings(_program, count, varyings, bufferMode);
		}

		void shader::link()
		{
			glLinkProgram(_program);

			GLint status = 0;
			glGetProgramiv(_program, GL_LINK_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint maxlength = 0;
				glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &maxlength);

				_linker_log.resize(maxlength);
				glGetProgramInfoLog(_program, maxlength, &maxlength, &_linker_log[0]);
				_linker_log.resize(maxlength);
				_link_status = false;
			}
			else
			{
				_link_status = true;
			}
		}

		bool shader::has_vertex() const
		{
			return _shaders[sti<GL_VERTEX_SHADER>::index] != 0;
		}
		bool shader::has_fragment() const
		{
			return _shaders[sti<GL_FRAGMENT_SHADER>::index] != 0;
		}
		bool shader::has_tess_control() const
		{
			return _shaders[sti<GL_TESS_CONTROL_SHADER>::index] != 0;
		}
		bool shader::has_tess_evaluation() const
		{
			return _shaders[sti<GL_TESS_EVALUATION_SHADER>::index] != 0;
		}
		bool shader::has_compute() const
		{
			return _shaders[sti<GL_COMPUTE_SHADER>::index] != 0;
		}
		bool shader::has_stage(GLenum stage) const
		{
			return _shaders[GetTypeIndex(stage)] != 0;
		}

		bool shader::compile_status(GLenum type) const
		{
			return _statuses[GetTypeIndex(type)];
		}
		bool shader::link_status() const
		{
			return _link_status;
		}

		GLuint shader::program()
		{
			return _program;
		}
		const std::string& shader::shader_log(GLenum shader_stage) const
		{
			return _logs[GetTypeIndex(shader_stage)];
		}
		const std::string& shader::program_log() const
		{
			return _linker_log;
		}

		bool shader::valid() const
		{
			return _program != 0;
		}

		void shader::check_errors(std::initializer_list<GLenum> stages) const
		{
			if (!valid())
				return;

			bool error = false;
			
			for (GLenum stage : stages)
			{
				if (!compile_status(stage) && has_stage(stage))
				{
					error = true;
					//printf("%s", shader_log(stage).c_str());
				}
			}

			if (!link_status())
			{
				error = true;
				printf("%s", program_log().c_str());
			}

			if (error)
			{
				__debugbreak();
				std::terminate();
			}
		}
	}
}
