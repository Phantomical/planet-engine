#pragma once

#include "buffer_manager.h"
#include "managed_buffer.h"
#include "memmgr.h"

#include <glm\glm.hpp>

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
		static constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;

	private:
		static constexpr size_t COMPUTE_GROUP_SIZE = 128;

	private:
		/* Buffers */
		sparse_managed_buffer _patch_buffer;

		managed_buffer _download_buf;
		void* _download_ptr;

		GLuint _draw_command_buffer;
		GLuint _draw_matrix_buffer;

		GLuint _element_buffer;

		GLuint _leaf_parents;
		GLuint _leaf_patches;

		/* Shaders */
		GLuint _check_subdivide;
		GLuint _check_merge;
		GLuint _calc_new_pos;

		GLuint _vertex_gen;
		GLuint _mesh_gen;
		
		GLuint _length_calc;
		GLuint _reduce_max;

		/* Parameters */
		double _planet_radius;
		double _scale;
		double _skirt_depth;
		unsigned int _max_level;

		void update_patches(const glm::dvec3& cam_pos);

		/* Mesh Generation */
		void generate_vertices(GLuint patchID, GLuint buffers[2]);
		void generate_mesh(GLuint patchID, GLuint buffers[2]);

		/* Farthest Vertex Calculation */
		void calc_lengths(GLuint patchID, GLuint& tmp_buffer);
		void calc_max(GLuint tmp_buffer, GLuint s);
		void copy_max(GLuint patchID, GLuint tmp_buffer);
	};
}
