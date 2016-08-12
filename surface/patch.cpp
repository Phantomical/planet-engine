#include "patch.h"

#include <algorithm>

namespace planet_engine
{
	using glm::dvec3;
	using glm::fvec3;
	using glm::normalize;

	void patch::split()
	{
		assert(!subdivided());

		info info;
		info.data = data;
		info.level = level + 1;
		info.parent = shared_from_this();
		dvec3 centre = (nwc + nec + swc + sec) * 0.25;

		info.nwc = nwc;
		info.nec = (nwc + nec) * 0.5;
		info.swc = (nwc + swc) * 0.5;
		info.sec = centre;
		nw = std::make_shared<patch>(info);

		info.nwc = (nwc + nec) * 0.5;
		info.nec = nec;
		info.swc = centre;
		info.sec = (nec + sec) * 0.5;
		ne = std::make_shared<patch>(info);

		info.nwc = (nwc + swc) * 0.5;
		info.nec = centre;
		info.swc = swc;
		info.sec = (swc + sec) * 0.5;
		sw = std::make_shared<patch>(info);

		info.nwc = centre;
		info.nec = (nec + sec) * 0.5;
		info.swc = (swc + sec) * 0.5;
		info.sec = sec;
		se = std::make_shared<patch>(info);

		{
			auto it = std::find(data->leaf_patches.begin(), data->leaf_patches.end(), shared_from_this());
			if (it != data->leaf_patches.end())
				data->leaf_patches.erase(it);
		}
		data->leaf_parents.push_back(shared_from_this());

		data->leaf_patches.push_back(nw);
		data->leaf_patches.push_back(ne);
		data->leaf_patches.push_back(sw);
		data->leaf_patches.push_back(se);
	}
	void patch::merge()
	{
		assert(subdivided());
		nw->remove_internal();
		ne->remove_internal();
		sw->remove_internal();
		se->remove_internal();
		nw = ne = sw = se = nullptr;

		{
			auto it = std::find(data->leaf_parents.begin(), data->leaf_parents.end(), shared_from_this());
			if (it != data->leaf_parents.end())
				data->leaf_parents.erase(it);
		}

		data->leaf_patches.push_back(shared_from_this());
	}

	bool patch::should_subdivide(const glm::dvec3& cam_pos) const
	{
		double dis = farthest_vertex;
		if (farthest_vertex == std::numeric_limits<float>::max())
			dis = side_length();
		return level < MAX_LEVEL && length2(cam_pos - pos) * MULT < dis * dis;
	}
	bool patch::should_merge(const glm::dvec3& cam_pos) const
	{
		return length2(cam_pos - pos) * MULT > farthest_vertex * farthest_vertex;
	}

	bool patch::subdivided() const
	{
		return nw != nullptr;
	}
	double patch::side_length() const
	{
		glm::dvec3 diff = nwc - nec;

		return std::max({ diff.x, diff.y, diff.z });
	}

	size_t patch::get_max_level() const
	{
		if (!subdivided())
			return level;
		return std::max({
			nw->get_max_level(),
			ne->get_max_level(),
			sw->get_max_level(),
			se->get_max_level()
		});
	}

	void patch::remove_internal()
	{
		if (subdivided())
		{
			nw->remove_internal();
			ne->remove_internal();
			sw->remove_internal();
			se->remove_internal();
			nw = ne = sw = se = nullptr;
		}


		auto it = std::find(data->leaf_parents.begin(), data->leaf_parents.end(), shared_from_this());
		if (it != data->leaf_parents.end())
		{
			data->leaf_parents.erase(it);
		}
		else
		{
			auto it = std::find(data->leaf_patches.begin(), data->leaf_patches.end(), shared_from_this());
			if (it != data->leaf_patches.end())
				data->leaf_patches.erase(it);
		}
	}

	patch::patch(const info& info) :
		nw(nullptr),
		ne(nullptr),
		sw(nullptr),
		se(nullptr),
		nwc(info.nwc),
		nec(info.nec),
		swc(info.swc),
		sec(info.sec),
		level(info.level),
		data(info.data),
		parent(info.parent),
		farthest_vertex(std::numeric_limits<float>::max())
	{
		pos = to_sphere(nwc + nec + swc + sec, data->planet_radius);

		auto v = glm::ivec3(pos);
		auto h = std::hash<int>();
		hash = h(v.x) ^ (v.y) + v.z;
	}
}
