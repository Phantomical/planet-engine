#pragma once

#include "planet.h"
#include "gl_core.h"
#include <vector>
#include <map>
#include <glm/glm.hpp>

namespace planet_engine
{
	struct renderer_data
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
		std::map<std::shared_ptr<patch>, renderer_data> parent_map;
		std::map<std::shared_ptr<patch>, renderer_data> rendermap;
		std::deque<std::tuple<std::shared_ptr<patch>, GLuint, GLuint>> gen_results;
		bool keep_meshes;

		void update(const glm::dvec3& cam_pos);
	};
	
}
