#ifndef GPU_SURFACE_PATCH_ENGINE
#define GPU_SURFACE_PATCH_ENGINE

#include <glm\glm.hpp>

#ifdef GL_core_profile
// GLSL definition
struct patch_data
{
	double _pdata[15];
	uint level;
	uint parent;
	uvec4 children;
	vec3 pos_offset;
	float farthest_vertex;
};

#define POS(var) dvec3(var._pdata[0x0], var._pdata[0x1], var._pdata[0x2])
#define NWC(var) dvec3(var._pdata[0x3], var._pdata[0x4], var._pdata[0x5])
#define NEC(var) dvec3(var._pdata[0x6], var._pdata[0x7], var._pdata[0x8])
#define SWC(var) dvec3(var._pdata[0x9], var._pdata[0xA], var._pdata[0xB])
#define SEC(var) dvec3(var._pdata[0xC], var._pdata[0xD], var._pdata[0xE])

#define INVALID_LEVEL 0xFFFFFFFF

#else
namespace planet_engine
{
	namespace gpu_surface
	{
		// C++ definition
		struct patch_data
		{
			glm::dvec3 pos;
			glm::dvec3 nwc;
			glm::dvec3 nec;
			glm::dvec3 swc;
			glm::dvec3 sec;
			glm::uint level;
			glm::uint parent;
			glm::uvec4 children;
			glm::vec3 pos_offset;
			float farthest_vertex;
		};

		static constexpr glm::uint INVALID_LEVEL = 0xFFFFFFFF;
	}
}
#endif

#endif