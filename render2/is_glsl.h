
/*
	This file provides a macro that 
	allows headers that will be included from
	both glsl code and C++/C code to
	determine which language it is being
	compiled as
*/

#ifdef IS_GLSL
#	undef IS_GLSL
#endif

#ifdef GL_core_profile
#	define IS_GLSL 1
#else
#	define IS_GLSL 0
#endif