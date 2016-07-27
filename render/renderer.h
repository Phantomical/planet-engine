#pragma once

#include "planet.h"
#include "gl_core.h"
#include <vector>

namespace planet_engine
{
	class renderer
	{
		std::shared_ptr<planet_data> data;
		planet planet;
	};
	
}
