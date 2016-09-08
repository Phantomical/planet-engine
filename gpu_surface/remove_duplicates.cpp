#include "remove_duplicates.h"

namespace planet_engine
{
	namespace gpu_surface
	{
		rmdup_result remove_duplicates(GLuint buffer, GLuint size, GLuint max_value)
		{
			static constexpr GLuint COMPUTE_GROUP_SIZE = 128;

			static GLuint rmdup_1;
			static GLuint rmdup_2;

			/* Setup */
			GLuint buffers[3];
			glGenBuffers(3, buffers);

			GLuint& histogram = buffers[0];
			GLuint& outbuf = buffers[1];
			GLuint& ctrbuf = buffers[2];

			glBindBuffer(GL_SHADER_STORAGE_BUFFER, histogram);
			glBufferData(GL_SHADER_STORAGE_BUFFER, (size + 31) / 32, nullptr, GL_STATIC_DRAW);

			GLuint zero = 0;
			glClearBufferData(GL_SHADER_STORAGE_BUFFER, GL_R32UI, GL_R32UI, GL_UNSIGNED_INT, &zero);
			
			glBindBuffer(GL_SHADER_STORAGE_BUFFER, outbuf);
			glBufferData(GL_SHADER_STORAGE_BUFFER, size * sizeof(GLuint), nullptr, GL_STATIC_DRAW);

			glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, ctrbuf);
			glBufferData(GL_ATOMIC_COUNTER_BUFFER, sizeof(GLuint), &zero, GL_STATIC_DRAW);

			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

			/* Build occurence-sort histogram */
			glUseProgram(rmdup_1);
			glUniform1ui(0, size);

			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, buffer);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, histogram);

			glDispatchCompute((size + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);
			
			glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

			/* Fill output buffer from histogram */
			glUseProgram(rmdup_2);
			glUniform1ui(0, size);

			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, outbuf);
			glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, histogram);

			glBindBufferBase(GL_ATOMIC_COUNTER_BUFFER, 0, ctrbuf);

			glDispatchCompute((size + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE, 1, 1);

			glDeleteBuffers(1, buffers);

			return{ outbuf, ctrbuf };
		}
	}
}
