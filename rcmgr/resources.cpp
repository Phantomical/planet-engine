
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
		std::string operator ""_s(const char* str, size_t)
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
				DisplayError("ERROR: Unable to find definition for resource '"_s
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
				DisplayError("Error while compiling shader '"_s + shader_name + "'");
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
					DisplayError("Error while linking shader '"_s + shader_name + "'");
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
				DisplayError("Unable to load path '"_s + it->second + "' while loading resource '" + resource_name);
			}

			std::stringstream buffer;
			buffer << t.rdbuf();
			return buffer.str();
		}

		ResourceManager::ResourceManager() :
			Data(new Impl)
		{
			InitResources(Data);
		}
		ResourceManager::~ResourceManager()
		{
			delete Data;
		}

#define ADD_SHADER(name, vert, geom, tctrl, teval, frag) \
	data->Shaders[name] = { vert, geom, tctrl, teval, frag, nullptr }
#define ADD_COMPUTE(name, comp) \
	data->Shaders[name] = { nullptr, nullptr, nullptr, nullptr, nullptr, comp }
#define ADD_FILE(name, path) \
	data->Files[name] = path

		void ResourceManager::InitResources(Impl* data)
		{
			/* Shaders */
			/* gpu_surface */
			/* remove_duplicates */
			ADD_COMPUTE("gpu_surface\\rmdup-1", "gpu_surface\\shaders\\rmdup-1");
			ADD_COMPUTE("gpu_surface\\rmdup-2", "gpu_surface\\shaders\\rmdup-2");
			
			ADD_COMPUTE("gpu_surface\\should-merge", "gpu_surface\\shaders\\should-merge");
			ADD_COMPUTE("gpu_surface\\should-subdivide", "gpu_suface\\shaders\\should-subdivide");

			/* render */
			/* occlusion-culling */
			ADD_SHADER("render\\occlusion-culling\\occludee", 
				"render\\occlusion-culling\\shaders\\occludee-vert",
				nullptr, nullptr, nullptr,
				"render\\occlusion-culling\\shaders\\occludee-frag");
			ADD_SHADER("render\\occlusion-culling\\occluder",
				"render\\occlusion-culling\\shaders\\occluder-vert",
				"render\\occlusion-culling\\shaders\\occluder-geom",
				nullptr, nullptr, nullptr);

			/* pipeline */
			ADD_COMPUTE("render\\patch-pipline\\compact", "render\\patch-pipline\\shaders\\compact");
			ADD_COMPUTE("render\\patch-pipline\\get_pos", "render\\patch-pipline\\shaders\\get_pos");
			ADD_COMPUTE("render\\patch-pipline\\length", "render\\patch-pipline\\shaders\\length");
			ADD_COMPUTE("render\\patch-pipline\\max", "render\\patch-pipline\\shaders\\max");
			ADD_COMPUTE("render\\patch-pipline\\mesh_gen", "render\\patch-pipline\\shaders\\mesh_gen");
			ADD_COMPUTE("render\\patch-pipline\\noise", "render\\patch-pipline\\shaders\\noise");
			ADD_COMPUTE("render\\patch-pipline\\vertex_gen", "render\\patch-pipline\\shaders\\vertex_gen");

			/* renderer */
			ADD_COMPUTE("render\\renderer\\command_update", "render\\renderer\\shaders\\command_update");

			/* general */
			ADD_SHADER("render\\planet-shader",
				"render\\shaders\\planet-shader-vert",
				nullptr, nullptr, nullptr,
				"render\\shaders\\planet-shader-frag");

			/* Files */
			/* gpu_surface */
			ADD_FILE("gpu_surface\\shaders\\rmdup-1", "rmdup-1.glsl");
			ADD_FILE("gpu_surface\\shaders\\rmdup-2", "rmdup-2.glsl");

			ADD_FILE("gpu_surface\\shaders\\should-merge", "should_merge.glsl");
			ADD_FILE("gpu_surface\\shaders\\should-subdivide", "should_subdivide.glsl");

			/* render */
			ADD_FILE("render\\occlusion-culling\\shaders\\occludee-frag", "occludee-frag.glsl");
			ADD_FILE("render\\occlusion-culling\\shaders\\occludee-vert", "occludee-vert.glsl");
			ADD_FILE("render\\occlusion-culling\\shaders\\occluder-geom", "occluder-geom.glsl");
			ADD_FILE("render\\occlusion-culling\\shaders\\occluder-vert", "occluder-vert.glsl");

			ADD_FILE("render\\patch-pipline\\shaders\\compact", "compact.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\get_pos", "get_pos.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\length", "length.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\max", "max.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\mesh_gen", "mesh_gen.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\noise", "noise.glsl");
			ADD_FILE("render\\patch-pipline\\shaders\\vertex_gen", "vertex_gen.glsl");

			ADD_FILE("render\\renderer\\shaders\\command_update", "command_update.glsl");

			ADD_FILE("render\\shaders\\planet-shader-vert", "planet_shader_vert.glsl");
			ADD_FILE("render\\shaders\\planet-shader-frag", "planet_shader_frag.glsl");
		}
	}
}
