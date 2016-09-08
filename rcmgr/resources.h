#pragma once

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

		public:
			// Loads and compiles a shader resource to an OpenGL program
			// Parameters:
			//     shader_name: The string key that the shader is associated with
			//     critical:    Indicates if the resource manager should halt the
			//                  application if the shader fails to compile
			GLuint RCMGR_API LoadShader(const char* shader_name, bool critical = true);
		};

		RCMGR_API ResourceManager* RcMgr;
	}
}
