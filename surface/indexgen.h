#pragma once

#include <cstdint>
#include <cstdlib>

namespace planet_engine
{
	inline constexpr std::size_t num_indices(std::size_t side_len)
	{
		return (side_len - 1) * (side_len - 1) * 6 + 24 * (side_len - 1);
	}
	inline constexpr std::size_t num_vertices(std::size_t side_len)
	{
		return side_len * side_len + side_len * 4;
	}

	unsigned int* gen_indices(std::size_t side_len);

	inline unsigned int* gen_indices_32(std::size_t side_len)
	{
		return gen_indices(side_len);
	}
}
