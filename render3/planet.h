#pragma once

#include "buffer_manager.h"
#include "memmgr.h"

#include "indexgen.h"

namespace planet_engine
{
	class planet
	{
	public:
		static constexpr size_t SIDE_LEN = 33;
		static constexpr size_t NUM_VERTICES = num_vertices(SIDE_LEN);
		static constexpr size_t NUM_ELEMENTS = num_indices(SIDE_LEN);
		static constexpr size_t VERTEX_SIZE = sizeof(float) * 10;

	private:
		static constexpr size_t COMPUTE_GROUP_SIZE = 128;
		static constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;

	private:
		buffer_manager _patch_buffer;

		GLuint _download_buffer;
		mem::bufmgr _download_heap;
		void* _download_ptr;

		GLuint _draw_command_buffer;
		GLuint _draw_matrix_buffer;

		GLuint _element_buffer;

		double planet_radius;
		double scale;
		double skirt_depth;
	};
}
