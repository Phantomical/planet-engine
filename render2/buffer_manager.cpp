#include "buffer_manager.h"
#include <cassert>

namespace planet_engine
{
	template<typename T, typename Container>
	bool contains(const Container& c, const T& val)
	{
		return std::find(std::begin(c), std::end(c), val) != std::end(c);
	}
	template<typename T, typename Container>
	auto find(Container& c, const T& val)
	{
		return std::find(std::begin(c), std::end(c), val);
	}

	void buffer_manager::alloc_buffer(GLuint num_blocks)
	{
		GLint64 val;
		glGetInteger64v(GL_SPARSE_BUFFER_PAGE_SIZE_ARB, &val);

		_page_size = static_cast<GLuint>(val);

		_max_pages = (uint64_t(num_blocks) * _block_size + _page_size - 1) / _page_size;

		glGenBuffers(1, &_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, _buffer);
		glBufferStorage(GL_ARRAY_BUFFER, _max_pages * _page_size, nullptr, GL_SPARSE_STORAGE_BIT_ARB);

		pqueue_type queue;
		_free_list.swap(queue);

		_offsets.clear();
		_locked.clear();

		_max_index = 0;
		_num_pages = 0;
	}
	void buffer_manager::return_index(GLuint block)
	{
		_free_list.push(block);
	}

	GLuint buffer_manager::alloc_block()
	{
		if (!_free_list.empty())
		{
			// There is an open spot in the free list
			// so we don't have to expand right now
			GLuint val = _free_list.top();
			_free_list.pop();
			_offsets.insert(val);
			return val;
		}

		GLuint index = _max_index++;

		while (_max_index * _block_size > _num_pages * _page_size)
		{
			assert((_num_pages + 1) < _max_pages);
			//Commits the next page allowing it to be used for mesh data
			glNamedBufferPageCommitmentEXT(_buffer,
				_num_pages++ * _page_size, _page_size, GL_TRUE);
		}

		_offsets.insert(index);

		//OutputDebug("[BUFMGR][At ", this, "] Allocated offset ", index, ".\n");

		return index;
	}
	void buffer_manager::dealloc_block(GLuint offset)
	{
		//OutputDebug("[BUFMGR][At ", this, "] Deallocated offset ", offset, ".\n");

		assert(offset < _max_index);

		_offsets.erase(offset);

		if (!contains(_locked, offset))
		{
			return_index(offset);
		}
	}

	void buffer_manager::lock(GLuint offset)
	{
		_locked.insert(offset);
	}
	void buffer_manager::unlock(GLuint offset)
	{
		_locked.erase(offset);

		if (!contains(_offsets, offset))
			return_index(offset);
	}

	void buffer_manager::uncommit_unused()
	{
		GLuint max = current_max();

		std::vector<GLuint> used;

		while (!_free_list.empty())
		{
			if (_free_list.top() < max)
				used.push_back(_free_list.top());
			_free_list.pop();
		}

		glBindBuffer(GL_ARRAY_BUFFER, _buffer);
		
		for (GLuint page = ((max + _page_size - 1) / _page_size); page < _num_pages; ++page)
		{
			glBufferPageCommitmentARB(GL_ARRAY_BUFFER, page * _page_size, _page_size, GL_FALSE);
		}

		for (GLuint open : used)
			_free_list.push(open);
	}

	GLuint buffer_manager::buffer() const
	{
		return _buffer;
	}
	GLuint buffer_manager::max_size() const
	{
		return _max_pages * _page_size;
	}
	GLuint buffer_manager::block_size() const
	{
		return _block_size;
	}
	GLuint buffer_manager::size() const
	{
		return _max_index;
	}
	GLuint buffer_manager::max_index() const
	{
		if (_offsets.size() != 0)
		{
			std::vector<GLuint> offsets(_offsets.begin(), _offsets.end());
			assert(std::max(std::initializer_list<GLuint>(
				offsets.data(), offsets.data() + offsets.size())) < _max_index);
		}
		return _max_index;
	}
	GLuint buffer_manager::current_max() const
	{
		if (_offsets.empty())
			return 0;
		return *std::max_element(_offsets.begin(), _offsets.end()) + 1;
	}

	buffer_manager::buffer_manager(GLuint block_size, GLuint num_blocks)
	{
		GLint alignment;
		glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &alignment);

		_block_size = ((block_size + alignment - 1) / alignment) * alignment;

		alloc_buffer(num_blocks);
	}
	buffer_manager::~buffer_manager()
	{
		GLsync sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);

		bool cond = true;
		do
		{
			switch (glClientWaitSync(sync, GL_SYNC_FLUSH_COMMANDS_BIT, GL_TIMEOUT_IGNORED))
			{
			case GL_ALREADY_SIGNALED:
			case GL_CONDITION_SATISFIED:
				cond = false;
				break;
			case GL_TIMEOUT_EXPIRED:
				break;
			default:
				assert(false);
			}
		} while (cond);

		glDeleteSync(sync);
		glDeleteBuffers(1, &_buffer);
	}
}
