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

	struct mesh_vertex
	{
		// Vertex position
		glm::dvec3 vertex;
		// Vector pointing outward from the centre of the planet
		glm::dvec3 texcoord;
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
		float farthest_vertex;

		std::shared_ptr<planet_data> data;

		std::weak_ptr<patch> parent;

		patch(const info& info);

		void split();
		void merge();

		bool is_leaf() const
		{
			return !nw;
		}

		bool should_subdivide(const glm::dvec3& cam_pos) const
		{
			static constexpr double MULT = 1.0 / (2.5 * 2.5);

			return length2(cam_pos - pos) * MULT < farthest_vertex * farthest_vertex;
		}
		bool should_merge(const glm::dvec3& cam_pos) const
		{
			static constexpr double MULT = 1.0 / (2.5 * 2.5);

			return length2(cam_pos - pos) * MULT > farthest_vertex * farthest_vertex;
		}
	};

	struct planet_data
	{
		double planet_radius;
		contig_vector<std::shared_ptr<patch>> leaf_patches;
		contig_vector<std::shared_ptr<patch>> leaf_parents;
		std::vector<std::shared_ptr<patch>> to_subdivide;
		std::vector<std::shared_ptr<patch>> to_merge;
		glm::dmat4 model_matrix;
	};
}
