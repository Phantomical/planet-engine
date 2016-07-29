#include "renderer.h"
#include <glm\gtc\matrix_transform.hpp>

const char* MeshGenShader;
const char* DistanceCalc;

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
	struct renderer::computeinfo
	{
		GLsync sync;
		std::vector<std::weak_ptr<patch>> patches;
		GLuint results;
	};

	GLuint compile_meshgen()
	{
		GLuint program = glCreateProgram();
		GLuint shader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(shader, 1, &MeshGenShader, nullptr);
		glCompileShader(shader);

		glAttachShader(program, shader);

		const char* varyings[] =
		{
			"out_vertex",
			"out_normal",
			"out_displacement"
		};

		glTransformFeedbackVaryings(program, 3, varyings, GL_INTERLEAVED_ATTRIBS);

		glLinkProgram(program);

		glDetachShader(program, shader);
		glDeleteShader(shader);

		return program;
	}

	void renderer::subdivide()
	{
		// Nothing run in this section needs to output to the screen
		glEnable(GL_RASTERIZER_DISCARD);

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

			data->leaf_parents.push_back(patch);
			auto it1 = std::find(data->leaf_patches.begin(), data->leaf_patches.end(), patch);
			if (it1 != data->leaf_patches.end())
			{
				data->leaf_patches.erase(it1);
			}

			data->leaf_patches.push_back(patch->nw);
			data->leaf_patches.push_back(patch->ne);
			data->leaf_patches.push_back(patch->sw);
			data->leaf_patches.push_back(patch->se);

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

			glBindBuffer(GL_ARRAY_BUFFER, buffers[i]);
			glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * 7) * patch::NUM_VERTICES, nullptr, GL_STATIC_DRAW);
		}

		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(buffer_val) * size, vals, GL_DYNAMIC_DRAW);
		delete[] vals;
		// Bind our useless buffer
		// We only use this so that there are the
		// correct number of vertices captured   
		// with transform feedback
		glBindBuffer(GL_ARRAY_BUFFER, elements);
		// Bind our program
		glUseProgram(meshgen.program);
		// This causes different vertices to overlap but that
		// doesn't matter because we don't use them anyway
		glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 1, (void*)0);

		for (size_t i = 0; i < size; ++i)
		{
			glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, buffers[i]);
			glBindBufferRange(GL_UNIFORM_BUFFER, meshgen.index, ubo, sizeof(buffer_val) * i, sizeof(buffer_val));

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
			rdat.radius = data->to_merge[i]->farthest_vertex;

			rendermap.insert(std::make_pair(patches[i], rdat));
		}

		delete[] buffers;
		data->to_subdivide.clear();

		glDisable(GL_RASTERIZER_DISCARD);
	}
	void renderer::merge()
	{
		glEnable(GL_RASTERIZER_DISCARD);

		size_t size = data->to_merge.size();
		GLuint ubo;
		GLuint* buffers = new GLuint[size];
		buffer_val* vals = new buffer_val[size];

		for (size_t i = 0; i < size; ++i)
		{
			std::shared_ptr<patch> patch = data->to_merge[i];
			buffers[i] = merge_children(patch);

			vals[i].pos = patch->pos;
			vals[i].nwc = patch->nwc;
			vals[i].nec = patch->nec;
			vals[i].swc = patch->swc;
			vals[i].sec = patch->sec;
			vals[i].planet_radius = patch->data->planet_radius;
			vals[i].skirt_depth = patch::SKIRT_DEPTH;
			vals[i].scale = 1.0;

			glNamedBufferData(buffers[i], sizeof(float) * 7 * patch::NUM_VERTICES, nullptr, GL_STATIC_DRAW);
		}

		glCreateBuffers(1, &ubo);
		glNamedBufferData(ubo, sizeof(buffer_val) * size, vals, GL_DYNAMIC_DRAW);
		delete[] vals;

		glUseProgram(meshgen.program);
		glBindBuffer(GL_ARRAY_BUFFER, elements);
		glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 1, (void*)0);

		for (size_t i = 0; i < size; ++i)
		{
			glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, buffers[i]);
			glBindBufferRange(GL_UNIFORM_BUFFER, meshgen.index, ubo, sizeof(buffer_val) * i, sizeof(buffer_val));

			glBeginTransformFeedback(GL_POINTS);

			glDrawArrays(GL_POINTS, 0, patch::NUM_VERTICES);

			glEndTransformFeedback();
		}

		glDeleteBuffers(1, &ubo);

		for (size_t i = 0; i < size; ++i)
		{
			render_data rdat;

			rdat.mesh_buffer = buffers[i];
			rdat.pos = data->to_merge[i]->pos;
			rdat.radius = data->to_merge[i]->farthest_vertex;

			rendermap.insert(std::make_pair(data->to_merge[i], rdat));
		}

		delete[] buffers;
		data->to_merge.clear();

		glDisable(GL_RASTERIZER_DISCARD);
	}
	GLuint renderer::merge_children(std::shared_ptr<patch> p)
	{
		GLuint result = 0;
		std::shared_ptr<patch> patches[4] = { p->nw, p->ne, p->sw, p->se };

		for (auto patch : patches)
		{
			{
				auto it = std::find(data->leaf_patches.begin(), data->leaf_patches.end(), patch);
				if (it != data->leaf_patches.end())
				{
					data->leaf_patches.erase(it);
				}
				else
				{
					it = std::find(data->leaf_parents.begin(), data->leaf_parents.end(), patch);
					if (it != data->leaf_parents.end())
						data->leaf_parents.erase(it);
				}
			}
			{
				auto it = rendermap.find(patch);
				if (result != 0)
					glDeleteBuffers(1, &result);
				if (it == rendermap.end())
				{
					result = merge_children(patch);
				}
				else
				{
					result = it->second.mesh_buffer;
					rendermap.erase(it);
				}
			}
		}

		return result;
	}
	void renderer::calc_farthest()
	{
		if (info != nullptr)
		{
			bool done = false;
			do
			{
				switch (glClientWaitSync(info->sync, GL_SYNC_FLUSH_COMMANDS_BIT, 100000))
				{
				case GL_ALREADY_SIGNALED:
				case GL_CONDITION_SATISFIED:
					done = true;
					break;
				case GL_TIMEOUT_EXPIRED:
					continue;
				default:
					assert(false);
				}
			} while (!done);

			float* ptr = (float*)glMapNamedBuffer(info->results, GL_READ_ONLY);

			for (size_t i = 0; i < info->patches.size(); ++i)
			{
				if (!info->patches[i].expired())
				{
					auto patch = info->patches[i].lock();
					patch->farthest_vertex = ptr[i];
					auto it = rendermap.find(patch);
					if (it != rendermap.end())
						it->second.radius = ptr[i];
				}
			}

			glUnmapNamedBuffer(info->results);

			info->patches.clear();
			glDeleteSync(info->sync);
		}
		else
		{
			info = std::shared_ptr<computeinfo>(new computeinfo);
			glCreateBuffers(1, &info->results);
		}

		glUseProgram(discalc.program);

		glNamedBufferData(info->results, rendermap.size() * sizeof(float), nullptr, GL_STATIC_DRAW);

		size_t idx = 0;

		for (auto it = std::begin(rendermap), end = std::end(rendermap); it != end; ++it)
		{
			auto& pair = *it;

			if (pair.second.radius != std::numeric_limits<float>::max())
				continue;

			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 0, pair.second.mesh_buffer, 0, sizeof(float) * 7 * patch::SIDE_LEN * patch::SIDE_LEN);
			glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 1, info->results, idx * sizeof(float), sizeof(float));

			glDispatchCompute(patch::SIDE_LEN, ((patch::SIDE_LEN + 15) >> 4), 1);

			++idx;

			info->patches.push_back(it->first);
		}

		info->sync = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
	}

	void renderer::render(const glm::dmat4& view_mat, const void* uniforms, size_t size) const
	{
		glm::dmat4 PVM = view_mat * data->model_matrix;

		glUseProgram(shader.program);

		GLuint ubo;
		if (size != 0)
		{
			glGenBuffers(1, &ubo);
			glBufferData(GL_UNIFORM_BUFFER, size, uniforms, GL_STATIC_DRAW);
			glBindBufferRange(GL_UNIFORM_BUFFER, shader.uniforms, ubo, 0, size);
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);

		for (const auto& pair : rendermap)
		{
			glm::mat4 matrix = (glm::mat4)(PVM * glm::translate(glm::dmat4(1.0), pair.second.pos));

			glBindBuffer(GL_ARRAY_BUFFER, pair.second.mesh_buffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 3));
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 6));

			if (size != 0)
				glUniformMatrix4fv(0, 1, GL_FALSE, &matrix[0][0]);

			glDrawElements(GL_TRIANGLES, patch::NUM_INDICES, GL_UNSIGNED_INT, (void*)0);
		}

		if (size != 0)
			glDeleteBuffers(1, &ubo);
	}

	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		subdivide();
		merge();
	}

	renderer::renderer(double planet_radius) :
		planet(planet_radius)
	{
		uint32_t* indices = gen_indices_32(patch::SIDE_LEN);

		glCreateBuffers(1, &elements);
		glNamedBufferData(elements, num_indices(patch::SIDE_LEN) * sizeof(uint32_t), indices, GL_STATIC_DRAW);

		delete[] indices;

		data = planet.data;
		for (auto& side : data->to_subdivide)
		{
			side->split();
		}

		meshgen.program = compile_meshgen();
	}
}
