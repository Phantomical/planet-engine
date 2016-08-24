#include "planet.h"
#include "findutils.h"

#include <stack>

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

	planet::planet(double radius, double scale)
	{
		data = std::make_shared<planet_data>();
		data->planet_radius = radius;
		data->scale = scale;
		data->max_level = static_cast<size_t>(std::log2(radius / patch::MAX_RESOLUTION));

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
			data->to_add.push_back(side);
			data->leaf_patches.push_back(side);
		}
	}

	void planet::update(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel)
	{
		update_info uinfo;

		for (auto& patch : data->leaf_patches)
		{
			assert(!patch->is);
			if (patch->should_subdivide(cam_pos, cam_vel))
			{
				patch->split(uinfo);
			}
		}

		for (auto& patch : data->leaf_parents)
		{
			if (patch->should_merge(cam_pos, cam_vel) && patch->subdivided())
			{
				patch->merge(uinfo);
			}
		}

		for (auto patch : uinfo.leafs_to_erase)
		{
			auto it = util::find(data->leaf_patches, patch);
			if (it != data->leaf_patches.end())
				data->leaf_patches.erase(it);
		}

		for (auto patch : uinfo.leafs_to_add)
		{
			if (!patch->subdivided())
				data->leaf_patches.push_back(patch);
		}

		for (auto patch : uinfo.parents_to_erase)
		{
			auto it = util::find(data->leaf_parents, patch);
			if (it != data->leaf_parents.end())
				data->leaf_parents.erase(it);
		}

		for (auto patch : uinfo.parents_to_add)
		{
			if (patch->subdivided())
				data->leaf_parents.push_back(patch);
		}
	}
	void planet::reset()
	{
		{
			std::stack<std::shared_ptr<patch>> stack;

			stack.push(sides[0]);
			stack.push(sides[1]);
			stack.push(sides[2]);
			stack.push(sides[3]);
			stack.push(sides[4]);
			stack.push(sides[5]);

			while (!stack.empty())
			{
				auto p = stack.top();
				stack.pop();

				if (p->subdivided())
				{
					stack.push(p->nw);
					stack.push(p->ne);
					stack.push(p->sw);
					stack.push(p->se);
				}

				if (p->level != 0)
					data->to_remove.push_back(p);
			}
		}

		for (size_t i = 0; i < 6; ++i)
		{
			if (sides[i]->subdivided())
				data->to_add.push_back(sides[i]);
		}
	}

	size_t planet::get_max_level() const
	{
		return std::max({
			sides[0]->get_max_level(),
			sides[1]->get_max_level(),
			sides[2]->get_max_level(),
			sides[3]->get_max_level(),
			sides[4]->get_max_level(),
			sides[5]->get_max_level()
		});
	}
}
