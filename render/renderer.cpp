#include "renderer.h"

namespace planet_engine
{
	std::pair<std::shared_ptr<patch>, render_data> gen_data(std::shared_ptr<patch::mesh> mesh)
	{
		buffer_val val;
		val.pos = mesh->pos;

		val.nwc = mesh->patch->nwc;
		val.nec = mesh->patch->nec;
		val.swc = mesh->patch->swc;
		val.sec = mesh->patch->sec;

		val.planet_radius = mesh->patch->data->planet_radius;
		val.skirt_depth = patch::SKIRT_DEPTH;
		val.scale = 1.0;

		GLuint buffers[2];
		glGenBuffers(2, buffers);

		// Fill uniform buffer
		glBindBuffer(GL_UNIFORM_BUFFER, buffers[1]);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(buffer_val), &val, GL_STATIC_DRAW);

		glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, buffers[0]);
		glBufferData(GL_TRANSFORM_FEEDBACK_BUFFER, (sizeof(float) * 7) * patch::NUM_VERTICES, (void*)0, GL_STATIC_DRAW);
		

		glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, patch::NUM_VERTICES);
	}
	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		
		glBindBuffer(GL_ARRAY_BUFFER, dummy_buffer);

		size_t size = data->to_subdivide.size();

		GLuint ubo;
		GLuint* buffers = new GLuint[size];
		buffer_val* vals = new buffer_val[size];
		
		glGenBuffers(1, &ubo);
		glGenBuffers(size, buffers);

		glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);

		for (size_t i = 0; i < size; ++i)
		{
			auto patch = data->to_subdivide[i];

			vals[i].pos = patch->pos;
			vals[i].nwc = patch->nwc;
			vals[i].nec = patch->nec;
			vals[i].swc = patch->swc;
			vals[i].sec = patch->sec;
			vals[i].planet_radius = patch->data->planet_radius;
			vals[i].skirt_depth = patch::SKIRT_DEPTH;
			vals[i].scale = 1.0;

			glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, buffers[i]);
			glBufferData(GL_TRANSFORM_FEEDBACK_BUFFER, (sizeof(float) * 7) * patch::NUM_VERTICES, (void*)0, GL_STATIC_DRAW);
		}

		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, ubo, vals, GL_DYNAMIC_DRAW);
		delete[] vals;

		for (size_t i = 0; i < size; ++i)
		{
			glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, buffers[i]);
			glBindBufferRange(GL_UNIFORM_BUFFER, uniform_index, ubo, sizeof(buffer_val) * i, sizeof(buffer_val));

			glDrawArrays(GL_TRIANGLES, 0, patch::NUM_VERTICES);
		}

		glDeleteBuffers(1, &ubo);

		delete[] buffers;
	}
}
