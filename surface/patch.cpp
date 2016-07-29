#include "patch.h"

#include <algorithm>

namespace planet_engine
{
	using glm::dvec3;
	using glm::fvec3;
	using glm::normalize;

	void patch::split()
	{
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
	}
	void patch::merge()
	{
		nw = ne = sw = se = nullptr;
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
	}
}
