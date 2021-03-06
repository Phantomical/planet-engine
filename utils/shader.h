#pragma once

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
			bool _statuses[NumShaderTypes];
			// The link log
			std::string _linker_log;
			bool _link_status;

		public:
			glsl_shader();
			glsl_shader(bool owns);
			glsl_shader(glsl_shader&& sh);
			glsl_shader(const glsl_shader&) = delete;

			~glsl_shader();

			void vertex(const char* source);
			void vertex(const std::string& source);
			void geometry(const char* source);
			void geometry(const std::string& source);
			void fragment(const char* source);
			void fragment(const std::string& source);
			void tess_control(const char* source);
			void tess_control(const std::string& source);
			void tess_evaluation(const char* source);
			void tess_evaluation(const std::string& source);
			void compute(const char* source);
			void compute(const std::string& source);
			void stage(GLenum stage, const char* source);
			void stage(GLenum stage, const std::string& source);

			void transform_feedback_varyings(size_t count, const char** varyings, GLenum bufferMode);

			void link();

			bool has_vertex() const;
			bool has_geometry() const;
			bool has_fragment() const;
			bool has_tess_control() const;
			bool has_tess_evaluation() const;
			bool has_compute() const;
			bool has_stage(GLenum stage) const;

			bool compile_status(GLenum type) const;
			bool link_status() const;

			bool valid() const;

			//Prints out errors to the console and terminates if an error is found
			void check_errors(std::initializer_list<GLenum> stages, bool exit_on_faliure = true) const;

			GLuint program();
			const std::string& shader_log(GLenum shader_stage) const;
			const std::string& program_log() const;
		};

		typedef glsl_shader shader;
	}
}

