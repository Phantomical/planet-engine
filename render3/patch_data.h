
#include <glm\glm.hpp>

namespace planet_engine
{
	struct planet_data
	{
		double planet_radius;
		double scale;
		// Texture tiling distance for textures
		// in each direction
		glm::vec3 texture_tile_dist;
	};

	struct patch_data
	{
		glm::dvec3 nwc; // Quadrant 0
		double _vpad1;
		glm::dvec3 nec; // Quadrant 1
		double _vpad2;
		glm::dvec3 swc; // Quadrant 2
		double _vpad3;
		glm::dvec3 sec; // Quadrant 3
		double _vpad4;

		glm::dvec3 pos; // Position in planet space
		double _vpad5;

		// Child indexes
		unsigned int nw;
		unsigned int ne;
		unsigned int sw;
		unsigned int se;

		unsigned int level; // Level within the quadtree
		unsigned int parent; // Index of the parent of this patch
		float farthest_vertex;

		unsigned int index;
	};
}
