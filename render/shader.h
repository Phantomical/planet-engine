#pragma once

#include "gl_core.h"
#include <string>

namespace planet_engine
{
	namespace util
	{
		class glsl_shader
		{
		private:
			static constexpr size_t NumShaderTypes = 6;
			// Indicates whether the program should
			// delete the program when the destructor
			// is invoked
			bool _destroy;
			// The OpenGL program ID
			GLuint _program;
			// The shader id of all the shader stages
			GLuint _shaders[NumShaderTypes];
			// The info logs from the compilation of the 
			// shader stages
			std::string _logs[NumShaderTypes];
			// The link log
			std::string _linker_log;

		public:
			glsl_shader();
			glsl_shader(bool owns);
			glsl_shader(glsl_shader&& sh);
			glsl_shader(const glsl_shader&) = delete;

			~glsl_shader();

			glsl_shader&& vertex(const char* source);
			glsl_shader&& vertex(const std::string& source);
			glsl_shader&& fragment(const char* source);
			glsl_shader&& fragment(const std::string& source);
			glsl_shader&& tess_control(const char* source);
			glsl_shader&& tess_control(const std::string& source);
			glsl_shader&& tess_evaluation(const char* source);
			glsl_shader&& tess_evaluation(const std::string& source);
			glsl_shader&& compute(const char* source);
			glsl_shader&& compute(const std::string& source);

			glsl_shader&& transform_feedback_varyings(size_t count, const char** varyings, GLenum bufferMode);

			glsl_shader&& link();

			bool has_vertex() const;
			bool has_fragment() const;
			bool has_tess_control() const;
			bool has_tess_evaluation() const;
			bool has_compute() const;

			bool valid() const;

			GLuint program();
			const std::string& shader_log(GLenum shader_stage) const;
			const std::string& program_log() const;
		};
	}
}
