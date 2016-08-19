#include "managed_buffer.h"

namespace planet_engine
{
	void managed_buffer::setup(GLuint size, GLbitfield flags)
	{
		glGenBuffers(1, &_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, _buffer);
		glBufferStorage(GL_ARRAY_BUFFER, size, nullptr, flags);
	}
	void managed_buffer::teardown()
	{
		if (_buffer != 0)
			glDeleteBuffers(1, &_buffer);
	}

	managed_buffer::managed_buffer(GLuint size, GLbitfield flags) :
		_size(size),
		_allocator(size)
	{
		setup(size, flags);
	}
	managed_buffer::managed_buffer(managed_buffer&& buf) :
		_buffer(buf._buffer),
		_size(buf._size),
		_allocator(std::move(buf._allocator))
	{
		buf._buffer = 0;
		buf._size = 0;
	}
	managed_buffer::~managed_buffer() noexcept
	{
		teardown();
	}

	managed_buffer& managed_buffer::operator=(managed_buffer&& buf)
	{
		teardown();

		_buffer = buf._buffer;
		_size = buf._size;
		_allocator = std::move(buf._allocator);

		buf._buffer = 0;
		buf._size = 0;
	}

	GLuint managed_buffer::alloc(GLuint size, GLuint alignment) noexcept
	{
		auto offset = _allocator.alloc(size, alignment);
		if (offset == std::numeric_limits<size_t>::max())
		{
			_allocator.defrag();
			offset = _allocator.alloc(size, alignment);
		}
		return (GLuint)offset;
	}
	void managed_buffer::dealloc(GLuint offset) noexcept
	{
		_allocator.dealloc(offset);
	}

	GLuint managed_buffer::buffer() const noexcept
	{
		return _buffer;
	}
	GLuint managed_buffer::size() const noexcept
	{
		return _size;
	}
}
