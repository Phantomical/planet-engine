#pragma once

#include "patch.h"
#include "gl_core.h"
#include "buffer_manager.h"
#include "any_of.h"

#include <map>
#include <queue>
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

	struct pipeline_item
	{
		enum item_type : uint_least8_t
		{
			ADD,
			REMOVE
		};

		item_type type;
		std::weak_ptr<patch> patch;
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
		
		struct generate_state
		{
			enum execution_state : uint_least8_t
			{
				START = 0,
				GEN_VERTEX_ARRAY = 1,
				GEN_MESH = 2,
				DONE = 3,
				ERROR_STATE = 0xFF
			};

			execution_state state;
			patch_pipeline* pipeline;
			std::shared_ptr<patch> target_patch;

			GLuint vertex_buffer;
			GLuint uniform;

			GLuint offset;

			bool is_done() const;
			void step();

			generate_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);
		};
		struct upsample_state
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

			upsample_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);
		};
		struct remove_state
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

			remove_state(std::shared_ptr<patch> p, patch_pipeline* pipeline);
		};

		typedef util::any_of<generate_state, upsample_state, remove_state> exec_type;

		buffer_manager _manager;

		std::queue<exec_type> _waiting;
		std::deque<exec_type> _executing;
		std::map<std::shared_ptr<patch>, GLuint> _offsets;

		GLuint _meshgen;
		GLuint _vertex_gen;
		GLuint _upsampler;

	public:
		patch_pipeline(size_t num_blocks);
		patch_pipeline(const patch_pipeline&) = delete;
		patch_pipeline(patch_pipeline&&) = delete;
		~patch_pipeline();

		void upsample(std::shared_ptr<patch> patch);
		void generate(std::shared_ptr<patch> patch);
		void remove(std::shared_ptr<patch> patch);

		void cull();

		buffer_manager& manager();
		const decltype(_offsets)& patches() const;

		update_state process(size_t n = 4);

		static bool can_upsample(std::shared_ptr<patch> patch);
	};
}
