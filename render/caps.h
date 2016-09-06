#pragma once

#ifdef GL_core_profile
#	define NORMAL_BIT       0x1
#	define DISPLACEMENT_BIT 0x2
#	define OUTDIR_BIT       0x4
uint stride(uint bits)
{
	return 3
		+ (NORMAL_BIT & bits) * 3
		+ ((DISPLACEMENT_BIT & bits) >> 1)
		+ ((OUTDIR_BIT & bits) >> 2) * 3;
}
#else
namespace planet_engine
{
	enum cap_bits
	{
		NORMAL_BIT = 0x1,
		DISPLACEMENT_BIT = 0x2,
		OUTDIR_BIT = 0x4
	};

	constexpr unsigned stride(cap_bits bits)
	{
		return 3
			+ ((NORMAL_BIT & bits)) * 3
			+ ((DISPLACEMENT_BIT & bits) >> 1)
			+ ((OUTDIR_BIT & bits) >> 2) * 3;
	}
}
#endif
