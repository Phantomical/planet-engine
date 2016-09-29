#pragma once

#include "constants.h"
#include "planet.h"
#include "gl_core.h"
#include "buffer_manager.h"
#include "patch_pipeline.h"

#include <future>
#include <vector>
#include <queue>
#include <set>
#include <map>

namespace planet_engine
{	
	typedef sparse_managed_buffer buffer_manager;

	class renderer
	{
	public:
		static constexpr size_t NUM_VERTICES = constants::NUM_VERTICES;
		static constexpr size_t NUM_INDICES = constants::NUM_ELEMENTS;
		static constexpr size_t SIDE_LEN = constants::SIDE_LEN;
		static constexpr size_t VERTEX_SIZE = constants::VERTEX_SIZE;
		static constexpr size_t MESH_SIZE = constants::MESH_SIZE;
		static constexpr size_t COMPUTE_GROUP_SIZE = constants::COMPUTE_GROUP_SIZE;
		// The maximum number of mesh blocks that can be allocated in GPU memory
		static constexpr size_t NUM_BLOCKS = 16384;
		static constexpr double SCALE = 100.0;
		static constexpr size_t COMMANDS_PER_FRAME = 16;

	private:
		/*
		Vertex Data Layout:
			vertex - 3 floats
			normal - 3 floats
			displacement - 1 float
			outdir - 3 floats
		*/

		typedef GLuint offset_type;
		typedef std::priority_queue<offset_type,
			std::vector<offset_type>,
			std::greater<offset_type>> pqueue_type;

		patch_pipeline pipeline;

		// The buffer for the draw commands
		GLuint drawcommands;
		// Matrix buffer
		GLuint matbuffer;

		GLuint vertex_array;

		// Element buffer
		GLuint elements;

		// Compute shader for uploading new commands to the command buffer
		GLuint command_update;
		// The shader that is used for actually rendering the planet
		GLuint planet_shader;

		void update_meshes();

	public:
		planet planet;
		std::shared_ptr<planet_data> data;

		void update(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel = glm::dvec3(0.0));
		void render(const glm::dmat4& mvp_mat);

		std::future<std::pair<GLuint, GLsync>> get_mesh(std::shared_ptr<patch> patch);

		renderer(GLuint shader, double planet_radius, double scale = SCALE);
		renderer(const renderer&) = delete;

		~renderer();
	};
}
