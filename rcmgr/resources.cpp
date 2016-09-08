
#include "resources.h"

#include <cstdlib>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>

#include "gl_core.h"

#include <Windows.h>

namespace planet_engine
{
	namespace resources
	{
		std::string operator ""s(const char* str, size_t)
		{
			return std::string(str);
		}

		[[noreturn]] 
		void DisplayError(const std::string& errmsg)
		{
			printf("%s", errmsg.c_str());
			MessageBoxA(nullptr, errmsg.c_str(), nullptr, 0);
			std::quick_exit(EXIT_FAILURE);
		}

		struct ShaderSources
		{
			std::string Sources[6];
		};

		struct ResourceManager::Impl
		{
			std::unordered_map<std::string, ShaderSources> Shaders;
			std::unordered_map<std::string, std::string> Files;
		};

		GLuint ResourceManager::LoadShader(const char* shader_name)
		{
			static constexpr GLenum StageEnums[] = {
				GL_VERTEX_SHADER,
				GL_GEOMETRY_SHADER,
				GL_TESS_CONTROL_SHADER,
				GL_TESS_EVALUATION_SHADER,
				GL_FRAGMENT_SHADER,
				GL_COMPUTE_SHADER
			};

			auto it = Data->Shaders.find(shader_name);
			if (it == Data->Shaders.end())
			{
				DisplayError(std::string("ERROR: Unable to find definition for resource '")
					+ shader_name + "'\n");
			}

			std::string* sources = it->second.Sources;
			GLuint program = glCreateProgram();

			GLuint shaders[6];
			std::memset(shaders, 0, sizeof(shaders));

			bool iserr = false;

			for (size_t i = 0; i < 6; ++i)
			{
				if (!sources[i].empty())
				{
					std::string source = LoadText(sources[i].c_str(), false);
					const char* str = source.c_str();
					GLuint shader = glCreateShader(StageEnums[i]);

					glShaderSource(shader, 1, &str, nullptr);
					glCompileShader(shader);

					glAttachShader(program, shader);

					shaders[i] = shader;
				}
			}

			for (size_t i = 0; i < 6; ++i)
			{
				if (!sources[i].empty())
				{
					GLint status = 0;

					glGetShaderiv(shaders[i], GL_COMPILE_STATUS, &status);

					if (status == GL_FALSE)
					{
						iserr = true;
						GLint maxlength = 0;
						glGetShaderiv(shaders[i], GL_INFO_LOG_LENGTH, &maxlength);

						std::string log(maxlength + 1, '\0');
						glGetShaderInfoLog(shaders[i], maxlength, &maxlength, &log[0]);

						printf("%s\n", log.c_str());
					}
				}
			}

			if (iserr)
			{
				DisplayError(std::string("Error while compiling shader '") + shader_name + "'");
			}

			glLinkProgram(program);

			{
				GLint status = 0;
				glGetProgramiv(program, GL_LINK_STATUS, &status);

				if (status == GL_FALSE)
				{
					GLint maxlength = 0;
					glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxlength);

					std::string log(maxlength + 1, '\0');
					glGetProgramInfoLog(program, maxlength, &maxlength, &log[0]);

					printf("%s", log.c_str());
					DisplayError(std::string("Error while linking shader '") + shader_name + "'");
				}
			}

			for (size_t i = 0; i < 6; ++i)
			{
				if (shaders[i] != 0)
				{
					glDetachShader(program, shaders[i]);
					glDeleteShader(shaders[i]);
				}
			}

			return program;
		}
		std::string ResourceManager::LoadText(const char* resource_name, bool cached /* Unused for now */)
		{
			auto it = Data->Files.find(resource_name);
			if (it == Data->Files.end())
			{
				DisplayError(std::string("Resource '") + resource_name + "' does not exist.");
			}

			std::ifstream t(it->second);

			if (!t.is_open())
			{
				DisplayError("Unable to load path '"s + it->second + "' while loading resource '" + resource_name);
			}

			std::stringstream buffer;
			buffer << t.rdbuf();
			return buffer.str();
		}

		ResourceManager::ResourceManager() :
			Data(new Impl)
		{

		}
		ResourceManager::~ResourceManager()
		{
			delete Data;
		}
	}
}
