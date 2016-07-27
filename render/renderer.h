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
	struct buffer_val 
	{
		glm::dvec3 pos;
		double _pad1;
		glm::dvec3 nwc;
		double _pad2;
		glm::dvec3 nec;
		double _pad3;
		glm::dvec3 swc;
		double _pad3;
		glm::dvec3 sec;
		double _pad4;
		double planet_radius;
		double skirt_depth;
		double scale;
		double _pad5;
	};

	class renderer
	{
	public:
		std::shared_ptr<planet_data> data;
		planet planet;
		std::map<std::shared_ptr<patch>, render_data> parent_map;
		std::map<std::shared_ptr<patch>, render_data> rendermap;
		bool keep_meshes;
		GLuint dummy_buffer;
		GLuint meshgen_program;
		GLuint uniform_index;
		
		void update(const glm::dvec3& cam_pos);
	};
	
}
