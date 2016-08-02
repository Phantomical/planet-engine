#include "compute.h"

#include <utility>

namespace glutils
{
	compute&& compute::source_buffer(GLuint bufID, GLsizeiptr range, GLintptr offset, GLuint binding)
	{
		source.buffer = bufID;
		source.range = range;
		source.offset = offset;
		source.binding = binding;

		return std::move(*this);
	}
	compute&& compute::dest_buffer(GLuint bufID, GLsizeiptr range, GLintptr offset, GLuint binding)
	{
		dest.buffer = bufID;
		dest.range = range;
		dest.offset = offset;
		dest.binding = binding;

		return std::move(*this);
	}

	compute&& compute::dispatch(GLuint x, GLuint y, GLuint z)
	{
		GLuint buffers[] = { source.buffer, dest.buffer };
		GLintptr offsets[] = { source.offset, dest.offset };
		GLsizeiptr ranges[] = { source.range, dest.range };

		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, source.binding, source.buffer, source.offset, source.range);
		glBindBufferRange(GL_SHADER_STORAGE_BUFFER, dest.binding, dest.buffer, dest.offset, dest.range);

		glDispatchCompute(x, y, z);
		sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);

		return std::move(*this);
	}

	GLuint compute::get_source()
	{
		return source.buffer;
	}
	GLuint compute::get_dest()
	{
		return dest.buffer;
	}

	bool compute::is_done() const
	{
		if (glClientWaitSync(sync, GL_SYNC_FLUSH_COMMANDS_BIT, 0) == GL_TIMEOUT_EXPIRED)
			return false;
		return true;
	}
	void compute::wait() const
	{
		while (glClientWaitSync(sync, GL_SYNC_FLUSH_COMMANDS_BIT, GL_TIMEOUT_IGNORED) == GL_TIMEOUT_EXPIRED);
	}
}
