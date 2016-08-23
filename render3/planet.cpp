#include "planet.h"

namespace planet_engine
{
	void planet::update_patches(const glm::dvec3& cam_pos)
	{
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, _patch_buffer);
		glBindBuffersBase(GL_SHADER_STORAGE_BUFFER, 2, 6, _mod_queues);

		GLuint zero = 0;
		glClearBufferData(_ctr_buffer, GL_R32UI, GL_R32UI, GL_UNSIGNED_INT, &zero);

		glBindBufferBase(GL_ATOMIC_COUNTER_BUFFER, 0, _ctr_buffer);

		GLuint num_dispatches = (_patch_list.current_max() + PER_PATCH_GROUP_SIZE - 1) / PER_PATCH_GROUP_SIZE;

		/* Subdivide Update */
		glUseProgram(_check_subdivide);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _patch_leaves);
		glDispatchCompute(num_dispatches, 1, 1);

		/* Merge Update */
		glUseProgram(_check_merge);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, _patch_parents);
		glDispatchCompute(num_dispatches, 1, 1);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT | GL_ATOMIC_COUNTER_BARRIER_BIT);
	}
}
