#pragma once

#include <cstdint>
#include <cstdlib>

namespace planet_engine
{
	constexpr std::size_t num_indices(std::size_t side_len)
	{
		return (side_len - 1) * (side_len - 1) * 6 + 24 * (side_len - 1);
	}
	constexpr std::size_t num_vertices(std::size_t side_len)
	{
		return side_len * side_len + side_len * 4;
	}

	std::uint16_t* gen_indices_16(std::size_t side_len);
	std::uint32_t* gen_indices_32(std::size_t side_len);
}
