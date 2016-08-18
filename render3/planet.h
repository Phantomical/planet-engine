#pragma once

#include "buffer_manager.h"
#include "managed_buffer.h"
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
		sparse_managed_buffer _patch_buffer;

		managed_buffer _download_buf;
		void* _download_ptr;

		GLuint _draw_command_buffer;
		GLuint _draw_matrix_buffer;

		GLuint _element_buffer;

		double _planet_radius;
		double _scale;
		double _skirt_depth;
	};
}
