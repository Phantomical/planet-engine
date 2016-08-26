#pragma once

#include "constants.h"
#include "gl_core.h"
#include "buffer_manager.h"
#include "any_of.h"

#include <map>
#include <queue>
#include <functional>
#include <unordered_map>

namespace planet_engine
{
	typedef sparse_managed_buffer buffer_manager;

	struct DrawElementsIndirectCommand
	{
		GLuint count;
		GLuint instanceCount;
		GLuint firstIndex;
		GLuint baseVertex;
		GLuint baseInstance;
	};
	struct MoveCommand
	{
		GLuint source;
		GLuint dest;
		GLuint is_new;
	};
	struct update_state
	{
		std::vector<DrawElementsIndirectCommand> commands;
		std::vector<MoveCommand> movecommands;

		void concat(const update_state& ust);
	};

	struct mesh_info
	{
		glm::dvec3 pos;
		double planet_radius;
		glm::dvec3 nwc;
		double skirt_depth;
		glm::dvec3 nec;
		double scale;
		glm::dvec3 swc;
		double _pad4;
		glm::dvec3 sec;
		double _pad5;
	};

	class patch_pipeline
	{
	private:
		static constexpr size_t SIDE_LEN = constants::SIDE_LEN;
		static constexpr size_t NUM_VERTICES = constants::NUM_VERTICES;
		static constexpr size_t NUM_ELEMENTS = constants::NUM_ELEMENTS;
		static constexpr double SKIRT_DEPTH = constants::SKIRT_DEPTH;
		static constexpr size_t SHADER_GROUP_SIZE = constants::COMPUTE_GROUP_SIZE;
		static constexpr size_t VERTEX_SIZE = constants::VERTEX_SIZE;
		static constexpr size_t MESH_SIZE = constants::MESH_SIZE;
		static constexpr size_t VERTEX_BUFFER_SIZE = (SIDE_LEN + 2) * (SIDE_LEN + 2) * sizeof(float) * 4;
		static constexpr size_t NUM_INVOCATIONS = ((SIDE_LEN + 2) * (SIDE_LEN + 2) + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;
		static constexpr size_t GEN_VERTEX_INVOCATIONS = (SIDE_LEN + 2 + 7) / 8;
		static constexpr size_t CANCELLED_COUNTER_VALUE = 0xFF;
		static constexpr size_t MAX_SCAN_DEPTH = 512;
		static constexpr size_t LENGTH_CACHE_SIZE = 32;
		
		buffer_manager _manager;

		std::deque<std::shared_ptr<patch>> _generate;
		std::deque<std::shared_ptr<patch>> _remove;

		std::map<std::shared_ptr<patch>, GLuint> _offsets;

		size_t cull_counter;

		/* Shaders */
		GLuint _meshgen;
		GLuint _vertex_gen;
		GLuint _length_calc;
		GLuint _max_calc;
		GLuint _get_pos;
		GLuint _compact;

		/* Implementation Defined Constants */
		GLuint _ssbo_alignment;
		GLuint _ubo_alignment;

		// Cache for downloading all buffer lengths at once
		GLuint _lengths;
		std::vector<std::weak_ptr<patch>> _patches;

		void dispatch_vertex_gen(GLuint size, GLuint vertices, GLuint infos);
		void dispatch_get_pos(GLuint size, GLuint infos, GLuint positions);
		void dispatch_gen_meshes(GLuint size, GLuint infos, GLuint verts, GLuint offsets);
		void dispatch_length_calc(GLuint size, GLuint infos, GLuint offsets);

		void gen_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, size_t size);
		void remove_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, size_t size);

	public:
		patch_pipeline(size_t num_blocks);
		patch_pipeline(const patch_pipeline&) = delete;
		patch_pipeline(patch_pipeline&&) = delete;
		~patch_pipeline();

		void generate(std::shared_ptr<patch> patch);
		void remove(std::shared_ptr<patch> patch);

		void cull();

		buffer_manager& manager();
		const decltype(_offsets)& patches() const;

		update_state process();
	};
}
