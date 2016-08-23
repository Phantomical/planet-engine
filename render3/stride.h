
#define STRIDE_VAL 10

#ifndef GL_core_profile
#pragma once

namespace planet_engine
{
	static constexpr size_t STRIDE = STRIDE_VAL;
}

#undef STRIDE_VAL
#else
#define STRIDE STRIDE_VAL
#endif
