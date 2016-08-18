
#include "memmgr.h"

#include <algorithm>
#include <cassert>

namespace planet_engine
{
	namespace mem
	{
		template<typename T>
		inline T roundup(T a, T b)
		{
			return ((a + b - 1) / b) * b;
		}

		template<typename Iter>
		// Insertion sort
		void isort(Iter first, Iter last)
		{
			for (Iter it = first; it != last; ++it)
				std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
		}

		bufmgr::bufmgr(size_t size) :
			_size(size)
		{
			_allocations.insert({ size, 0 });
		}

		bool bufmgr::suitable(const AllocInfo& info, size_t size, size_t alignment) const
		{
			if (info.size < size)
				return false;
			if (info.offset % alignment == 0)
				return true;
			if (info.size - (roundup(info.offset, alignment) - info.offset) < size)
				return true;
			return false;
		}
		bool bufmgr::adjacent(const AllocInfo& info1, const AllocInfo& info2) const
		{
			return info1.offset + info1.size == info2.offset;
		}

		size_t bufmgr::alloc(size_t size, size_t alignment)
		{
			AllocInfo result = { ~0, ~0 };

			auto it = _free_list.begin();
			for (; it != _free_list.end(); ++it)
			{
				if (suitable(*it, size, alignment))
				{
					if (it->offset % alignment == 0)
					{
						auto pair = it->split(roundup<size_t>(it->offset, alignment)
							- it->offset);
						result = pair.second;
						*it = pair.first;
					}
					else
					{
						result = *it;
						_free_list.erase(it);
					}
				}
			}

			if (result.offset != ~0)
				_allocations.insert(result);

			return result.offset;
		}
		void bufmgr::dealloc(size_t mem)
		{
			AllocInfo info = { 0, mem };
			auto it = _allocations.find(info);
			assert(it != _allocations.end());

			info = *it;

			_allocations.erase(it);

			_free_list.push_back(info);

			isort(_free_list.begin(), _free_list.end());
		}

		void bufmgr::defrag()
		{
			auto prev = _free_list.rbegin();
			for (auto it = prev; it != _free_list.rend(); ++it)
			{
				if (adjacent(*std::next(it), *it))
				{
					auto& info = *std::next(it);
					info.size += it->size;
				}
				else
				{
					_free_list.erase(std::prev(it).base(), prev.base());
					prev = it;
				}
			}
		}
	}
}