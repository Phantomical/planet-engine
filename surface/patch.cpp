#include "patch.h"

#include <algorithm>

namespace planet_engine
{
	using glm::dvec3;
	using glm::fvec3;
	using glm::normalize;

	std::shared_ptr<patch::mesh> patch::gen_mesh() const
	{
		static constexpr double INTERP = 1.0 / (SIDE_LEN - 1);

		patch::mesh* mesh_ptr = new mesh;

		mesh_ptr->patch = this->shared_from_this();
		mesh_ptr->adj_pos = glm::normalize(pos) * data->noise_func(pos.x, pos.y, pos.z) + pos;
		mesh_ptr->farthest_vertex = std::numeric_limits<float>::max();

		for (size_t x = 0; x < SIDE_LEN; x++)
		{
			//Calculate horizontal position
			double interp = INTERP * (double)x;
			dvec3 v1 = lerp(nwc, nec, interp);
			dvec3 v2 = lerp(swc, sec, interp);
			for (size_t y = 0; y < SIDE_LEN; y++)
			{
				//Calculate vertical position
				dvec3 vtx = lerp(v1, v2, INTERP * (double)y);
				//Map to sphere
				vtx = to_sphere(vtx, data->planet_radius);
				dvec3 nvtx = glm::normalize(vtx);
				// Evaluate noise function
				double displacement = data->noise_func(vtx.x, vtx.y, vtx.z);
				vtx += nvtx * displacement;
				//Assign vertex position
				mesh_ptr->data[x * SIDE_LEN + y].vertex = (fvec3)(vtx - mesh_ptr->adj_pos);
				// Texture coordinate is for cubemap textures only
				mesh_ptr->data[x * SIDE_LEN + y].texcoord = (fvec3)nvtx;
				// Assign displacement value
				mesh_ptr->data[x * SIDE_LEN + y].displacement = (float)displacement;

				mesh_ptr->farthest_vertex = std::max<double>(
					length2(mesh_ptr->data[x * SIDE_LEN + y].vertex),
					mesh_ptr->farthest_vertex);
			}
		}

		mesh_ptr->farthest_vertex = std::sqrt(mesh_ptr->farthest_vertex);

		/*
		Skirt is the position of the surface, but SKIRT_DEPTH units lower

		Calculate position on the sphere, then subtract SKIRT_DEPTH units
		Texture coordinate is still just normalized position
		*/

		//Vertex normal relative to planet centre
		dvec3 vnrm;
		//Sizeof base surface data
		size_t data_size = SIDE_LEN * SIDE_LEN;
		for (size_t i = 0; i < SIDE_LEN; i++)
		{

			vnrm = normalize(lerp(nwc, swc, INTERP * (double)i));
			mesh_ptr->data[data_size + i].vertex = (fvec3)((vnrm * data->planet_radius - vnrm * SKIRT_DEPTH) - pos);
			mesh_ptr->data[data_size + i].texcoord = (fvec3)vnrm;
			mesh_ptr->data[data_size + i].displacement = -SKIRT_DEPTH;
		}
		data_size += SIDE_LEN;
		for (size_t i = 0; i < SIDE_LEN; i++)
		{
			vnrm = normalize(lerp(swc, sec, INTERP * (double)i));
			mesh_ptr->data[data_size + i].vertex = (fvec3)((vnrm * data->planet_radius - vnrm * SKIRT_DEPTH) - pos);
			mesh_ptr->data[data_size + i].texcoord = (fvec3)vnrm;
			mesh_ptr->data[data_size + i].displacement = -SKIRT_DEPTH;
		}
		data_size += SIDE_LEN;
		for (size_t i = 0; i < SIDE_LEN; i++)
		{
			vnrm = normalize(lerp(nec, sec, INTERP * (double)i));
			mesh_ptr->data[data_size + i].vertex = (fvec3)((vnrm * data->planet_radius - vnrm * SKIRT_DEPTH) - pos);
			mesh_ptr->data[data_size + i].texcoord = (fvec3)vnrm;
			mesh_ptr->data[data_size + i].displacement = -SKIRT_DEPTH;
		}
		data_size += SIDE_LEN;
		for (size_t i = 0; i < SIDE_LEN; i++)
		{
			vnrm = normalize(lerp(nwc, nec, INTERP * (double)i));
			mesh_ptr->data[data_size + i].vertex = (fvec3)((vnrm * data->planet_radius - vnrm * SKIRT_DEPTH) - pos);
			mesh_ptr->data[data_size + i].texcoord = (fvec3)vnrm;
			mesh_ptr->data[data_size + i].displacement = -SKIRT_DEPTH;
		}

		//TODO: Normal calculations for lighting

		return std::shared_ptr<mesh>(mesh_ptr);
	}

	void patch::split()
	{
		info info;
		info.data = data;
		info.level = level + 1;
		info.parent = shared_from_this();
		dvec3 centre = (nwc + nec + swc + sec) * 0.25;

		info.nwc = nwc;
		info.nec = (nwc + nec) * 0.5;
		info.swc = (nwc + swc) * 0.5;
		info.sec = centre;
		nw = std::make_shared<patch>(info);

		info.nwc = (nwc + nec) * 0.5;
		info.nec = nec;
		info.swc = centre;
		info.sec = (nec + sec) * 0.5;
		ne = std::make_shared<patch>(info);

		info.nwc = (nwc + swc) * 0.5;
		info.nec = centre;
		info.swc = swc;
		info.sec = (swc + sec) * 0.5;
		sw = std::make_shared<patch>(info);

		info.nwc = centre;
		info.nec = (nec + sec) * 0.5;
		info.swc = (swc + sec) * 0.5;
		info.sec = sec;
	}
	void patch::merge()
	{
		nw = ne = sw = se = nullptr;
	}
}
