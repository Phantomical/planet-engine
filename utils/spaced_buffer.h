#pragma once

namespace planet_engine
{
	namespace util
	{
		template<typename T>
		class spaced_buffer
		{
		private:
			size_t _alignment;
			size_t _size;

			void* _memory;

		public:
			spaced_buffer(size_t alignment, size_t size) :
				_alignment((((sizeof(T) + alignment - 1) / alignment) * alignment)),
				_size(size),
				_memory(malloc(_alignment * size))
			{
				for (size_t i = 0; i < size; ++i)
					new (&(*this)[i]) T();
			}
			spaced_buffer(size_t alignment, void* ptr) :
				_alignment(alignment),
				_size(0),
				_memory(ptr)
			{

			}
			~spaced_buffer()
			{
				if (_size != 0)
				{
					for (size_t i = 0; i < _size; ++i)
						(*this)[i].~T();
					free(_memory);
				}
			}

			T& operator[](size_t idx)
			{
				return *(T*)((char*)_memory + _alignment * idx);
			}

			T* data()
			{
				return (T*)_memory;
			}

			size_t alignment() const
			{
				return _alignment;
			}
			size_t size() const
			{
				return _size;
			}
		};
	}
}
