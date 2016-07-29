#include "planet.h"

namespace planet_engine
{
	using glm::dvec3;

	void set_info(patch::info& info, const dvec3& nwc, const dvec3& nec, const dvec3& swc, const dvec3& sec)
	{
		info.nwc = nwc;
		info.nec = nec;
		info.swc = swc;
		info.sec = sec;
	}

	planet::planet(double radius)
	{
		data = std::make_shared<planet_data>();
		data->planet_radius = radius;

		patch::info info;
		info.level = 0;
		info.data = data;

		set_info(info, dvec3(radius, radius, -radius), dvec3(-radius, radius, -radius), dvec3(radius, radius, radius), dvec3(-radius, radius, radius));
		sides[0] = std::make_shared<patch>(info);

		set_info(info, dvec3(-radius, -radius, radius), dvec3(-radius, -radius, -radius), dvec3(radius, -radius, radius), dvec3(radius, -radius, -radius));
		sides[1] = std::make_shared<patch>(info);

		set_info(info, dvec3(-radius, -radius, -radius), dvec3(-radius, radius, -radius), dvec3(radius, -radius, -radius), dvec3(radius, radius, -radius));
		sides[2] = std::make_shared<patch>(info);

		set_info(info, dvec3(radius, radius, radius), dvec3(-radius, radius, radius), dvec3(radius, -radius, radius), dvec3(-radius, -radius, radius));
		sides[3] = std::make_shared<patch>(info);

		set_info(info, dvec3(-radius, radius, radius), dvec3(-radius, radius, -radius), dvec3(-radius, -radius, radius), dvec3(-radius, -radius, -radius));
		sides[4] = std::make_shared<patch>(info);

		set_info(info, dvec3(radius, -radius, -radius), dvec3(radius, radius, -radius), dvec3(radius, -radius, radius), dvec3(radius, radius, radius));
		sides[5] = std::make_shared<patch>(info);

		for (auto side : sides)
		{
			data->to_subdivide.push_back(side);
		}
	}

	void planet::update(const glm::dvec3& cam_pos)
	{
		for (auto& leaf : data->leaf_patches)
		{
			if (leaf->should_subdivide(cam_pos))
			{
				data->to_subdivide.push_back(leaf);
			}
		}

		for (auto& lp : data->leaf_parents)
		{
			if (lp->should_merge(cam_pos))
			{
				data->to_merge.push_back(lp);
			}
		}
	}
}
