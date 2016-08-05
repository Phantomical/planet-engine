#include "indexgen.h"

namespace planet_engine
{
	template<typename vTy>
	vTy* gen_indices(std::size_t _side_len)
	{
		vTy side_len = static_cast<vTy>(_side_len);
		vTy* indices = new vTy[num_indices(side_len)];

		vTy idx = 0;

		for (vTy y = 0; y < side_len - 1; y++)
		{
			for (vTy x = 0; x < side_len - 1; x++)
			{
				//First triangle
				indices[idx++] = y * side_len + x;
				indices[idx++] = y * side_len + x + 1;
				indices[idx++] = (y + 1) * side_len + x;

				//Second triangle
				indices[idx++] = y * side_len + x + 1;
				indices[idx++] = (y + 1) * side_len + x + 1;
				indices[idx++] = (y + 1) * side_len + x;
			}
		}

		//Generate indices for skirt

		for (vTy i = 0; i < side_len - 1; i++)
		{
			//Top side
			indices[idx++] = side_len * side_len + i;
			indices[idx++] = side_len * side_len + i + 1;
			indices[idx++] = i;

			indices[idx++] = side_len * side_len + i + 1;
			indices[idx++] = i + 1;
			indices[idx++] = i;

			//Right side
			indices[idx++] = side_len * (i + 1) - 1;
			indices[idx++] = side_len * side_len + side_len + i;
			indices[idx++] = side_len * (i + 2) - 1;

			indices[idx++] = side_len * side_len + side_len + i;
			indices[idx++] = side_len * side_len + side_len + i + 1;
			indices[idx++] = side_len * (i + 2) - 1;

			//Bottom side
			indices[idx++] = (side_len - 1) * side_len + i;
			indices[idx++] = (side_len - 1) * side_len + i + 1;
			indices[idx++] = side_len * (side_len + 2) + i;

			indices[idx++] = (side_len - 1) * side_len + i + 1;
			indices[idx++] = side_len * (side_len + 2) + i + 1;
			indices[idx++] = side_len * (side_len + 2) + i;

			//Left side
			indices[idx++] = side_len * (side_len + 3) + i;
			indices[idx++] = side_len * i;
			indices[idx++] = side_len * (side_len + 3) + i + 1;

			indices[idx++] = side_len * i;
			indices[idx++] = side_len * (i + 1);
			indices[idx++] = side_len * (side_len + 3) + i + 1;
		}

		return indices;
	}

	unsigned int* gen_indices(size_t side_len)
	{
		return gen_indices<unsigned int>(side_len);
	}
}
