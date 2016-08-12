#pragma once

#include <utility>
#include <algorithm>

namespace planet_engine
{
	namespace util
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
		template<typename Container, typename Pred>
		auto find_if(Container& c, const Pred& p)
		{
			return std::find_if(std::begin(c), std::end(c), p);
		}
	}
}
