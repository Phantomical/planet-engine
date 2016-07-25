#pragma once

#include "indexgen.h"
#include "mathutils.h"
#include "contig_vector.h"

#include <functional>
#include <memory>

namespace planet_engine
{
	/*
	Quadrant info

	_______________
	|nwc	|		|nec
	|	0	|	1	|
	|_______|_______|
	|		|		|
	|	2	|	3	|
	|_______|_______|
	swc				 sec
	*/

	struct patch;

	struct vertex
	{
		// Vertex position
		glm::fvec3 vertex;
		// Vector pointing outward from the centre of the planet
		glm::fvec3 texcoord;
		// How far this point was displaced by the noise function
		float displacement;
	};

	struct planet_data
	{
		double planet_radius;
		std::function<double(double, double, double)> noise_func;
		contig_vector<std::shared_ptr<patch>> leaf_patches;
		contig_vector<std::shared_ptr<patch>> leaf_parents;
	};

	struct patch : std::enable_shared_from_this<patch>
	{
	public:
		static constexpr size_t SIDE_LEN = 129;
		static constexpr size_t NUM_VERTICES = num_vertices(SIDE_LEN);
		static constexpr size_t NUM_INDICES = num_indices(SIDE_LEN);
		static constexpr double SKIRT_DEPTH = 500.0;

		struct info
		{
			glm::dvec3 nec;
			glm::dvec3 nwc;
			glm::dvec3 sec;
			glm::dvec3 swc;
			unsigned int level;
			double side_len;
			std::weak_ptr<patch> parent;
			planet_data* data;
		};
		struct mesh
		{
			vertex data[NUM_VERTICES]; // Vertex data
			double farthest_vertex;    // Distance from adj_pos to the farthest vertex
			glm::dvec3 adj_pos;        // Position adjusted for terrain height
		};

		std::shared_ptr<patch> nw;
		std::shared_ptr<patch> ne;
		std::shared_ptr<patch> sw;
		std::shared_ptr<patch> se;

		glm::dvec3 nwc; // Quadrant 0
		glm::dvec3 nec; // Quadrant 1
		glm::dvec3 swc; // Quadrant 2
		glm::dvec3 sec; // Quadrant 3

		glm::dvec3 pos; // Position in planet space

		unsigned int level;  // Level within the quadtree
		double side_len;     // Side lenght of the patch

		planet_data* data;

		std::weak_ptr<patch> parent;

		patch(const info& info) :
			nw(nullptr),
			ne(nullptr),
			sw(nullptr),
			se(nullptr),
			nwc(info.nwc),
			nec(info.nec),
			swc(info.swc),
			sec(info.sec),
			level(info.level),
			side_len(info.side_len),
			data(info.data),
			parent(info.parent)
		{
			pos = to_sphere(nwc + nec + swc + sec, data->planet_radius);
		}

	private:
		std::shared_ptr<mesh> gen_mesh();
	};
}
