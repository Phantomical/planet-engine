#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace planet_engine
{
	struct patch
	{
		std::shared_ptr<patch> nw;
		std::shared_ptr<patch> ne;
		std::shared_ptr<patch> sw;
		std::shared_ptr<patch> se;

		glm::dvec3 adjusted_centre;

		glm::dvec3 nwc;
		glm::dvec3 nec;
		glm::dvec3 swc;
		glm::dvec3 sec;

		glm::dvec3 position;

		unsigned int level;  // Level within the quadtree
		double side_len;     // Side lenght of the patch

		patch* parent;
	};
}
