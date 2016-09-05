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
		
		struct gen_meshes_state
		{
		private:
			enum states
			{
				INITIAL,
				DISPATCH_VERTEX_GEN,
				DISPATCH_GEN_MESHES,
				DISPATCH_LENGTH_CALC,
				DISPATCH_MAX_CALC,
				DISPATCH_COMPACT,
				RETRIEVE_RESULTS,
				DONE
			};
			
			std::vector<std::shared_ptr<patch>> patches;
			patch_pipeline* pipeline;
			GLuint* offsets;
			size_t state;
			GLuint buffers[6];
			GLuint size;

		public:
			// Returns the barriers that need to be executed
			GLenum execute_next(update_state& ustate);

			bool is_done() const;

			gen_meshes_state(const std::shared_ptr<patch>* patches, GLuint size, patch_pipeline* pipeline);
			~gen_meshes_state();

			gen_meshes_state(const gen_meshes_state&) = delete;
			gen_meshes_state(gen_meshes_state&&) = delete;
		};
		struct remove_state
		{
		private:
			size_t state;
			patch_pipeline* pipeline;

			std::vector<std::shared_ptr<patch>> patches;

		public:
			void execute_next(update_state& ustate);

			bool is_done() const;
		};

		buffer_manager _manager;

		std::deque<std::shared_ptr<patch>> _generate;
		std::deque<std::shared_ptr<patch>> _remove;

		std::deque<gen_meshes_state> _gen_states;
		std::deque<remove_state> _remove_state;

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
		void dispatch_length_calc(GLuint size, GLuint offsets, GLuint lengths, GLuint positions);
		void dispatch_max_calc(GLuint size, GLuint lengths);
		void dispatch_compact(GLuint size, GLuint lengths, GLuint target);

		void gen_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, GLuint size);
		void remove_meshes(update_state& ustate, const std::shared_ptr<patch>* patches, GLuint size);

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
