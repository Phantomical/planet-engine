#include "occlusion.h"
#include "shader.h"
#include "load_file.h"

#include <glm\gtc\matrix_transform.hpp>

namespace planet_engine
{
	namespace
	{
		void make_icosphere(std::vector<glm::vec3>& verts, std::vector<unsigned short>& indices)
		{
			// (1 + sqrt(5)) / 2
			static constexpr float t = 1.6180339887498948482f;
			// Multiplier so that the insphere of the tetrahedron
			// has a radius of 1.0
			static constexpr float RADIUS = 1.2584085723648189697f;

			// Create 12 vertices of icosahedron
			verts.emplace_back(-1, t, 0);
			verts.emplace_back(1, t, 0);
			verts.emplace_back(-1, -t, 0);
			verts.emplace_back(1, -t, 0);

			verts.emplace_back(0, -1, t);
			verts.emplace_back(0, 1, t);
			verts.emplace_back(0, -1, -t);
			verts.emplace_back(0, 1, -t);

			verts.emplace_back(t, 0, -1);
			verts.emplace_back(t, 0, 1);
			verts.emplace_back(-t, 0, -1);
			verts.emplace_back(-t, 0, 1);

			// Create the 20 faces of the icosahedron
			indices.insert(indices.end(),
			{
				0, 11, 5,
				0, 5, 1,
				0, 1, 7,
				0, 7, 10,
				0, 10, 11,

				1, 5, 9,
				5, 11, 4,
				11, 10, 2,
				10, 7, 6,
				7, 1, 8,

				3, 9, 4,
				3, 4, 2,
				3, 2, 6,
				3, 6, 8,
				3, 8, 9,

				4, 9, 5,
				2, 4, 11,
				6, 2, 10,
				8, 6, 7,
				9, 8, 1
			});

			for (auto& vert : verts)
			{
				vert = glm::normalize(vert) * RADIUS;
			}
		}
	}

	void occlusion::draw_occluders(const occlusion_info& ocinfo, const glm::dmat4& VP)
	{
		glBindVertexArray(occluder_vao);
		glUseProgram(occluder);

		glBindBuffer(GL_ARRAY_BUFFER, occluder_buf);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::dvec4) * ocinfo.occludees.size(),
			nullptr, GL_STREAM_DRAW);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glVertexAttribLPointer(0, 3, GL_DOUBLE, sizeof(glm::dvec4), (void*)0);
		glVertexAttribLPointer(1, 1, GL_DOUBLE, sizeof(glm::dvec4), (void*)sizeof(glm::dvec3));

		glUniform3fv(0, 1, &ocinfo.cam_forward[0]);
		glUniform3fv(1, 1, &ocinfo.cam_up[0]);
		glUniformMatrix4dv(2, 1, GL_FALSE, &VP[0][0]);

		glDrawArrays(GL_POINT, 0, (GLsizei)ocinfo.occludees.size());

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
	void occlusion::draw_occludees(const occlusion_info& ocinfo, const glm::dmat4& VP, GLuint results)
	{
		glDepthMask(GL_FALSE);

		glBindVertexArray(occludee_vao);
		glUseProgram(occludee);

		glBindBuffer(GL_ARRAY_BUFFER, occludee_buf);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * ocinfo.occludees.size(),
			nullptr, GL_STATIC_DRAW);

		glm::mat4* matrices = (glm::mat4*)glMapBufferRange(GL_ARRAY_BUFFER, 0, ocinfo.occludees.size(),
			GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
		for (size_t i = 0; i < ocinfo.occludees.size(); ++i)
		{
			glm::dmat4 mvp = VP * glm::scale(glm::dmat4(1.0), glm::dvec3(ocinfo.occludees[i].w))
				* glm::translate(glm::dmat4(1.0), glm::dvec3(ocinfo.occludees[i]));
			matrices[i] = glm::mat4(mvp);
		}
		glUnmapBuffer(GL_ARRAY_BUFFER);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)sizeof(glm::vec4));
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 2));
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 3));

		glVertexAttribDivisor(1, 1);
		glVertexAttribDivisor(2, 1);
		glVertexAttribDivisor(3, 1);
		glVertexAttribDivisor(4, 1);

		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, results);

		glDrawElementsInstanced(GL_TRIANGLES, num_indices, GL_UNSIGNED_SHORT, nullptr, (GLsizei)ocinfo.occludees.size());

		glDepthMask(GL_TRUE);
	}

	GLuint occlusion::occlusion_check(const occlusion_info& ocinfo, const glm::dmat4& VP)
	{
		GLuint zero = 0;

		glDeleteBuffers(1, &results);
		glGenBuffers(1, &results);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, results);
		glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(GLuint) * ocinfo.occludees.size(), nullptr, GL_STATIC_DRAW);
		glClearBufferData(GL_SHADER_STORAGE_BUFFER, GL_R32UI, GL_R32UI, GL_UNSIGNED_INT, &zero);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);

		draw_occluders(ocinfo, VP);

		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

		draw_occludees(ocinfo, VP, results);

		glClear(GL_DEPTH_BUFFER_BIT);

		glBindVertexArray(0);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

		return results;
	}

	occlusion::occlusion(GLuint fbo_width, GLuint fbo_height)
	{
		glGenVertexArrays(1, &occluder_vao);
		glGenVertexArrays(1, &occludee_vao);

		glGenFramebuffers(1, &fbo);

		glGenTextures(1, &depth_tex);

		GLuint buffers[4];
		glGenBuffers(4, buffers);
		occluder_buf = buffers[0];
		occludee_buf = buffers[1];
		vertices = buffers[2];
		indices = buffers[3];
		results = 0;

		util::shader occluder(false);
		occluder.vertex(util::read_file("occluder-vert.glsl"));
		occluder.geometry(util::read_file("occluder-geom.glsl"));
		occluder.link();
		occluder.check_errors({ GL_VERTEX_SHADER, GL_GEOMETRY_SHADER });

		util::shader occludee(false);
		occludee.vertex(util::read_file("occludee-vert.glsl"));
		occludee.fragment(util::read_file("occludee-frag.glsl"));
		occludee.link();
		occludee.check_errors({ GL_VERTEX_SHADER, GL_FRAGMENT_SHADER });

		this->occluder = occluder.program();
		this->occludee = occludee.program();

		glGenTextures(1, &depth_tex);
		glBindTexture(GL_TEXTURE_2D, depth_tex);

		glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH_COMPONENT32F, fbo_width, fbo_height);

		glBindVertexArray(occludee_vao);
		std::vector<glm::vec3> verts;
		std::vector<unsigned short> inds;
		make_icosphere(verts, inds);
		glBindBuffer(GL_ARRAY_BUFFER, vertices);
		glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), verts.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(unsigned short),
			inds.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		glBindVertexArray(0);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);

		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depth_tex, 0);

		assert(glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);

		glClear(GL_DEPTH_BUFFER_BIT);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	}
}
