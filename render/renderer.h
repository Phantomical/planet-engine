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
		GLuint mesh_buffer;
		glm::dvec3 pos;
	};

	class renderer
	{
	public:
		std::shared_ptr<planet_data> data;
		planet planet;
		std::map<std::shared_ptr<patch>, render_data> rendermap;
		bool keep_meshes;
		// A buffer containing patch::NUM_VERTICES unspecified floats
		// its values are never used. Its only use is to make sure that
		// the transform feedback shader is called with the correct 
		// value of gl_VertexID to calculate the vertex position
		GLuint dummy_buffer;
		GLuint meshgen_program;
		GLuint uniform_index;
		
		// Contains the logic for calculating the patches of the new mesh
		void subdivide();
		void merge();

		void update(const glm::dvec3& cam_pos);
	};
	
}
