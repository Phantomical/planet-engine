#pragma once

#include <set>
#include <vector>

namespace planet_engine
{
	namespace mem
	{
		// Manages a single buffer 
		class bufmgr
		{
		private:
			struct AllocInfo
			{
				size_t size;
				size_t offset;

				bool operator==(size_t offset) const
				{
					return this->offset == offset;
				}
				bool operator!=(size_t offset) const
				{
					return !(*this == offset);
				}

				bool operator==(const AllocInfo& info) const
				{
					return offset == info.offset;
				}
				bool operator!=(const AllocInfo& info) const
				{
					return !(*this == info);
				}

				bool operator<(const AllocInfo& info) const
				{
					return offset < info.offset;
				}
				bool operator>(const AllocInfo& info) const
				{
					return offset > info.offset;
				}
				bool operator<=(const AllocInfo& info) const
				{
					return !(*this > info);
				}
				bool operator>=(const AllocInfo& info) const
				{
					return !(*this < info);
				}

				std::pair<AllocInfo, AllocInfo> split(size_t sz) const
				{
					AllocInfo v1 = { offset, sz };
					AllocInfo v2 = { offset + sz, size - sz };

					return std::make_pair(v1, v2);
				}
			};

			size_t _size;

			std::vector<AllocInfo> _free_list;
			std::set<AllocInfo> _allocations;

			bool suitable(const AllocInfo& info, size_t size, size_t alignment) const;
			bool adjacent(const AllocInfo& info1, const AllocInfo& info2) const;

		public:
			bufmgr(size_t size);

			// Allocates an offset into a buffer
			size_t alloc(size_t size, size_t alignment);
			void dealloc(size_t offset);

			void defrag();
		};
	}
}
