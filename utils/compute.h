#pragma once

#include "gl_core.h"

namespace glutils
{
	class compute
	{
	private:
		struct buf_info
		{
			GLuint buffer;
			GLintptr offset;
			GLsizeiptr range;
			GLuint binding;
		};
		
		buf_info source;
		buf_info dest;
		GLuint program;

		GLsync sync;

	public:
		compute(GLuint program);

		compute&& source_buffer(GLuint bufID, GLsizeiptr range, GLintptr offset = 0, GLuint binding = 0);
		compute&& dest_buffer(GLuint bufID, GLsizeiptr range, GLintptr offset = 0, GLuint binding = 1);

		compute&& dispatch(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);

		GLuint get_source();
		GLuint get_dest();

		// Indicates whether the calculation is done
		bool is_done() const;
		// Waits until the compute shader execution is done
		void wait() const;
	};
}
