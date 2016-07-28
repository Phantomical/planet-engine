#include "renderer.h"

namespace planet_engine
{
	struct buffer_val
	{
		glm::dvec3 pos;
		double _pad1;
		glm::dvec3 nwc;
		double _pad2;
		glm::dvec3 nec;
		double _pad3;
		glm::dvec3 swc;
		double _pad4;
		glm::dvec3 sec;
		double _pad5;
		double planet_radius;
		double skirt_depth;
		double scale;
		double _pad6;
	};

	void renderer::subdivide()
	{
		// Nothing run in this section needs to output to the screen
		glEnable(GL_RASTERIZER_DISCARD);

		// Bind our useless buffer
		// We only use this so that there are the
		// correct number of vertices captured   
		// with transform feedback
		glBindBuffer(GL_ARRAY_BUFFER, dummy_buffer);

		size_t size = data->to_subdivide.size() * 4;

		GLuint ubo;
		GLuint* buffers = new GLuint[size];
		buffer_val* vals = new buffer_val[size];
		std::shared_ptr<patch>* patches = new std::shared_ptr<patch>[size];

		for (size_t i = 0; i < data->to_subdivide.size(); ++i)
		{
			auto patch = data->to_subdivide[i];

			patches[i * 4 + 0] = patch->nw;
			patches[i * 4 + 1] = patch->ne;
			patches[i * 4 + 2] = patch->sw;
			patches[i * 4 + 3] = patch->se;

			auto it = rendermap.find(patch);
			// This should always be true
			// but it isn't really a problem
			// if it is false.
			if (it != rendermap.end())
			{
				glDeleteBuffers(1, &it->second.mesh_buffer);
				rendermap.erase(it);
			}
		}

		glGenBuffers(1, &ubo);
		glGenBuffers(size, buffers);

		glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);

		for (size_t i = 0; i < data->to_subdivide.size(); ++i)
		{
			auto patch = patches[i];

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

			glBeginTransformFeedback(GL_POINTS);

			glDrawArrays(GL_POINTS, 0, patch::NUM_VERTICES);

			glEndTransformFeedback();
		}

		glDeleteBuffers(1, &ubo);

		for (size_t i = 0; i < size; ++i)
		{
			render_data rdat;

			rdat.mesh_buffer = buffers[i];
			rdat.pos = patches[i]->pos;

			rendermap.insert(std::make_pair(patches[i], rdat));
		}

		delete[] buffers;
		data->to_subdivide.empty();

		glDisable(GL_RASTERIZER_DISCARD);
	}
	void renderer::merge()
	{

	}

	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		subdivide();
	}
}
