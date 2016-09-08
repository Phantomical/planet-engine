#pragma once

#include "gl_core.h"
#include <utility>

namespace planet_engine
{
	namespace gpu_surface
	{
		struct rmdup_result
		{
			GLuint result_buffer;
			GLuint result_size_buffer;
		};

		rmdup_result remove_duplicates(GLuint buffer, GLuint size, GLuint max_value);
	}
}
