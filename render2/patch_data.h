#include "is_glsl.h"

#if !IS_GLSL
// The GLSL include preprocessing step doesn't allow nested includes
// so include guards aren't needed for glsl (also #pragma once wouldn't
// be a valid preprocessor instruction
#pragma once

#include <glm\glm.hpp>

#define uint unsigned int
#define vec2 glm::vec2
#define vec3 glm::vec3
#define vec4 glm::vec4
#define dvec2 glm::dvec2
#define dvec3 glm::dvec3
#define dvec4 glm::dvec4
#define ivec2 glm::ivec2
#define ivec3 glm::ivec3
#define ivec4 glm::ivec4
#define uvec2 glm::uvec2
#define uvec3 glm::uvec3
#define uvec4 glm::uvec4
#endif

#if !IS_GLSL
namespace planet_engine
{
#endif
	struct planet_data
	{
		double planet_radius;
		double scale;
		// Texture tiling distance for textures
		// in each direction
		vec3 texture_tile_dist;
	};

	struct patch_data
	{
		// Indexes of children
		uint nw;
		uint ne;
		uint sw;
		uint se;

		// Corners
		dvec3 nwc; // Quadrant 0
		dvec3 nec; // Quadrant 1
		dvec3 swc; // Quadrant 2
		dvec3 sec; // Quadrant 3

		dvec3 pos; // Position in planet space
		dvec3 actual_pos; // pos transformed by the noise function

		uint level; // Level within the quadtree
		uint parent; // Index of the parent of this patch
		float farthest_vertex;
	};

#if !IS_GLSL
}
#endif

#if !IS_GLSL
#undef uint
#undef vec2
#undef vec3
#undef vec4
#undef dvec2
#undef dvec3
#undef dvec4
#undef ivec2
#undef ivec3
#undef ivec4
#undef uvec2
#undef uvec3
#undef uvec4
#endif
