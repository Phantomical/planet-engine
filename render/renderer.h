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

	struct frustum
	{
		struct plane
		{
			double a, b, c, d;

			plane() = default;
			plane(double a, double b, double c, double d) :
				a(a),
				b(b),
				c(c),
				d(d)
			{

			}

			void normalize()
			{
				double q = 1.0 / std::sqrt(a*a + b*b + c*c);
				a *= q;
				b *= q;
				c *= q;
				d *= q;
			}
		};

		plane planes[6];

		frustum(const glm::dmat4& m)
		{
			planes[0].a = m[4-1][1-1] + m[1-1][1-1];
			planes[0].b = m[4-1][2-1] + m[1-1][2-1];
			planes[0].c = m[4-1][3-1] + m[1-1][3-1];
			planes[0].d = m[4-1][4-1] + m[1-1][4-1];
			// Right clipping plane
			planes[1].a = m[4-1][1-1] - m[1-1][1-1];
			planes[1].b = m[4-1][2-1] - m[1-1][2-1];
			planes[1].c = m[4-1][3-1] - m[1-1][3-1];
			planes[1].d = m[4-1][4-1] - m[1-1][4-1];
			// Top clipping plane
			planes[2].a = m[4-1][1-1] - m[2-1][1-1];
			planes[2].b = m[4-1][2-1] - m[2-1][2-1];
			planes[2].c = m[4-1][3-1] - m[2-1][3-1];
			planes[2].d = m[4-1][4-1] - m[2-1][4-1];
			// Bottom clipping plane
			planes[3].a = m[4-1][1-1] + m[2-1][1-1];
			planes[3].b = m[4-1][2-1] + m[2-1][2-1];
			planes[3].c = m[4-1][3-1] + m[2-1][3-1];
			planes[3].d = m[4-1][4-1] + m[2-1][4-1];
			// Near clipping plane
			planes[4].a = m[4-1][1-1] + m[3-1][1-1];
			planes[4].b = m[4-1][2-1] + m[3-1][2-1];
			planes[4].c = m[4-1][3-1] + m[3-1][3-1];
			planes[4].d = m[4-1][4-1] + m[3-1][4-1];
			// Far clipping plane
			planes[5].a = m[4-1][1-1] - m[3-1][1-1];
			planes[5].b = m[4-1][2-1] - m[3-1][2-1];
			planes[5].c = m[4-1][3-1] - m[3-1][3-1];
			planes[5].d = m[4-1][4-1] - m[3-1][4-1];

			for (size_t i = 0; i < std::size(planes); ++i)
				planes[i].normalize();
		}

		bool intersects(const glm::dvec3& pt, double radius) const
		{
			for (size_t i = 0; i < std::size(planes); ++i)
			{
				double dis = planes[i].a * pt.x
					+ planes[i].b * pt.y
					+ planes[i].c * pt.z
					+ planes[i].d;

				if (-radius < dis)
					return true;
			}

			return false;
		}
	};

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
		// Draw commands for visible objects
		GLuint visible_commands;
		// Matrix buffer
		GLuint matbuffer;

		std::vector<std::weak_ptr<patch>> visible;

		GLuint vertex_array;

		// Element buffer
		GLuint elements;

		// Compute shader for uploading new commands to the command buffer
		GLuint command_update;
		// Compute shader for copying draw commands
		GLuint copy_commands;
		// The shader that is used for actually rendering the planet
		GLuint planet_shader;

		void update_meshes();

	public:
		planet planet;
		std::shared_ptr<planet_data> data;

		void frustum_cull(const frustum& f);
		void update(const glm::dvec3& cam_pos, const glm::dvec3& cam_vel = glm::dvec3(0.0));
		void render(const glm::dmat4& mvp_mat);

		std::future<std::pair<GLuint, GLsync>> get_mesh(std::shared_ptr<patch> patch);

		renderer(GLuint shader, double planet_radius, double scale = SCALE);
		renderer(const renderer&) = delete;

		~renderer();
	};
}
