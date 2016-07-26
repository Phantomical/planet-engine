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

	planet::planet(double radius, const std::function<double(double, double, double)>& noise_func)
	{
		data = std::make_shared<planet_data>();
		data->planet_radius = radius;
		data->noise_func = noise_func;

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
	}
}
