#include "patch.h"
#include "defs.h"
#include "findutils.h"

#undef max
#undef min

namespace planet_engine
{
	using glm::dvec3;
	using glm::fvec3;
	using glm::normalize;

	void patch::split(update_info& uinfo)
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

		data->to_remove.push_back(shared_from_this());
		data->to_add.push_back(nw);
		data->to_add.push_back(ne);
		data->to_add.push_back(sw);
		data->to_add.push_back(se);

		uinfo.leafs_to_erase.push_back(shared_from_this());
		uinfo.parents_to_add.push_back(shared_from_this());

		uinfo.leafs_to_add.push_back(nw);
		uinfo.leafs_to_add.push_back(ne);
		uinfo.leafs_to_add.push_back(sw);
		uinfo.leafs_to_add.push_back(se);
	}
	void patch::merge(update_info& uinfo)
	{
		//assert(subdivided());
		if (!subdivided())
		{
			OutputDebug("[PATCH] Invalid merge called.\n");
			return;
		}

		nw->remove_internal(uinfo);
		ne->remove_internal(uinfo);
		sw->remove_internal(uinfo);
		se->remove_internal(uinfo);
		nw = ne = sw = se = nullptr;

		uinfo.parents_to_erase.push_back(shared_from_this());
		uinfo.leafs_to_add.push_back(shared_from_this());

		data->to_add.push_back(shared_from_this());
	}

	bool patch::should_subdivide(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel) const
	{
		return level < data->max_level && side_length() > glm::length(cam_vel) 
			&& length(cam_pos - actual_pos) * MULT < farthest_vertex;
	}
	bool patch::should_merge(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel) const
	{
		return length(cam_pos - actual_pos) * MULT > farthest_vertex;
	}

	bool patch::subdivided() const
	{
		return nw != nullptr;
	}
	double patch::side_length() const
	{
		using std::abs;

		glm::dvec3 diff = nwc - nec;

		return std::max({ abs(diff.x), abs(diff.y), abs(diff.z) });
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

	void patch::remove_internal(update_info& uinfo)
	{
		if (subdivided())
		{
			nw->remove_internal(uinfo);
			ne->remove_internal(uinfo);
			sw->remove_internal(uinfo);
			se->remove_internal(uinfo);
			nw = ne = sw = se = nullptr;
		}

		uinfo.leafs_to_erase.push_back(shared_from_this());
		uinfo.parents_to_erase.push_back(shared_from_this());

		data->to_remove.push_back(shared_from_this());
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
		parent(info.parent)
	{
		pos = to_sphere(nwc + nec + swc + sec, data->planet_radius);
		// Temporary assignments
		// These should be replaced with more accurate values
		// when the mesh is generated
		actual_pos = pos;
		farthest_vertex = side_length();
	}
}
