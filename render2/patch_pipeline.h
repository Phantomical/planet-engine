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

		struct generate_state
		{
			std::shared_ptr<patch> target;
			size_t counter;
			patch_pipeline* pipeline;

			GLuint buffers[3];
			GLuint offset;

			void cancel();

			bool can_finalize() const;
			void finalize(update_state& ustate);

			generate_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline);
		};
		struct remove_state
		{
			std::shared_ptr<patch> target;
			size_t counter;
			patch_pipeline* pipeline;

			void cancel();

			bool can_finalize() const;
			void finalize(update_state& ustate);

			remove_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline);
		};
		struct discalc_state
		{
			std::shared_ptr<patch> target;
			size_t counter;
			patch_pipeline* pipeline;

			GLuint tmpbuf;

			void calc_lengths();
			void sum_result(size_t s);
			void download_result();

			void cancel();

			bool can_finalize() const;
			void finalize(update_state& ustate);

			discalc_state(std::shared_ptr<patch> tgt, patch_pipeline* pipeline);
		};

		typedef util::any_of<
			std::shared_ptr<remove_state>,
			std::shared_ptr<generate_state>,
			std::shared_ptr<discalc_state>> exec_type;

		buffer_manager _manager;

		// Returns a boolean indicating if the job
		// had been cancelled. False indicates that
		// the job had been cancelled
		std::queue<std::function<bool()>> _job_queue;
		std::deque<exec_type> _exec_queue;

		std::map<std::shared_ptr<patch>, GLuint> _offsets;

		/* Shaders */
		GLuint _meshgen;
		GLuint _vertex_gen;
		GLuint _length_calc;
		GLuint _max_calc;
		GLuint _get_pos;

		/* Implementation Defined Constants */
		GLuint _ssbo_alignment;

		// Cache for downloading all buffer lengths at once
		GLuint _lengths;
		std::vector<std::weak_ptr<patch>> _patches;

		void gen_vertices(GLuint buffers[3], std::shared_ptr<patch> patch, GLuint* offset);
		void gen_mesh(GLuint buffers[3], std::shared_ptr<patch> patch, const GLuint* offset);

	public:
		patch_pipeline(size_t num_blocks);
		patch_pipeline(const patch_pipeline&) = delete;
		patch_pipeline(patch_pipeline&&) = delete;
		~patch_pipeline();

		void generate(std::shared_ptr<patch> patch);
		void remove(std::shared_ptr<patch> patch);
		void discalc(std::shared_ptr<patch> patch);

		void cull();

		buffer_manager& manager();
		const decltype(_offsets)& patches() const;

		update_state process(size_t n = 4);
	};
}
