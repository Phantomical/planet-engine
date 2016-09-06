#pragma once

#include "gl_core.h"

#include <vector>
#include <glm\glm.hpp>

namespace planet_engine
{
	struct occlusion_info
	{
		std::vector<glm::dvec4> occluders;
		std::vector<glm::dvec4> occludees;
		glm::vec3 cam_up;
		glm::vec3 cam_forward;
	};

	class occlusion
	{
	private:
		GLuint occluder_vao;
		GLuint occludee_vao;
		GLuint fbo;

		/* Textures */
		GLuint depth_tex;

		/* Buffers */
		GLuint occluder_buf;
		GLuint occludee_buf;
		GLuint vertices;
		GLuint indices;
		GLuint results;

		/* Shaders */
		GLuint occluder;
		GLuint occludee;

		/* Other */
		GLuint num_indices;

		void draw_occluders(const occlusion_info& ocinfo, const glm::dmat4& VP);
		void draw_occludees(const occlusion_info& ocinfo, const glm::dmat4& VP, GLuint results);

	public:
		// Returns a buffer of uints which are either 1 or 0 to indicate whether the 
		// mesh indicated by position should be drawn. That buffer is valid until the
		// next time occlusion_check is called
		GLuint occlusion_check(const occlusion_info& ocinfo, const glm::dmat4& VP);

		occlusion(GLuint fbo_width, GLuint fbo_height);
	};
}
