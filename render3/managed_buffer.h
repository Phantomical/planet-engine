#pragma once

#include "gl_core.h"
#include "memmgr.h"

#include <vector>
#include <set>

namespace planet_engine
{
	class managed_buffer
	{
	private:
		GLuint _buffer;
		GLuint _size;

		mem::bufmgr _allocator;

		void setup(GLuint size, GLbitfield flags);
		void teardown();

	public:
		static constexpr GLuint INVALID_ALLOCATION = ~0;

		managed_buffer(GLuint size, GLbitfield storage_flags);
		managed_buffer(managed_buffer&& buf);
		~managed_buffer() noexcept;

		managed_buffer& operator=(managed_buffer&& buf);

		// If the allocation failed returns INVALID_ALLOCATION
		GLuint alloc(GLuint size, GLuint alignment = 8) noexcept;
		void dealloc(GLuint offset) noexcept;

		GLuint buffer() const noexcept;
		GLuint size() const noexcept;

		managed_buffer(const managed_buffer&) = delete;
		void operator=(const managed_buffer&) = delete;
	};
}
