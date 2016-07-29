#pragma once

#include "planet.h"
#include "gl_core.h"
#include <vector>
#include <map>
#include <glm/glm.hpp>

namespace planet_engine
{
	struct render_data
	{
		GLuint mesh_buffer; // The OpenGL buffer ID of the mesh
		glm::dvec3 pos;     // The position of the mesh in planet space
		float radius;       // The distance from the farthest vertex to the position
	};

	class renderer
	{
	public:
		struct computeinfo;

		std::shared_ptr<planet_data> data;
		planet planet;
		std::map<std::shared_ptr<patch>, render_data> rendermap;
		std::shared_ptr<computeinfo> info;

		// Buffer containing all the indices for the mesh
		GLuint elements;
		struct
		{
			GLuint program; // OpenGL program ID
			GLuint index;   // Index of input uniform block
		} meshgen;
		struct
		{
			GLuint program;  // OpenGL program ID
			GLuint in_index; // Index of input vertex buffer
			GLuint results;  // Index of results buffer
		} discalc;
		struct
		{
			GLuint program;  // OpenGL program ID
			GLuint uniforms; // Uniform Buffer Binding index
		} shader;
		
		GLuint merge_children(std::shared_ptr<patch> patch);
		// Contains the logic for calculating the patches of the new mesh
		void subdivide();
		void merge();
		// Calculates the farthest vertex for all 
		// the patches where it hasn't been done yet
		void calc_farthest();

	public:
		void render(const glm::dmat4& MVP_mat, const void* uniforms, size_t size) const;

		void update(const glm::dvec3& cam_pos);

		renderer(double planet_radius);
	};
	
}
