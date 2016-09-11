#include "surface.h"

namespace planet_engine
{
	namespace gpu_shader
	{
		void surface::update_patches(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel)
		{
			glm::dvec3 camdata[] = { cam_pos, cam_vel };


			GLuint buffers[4];
			glGenBuffers(4, buffers);

			GLuint& cambuf = buffers[0];
			GLuint& to_subdivide = buffers[1];
			GLuint& to_merge = buffers[2];
			GLuint& counters = buffers[3];

			GLuint zero = 0;

			// Setup buffers first
			glBindBuffer(GL_UNIFORM_BUFFER, cambuf);
			glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::dvec3) * 2, camdata, GL_STREAM_DRAW);

			glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, counters);
			glBufferData(GL_ATOMIC_COUNTER_BUFFER, sizeof(GLuint) * 2, nullptr, GL_STATIC_DRAW);
			glClearBufferData(GL_ATOMIC_COUNTER_BUFFER, GL_R32UI, GL_RED, GL_UNSIGNED_INT, &zero);

			glBindBuffer(GL_SHADER_STORAGE_BUFFER, to_subdivide);
			glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(GLuint) * 1024, nullptr, GL_STATIC_DRAW);
			glClearBufferData(GL_SHADER_STORAGE_BUFFER, GL_R32UI, GL_RED, GL_UNSIGNED_INT, &zero);

			glBindBuffer(GL_SHADER_STORAGE_BUFFER, to_merge);
			glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(GLuint) * 1024, nullptr, GL_STATIC_DRAW);
			glClearBufferData(GL_SHADER_STORAGE_BUFFER, GL_R32UI, GL_RED, GL_UNSIGNED_INT, &zero);


			// Bind buffers used by both programs
			glBindBufferBase(GL_UNIFORM_BUFFER, 0, planet_data);
			glBindBufferBase(GL_UNIFORM_BUFFER, 1, cambuf);

			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, patches);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, leaves);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, parents);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, to_subdivide);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 4, to_merge);

			glBindBufferBase(GL_ATOMIC_COUNTER_BUFFER, 0, counters);

			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT | GL_ATOMIC_COUNTER_BARRIER_BIT);

			glUseProgram(should_subdivide);

			glDispatchCompute((num_parents + 15) / 16, 1, 1);

			glUseProgram(should_merge);
			glDispatchCompute((num_leaves + 16) / 16, 1, 1);

			//TODO: Continue
		}
	}
}
