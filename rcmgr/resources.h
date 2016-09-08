#pragma once

#include <memory>
#include <string>

#ifndef __gl_h_
typedef unsigned int GLuint;
#endif

#ifdef RCMGR_EXPORTS
#	define RCMGR_API __declspec(dllexport)
#else
#	define RCMGR_API __declspec(dllimport)
#endif

namespace planet_engine
{
	namespace resources
	{
		class ResourceManager
		{
		private:
			struct Impl;

			Impl* Data;

			static void InitResources(Impl* data);

		public:
			// Loads and compiles a shader resource to an OpenGL program
			// Parameters:
			//     shader_name: The string key that the shader is associated with
			//     critical:    Indicates if the resource manager should halt the
			//                  application if the shader fails to compile
			GLuint RCMGR_API LoadShader(const char* resource_name);
			std::string RCMGR_API LoadText(const char* resource_name, bool cached = false);

			ResourceManager();
			~ResourceManager();

			ResourceManager(const ResourceManager&) = delete;
			ResourceManager(ResourceManager&&) = delete;
		};

		extern RCMGR_API std::shared_ptr<ResourceManager> RcMgr;
	}
}
