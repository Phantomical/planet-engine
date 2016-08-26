#pragma once

#include "indexgen.h"
#include "mathutils.h"
#include "contig_vector.h"

#include <functional>
#include <memory>
#include <queue>
#include <set>

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
	
	struct update_info
	{
		std::vector<std::shared_ptr<patch>> parents_to_erase;
		std::vector<std::shared_ptr<patch>> parents_to_add;
		std::vector<std::shared_ptr<patch>> leafs_to_erase;
		std::vector<std::shared_ptr<patch>> leafs_to_add;
	};

	struct patch : std::enable_shared_from_this<patch>
	{
	public:
		static constexpr size_t SIDE_LEN = 33;
		static constexpr size_t NUM_VERTICES = num_vertices(SIDE_LEN);
		static constexpr size_t NUM_INDICES = num_indices(SIDE_LEN);
		static constexpr double SKIRT_DEPTH = 500.0;
		// Minimum distance between vertices
		static constexpr double MAX_RESOLUTION = 0.1;
		static constexpr size_t MAX_LEVEL = 0;

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

		unsigned int level;  // Level within the quadtree
		float farthest_vertex;

		std::shared_ptr<patch> nw;
		std::shared_ptr<patch> ne;
		std::shared_ptr<patch> sw;
		std::shared_ptr<patch> se;

		glm::dvec3 nwc; // Quadrant 0
		glm::dvec3 nec; // Quadrant 1
		glm::dvec3 swc; // Quadrant 2
		glm::dvec3 sec; // Quadrant 3

		glm::dvec3 pos; // Position in planet space
		glm::dvec3 actual_pos; // pos transformed by the noise function
		
		std::shared_ptr<planet_data> data;

		std::weak_ptr<patch> parent;
		
		patch(const info& info);

		void split(update_info& info);
		void merge(update_info& info);

	private:
		static constexpr double MULT = 1.0 / (10.0);

	public:
		bool should_subdivide(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel) const;
		bool should_merge(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel) const;

		bool subdivided() const;
		double side_length() const;

		size_t get_max_level() const;

	private:
		void remove_internal(update_info& info);
	};

	struct planet_data
	{
		double planet_radius;
		double skirt_depth;
		double scale;
		size_t max_level;
		std::set<std::shared_ptr<patch>> leaf_patches;
		std::set<std::shared_ptr<patch>> leaf_parents;
		std::vector<std::shared_ptr<patch>> to_add;
		std::vector<std::shared_ptr<patch>> to_remove;
		glm::dmat4 model_matrix;
	};
}
