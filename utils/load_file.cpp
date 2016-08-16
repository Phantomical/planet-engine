#include "load_file.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

namespace planet_engine
{
	namespace util
	{
		std::string read_file(const std::string& path)
		{
			std::ifstream t(path);

			if (!t.is_open())
			{
				std::cout << "Unable to open " << path << std::endl;
				assert(false);
			}

			std::stringstream buffer;
			buffer << t.rdbuf();
			return buffer.str();
		}
	}
}
