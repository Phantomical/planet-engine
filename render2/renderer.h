#pragma once

#include "planet.h"
#include "gl_core.h"
#include "buffer_manager.h"
#include "patch_pipeline.h"

#include <vector>
#include <queue>
#include <set>
#include <map>

namespace planet_engine
{
	class renderer
	{
	private:
		static constexpr size_t NUM_VERTICES = patch::NUM_VERTICES;
		static constexpr size_t NUM_INDICES = patch::NUM_INDICES;
		static constexpr size_t SIDE_LEN = patch::SIDE_LEN;
		static constexpr size_t VERTEX_SIZE = sizeof(float) * 8;
		static constexpr size_t MESH_SIZE = NUM_VERTICES * VERTEX_SIZE;
		// The maximum number of mesh blocks that can be allocated in GPU memory
		static constexpr size_t NUM_BLOCKS = 1 << 10;
		static constexpr size_t COMPUTE_GROUP_SIZE = 128;
		static constexpr double SCALE = 100.0;
		static constexpr size_t COMMANDS_PER_FRAME = 4;

		typedef GLuint offset_type;
		typedef std::priority_queue<offset_type,
			std::vector<offset_type>,
			std::greater<offset_type>> pqueue_type;

		friend struct compute_state;

		struct compute_state
		{
			static constexpr size_t NUM_RESULT_ELEMS = SIDE_LEN * SIDE_LEN;
			static constexpr size_t COMPUTE_GROUP_SIZE = COMPUTE_GROUP_SIZE;
			static constexpr size_t NUM_COMPUTE_GROUPS = (NUM_RESULT_ELEMS + COMPUTE_GROUP_SIZE - 1) / COMPUTE_GROUP_SIZE;

			renderer* parent;
			std::vector<GLuint> offsets;
			std::vector<std::weak_ptr<patch>> patches;
			GLuint size;
			GLuint result_buffer;

			// Dispatches the next step in the sequence
			void compute_next();
			// Indicates whether all the steps in the sequence are done
			bool is_done() const;
			// Returns the results and deletes all the buffers
			void update_patches();
		};
		
		//buffer_manager meshes;

		patch_pipeline pipeline;

		// The buffer for the draw commands
		GLuint drawcommands;
		// Matrix buffer
		GLuint matbuffer;

		GLuint vertex_array;

		// Element buffer
		GLuint elements;

		// Mesh generation shader
		//GLuint meshgen;
		// Parallel maximum calculation shader
		GLuint max_calc;
		// Parallel distance calculation shader
		GLuint length_calc;
		// Compute shader for uploading new commands to the command buffer
		GLuint command_update;
		// The shader that is used for actually rendering the planet
		GLuint planet_shader;

		/* OpenGL constants */
		// Required offset alignment for uniform buffer objects
		GLuint ubo_offset_alignment;
		// Required offset alignment for shader storage buffers
		GLuint ssbo_offset_alignment;

		std::deque<compute_state> compute_states;

		compute_state compute_bounds(std::initializer_list<std::shared_ptr<patch>> meshes);

		void step_compute_states();
		void update_meshes(size_t n);

	public:
		planet planet;
		std::shared_ptr<planet_data> data;

		void update(const glm::dvec3& cam_pos);
		void render(const glm::dmat4& mvp_mat);

		renderer(GLuint shader, double planet_radius);
		renderer(const renderer&) = delete;

		~renderer();
	};
}
