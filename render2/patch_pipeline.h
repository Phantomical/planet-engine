#pragma once

#include "patch.h"
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
		static constexpr size_t SIDE_LEN = patch::SIDE_LEN;
		static constexpr size_t NUM_VERTICES = patch::NUM_VERTICES;
		static constexpr size_t NUM_ELEMENTS = patch::NUM_INDICES;
		static constexpr double SKIRT_DEPTH = patch::SKIRT_DEPTH;
		static constexpr size_t SHADER_GROUP_SIZE = 128;
		static constexpr size_t VERTEX_SIZE = sizeof(float) * 8;
		static constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;
		static constexpr size_t VERTEX_BUFFER_SIZE = (SIDE_LEN + 2) * (SIDE_LEN + 2) * sizeof(float) * 4;
		static constexpr size_t NUM_INVOCATIONS = ((SIDE_LEN + 2) * (SIDE_LEN + 2) + SHADER_GROUP_SIZE - 1) / SHADER_GROUP_SIZE;
		static constexpr size_t GEN_VERTEX_INVOCATIONS = (SIDE_LEN + 2 + 7) / 7;

		struct _upsample_state
		{
			enum execution_state : uint_least8_t
			{
				START = 0,
				DONE = 1,
				ERROR_STATE = 0xFF
			};

			execution_state state;
			patch_pipeline* pipeline;
			std::shared_ptr<patch> target_patch;
			// Order: NW, NE, SW, SE
			std::shared_ptr<patch> children[4];

			GLuint offset;

			bool is_done() const;
			void step();

			_upsample_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);
		};
		struct _remove_state
		{
			enum execution_state : uint_least8_t
			{
				START = 0,
				DONE = 1,
				ERROR_STATE = 0xFF
			};

			execution_state state;
			patch_pipeline* pipeline;
			std::shared_ptr<patch> target_patch;

			GLuint offset;

			size_t ctr;

			bool is_done() const;
			void step();

			_remove_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);
		};

		struct subdivide_state
		{
			size_t counter;
			patch_pipeline* pipeline;

			GLuint buffers[4][2]

			GLuint offsets[4];
			std::shared_ptr<patch> children[4];
			GLuint offset;
			std::shared_ptr<patch> parent;

			void gen_vertices(size_t idx);
			void gen_mesh(size_t idx);

			subdivide_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);

			bool can_finalize();
			void get_state(update_state& ustate);
		};
		struct merge_state
		{
			size_t counter;
			patch_pipeline* pipeline;

			std::shared_ptr<patch> parent;
			std::shared_ptr<patch> children[4];

			GLuint offset;
			GLuint offsets[4];

			GLuint buffers[2];

			merge_state(std::shared_ptr<patch> patch, patch_pipeline* pipeline);

			void gen_vertices();
			void gen_mesh();

			bool can_finalize();
			void get_state(update_state& ustate);
		};
		struct remove_state
		{
			remove_state(std::shared_ptr<patch> patch, patch_pipeline* pipeline);

			bool can_finalize();
			void get_state(update_state& ustate);

			std::shared_ptr<patch> patch;
			patch_pipeline* pipeline;
		};
		struct generate_state
		{
			generate_state(std::shared_ptr<patch> patch, patch_pipeline* pipeline);

			void gen_vertices();
			void gen_mesh();

			bool can_finalize();
			void get_state(update_state& ustate);

			size_t counter;
			patch_pipeline* pipeline;

			std::shared_ptr<patch> patch;
			GLuint offset;

			GLuint uniforms;
			GLuint vertex_buffer;
		};

		typedef util::any_of<
			std::shared_ptr<subdivide_state>,
			std::shared_ptr<merge_state>,
			std::shared_ptr<remove_state>,
			std::shared_ptr<generate_state>> exec_type;

		buffer_manager _manager;

		std::queue<std::function<void()>> _job_queue;
		std::queue<exec_type> _exec_queue;

		std::map<std::shared_ptr<patch>, GLuint> _offsets;

		GLuint _meshgen;
		GLuint _vertex_gen;
		GLuint _upsampler;

		void gen_vertices(GLuint buffers[2], std::shared_ptr<patch> patch, GLuint* offset);
		void gen_mesh(GLuint buffers[2], std::shared_ptr<patch> patch, GLuint* offset);

	public:
		patch_pipeline(size_t num_blocks);
		patch_pipeline(const patch_pipeline&) = delete;
		patch_pipeline(patch_pipeline&&) = delete;
		~patch_pipeline();

		void subdivide(std::shared_ptr<patch> patch);
		void merge(std::shared_ptr<patch> patch);
		void generate(std::shared_ptr<patch> patch);
		void remove(std::shared_ptr<patch> patch);

		void cull();

		buffer_manager& manager();
		const decltype(_offsets)& patches() const;

		update_state process(size_t n = 4);

		static bool can_upsample(std::shared_ptr<patch> patch);
	};
}
