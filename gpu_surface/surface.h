#pragma once

#include "gl_core.h"
#include <glm\glm.hpp>

namespace planet_engine
{
	namespace gpu_shader
	{
		class surface
		{
		private:
			static constexpr size_t COMPUTE_GROUP_SIZE = 16;

			/* Shaders */
			GLuint should_subdivide;
			GLuint should_merge;

			/* Buffers */
			GLuint patches;
			GLuint planet_data;

			GLuint leaves;
			GLuint parents;

			GLuint num_parents;
			GLuint num_leaves;

		public:
			void update_patches(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel);

		};
	}
}
