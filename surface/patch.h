#pragma once

#include "indexgen.h"
#include "mathutils.h"
#include "contig_vector.h"

#include <functional>
#include <memory>
#include <queue>

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
	struct planet_data;

	struct vertex
	{
		// Vertex position
		glm::fvec3 vertex;
		// Vector pointing outward from the centre of the planet
		glm::fvec3 texcoord;
		// How far this point was displaced by the noise function
		float displacement;
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
			std::weak_ptr<patch> parent;
			std::shared_ptr<planet_data> data;
		};
		struct mesh
		{
			vertex data[NUM_VERTICES];    // Vertex data
			double farthest_vertex;       // Distance from adj_pos to the farthest vertex
			glm::dvec3 adj_pos;           // Position adjusted for terrain height
			std::shared_ptr<patch> patch; // Patch that this mesh was generated for

			bool should_subdivide(const glm::dvec3& cam_pos)
			{
				static constexpr double MULT = 1.0 / (2.5 * 2.5);

				return length2(cam_pos - adj_pos) * MULT < farthest_vertex * farthest_vertex;
			}
			bool should_merge(const glm::dvec3& cam_pos)
			{
				static constexpr double MULT = 1.0 / (2.5 * 2.5);

				return length2(cam_pos - adj_pos) * MULT > farthest_vertex * farthest_vertex;
			}
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

		std::shared_ptr<planet_data> data;

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
			data(info.data),
			parent(info.parent)
		{
			pos = to_sphere(nwc + nec + swc + sec, data->planet_radius);
		}

		void split();
		void merge();

		std::shared_ptr<mesh> gen_mesh() const;
		bool is_leaf() const
		{
			return !nw;
		}
	};

	struct planet_data
	{
		double planet_radius;
		std::function<double(double, double, double)> noise_func;
		contig_vector<std::shared_ptr<patch::mesh>> leaf_patches;
		contig_vector<std::shared_ptr<patch::mesh>> leaf_parents;
		std::queue<std::shared_ptr<patch>> to_subdivide;
		std::queue<std::shared_ptr<patch>> to_merge;
	};
}
