#pragma once

#include "patch.h"

namespace planet_engine
{
	struct planet
	{
		std::shared_ptr<patch> sides[6];
		std::shared_ptr<planet_data> data;

		planet(double radius);

		void update(const glm::dvec3& cam_pos);
	};
}
