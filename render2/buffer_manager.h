#pragma once

#include "gl_core.h"
#include "defs.h"

#include <set>
#include <queue>
#include <functional>

namespace planet_engine
{
	struct buffer_manager
	{
	private:
		typedef std::priority_queue<GLuint, std::vector<GLuint>,
			std::greater<GLuint>> pqueue_type;

		// A list of free offsets
		pqueue_type _free_list;
		// A list of currently used offsets
		std::set<GLuint> _offsets;
		// Offsets which cannot be freed yet
		std::set<GLuint> _locked;
		// The next greatest index after the free list is empty
		GLuint _max_index;
		// The number of pages that are currently committed
		GLuint _num_pages;
		// The size of each page
		GLuint _page_size;
		// The buffer that the data is contained within
		GLuint _buffer;
		// The size of each allocated block
		GLuint _block_size;
		// The number of pages in the buffer
		GLuint _max_pages;

		void alloc_buffer(GLuint num_blocks);

		void return_index(GLuint block);

	public:
		GLuint alloc_block();
		void dealloc_block(GLuint offset);

		void lock(GLuint offset);
		void unlock(GLuint offset);

		GLuint buffer() const;
		GLuint max_size() const;
		GLuint block_size() const;
		GLuint size() const;
		GLuint max_index() const;
		GLuint current_max() const;

		buffer_manager(GLuint block_size, GLuint num_blocks);
		buffer_manager(const buffer_manager&) = delete;

		~buffer_manager();
	};
}
