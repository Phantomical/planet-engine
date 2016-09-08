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
			// Loads and compiles the shader 
			GLuint RCMGR_API LoadShader(const char* shader_name);
		};

		RCMGR_API ResourceManager* RcMgr;
	}
}
