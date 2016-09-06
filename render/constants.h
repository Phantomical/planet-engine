#pragma once

#include "patch.h"
#include "stride.h"

namespace planet_engine
{
	namespace constants
	{
		constexpr size_t SIDE_LEN = patch::SIDE_LEN;
		constexpr size_t NUM_VERTICES = num_vertices(SIDE_LEN);
		constexpr size_t NUM_ELEMENTS = num_indices(SIDE_LEN);
		constexpr size_t COMPUTE_GROUP_SIZE = 128;
		constexpr size_t VERTEX_SIZE = sizeof(float) * STRIDE;
		constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;
		constexpr double SKIRT_DEPTH = patch::SKIRT_DEPTH;
	}
}
