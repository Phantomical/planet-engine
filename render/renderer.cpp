#include "renderer.h"

namespace planet_engine
{
	void renderer::update(const glm::dvec3& cam_pos)
	{
		planet.update(cam_pos);

		for (auto& tuple : gen_results)
		{
			auto ptr = std::get<0>(tuple);
			auto buf = std::get<1>(tuple);
			// The original buffer
			auto todel = std::get<2>(tuple);
		}

		while (!data->to_subdivide.empty())
		{

		}
	}
}
