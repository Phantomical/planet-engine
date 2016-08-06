#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "gl_core.h"

#if defined(__APPLE__)
#include <dlfcn.h>

static void* AppleGLGetProcAddress (const char *name)
{
	static void* image = NULL;
	
	if (NULL == image)
		image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);

	return (image ? dlsym(image, name) : NULL);
}
#endif /* __APPLE__ */

#if defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>

static void* SunGetProcAddress (const GLubyte* name)
{
  static void* h = NULL;
  static void* gpa;

  if (h == NULL)
  {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void*(*)(const GLubyte*))gpa)(name);
  else
    return dlsym(h, (const char*)name);
}
#endif /* __sgi || __sun */

#if defined(_WIN32)

#ifdef _MSC_VER
#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
#pragma warning(disable: 4996)
#endif

static int TestPointer(const PROC pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

static PROC WinGetProcAddress(const char *name)
{
	HMODULE glMod = NULL;
	PROC pFunc = wglGetProcAddress((LPCSTR)name);
	if(TestPointer(pFunc))
	{
		return pFunc;
	}
	glMod = GetModuleHandleA("OpenGL32.dll");
	return (PROC)GetProcAddress(glMod, (LPCSTR)name);
}
	
#define IntGetProcAddress(name) WinGetProcAddress(name)
#else
	#if defined(__APPLE__)
		#define IntGetProcAddress(name) AppleGLGetProcAddress(name)
	#else
		#if defined(__sgi) || defined(__sun)
			#define IntGetProcAddress(name) SunGetProcAddress(name)
		#else /* GLX */
		    #include <GL/glx.h>

			#define IntGetProcAddress(name) (*glXGetProcAddressARB)((const GLubyte*)name)
		#endif
	#endif
#endif

int ogl_ext_AMD_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_ARB_arrays_of_arrays = ogl_LOAD_FAILED;
int ogl_ext_ARB_base_instance = ogl_LOAD_FAILED;
int ogl_ext_ARB_blend_func_extended = ogl_LOAD_FAILED;
int ogl_ext_ARB_buffer_storage = ogl_LOAD_FAILED;
int ogl_ext_ARB_cl_event = ogl_LOAD_FAILED;
int ogl_ext_ARB_clear_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_clear_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_clip_control = ogl_LOAD_FAILED;
int ogl_ext_ARB_color_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_compressed_texture_pixel_storage = ogl_LOAD_FAILED;
int ogl_ext_ARB_conservative_depth = ogl_LOAD_FAILED;
int ogl_ext_ARB_compute_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_compute_variable_group_size = ogl_LOAD_FAILED;
int ogl_ext_ARB_conditional_render_inverted = ogl_LOAD_FAILED;
int ogl_ext_ARB_copy_buffer = ogl_LOAD_FAILED;
int ogl_ext_ARB_copy_image = ogl_LOAD_FAILED;
int ogl_ext_ARB_cull_distance = ogl_LOAD_FAILED;
int ogl_ext_ARB_debug_output = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_clamp = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_derivative_control = ogl_LOAD_FAILED;
int ogl_ext_ARB_direct_state_access = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_buffers = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_buffers_blend = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_elements_base_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_instanced = ogl_LOAD_FAILED;
int ogl_ext_ARB_enhanced_layouts = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES2_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES3_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES3_1_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES3_2_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_explicit_attrib_location = ogl_LOAD_FAILED;
int ogl_ext_ARB_explicit_uniform_location = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_coord_conventions = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_layer_viewport = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_program = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_program_shadow = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_no_attachments = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_sRGB = ogl_LOAD_FAILED;
int ogl_ext_ARB_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_ARB_get_program_binary = ogl_LOAD_FAILED;
int ogl_ext_ARB_get_texture_sub_image = ogl_LOAD_FAILED;
int ogl_ext_ARB_gpu_shader5 = ogl_LOAD_FAILED;
int ogl_ext_ARB_gpu_shader_fp64 = ogl_LOAD_FAILED;
int ogl_ext_ARB_gpu_shader_int64 = ogl_LOAD_FAILED;
int ogl_ext_ARB_half_float_pixel = ogl_LOAD_FAILED;
int ogl_ext_ARB_half_float_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_imaging = ogl_LOAD_FAILED;
int ogl_ext_ARB_indirect_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_instanced_arrays = ogl_LOAD_FAILED;
int ogl_ext_ARB_internalformat_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_internalformat_query2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_invalidate_subdata = ogl_LOAD_FAILED;
int ogl_ext_ARB_map_buffer_alignment = ogl_LOAD_FAILED;
int ogl_ext_ARB_map_buffer_range = ogl_LOAD_FAILED;
int ogl_ext_ARB_multi_bind = ogl_LOAD_FAILED;
int ogl_ext_ARB_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_ARB_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_multitexture = ogl_LOAD_FAILED;
int ogl_ext_ARB_occlusion_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_occlusion_query2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_parallel_shader_compile = ogl_LOAD_FAILED;
int ogl_ext_ARB_pipeline_statistics_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_pixel_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_point_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_point_sprite = ogl_LOAD_FAILED;
int ogl_ext_ARB_program_interface_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_provoking_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_query_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_robust_buffer_access_behavior = ogl_LOAD_FAILED;
int ogl_ext_ARB_robustness = ogl_LOAD_FAILED;
int ogl_ext_ARB_sample_shading = ogl_LOAD_FAILED;
int ogl_ext_ARB_sampler_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_seamless_cube_map = ogl_LOAD_FAILED;
int ogl_ext_ARB_separate_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_atomic_counter_ops = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_atomic_counters = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_bit_encoding = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_draw_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_group_vote = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_image_load_store = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_image_size = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_precision = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_storage_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_subroutine = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_texture_image_samples = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_texture_lod = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_100 = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_420pack = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_include = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_packing = ogl_LOAD_FAILED;
int ogl_ext_ARB_shadow = ogl_LOAD_FAILED;
int ogl_ext_ARB_sparse_buffer = ogl_LOAD_FAILED;
int ogl_ext_ARB_sparse_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_stencil_texturing = ogl_LOAD_FAILED;
int ogl_ext_ARB_sync = ogl_LOAD_FAILED;
int ogl_ext_ARB_tessellation_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_barrier = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_border_clamp = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_object_rgb32 = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_range = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression_bptc = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression_rgtc = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_cube_map = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_cube_map_array = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_add = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_combine = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_crossbar = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_dot3 = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_gather = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_mirror_clamp_to_edge = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_mirrored_repeat = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_non_power_of_two = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_query_levels = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_query_lod = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rectangle = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rg = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rgb10_a2ui = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_stencil8 = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_storage = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_storage_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_swizzle = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_view = ogl_LOAD_FAILED;
int ogl_ext_ARB_timer_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback3 = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback_instanced = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback_overflow_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_transpose_matrix = ogl_LOAD_FAILED;
int ogl_ext_ARB_uniform_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_array_bgra = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_array_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_attrib_64bit = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_attrib_binding = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_program = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_type_10f_11f_11f_rev = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_type_2_10_10_10_rev = ogl_LOAD_FAILED;
int ogl_ext_ARB_viewport_array = ogl_LOAD_FAILED;
int ogl_ext_ARB_window_pos = ogl_LOAD_FAILED;
int ogl_ext_ATI_draw_buffers = ogl_LOAD_FAILED;
int ogl_ext_ATI_texture_float = ogl_LOAD_FAILED;
int ogl_ext_ATI_texture_mirror_once = ogl_LOAD_FAILED;
int ogl_ext_S3_s3tc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_add = ogl_LOAD_FAILED;
int ogl_ext_EXT_abgr = ogl_LOAD_FAILED;
int ogl_ext_EXT_bgra = ogl_LOAD_FAILED;
int ogl_ext_EXT_bindable_uniform = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_equation_separate = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_func_separate = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_minmax = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_subtract = ogl_LOAD_FAILED;
int ogl_ext_EXT_compiled_vertex_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_depth_bounds_test = ogl_LOAD_FAILED;
int ogl_ext_EXT_direct_state_access = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_buffers2 = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_instanced = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_range_elements = ogl_LOAD_FAILED;
int ogl_ext_EXT_fog_coord = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_blit = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_multisample = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_multisample_blit_scaled = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_sRGB = ogl_LOAD_FAILED;
int ogl_ext_EXT_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_EXT_gpu_program_parameters = ogl_LOAD_FAILED;
int ogl_ext_EXT_gpu_shader4 = ogl_LOAD_FAILED;
int ogl_ext_EXT_multi_draw_arrays = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_depth_stencil = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_float = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_pixels = ogl_LOAD_FAILED;
int ogl_ext_EXT_pixel_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_point_parameters = ogl_LOAD_FAILED;
int ogl_ext_EXT_polygon_offset_clamp = ogl_LOAD_FAILED;
int ogl_ext_EXT_provoking_vertex = ogl_LOAD_FAILED;
int ogl_ext_EXT_rescale_normal = ogl_LOAD_FAILED;
int ogl_ext_EXT_secondary_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_separate_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_EXT_separate_specular_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_shader_image_load_store = ogl_LOAD_FAILED;
int ogl_ext_EXT_shader_integer_mix = ogl_LOAD_FAILED;
int ogl_ext_EXT_shadow_funcs = ogl_LOAD_FAILED;
int ogl_ext_EXT_stencil_two_side = ogl_LOAD_FAILED;
int ogl_ext_EXT_stencil_wrap = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture3D = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_latc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_rgtc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_s3tc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_cube_map = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_combine = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_dot3 = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_filter_anisotropic = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_integer = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_lod_bias = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_mirror_clamp = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_shared_exponent = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_sRGB = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_sRGB_decode = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_swizzle = ogl_LOAD_FAILED;
int ogl_ext_EXT_timer_query = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_array_bgra = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_attrib_64bit = ogl_LOAD_FAILED;
int ogl_ext_IBM_rasterpos_clip = ogl_LOAD_FAILED;
int ogl_ext_IBM_texture_mirrored_repeat = ogl_LOAD_FAILED;
int ogl_ext_KHR_context_flush_control = ogl_LOAD_FAILED;
int ogl_ext_KHR_debug = ogl_LOAD_FAILED;
int ogl_ext_KHR_no_error = ogl_LOAD_FAILED;
int ogl_ext_KHR_robust_buffer_access_behavior = ogl_LOAD_FAILED;
int ogl_ext_KHR_robustness = ogl_LOAD_FAILED;
int ogl_ext_NV_bindless_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_NV_bindless_multi_draw_indirect_count = ogl_LOAD_FAILED;
int ogl_ext_NV_blend_equation_advanced = ogl_LOAD_FAILED;
int ogl_ext_NV_blend_square = ogl_LOAD_FAILED;
int ogl_ext_NV_command_list = ogl_LOAD_FAILED;
int ogl_ext_NV_compute_program5 = ogl_LOAD_FAILED;
int ogl_ext_NV_conditional_render = ogl_LOAD_FAILED;
int ogl_ext_NV_copy_depth_to_color = ogl_LOAD_FAILED;
int ogl_ext_NV_copy_image = ogl_LOAD_FAILED;
int ogl_ext_NV_depth_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_NV_depth_clamp = ogl_LOAD_FAILED;
int ogl_ext_NV_draw_texture = ogl_LOAD_FAILED;
int ogl_ext_NV_explicit_multisample = ogl_LOAD_FAILED;
int ogl_ext_NV_fence = ogl_LOAD_FAILED;
int ogl_ext_NV_float_buffer = ogl_LOAD_FAILED;
int ogl_ext_NV_fog_distance = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program_option = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program2 = ogl_LOAD_FAILED;
int ogl_ext_NV_framebuffer_multisample_coverage = ogl_LOAD_FAILED;
int ogl_ext_NV_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program4 = ogl_LOAD_FAILED;
int ogl_ext_NV_internalformat_sample_query = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program5 = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program5_mem_extended = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_shader5 = ogl_LOAD_FAILED;
int ogl_ext_NV_half_float = ogl_LOAD_FAILED;
int ogl_ext_NV_light_max_exponent = ogl_LOAD_FAILED;
int ogl_ext_NV_multisample_coverage = ogl_LOAD_FAILED;
int ogl_ext_NV_multisample_filter_hint = ogl_LOAD_FAILED;
int ogl_ext_NV_occlusion_query = ogl_LOAD_FAILED;
int ogl_ext_NV_packed_depth_stencil = ogl_LOAD_FAILED;
int ogl_ext_NV_parameter_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_NV_parameter_buffer_object2 = ogl_LOAD_FAILED;
int ogl_ext_NV_path_rendering = ogl_LOAD_FAILED;
int ogl_ext_NV_pixel_data_range = ogl_LOAD_FAILED;
int ogl_ext_NV_point_sprite = ogl_LOAD_FAILED;
int ogl_ext_NV_primitive_restart = ogl_LOAD_FAILED;
int ogl_ext_NV_register_combiners = ogl_LOAD_FAILED;
int ogl_ext_NV_register_combiners2 = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_atomic_counters = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_atomic_float = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_buffer_load = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_storage_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_NV_texgen_reflection = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_barrier = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_compression_vtc = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_env_combine4 = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_multisample = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_rectangle = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader2 = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader3 = ogl_LOAD_FAILED;
int ogl_ext_NV_transform_feedback = ogl_LOAD_FAILED;
int ogl_ext_NV_transform_feedback2 = ogl_LOAD_FAILED;
int ogl_ext_NV_uniform_buffer_unified_memory = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_array_range = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_array_range2 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_attrib_integer_64bit = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_buffer_unified_memory = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program1_1 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program2 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program2_option = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program3 = ogl_LOAD_FAILED;
int ogl_ext_NV_video_capture = ogl_LOAD_FAILED;
int ogl_ext_NVX_conditional_render = ogl_LOAD_FAILED;
int ogl_ext_NVX_gpu_memory_info = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_thread_group = ogl_LOAD_FAILED;
int ogl_ext_KHR_blend_equation_advanced = ogl_LOAD_FAILED;
int ogl_ext_SGIS_generate_mipmap = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_lod = ogl_LOAD_FAILED;
int ogl_ext_SGIX_depth_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIX_shadow = ogl_LOAD_FAILED;
int ogl_ext_SUN_slice_accum = ogl_LOAD_FAILED;

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectAMD)(GLenum mode, const void * indirect, GLsizei primcount, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectAMD)(GLenum mode, GLenum type, const void * indirect, GLsizei primcount, GLsizei stride) = NULL;

static int Load_AMD_multi_draw_indirect(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectAMD = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirectAMD");
	if(!_ptrc_glMultiDrawArraysIndirectAMD) numFailed++;
	_ptrc_glMultiDrawElementsIndirectAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirectAMD");
	if(!_ptrc_glMultiDrawElementsIndirectAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) = NULL;

static int Load_ARB_base_instance(void)
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei, GLuint))IntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!_ptrc_glDrawArraysInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertexBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseVertexBaseInstance) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint program, const GLchar * name) = NULL;

static int Load_ARB_blend_func_extended(void)
{
	int numFailed = 0;
	_ptrc_glBindFragDataLocationIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationIndexed");
	if(!_ptrc_glBindFragDataLocationIndexed) numFailed++;
	_ptrc_glGetFragDataIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataIndex");
	if(!_ptrc_glGetFragDataIndex) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) = NULL;

static int Load_ARB_buffer_storage(void)
{
	int numFailed = 0;
	_ptrc_glBufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glBufferStorage");
	if(!_ptrc_glBufferStorage) numFailed++;
	return numFailed;
}

GLsync (CODEGEN_FUNCPTR *_ptrc_glCreateSyncFromCLeventARB)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags) = NULL;

static int Load_ARB_cl_event(void)
{
	int numFailed = 0;
	_ptrc_glCreateSyncFromCLeventARB = (GLsync (CODEGEN_FUNCPTR *)(struct _cl_context *, struct _cl_event *, GLbitfield))IntGetProcAddress("glCreateSyncFromCLeventARB");
	if(!_ptrc_glCreateSyncFromCLeventARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) = NULL;

static int Load_ARB_clear_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glClearBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferData");
	if(!_ptrc_glClearBufferData) numFailed++;
	_ptrc_glClearBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferSubData");
	if(!_ptrc_glClearBufferSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) = NULL;

static int Load_ARB_clear_texture(void)
{
	int numFailed = 0;
	_ptrc_glClearTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexImage");
	if(!_ptrc_glClearTexImage) numFailed++;
	_ptrc_glClearTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexSubImage");
	if(!_ptrc_glClearTexSubImage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClipControl)(GLenum origin, GLenum depth) = NULL;

static int Load_ARB_clip_control(void)
{
	int numFailed = 0;
	_ptrc_glClipControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClipControl");
	if(!_ptrc_glClipControl) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClampColorARB)(GLenum target, GLenum clamp) = NULL;

static int Load_ARB_color_buffer_float(void)
{
	int numFailed = 0;
	_ptrc_glClampColorARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClampColorARB");
	if(!_ptrc_glClampColorARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr indirect) = NULL;

static int Load_ARB_compute_shader(void)
{
	int numFailed = 0;
	_ptrc_glDispatchCompute = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchCompute");
	if(!_ptrc_glDispatchCompute) numFailed++;
	_ptrc_glDispatchComputeIndirect = (void (CODEGEN_FUNCPTR *)(GLintptr))IntGetProcAddress("glDispatchComputeIndirect");
	if(!_ptrc_glDispatchComputeIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z) = NULL;

static int Load_ARB_compute_variable_group_size(void)
{
	int numFailed = 0;
	_ptrc_glDispatchComputeGroupSizeARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchComputeGroupSizeARB");
	if(!_ptrc_glDispatchComputeGroupSizeARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = NULL;

static int Load_ARB_copy_buffer(void)
{
	int numFailed = 0;
	_ptrc_glCopyBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyBufferSubData");
	if(!_ptrc_glCopyBufferSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) = NULL;

static int Load_ARB_copy_image(void)
{
	int numFailed = 0;
	_ptrc_glCopyImageSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubData");
	if(!_ptrc_glCopyImageSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void * userParam) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) = NULL;

static int Load_ARB_debug_output(void)
{
	int numFailed = 0;
	_ptrc_glDebugMessageCallbackARB = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROCARB, const void *))IntGetProcAddress("glDebugMessageCallbackARB");
	if(!_ptrc_glDebugMessageCallbackARB) numFailed++;
	_ptrc_glDebugMessageControlARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControlARB");
	if(!_ptrc_glDebugMessageControlARB) numFailed++;
	_ptrc_glDebugMessageInsertARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsertARB");
	if(!_ptrc_glDebugMessageInsertARB) numFailed++;
	_ptrc_glGetDebugMessageLogARB = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLogARB");
	if(!_ptrc_glGetDebugMessageLogARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindTextureUnit)(GLuint unit, GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat depth, GLint stencil) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateBuffers)(GLsizei n, GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateFramebuffers)(GLsizei n, GLuint * framebuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateProgramPipelines)(GLsizei n, GLuint * pipelines) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateQueries)(GLenum target, GLsizei n, GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateRenderbuffers)(GLsizei n, GLuint * renderbuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateSamplers)(GLsizei n, GLuint * samplers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateTextures)(GLenum target, GLsizei n, GLuint * textures) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateTransformFeedbacks)(GLsizei n, GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateVertexArrays)(GLsizei n, GLuint * arrays) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmap)(GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBuffer)(GLuint buffer, GLenum access) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum * bufs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteri)(GLuint texture, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBuffer)(GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) = NULL;

static int Load_ARB_direct_state_access(void)
{
	int numFailed = 0;
	_ptrc_glBindTextureUnit = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindTextureUnit");
	if(!_ptrc_glBindTextureUnit) numFailed++;
	_ptrc_glBlitNamedFramebuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitNamedFramebuffer");
	if(!_ptrc_glBlitNamedFramebuffer) numFailed++;
	_ptrc_glCheckNamedFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCheckNamedFramebufferStatus");
	if(!_ptrc_glCheckNamedFramebufferStatus) numFailed++;
	_ptrc_glClearNamedBufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferData");
	if(!_ptrc_glClearNamedBufferData) numFailed++;
	_ptrc_glClearNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferSubData");
	if(!_ptrc_glClearNamedBufferSubData) numFailed++;
	_ptrc_glClearNamedFramebufferfi = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLfloat, GLint))IntGetProcAddress("glClearNamedFramebufferfi");
	if(!_ptrc_glClearNamedFramebufferfi) numFailed++;
	_ptrc_glClearNamedFramebufferfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLfloat *))IntGetProcAddress("glClearNamedFramebufferfv");
	if(!_ptrc_glClearNamedFramebufferfv) numFailed++;
	_ptrc_glClearNamedFramebufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLint *))IntGetProcAddress("glClearNamedFramebufferiv");
	if(!_ptrc_glClearNamedFramebufferiv) numFailed++;
	_ptrc_glClearNamedFramebufferuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLuint *))IntGetProcAddress("glClearNamedFramebufferuiv");
	if(!_ptrc_glClearNamedFramebufferuiv) numFailed++;
	_ptrc_glCompressedTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage1D");
	if(!_ptrc_glCompressedTextureSubImage1D) numFailed++;
	_ptrc_glCompressedTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage2D");
	if(!_ptrc_glCompressedTextureSubImage2D) numFailed++;
	_ptrc_glCompressedTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage3D");
	if(!_ptrc_glCompressedTextureSubImage3D) numFailed++;
	_ptrc_glCopyNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyNamedBufferSubData");
	if(!_ptrc_glCopyNamedBufferSubData) numFailed++;
	_ptrc_glCopyTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTextureSubImage1D");
	if(!_ptrc_glCopyTextureSubImage1D) numFailed++;
	_ptrc_glCopyTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage2D");
	if(!_ptrc_glCopyTextureSubImage2D) numFailed++;
	_ptrc_glCopyTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage3D");
	if(!_ptrc_glCopyTextureSubImage3D) numFailed++;
	_ptrc_glCreateBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateBuffers");
	if(!_ptrc_glCreateBuffers) numFailed++;
	_ptrc_glCreateFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateFramebuffers");
	if(!_ptrc_glCreateFramebuffers) numFailed++;
	_ptrc_glCreateProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateProgramPipelines");
	if(!_ptrc_glCreateProgramPipelines) numFailed++;
	_ptrc_glCreateQueries = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glCreateQueries");
	if(!_ptrc_glCreateQueries) numFailed++;
	_ptrc_glCreateRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateRenderbuffers");
	if(!_ptrc_glCreateRenderbuffers) numFailed++;
	_ptrc_glCreateSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateSamplers");
	if(!_ptrc_glCreateSamplers) numFailed++;
	_ptrc_glCreateTextures = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glCreateTextures");
	if(!_ptrc_glCreateTextures) numFailed++;
	_ptrc_glCreateTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateTransformFeedbacks");
	if(!_ptrc_glCreateTransformFeedbacks) numFailed++;
	_ptrc_glCreateVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateVertexArrays");
	if(!_ptrc_glCreateVertexArrays) numFailed++;
	_ptrc_glDisableVertexArrayAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDisableVertexArrayAttrib");
	if(!_ptrc_glDisableVertexArrayAttrib) numFailed++;
	_ptrc_glEnableVertexArrayAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glEnableVertexArrayAttrib");
	if(!_ptrc_glEnableVertexArrayAttrib) numFailed++;
	_ptrc_glFlushMappedNamedBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedNamedBufferRange");
	if(!_ptrc_glFlushMappedNamedBufferRange) numFailed++;
	_ptrc_glGenerateTextureMipmap = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGenerateTextureMipmap");
	if(!_ptrc_glGenerateTextureMipmap) numFailed++;
	_ptrc_glGetCompressedTextureImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, void *))IntGetProcAddress("glGetCompressedTextureImage");
	if(!_ptrc_glGetCompressedTextureImage) numFailed++;
	_ptrc_glGetNamedBufferParameteri64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetNamedBufferParameteri64v");
	if(!_ptrc_glGetNamedBufferParameteri64v) numFailed++;
	_ptrc_glGetNamedBufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedBufferParameteriv");
	if(!_ptrc_glGetNamedBufferParameteriv) numFailed++;
	_ptrc_glGetNamedBufferPointerv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetNamedBufferPointerv");
	if(!_ptrc_glGetNamedBufferPointerv) numFailed++;
	_ptrc_glGetNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, void *))IntGetProcAddress("glGetNamedBufferSubData");
	if(!_ptrc_glGetNamedBufferSubData) numFailed++;
	_ptrc_glGetNamedFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetNamedFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetNamedFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferParameteriv");
	if(!_ptrc_glGetNamedFramebufferParameteriv) numFailed++;
	_ptrc_glGetNamedRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedRenderbufferParameteriv");
	if(!_ptrc_glGetNamedRenderbufferParameteriv) numFailed++;
	_ptrc_glGetQueryBufferObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjecti64v");
	if(!_ptrc_glGetQueryBufferObjecti64v) numFailed++;
	_ptrc_glGetQueryBufferObjectiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectiv");
	if(!_ptrc_glGetQueryBufferObjectiv) numFailed++;
	_ptrc_glGetQueryBufferObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectui64v");
	if(!_ptrc_glGetQueryBufferObjectui64v) numFailed++;
	_ptrc_glGetQueryBufferObjectuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectuiv");
	if(!_ptrc_glGetQueryBufferObjectuiv) numFailed++;
	_ptrc_glGetTextureImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetTextureImage");
	if(!_ptrc_glGetTextureImage) numFailed++;
	_ptrc_glGetTextureLevelParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureLevelParameterfv");
	if(!_ptrc_glGetTextureLevelParameterfv) numFailed++;
	_ptrc_glGetTextureLevelParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLint *))IntGetProcAddress("glGetTextureLevelParameteriv");
	if(!_ptrc_glGetTextureLevelParameteriv) numFailed++;
	_ptrc_glGetTextureParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterIiv");
	if(!_ptrc_glGetTextureParameterIiv) numFailed++;
	_ptrc_glGetTextureParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetTextureParameterIuiv");
	if(!_ptrc_glGetTextureParameterIuiv) numFailed++;
	_ptrc_glGetTextureParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureParameterfv");
	if(!_ptrc_glGetTextureParameterfv) numFailed++;
	_ptrc_glGetTextureParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTextureParameteriv");
	if(!_ptrc_glGetTextureParameteriv) numFailed++;
	_ptrc_glGetTransformFeedbacki64_v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint64 *))IntGetProcAddress("glGetTransformFeedbacki64_v");
	if(!_ptrc_glGetTransformFeedbacki64_v) numFailed++;
	_ptrc_glGetTransformFeedbacki_v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint *))IntGetProcAddress("glGetTransformFeedbacki_v");
	if(!_ptrc_glGetTransformFeedbacki_v) numFailed++;
	_ptrc_glGetTransformFeedbackiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTransformFeedbackiv");
	if(!_ptrc_glGetTransformFeedbackiv) numFailed++;
	_ptrc_glGetVertexArrayIndexed64iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetVertexArrayIndexed64iv");
	if(!_ptrc_glGetVertexArrayIndexed64iv) numFailed++;
	_ptrc_glGetVertexArrayIndexediv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIndexediv");
	if(!_ptrc_glGetVertexArrayIndexediv) numFailed++;
	_ptrc_glGetVertexArrayiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayiv");
	if(!_ptrc_glGetVertexArrayiv) numFailed++;
	_ptrc_glInvalidateNamedFramebufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateNamedFramebufferData");
	if(!_ptrc_glInvalidateNamedFramebufferData) numFailed++;
	_ptrc_glInvalidateNamedFramebufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateNamedFramebufferSubData");
	if(!_ptrc_glInvalidateNamedFramebufferSubData) numFailed++;
	_ptrc_glMapNamedBuffer = (void * (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMapNamedBuffer");
	if(!_ptrc_glMapNamedBuffer) numFailed++;
	_ptrc_glMapNamedBufferRange = (void * (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapNamedBufferRange");
	if(!_ptrc_glMapNamedBufferRange) numFailed++;
	_ptrc_glNamedBufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLenum))IntGetProcAddress("glNamedBufferData");
	if(!_ptrc_glNamedBufferData) numFailed++;
	_ptrc_glNamedBufferStorage = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glNamedBufferStorage");
	if(!_ptrc_glNamedBufferStorage) numFailed++;
	_ptrc_glNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, const void *))IntGetProcAddress("glNamedBufferSubData");
	if(!_ptrc_glNamedBufferSubData) numFailed++;
	_ptrc_glNamedFramebufferDrawBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glNamedFramebufferDrawBuffer");
	if(!_ptrc_glNamedFramebufferDrawBuffer) numFailed++;
	_ptrc_glNamedFramebufferDrawBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glNamedFramebufferDrawBuffers");
	if(!_ptrc_glNamedFramebufferDrawBuffers) numFailed++;
	_ptrc_glNamedFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glNamedFramebufferParameteri");
	if(!_ptrc_glNamedFramebufferParameteri) numFailed++;
	_ptrc_glNamedFramebufferReadBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glNamedFramebufferReadBuffer");
	if(!_ptrc_glNamedFramebufferReadBuffer) numFailed++;
	_ptrc_glNamedFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glNamedFramebufferRenderbuffer");
	if(!_ptrc_glNamedFramebufferRenderbuffer) numFailed++;
	_ptrc_glNamedFramebufferTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture");
	if(!_ptrc_glNamedFramebufferTexture) numFailed++;
	_ptrc_glNamedFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTextureLayer");
	if(!_ptrc_glNamedFramebufferTextureLayer) numFailed++;
	_ptrc_glNamedRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorage");
	if(!_ptrc_glNamedRenderbufferStorage) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisample");
	if(!_ptrc_glNamedRenderbufferStorageMultisample) numFailed++;
	_ptrc_glTextureBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glTextureBuffer");
	if(!_ptrc_glTextureBuffer) numFailed++;
	_ptrc_glTextureBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTextureBufferRange");
	if(!_ptrc_glTextureBufferRange) numFailed++;
	_ptrc_glTextureParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glTextureParameterIiv");
	if(!_ptrc_glTextureParameterIiv) numFailed++;
	_ptrc_glTextureParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glTextureParameterIuiv");
	if(!_ptrc_glTextureParameterIuiv) numFailed++;
	_ptrc_glTextureParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glTextureParameterf");
	if(!_ptrc_glTextureParameterf) numFailed++;
	_ptrc_glTextureParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glTextureParameterfv");
	if(!_ptrc_glTextureParameterfv) numFailed++;
	_ptrc_glTextureParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glTextureParameteri");
	if(!_ptrc_glTextureParameteri) numFailed++;
	_ptrc_glTextureParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glTextureParameteriv");
	if(!_ptrc_glTextureParameteriv) numFailed++;
	_ptrc_glTextureStorage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTextureStorage1D");
	if(!_ptrc_glTextureStorage1D) numFailed++;
	_ptrc_glTextureStorage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage2D");
	if(!_ptrc_glTextureStorage2D) numFailed++;
	_ptrc_glTextureStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage2DMultisample");
	if(!_ptrc_glTextureStorage2DMultisample) numFailed++;
	_ptrc_glTextureStorage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage3D");
	if(!_ptrc_glTextureStorage3D) numFailed++;
	_ptrc_glTextureStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage3DMultisample");
	if(!_ptrc_glTextureStorage3DMultisample) numFailed++;
	_ptrc_glTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage1D");
	if(!_ptrc_glTextureSubImage1D) numFailed++;
	_ptrc_glTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage2D");
	if(!_ptrc_glTextureSubImage2D) numFailed++;
	_ptrc_glTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage3D");
	if(!_ptrc_glTextureSubImage3D) numFailed++;
	_ptrc_glTransformFeedbackBufferBase = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glTransformFeedbackBufferBase");
	if(!_ptrc_glTransformFeedbackBufferBase) numFailed++;
	_ptrc_glTransformFeedbackBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTransformFeedbackBufferRange");
	if(!_ptrc_glTransformFeedbackBufferRange) numFailed++;
	_ptrc_glUnmapNamedBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUnmapNamedBuffer");
	if(!_ptrc_glUnmapNamedBuffer) numFailed++;
	_ptrc_glVertexArrayAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayAttribBinding");
	if(!_ptrc_glVertexArrayAttribBinding) numFailed++;
	_ptrc_glVertexArrayAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexArrayAttribFormat");
	if(!_ptrc_glVertexArrayAttribFormat) numFailed++;
	_ptrc_glVertexArrayAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayAttribIFormat");
	if(!_ptrc_glVertexArrayAttribIFormat) numFailed++;
	_ptrc_glVertexArrayAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayAttribLFormat");
	if(!_ptrc_glVertexArrayAttribLFormat) numFailed++;
	_ptrc_glVertexArrayBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayBindingDivisor");
	if(!_ptrc_glVertexArrayBindingDivisor) numFailed++;
	_ptrc_glVertexArrayElementBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexArrayElementBuffer");
	if(!_ptrc_glVertexArrayElementBuffer) numFailed++;
	_ptrc_glVertexArrayVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glVertexArrayVertexBuffer");
	if(!_ptrc_glVertexArrayVertexBuffer) numFailed++;
	_ptrc_glVertexArrayVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glVertexArrayVertexBuffers");
	if(!_ptrc_glVertexArrayVertexBuffers) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersARB)(GLsizei n, const GLenum * bufs) = NULL;

static int Load_ARB_draw_buffers(void)
{
	int numFailed = 0;
	_ptrc_glDrawBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffersARB");
	if(!_ptrc_glDrawBuffersARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationiARB)(GLuint buf, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst) = NULL;

static int Load_ARB_draw_buffers_blend(void)
{
	int numFailed = 0;
	_ptrc_glBlendEquationSeparateiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparateiARB");
	if(!_ptrc_glBlendEquationSeparateiARB) numFailed++;
	_ptrc_glBlendEquationiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBlendEquationiARB");
	if(!_ptrc_glBlendEquationiARB) numFailed++;
	_ptrc_glBlendFuncSeparateiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateiARB");
	if(!_ptrc_glBlendFuncSeparateiARB) numFailed++;
	_ptrc_glBlendFunciARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendFunciARB");
	if(!_ptrc_glBlendFunciARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum mode, const void * indirect) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect) = NULL;

static int Load_ARB_draw_indirect(void)
{
	int numFailed = 0;
	_ptrc_glDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *))IntGetProcAddress("glDrawArraysIndirect");
	if(!_ptrc_glDrawArraysIndirect) numFailed++;
	_ptrc_glDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *))IntGetProcAddress("glDrawElementsIndirect");
	if(!_ptrc_glDrawElementsIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) = NULL;

static int Load_ARB_draw_elements_base_vertex(void)
{
	int numFailed = 0;
	_ptrc_glDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLint))IntGetProcAddress("glDrawElementsBaseVertex");
	if(!_ptrc_glDrawElementsBaseVertex) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint))IntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!_ptrc_glDrawElementsInstancedBaseVertex) numFailed++;
	_ptrc_glDrawRangeElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint))IntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!_ptrc_glDrawRangeElementsBaseVertex) numFailed++;
	_ptrc_glMultiDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei, const GLint *))IntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!_ptrc_glMultiDrawElementsBaseVertex) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedARB)(GLenum mode, GLint first, GLsizei count, GLsizei primcount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedARB)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount) = NULL;

static int Load_ARB_draw_instanced(void)
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstancedARB");
	if(!_ptrc_glDrawArraysInstancedARB) numFailed++;
	_ptrc_glDrawElementsInstancedARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei))IntGetProcAddress("glDrawElementsInstancedARB");
	if(!_ptrc_glDrawElementsInstancedARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat d) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat n, GLfloat f) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length) = NULL;

static int Load_ARB_ES2_compatibility(void)
{
	int numFailed = 0;
	_ptrc_glClearDepthf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glClearDepthf");
	if(!_ptrc_glClearDepthf) numFailed++;
	_ptrc_glDepthRangef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glDepthRangef");
	if(!_ptrc_glDepthRangef) numFailed++;
	_ptrc_glGetShaderPrecisionFormat = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *, GLint *))IntGetProcAddress("glGetShaderPrecisionFormat");
	if(!_ptrc_glGetShaderPrecisionFormat) numFailed++;
	_ptrc_glReleaseShaderCompiler = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glReleaseShaderCompiler");
	if(!_ptrc_glReleaseShaderCompiler) numFailed++;
	_ptrc_glShaderBinary = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLenum, const void *, GLsizei))IntGetProcAddress("glShaderBinary");
	if(!_ptrc_glShaderBinary) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierByRegion)(GLbitfield barriers) = NULL;

static int Load_ARB_ES3_1_compatibility(void)
{
	int numFailed = 0;
	_ptrc_glMemoryBarrierByRegion = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrierByRegion");
	if(!_ptrc_glMemoryBarrierByRegion) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveBoundingBoxARB)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) = NULL;

static int Load_ARB_ES3_2_compatibility(void)
{
	int numFailed = 0;
	_ptrc_glPrimitiveBoundingBoxARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glPrimitiveBoundingBoxARB");
	if(!_ptrc_glPrimitiveBoundingBoxARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum target, GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei n, const GLuint * programs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei n, GLuint * programs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum target, GLuint index, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum target, GLuint index, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum target, GLuint index, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum target, GLuint index, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum target, GLenum pname, void * string) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum target, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum target, GLenum format, GLsizei len, const void * string) = NULL;

static int Load_ARB_fragment_program(void)
{
	int numFailed = 0;
	_ptrc_glBindProgramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramARB");
	if(!_ptrc_glBindProgramARB) numFailed++;
	_ptrc_glDeleteProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsARB");
	if(!_ptrc_glDeleteProgramsARB) numFailed++;
	_ptrc_glGenProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsARB");
	if(!_ptrc_glGenProgramsARB) numFailed++;
	_ptrc_glGetProgramEnvParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramEnvParameterdvARB");
	if(!_ptrc_glGetProgramEnvParameterdvARB) numFailed++;
	_ptrc_glGetProgramEnvParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramEnvParameterfvARB");
	if(!_ptrc_glGetProgramEnvParameterfvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramLocalParameterdvARB");
	if(!_ptrc_glGetProgramLocalParameterdvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramLocalParameterfvARB");
	if(!_ptrc_glGetProgramLocalParameterfvARB) numFailed++;
	_ptrc_glGetProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, void *))IntGetProcAddress("glGetProgramStringARB");
	if(!_ptrc_glGetProgramStringARB) numFailed++;
	_ptrc_glGetProgramivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramivARB");
	if(!_ptrc_glGetProgramivARB) numFailed++;
	_ptrc_glIsProgramARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramARB");
	if(!_ptrc_glIsProgramARB) numFailed++;
	_ptrc_glProgramEnvParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramEnvParameter4dARB");
	if(!_ptrc_glProgramEnvParameter4dARB) numFailed++;
	_ptrc_glProgramEnvParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramEnvParameter4dvARB");
	if(!_ptrc_glProgramEnvParameter4dvARB) numFailed++;
	_ptrc_glProgramEnvParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramEnvParameter4fARB");
	if(!_ptrc_glProgramEnvParameter4fARB) numFailed++;
	_ptrc_glProgramEnvParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramEnvParameter4fvARB");
	if(!_ptrc_glProgramEnvParameter4fvARB) numFailed++;
	_ptrc_glProgramLocalParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramLocalParameter4dARB");
	if(!_ptrc_glProgramLocalParameter4dARB) numFailed++;
	_ptrc_glProgramLocalParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramLocalParameter4dvARB");
	if(!_ptrc_glProgramLocalParameter4dvARB) numFailed++;
	_ptrc_glProgramLocalParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramLocalParameter4fARB");
	if(!_ptrc_glProgramLocalParameter4fARB) numFailed++;
	_ptrc_glProgramLocalParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramLocalParameter4fvARB");
	if(!_ptrc_glProgramLocalParameter4fvARB) numFailed++;
	_ptrc_glProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const void *))IntGetProcAddress("glProgramStringARB");
	if(!_ptrc_glProgramStringARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;

static int Load_ARB_framebuffer_no_attachments(void)
{
	int numFailed = 0;
	_ptrc_glFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFramebufferParameteri");
	if(!_ptrc_glFramebufferParameteri) numFailed++;
	_ptrc_glGetFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameteriv");
	if(!_ptrc_glGetFramebufferParameteriv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum target, GLuint framebuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei n, GLuint * framebuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint framebuffer) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;

static int Load_ARB_framebuffer_object(void)
{
	int numFailed = 0;
	_ptrc_glBindFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebuffer");
	if(!_ptrc_glBindFramebuffer) numFailed++;
	_ptrc_glBindRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbuffer");
	if(!_ptrc_glBindRenderbuffer) numFailed++;
	_ptrc_glBlitFramebuffer = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebuffer");
	if(!_ptrc_glBlitFramebuffer) numFailed++;
	_ptrc_glCheckFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatus");
	if(!_ptrc_glCheckFramebufferStatus) numFailed++;
	_ptrc_glDeleteFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffers");
	if(!_ptrc_glDeleteFramebuffers) numFailed++;
	_ptrc_glDeleteRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffers");
	if(!_ptrc_glDeleteRenderbuffers) numFailed++;
	_ptrc_glFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbuffer");
	if(!_ptrc_glFramebufferRenderbuffer) numFailed++;
	_ptrc_glFramebufferTexture1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1D");
	if(!_ptrc_glFramebufferTexture1D) numFailed++;
	_ptrc_glFramebufferTexture2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2D");
	if(!_ptrc_glFramebufferTexture2D) numFailed++;
	_ptrc_glFramebufferTexture3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3D");
	if(!_ptrc_glFramebufferTexture3D) numFailed++;
	_ptrc_glFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayer");
	if(!_ptrc_glFramebufferTextureLayer) numFailed++;
	_ptrc_glGenFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffers");
	if(!_ptrc_glGenFramebuffers) numFailed++;
	_ptrc_glGenRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffers");
	if(!_ptrc_glGenRenderbuffers) numFailed++;
	_ptrc_glGenerateMipmap = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmap");
	if(!_ptrc_glGenerateMipmap) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameteriv");
	if(!_ptrc_glGetRenderbufferParameteriv) numFailed++;
	_ptrc_glIsFramebuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebuffer");
	if(!_ptrc_glIsFramebuffer) numFailed++;
	_ptrc_glIsRenderbuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbuffer");
	if(!_ptrc_glIsRenderbuffer) numFailed++;
	_ptrc_glRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorage");
	if(!_ptrc_glRenderbufferStorage) numFailed++;
	_ptrc_glRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisample");
	if(!_ptrc_glRenderbufferStorageMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureARB)(GLenum target, GLenum attachment, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriARB)(GLuint program, GLenum pname, GLint value) = NULL;

static int Load_ARB_geometry_shader4(void)
{
	int numFailed = 0;
	_ptrc_glFramebufferTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTextureARB");
	if(!_ptrc_glFramebufferTextureARB) numFailed++;
	_ptrc_glFramebufferTextureFaceARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLenum))IntGetProcAddress("glFramebufferTextureFaceARB");
	if(!_ptrc_glFramebufferTextureFaceARB) numFailed++;
	_ptrc_glFramebufferTextureLayerARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayerARB");
	if(!_ptrc_glFramebufferTextureLayerARB) numFailed++;
	_ptrc_glProgramParameteriARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteriARB");
	if(!_ptrc_glProgramParameteriARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint program, GLenum pname, GLint value) = NULL;

static int Load_ARB_get_program_binary(void)
{
	int numFailed = 0;
	_ptrc_glGetProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLenum *, void *))IntGetProcAddress("glGetProgramBinary");
	if(!_ptrc_glGetProgramBinary) numFailed++;
	_ptrc_glProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const void *, GLsizei))IntGetProcAddress("glProgramBinary");
	if(!_ptrc_glProgramBinary) numFailed++;
	_ptrc_glProgramParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteri");
	if(!_ptrc_glProgramParameteri) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels) = NULL;

static int Load_ARB_get_texture_sub_image(void)
{
	int numFailed = 0;
	_ptrc_glGetCompressedTextureSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, void *))IntGetProcAddress("glGetCompressedTextureSubImage");
	if(!_ptrc_glGetCompressedTextureSubImage) numFailed++;
	_ptrc_glGetTextureSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetTextureSubImage");
	if(!_ptrc_glGetTextureSubImage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint program, GLint location, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint location, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint location, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;

static int Load_ARB_gpu_shader_fp64(void)
{
	int numFailed = 0;
	_ptrc_glGetUniformdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble *))IntGetProcAddress("glGetUniformdv");
	if(!_ptrc_glGetUniformdv) numFailed++;
	_ptrc_glUniform1d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble))IntGetProcAddress("glUniform1d");
	if(!_ptrc_glUniform1d) numFailed++;
	_ptrc_glUniform1dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform1dv");
	if(!_ptrc_glUniform1dv) numFailed++;
	_ptrc_glUniform2d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble))IntGetProcAddress("glUniform2d");
	if(!_ptrc_glUniform2d) numFailed++;
	_ptrc_glUniform2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform2dv");
	if(!_ptrc_glUniform2dv) numFailed++;
	_ptrc_glUniform3d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform3d");
	if(!_ptrc_glUniform3d) numFailed++;
	_ptrc_glUniform3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform3dv");
	if(!_ptrc_glUniform3dv) numFailed++;
	_ptrc_glUniform4d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform4d");
	if(!_ptrc_glUniform4d) numFailed++;
	_ptrc_glUniform4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform4dv");
	if(!_ptrc_glUniform4dv) numFailed++;
	_ptrc_glUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2dv");
	if(!_ptrc_glUniformMatrix2dv) numFailed++;
	_ptrc_glUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x3dv");
	if(!_ptrc_glUniformMatrix2x3dv) numFailed++;
	_ptrc_glUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x4dv");
	if(!_ptrc_glUniformMatrix2x4dv) numFailed++;
	_ptrc_glUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3dv");
	if(!_ptrc_glUniformMatrix3dv) numFailed++;
	_ptrc_glUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x2dv");
	if(!_ptrc_glUniformMatrix3x2dv) numFailed++;
	_ptrc_glUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x4dv");
	if(!_ptrc_glUniformMatrix3x4dv) numFailed++;
	_ptrc_glUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4dv");
	if(!_ptrc_glUniformMatrix4dv) numFailed++;
	_ptrc_glUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x2dv");
	if(!_ptrc_glUniformMatrix4x2dv) numFailed++;
	_ptrc_glUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x3dv");
	if(!_ptrc_glUniformMatrix4x3dv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vARB)(GLuint program, GLint location, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vARB)(GLuint program, GLint location, GLuint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformi64vARB)(GLuint program, GLint location, GLsizei bufSize, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformui64vARB)(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64ARB)(GLuint program, GLint location, GLint64 x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64ARB)(GLuint program, GLint location, GLuint64 x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64ARB)(GLint location, GLint64 x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vARB)(GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64ARB)(GLint location, GLuint64 x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vARB)(GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64ARB)(GLint location, GLint64 x, GLint64 y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vARB)(GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64ARB)(GLint location, GLuint64 x, GLuint64 y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vARB)(GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vARB)(GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vARB)(GLint location, GLsizei count, const GLuint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vARB)(GLint location, GLsizei count, const GLint64 * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vARB)(GLint location, GLsizei count, const GLuint64 * value) = NULL;

static int Load_ARB_gpu_shader_int64(void)
{
	int numFailed = 0;
	_ptrc_glGetUniformi64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64 *))IntGetProcAddress("glGetUniformi64vARB");
	if(!_ptrc_glGetUniformi64vARB) numFailed++;
	_ptrc_glGetUniformui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64 *))IntGetProcAddress("glGetUniformui64vARB");
	if(!_ptrc_glGetUniformui64vARB) numFailed++;
	_ptrc_glGetnUniformi64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLint64 *))IntGetProcAddress("glGetnUniformi64vARB");
	if(!_ptrc_glGetnUniformi64vARB) numFailed++;
	_ptrc_glGetnUniformui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLuint64 *))IntGetProcAddress("glGetnUniformui64vARB");
	if(!_ptrc_glGetnUniformui64vARB) numFailed++;
	_ptrc_glProgramUniform1i64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64))IntGetProcAddress("glProgramUniform1i64ARB");
	if(!_ptrc_glProgramUniform1i64ARB) numFailed++;
	_ptrc_glProgramUniform1i64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64 *))IntGetProcAddress("glProgramUniform1i64vARB");
	if(!_ptrc_glProgramUniform1i64vARB) numFailed++;
	_ptrc_glProgramUniform1ui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64))IntGetProcAddress("glProgramUniform1ui64ARB");
	if(!_ptrc_glProgramUniform1ui64ARB) numFailed++;
	_ptrc_glProgramUniform1ui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniform1ui64vARB");
	if(!_ptrc_glProgramUniform1ui64vARB) numFailed++;
	_ptrc_glProgramUniform2i64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64, GLint64))IntGetProcAddress("glProgramUniform2i64ARB");
	if(!_ptrc_glProgramUniform2i64ARB) numFailed++;
	_ptrc_glProgramUniform2i64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64 *))IntGetProcAddress("glProgramUniform2i64vARB");
	if(!_ptrc_glProgramUniform2i64vARB) numFailed++;
	_ptrc_glProgramUniform2ui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64, GLuint64))IntGetProcAddress("glProgramUniform2ui64ARB");
	if(!_ptrc_glProgramUniform2ui64ARB) numFailed++;
	_ptrc_glProgramUniform2ui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniform2ui64vARB");
	if(!_ptrc_glProgramUniform2ui64vARB) numFailed++;
	_ptrc_glProgramUniform3i64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64, GLint64, GLint64))IntGetProcAddress("glProgramUniform3i64ARB");
	if(!_ptrc_glProgramUniform3i64ARB) numFailed++;
	_ptrc_glProgramUniform3i64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64 *))IntGetProcAddress("glProgramUniform3i64vARB");
	if(!_ptrc_glProgramUniform3i64vARB) numFailed++;
	_ptrc_glProgramUniform3ui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64, GLuint64, GLuint64))IntGetProcAddress("glProgramUniform3ui64ARB");
	if(!_ptrc_glProgramUniform3ui64ARB) numFailed++;
	_ptrc_glProgramUniform3ui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniform3ui64vARB");
	if(!_ptrc_glProgramUniform3ui64vARB) numFailed++;
	_ptrc_glProgramUniform4i64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64, GLint64, GLint64, GLint64))IntGetProcAddress("glProgramUniform4i64ARB");
	if(!_ptrc_glProgramUniform4i64ARB) numFailed++;
	_ptrc_glProgramUniform4i64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64 *))IntGetProcAddress("glProgramUniform4i64vARB");
	if(!_ptrc_glProgramUniform4i64vARB) numFailed++;
	_ptrc_glProgramUniform4ui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64, GLuint64, GLuint64, GLuint64))IntGetProcAddress("glProgramUniform4ui64ARB");
	if(!_ptrc_glProgramUniform4ui64ARB) numFailed++;
	_ptrc_glProgramUniform4ui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniform4ui64vARB");
	if(!_ptrc_glProgramUniform4ui64vARB) numFailed++;
	_ptrc_glUniform1i64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint64))IntGetProcAddress("glUniform1i64ARB");
	if(!_ptrc_glUniform1i64ARB) numFailed++;
	_ptrc_glUniform1i64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64 *))IntGetProcAddress("glUniform1i64vARB");
	if(!_ptrc_glUniform1i64vARB) numFailed++;
	_ptrc_glUniform1ui64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64))IntGetProcAddress("glUniform1ui64ARB");
	if(!_ptrc_glUniform1ui64ARB) numFailed++;
	_ptrc_glUniform1ui64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniform1ui64vARB");
	if(!_ptrc_glUniform1ui64vARB) numFailed++;
	_ptrc_glUniform2i64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint64, GLint64))IntGetProcAddress("glUniform2i64ARB");
	if(!_ptrc_glUniform2i64ARB) numFailed++;
	_ptrc_glUniform2i64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64 *))IntGetProcAddress("glUniform2i64vARB");
	if(!_ptrc_glUniform2i64vARB) numFailed++;
	_ptrc_glUniform2ui64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64, GLuint64))IntGetProcAddress("glUniform2ui64ARB");
	if(!_ptrc_glUniform2ui64ARB) numFailed++;
	_ptrc_glUniform2ui64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniform2ui64vARB");
	if(!_ptrc_glUniform2ui64vARB) numFailed++;
	_ptrc_glUniform3i64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint64, GLint64, GLint64))IntGetProcAddress("glUniform3i64ARB");
	if(!_ptrc_glUniform3i64ARB) numFailed++;
	_ptrc_glUniform3i64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64 *))IntGetProcAddress("glUniform3i64vARB");
	if(!_ptrc_glUniform3i64vARB) numFailed++;
	_ptrc_glUniform3ui64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64, GLuint64, GLuint64))IntGetProcAddress("glUniform3ui64ARB");
	if(!_ptrc_glUniform3ui64ARB) numFailed++;
	_ptrc_glUniform3ui64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniform3ui64vARB");
	if(!_ptrc_glUniform3ui64vARB) numFailed++;
	_ptrc_glUniform4i64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint64, GLint64, GLint64, GLint64))IntGetProcAddress("glUniform4i64ARB");
	if(!_ptrc_glUniform4i64ARB) numFailed++;
	_ptrc_glUniform4i64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64 *))IntGetProcAddress("glUniform4i64vARB");
	if(!_ptrc_glUniform4i64vARB) numFailed++;
	_ptrc_glUniform4ui64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64, GLuint64, GLuint64, GLuint64))IntGetProcAddress("glUniform4ui64ARB");
	if(!_ptrc_glUniform4ui64ARB) numFailed++;
	_ptrc_glUniform4ui64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniform4ui64vARB");
	if(!_ptrc_glUniform4ui64vARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquation)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorSubTable)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTable)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfv)(GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameteriv)(GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1D)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterf)(GLenum target, GLenum pname, GLfloat params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfv)(GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteri)(GLenum target, GLenum pname, GLint params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriv)(GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTable)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTable)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTable)(GLenum target, GLenum format, GLenum type, void * table) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilter)(GLenum target, GLenum format, GLenum type, void * image) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilter)(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glHistogram)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMinmax)(GLenum target, GLenum internalformat, GLboolean sink) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetHistogram)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetMinmax)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column) = NULL;

static int Load_ARB_imaging(void)
{
	int numFailed = 0;
	_ptrc_glBlendColor = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBlendColor");
	if(!_ptrc_glBlendColor) numFailed++;
	_ptrc_glBlendEquation = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBlendEquation");
	if(!_ptrc_glBlendEquation) numFailed++;
	_ptrc_glColorSubTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glColorSubTable");
	if(!_ptrc_glColorSubTable) numFailed++;
	_ptrc_glColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glColorTable");
	if(!_ptrc_glColorTable) numFailed++;
	_ptrc_glColorTableParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glColorTableParameterfv");
	if(!_ptrc_glColorTableParameterfv) numFailed++;
	_ptrc_glColorTableParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glColorTableParameteriv");
	if(!_ptrc_glColorTableParameteriv) numFailed++;
	_ptrc_glConvolutionFilter1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glConvolutionFilter1D");
	if(!_ptrc_glConvolutionFilter1D) numFailed++;
	_ptrc_glConvolutionFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glConvolutionFilter2D");
	if(!_ptrc_glConvolutionFilter2D) numFailed++;
	_ptrc_glConvolutionParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glConvolutionParameterf");
	if(!_ptrc_glConvolutionParameterf) numFailed++;
	_ptrc_glConvolutionParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glConvolutionParameterfv");
	if(!_ptrc_glConvolutionParameterfv) numFailed++;
	_ptrc_glConvolutionParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glConvolutionParameteri");
	if(!_ptrc_glConvolutionParameteri) numFailed++;
	_ptrc_glConvolutionParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glConvolutionParameteriv");
	if(!_ptrc_glConvolutionParameteriv) numFailed++;
	_ptrc_glCopyColorSubTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorSubTable");
	if(!_ptrc_glCopyColorSubTable) numFailed++;
	_ptrc_glCopyColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorTable");
	if(!_ptrc_glCopyColorTable) numFailed++;
	_ptrc_glCopyConvolutionFilter1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyConvolutionFilter1D");
	if(!_ptrc_glCopyConvolutionFilter1D) numFailed++;
	_ptrc_glCopyConvolutionFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyConvolutionFilter2D");
	if(!_ptrc_glCopyConvolutionFilter2D) numFailed++;
	_ptrc_glGetColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, void *))IntGetProcAddress("glGetColorTable");
	if(!_ptrc_glGetColorTable) numFailed++;
	_ptrc_glGetColorTableParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetColorTableParameterfv");
	if(!_ptrc_glGetColorTableParameterfv) numFailed++;
	_ptrc_glGetColorTableParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetColorTableParameteriv");
	if(!_ptrc_glGetColorTableParameteriv) numFailed++;
	_ptrc_glGetConvolutionFilter = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, void *))IntGetProcAddress("glGetConvolutionFilter");
	if(!_ptrc_glGetConvolutionFilter) numFailed++;
	_ptrc_glGetConvolutionParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetConvolutionParameterfv");
	if(!_ptrc_glGetConvolutionParameterfv) numFailed++;
	_ptrc_glGetConvolutionParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetConvolutionParameteriv");
	if(!_ptrc_glGetConvolutionParameteriv) numFailed++;
	_ptrc_glGetHistogram = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, void *))IntGetProcAddress("glGetHistogram");
	if(!_ptrc_glGetHistogram) numFailed++;
	_ptrc_glGetHistogramParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetHistogramParameterfv");
	if(!_ptrc_glGetHistogramParameterfv) numFailed++;
	_ptrc_glGetHistogramParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetHistogramParameteriv");
	if(!_ptrc_glGetHistogramParameteriv) numFailed++;
	_ptrc_glGetMinmax = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, void *))IntGetProcAddress("glGetMinmax");
	if(!_ptrc_glGetMinmax) numFailed++;
	_ptrc_glGetMinmaxParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMinmaxParameterfv");
	if(!_ptrc_glGetMinmaxParameterfv) numFailed++;
	_ptrc_glGetMinmaxParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMinmaxParameteriv");
	if(!_ptrc_glGetMinmaxParameteriv) numFailed++;
	_ptrc_glGetSeparableFilter = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, void *, void *, void *))IntGetProcAddress("glGetSeparableFilter");
	if(!_ptrc_glGetSeparableFilter) numFailed++;
	_ptrc_glHistogram = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLboolean))IntGetProcAddress("glHistogram");
	if(!_ptrc_glHistogram) numFailed++;
	_ptrc_glMinmax = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLboolean))IntGetProcAddress("glMinmax");
	if(!_ptrc_glMinmax) numFailed++;
	_ptrc_glResetHistogram = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetHistogram");
	if(!_ptrc_glResetHistogram) numFailed++;
	_ptrc_glResetMinmax = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetMinmax");
	if(!_ptrc_glResetMinmax) numFailed++;
	_ptrc_glSeparableFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const void *, const void *))IntGetProcAddress("glSeparableFilter2D");
	if(!_ptrc_glSeparableFilter2D) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) = NULL;

static int Load_ARB_indirect_parameters(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectCountARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirectCountARB");
	if(!_ptrc_glMultiDrawArraysIndirectCountARB) numFailed++;
	_ptrc_glMultiDrawElementsIndirectCountARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirectCountARB");
	if(!_ptrc_glMultiDrawElementsIndirectCountARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisorARB)(GLuint index, GLuint divisor) = NULL;

static int Load_ARB_instanced_arrays(void)
{
	int numFailed = 0;
	_ptrc_glVertexAttribDivisorARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribDivisorARB");
	if(!_ptrc_glVertexAttribDivisorARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params) = NULL;

static int Load_ARB_internalformat_query(void)
{
	int numFailed = 0;
	_ptrc_glGetInternalformativ = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetInternalformativ");
	if(!_ptrc_glGetInternalformativ) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params) = NULL;

static int Load_ARB_internalformat_query2(void)
{
	int numFailed = 0;
	_ptrc_glGetInternalformati64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint64 *))IntGetProcAddress("glGetInternalformati64v");
	if(!_ptrc_glGetInternalformati64v) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) = NULL;

static int Load_ARB_invalidate_subdata(void)
{
	int numFailed = 0;
	_ptrc_glInvalidateBufferData = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glInvalidateBufferData");
	if(!_ptrc_glInvalidateBufferData) numFailed++;
	_ptrc_glInvalidateBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glInvalidateBufferSubData");
	if(!_ptrc_glInvalidateBufferSubData) numFailed++;
	_ptrc_glInvalidateFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateFramebuffer");
	if(!_ptrc_glInvalidateFramebuffer) numFailed++;
	_ptrc_glInvalidateSubFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateSubFramebuffer");
	if(!_ptrc_glInvalidateSubFramebuffer) numFailed++;
	_ptrc_glInvalidateTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glInvalidateTexImage");
	if(!_ptrc_glInvalidateTexImage) numFailed++;
	_ptrc_glInvalidateTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glInvalidateTexSubImage");
	if(!_ptrc_glInvalidateTexSubImage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) = NULL;

static int Load_ARB_map_buffer_range(void)
{
	int numFailed = 0;
	_ptrc_glFlushMappedBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedBufferRange");
	if(!_ptrc_glFlushMappedBufferRange) numFailed++;
	_ptrc_glMapBufferRange = (void * (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapBufferRange");
	if(!_ptrc_glMapBufferRange) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint first, GLsizei count, const GLuint * textures) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint first, GLsizei count, const GLuint * samplers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint first, GLsizei count, const GLuint * textures) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides) = NULL;

static int Load_ARB_multi_bind(void)
{
	int numFailed = 0;
	_ptrc_glBindBuffersBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindBuffersBase");
	if(!_ptrc_glBindBuffersBase) numFailed++;
	_ptrc_glBindBuffersRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *))IntGetProcAddress("glBindBuffersRange");
	if(!_ptrc_glBindBuffersRange) numFailed++;
	_ptrc_glBindImageTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindImageTextures");
	if(!_ptrc_glBindImageTextures) numFailed++;
	_ptrc_glBindSamplers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindSamplers");
	if(!_ptrc_glBindSamplers) numFailed++;
	_ptrc_glBindTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindTextures");
	if(!_ptrc_glBindTextures) numFailed++;
	_ptrc_glBindVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glBindVertexBuffers");
	if(!_ptrc_glBindVertexBuffers) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) = NULL;

static int Load_ARB_multi_draw_indirect(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirect");
	if(!_ptrc_glMultiDrawArraysIndirect) numFailed++;
	_ptrc_glMultiDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirect");
	if(!_ptrc_glMultiDrawElementsIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageARB)(GLfloat value, GLboolean invert) = NULL;

static int Load_ARB_multisample(void)
{
	int numFailed = 0;
	_ptrc_glSampleCoverageARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLboolean))IntGetProcAddress("glSampleCoverageARB");
	if(!_ptrc_glSampleCoverageARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveTextureARB)(GLenum texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTextureARB)(GLenum texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dARB)(GLenum target, GLdouble s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dvARB)(GLenum target, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fARB)(GLenum target, GLfloat s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fvARB)(GLenum target, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iARB)(GLenum target, GLint s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1ivARB)(GLenum target, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sARB)(GLenum target, GLshort s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1svARB)(GLenum target, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dARB)(GLenum target, GLdouble s, GLdouble t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dvARB)(GLenum target, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fARB)(GLenum target, GLfloat s, GLfloat t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fvARB)(GLenum target, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iARB)(GLenum target, GLint s, GLint t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2ivARB)(GLenum target, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sARB)(GLenum target, GLshort s, GLshort t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2svARB)(GLenum target, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dvARB)(GLenum target, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fvARB)(GLenum target, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iARB)(GLenum target, GLint s, GLint t, GLint r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3ivARB)(GLenum target, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sARB)(GLenum target, GLshort s, GLshort t, GLshort r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3svARB)(GLenum target, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dvARB)(GLenum target, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fvARB)(GLenum target, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iARB)(GLenum target, GLint s, GLint t, GLint r, GLint q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4ivARB)(GLenum target, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sARB)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4svARB)(GLenum target, const GLshort * v) = NULL;

static int Load_ARB_multitexture(void)
{
	int numFailed = 0;
	_ptrc_glActiveTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveTextureARB");
	if(!_ptrc_glActiveTextureARB) numFailed++;
	_ptrc_glClientActiveTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glClientActiveTextureARB");
	if(!_ptrc_glClientActiveTextureARB) numFailed++;
	_ptrc_glMultiTexCoord1dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble))IntGetProcAddress("glMultiTexCoord1dARB");
	if(!_ptrc_glMultiTexCoord1dARB) numFailed++;
	_ptrc_glMultiTexCoord1dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord1dvARB");
	if(!_ptrc_glMultiTexCoord1dvARB) numFailed++;
	_ptrc_glMultiTexCoord1fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glMultiTexCoord1fARB");
	if(!_ptrc_glMultiTexCoord1fARB) numFailed++;
	_ptrc_glMultiTexCoord1fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord1fvARB");
	if(!_ptrc_glMultiTexCoord1fvARB) numFailed++;
	_ptrc_glMultiTexCoord1iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glMultiTexCoord1iARB");
	if(!_ptrc_glMultiTexCoord1iARB) numFailed++;
	_ptrc_glMultiTexCoord1ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord1ivARB");
	if(!_ptrc_glMultiTexCoord1ivARB) numFailed++;
	_ptrc_glMultiTexCoord1sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort))IntGetProcAddress("glMultiTexCoord1sARB");
	if(!_ptrc_glMultiTexCoord1sARB) numFailed++;
	_ptrc_glMultiTexCoord1svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord1svARB");
	if(!_ptrc_glMultiTexCoord1svARB) numFailed++;
	_ptrc_glMultiTexCoord2dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord2dARB");
	if(!_ptrc_glMultiTexCoord2dARB) numFailed++;
	_ptrc_glMultiTexCoord2dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord2dvARB");
	if(!_ptrc_glMultiTexCoord2dvARB) numFailed++;
	_ptrc_glMultiTexCoord2fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord2fARB");
	if(!_ptrc_glMultiTexCoord2fARB) numFailed++;
	_ptrc_glMultiTexCoord2fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord2fvARB");
	if(!_ptrc_glMultiTexCoord2fvARB) numFailed++;
	_ptrc_glMultiTexCoord2iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint))IntGetProcAddress("glMultiTexCoord2iARB");
	if(!_ptrc_glMultiTexCoord2iARB) numFailed++;
	_ptrc_glMultiTexCoord2ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord2ivARB");
	if(!_ptrc_glMultiTexCoord2ivARB) numFailed++;
	_ptrc_glMultiTexCoord2sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord2sARB");
	if(!_ptrc_glMultiTexCoord2sARB) numFailed++;
	_ptrc_glMultiTexCoord2svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord2svARB");
	if(!_ptrc_glMultiTexCoord2svARB) numFailed++;
	_ptrc_glMultiTexCoord3dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord3dARB");
	if(!_ptrc_glMultiTexCoord3dARB) numFailed++;
	_ptrc_glMultiTexCoord3dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord3dvARB");
	if(!_ptrc_glMultiTexCoord3dvARB) numFailed++;
	_ptrc_glMultiTexCoord3fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord3fARB");
	if(!_ptrc_glMultiTexCoord3fARB) numFailed++;
	_ptrc_glMultiTexCoord3fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord3fvARB");
	if(!_ptrc_glMultiTexCoord3fvARB) numFailed++;
	_ptrc_glMultiTexCoord3iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord3iARB");
	if(!_ptrc_glMultiTexCoord3iARB) numFailed++;
	_ptrc_glMultiTexCoord3ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord3ivARB");
	if(!_ptrc_glMultiTexCoord3ivARB) numFailed++;
	_ptrc_glMultiTexCoord3sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord3sARB");
	if(!_ptrc_glMultiTexCoord3sARB) numFailed++;
	_ptrc_glMultiTexCoord3svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord3svARB");
	if(!_ptrc_glMultiTexCoord3svARB) numFailed++;
	_ptrc_glMultiTexCoord4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord4dARB");
	if(!_ptrc_glMultiTexCoord4dARB) numFailed++;
	_ptrc_glMultiTexCoord4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord4dvARB");
	if(!_ptrc_glMultiTexCoord4dvARB) numFailed++;
	_ptrc_glMultiTexCoord4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord4fARB");
	if(!_ptrc_glMultiTexCoord4fARB) numFailed++;
	_ptrc_glMultiTexCoord4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord4fvARB");
	if(!_ptrc_glMultiTexCoord4fvARB) numFailed++;
	_ptrc_glMultiTexCoord4iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord4iARB");
	if(!_ptrc_glMultiTexCoord4iARB) numFailed++;
	_ptrc_glMultiTexCoord4ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord4ivARB");
	if(!_ptrc_glMultiTexCoord4ivARB) numFailed++;
	_ptrc_glMultiTexCoord4sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord4sARB");
	if(!_ptrc_glMultiTexCoord4sARB) numFailed++;
	_ptrc_glMultiTexCoord4svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord4svARB");
	if(!_ptrc_glMultiTexCoord4svARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryARB)(GLenum target, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueriesARB)(GLsizei n, const GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQueryARB)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenQueriesARB)(GLsizei n, GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectivARB)(GLuint id, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuivARB)(GLuint id, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryivARB)(GLenum target, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQueryARB)(GLuint id) = NULL;

static int Load_ARB_occlusion_query(void)
{
	int numFailed = 0;
	_ptrc_glBeginQueryARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBeginQueryARB");
	if(!_ptrc_glBeginQueryARB) numFailed++;
	_ptrc_glDeleteQueriesARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteQueriesARB");
	if(!_ptrc_glDeleteQueriesARB) numFailed++;
	_ptrc_glEndQueryARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEndQueryARB");
	if(!_ptrc_glEndQueryARB) numFailed++;
	_ptrc_glGenQueriesARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenQueriesARB");
	if(!_ptrc_glGenQueriesARB) numFailed++;
	_ptrc_glGetQueryObjectivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryObjectivARB");
	if(!_ptrc_glGetQueryObjectivARB) numFailed++;
	_ptrc_glGetQueryObjectuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetQueryObjectuivARB");
	if(!_ptrc_glGetQueryObjectuivARB) numFailed++;
	_ptrc_glGetQueryivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetQueryivARB");
	if(!_ptrc_glGetQueryivARB) numFailed++;
	_ptrc_glIsQueryARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsQueryARB");
	if(!_ptrc_glIsQueryARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMaxShaderCompilerThreadsARB)(GLuint count) = NULL;

static int Load_ARB_parallel_shader_compile(void)
{
	int numFailed = 0;
	_ptrc_glMaxShaderCompilerThreadsARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glMaxShaderCompilerThreadsARB");
	if(!_ptrc_glMaxShaderCompilerThreadsARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfARB)(GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvARB)(GLenum pname, const GLfloat * params) = NULL;

static int Load_ARB_point_parameters(void)
{
	int numFailed = 0;
	_ptrc_glPointParameterfARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterfARB");
	if(!_ptrc_glPointParameterfARB) numFailed++;
	_ptrc_glPointParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfvARB");
	if(!_ptrc_glPointParameterfvARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint * params) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params) = NULL;

static int Load_ARB_program_interface_query(void)
{
	int numFailed = 0;
	_ptrc_glGetProgramInterfaceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramInterfaceiv");
	if(!_ptrc_glGetProgramInterfaceiv) numFailed++;
	_ptrc_glGetProgramResourceIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceIndex");
	if(!_ptrc_glGetProgramResourceIndex) numFailed++;
	_ptrc_glGetProgramResourceLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocation");
	if(!_ptrc_glGetProgramResourceLocation) numFailed++;
	_ptrc_glGetProgramResourceLocationIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!_ptrc_glGetProgramResourceLocationIndex) numFailed++;
	_ptrc_glGetProgramResourceName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramResourceName");
	if(!_ptrc_glGetProgramResourceName) numFailed++;
	_ptrc_glGetProgramResourceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetProgramResourceiv");
	if(!_ptrc_glGetProgramResourceiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum mode) = NULL;

static int Load_ARB_provoking_vertex(void)
{
	int numFailed = 0;
	_ptrc_glProvokingVertex = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertex");
	if(!_ptrc_glProvokingVertex) numFailed++;
	return numFailed;
}

GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatusARB)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnColorTableARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void * img) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnConvolutionFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnHistogramARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapdvARB)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapfvARB)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapivARB)(GLenum target, GLenum query, GLsizei bufSize, GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMinmaxARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapfvARB)(GLenum map, GLsizei bufSize, GLfloat * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapuivARB)(GLenum map, GLsizei bufSize, GLuint * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapusvARB)(GLenum map, GLsizei bufSize, GLushort * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPolygonStippleARB)(GLsizei bufSize, GLubyte * pattern) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnSeparableFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) = NULL;

static int Load_ARB_robustness(void)
{
	int numFailed = 0;
	_ptrc_glGetGraphicsResetStatusARB = (GLenum (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glGetGraphicsResetStatusARB");
	if(!_ptrc_glGetGraphicsResetStatusARB) numFailed++;
	_ptrc_glGetnColorTableARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnColorTableARB");
	if(!_ptrc_glGetnColorTableARB) numFailed++;
	_ptrc_glGetnCompressedTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, void *))IntGetProcAddress("glGetnCompressedTexImageARB");
	if(!_ptrc_glGetnCompressedTexImageARB) numFailed++;
	_ptrc_glGetnConvolutionFilterARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnConvolutionFilterARB");
	if(!_ptrc_glGetnConvolutionFilterARB) numFailed++;
	_ptrc_glGetnHistogramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnHistogramARB");
	if(!_ptrc_glGetnHistogramARB) numFailed++;
	_ptrc_glGetnMapdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLdouble *))IntGetProcAddress("glGetnMapdvARB");
	if(!_ptrc_glGetnMapdvARB) numFailed++;
	_ptrc_glGetnMapfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLfloat *))IntGetProcAddress("glGetnMapfvARB");
	if(!_ptrc_glGetnMapfvARB) numFailed++;
	_ptrc_glGetnMapivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetnMapivARB");
	if(!_ptrc_glGetnMapivARB) numFailed++;
	_ptrc_glGetnMinmaxARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnMinmaxARB");
	if(!_ptrc_glGetnMinmaxARB) numFailed++;
	_ptrc_glGetnPixelMapfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLfloat *))IntGetProcAddress("glGetnPixelMapfvARB");
	if(!_ptrc_glGetnPixelMapfvARB) numFailed++;
	_ptrc_glGetnPixelMapuivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glGetnPixelMapuivARB");
	if(!_ptrc_glGetnPixelMapuivARB) numFailed++;
	_ptrc_glGetnPixelMapusvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLushort *))IntGetProcAddress("glGetnPixelMapusvARB");
	if(!_ptrc_glGetnPixelMapusvARB) numFailed++;
	_ptrc_glGetnPolygonStippleARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLubyte *))IntGetProcAddress("glGetnPolygonStippleARB");
	if(!_ptrc_glGetnPolygonStippleARB) numFailed++;
	_ptrc_glGetnSeparableFilterARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, void *, GLsizei, void *, void *))IntGetProcAddress("glGetnSeparableFilterARB");
	if(!_ptrc_glGetnSeparableFilterARB) numFailed++;
	_ptrc_glGetnTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnTexImageARB");
	if(!_ptrc_glGetnTexImageARB) numFailed++;
	_ptrc_glGetnUniformdvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLdouble *))IntGetProcAddress("glGetnUniformdvARB");
	if(!_ptrc_glGetnUniformdvARB) numFailed++;
	_ptrc_glGetnUniformfvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLfloat *))IntGetProcAddress("glGetnUniformfvARB");
	if(!_ptrc_glGetnUniformfvARB) numFailed++;
	_ptrc_glGetnUniformivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLint *))IntGetProcAddress("glGetnUniformivARB");
	if(!_ptrc_glGetnUniformivARB) numFailed++;
	_ptrc_glGetnUniformuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLuint *))IntGetProcAddress("glGetnUniformuivARB");
	if(!_ptrc_glGetnUniformuivARB) numFailed++;
	_ptrc_glReadnPixelsARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glReadnPixelsARB");
	if(!_ptrc_glReadnPixelsARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShadingARB)(GLfloat value) = NULL;

static int Load_ARB_sample_shading(void)
{
	int numFailed = 0;
	_ptrc_glMinSampleShadingARB = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glMinSampleShadingARB");
	if(!_ptrc_glMinSampleShadingARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint unit, GLuint sampler) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei count, const GLuint * samplers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei count, GLuint * samplers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint sampler) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param) = NULL;

static int Load_ARB_sampler_objects(void)
{
	int numFailed = 0;
	_ptrc_glBindSampler = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindSampler");
	if(!_ptrc_glBindSampler) numFailed++;
	_ptrc_glDeleteSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteSamplers");
	if(!_ptrc_glDeleteSamplers) numFailed++;
	_ptrc_glGenSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenSamplers");
	if(!_ptrc_glGenSamplers) numFailed++;
	_ptrc_glGetSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameterIiv");
	if(!_ptrc_glGetSamplerParameterIiv) numFailed++;
	_ptrc_glGetSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetSamplerParameterIuiv");
	if(!_ptrc_glGetSamplerParameterIuiv) numFailed++;
	_ptrc_glGetSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetSamplerParameterfv");
	if(!_ptrc_glGetSamplerParameterfv) numFailed++;
	_ptrc_glGetSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameteriv");
	if(!_ptrc_glGetSamplerParameteriv) numFailed++;
	_ptrc_glIsSampler = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsSampler");
	if(!_ptrc_glIsSampler) numFailed++;
	_ptrc_glSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameterIiv");
	if(!_ptrc_glSamplerParameterIiv) numFailed++;
	_ptrc_glSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glSamplerParameterIuiv");
	if(!_ptrc_glSamplerParameterIuiv) numFailed++;
	_ptrc_glSamplerParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glSamplerParameterf");
	if(!_ptrc_glSamplerParameterf) numFailed++;
	_ptrc_glSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glSamplerParameterfv");
	if(!_ptrc_glSamplerParameterfv) numFailed++;
	_ptrc_glSamplerParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glSamplerParameteri");
	if(!_ptrc_glSamplerParameteri) numFailed++;
	_ptrc_glSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameteriv");
	if(!_ptrc_glSamplerParameteriv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint pipeline, GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint pipeline) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const* strings) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei n, const GLuint * pipelines) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei n, GLuint * pipelines) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint pipeline) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint program, GLint location, GLint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint pipeline) = NULL;

static int Load_ARB_separate_shader_objects(void)
{
	int numFailed = 0;
	_ptrc_glActiveShaderProgram = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glActiveShaderProgram");
	if(!_ptrc_glActiveShaderProgram) numFailed++;
	_ptrc_glBindProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindProgramPipeline");
	if(!_ptrc_glBindProgramPipeline) numFailed++;
	_ptrc_glCreateShaderProgramv = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLchar *const*))IntGetProcAddress("glCreateShaderProgramv");
	if(!_ptrc_glCreateShaderProgramv) numFailed++;
	_ptrc_glDeleteProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramPipelines");
	if(!_ptrc_glDeleteProgramPipelines) numFailed++;
	_ptrc_glGenProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramPipelines");
	if(!_ptrc_glGenProgramPipelines) numFailed++;
	_ptrc_glGetProgramPipelineInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!_ptrc_glGetProgramPipelineInfoLog) numFailed++;
	_ptrc_glGetProgramPipelineiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramPipelineiv");
	if(!_ptrc_glGetProgramPipelineiv) numFailed++;
	_ptrc_glIsProgramPipeline = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramPipeline");
	if(!_ptrc_glIsProgramPipeline) numFailed++;
	_ptrc_glProgramUniform1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1d");
	if(!_ptrc_glProgramUniform1d) numFailed++;
	_ptrc_glProgramUniform1dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dv");
	if(!_ptrc_glProgramUniform1dv) numFailed++;
	_ptrc_glProgramUniform1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1f");
	if(!_ptrc_glProgramUniform1f) numFailed++;
	_ptrc_glProgramUniform1fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fv");
	if(!_ptrc_glProgramUniform1fv) numFailed++;
	_ptrc_glProgramUniform1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1i");
	if(!_ptrc_glProgramUniform1i) numFailed++;
	_ptrc_glProgramUniform1iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1iv");
	if(!_ptrc_glProgramUniform1iv) numFailed++;
	_ptrc_glProgramUniform1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1ui");
	if(!_ptrc_glProgramUniform1ui) numFailed++;
	_ptrc_glProgramUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uiv");
	if(!_ptrc_glProgramUniform1uiv) numFailed++;
	_ptrc_glProgramUniform2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2d");
	if(!_ptrc_glProgramUniform2d) numFailed++;
	_ptrc_glProgramUniform2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dv");
	if(!_ptrc_glProgramUniform2dv) numFailed++;
	_ptrc_glProgramUniform2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2f");
	if(!_ptrc_glProgramUniform2f) numFailed++;
	_ptrc_glProgramUniform2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fv");
	if(!_ptrc_glProgramUniform2fv) numFailed++;
	_ptrc_glProgramUniform2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2i");
	if(!_ptrc_glProgramUniform2i) numFailed++;
	_ptrc_glProgramUniform2iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2iv");
	if(!_ptrc_glProgramUniform2iv) numFailed++;
	_ptrc_glProgramUniform2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2ui");
	if(!_ptrc_glProgramUniform2ui) numFailed++;
	_ptrc_glProgramUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uiv");
	if(!_ptrc_glProgramUniform2uiv) numFailed++;
	_ptrc_glProgramUniform3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3d");
	if(!_ptrc_glProgramUniform3d) numFailed++;
	_ptrc_glProgramUniform3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dv");
	if(!_ptrc_glProgramUniform3dv) numFailed++;
	_ptrc_glProgramUniform3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3f");
	if(!_ptrc_glProgramUniform3f) numFailed++;
	_ptrc_glProgramUniform3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fv");
	if(!_ptrc_glProgramUniform3fv) numFailed++;
	_ptrc_glProgramUniform3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3i");
	if(!_ptrc_glProgramUniform3i) numFailed++;
	_ptrc_glProgramUniform3iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3iv");
	if(!_ptrc_glProgramUniform3iv) numFailed++;
	_ptrc_glProgramUniform3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3ui");
	if(!_ptrc_glProgramUniform3ui) numFailed++;
	_ptrc_glProgramUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uiv");
	if(!_ptrc_glProgramUniform3uiv) numFailed++;
	_ptrc_glProgramUniform4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4d");
	if(!_ptrc_glProgramUniform4d) numFailed++;
	_ptrc_glProgramUniform4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dv");
	if(!_ptrc_glProgramUniform4dv) numFailed++;
	_ptrc_glProgramUniform4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4f");
	if(!_ptrc_glProgramUniform4f) numFailed++;
	_ptrc_glProgramUniform4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fv");
	if(!_ptrc_glProgramUniform4fv) numFailed++;
	_ptrc_glProgramUniform4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4i");
	if(!_ptrc_glProgramUniform4i) numFailed++;
	_ptrc_glProgramUniform4iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4iv");
	if(!_ptrc_glProgramUniform4iv) numFailed++;
	_ptrc_glProgramUniform4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4ui");
	if(!_ptrc_glProgramUniform4ui) numFailed++;
	_ptrc_glProgramUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uiv");
	if(!_ptrc_glProgramUniform4uiv) numFailed++;
	_ptrc_glProgramUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dv");
	if(!_ptrc_glProgramUniformMatrix2dv) numFailed++;
	_ptrc_glProgramUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fv");
	if(!_ptrc_glProgramUniformMatrix2fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!_ptrc_glProgramUniformMatrix2x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!_ptrc_glProgramUniformMatrix2x3fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!_ptrc_glProgramUniformMatrix2x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!_ptrc_glProgramUniformMatrix2x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dv");
	if(!_ptrc_glProgramUniformMatrix3dv) numFailed++;
	_ptrc_glProgramUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fv");
	if(!_ptrc_glProgramUniformMatrix3fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!_ptrc_glProgramUniformMatrix3x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!_ptrc_glProgramUniformMatrix3x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!_ptrc_glProgramUniformMatrix3x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!_ptrc_glProgramUniformMatrix3x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dv");
	if(!_ptrc_glProgramUniformMatrix4dv) numFailed++;
	_ptrc_glProgramUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fv");
	if(!_ptrc_glProgramUniformMatrix4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!_ptrc_glProgramUniformMatrix4x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!_ptrc_glProgramUniformMatrix4x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!_ptrc_glProgramUniformMatrix4x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!_ptrc_glProgramUniformMatrix4x3fv) numFailed++;
	_ptrc_glUseProgramStages = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield, GLuint))IntGetProcAddress("glUseProgramStages");
	if(!_ptrc_glUseProgramStages) numFailed++;
	_ptrc_glValidateProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgramPipeline");
	if(!_ptrc_glValidateProgramPipeline) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params) = NULL;

static int Load_ARB_shader_atomic_counters(void)
{
	int numFailed = 0;
	_ptrc_glGetActiveAtomicCounterBufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!_ptrc_glGetActiveAtomicCounterBufferiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield barriers) = NULL;

static int Load_ARB_shader_image_load_store(void)
{
	int numFailed = 0;
	_ptrc_glBindImageTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum))IntGetProcAddress("glBindImageTexture");
	if(!_ptrc_glBindImageTexture) numFailed++;
	_ptrc_glMemoryBarrier = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrier");
	if(!_ptrc_glMemoryBarrier) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAttachObjectARB)(GLhandleARB containerObj, GLhandleARB obj) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderARB)(GLhandleARB shaderObj) = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateProgramObjectARB)(void) = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateShaderObjectARB)(GLenum shaderType) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteObjectARB)(GLhandleARB obj) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDetachObjectARB)(GLhandleARB containerObj, GLhandleARB attachedObj) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedObjectsARB)(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj) = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glGetHandleARB)(GLenum pname) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInfoLogARB)(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterfvARB)(GLhandleARB obj, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivARB)(GLhandleARB obj, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSourceARB)(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocationARB)(GLhandleARB programObj, const GLcharARB * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfvARB)(GLhandleARB programObj, GLint location, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformivARB)(GLhandleARB programObj, GLint location, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLinkProgramARB)(GLhandleARB programObj) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderSourceARB)(GLhandleARB shaderObj, GLsizei count, const GLcharARB ** string, const GLint * length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fARB)(GLint location, GLfloat v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fvARB)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1iARB)(GLint location, GLint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ivARB)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fARB)(GLint location, GLfloat v0, GLfloat v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fvARB)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2iARB)(GLint location, GLint v0, GLint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ivARB)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fvARB)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3iARB)(GLint location, GLint v0, GLint v1, GLint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ivARB)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fvARB)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4iARB)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ivARB)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgramObjectARB)(GLhandleARB programObj) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramARB)(GLhandleARB programObj) = NULL;

static int Load_ARB_shader_objects(void)
{
	int numFailed = 0;
	_ptrc_glAttachObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLhandleARB))IntGetProcAddress("glAttachObjectARB");
	if(!_ptrc_glAttachObjectARB) numFailed++;
	_ptrc_glCompileShaderARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glCompileShaderARB");
	if(!_ptrc_glCompileShaderARB) numFailed++;
	_ptrc_glCreateProgramObjectARB = (GLhandleARB (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glCreateProgramObjectARB");
	if(!_ptrc_glCreateProgramObjectARB) numFailed++;
	_ptrc_glCreateShaderObjectARB = (GLhandleARB (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCreateShaderObjectARB");
	if(!_ptrc_glCreateShaderObjectARB) numFailed++;
	_ptrc_glDeleteObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glDeleteObjectARB");
	if(!_ptrc_glDeleteObjectARB) numFailed++;
	_ptrc_glDetachObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLhandleARB))IntGetProcAddress("glDetachObjectARB");
	if(!_ptrc_glDetachObjectARB) numFailed++;
	_ptrc_glGetActiveUniformARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *))IntGetProcAddress("glGetActiveUniformARB");
	if(!_ptrc_glGetActiveUniformARB) numFailed++;
	_ptrc_glGetAttachedObjectsARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *))IntGetProcAddress("glGetAttachedObjectsARB");
	if(!_ptrc_glGetAttachedObjectsARB) numFailed++;
	_ptrc_glGetHandleARB = (GLhandleARB (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGetHandleARB");
	if(!_ptrc_glGetHandleARB) numFailed++;
	_ptrc_glGetInfoLogARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *))IntGetProcAddress("glGetInfoLogARB");
	if(!_ptrc_glGetInfoLogARB) numFailed++;
	_ptrc_glGetObjectParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLenum, GLfloat *))IntGetProcAddress("glGetObjectParameterfvARB");
	if(!_ptrc_glGetObjectParameterfvARB) numFailed++;
	_ptrc_glGetObjectParameterivARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLenum, GLint *))IntGetProcAddress("glGetObjectParameterivARB");
	if(!_ptrc_glGetObjectParameterivARB) numFailed++;
	_ptrc_glGetShaderSourceARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *))IntGetProcAddress("glGetShaderSourceARB");
	if(!_ptrc_glGetShaderSourceARB) numFailed++;
	_ptrc_glGetUniformLocationARB = (GLint (CODEGEN_FUNCPTR *)(GLhandleARB, const GLcharARB *))IntGetProcAddress("glGetUniformLocationARB");
	if(!_ptrc_glGetUniformLocationARB) numFailed++;
	_ptrc_glGetUniformfvARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLint, GLfloat *))IntGetProcAddress("glGetUniformfvARB");
	if(!_ptrc_glGetUniformfvARB) numFailed++;
	_ptrc_glGetUniformivARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLint, GLint *))IntGetProcAddress("glGetUniformivARB");
	if(!_ptrc_glGetUniformivARB) numFailed++;
	_ptrc_glLinkProgramARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glLinkProgramARB");
	if(!_ptrc_glLinkProgramARB) numFailed++;
	_ptrc_glShaderSourceARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *))IntGetProcAddress("glShaderSourceARB");
	if(!_ptrc_glShaderSourceARB) numFailed++;
	_ptrc_glUniform1fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat))IntGetProcAddress("glUniform1fARB");
	if(!_ptrc_glUniform1fARB) numFailed++;
	_ptrc_glUniform1fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform1fvARB");
	if(!_ptrc_glUniform1fvARB) numFailed++;
	_ptrc_glUniform1iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glUniform1iARB");
	if(!_ptrc_glUniform1iARB) numFailed++;
	_ptrc_glUniform1ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform1ivARB");
	if(!_ptrc_glUniform1ivARB) numFailed++;
	_ptrc_glUniform2fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat))IntGetProcAddress("glUniform2fARB");
	if(!_ptrc_glUniform2fARB) numFailed++;
	_ptrc_glUniform2fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform2fvARB");
	if(!_ptrc_glUniform2fvARB) numFailed++;
	_ptrc_glUniform2iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glUniform2iARB");
	if(!_ptrc_glUniform2iARB) numFailed++;
	_ptrc_glUniform2ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform2ivARB");
	if(!_ptrc_glUniform2ivARB) numFailed++;
	_ptrc_glUniform3fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform3fARB");
	if(!_ptrc_glUniform3fARB) numFailed++;
	_ptrc_glUniform3fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform3fvARB");
	if(!_ptrc_glUniform3fvARB) numFailed++;
	_ptrc_glUniform3iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform3iARB");
	if(!_ptrc_glUniform3iARB) numFailed++;
	_ptrc_glUniform3ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform3ivARB");
	if(!_ptrc_glUniform3ivARB) numFailed++;
	_ptrc_glUniform4fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform4fARB");
	if(!_ptrc_glUniform4fARB) numFailed++;
	_ptrc_glUniform4fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform4fvARB");
	if(!_ptrc_glUniform4fvARB) numFailed++;
	_ptrc_glUniform4iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform4iARB");
	if(!_ptrc_glUniform4iARB) numFailed++;
	_ptrc_glUniform4ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform4ivARB");
	if(!_ptrc_glUniform4ivARB) numFailed++;
	_ptrc_glUniformMatrix2fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2fvARB");
	if(!_ptrc_glUniformMatrix2fvARB) numFailed++;
	_ptrc_glUniformMatrix3fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3fvARB");
	if(!_ptrc_glUniformMatrix3fvARB) numFailed++;
	_ptrc_glUniformMatrix4fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4fvARB");
	if(!_ptrc_glUniformMatrix4fvARB) numFailed++;
	_ptrc_glUseProgramObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glUseProgramObjectARB");
	if(!_ptrc_glUseProgramObjectARB) numFailed++;
	_ptrc_glValidateProgramARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glValidateProgramARB");
	if(!_ptrc_glValidateProgramARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) = NULL;

static int Load_ARB_shader_storage_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glShaderStorageBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glShaderStorageBlockBinding");
	if(!_ptrc_glShaderStorageBlockBinding) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices) = NULL;

static int Load_ARB_shader_subroutine(void)
{
	int numFailed = 0;
	_ptrc_glGetActiveSubroutineName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineName");
	if(!_ptrc_glGetActiveSubroutineName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!_ptrc_glGetActiveSubroutineUniformName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!_ptrc_glGetActiveSubroutineUniformiv) numFailed++;
	_ptrc_glGetProgramStageiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramStageiv");
	if(!_ptrc_glGetProgramStageiv) numFailed++;
	_ptrc_glGetSubroutineIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineIndex");
	if(!_ptrc_glGetSubroutineIndex) numFailed++;
	_ptrc_glGetSubroutineUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineUniformLocation");
	if(!_ptrc_glGetSubroutineUniformLocation) numFailed++;
	_ptrc_glGetUniformSubroutineuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint *))IntGetProcAddress("glGetUniformSubroutineuiv");
	if(!_ptrc_glGetUniformSubroutineuiv) numFailed++;
	_ptrc_glUniformSubroutinesuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glUniformSubroutinesuiv");
	if(!_ptrc_glUniformSubroutinesuiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const* path, const GLint * length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamedStringARB)(GLint namelen, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringARB)(GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringivARB)(GLint namelen, const GLchar * name, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedStringARB)(GLint namelen, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedStringARB)(GLenum type, GLint namelen, const GLchar * name, GLint stringlen, const GLchar * string) = NULL;

static int Load_ARB_shading_language_include(void)
{
	int numFailed = 0;
	_ptrc_glCompileShaderIncludeARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, const GLint *))IntGetProcAddress("glCompileShaderIncludeARB");
	if(!_ptrc_glCompileShaderIncludeARB) numFailed++;
	_ptrc_glDeleteNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *))IntGetProcAddress("glDeleteNamedStringARB");
	if(!_ptrc_glDeleteNamedStringARB) numFailed++;
	_ptrc_glGetNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *, GLsizei, GLint *, GLchar *))IntGetProcAddress("glGetNamedStringARB");
	if(!_ptrc_glGetNamedStringARB) numFailed++;
	_ptrc_glGetNamedStringivARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *, GLenum, GLint *))IntGetProcAddress("glGetNamedStringivARB");
	if(!_ptrc_glGetNamedStringivARB) numFailed++;
	_ptrc_glIsNamedStringARB = (GLboolean (CODEGEN_FUNCPTR *)(GLint, const GLchar *))IntGetProcAddress("glIsNamedStringARB");
	if(!_ptrc_glIsNamedStringARB) numFailed++;
	_ptrc_glNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLchar *, GLint, const GLchar *))IntGetProcAddress("glNamedStringARB");
	if(!_ptrc_glNamedStringARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) = NULL;

static int Load_ARB_sparse_buffer(void)
{
	int numFailed = 0;
	_ptrc_glBufferPageCommitmentARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLboolean))IntGetProcAddress("glBufferPageCommitmentARB");
	if(!_ptrc_glBufferPageCommitmentARB) numFailed++;
	_ptrc_glNamedBufferPageCommitmentARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLboolean))IntGetProcAddress("glNamedBufferPageCommitmentARB");
	if(!_ptrc_glNamedBufferPageCommitmentARB) numFailed++;
	_ptrc_glNamedBufferPageCommitmentEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLboolean))IntGetProcAddress("glNamedBufferPageCommitmentEXT");
	if(!_ptrc_glNamedBufferPageCommitmentEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) = NULL;

static int Load_ARB_sparse_texture(void)
{
	int numFailed = 0;
	_ptrc_glTexPageCommitmentARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexPageCommitmentARB");
	if(!_ptrc_glTexPageCommitmentARB) numFailed++;
	return numFailed;
}

GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync sync) = NULL;
GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum condition, GLbitfield flags) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum pname, GLint64 * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync sync) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;

static int Load_ARB_sync(void)
{
	int numFailed = 0;
	_ptrc_glClientWaitSync = (GLenum (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glClientWaitSync");
	if(!_ptrc_glClientWaitSync) numFailed++;
	_ptrc_glDeleteSync = (void (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glDeleteSync");
	if(!_ptrc_glDeleteSync) numFailed++;
	_ptrc_glFenceSync = (GLsync (CODEGEN_FUNCPTR *)(GLenum, GLbitfield))IntGetProcAddress("glFenceSync");
	if(!_ptrc_glFenceSync) numFailed++;
	_ptrc_glGetInteger64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLint64 *))IntGetProcAddress("glGetInteger64v");
	if(!_ptrc_glGetInteger64v) numFailed++;
	_ptrc_glGetSynciv = (void (CODEGEN_FUNCPTR *)(GLsync, GLenum, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetSynciv");
	if(!_ptrc_glGetSynciv) numFailed++;
	_ptrc_glIsSync = (GLboolean (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glIsSync");
	if(!_ptrc_glIsSync) numFailed++;
	_ptrc_glWaitSync = (void (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glWaitSync");
	if(!_ptrc_glWaitSync) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum pname, const GLfloat * values) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum pname, GLint value) = NULL;

static int Load_ARB_tessellation_shader(void)
{
	int numFailed = 0;
	_ptrc_glPatchParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPatchParameterfv");
	if(!_ptrc_glPatchParameterfv) numFailed++;
	_ptrc_glPatchParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPatchParameteri");
	if(!_ptrc_glPatchParameteri) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrier)(void) = NULL;

static int Load_ARB_texture_barrier(void)
{
	int numFailed = 0;
	_ptrc_glTextureBarrier = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glTextureBarrier");
	if(!_ptrc_glTextureBarrier) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferARB)(GLenum target, GLenum internalformat, GLuint buffer) = NULL;

static int Load_ARB_texture_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glTexBufferARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBufferARB");
	if(!_ptrc_glTexBufferARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;

static int Load_ARB_texture_buffer_range(void)
{
	int numFailed = 0;
	_ptrc_glTexBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTexBufferRange");
	if(!_ptrc_glTexBufferRange) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1DARB)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImageARB)(GLenum target, GLint level, void * img) = NULL;

static int Load_ARB_texture_compression(void)
{
	int numFailed = 0;
	_ptrc_glCompressedTexImage1DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage1DARB");
	if(!_ptrc_glCompressedTexImage1DARB) numFailed++;
	_ptrc_glCompressedTexImage2DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage2DARB");
	if(!_ptrc_glCompressedTexImage2DARB) numFailed++;
	_ptrc_glCompressedTexImage3DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage3DARB");
	if(!_ptrc_glCompressedTexImage3DARB) numFailed++;
	_ptrc_glCompressedTexSubImage1DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage1DARB");
	if(!_ptrc_glCompressedTexSubImage1DARB) numFailed++;
	_ptrc_glCompressedTexSubImage2DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage2DARB");
	if(!_ptrc_glCompressedTexSubImage2DARB) numFailed++;
	_ptrc_glCompressedTexSubImage3DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage3DARB");
	if(!_ptrc_glCompressedTexSubImage3DARB) numFailed++;
	_ptrc_glGetCompressedTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, void *))IntGetProcAddress("glGetCompressedTexImageARB");
	if(!_ptrc_glGetCompressedTexImageARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint maskNumber, GLbitfield mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;

static int Load_ARB_texture_multisample(void)
{
	int numFailed = 0;
	_ptrc_glGetMultisamplefv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefv");
	if(!_ptrc_glGetMultisamplefv) numFailed++;
	_ptrc_glSampleMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaski");
	if(!_ptrc_glSampleMaski) numFailed++;
	_ptrc_glTexImage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisample");
	if(!_ptrc_glTexImage2DMultisample) numFailed++;
	_ptrc_glTexImage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisample");
	if(!_ptrc_glTexImage3DMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) = NULL;

static int Load_ARB_texture_storage(void)
{
	int numFailed = 0;
	_ptrc_glTexStorage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTexStorage1D");
	if(!_ptrc_glTexStorage1D) numFailed++;
	_ptrc_glTexStorage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTexStorage2D");
	if(!_ptrc_glTexStorage2D) numFailed++;
	_ptrc_glTexStorage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTexStorage3D");
	if(!_ptrc_glTexStorage3D) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;

static int Load_ARB_texture_storage_multisample(void)
{
	int numFailed = 0;
	_ptrc_glTexStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage2DMultisample");
	if(!_ptrc_glTexStorage2DMultisample) numFailed++;
	_ptrc_glTexStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage3DMultisample");
	if(!_ptrc_glTexStorage3DMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) = NULL;

static int Load_ARB_texture_view(void)
{
	int numFailed = 0;
	_ptrc_glTextureView = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glTextureView");
	if(!_ptrc_glTextureView) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint id, GLenum target) = NULL;

static int Load_ARB_timer_query(void)
{
	int numFailed = 0;
	_ptrc_glGetQueryObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64v");
	if(!_ptrc_glGetQueryObjecti64v) numFailed++;
	_ptrc_glGetQueryObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64v");
	if(!_ptrc_glGetQueryObjectui64v) numFailed++;
	_ptrc_glQueryCounter = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glQueryCounter");
	if(!_ptrc_glQueryCounter) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum target, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei n, const GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum mode, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei n, GLuint * ids) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)(void) = NULL;

static int Load_ARB_transform_feedback2(void)
{
	int numFailed = 0;
	_ptrc_glBindTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedback");
	if(!_ptrc_glBindTransformFeedback) numFailed++;
	_ptrc_glDeleteTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacks");
	if(!_ptrc_glDeleteTransformFeedbacks) numFailed++;
	_ptrc_glDrawTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedback");
	if(!_ptrc_glDrawTransformFeedback) numFailed++;
	_ptrc_glGenTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacks");
	if(!_ptrc_glGenTransformFeedbacks) numFailed++;
	_ptrc_glIsTransformFeedback = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedback");
	if(!_ptrc_glIsTransformFeedback) numFailed++;
	_ptrc_glPauseTransformFeedback = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPauseTransformFeedback");
	if(!_ptrc_glPauseTransformFeedback) numFailed++;
	_ptrc_glResumeTransformFeedback = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glResumeTransformFeedback");
	if(!_ptrc_glResumeTransformFeedback) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params) = NULL;

static int Load_ARB_transform_feedback3(void)
{
	int numFailed = 0;
	_ptrc_glBeginQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBeginQueryIndexed");
	if(!_ptrc_glBeginQueryIndexed) numFailed++;
	_ptrc_glDrawTransformFeedbackStream = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glDrawTransformFeedbackStream");
	if(!_ptrc_glDrawTransformFeedbackStream) numFailed++;
	_ptrc_glEndQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEndQueryIndexed");
	if(!_ptrc_glEndQueryIndexed) numFailed++;
	_ptrc_glGetQueryIndexediv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryIndexediv");
	if(!_ptrc_glGetQueryIndexediv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) = NULL;

static int Load_ARB_transform_feedback_instanced(void)
{
	int numFailed = 0;
	_ptrc_glDrawTransformFeedbackInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!_ptrc_glDrawTransformFeedbackInstanced) numFailed++;
	_ptrc_glDrawTransformFeedbackStreamInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!_ptrc_glDrawTransformFeedbackStreamInstanced) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixdARB)(const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixfARB)(const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixdARB)(const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixfARB)(const GLfloat * m) = NULL;

static int Load_ARB_transpose_matrix(void)
{
	int numFailed = 0;
	_ptrc_glLoadTransposeMatrixdARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glLoadTransposeMatrixdARB");
	if(!_ptrc_glLoadTransposeMatrixdARB) numFailed++;
	_ptrc_glLoadTransposeMatrixfARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glLoadTransposeMatrixfARB");
	if(!_ptrc_glLoadTransposeMatrixfARB) numFailed++;
	_ptrc_glMultTransposeMatrixdARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glMultTransposeMatrixdARB");
	if(!_ptrc_glMultTransposeMatrixdARB) numFailed++;
	_ptrc_glMultTransposeMatrixfARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glMultTransposeMatrixfARB");
	if(!_ptrc_glMultTransposeMatrixfARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegeri_v)(GLenum target, GLuint index, GLint * data) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = NULL;

static int Load_ARB_uniform_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glBindBufferBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBase");
	if(!_ptrc_glBindBufferBase) numFailed++;
	_ptrc_glBindBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRange");
	if(!_ptrc_glBindBufferRange) numFailed++;
	_ptrc_glGetActiveUniformBlockName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformBlockName");
	if(!_ptrc_glGetActiveUniformBlockName) numFailed++;
	_ptrc_glGetActiveUniformBlockiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformBlockiv");
	if(!_ptrc_glGetActiveUniformBlockiv) numFailed++;
	_ptrc_glGetActiveUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformName");
	if(!_ptrc_glGetActiveUniformName) numFailed++;
	_ptrc_glGetActiveUniformsiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformsiv");
	if(!_ptrc_glGetActiveUniformsiv) numFailed++;
	_ptrc_glGetIntegeri_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegeri_v");
	if(!_ptrc_glGetIntegeri_v) numFailed++;
	_ptrc_glGetUniformBlockIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformBlockIndex");
	if(!_ptrc_glGetUniformBlockIndex) numFailed++;
	_ptrc_glGetUniformIndices = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLuint *))IntGetProcAddress("glGetUniformIndices");
	if(!_ptrc_glGetUniformIndices) numFailed++;
	_ptrc_glUniformBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glUniformBlockBinding");
	if(!_ptrc_glUniformBlockBinding) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint ren_array) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei n, const GLuint * arrays) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei n, GLuint * arrays) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint ren_array) = NULL;

static int Load_ARB_vertex_array_object(void)
{
	int numFailed = 0;
	_ptrc_glBindVertexArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexArray");
	if(!_ptrc_glBindVertexArray) numFailed++;
	_ptrc_glDeleteVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteVertexArrays");
	if(!_ptrc_glDeleteVertexArrays) numFailed++;
	_ptrc_glGenVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenVertexArrays");
	if(!_ptrc_glGenVertexArrays) numFailed++;
	_ptrc_glIsVertexArray = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsVertexArray");
	if(!_ptrc_glIsVertexArray) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint index, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;

static int Load_ARB_vertex_attrib_64bit(void)
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdv");
	if(!_ptrc_glGetVertexAttribLdv) numFailed++;
	_ptrc_glVertexAttribL1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1d");
	if(!_ptrc_glVertexAttribL1d) numFailed++;
	_ptrc_glVertexAttribL1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dv");
	if(!_ptrc_glVertexAttribL1dv) numFailed++;
	_ptrc_glVertexAttribL2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2d");
	if(!_ptrc_glVertexAttribL2d) numFailed++;
	_ptrc_glVertexAttribL2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dv");
	if(!_ptrc_glVertexAttribL2dv) numFailed++;
	_ptrc_glVertexAttribL3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3d");
	if(!_ptrc_glVertexAttribL3d) numFailed++;
	_ptrc_glVertexAttribL3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dv");
	if(!_ptrc_glVertexAttribL3dv) numFailed++;
	_ptrc_glVertexAttribL4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4d");
	if(!_ptrc_glVertexAttribL4d) numFailed++;
	_ptrc_glVertexAttribL4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dv");
	if(!_ptrc_glVertexAttribL4dv) numFailed++;
	_ptrc_glVertexAttribLPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glVertexAttribLPointer");
	if(!_ptrc_glVertexAttribLPointer) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor) = NULL;

static int Load_ARB_vertex_attrib_binding(void)
{
	int numFailed = 0;
	_ptrc_glBindVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glBindVertexBuffer");
	if(!_ptrc_glBindVertexBuffer) numFailed++;
	_ptrc_glVertexAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribBinding");
	if(!_ptrc_glVertexAttribBinding) numFailed++;
	_ptrc_glVertexAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribFormat");
	if(!_ptrc_glVertexAttribFormat) numFailed++;
	_ptrc_glVertexAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribIFormat");
	if(!_ptrc_glVertexAttribIFormat) numFailed++;
	_ptrc_glVertexAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribLFormat");
	if(!_ptrc_glVertexAttribLFormat) numFailed++;
	_ptrc_glVertexBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexBindingDivisor");
	if(!_ptrc_glVertexBindingDivisor) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindBufferARB)(GLenum target, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferDataARB)(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffersARB)(GLsizei n, const GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenBuffersARB)(GLsizei n, GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterivARB)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointervARB)(GLenum target, GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferARB)(GLuint buffer) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferARB)(GLenum target, GLenum access) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBufferARB)(GLenum target) = NULL;

static int Load_ARB_vertex_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glBindBufferARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindBufferARB");
	if(!_ptrc_glBindBufferARB) numFailed++;
	_ptrc_glBufferDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptrARB, const void *, GLenum))IntGetProcAddress("glBufferDataARB");
	if(!_ptrc_glBufferDataARB) numFailed++;
	_ptrc_glBufferSubDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptrARB, GLsizeiptrARB, const void *))IntGetProcAddress("glBufferSubDataARB");
	if(!_ptrc_glBufferSubDataARB) numFailed++;
	_ptrc_glDeleteBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteBuffersARB");
	if(!_ptrc_glDeleteBuffersARB) numFailed++;
	_ptrc_glGenBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenBuffersARB");
	if(!_ptrc_glGenBuffersARB) numFailed++;
	_ptrc_glGetBufferParameterivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetBufferParameterivARB");
	if(!_ptrc_glGetBufferParameterivARB) numFailed++;
	_ptrc_glGetBufferPointervARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, void **))IntGetProcAddress("glGetBufferPointervARB");
	if(!_ptrc_glGetBufferPointervARB) numFailed++;
	_ptrc_glGetBufferSubDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptrARB, GLsizeiptrARB, void *))IntGetProcAddress("glGetBufferSubDataARB");
	if(!_ptrc_glGetBufferSubDataARB) numFailed++;
	_ptrc_glIsBufferARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsBufferARB");
	if(!_ptrc_glIsBufferARB) numFailed++;
	_ptrc_glMapBufferARB = (void * (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMapBufferARB");
	if(!_ptrc_glMapBufferARB) numFailed++;
	_ptrc_glUnmapBufferARB = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glUnmapBufferARB");
	if(!_ptrc_glUnmapBufferARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArrayARB)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArrayARB)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervARB)(GLuint index, GLenum pname, void ** pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvARB)(GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvARB)(GLuint index, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivARB)(GLuint index, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dARB)(GLuint index, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvARB)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fARB)(GLuint index, GLfloat x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvARB)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sARB)(GLuint index, GLshort x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svARB)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dARB)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvARB)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fARB)(GLuint index, GLfloat x, GLfloat y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvARB)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sARB)(GLuint index, GLshort x, GLshort y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svARB)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvARB)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvARB)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sARB)(GLuint index, GLshort x, GLshort y, GLshort z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svARB)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NbvARB)(GLuint index, const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NivARB)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NsvARB)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubARB)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubvARB)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NuivARB)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NusvARB)(GLuint index, const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bvARB)(GLuint index, const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvARB)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvARB)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ivARB)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sARB)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svARB)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvARB)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uivARB)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usvARB)(GLuint index, const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerARB)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) = NULL;

static int Load_ARB_vertex_program(void)
{
	int numFailed = 0;
	_ptrc_glBindProgramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramARB");
	if(!_ptrc_glBindProgramARB) numFailed++;
	_ptrc_glDeleteProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsARB");
	if(!_ptrc_glDeleteProgramsARB) numFailed++;
	_ptrc_glDisableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVertexAttribArrayARB");
	if(!_ptrc_glDisableVertexAttribArrayARB) numFailed++;
	_ptrc_glEnableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVertexAttribArrayARB");
	if(!_ptrc_glEnableVertexAttribArrayARB) numFailed++;
	_ptrc_glGenProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsARB");
	if(!_ptrc_glGenProgramsARB) numFailed++;
	_ptrc_glGetProgramEnvParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramEnvParameterdvARB");
	if(!_ptrc_glGetProgramEnvParameterdvARB) numFailed++;
	_ptrc_glGetProgramEnvParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramEnvParameterfvARB");
	if(!_ptrc_glGetProgramEnvParameterfvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramLocalParameterdvARB");
	if(!_ptrc_glGetProgramLocalParameterdvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramLocalParameterfvARB");
	if(!_ptrc_glGetProgramLocalParameterfvARB) numFailed++;
	_ptrc_glGetProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, void *))IntGetProcAddress("glGetProgramStringARB");
	if(!_ptrc_glGetProgramStringARB) numFailed++;
	_ptrc_glGetProgramivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramivARB");
	if(!_ptrc_glGetProgramivARB) numFailed++;
	_ptrc_glGetVertexAttribPointervARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetVertexAttribPointervARB");
	if(!_ptrc_glGetVertexAttribPointervARB) numFailed++;
	_ptrc_glGetVertexAttribdvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdvARB");
	if(!_ptrc_glGetVertexAttribdvARB) numFailed++;
	_ptrc_glGetVertexAttribfvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfvARB");
	if(!_ptrc_glGetVertexAttribfvARB) numFailed++;
	_ptrc_glGetVertexAttribivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribivARB");
	if(!_ptrc_glGetVertexAttribivARB) numFailed++;
	_ptrc_glIsProgramARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramARB");
	if(!_ptrc_glIsProgramARB) numFailed++;
	_ptrc_glProgramEnvParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramEnvParameter4dARB");
	if(!_ptrc_glProgramEnvParameter4dARB) numFailed++;
	_ptrc_glProgramEnvParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramEnvParameter4dvARB");
	if(!_ptrc_glProgramEnvParameter4dvARB) numFailed++;
	_ptrc_glProgramEnvParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramEnvParameter4fARB");
	if(!_ptrc_glProgramEnvParameter4fARB) numFailed++;
	_ptrc_glProgramEnvParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramEnvParameter4fvARB");
	if(!_ptrc_glProgramEnvParameter4fvARB) numFailed++;
	_ptrc_glProgramLocalParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramLocalParameter4dARB");
	if(!_ptrc_glProgramLocalParameter4dARB) numFailed++;
	_ptrc_glProgramLocalParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramLocalParameter4dvARB");
	if(!_ptrc_glProgramLocalParameter4dvARB) numFailed++;
	_ptrc_glProgramLocalParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramLocalParameter4fARB");
	if(!_ptrc_glProgramLocalParameter4fARB) numFailed++;
	_ptrc_glProgramLocalParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramLocalParameter4fvARB");
	if(!_ptrc_glProgramLocalParameter4fvARB) numFailed++;
	_ptrc_glProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const void *))IntGetProcAddress("glProgramStringARB");
	if(!_ptrc_glProgramStringARB) numFailed++;
	_ptrc_glVertexAttrib1dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1dARB");
	if(!_ptrc_glVertexAttrib1dARB) numFailed++;
	_ptrc_glVertexAttrib1dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dvARB");
	if(!_ptrc_glVertexAttrib1dvARB) numFailed++;
	_ptrc_glVertexAttrib1fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1fARB");
	if(!_ptrc_glVertexAttrib1fARB) numFailed++;
	_ptrc_glVertexAttrib1fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fvARB");
	if(!_ptrc_glVertexAttrib1fvARB) numFailed++;
	_ptrc_glVertexAttrib1sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1sARB");
	if(!_ptrc_glVertexAttrib1sARB) numFailed++;
	_ptrc_glVertexAttrib1svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1svARB");
	if(!_ptrc_glVertexAttrib1svARB) numFailed++;
	_ptrc_glVertexAttrib2dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2dARB");
	if(!_ptrc_glVertexAttrib2dARB) numFailed++;
	_ptrc_glVertexAttrib2dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dvARB");
	if(!_ptrc_glVertexAttrib2dvARB) numFailed++;
	_ptrc_glVertexAttrib2fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2fARB");
	if(!_ptrc_glVertexAttrib2fARB) numFailed++;
	_ptrc_glVertexAttrib2fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fvARB");
	if(!_ptrc_glVertexAttrib2fvARB) numFailed++;
	_ptrc_glVertexAttrib2sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2sARB");
	if(!_ptrc_glVertexAttrib2sARB) numFailed++;
	_ptrc_glVertexAttrib2svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2svARB");
	if(!_ptrc_glVertexAttrib2svARB) numFailed++;
	_ptrc_glVertexAttrib3dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3dARB");
	if(!_ptrc_glVertexAttrib3dARB) numFailed++;
	_ptrc_glVertexAttrib3dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dvARB");
	if(!_ptrc_glVertexAttrib3dvARB) numFailed++;
	_ptrc_glVertexAttrib3fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3fARB");
	if(!_ptrc_glVertexAttrib3fARB) numFailed++;
	_ptrc_glVertexAttrib3fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fvARB");
	if(!_ptrc_glVertexAttrib3fvARB) numFailed++;
	_ptrc_glVertexAttrib3sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3sARB");
	if(!_ptrc_glVertexAttrib3sARB) numFailed++;
	_ptrc_glVertexAttrib3svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3svARB");
	if(!_ptrc_glVertexAttrib3svARB) numFailed++;
	_ptrc_glVertexAttrib4NbvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4NbvARB");
	if(!_ptrc_glVertexAttrib4NbvARB) numFailed++;
	_ptrc_glVertexAttrib4NivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4NivARB");
	if(!_ptrc_glVertexAttrib4NivARB) numFailed++;
	_ptrc_glVertexAttrib4NsvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4NsvARB");
	if(!_ptrc_glVertexAttrib4NsvARB) numFailed++;
	_ptrc_glVertexAttrib4NubARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4NubARB");
	if(!_ptrc_glVertexAttrib4NubARB) numFailed++;
	_ptrc_glVertexAttrib4NubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4NubvARB");
	if(!_ptrc_glVertexAttrib4NubvARB) numFailed++;
	_ptrc_glVertexAttrib4NuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4NuivARB");
	if(!_ptrc_glVertexAttrib4NuivARB) numFailed++;
	_ptrc_glVertexAttrib4NusvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4NusvARB");
	if(!_ptrc_glVertexAttrib4NusvARB) numFailed++;
	_ptrc_glVertexAttrib4bvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4bvARB");
	if(!_ptrc_glVertexAttrib4bvARB) numFailed++;
	_ptrc_glVertexAttrib4dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4dARB");
	if(!_ptrc_glVertexAttrib4dARB) numFailed++;
	_ptrc_glVertexAttrib4dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dvARB");
	if(!_ptrc_glVertexAttrib4dvARB) numFailed++;
	_ptrc_glVertexAttrib4fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4fARB");
	if(!_ptrc_glVertexAttrib4fARB) numFailed++;
	_ptrc_glVertexAttrib4fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fvARB");
	if(!_ptrc_glVertexAttrib4fvARB) numFailed++;
	_ptrc_glVertexAttrib4ivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4ivARB");
	if(!_ptrc_glVertexAttrib4ivARB) numFailed++;
	_ptrc_glVertexAttrib4sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4sARB");
	if(!_ptrc_glVertexAttrib4sARB) numFailed++;
	_ptrc_glVertexAttrib4svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4svARB");
	if(!_ptrc_glVertexAttrib4svARB) numFailed++;
	_ptrc_glVertexAttrib4ubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubvARB");
	if(!_ptrc_glVertexAttrib4ubvARB) numFailed++;
	_ptrc_glVertexAttrib4uivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4uivARB");
	if(!_ptrc_glVertexAttrib4uivARB) numFailed++;
	_ptrc_glVertexAttrib4usvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4usvARB");
	if(!_ptrc_glVertexAttrib4usvARB) numFailed++;
	_ptrc_glVertexAttribPointerARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *))IntGetProcAddress("glVertexAttribPointerARB");
	if(!_ptrc_glVertexAttribPointerARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocationARB)(GLhandleARB programObj, GLuint index, const GLcharARB * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttribARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocationARB)(GLhandleARB programObj, const GLcharARB * name) = NULL;

static int Load_ARB_vertex_shader(void)
{
	int numFailed = 0;
	_ptrc_glBindAttribLocationARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, const GLcharARB *))IntGetProcAddress("glBindAttribLocationARB");
	if(!_ptrc_glBindAttribLocationARB) numFailed++;
	_ptrc_glDisableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVertexAttribArrayARB");
	if(!_ptrc_glDisableVertexAttribArrayARB) numFailed++;
	_ptrc_glEnableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVertexAttribArrayARB");
	if(!_ptrc_glEnableVertexAttribArrayARB) numFailed++;
	_ptrc_glGetActiveAttribARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *))IntGetProcAddress("glGetActiveAttribARB");
	if(!_ptrc_glGetActiveAttribARB) numFailed++;
	_ptrc_glGetAttribLocationARB = (GLint (CODEGEN_FUNCPTR *)(GLhandleARB, const GLcharARB *))IntGetProcAddress("glGetAttribLocationARB");
	if(!_ptrc_glGetAttribLocationARB) numFailed++;
	_ptrc_glGetVertexAttribPointervARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetVertexAttribPointervARB");
	if(!_ptrc_glGetVertexAttribPointervARB) numFailed++;
	_ptrc_glGetVertexAttribdvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdvARB");
	if(!_ptrc_glGetVertexAttribdvARB) numFailed++;
	_ptrc_glGetVertexAttribfvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfvARB");
	if(!_ptrc_glGetVertexAttribfvARB) numFailed++;
	_ptrc_glGetVertexAttribivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribivARB");
	if(!_ptrc_glGetVertexAttribivARB) numFailed++;
	_ptrc_glVertexAttrib1dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1dARB");
	if(!_ptrc_glVertexAttrib1dARB) numFailed++;
	_ptrc_glVertexAttrib1dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dvARB");
	if(!_ptrc_glVertexAttrib1dvARB) numFailed++;
	_ptrc_glVertexAttrib1fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1fARB");
	if(!_ptrc_glVertexAttrib1fARB) numFailed++;
	_ptrc_glVertexAttrib1fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fvARB");
	if(!_ptrc_glVertexAttrib1fvARB) numFailed++;
	_ptrc_glVertexAttrib1sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1sARB");
	if(!_ptrc_glVertexAttrib1sARB) numFailed++;
	_ptrc_glVertexAttrib1svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1svARB");
	if(!_ptrc_glVertexAttrib1svARB) numFailed++;
	_ptrc_glVertexAttrib2dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2dARB");
	if(!_ptrc_glVertexAttrib2dARB) numFailed++;
	_ptrc_glVertexAttrib2dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dvARB");
	if(!_ptrc_glVertexAttrib2dvARB) numFailed++;
	_ptrc_glVertexAttrib2fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2fARB");
	if(!_ptrc_glVertexAttrib2fARB) numFailed++;
	_ptrc_glVertexAttrib2fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fvARB");
	if(!_ptrc_glVertexAttrib2fvARB) numFailed++;
	_ptrc_glVertexAttrib2sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2sARB");
	if(!_ptrc_glVertexAttrib2sARB) numFailed++;
	_ptrc_glVertexAttrib2svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2svARB");
	if(!_ptrc_glVertexAttrib2svARB) numFailed++;
	_ptrc_glVertexAttrib3dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3dARB");
	if(!_ptrc_glVertexAttrib3dARB) numFailed++;
	_ptrc_glVertexAttrib3dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dvARB");
	if(!_ptrc_glVertexAttrib3dvARB) numFailed++;
	_ptrc_glVertexAttrib3fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3fARB");
	if(!_ptrc_glVertexAttrib3fARB) numFailed++;
	_ptrc_glVertexAttrib3fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fvARB");
	if(!_ptrc_glVertexAttrib3fvARB) numFailed++;
	_ptrc_glVertexAttrib3sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3sARB");
	if(!_ptrc_glVertexAttrib3sARB) numFailed++;
	_ptrc_glVertexAttrib3svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3svARB");
	if(!_ptrc_glVertexAttrib3svARB) numFailed++;
	_ptrc_glVertexAttrib4NbvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4NbvARB");
	if(!_ptrc_glVertexAttrib4NbvARB) numFailed++;
	_ptrc_glVertexAttrib4NivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4NivARB");
	if(!_ptrc_glVertexAttrib4NivARB) numFailed++;
	_ptrc_glVertexAttrib4NsvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4NsvARB");
	if(!_ptrc_glVertexAttrib4NsvARB) numFailed++;
	_ptrc_glVertexAttrib4NubARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4NubARB");
	if(!_ptrc_glVertexAttrib4NubARB) numFailed++;
	_ptrc_glVertexAttrib4NubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4NubvARB");
	if(!_ptrc_glVertexAttrib4NubvARB) numFailed++;
	_ptrc_glVertexAttrib4NuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4NuivARB");
	if(!_ptrc_glVertexAttrib4NuivARB) numFailed++;
	_ptrc_glVertexAttrib4NusvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4NusvARB");
	if(!_ptrc_glVertexAttrib4NusvARB) numFailed++;
	_ptrc_glVertexAttrib4bvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4bvARB");
	if(!_ptrc_glVertexAttrib4bvARB) numFailed++;
	_ptrc_glVertexAttrib4dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4dARB");
	if(!_ptrc_glVertexAttrib4dARB) numFailed++;
	_ptrc_glVertexAttrib4dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dvARB");
	if(!_ptrc_glVertexAttrib4dvARB) numFailed++;
	_ptrc_glVertexAttrib4fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4fARB");
	if(!_ptrc_glVertexAttrib4fARB) numFailed++;
	_ptrc_glVertexAttrib4fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fvARB");
	if(!_ptrc_glVertexAttrib4fvARB) numFailed++;
	_ptrc_glVertexAttrib4ivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4ivARB");
	if(!_ptrc_glVertexAttrib4ivARB) numFailed++;
	_ptrc_glVertexAttrib4sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4sARB");
	if(!_ptrc_glVertexAttrib4sARB) numFailed++;
	_ptrc_glVertexAttrib4svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4svARB");
	if(!_ptrc_glVertexAttrib4svARB) numFailed++;
	_ptrc_glVertexAttrib4ubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubvARB");
	if(!_ptrc_glVertexAttrib4ubvARB) numFailed++;
	_ptrc_glVertexAttrib4uivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4uivARB");
	if(!_ptrc_glVertexAttrib4uivARB) numFailed++;
	_ptrc_glVertexAttrib4usvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4usvARB");
	if(!_ptrc_glVertexAttrib4usvARB) numFailed++;
	_ptrc_glVertexAttribPointerARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *))IntGetProcAddress("glVertexAttribPointerARB");
	if(!_ptrc_glVertexAttribPointerARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorP3ui)(GLenum type, GLuint color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP3uiv)(GLenum type, const GLuint * color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP4ui)(GLenum type, GLuint color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP4uiv)(GLenum type, const GLuint * color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalP3ui)(GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalP3uiv)(GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3ui)(GLenum type, GLuint color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3uiv)(GLenum type, const GLuint * color) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1ui)(GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1uiv)(GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2ui)(GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2uiv)(GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3ui)(GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3uiv)(GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4ui)(GLenum type, GLuint coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4uiv)(GLenum type, const GLuint * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP2ui)(GLenum type, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP2uiv)(GLenum type, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP3ui)(GLenum type, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP3uiv)(GLenum type, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP4ui)(GLenum type, GLuint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP4uiv)(GLenum type, const GLuint * value) = NULL;

static int Load_ARB_vertex_type_2_10_10_10_rev(void)
{
	int numFailed = 0;
	_ptrc_glColorP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glColorP3ui");
	if(!_ptrc_glColorP3ui) numFailed++;
	_ptrc_glColorP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glColorP3uiv");
	if(!_ptrc_glColorP3uiv) numFailed++;
	_ptrc_glColorP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glColorP4ui");
	if(!_ptrc_glColorP4ui) numFailed++;
	_ptrc_glColorP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glColorP4uiv");
	if(!_ptrc_glColorP4uiv) numFailed++;
	_ptrc_glMultiTexCoordP1ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP1ui");
	if(!_ptrc_glMultiTexCoordP1ui) numFailed++;
	_ptrc_glMultiTexCoordP1uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP1uiv");
	if(!_ptrc_glMultiTexCoordP1uiv) numFailed++;
	_ptrc_glMultiTexCoordP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP2ui");
	if(!_ptrc_glMultiTexCoordP2ui) numFailed++;
	_ptrc_glMultiTexCoordP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP2uiv");
	if(!_ptrc_glMultiTexCoordP2uiv) numFailed++;
	_ptrc_glMultiTexCoordP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP3ui");
	if(!_ptrc_glMultiTexCoordP3ui) numFailed++;
	_ptrc_glMultiTexCoordP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP3uiv");
	if(!_ptrc_glMultiTexCoordP3uiv) numFailed++;
	_ptrc_glMultiTexCoordP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP4ui");
	if(!_ptrc_glMultiTexCoordP4ui) numFailed++;
	_ptrc_glMultiTexCoordP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP4uiv");
	if(!_ptrc_glMultiTexCoordP4uiv) numFailed++;
	_ptrc_glNormalP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glNormalP3ui");
	if(!_ptrc_glNormalP3ui) numFailed++;
	_ptrc_glNormalP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glNormalP3uiv");
	if(!_ptrc_glNormalP3uiv) numFailed++;
	_ptrc_glSecondaryColorP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glSecondaryColorP3ui");
	if(!_ptrc_glSecondaryColorP3ui) numFailed++;
	_ptrc_glSecondaryColorP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glSecondaryColorP3uiv");
	if(!_ptrc_glSecondaryColorP3uiv) numFailed++;
	_ptrc_glTexCoordP1ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP1ui");
	if(!_ptrc_glTexCoordP1ui) numFailed++;
	_ptrc_glTexCoordP1uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP1uiv");
	if(!_ptrc_glTexCoordP1uiv) numFailed++;
	_ptrc_glTexCoordP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP2ui");
	if(!_ptrc_glTexCoordP2ui) numFailed++;
	_ptrc_glTexCoordP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP2uiv");
	if(!_ptrc_glTexCoordP2uiv) numFailed++;
	_ptrc_glTexCoordP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP3ui");
	if(!_ptrc_glTexCoordP3ui) numFailed++;
	_ptrc_glTexCoordP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP3uiv");
	if(!_ptrc_glTexCoordP3uiv) numFailed++;
	_ptrc_glTexCoordP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP4ui");
	if(!_ptrc_glTexCoordP4ui) numFailed++;
	_ptrc_glTexCoordP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP4uiv");
	if(!_ptrc_glTexCoordP4uiv) numFailed++;
	_ptrc_glVertexAttribP1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP1ui");
	if(!_ptrc_glVertexAttribP1ui) numFailed++;
	_ptrc_glVertexAttribP1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP1uiv");
	if(!_ptrc_glVertexAttribP1uiv) numFailed++;
	_ptrc_glVertexAttribP2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP2ui");
	if(!_ptrc_glVertexAttribP2ui) numFailed++;
	_ptrc_glVertexAttribP2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP2uiv");
	if(!_ptrc_glVertexAttribP2uiv) numFailed++;
	_ptrc_glVertexAttribP3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP3ui");
	if(!_ptrc_glVertexAttribP3ui) numFailed++;
	_ptrc_glVertexAttribP3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP3uiv");
	if(!_ptrc_glVertexAttribP3uiv) numFailed++;
	_ptrc_glVertexAttribP4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP4ui");
	if(!_ptrc_glVertexAttribP4ui) numFailed++;
	_ptrc_glVertexAttribP4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP4uiv");
	if(!_ptrc_glVertexAttribP4uiv) numFailed++;
	_ptrc_glVertexP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP2ui");
	if(!_ptrc_glVertexP2ui) numFailed++;
	_ptrc_glVertexP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP2uiv");
	if(!_ptrc_glVertexP2uiv) numFailed++;
	_ptrc_glVertexP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP3ui");
	if(!_ptrc_glVertexP3ui) numFailed++;
	_ptrc_glVertexP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP3uiv");
	if(!_ptrc_glVertexP3uiv) numFailed++;
	_ptrc_glVertexP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP4ui");
	if(!_ptrc_glVertexP4ui) numFailed++;
	_ptrc_glVertexP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP4uiv");
	if(!_ptrc_glVertexP4uiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum target, GLuint index, GLdouble * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum target, GLuint index, GLfloat * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint first, GLsizei count, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint index, const GLfloat * v) = NULL;

static int Load_ARB_viewport_array(void)
{
	int numFailed = 0;
	_ptrc_glDepthRangeArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glDepthRangeArrayv");
	if(!_ptrc_glDepthRangeArrayv) numFailed++;
	_ptrc_glDepthRangeIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glDepthRangeIndexed");
	if(!_ptrc_glDepthRangeIndexed) numFailed++;
	_ptrc_glGetDoublei_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_v");
	if(!_ptrc_glGetDoublei_v) numFailed++;
	_ptrc_glGetFloati_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_v");
	if(!_ptrc_glGetFloati_v) numFailed++;
	_ptrc_glScissorArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *))IntGetProcAddress("glScissorArrayv");
	if(!_ptrc_glScissorArrayv) numFailed++;
	_ptrc_glScissorIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissorIndexed");
	if(!_ptrc_glScissorIndexed) numFailed++;
	_ptrc_glScissorIndexedv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glScissorIndexedv");
	if(!_ptrc_glScissorIndexedv) numFailed++;
	_ptrc_glViewportArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glViewportArrayv");
	if(!_ptrc_glViewportArrayv) numFailed++;
	_ptrc_glViewportIndexedf = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glViewportIndexedf");
	if(!_ptrc_glViewportIndexedf) numFailed++;
	_ptrc_glViewportIndexedfv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glViewportIndexedfv");
	if(!_ptrc_glViewportIndexedfv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dARB)(GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvARB)(const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fARB)(GLfloat x, GLfloat y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvARB)(const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iARB)(GLint x, GLint y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivARB)(const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sARB)(GLshort x, GLshort y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svARB)(const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dARB)(GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvARB)(const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fARB)(GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvARB)(const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iARB)(GLint x, GLint y, GLint z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivARB)(const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sARB)(GLshort x, GLshort y, GLshort z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svARB)(const GLshort * v) = NULL;

static int Load_ARB_window_pos(void)
{
	int numFailed = 0;
	_ptrc_glWindowPos2dARB = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glWindowPos2dARB");
	if(!_ptrc_glWindowPos2dARB) numFailed++;
	_ptrc_glWindowPos2dvARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos2dvARB");
	if(!_ptrc_glWindowPos2dvARB) numFailed++;
	_ptrc_glWindowPos2fARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glWindowPos2fARB");
	if(!_ptrc_glWindowPos2fARB) numFailed++;
	_ptrc_glWindowPos2fvARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos2fvARB");
	if(!_ptrc_glWindowPos2fvARB) numFailed++;
	_ptrc_glWindowPos2iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glWindowPos2iARB");
	if(!_ptrc_glWindowPos2iARB) numFailed++;
	_ptrc_glWindowPos2ivARB = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos2ivARB");
	if(!_ptrc_glWindowPos2ivARB) numFailed++;
	_ptrc_glWindowPos2sARB = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glWindowPos2sARB");
	if(!_ptrc_glWindowPos2sARB) numFailed++;
	_ptrc_glWindowPos2svARB = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos2svARB");
	if(!_ptrc_glWindowPos2svARB) numFailed++;
	_ptrc_glWindowPos3dARB = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glWindowPos3dARB");
	if(!_ptrc_glWindowPos3dARB) numFailed++;
	_ptrc_glWindowPos3dvARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos3dvARB");
	if(!_ptrc_glWindowPos3dvARB) numFailed++;
	_ptrc_glWindowPos3fARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glWindowPos3fARB");
	if(!_ptrc_glWindowPos3fARB) numFailed++;
	_ptrc_glWindowPos3fvARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos3fvARB");
	if(!_ptrc_glWindowPos3fvARB) numFailed++;
	_ptrc_glWindowPos3iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glWindowPos3iARB");
	if(!_ptrc_glWindowPos3iARB) numFailed++;
	_ptrc_glWindowPos3ivARB = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos3ivARB");
	if(!_ptrc_glWindowPos3ivARB) numFailed++;
	_ptrc_glWindowPos3sARB = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glWindowPos3sARB");
	if(!_ptrc_glWindowPos3sARB) numFailed++;
	_ptrc_glWindowPos3svARB = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos3svARB");
	if(!_ptrc_glWindowPos3svARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersATI)(GLsizei n, const GLenum * bufs) = NULL;

static int Load_ATI_draw_buffers(void)
{
	int numFailed = 0;
	_ptrc_glDrawBuffersATI = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffersATI");
	if(!_ptrc_glDrawBuffersATI) numFailed++;
	return numFailed;
}

GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBufferSizeEXT)(GLuint program, GLint location) = NULL;
GLintptr (CODEGEN_FUNCPTR *_ptrc_glGetUniformOffsetEXT)(GLuint program, GLint location) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformBufferEXT)(GLuint program, GLint location, GLuint buffer) = NULL;

static int Load_EXT_bindable_uniform(void)
{
	int numFailed = 0;
	_ptrc_glGetUniformBufferSizeEXT = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glGetUniformBufferSizeEXT");
	if(!_ptrc_glGetUniformBufferSizeEXT) numFailed++;
	_ptrc_glGetUniformOffsetEXT = (GLintptr (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glGetUniformOffsetEXT");
	if(!_ptrc_glGetUniformOffsetEXT) numFailed++;
	_ptrc_glUniformBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glUniformBufferEXT");
	if(!_ptrc_glUniformBufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendColorEXT)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;

static int Load_EXT_blend_color(void)
{
	int numFailed = 0;
	_ptrc_glBlendColorEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBlendColorEXT");
	if(!_ptrc_glBlendColorEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateEXT)(GLenum modeRGB, GLenum modeAlpha) = NULL;

static int Load_EXT_blend_equation_separate(void)
{
	int numFailed = 0;
	_ptrc_glBlendEquationSeparateEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparateEXT");
	if(!_ptrc_glBlendEquationSeparateEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateEXT)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = NULL;

static int Load_EXT_blend_func_separate(void)
{
	int numFailed = 0;
	_ptrc_glBlendFuncSeparateEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateEXT");
	if(!_ptrc_glBlendFuncSeparateEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationEXT)(GLenum mode) = NULL;

static int Load_EXT_blend_minmax(void)
{
	int numFailed = 0;
	_ptrc_glBlendEquationEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBlendEquationEXT");
	if(!_ptrc_glBlendEquationEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glLockArraysEXT)(GLint first, GLsizei count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUnlockArraysEXT)(void) = NULL;

static int Load_EXT_compiled_vertex_array(void)
{
	int numFailed = 0;
	_ptrc_glLockArraysEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei))IntGetProcAddress("glLockArraysEXT");
	if(!_ptrc_glLockArraysEXT) numFailed++;
	_ptrc_glUnlockArraysEXT = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glUnlockArraysEXT");
	if(!_ptrc_glUnlockArraysEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsEXT)(GLclampd zmin, GLclampd zmax) = NULL;

static int Load_EXT_depth_bounds_test(void)
{
	int numFailed = 0;
	_ptrc_glDepthBoundsEXT = (void (CODEGEN_FUNCPTR *)(GLclampd, GLclampd))IntGetProcAddress("glDepthBoundsEXT");
	if(!_ptrc_glDepthBoundsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindMultiTextureEXT)(GLenum texunit, GLenum target, GLuint texture) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatusEXT)(GLuint framebuffer, GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferDataEXT)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubDataEXT)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClientAttribDefaultEXT)(GLbitfield mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateIndexedEXT)(GLenum ren_array, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateiEXT)(GLenum ren_array, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttribEXT)(GLuint vaobj, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayEXT)(GLuint vaobj, GLenum ren_array) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateIndexedEXT)(GLenum ren_array, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateiEXT)(GLenum ren_array, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttribEXT)(GLuint vaobj, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayEXT)(GLuint vaobj, GLenum ren_array) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBufferEXT)(GLuint framebuffer, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBuffersEXT)(GLuint framebuffer, GLsizei n, const GLenum * bufs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferReadBufferEXT)(GLuint framebuffer, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMultiTexMipmapEXT)(GLenum texunit, GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmapEXT)(GLuint texture, GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum target, GLuint index, GLboolean * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedMultiTexImageEXT)(GLenum texunit, GLenum target, GLint lod, void * img) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImageEXT)(GLuint texture, GLenum target, GLint lod, void * img) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoubleIndexedvEXT)(GLenum target, GLuint index, GLdouble * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_vEXT)(GLenum pname, GLuint index, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloatIndexedvEXT)(GLenum target, GLuint index, GLfloat * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_vEXT)(GLenum pname, GLuint index, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum target, GLuint index, GLint * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexImageEXT)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterfvEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterivEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterivEXT)(GLuint buffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointervEXT)(GLuint buffer, GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIivEXT)(GLuint program, GLenum target, GLuint index, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIuivEXT)(GLuint program, GLenum target, GLuint index, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterdvEXT)(GLuint program, GLenum target, GLuint index, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterfvEXT)(GLuint program, GLenum target, GLuint index, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramStringEXT)(GLuint program, GLenum target, GLenum pname, void * string) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramivEXT)(GLuint program, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameterivEXT)(GLuint renderbuffer, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointerIndexedvEXT)(GLenum target, GLuint index, void ** data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointeri_vEXT)(GLenum pname, GLuint index, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImageEXT)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfvEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterivEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegervEXT)(GLuint vaobj, GLenum pname, GLint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, void ** param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointervEXT)(GLuint vaobj, GLenum pname, void ** param) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum target, GLuint index) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferEXT)(GLuint buffer, GLenum access) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixFrustumEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadIdentityEXT)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposedEXT)(GLenum mode, const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposefEXT)(GLenum mode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoaddEXT)(GLenum mode, const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadfEXT)(GLenum mode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposedEXT)(GLenum mode, const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposefEXT)(GLenum mode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultdEXT)(GLenum mode, const GLdouble * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultfEXT)(GLenum mode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixOrthoEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixPopEXT)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixPushEXT)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatedEXT)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatefEXT)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixScaledEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixScalefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatedEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexBufferEXT)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordPointerEXT)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnviEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGeniEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameteriEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexRenderbufferEXT)(GLenum texunit, GLenum target, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferDataEXT)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferStorageEXT)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedCopyBufferSubDataEXT)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteriEXT)(GLuint framebuffer, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbufferEXT)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture1DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture2DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture3DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureFaceEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayerEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dEXT)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dvEXT)(GLuint program, GLenum target, GLuint index, const GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fEXT)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fvEXT)(GLuint program, GLenum target, GLuint index, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4iEXT)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4ivEXT)(GLuint program, GLenum target, GLuint index, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uiEXT)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uivEXT)(GLuint program, GLenum target, GLuint index, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameters4fvEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4ivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4uivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramStringEXT)(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageEXT)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dEXT)(GLuint program, GLint location, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fEXT)(GLuint program, GLint location, GLfloat v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iEXT)(GLuint program, GLint location, GLint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiEXT)(GLuint program, GLint location, GLuint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iEXT)(GLuint program, GLint location, GLint v0, GLint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttribDefaultEXT)(GLbitfield mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRangeEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexturePageCommitmentEXT)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriEXT)(GLuint texture, GLenum target, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureRenderbufferEXT)(GLuint texture, GLenum target, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBufferEXT)(GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindVertexBufferEXT)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayEdgeFlagOffsetEXT)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayFogCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayIndexOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayMultiTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayNormalOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArraySecondaryColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribBindingEXT)(GLuint vaobj, GLuint attribindex, GLuint bindingindex) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribDivisorEXT)(GLuint vaobj, GLuint index, GLuint divisor) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBindingDivisorEXT)(GLuint vaobj, GLuint bindingindex, GLuint divisor) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) = NULL;

static int Load_EXT_direct_state_access(void)
{
	int numFailed = 0;
	_ptrc_glBindMultiTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glBindMultiTextureEXT");
	if(!_ptrc_glBindMultiTextureEXT) numFailed++;
	_ptrc_glCheckNamedFramebufferStatusEXT = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCheckNamedFramebufferStatusEXT");
	if(!_ptrc_glCheckNamedFramebufferStatusEXT) numFailed++;
	_ptrc_glClearNamedBufferDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferDataEXT");
	if(!_ptrc_glClearNamedBufferDataEXT) numFailed++;
	_ptrc_glClearNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizeiptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferSubDataEXT");
	if(!_ptrc_glClearNamedBufferSubDataEXT) numFailed++;
	_ptrc_glClientAttribDefaultEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glClientAttribDefaultEXT");
	if(!_ptrc_glClientAttribDefaultEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexImage1DEXT");
	if(!_ptrc_glCompressedMultiTexImage1DEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexImage2DEXT");
	if(!_ptrc_glCompressedMultiTexImage2DEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexImage3DEXT");
	if(!_ptrc_glCompressedMultiTexImage3DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexSubImage1DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexSubImage2DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedMultiTexSubImage3DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glCompressedTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTextureImage1DEXT");
	if(!_ptrc_glCompressedTextureImage1DEXT) numFailed++;
	_ptrc_glCompressedTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTextureImage2DEXT");
	if(!_ptrc_glCompressedTextureImage2DEXT) numFailed++;
	_ptrc_glCompressedTextureImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTextureImage3DEXT");
	if(!_ptrc_glCompressedTextureImage3DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage1DEXT");
	if(!_ptrc_glCompressedTextureSubImage1DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage2DEXT");
	if(!_ptrc_glCompressedTextureSubImage2DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage3DEXT");
	if(!_ptrc_glCompressedTextureSubImage3DEXT) numFailed++;
	_ptrc_glCopyMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyMultiTexImage1DEXT");
	if(!_ptrc_glCopyMultiTexImage1DEXT) numFailed++;
	_ptrc_glCopyMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyMultiTexImage2DEXT");
	if(!_ptrc_glCopyMultiTexImage2DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage1DEXT");
	if(!_ptrc_glCopyMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage2DEXT");
	if(!_ptrc_glCopyMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage3DEXT");
	if(!_ptrc_glCopyMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glCopyTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyTextureImage1DEXT");
	if(!_ptrc_glCopyTextureImage1DEXT) numFailed++;
	_ptrc_glCopyTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyTextureImage2DEXT");
	if(!_ptrc_glCopyTextureImage2DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTextureSubImage1DEXT");
	if(!_ptrc_glCopyTextureSubImage1DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage2DEXT");
	if(!_ptrc_glCopyTextureSubImage2DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage3DEXT");
	if(!_ptrc_glCopyTextureSubImage3DEXT) numFailed++;
	_ptrc_glDisableClientStateIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableClientStateIndexedEXT");
	if(!_ptrc_glDisableClientStateIndexedEXT) numFailed++;
	_ptrc_glDisableClientStateiEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableClientStateiEXT");
	if(!_ptrc_glDisableClientStateiEXT) numFailed++;
	_ptrc_glDisableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableIndexedEXT");
	if(!_ptrc_glDisableIndexedEXT) numFailed++;
	_ptrc_glDisableVertexArrayAttribEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDisableVertexArrayAttribEXT");
	if(!_ptrc_glDisableVertexArrayAttribEXT) numFailed++;
	_ptrc_glDisableVertexArrayEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glDisableVertexArrayEXT");
	if(!_ptrc_glDisableVertexArrayEXT) numFailed++;
	_ptrc_glEnableClientStateIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableClientStateIndexedEXT");
	if(!_ptrc_glEnableClientStateIndexedEXT) numFailed++;
	_ptrc_glEnableClientStateiEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableClientStateiEXT");
	if(!_ptrc_glEnableClientStateiEXT) numFailed++;
	_ptrc_glEnableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableIndexedEXT");
	if(!_ptrc_glEnableIndexedEXT) numFailed++;
	_ptrc_glEnableVertexArrayAttribEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glEnableVertexArrayAttribEXT");
	if(!_ptrc_glEnableVertexArrayAttribEXT) numFailed++;
	_ptrc_glEnableVertexArrayEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glEnableVertexArrayEXT");
	if(!_ptrc_glEnableVertexArrayEXT) numFailed++;
	_ptrc_glFlushMappedNamedBufferRangeEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedNamedBufferRangeEXT");
	if(!_ptrc_glFlushMappedNamedBufferRangeEXT) numFailed++;
	_ptrc_glFramebufferDrawBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glFramebufferDrawBufferEXT");
	if(!_ptrc_glFramebufferDrawBufferEXT) numFailed++;
	_ptrc_glFramebufferDrawBuffersEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glFramebufferDrawBuffersEXT");
	if(!_ptrc_glFramebufferDrawBuffersEXT) numFailed++;
	_ptrc_glFramebufferReadBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glFramebufferReadBufferEXT");
	if(!_ptrc_glFramebufferReadBufferEXT) numFailed++;
	_ptrc_glGenerateMultiTexMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glGenerateMultiTexMipmapEXT");
	if(!_ptrc_glGenerateMultiTexMipmapEXT) numFailed++;
	_ptrc_glGenerateTextureMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glGenerateTextureMipmapEXT");
	if(!_ptrc_glGenerateTextureMipmapEXT) numFailed++;
	_ptrc_glGetBooleanIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleanIndexedvEXT");
	if(!_ptrc_glGetBooleanIndexedvEXT) numFailed++;
	_ptrc_glGetCompressedMultiTexImageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, void *))IntGetProcAddress("glGetCompressedMultiTexImageEXT");
	if(!_ptrc_glGetCompressedMultiTexImageEXT) numFailed++;
	_ptrc_glGetCompressedTextureImageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, void *))IntGetProcAddress("glGetCompressedTextureImageEXT");
	if(!_ptrc_glGetCompressedTextureImageEXT) numFailed++;
	_ptrc_glGetDoubleIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoubleIndexedvEXT");
	if(!_ptrc_glGetDoubleIndexedvEXT) numFailed++;
	_ptrc_glGetDoublei_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_vEXT");
	if(!_ptrc_glGetDoublei_vEXT) numFailed++;
	_ptrc_glGetFloatIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloatIndexedvEXT");
	if(!_ptrc_glGetFloatIndexedvEXT) numFailed++;
	_ptrc_glGetFloati_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_vEXT");
	if(!_ptrc_glGetFloati_vEXT) numFailed++;
	_ptrc_glGetFramebufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameterivEXT");
	if(!_ptrc_glGetFramebufferParameterivEXT) numFailed++;
	_ptrc_glGetIntegerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegerIndexedvEXT");
	if(!_ptrc_glGetIntegerIndexedvEXT) numFailed++;
	_ptrc_glGetMultiTexEnvfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexEnvfvEXT");
	if(!_ptrc_glGetMultiTexEnvfvEXT) numFailed++;
	_ptrc_glGetMultiTexEnvivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexEnvivEXT");
	if(!_ptrc_glGetMultiTexEnvivEXT) numFailed++;
	_ptrc_glGetMultiTexGendvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLdouble *))IntGetProcAddress("glGetMultiTexGendvEXT");
	if(!_ptrc_glGetMultiTexGendvEXT) numFailed++;
	_ptrc_glGetMultiTexGenfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexGenfvEXT");
	if(!_ptrc_glGetMultiTexGenfvEXT) numFailed++;
	_ptrc_glGetMultiTexGenivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexGenivEXT");
	if(!_ptrc_glGetMultiTexGenivEXT) numFailed++;
	_ptrc_glGetMultiTexImageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLenum, void *))IntGetProcAddress("glGetMultiTexImageEXT");
	if(!_ptrc_glGetMultiTexImageEXT) numFailed++;
	_ptrc_glGetMultiTexLevelParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexLevelParameterfvEXT");
	if(!_ptrc_glGetMultiTexLevelParameterfvEXT) numFailed++;
	_ptrc_glGetMultiTexLevelParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetMultiTexLevelParameterivEXT");
	if(!_ptrc_glGetMultiTexLevelParameterivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexParameterIivEXT");
	if(!_ptrc_glGetMultiTexParameterIivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint *))IntGetProcAddress("glGetMultiTexParameterIuivEXT");
	if(!_ptrc_glGetMultiTexParameterIuivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexParameterfvEXT");
	if(!_ptrc_glGetMultiTexParameterfvEXT) numFailed++;
	_ptrc_glGetMultiTexParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexParameterivEXT");
	if(!_ptrc_glGetMultiTexParameterivEXT) numFailed++;
	_ptrc_glGetNamedBufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedBufferParameterivEXT");
	if(!_ptrc_glGetNamedBufferParameterivEXT) numFailed++;
	_ptrc_glGetNamedBufferPointervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetNamedBufferPointervEXT");
	if(!_ptrc_glGetNamedBufferPointervEXT) numFailed++;
	_ptrc_glGetNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, void *))IntGetProcAddress("glGetNamedBufferSubDataEXT");
	if(!_ptrc_glGetNamedBufferSubDataEXT) numFailed++;
	_ptrc_glGetNamedFramebufferAttachmentParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
	if(!_ptrc_glGetNamedFramebufferAttachmentParameterivEXT) numFailed++;
	_ptrc_glGetNamedFramebufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferParameterivEXT");
	if(!_ptrc_glGetNamedFramebufferParameterivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint *))IntGetProcAddress("glGetNamedProgramLocalParameterIivEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterIivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLuint *))IntGetProcAddress("glGetNamedProgramLocalParameterIuivEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterIuivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterdvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetNamedProgramLocalParameterdvEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterdvEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetNamedProgramLocalParameterfvEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterfvEXT) numFailed++;
	_ptrc_glGetNamedProgramStringEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, void *))IntGetProcAddress("glGetNamedProgramStringEXT");
	if(!_ptrc_glGetNamedProgramStringEXT) numFailed++;
	_ptrc_glGetNamedProgramivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedProgramivEXT");
	if(!_ptrc_glGetNamedProgramivEXT) numFailed++;
	_ptrc_glGetNamedRenderbufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedRenderbufferParameterivEXT");
	if(!_ptrc_glGetNamedRenderbufferParameterivEXT) numFailed++;
	_ptrc_glGetPointerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, void **))IntGetProcAddress("glGetPointerIndexedvEXT");
	if(!_ptrc_glGetPointerIndexedvEXT) numFailed++;
	_ptrc_glGetPointeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, void **))IntGetProcAddress("glGetPointeri_vEXT");
	if(!_ptrc_glGetPointeri_vEXT) numFailed++;
	_ptrc_glGetTextureImageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLenum, void *))IntGetProcAddress("glGetTextureImageEXT");
	if(!_ptrc_glGetTextureImageEXT) numFailed++;
	_ptrc_glGetTextureLevelParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureLevelParameterfvEXT");
	if(!_ptrc_glGetTextureLevelParameterfvEXT) numFailed++;
	_ptrc_glGetTextureLevelParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetTextureLevelParameterivEXT");
	if(!_ptrc_glGetTextureLevelParameterivEXT) numFailed++;
	_ptrc_glGetTextureParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterIivEXT");
	if(!_ptrc_glGetTextureParameterIivEXT) numFailed++;
	_ptrc_glGetTextureParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTextureParameterIuivEXT");
	if(!_ptrc_glGetTextureParameterIuivEXT) numFailed++;
	_ptrc_glGetTextureParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTextureParameterfvEXT");
	if(!_ptrc_glGetTextureParameterfvEXT) numFailed++;
	_ptrc_glGetTextureParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterivEXT");
	if(!_ptrc_glGetTextureParameterivEXT) numFailed++;
	_ptrc_glGetVertexArrayIntegeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIntegeri_vEXT");
	if(!_ptrc_glGetVertexArrayIntegeri_vEXT) numFailed++;
	_ptrc_glGetVertexArrayIntegervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIntegervEXT");
	if(!_ptrc_glGetVertexArrayIntegervEXT) numFailed++;
	_ptrc_glGetVertexArrayPointeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, void **))IntGetProcAddress("glGetVertexArrayPointeri_vEXT");
	if(!_ptrc_glGetVertexArrayPointeri_vEXT) numFailed++;
	_ptrc_glGetVertexArrayPointervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetVertexArrayPointervEXT");
	if(!_ptrc_glGetVertexArrayPointervEXT) numFailed++;
	_ptrc_glIsEnabledIndexedEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledIndexedEXT");
	if(!_ptrc_glIsEnabledIndexedEXT) numFailed++;
	_ptrc_glMapNamedBufferEXT = (void * (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMapNamedBufferEXT");
	if(!_ptrc_glMapNamedBufferEXT) numFailed++;
	_ptrc_glMapNamedBufferRangeEXT = (void * (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapNamedBufferRangeEXT");
	if(!_ptrc_glMapNamedBufferRangeEXT) numFailed++;
	_ptrc_glMatrixFrustumEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixFrustumEXT");
	if(!_ptrc_glMatrixFrustumEXT) numFailed++;
	_ptrc_glMatrixLoadIdentityEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixLoadIdentityEXT");
	if(!_ptrc_glMatrixLoadIdentityEXT) numFailed++;
	_ptrc_glMatrixLoadTransposedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixLoadTransposedEXT");
	if(!_ptrc_glMatrixLoadTransposedEXT) numFailed++;
	_ptrc_glMatrixLoadTransposefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoadTransposefEXT");
	if(!_ptrc_glMatrixLoadTransposefEXT) numFailed++;
	_ptrc_glMatrixLoaddEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixLoaddEXT");
	if(!_ptrc_glMatrixLoaddEXT) numFailed++;
	_ptrc_glMatrixLoadfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoadfEXT");
	if(!_ptrc_glMatrixLoadfEXT) numFailed++;
	_ptrc_glMatrixMultTransposedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixMultTransposedEXT");
	if(!_ptrc_glMatrixMultTransposedEXT) numFailed++;
	_ptrc_glMatrixMultTransposefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMultTransposefEXT");
	if(!_ptrc_glMatrixMultTransposefEXT) numFailed++;
	_ptrc_glMatrixMultdEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixMultdEXT");
	if(!_ptrc_glMatrixMultdEXT) numFailed++;
	_ptrc_glMatrixMultfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMultfEXT");
	if(!_ptrc_glMatrixMultfEXT) numFailed++;
	_ptrc_glMatrixOrthoEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixOrthoEXT");
	if(!_ptrc_glMatrixOrthoEXT) numFailed++;
	_ptrc_glMatrixPopEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixPopEXT");
	if(!_ptrc_glMatrixPopEXT) numFailed++;
	_ptrc_glMatrixPushEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixPushEXT");
	if(!_ptrc_glMatrixPushEXT) numFailed++;
	_ptrc_glMatrixRotatedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixRotatedEXT");
	if(!_ptrc_glMatrixRotatedEXT) numFailed++;
	_ptrc_glMatrixRotatefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixRotatefEXT");
	if(!_ptrc_glMatrixRotatefEXT) numFailed++;
	_ptrc_glMatrixScaledEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixScaledEXT");
	if(!_ptrc_glMatrixScaledEXT) numFailed++;
	_ptrc_glMatrixScalefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixScalefEXT");
	if(!_ptrc_glMatrixScalefEXT) numFailed++;
	_ptrc_glMatrixTranslatedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixTranslatedEXT");
	if(!_ptrc_glMatrixTranslatedEXT) numFailed++;
	_ptrc_glMatrixTranslatefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixTranslatefEXT");
	if(!_ptrc_glMatrixTranslatefEXT) numFailed++;
	_ptrc_glMultiTexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexBufferEXT");
	if(!_ptrc_glMultiTexBufferEXT) numFailed++;
	_ptrc_glMultiTexCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glMultiTexCoordPointerEXT");
	if(!_ptrc_glMultiTexCoordPointerEXT) numFailed++;
	_ptrc_glMultiTexEnvfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexEnvfEXT");
	if(!_ptrc_glMultiTexEnvfEXT) numFailed++;
	_ptrc_glMultiTexEnvfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexEnvfvEXT");
	if(!_ptrc_glMultiTexEnvfvEXT) numFailed++;
	_ptrc_glMultiTexEnviEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexEnviEXT");
	if(!_ptrc_glMultiTexEnviEXT) numFailed++;
	_ptrc_glMultiTexEnvivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexEnvivEXT");
	if(!_ptrc_glMultiTexEnvivEXT) numFailed++;
	_ptrc_glMultiTexGendEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLdouble))IntGetProcAddress("glMultiTexGendEXT");
	if(!_ptrc_glMultiTexGendEXT) numFailed++;
	_ptrc_glMultiTexGendvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLdouble *))IntGetProcAddress("glMultiTexGendvEXT");
	if(!_ptrc_glMultiTexGendvEXT) numFailed++;
	_ptrc_glMultiTexGenfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexGenfEXT");
	if(!_ptrc_glMultiTexGenfEXT) numFailed++;
	_ptrc_glMultiTexGenfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexGenfvEXT");
	if(!_ptrc_glMultiTexGenfvEXT) numFailed++;
	_ptrc_glMultiTexGeniEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexGeniEXT");
	if(!_ptrc_glMultiTexGeniEXT) numFailed++;
	_ptrc_glMultiTexGenivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexGenivEXT");
	if(!_ptrc_glMultiTexGenivEXT) numFailed++;
	_ptrc_glMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexImage1DEXT");
	if(!_ptrc_glMultiTexImage1DEXT) numFailed++;
	_ptrc_glMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexImage2DEXT");
	if(!_ptrc_glMultiTexImage2DEXT) numFailed++;
	_ptrc_glMultiTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexImage3DEXT");
	if(!_ptrc_glMultiTexImage3DEXT) numFailed++;
	_ptrc_glMultiTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexParameterIivEXT");
	if(!_ptrc_glMultiTexParameterIivEXT) numFailed++;
	_ptrc_glMultiTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexParameterIuivEXT");
	if(!_ptrc_glMultiTexParameterIuivEXT) numFailed++;
	_ptrc_glMultiTexParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexParameterfEXT");
	if(!_ptrc_glMultiTexParameterfEXT) numFailed++;
	_ptrc_glMultiTexParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexParameterfvEXT");
	if(!_ptrc_glMultiTexParameterfvEXT) numFailed++;
	_ptrc_glMultiTexParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexParameteriEXT");
	if(!_ptrc_glMultiTexParameteriEXT) numFailed++;
	_ptrc_glMultiTexParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexParameterivEXT");
	if(!_ptrc_glMultiTexParameterivEXT) numFailed++;
	_ptrc_glMultiTexRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexRenderbufferEXT");
	if(!_ptrc_glMultiTexRenderbufferEXT) numFailed++;
	_ptrc_glMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexSubImage1DEXT");
	if(!_ptrc_glMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexSubImage2DEXT");
	if(!_ptrc_glMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glMultiTexSubImage3DEXT");
	if(!_ptrc_glMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glNamedBufferDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLenum))IntGetProcAddress("glNamedBufferDataEXT");
	if(!_ptrc_glNamedBufferDataEXT) numFailed++;
	_ptrc_glNamedBufferStorageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glNamedBufferStorageEXT");
	if(!_ptrc_glNamedBufferStorageEXT) numFailed++;
	_ptrc_glNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, const void *))IntGetProcAddress("glNamedBufferSubDataEXT");
	if(!_ptrc_glNamedBufferSubDataEXT) numFailed++;
	_ptrc_glNamedCopyBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glNamedCopyBufferSubDataEXT");
	if(!_ptrc_glNamedCopyBufferSubDataEXT) numFailed++;
	_ptrc_glNamedFramebufferParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glNamedFramebufferParameteriEXT");
	if(!_ptrc_glNamedFramebufferParameteriEXT) numFailed++;
	_ptrc_glNamedFramebufferRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glNamedFramebufferRenderbufferEXT");
	if(!_ptrc_glNamedFramebufferRenderbufferEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture1DEXT");
	if(!_ptrc_glNamedFramebufferTexture1DEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture2DEXT");
	if(!_ptrc_glNamedFramebufferTexture2DEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTexture3DEXT");
	if(!_ptrc_glNamedFramebufferTexture3DEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTextureEXT");
	if(!_ptrc_glNamedFramebufferTextureEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureFaceEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLenum))IntGetProcAddress("glNamedFramebufferTextureFaceEXT");
	if(!_ptrc_glNamedFramebufferTextureFaceEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureLayerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTextureLayerEXT");
	if(!_ptrc_glNamedFramebufferTextureLayerEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glNamedProgramLocalParameter4dEXT");
	if(!_ptrc_glNamedProgramLocalParameter4dEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLdouble *))IntGetProcAddress("glNamedProgramLocalParameter4dvEXT");
	if(!_ptrc_glNamedProgramLocalParameter4dvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glNamedProgramLocalParameter4fEXT");
	if(!_ptrc_glNamedProgramLocalParameter4fEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLfloat *))IntGetProcAddress("glNamedProgramLocalParameter4fvEXT");
	if(!_ptrc_glNamedProgramLocalParameter4fvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glNamedProgramLocalParameterI4iEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4iEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLint *))IntGetProcAddress("glNamedProgramLocalParameterI4ivEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4ivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glNamedProgramLocalParameterI4uiEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4uiEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLuint *))IntGetProcAddress("glNamedProgramLocalParameterI4uivEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4uivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glNamedProgramLocalParameters4fvEXT");
	if(!_ptrc_glNamedProgramLocalParameters4fvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParametersI4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glNamedProgramLocalParametersI4ivEXT");
	if(!_ptrc_glNamedProgramLocalParametersI4ivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParametersI4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glNamedProgramLocalParametersI4uivEXT");
	if(!_ptrc_glNamedProgramLocalParametersI4uivEXT) numFailed++;
	_ptrc_glNamedProgramStringEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLsizei, const void *))IntGetProcAddress("glNamedProgramStringEXT");
	if(!_ptrc_glNamedProgramStringEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageEXT");
	if(!_ptrc_glNamedRenderbufferStorageEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
	if(!_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
	if(!_ptrc_glNamedRenderbufferStorageMultisampleEXT) numFailed++;
	_ptrc_glProgramUniform1dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1dEXT");
	if(!_ptrc_glProgramUniform1dEXT) numFailed++;
	_ptrc_glProgramUniform1dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dvEXT");
	if(!_ptrc_glProgramUniform1dvEXT) numFailed++;
	_ptrc_glProgramUniform1fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1fEXT");
	if(!_ptrc_glProgramUniform1fEXT) numFailed++;
	_ptrc_glProgramUniform1fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fvEXT");
	if(!_ptrc_glProgramUniform1fvEXT) numFailed++;
	_ptrc_glProgramUniform1iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1iEXT");
	if(!_ptrc_glProgramUniform1iEXT) numFailed++;
	_ptrc_glProgramUniform1ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1ivEXT");
	if(!_ptrc_glProgramUniform1ivEXT) numFailed++;
	_ptrc_glProgramUniform1uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1uiEXT");
	if(!_ptrc_glProgramUniform1uiEXT) numFailed++;
	_ptrc_glProgramUniform1uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uivEXT");
	if(!_ptrc_glProgramUniform1uivEXT) numFailed++;
	_ptrc_glProgramUniform2dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2dEXT");
	if(!_ptrc_glProgramUniform2dEXT) numFailed++;
	_ptrc_glProgramUniform2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dvEXT");
	if(!_ptrc_glProgramUniform2dvEXT) numFailed++;
	_ptrc_glProgramUniform2fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2fEXT");
	if(!_ptrc_glProgramUniform2fEXT) numFailed++;
	_ptrc_glProgramUniform2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fvEXT");
	if(!_ptrc_glProgramUniform2fvEXT) numFailed++;
	_ptrc_glProgramUniform2iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2iEXT");
	if(!_ptrc_glProgramUniform2iEXT) numFailed++;
	_ptrc_glProgramUniform2ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2ivEXT");
	if(!_ptrc_glProgramUniform2ivEXT) numFailed++;
	_ptrc_glProgramUniform2uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2uiEXT");
	if(!_ptrc_glProgramUniform2uiEXT) numFailed++;
	_ptrc_glProgramUniform2uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uivEXT");
	if(!_ptrc_glProgramUniform2uivEXT) numFailed++;
	_ptrc_glProgramUniform3dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3dEXT");
	if(!_ptrc_glProgramUniform3dEXT) numFailed++;
	_ptrc_glProgramUniform3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dvEXT");
	if(!_ptrc_glProgramUniform3dvEXT) numFailed++;
	_ptrc_glProgramUniform3fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3fEXT");
	if(!_ptrc_glProgramUniform3fEXT) numFailed++;
	_ptrc_glProgramUniform3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fvEXT");
	if(!_ptrc_glProgramUniform3fvEXT) numFailed++;
	_ptrc_glProgramUniform3iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3iEXT");
	if(!_ptrc_glProgramUniform3iEXT) numFailed++;
	_ptrc_glProgramUniform3ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3ivEXT");
	if(!_ptrc_glProgramUniform3ivEXT) numFailed++;
	_ptrc_glProgramUniform3uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3uiEXT");
	if(!_ptrc_glProgramUniform3uiEXT) numFailed++;
	_ptrc_glProgramUniform3uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uivEXT");
	if(!_ptrc_glProgramUniform3uivEXT) numFailed++;
	_ptrc_glProgramUniform4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4dEXT");
	if(!_ptrc_glProgramUniform4dEXT) numFailed++;
	_ptrc_glProgramUniform4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dvEXT");
	if(!_ptrc_glProgramUniform4dvEXT) numFailed++;
	_ptrc_glProgramUniform4fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4fEXT");
	if(!_ptrc_glProgramUniform4fEXT) numFailed++;
	_ptrc_glProgramUniform4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fvEXT");
	if(!_ptrc_glProgramUniform4fvEXT) numFailed++;
	_ptrc_glProgramUniform4iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4iEXT");
	if(!_ptrc_glProgramUniform4iEXT) numFailed++;
	_ptrc_glProgramUniform4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4ivEXT");
	if(!_ptrc_glProgramUniform4ivEXT) numFailed++;
	_ptrc_glProgramUniform4uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4uiEXT");
	if(!_ptrc_glProgramUniform4uiEXT) numFailed++;
	_ptrc_glProgramUniform4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uivEXT");
	if(!_ptrc_glProgramUniform4uivEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dvEXT");
	if(!_ptrc_glProgramUniformMatrix2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fvEXT");
	if(!_ptrc_glProgramUniformMatrix2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dvEXT");
	if(!_ptrc_glProgramUniformMatrix2x3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fvEXT");
	if(!_ptrc_glProgramUniformMatrix2x3fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dvEXT");
	if(!_ptrc_glProgramUniformMatrix2x4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fvEXT");
	if(!_ptrc_glProgramUniformMatrix2x4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dvEXT");
	if(!_ptrc_glProgramUniformMatrix3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fvEXT");
	if(!_ptrc_glProgramUniformMatrix3fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dvEXT");
	if(!_ptrc_glProgramUniformMatrix3x2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fvEXT");
	if(!_ptrc_glProgramUniformMatrix3x2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dvEXT");
	if(!_ptrc_glProgramUniformMatrix3x4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fvEXT");
	if(!_ptrc_glProgramUniformMatrix3x4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dvEXT");
	if(!_ptrc_glProgramUniformMatrix4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fvEXT");
	if(!_ptrc_glProgramUniformMatrix4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dvEXT");
	if(!_ptrc_glProgramUniformMatrix4x2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fvEXT");
	if(!_ptrc_glProgramUniformMatrix4x2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dvEXT");
	if(!_ptrc_glProgramUniformMatrix4x3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fvEXT");
	if(!_ptrc_glProgramUniformMatrix4x3fvEXT) numFailed++;
	_ptrc_glPushClientAttribDefaultEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glPushClientAttribDefaultEXT");
	if(!_ptrc_glPushClientAttribDefaultEXT) numFailed++;
	_ptrc_glTextureBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glTextureBufferEXT");
	if(!_ptrc_glTextureBufferEXT) numFailed++;
	_ptrc_glTextureBufferRangeEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTextureBufferRangeEXT");
	if(!_ptrc_glTextureBufferRangeEXT) numFailed++;
	_ptrc_glTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTextureImage1DEXT");
	if(!_ptrc_glTextureImage1DEXT) numFailed++;
	_ptrc_glTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTextureImage2DEXT");
	if(!_ptrc_glTextureImage2DEXT) numFailed++;
	_ptrc_glTextureImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTextureImage3DEXT");
	if(!_ptrc_glTextureImage3DEXT) numFailed++;
	_ptrc_glTexturePageCommitmentEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexturePageCommitmentEXT");
	if(!_ptrc_glTexturePageCommitmentEXT) numFailed++;
	_ptrc_glTextureParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLint *))IntGetProcAddress("glTextureParameterIivEXT");
	if(!_ptrc_glTextureParameterIivEXT) numFailed++;
	_ptrc_glTextureParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLuint *))IntGetProcAddress("glTextureParameterIuivEXT");
	if(!_ptrc_glTextureParameterIuivEXT) numFailed++;
	_ptrc_glTextureParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLfloat))IntGetProcAddress("glTextureParameterfEXT");
	if(!_ptrc_glTextureParameterfEXT) numFailed++;
	_ptrc_glTextureParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTextureParameterfvEXT");
	if(!_ptrc_glTextureParameterfvEXT) numFailed++;
	_ptrc_glTextureParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint))IntGetProcAddress("glTextureParameteriEXT");
	if(!_ptrc_glTextureParameteriEXT) numFailed++;
	_ptrc_glTextureParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLint *))IntGetProcAddress("glTextureParameterivEXT");
	if(!_ptrc_glTextureParameterivEXT) numFailed++;
	_ptrc_glTextureRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glTextureRenderbufferEXT");
	if(!_ptrc_glTextureRenderbufferEXT) numFailed++;
	_ptrc_glTextureStorage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTextureStorage1DEXT");
	if(!_ptrc_glTextureStorage1DEXT) numFailed++;
	_ptrc_glTextureStorage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage2DEXT");
	if(!_ptrc_glTextureStorage2DEXT) numFailed++;
	_ptrc_glTextureStorage2DMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage2DMultisampleEXT");
	if(!_ptrc_glTextureStorage2DMultisampleEXT) numFailed++;
	_ptrc_glTextureStorage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage3DEXT");
	if(!_ptrc_glTextureStorage3DEXT) numFailed++;
	_ptrc_glTextureStorage3DMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage3DMultisampleEXT");
	if(!_ptrc_glTextureStorage3DMultisampleEXT) numFailed++;
	_ptrc_glTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage1DEXT");
	if(!_ptrc_glTextureSubImage1DEXT) numFailed++;
	_ptrc_glTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage2DEXT");
	if(!_ptrc_glTextureSubImage2DEXT) numFailed++;
	_ptrc_glTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage3DEXT");
	if(!_ptrc_glTextureSubImage3DEXT) numFailed++;
	_ptrc_glUnmapNamedBufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUnmapNamedBufferEXT");
	if(!_ptrc_glUnmapNamedBufferEXT) numFailed++;
	_ptrc_glVertexArrayBindVertexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glVertexArrayBindVertexBufferEXT");
	if(!_ptrc_glVertexArrayBindVertexBufferEXT) numFailed++;
	_ptrc_glVertexArrayColorOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayColorOffsetEXT");
	if(!_ptrc_glVertexArrayColorOffsetEXT) numFailed++;
	_ptrc_glVertexArrayEdgeFlagOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayEdgeFlagOffsetEXT");
	if(!_ptrc_glVertexArrayEdgeFlagOffsetEXT) numFailed++;
	_ptrc_glVertexArrayFogCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayFogCoordOffsetEXT");
	if(!_ptrc_glVertexArrayFogCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayIndexOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayIndexOffsetEXT");
	if(!_ptrc_glVertexArrayIndexOffsetEXT) numFailed++;
	_ptrc_glVertexArrayMultiTexCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayMultiTexCoordOffsetEXT");
	if(!_ptrc_glVertexArrayMultiTexCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayNormalOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayNormalOffsetEXT");
	if(!_ptrc_glVertexArrayNormalOffsetEXT) numFailed++;
	_ptrc_glVertexArraySecondaryColorOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArraySecondaryColorOffsetEXT");
	if(!_ptrc_glVertexArraySecondaryColorOffsetEXT) numFailed++;
	_ptrc_glVertexArrayTexCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayTexCoordOffsetEXT");
	if(!_ptrc_glVertexArrayTexCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribBindingEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	if(!_ptrc_glVertexArrayVertexAttribBindingEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribDivisorEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayVertexAttribDivisorEXT");
	if(!_ptrc_glVertexArrayVertexAttribDivisorEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribIFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribIFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribIOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribIOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribLFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribLFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribLOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribLOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribLOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexBindingDivisorEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	if(!_ptrc_glVertexArrayVertexBindingDivisorEXT) numFailed++;
	_ptrc_glVertexArrayVertexOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexOffsetEXT");
	if(!_ptrc_glVertexArrayVertexOffsetEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorMaskIndexedEXT)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = NULL;

static int Load_EXT_draw_buffers2(void)
{
	int numFailed = 0;
	_ptrc_glColorMaskIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMaskIndexedEXT");
	if(!_ptrc_glColorMaskIndexedEXT) numFailed++;
	_ptrc_glDisableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableIndexedEXT");
	if(!_ptrc_glDisableIndexedEXT) numFailed++;
	_ptrc_glEnableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableIndexedEXT");
	if(!_ptrc_glEnableIndexedEXT) numFailed++;
	_ptrc_glGetBooleanIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleanIndexedvEXT");
	if(!_ptrc_glGetBooleanIndexedvEXT) numFailed++;
	_ptrc_glGetIntegerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegerIndexedvEXT");
	if(!_ptrc_glGetIntegerIndexedvEXT) numFailed++;
	_ptrc_glIsEnabledIndexedEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledIndexedEXT");
	if(!_ptrc_glIsEnabledIndexedEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedEXT)(GLenum mode, GLint start, GLsizei count, GLsizei primcount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedEXT)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount) = NULL;

static int Load_EXT_draw_instanced(void)
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstancedEXT");
	if(!_ptrc_glDrawArraysInstancedEXT) numFailed++;
	_ptrc_glDrawElementsInstancedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei))IntGetProcAddress("glDrawElementsInstancedEXT");
	if(!_ptrc_glDrawElementsInstancedEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsEXT)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) = NULL;

static int Load_EXT_draw_range_elements(void)
{
	int numFailed = 0;
	_ptrc_glDrawRangeElementsEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *))IntGetProcAddress("glDrawRangeElementsEXT");
	if(!_ptrc_glDrawRangeElementsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerEXT)(GLenum type, GLsizei stride, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddEXT)(GLdouble coord) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddvEXT)(const GLdouble * coord) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfEXT)(GLfloat coord) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfvEXT)(const GLfloat * coord) = NULL;

static int Load_EXT_fog_coord(void)
{
	int numFailed = 0;
	_ptrc_glFogCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const void *))IntGetProcAddress("glFogCoordPointerEXT");
	if(!_ptrc_glFogCoordPointerEXT) numFailed++;
	_ptrc_glFogCoorddEXT = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glFogCoorddEXT");
	if(!_ptrc_glFogCoorddEXT) numFailed++;
	_ptrc_glFogCoorddvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glFogCoorddvEXT");
	if(!_ptrc_glFogCoorddvEXT) numFailed++;
	_ptrc_glFogCoordfEXT = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glFogCoordfEXT");
	if(!_ptrc_glFogCoordfEXT) numFailed++;
	_ptrc_glFogCoordfvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glFogCoordfvEXT");
	if(!_ptrc_glFogCoordfvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebufferEXT)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = NULL;

static int Load_EXT_framebuffer_blit(void)
{
	int numFailed = 0;
	_ptrc_glBlitFramebufferEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebufferEXT");
	if(!_ptrc_glBlitFramebufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleEXT)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;

static int Load_EXT_framebuffer_multisample(void)
{
	int numFailed = 0;
	_ptrc_glRenderbufferStorageMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisampleEXT");
	if(!_ptrc_glRenderbufferStorageMultisampleEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFramebufferEXT)(GLenum target, GLuint framebuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbufferEXT)(GLenum target, GLuint renderbuffer) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatusEXT)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffersEXT)(GLsizei n, const GLuint * framebuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffersEXT)(GLsizei n, const GLuint * renderbuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbufferEXT)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffersEXT)(GLsizei n, GLuint * framebuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffersEXT)(GLsizei n, GLuint * renderbuffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmapEXT)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameterivEXT)(GLenum target, GLenum attachment, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameterivEXT)(GLenum target, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebufferEXT)(GLuint framebuffer) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbufferEXT)(GLuint renderbuffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageEXT)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = NULL;

static int Load_EXT_framebuffer_object(void)
{
	int numFailed = 0;
	_ptrc_glBindFramebufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebufferEXT");
	if(!_ptrc_glBindFramebufferEXT) numFailed++;
	_ptrc_glBindRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbufferEXT");
	if(!_ptrc_glBindRenderbufferEXT) numFailed++;
	_ptrc_glCheckFramebufferStatusEXT = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatusEXT");
	if(!_ptrc_glCheckFramebufferStatusEXT) numFailed++;
	_ptrc_glDeleteFramebuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffersEXT");
	if(!_ptrc_glDeleteFramebuffersEXT) numFailed++;
	_ptrc_glDeleteRenderbuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffersEXT");
	if(!_ptrc_glDeleteRenderbuffersEXT) numFailed++;
	_ptrc_glFramebufferRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbufferEXT");
	if(!_ptrc_glFramebufferRenderbufferEXT) numFailed++;
	_ptrc_glFramebufferTexture1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1DEXT");
	if(!_ptrc_glFramebufferTexture1DEXT) numFailed++;
	_ptrc_glFramebufferTexture2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2DEXT");
	if(!_ptrc_glFramebufferTexture2DEXT) numFailed++;
	_ptrc_glFramebufferTexture3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3DEXT");
	if(!_ptrc_glFramebufferTexture3DEXT) numFailed++;
	_ptrc_glGenFramebuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffersEXT");
	if(!_ptrc_glGenFramebuffersEXT) numFailed++;
	_ptrc_glGenRenderbuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffersEXT");
	if(!_ptrc_glGenRenderbuffersEXT) numFailed++;
	_ptrc_glGenerateMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmapEXT");
	if(!_ptrc_glGenerateMipmapEXT) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
	if(!_ptrc_glGetFramebufferAttachmentParameterivEXT) numFailed++;
	_ptrc_glGetRenderbufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameterivEXT");
	if(!_ptrc_glGetRenderbufferParameterivEXT) numFailed++;
	_ptrc_glIsFramebufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebufferEXT");
	if(!_ptrc_glIsFramebufferEXT) numFailed++;
	_ptrc_glIsRenderbufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbufferEXT");
	if(!_ptrc_glIsRenderbufferEXT) numFailed++;
	_ptrc_glRenderbufferStorageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageEXT");
	if(!_ptrc_glRenderbufferStorageEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriEXT)(GLuint program, GLenum pname, GLint value) = NULL;

static int Load_EXT_geometry_shader4(void)
{
	int numFailed = 0;
	_ptrc_glProgramParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteriEXT");
	if(!_ptrc_glProgramParameteriEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat * params) = NULL;

static int Load_EXT_gpu_program_parameters(void)
{
	int numFailed = 0;
	_ptrc_glProgramEnvParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramEnvParameters4fvEXT");
	if(!_ptrc_glProgramEnvParameters4fvEXT) numFailed++;
	_ptrc_glProgramLocalParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramLocalParameters4fvEXT");
	if(!_ptrc_glProgramLocalParameters4fvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationEXT)(GLuint program, GLuint color, const GLchar * name) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocationEXT)(GLuint program, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuivEXT)(GLuint program, GLint location, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiEXT)(GLint location, GLuint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uivEXT)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiEXT)(GLint location, GLuint v0, GLuint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uivEXT)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uivEXT)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uivEXT)(GLint location, GLsizei count, const GLuint * value) = NULL;

static int Load_EXT_gpu_shader4(void)
{
	int numFailed = 0;
	_ptrc_glBindFragDataLocationEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationEXT");
	if(!_ptrc_glBindFragDataLocationEXT) numFailed++;
	_ptrc_glGetFragDataLocationEXT = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataLocationEXT");
	if(!_ptrc_glGetFragDataLocationEXT) numFailed++;
	_ptrc_glGetUniformuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint *))IntGetProcAddress("glGetUniformuivEXT");
	if(!_ptrc_glGetUniformuivEXT) numFailed++;
	_ptrc_glUniform1uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint))IntGetProcAddress("glUniform1uiEXT");
	if(!_ptrc_glUniform1uiEXT) numFailed++;
	_ptrc_glUniform1uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform1uivEXT");
	if(!_ptrc_glUniform1uivEXT) numFailed++;
	_ptrc_glUniform2uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint))IntGetProcAddress("glUniform2uiEXT");
	if(!_ptrc_glUniform2uiEXT) numFailed++;
	_ptrc_glUniform2uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform2uivEXT");
	if(!_ptrc_glUniform2uivEXT) numFailed++;
	_ptrc_glUniform3uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform3uiEXT");
	if(!_ptrc_glUniform3uiEXT) numFailed++;
	_ptrc_glUniform3uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform3uivEXT");
	if(!_ptrc_glUniform3uivEXT) numFailed++;
	_ptrc_glUniform4uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform4uiEXT");
	if(!_ptrc_glUniform4uiEXT) numFailed++;
	_ptrc_glUniform4uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform4uivEXT");
	if(!_ptrc_glUniform4uivEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysEXT)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsEXT)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount) = NULL;

static int Load_EXT_multi_draw_arrays(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawArraysEXT");
	if(!_ptrc_glMultiDrawArraysEXT) numFailed++;
	_ptrc_glMultiDrawElementsEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei))IntGetProcAddress("glMultiDrawElementsEXT");
	if(!_ptrc_glMultiDrawElementsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfEXT)(GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvEXT)(GLenum pname, const GLfloat * params) = NULL;

static int Load_EXT_point_parameters(void)
{
	int numFailed = 0;
	_ptrc_glPointParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterfEXT");
	if(!_ptrc_glPointParameterfEXT) numFailed++;
	_ptrc_glPointParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfvEXT");
	if(!_ptrc_glPointParameterfvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetClampEXT)(GLfloat factor, GLfloat units, GLfloat clamp) = NULL;

static int Load_EXT_polygon_offset_clamp(void)
{
	int numFailed = 0;
	_ptrc_glPolygonOffsetClampEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glPolygonOffsetClampEXT");
	if(!_ptrc_glPolygonOffsetClampEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertexEXT)(GLenum mode) = NULL;

static int Load_EXT_provoking_vertex(void)
{
	int numFailed = 0;
	_ptrc_glProvokingVertexEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertexEXT");
	if(!_ptrc_glProvokingVertexEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bEXT)(GLbyte red, GLbyte green, GLbyte blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bvEXT)(const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dEXT)(GLdouble red, GLdouble green, GLdouble blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dvEXT)(const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fEXT)(GLfloat red, GLfloat green, GLfloat blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fvEXT)(const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iEXT)(GLint red, GLint green, GLint blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ivEXT)(const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sEXT)(GLshort red, GLshort green, GLshort blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3svEXT)(const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubEXT)(GLubyte red, GLubyte green, GLubyte blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubvEXT)(const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiEXT)(GLuint red, GLuint green, GLuint blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uivEXT)(const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usEXT)(GLushort red, GLushort green, GLushort blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usvEXT)(const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerEXT)(GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;

static int Load_EXT_secondary_color(void)
{
	int numFailed = 0;
	_ptrc_glSecondaryColor3bEXT = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glSecondaryColor3bEXT");
	if(!_ptrc_glSecondaryColor3bEXT) numFailed++;
	_ptrc_glSecondaryColor3bvEXT = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glSecondaryColor3bvEXT");
	if(!_ptrc_glSecondaryColor3bvEXT) numFailed++;
	_ptrc_glSecondaryColor3dEXT = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glSecondaryColor3dEXT");
	if(!_ptrc_glSecondaryColor3dEXT) numFailed++;
	_ptrc_glSecondaryColor3dvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glSecondaryColor3dvEXT");
	if(!_ptrc_glSecondaryColor3dvEXT) numFailed++;
	_ptrc_glSecondaryColor3fEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glSecondaryColor3fEXT");
	if(!_ptrc_glSecondaryColor3fEXT) numFailed++;
	_ptrc_glSecondaryColor3fvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glSecondaryColor3fvEXT");
	if(!_ptrc_glSecondaryColor3fvEXT) numFailed++;
	_ptrc_glSecondaryColor3iEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glSecondaryColor3iEXT");
	if(!_ptrc_glSecondaryColor3iEXT) numFailed++;
	_ptrc_glSecondaryColor3ivEXT = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glSecondaryColor3ivEXT");
	if(!_ptrc_glSecondaryColor3ivEXT) numFailed++;
	_ptrc_glSecondaryColor3sEXT = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glSecondaryColor3sEXT");
	if(!_ptrc_glSecondaryColor3sEXT) numFailed++;
	_ptrc_glSecondaryColor3svEXT = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glSecondaryColor3svEXT");
	if(!_ptrc_glSecondaryColor3svEXT) numFailed++;
	_ptrc_glSecondaryColor3ubEXT = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte))IntGetProcAddress("glSecondaryColor3ubEXT");
	if(!_ptrc_glSecondaryColor3ubEXT) numFailed++;
	_ptrc_glSecondaryColor3ubvEXT = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glSecondaryColor3ubvEXT");
	if(!_ptrc_glSecondaryColor3ubvEXT) numFailed++;
	_ptrc_glSecondaryColor3uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glSecondaryColor3uiEXT");
	if(!_ptrc_glSecondaryColor3uiEXT) numFailed++;
	_ptrc_glSecondaryColor3uivEXT = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glSecondaryColor3uivEXT");
	if(!_ptrc_glSecondaryColor3uivEXT) numFailed++;
	_ptrc_glSecondaryColor3usEXT = (void (CODEGEN_FUNCPTR *)(GLushort, GLushort, GLushort))IntGetProcAddress("glSecondaryColor3usEXT");
	if(!_ptrc_glSecondaryColor3usEXT) numFailed++;
	_ptrc_glSecondaryColor3usvEXT = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glSecondaryColor3usvEXT");
	if(!_ptrc_glSecondaryColor3usvEXT) numFailed++;
	_ptrc_glSecondaryColorPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glSecondaryColorPointerEXT");
	if(!_ptrc_glSecondaryColorPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveProgramEXT)(GLuint program) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramEXT)(GLenum type, const GLchar * string) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseShaderProgramEXT)(GLenum type, GLuint program) = NULL;

static int Load_EXT_separate_shader_objects(void)
{
	int numFailed = 0;
	_ptrc_glActiveProgramEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glActiveProgramEXT");
	if(!_ptrc_glActiveProgramEXT) numFailed++;
	_ptrc_glCreateShaderProgramEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, const GLchar *))IntGetProcAddress("glCreateShaderProgramEXT");
	if(!_ptrc_glCreateShaderProgramEXT) numFailed++;
	_ptrc_glUseShaderProgramEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glUseShaderProgramEXT");
	if(!_ptrc_glUseShaderProgramEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextureEXT)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierEXT)(GLbitfield barriers) = NULL;

static int Load_EXT_shader_image_load_store(void)
{
	int numFailed = 0;
	_ptrc_glBindImageTextureEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint))IntGetProcAddress("glBindImageTextureEXT");
	if(!_ptrc_glBindImageTextureEXT) numFailed++;
	_ptrc_glMemoryBarrierEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrierEXT");
	if(!_ptrc_glMemoryBarrierEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveStencilFaceEXT)(GLenum face) = NULL;

static int Load_EXT_stencil_two_side(void)
{
	int numFailed = 0;
	_ptrc_glActiveStencilFaceEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveStencilFaceEXT");
	if(!_ptrc_glActiveStencilFaceEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DEXT)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3DEXT)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;

static int Load_EXT_texture3D(void)
{
	int numFailed = 0;
	_ptrc_glTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTexImage3DEXT");
	if(!_ptrc_glTexImage3DEXT) numFailed++;
	_ptrc_glTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTexSubImage3DEXT");
	if(!_ptrc_glTexSubImage3DEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerEXT)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;

static int Load_EXT_texture_array(void)
{
	int numFailed = 0;
	_ptrc_glFramebufferTextureLayerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayerEXT");
	if(!_ptrc_glFramebufferTextureLayerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferEXT)(GLenum target, GLenum internalformat, GLuint buffer) = NULL;

static int Load_EXT_texture_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glTexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBufferEXT");
	if(!_ptrc_glTexBufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearColorIiEXT)(GLint red, GLint green, GLint blue, GLint alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearColorIuiEXT)(GLuint red, GLuint green, GLuint blue, GLuint alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIivEXT)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuivEXT)(GLenum target, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIivEXT)(GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuivEXT)(GLenum target, GLenum pname, const GLuint * params) = NULL;

static int Load_EXT_texture_integer(void)
{
	int numFailed = 0;
	_ptrc_glClearColorIiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glClearColorIiEXT");
	if(!_ptrc_glClearColorIiEXT) numFailed++;
	_ptrc_glClearColorIuiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glClearColorIuiEXT");
	if(!_ptrc_glClearColorIuiEXT) numFailed++;
	_ptrc_glGetTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameterIivEXT");
	if(!_ptrc_glGetTexParameterIivEXT) numFailed++;
	_ptrc_glGetTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTexParameterIuivEXT");
	if(!_ptrc_glGetTexParameterIuivEXT) numFailed++;
	_ptrc_glTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameterIivEXT");
	if(!_ptrc_glTexParameterIivEXT) numFailed++;
	_ptrc_glTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glTexParameterIuivEXT");
	if(!_ptrc_glTexParameterIuivEXT) numFailed++;
	return numFailed;
}

GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResidentEXT)(GLsizei n, const GLuint * textures, GLboolean * residences) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindTextureEXT)(GLenum target, GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTexturesEXT)(GLsizei n, const GLuint * textures) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTexturesEXT)(GLsizei n, GLuint * textures) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureEXT)(GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesEXT)(GLsizei n, const GLuint * textures, const GLclampf * priorities) = NULL;

static int Load_EXT_texture_object(void)
{
	int numFailed = 0;
	_ptrc_glAreTexturesResidentEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLboolean *))IntGetProcAddress("glAreTexturesResidentEXT");
	if(!_ptrc_glAreTexturesResidentEXT) numFailed++;
	_ptrc_glBindTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTextureEXT");
	if(!_ptrc_glBindTextureEXT) numFailed++;
	_ptrc_glDeleteTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTexturesEXT");
	if(!_ptrc_glDeleteTexturesEXT) numFailed++;
	_ptrc_glGenTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTexturesEXT");
	if(!_ptrc_glGenTexturesEXT) numFailed++;
	_ptrc_glIsTextureEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTextureEXT");
	if(!_ptrc_glIsTextureEXT) numFailed++;
	_ptrc_glPrioritizeTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, const GLclampf *))IntGetProcAddress("glPrioritizeTexturesEXT");
	if(!_ptrc_glPrioritizeTexturesEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64vEXT)(GLuint id, GLenum pname, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64vEXT)(GLuint id, GLenum pname, GLuint64 * params) = NULL;

static int Load_EXT_timer_query(void)
{
	int numFailed = 0;
	_ptrc_glGetQueryObjecti64vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64vEXT");
	if(!_ptrc_glGetQueryObjecti64vEXT) numFailed++;
	_ptrc_glGetQueryObjectui64vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64vEXT");
	if(!_ptrc_glGetQueryObjectui64vEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glArrayElementEXT)(GLint i) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysEXT)(GLenum mode, GLint first, GLsizei count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerEXT)(GLsizei stride, GLsizei count, const GLboolean * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointervEXT)(GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer) = NULL;

static int Load_EXT_vertex_array(void)
{
	int numFailed = 0;
	_ptrc_glArrayElementEXT = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glArrayElementEXT");
	if(!_ptrc_glArrayElementEXT) numFailed++;
	_ptrc_glColorPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const void *))IntGetProcAddress("glColorPointerEXT");
	if(!_ptrc_glColorPointerEXT) numFailed++;
	_ptrc_glDrawArraysEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei))IntGetProcAddress("glDrawArraysEXT");
	if(!_ptrc_glDrawArraysEXT) numFailed++;
	_ptrc_glEdgeFlagPointerEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLsizei, const GLboolean *))IntGetProcAddress("glEdgeFlagPointerEXT");
	if(!_ptrc_glEdgeFlagPointerEXT) numFailed++;
	_ptrc_glGetPointervEXT = (void (CODEGEN_FUNCPTR *)(GLenum, void **))IntGetProcAddress("glGetPointervEXT");
	if(!_ptrc_glGetPointervEXT) numFailed++;
	_ptrc_glIndexPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, const void *))IntGetProcAddress("glIndexPointerEXT");
	if(!_ptrc_glIndexPointerEXT) numFailed++;
	_ptrc_glNormalPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, const void *))IntGetProcAddress("glNormalPointerEXT");
	if(!_ptrc_glNormalPointerEXT) numFailed++;
	_ptrc_glTexCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const void *))IntGetProcAddress("glTexCoordPointerEXT");
	if(!_ptrc_glTexCoordPointerEXT) numFailed++;
	_ptrc_glVertexPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const void *))IntGetProcAddress("glVertexPointerEXT");
	if(!_ptrc_glVertexPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdvEXT)(GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dEXT)(GLuint index, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dvEXT)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dEXT)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dvEXT)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dvEXT)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dvEXT)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointerEXT)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;

static int Load_EXT_vertex_attrib_64bit(void)
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLdvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdvEXT");
	if(!_ptrc_glGetVertexAttribLdvEXT) numFailed++;
	_ptrc_glVertexAttribL1dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1dEXT");
	if(!_ptrc_glVertexAttribL1dEXT) numFailed++;
	_ptrc_glVertexAttribL1dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dvEXT");
	if(!_ptrc_glVertexAttribL1dvEXT) numFailed++;
	_ptrc_glVertexAttribL2dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2dEXT");
	if(!_ptrc_glVertexAttribL2dEXT) numFailed++;
	_ptrc_glVertexAttribL2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dvEXT");
	if(!_ptrc_glVertexAttribL2dvEXT) numFailed++;
	_ptrc_glVertexAttribL3dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3dEXT");
	if(!_ptrc_glVertexAttribL3dEXT) numFailed++;
	_ptrc_glVertexAttribL3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dvEXT");
	if(!_ptrc_glVertexAttribL3dvEXT) numFailed++;
	_ptrc_glVertexAttribL4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4dEXT");
	if(!_ptrc_glVertexAttribL4dEXT) numFailed++;
	_ptrc_glVertexAttribL4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dvEXT");
	if(!_ptrc_glVertexAttribL4dvEXT) numFailed++;
	_ptrc_glVertexAttribLPointerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glVertexAttribLPointerEXT");
	if(!_ptrc_glVertexAttribLPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC callback, const void * userParam) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void * ptr, GLsizei length, const GLchar * label) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar * message) = NULL;

static int Load_KHR_debug(void)
{
	int numFailed = 0;
	_ptrc_glDebugMessageCallback = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROC, const void *))IntGetProcAddress("glDebugMessageCallback");
	if(!_ptrc_glDebugMessageCallback) numFailed++;
	_ptrc_glDebugMessageControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControl");
	if(!_ptrc_glDebugMessageControl) numFailed++;
	_ptrc_glDebugMessageInsert = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsert");
	if(!_ptrc_glDebugMessageInsert) numFailed++;
	_ptrc_glGetDebugMessageLog = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLog");
	if(!_ptrc_glGetDebugMessageLog) numFailed++;
	_ptrc_glGetObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectLabel");
	if(!_ptrc_glGetObjectLabel) numFailed++;
	_ptrc_glGetObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectPtrLabel");
	if(!_ptrc_glGetObjectPtrLabel) numFailed++;
	_ptrc_glGetPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, void **))IntGetProcAddress("glGetPointerv");
	if(!_ptrc_glGetPointerv) numFailed++;
	_ptrc_glObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glObjectLabel");
	if(!_ptrc_glObjectLabel) numFailed++;
	_ptrc_glObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, const GLchar *))IntGetProcAddress("glObjectPtrLabel");
	if(!_ptrc_glObjectPtrLabel) numFailed++;
	_ptrc_glPopDebugGroup = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPopDebugGroup");
	if(!_ptrc_glPopDebugGroup) numFailed++;
	_ptrc_glPushDebugGroup = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glPushDebugGroup");
	if(!_ptrc_glPushDebugGroup) numFailed++;
	return numFailed;
}

GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatus)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) = NULL;

static int Load_KHR_robustness(void)
{
	int numFailed = 0;
	_ptrc_glGetGraphicsResetStatus = (GLenum (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glGetGraphicsResetStatus");
	if(!_ptrc_glGetGraphicsResetStatus) numFailed++;
	_ptrc_glGetnUniformfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLfloat *))IntGetProcAddress("glGetnUniformfv");
	if(!_ptrc_glGetnUniformfv) numFailed++;
	_ptrc_glGetnUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLint *))IntGetProcAddress("glGetnUniformiv");
	if(!_ptrc_glGetnUniformiv) numFailed++;
	_ptrc_glGetnUniformuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLuint *))IntGetProcAddress("glGetnUniformuiv");
	if(!_ptrc_glGetnUniformuiv) numFailed++;
	_ptrc_glReadnPixels = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glReadnPixels");
	if(!_ptrc_glReadnPixels) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessNV)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessNV)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) = NULL;

static int Load_NV_bindless_multi_draw_indirect(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectBindlessNV = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawArraysIndirectBindlessNV");
	if(!_ptrc_glMultiDrawArraysIndirectBindlessNV) numFailed++;
	_ptrc_glMultiDrawElementsIndirectBindlessNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawElementsIndirectBindlessNV");
	if(!_ptrc_glMultiDrawElementsIndirectBindlessNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessCountNV)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessCountNV)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) = NULL;

static int Load_NV_bindless_multi_draw_indirect_count(void)
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectBindlessCountNV = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawArraysIndirectBindlessCountNV");
	if(!_ptrc_glMultiDrawArraysIndirectBindlessCountNV) numFailed++;
	_ptrc_glMultiDrawElementsIndirectBindlessCountNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawElementsIndirectBindlessCountNV");
	if(!_ptrc_glMultiDrawElementsIndirectBindlessCountNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierNV)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendParameteriNV)(GLenum pname, GLint value) = NULL;

static int Load_NV_blend_equation_advanced(void)
{
	int numFailed = 0;
	_ptrc_glBlendBarrierNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glBlendBarrierNV");
	if(!_ptrc_glBlendBarrierNV) numFailed++;
	_ptrc_glBlendParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glBlendParameteriNV");
	if(!_ptrc_glBlendParameteriNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCallCommandListNV)(GLuint list) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCommandListSegmentsNV)(GLuint list, GLuint segments) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompileCommandListNV)(GLuint list) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateCommandListsNV)(GLsizei n, GLuint * lists) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCreateStatesNV)(GLsizei n, GLuint * states) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteCommandListsNV)(GLsizei n, const GLuint * lists) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteStatesNV)(GLsizei n, const GLuint * states) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsAddressNV)(GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsNV)(GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsStatesAddressNV)(const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsStatesNV)(GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetCommandHeaderNV)(GLenum tokenID, GLuint size) = NULL;
GLushort (CODEGEN_FUNCPTR *_ptrc_glGetStageIndexNV)(GLenum shadertype) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsCommandListNV)(GLuint list) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsStateNV)(GLuint state) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListDrawCommandsStatesClientNV)(GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStateCaptureNV)(GLuint state, GLenum mode) = NULL;

static int Load_NV_command_list(void)
{
	int numFailed = 0;
	_ptrc_glCallCommandListNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glCallCommandListNV");
	if(!_ptrc_glCallCommandListNV) numFailed++;
	_ptrc_glCommandListSegmentsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glCommandListSegmentsNV");
	if(!_ptrc_glCommandListSegmentsNV) numFailed++;
	_ptrc_glCompileCommandListNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glCompileCommandListNV");
	if(!_ptrc_glCompileCommandListNV) numFailed++;
	_ptrc_glCreateCommandListsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateCommandListsNV");
	if(!_ptrc_glCreateCommandListsNV) numFailed++;
	_ptrc_glCreateStatesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateStatesNV");
	if(!_ptrc_glCreateStatesNV) numFailed++;
	_ptrc_glDeleteCommandListsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteCommandListsNV");
	if(!_ptrc_glDeleteCommandListsNV) numFailed++;
	_ptrc_glDeleteStatesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteStatesNV");
	if(!_ptrc_glDeleteStatesNV) numFailed++;
	_ptrc_glDrawCommandsAddressNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint64 *, const GLsizei *, GLuint))IntGetProcAddress("glDrawCommandsAddressNV");
	if(!_ptrc_glDrawCommandsAddressNV) numFailed++;
	_ptrc_glDrawCommandsNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLintptr *, const GLsizei *, GLuint))IntGetProcAddress("glDrawCommandsNV");
	if(!_ptrc_glDrawCommandsNV) numFailed++;
	_ptrc_glDrawCommandsStatesAddressNV = (void (CODEGEN_FUNCPTR *)(const GLuint64 *, const GLsizei *, const GLuint *, const GLuint *, GLuint))IntGetProcAddress("glDrawCommandsStatesAddressNV");
	if(!_ptrc_glDrawCommandsStatesAddressNV) numFailed++;
	_ptrc_glDrawCommandsStatesNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLintptr *, const GLsizei *, const GLuint *, const GLuint *, GLuint))IntGetProcAddress("glDrawCommandsStatesNV");
	if(!_ptrc_glDrawCommandsStatesNV) numFailed++;
	_ptrc_glGetCommandHeaderNV = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glGetCommandHeaderNV");
	if(!_ptrc_glGetCommandHeaderNV) numFailed++;
	_ptrc_glGetStageIndexNV = (GLushort (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGetStageIndexNV");
	if(!_ptrc_glGetStageIndexNV) numFailed++;
	_ptrc_glIsCommandListNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsCommandListNV");
	if(!_ptrc_glIsCommandListNV) numFailed++;
	_ptrc_glIsStateNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsStateNV");
	if(!_ptrc_glIsStateNV) numFailed++;
	_ptrc_glListDrawCommandsStatesClientNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const void **, const GLsizei *, const GLuint *, const GLuint *, GLuint))IntGetProcAddress("glListDrawCommandsStatesClientNV");
	if(!_ptrc_glListDrawCommandsStatesClientNV) numFailed++;
	_ptrc_glStateCaptureNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glStateCaptureNV");
	if(!_ptrc_glStateCaptureNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNV)(GLuint id, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNV)(void) = NULL;

static int Load_NV_conditional_render(void)
{
	int numFailed = 0;
	_ptrc_glBeginConditionalRenderNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBeginConditionalRenderNV");
	if(!_ptrc_glBeginConditionalRenderNV) numFailed++;
	_ptrc_glEndConditionalRenderNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndConditionalRenderNV");
	if(!_ptrc_glEndConditionalRenderNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubDataNV)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) = NULL;

static int Load_NV_copy_image(void)
{
	int numFailed = 0;
	_ptrc_glCopyImageSubDataNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubDataNV");
	if(!_ptrc_glCopyImageSubDataNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearDepthdNV)(GLdouble depth) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsdNV)(GLdouble zmin, GLdouble zmax) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangedNV)(GLdouble zNear, GLdouble zFar) = NULL;

static int Load_NV_depth_buffer_float(void)
{
	int numFailed = 0;
	_ptrc_glClearDepthdNV = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glClearDepthdNV");
	if(!_ptrc_glClearDepthdNV) numFailed++;
	_ptrc_glDepthBoundsdNV = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthBoundsdNV");
	if(!_ptrc_glDepthBoundsdNV) numFailed++;
	_ptrc_glDepthRangedNV = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthRangedNV");
	if(!_ptrc_glDepthRangedNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawTextureNV)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) = NULL;

static int Load_NV_draw_texture(void)
{
	int numFailed = 0;
	_ptrc_glDrawTextureNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glDrawTextureNV");
	if(!_ptrc_glDrawTextureNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefvNV)(GLenum pname, GLuint index, GLfloat * val) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskIndexedNV)(GLuint index, GLbitfield mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexRenderbufferNV)(GLenum target, GLuint renderbuffer) = NULL;

static int Load_NV_explicit_multisample(void)
{
	int numFailed = 0;
	_ptrc_glGetMultisamplefvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefvNV");
	if(!_ptrc_glGetMultisamplefvNV) numFailed++;
	_ptrc_glSampleMaskIndexedNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaskIndexedNV");
	if(!_ptrc_glSampleMaskIndexedNV) numFailed++;
	_ptrc_glTexRenderbufferNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexRenderbufferNV");
	if(!_ptrc_glTexRenderbufferNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesNV)(GLsizei n, const GLuint * fences) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceNV)(GLuint fence) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFencesNV)(GLsizei n, GLuint * fences) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFenceivNV)(GLuint fence, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceNV)(GLuint fence) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetFenceNV)(GLuint fence, GLenum condition) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceNV)(GLuint fence) = NULL;

static int Load_NV_fence(void)
{
	int numFailed = 0;
	_ptrc_glDeleteFencesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFencesNV");
	if(!_ptrc_glDeleteFencesNV) numFailed++;
	_ptrc_glFinishFenceNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glFinishFenceNV");
	if(!_ptrc_glFinishFenceNV) numFailed++;
	_ptrc_glGenFencesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFencesNV");
	if(!_ptrc_glGenFencesNV) numFailed++;
	_ptrc_glGetFenceivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetFenceivNV");
	if(!_ptrc_glGetFenceivNV) numFailed++;
	_ptrc_glIsFenceNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFenceNV");
	if(!_ptrc_glIsFenceNV) numFailed++;
	_ptrc_glSetFenceNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glSetFenceNV");
	if(!_ptrc_glSetFenceNV) numFailed++;
	_ptrc_glTestFenceNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glTestFenceNV");
	if(!_ptrc_glTestFenceNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterdvNV)(GLuint id, GLsizei len, const GLubyte * name, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterfvNV)(GLuint id, GLsizei len, const GLubyte * name, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dNV)(GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dvNV)(GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fNV)(GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fvNV)(GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v) = NULL;

static int Load_NV_fragment_program(void)
{
	int numFailed = 0;
	_ptrc_glGetProgramNamedParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLdouble *))IntGetProcAddress("glGetProgramNamedParameterdvNV");
	if(!_ptrc_glGetProgramNamedParameterdvNV) numFailed++;
	_ptrc_glGetProgramNamedParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLfloat *))IntGetProcAddress("glGetProgramNamedParameterfvNV");
	if(!_ptrc_glGetProgramNamedParameterfvNV) numFailed++;
	_ptrc_glProgramNamedParameter4dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramNamedParameter4dNV");
	if(!_ptrc_glProgramNamedParameter4dNV) numFailed++;
	_ptrc_glProgramNamedParameter4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, const GLdouble *))IntGetProcAddress("glProgramNamedParameter4dvNV");
	if(!_ptrc_glProgramNamedParameter4dvNV) numFailed++;
	_ptrc_glProgramNamedParameter4fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramNamedParameter4fNV");
	if(!_ptrc_glProgramNamedParameter4fNV) numFailed++;
	_ptrc_glProgramNamedParameter4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, const GLfloat *))IntGetProcAddress("glProgramNamedParameter4fvNV");
	if(!_ptrc_glProgramNamedParameter4fvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;

static int Load_NV_framebuffer_multisample_coverage(void)
{
	int numFailed = 0;
	_ptrc_glRenderbufferStorageMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisampleCoverageNV");
	if(!_ptrc_glRenderbufferStorageMultisampleCoverageNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIivNV)(GLenum target, GLuint index, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIuivNV)(GLenum target, GLuint index, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIivNV)(GLenum target, GLuint index, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIuivNV)(GLenum target, GLuint index, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4ivNV)(GLenum target, GLuint index, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uivNV)(GLenum target, GLuint index, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4ivNV)(GLenum target, GLuint index, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uivNV)(GLenum target, GLuint index, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint * params) = NULL;

static int Load_NV_gpu_program4(void)
{
	int numFailed = 0;
	_ptrc_glGetProgramEnvParameterIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetProgramEnvParameterIivNV");
	if(!_ptrc_glGetProgramEnvParameterIivNV) numFailed++;
	_ptrc_glGetProgramEnvParameterIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramEnvParameterIuivNV");
	if(!_ptrc_glGetProgramEnvParameterIuivNV) numFailed++;
	_ptrc_glGetProgramLocalParameterIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetProgramLocalParameterIivNV");
	if(!_ptrc_glGetProgramLocalParameterIivNV) numFailed++;
	_ptrc_glGetProgramLocalParameterIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramLocalParameterIuivNV");
	if(!_ptrc_glGetProgramLocalParameterIuivNV) numFailed++;
	_ptrc_glProgramEnvParameterI4iNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramEnvParameterI4iNV");
	if(!_ptrc_glProgramEnvParameterI4iNV) numFailed++;
	_ptrc_glProgramEnvParameterI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLint *))IntGetProcAddress("glProgramEnvParameterI4ivNV");
	if(!_ptrc_glProgramEnvParameterI4ivNV) numFailed++;
	_ptrc_glProgramEnvParameterI4uiNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramEnvParameterI4uiNV");
	if(!_ptrc_glProgramEnvParameterI4uiNV) numFailed++;
	_ptrc_glProgramEnvParameterI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLuint *))IntGetProcAddress("glProgramEnvParameterI4uivNV");
	if(!_ptrc_glProgramEnvParameterI4uivNV) numFailed++;
	_ptrc_glProgramEnvParametersI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramEnvParametersI4ivNV");
	if(!_ptrc_glProgramEnvParametersI4ivNV) numFailed++;
	_ptrc_glProgramEnvParametersI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramEnvParametersI4uivNV");
	if(!_ptrc_glProgramEnvParametersI4uivNV) numFailed++;
	_ptrc_glProgramLocalParameterI4iNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramLocalParameterI4iNV");
	if(!_ptrc_glProgramLocalParameterI4iNV) numFailed++;
	_ptrc_glProgramLocalParameterI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLint *))IntGetProcAddress("glProgramLocalParameterI4ivNV");
	if(!_ptrc_glProgramLocalParameterI4ivNV) numFailed++;
	_ptrc_glProgramLocalParameterI4uiNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramLocalParameterI4uiNV");
	if(!_ptrc_glProgramLocalParameterI4uiNV) numFailed++;
	_ptrc_glProgramLocalParameterI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLuint *))IntGetProcAddress("glProgramLocalParameterI4uivNV");
	if(!_ptrc_glProgramLocalParameterI4uivNV) numFailed++;
	_ptrc_glProgramLocalParametersI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramLocalParametersI4ivNV");
	if(!_ptrc_glProgramLocalParametersI4ivNV) numFailed++;
	_ptrc_glProgramLocalParametersI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramLocalParametersI4uivNV");
	if(!_ptrc_glProgramLocalParametersI4uivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformatSampleivNV)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint * params) = NULL;

static int Load_NV_internalformat_sample_query(void)
{
	int numFailed = 0;
	_ptrc_glGetInternalformatSampleivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetInternalformatSampleivNV");
	if(!_ptrc_glGetInternalformatSampleivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramSubroutineParameteruivNV)(GLenum target, GLuint index, GLuint * param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramSubroutineParametersuivNV)(GLenum target, GLsizei count, const GLuint * params) = NULL;

static int Load_NV_gpu_program5(void)
{
	int numFailed = 0;
	_ptrc_glGetProgramSubroutineParameteruivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramSubroutineParameteruivNV");
	if(!_ptrc_glGetProgramSubroutineParameteruivNV) numFailed++;
	_ptrc_glProgramSubroutineParametersuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glProgramSubroutineParametersuivNV");
	if(!_ptrc_glProgramSubroutineParametersuivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vNV)(GLuint program, GLint location, GLint64EXT * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64NV)(GLuint program, GLint location, GLint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64NV)(GLuint program, GLint location, GLuint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64NV)(GLint location, GLint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vNV)(GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64NV)(GLint location, GLuint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64NV)(GLint location, GLint64EXT x, GLint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vNV)(GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vNV)(GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vNV)(GLint location, GLsizei count, const GLint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value) = NULL;

static int Load_NV_gpu_shader5(void)
{
	int numFailed = 0;
	_ptrc_glGetUniformi64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT *))IntGetProcAddress("glGetUniformi64vNV");
	if(!_ptrc_glGetUniformi64vNV) numFailed++;
	_ptrc_glProgramUniform1i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT))IntGetProcAddress("glProgramUniform1i64NV");
	if(!_ptrc_glProgramUniform1i64NV) numFailed++;
	_ptrc_glProgramUniform1i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform1i64vNV");
	if(!_ptrc_glProgramUniform1i64vNV) numFailed++;
	_ptrc_glProgramUniform1ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT))IntGetProcAddress("glProgramUniform1ui64NV");
	if(!_ptrc_glProgramUniform1ui64NV) numFailed++;
	_ptrc_glProgramUniform1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform1ui64vNV");
	if(!_ptrc_glProgramUniform1ui64vNV) numFailed++;
	_ptrc_glProgramUniform2i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform2i64NV");
	if(!_ptrc_glProgramUniform2i64NV) numFailed++;
	_ptrc_glProgramUniform2i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform2i64vNV");
	if(!_ptrc_glProgramUniform2i64vNV) numFailed++;
	_ptrc_glProgramUniform2ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform2ui64NV");
	if(!_ptrc_glProgramUniform2ui64NV) numFailed++;
	_ptrc_glProgramUniform2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform2ui64vNV");
	if(!_ptrc_glProgramUniform2ui64vNV) numFailed++;
	_ptrc_glProgramUniform3i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform3i64NV");
	if(!_ptrc_glProgramUniform3i64NV) numFailed++;
	_ptrc_glProgramUniform3i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform3i64vNV");
	if(!_ptrc_glProgramUniform3i64vNV) numFailed++;
	_ptrc_glProgramUniform3ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform3ui64NV");
	if(!_ptrc_glProgramUniform3ui64NV) numFailed++;
	_ptrc_glProgramUniform3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform3ui64vNV");
	if(!_ptrc_glProgramUniform3ui64vNV) numFailed++;
	_ptrc_glProgramUniform4i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform4i64NV");
	if(!_ptrc_glProgramUniform4i64NV) numFailed++;
	_ptrc_glProgramUniform4i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform4i64vNV");
	if(!_ptrc_glProgramUniform4i64vNV) numFailed++;
	_ptrc_glProgramUniform4ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform4ui64NV");
	if(!_ptrc_glProgramUniform4ui64NV) numFailed++;
	_ptrc_glProgramUniform4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform4ui64vNV");
	if(!_ptrc_glProgramUniform4ui64vNV) numFailed++;
	_ptrc_glUniform1i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT))IntGetProcAddress("glUniform1i64NV");
	if(!_ptrc_glUniform1i64NV) numFailed++;
	_ptrc_glUniform1i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform1i64vNV");
	if(!_ptrc_glUniform1i64vNV) numFailed++;
	_ptrc_glUniform1ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT))IntGetProcAddress("glUniform1ui64NV");
	if(!_ptrc_glUniform1ui64NV) numFailed++;
	_ptrc_glUniform1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform1ui64vNV");
	if(!_ptrc_glUniform1ui64vNV) numFailed++;
	_ptrc_glUniform2i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform2i64NV");
	if(!_ptrc_glUniform2i64NV) numFailed++;
	_ptrc_glUniform2i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform2i64vNV");
	if(!_ptrc_glUniform2i64vNV) numFailed++;
	_ptrc_glUniform2ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform2ui64NV");
	if(!_ptrc_glUniform2ui64NV) numFailed++;
	_ptrc_glUniform2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform2ui64vNV");
	if(!_ptrc_glUniform2ui64vNV) numFailed++;
	_ptrc_glUniform3i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform3i64NV");
	if(!_ptrc_glUniform3i64NV) numFailed++;
	_ptrc_glUniform3i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform3i64vNV");
	if(!_ptrc_glUniform3i64vNV) numFailed++;
	_ptrc_glUniform3ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform3ui64NV");
	if(!_ptrc_glUniform3ui64NV) numFailed++;
	_ptrc_glUniform3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform3ui64vNV");
	if(!_ptrc_glUniform3ui64vNV) numFailed++;
	_ptrc_glUniform4i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform4i64NV");
	if(!_ptrc_glUniform4i64NV) numFailed++;
	_ptrc_glUniform4i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform4i64vNV");
	if(!_ptrc_glUniform4i64vNV) numFailed++;
	_ptrc_glUniform4ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform4ui64NV");
	if(!_ptrc_glUniform4ui64NV) numFailed++;
	_ptrc_glUniform4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform4ui64vNV");
	if(!_ptrc_glUniform4ui64vNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhNV)(GLhalfNV fog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhvNV)(const GLhalfNV * fog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hNV)(GLenum target, GLhalfNV s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hvNV)(GLenum target, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hNV)(GLenum target, GLhalfNV s, GLhalfNV t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hvNV)(GLenum target, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hvNV)(GLenum target, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hvNV)(GLenum target, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3hNV)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hNV)(GLhalfNV s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hNV)(GLhalfNV s, GLhalfNV t) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2hNV)(GLhalfNV x, GLhalfNV y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4hvNV)(const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hNV)(GLuint index, GLhalfNV x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hvNV)(GLuint index, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hNV)(GLuint index, GLhalfNV x, GLhalfNV y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hvNV)(GLuint index, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hvNV)(GLuint index, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hvNV)(GLuint index, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1hvNV)(GLuint index, GLsizei n, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2hvNV)(GLuint index, GLsizei n, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3hvNV)(GLuint index, GLsizei n, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4hvNV)(GLuint index, GLsizei n, const GLhalfNV * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthNV)(GLhalfNV weight) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthvNV)(const GLhalfNV * weight) = NULL;

static int Load_NV_half_float(void)
{
	int numFailed = 0;
	_ptrc_glColor3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glColor3hNV");
	if(!_ptrc_glColor3hNV) numFailed++;
	_ptrc_glColor3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glColor3hvNV");
	if(!_ptrc_glColor3hvNV) numFailed++;
	_ptrc_glColor4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glColor4hNV");
	if(!_ptrc_glColor4hNV) numFailed++;
	_ptrc_glColor4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glColor4hvNV");
	if(!_ptrc_glColor4hvNV) numFailed++;
	_ptrc_glFogCoordhNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glFogCoordhNV");
	if(!_ptrc_glFogCoordhNV) numFailed++;
	_ptrc_glFogCoordhvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glFogCoordhvNV");
	if(!_ptrc_glFogCoordhvNV) numFailed++;
	_ptrc_glMultiTexCoord1hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV))IntGetProcAddress("glMultiTexCoord1hNV");
	if(!_ptrc_glMultiTexCoord1hNV) numFailed++;
	_ptrc_glMultiTexCoord1hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord1hvNV");
	if(!_ptrc_glMultiTexCoord1hvNV) numFailed++;
	_ptrc_glMultiTexCoord2hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord2hNV");
	if(!_ptrc_glMultiTexCoord2hNV) numFailed++;
	_ptrc_glMultiTexCoord2hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord2hvNV");
	if(!_ptrc_glMultiTexCoord2hvNV) numFailed++;
	_ptrc_glMultiTexCoord3hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord3hNV");
	if(!_ptrc_glMultiTexCoord3hNV) numFailed++;
	_ptrc_glMultiTexCoord3hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord3hvNV");
	if(!_ptrc_glMultiTexCoord3hvNV) numFailed++;
	_ptrc_glMultiTexCoord4hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord4hNV");
	if(!_ptrc_glMultiTexCoord4hNV) numFailed++;
	_ptrc_glMultiTexCoord4hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord4hvNV");
	if(!_ptrc_glMultiTexCoord4hvNV) numFailed++;
	_ptrc_glNormal3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glNormal3hNV");
	if(!_ptrc_glNormal3hNV) numFailed++;
	_ptrc_glNormal3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glNormal3hvNV");
	if(!_ptrc_glNormal3hvNV) numFailed++;
	_ptrc_glSecondaryColor3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glSecondaryColor3hNV");
	if(!_ptrc_glSecondaryColor3hNV) numFailed++;
	_ptrc_glSecondaryColor3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glSecondaryColor3hvNV");
	if(!_ptrc_glSecondaryColor3hvNV) numFailed++;
	_ptrc_glTexCoord1hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glTexCoord1hNV");
	if(!_ptrc_glTexCoord1hNV) numFailed++;
	_ptrc_glTexCoord1hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord1hvNV");
	if(!_ptrc_glTexCoord1hvNV) numFailed++;
	_ptrc_glTexCoord2hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord2hNV");
	if(!_ptrc_glTexCoord2hNV) numFailed++;
	_ptrc_glTexCoord2hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord2hvNV");
	if(!_ptrc_glTexCoord2hvNV) numFailed++;
	_ptrc_glTexCoord3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord3hNV");
	if(!_ptrc_glTexCoord3hNV) numFailed++;
	_ptrc_glTexCoord3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord3hvNV");
	if(!_ptrc_glTexCoord3hvNV) numFailed++;
	_ptrc_glTexCoord4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord4hNV");
	if(!_ptrc_glTexCoord4hNV) numFailed++;
	_ptrc_glTexCoord4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord4hvNV");
	if(!_ptrc_glTexCoord4hvNV) numFailed++;
	_ptrc_glVertex2hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex2hNV");
	if(!_ptrc_glVertex2hNV) numFailed++;
	_ptrc_glVertex2hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex2hvNV");
	if(!_ptrc_glVertex2hvNV) numFailed++;
	_ptrc_glVertex3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex3hNV");
	if(!_ptrc_glVertex3hNV) numFailed++;
	_ptrc_glVertex3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex3hvNV");
	if(!_ptrc_glVertex3hvNV) numFailed++;
	_ptrc_glVertex4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex4hNV");
	if(!_ptrc_glVertex4hNV) numFailed++;
	_ptrc_glVertex4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex4hvNV");
	if(!_ptrc_glVertex4hvNV) numFailed++;
	_ptrc_glVertexAttrib1hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV))IntGetProcAddress("glVertexAttrib1hNV");
	if(!_ptrc_glVertexAttrib1hNV) numFailed++;
	_ptrc_glVertexAttrib1hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib1hvNV");
	if(!_ptrc_glVertexAttrib1hvNV) numFailed++;
	_ptrc_glVertexAttrib2hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib2hNV");
	if(!_ptrc_glVertexAttrib2hNV) numFailed++;
	_ptrc_glVertexAttrib2hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib2hvNV");
	if(!_ptrc_glVertexAttrib2hvNV) numFailed++;
	_ptrc_glVertexAttrib3hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib3hNV");
	if(!_ptrc_glVertexAttrib3hNV) numFailed++;
	_ptrc_glVertexAttrib3hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib3hvNV");
	if(!_ptrc_glVertexAttrib3hvNV) numFailed++;
	_ptrc_glVertexAttrib4hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib4hNV");
	if(!_ptrc_glVertexAttrib4hNV) numFailed++;
	_ptrc_glVertexAttrib4hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib4hvNV");
	if(!_ptrc_glVertexAttrib4hvNV) numFailed++;
	_ptrc_glVertexAttribs1hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs1hvNV");
	if(!_ptrc_glVertexAttribs1hvNV) numFailed++;
	_ptrc_glVertexAttribs2hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs2hvNV");
	if(!_ptrc_glVertexAttribs2hvNV) numFailed++;
	_ptrc_glVertexAttribs3hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs3hvNV");
	if(!_ptrc_glVertexAttribs3hvNV) numFailed++;
	_ptrc_glVertexAttribs4hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs4hvNV");
	if(!_ptrc_glVertexAttribs4hvNV) numFailed++;
	_ptrc_glVertexWeighthNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glVertexWeighthNV");
	if(!_ptrc_glVertexWeighthNV) numFailed++;
	_ptrc_glVertexWeighthvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertexWeighthvNV");
	if(!_ptrc_glVertexWeighthvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginOcclusionQueryNV)(GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteOcclusionQueriesNV)(GLsizei n, const GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndOcclusionQueryNV)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenOcclusionQueriesNV)(GLsizei n, GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryivNV)(GLuint id, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryuivNV)(GLuint id, GLenum pname, GLuint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsOcclusionQueryNV)(GLuint id) = NULL;

static int Load_NV_occlusion_query(void)
{
	int numFailed = 0;
	_ptrc_glBeginOcclusionQueryNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginOcclusionQueryNV");
	if(!_ptrc_glBeginOcclusionQueryNV) numFailed++;
	_ptrc_glDeleteOcclusionQueriesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteOcclusionQueriesNV");
	if(!_ptrc_glDeleteOcclusionQueriesNV) numFailed++;
	_ptrc_glEndOcclusionQueryNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndOcclusionQueryNV");
	if(!_ptrc_glEndOcclusionQueryNV) numFailed++;
	_ptrc_glGenOcclusionQueriesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenOcclusionQueriesNV");
	if(!_ptrc_glGenOcclusionQueriesNV) numFailed++;
	_ptrc_glGetOcclusionQueryivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetOcclusionQueryivNV");
	if(!_ptrc_glGetOcclusionQueryivNV) numFailed++;
	_ptrc_glGetOcclusionQueryuivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetOcclusionQueryuivNV");
	if(!_ptrc_glGetOcclusionQueryuivNV) numFailed++;
	_ptrc_glIsOcclusionQueryNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsOcclusionQueryNV");
	if(!_ptrc_glIsOcclusionQueryNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIivNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIuivNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersfvNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat * params) = NULL;

static int Load_NV_parameter_buffer_object(void)
{
	int numFailed = 0;
	_ptrc_glProgramBufferParametersIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramBufferParametersIivNV");
	if(!_ptrc_glProgramBufferParametersIivNV) numFailed++;
	_ptrc_glProgramBufferParametersIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramBufferParametersIuivNV");
	if(!_ptrc_glProgramBufferParametersIuivNV) numFailed++;
	_ptrc_glProgramBufferParametersfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramBufferParametersfvNV");
	if(!_ptrc_glProgramBufferParametersfvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyPathNV)(GLuint resultPath, GLuint srcPath) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathNV)(GLuint path, GLenum coverMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathNV)(GLuint path, GLenum coverMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeletePathsNV)(GLuint path, GLsizei range) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenPathsNV)(GLsizei range) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenfvNV)(GLenum color, GLenum pname, GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenivNV)(GLenum color, GLenum pname, GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathCommandsNV)(GLuint path, GLubyte * commands) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathCoordsNV)(GLuint path, GLfloat * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathDashArrayNV)(GLuint path, GLfloat * dashArray) = NULL;
GLfloat (CODEGEN_FUNCPTR *_ptrc_glGetPathLengthNV)(GLuint path, GLsizei startSegment, GLsizei numSegments) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricRangeNV)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricsNV)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterfvNV)(GLuint path, GLenum pname, GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterivNV)(GLuint path, GLenum pname, GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathSpacingNV)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenfvNV)(GLenum texCoordSet, GLenum pname, GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenivNV)(GLenum texCoordSet, GLenum pname, GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourcefvNV)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInterpolatePathsNV)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPathNV)(GLuint path) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInFillPathNV)(GLuint path, GLuint mask, GLfloat x, GLfloat y) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInStrokePathNV)(GLuint path, GLfloat x, GLfloat y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoad3x2fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoad3x3fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTranspose3x3fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMult3x2fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMult3x3fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTranspose3x3fNV)(GLenum matrixMode, const GLfloat * m) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathColorGenNV)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat * coeffs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCommandsNV)(GLuint path, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCoordsNV)(GLuint path, GLsizei numCoords, GLenum coordType, const void * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCoverDepthFuncNV)(GLenum func) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathDashArrayNV)(GLuint path, GLsizei dashCount, const GLfloat * dashArray) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathFogGenNV)(GLenum genMode) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glPathGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glPathGlyphIndexRangeNV)(GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphRangeNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphsNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void * charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glPathMemoryGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void * fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfNV)(GLuint path, GLenum pname, GLfloat value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfvNV)(GLuint path, GLenum pname, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameteriNV)(GLuint path, GLenum pname, GLint value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterivNV)(GLuint path, GLenum pname, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStencilDepthOffsetNV)(GLfloat factor, GLfloat units) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStencilFuncNV)(GLenum func, GLint ref, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStringNV)(GLuint path, GLenum format, GLsizei length, const void * pathString) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathSubCommandsNV)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathSubCoordsNV)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void * coords) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathTexGenNV)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat * coeffs) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glPointAlongPathNV)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat * x, GLfloat * y, GLfloat * tangentX, GLfloat * tangentY) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramPathFragmentInputGenNV)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat * coeffs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathNV)(GLuint path, GLenum fillMode, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathNV)(GLuint path, GLint reference, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverFillPathNV)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverStrokePathNV)(GLuint path, GLint reference, GLuint mask, GLenum coverMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformPathNV)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat * transformValues) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightPathsNV)(GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights) = NULL;

static int Load_NV_path_rendering(void)
{
	int numFailed = 0;
	_ptrc_glCopyPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glCopyPathNV");
	if(!_ptrc_glCopyPathNV) numFailed++;
	_ptrc_glCoverFillPathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCoverFillPathInstancedNV");
	if(!_ptrc_glCoverFillPathInstancedNV) numFailed++;
	_ptrc_glCoverFillPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCoverFillPathNV");
	if(!_ptrc_glCoverFillPathNV) numFailed++;
	_ptrc_glCoverStrokePathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCoverStrokePathInstancedNV");
	if(!_ptrc_glCoverStrokePathInstancedNV) numFailed++;
	_ptrc_glCoverStrokePathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCoverStrokePathNV");
	if(!_ptrc_glCoverStrokePathNV) numFailed++;
	_ptrc_glDeletePathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei))IntGetProcAddress("glDeletePathsNV");
	if(!_ptrc_glDeletePathsNV) numFailed++;
	_ptrc_glGenPathsNV = (GLuint (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glGenPathsNV");
	if(!_ptrc_glGenPathsNV) numFailed++;
	_ptrc_glGetPathColorGenfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetPathColorGenfvNV");
	if(!_ptrc_glGetPathColorGenfvNV) numFailed++;
	_ptrc_glGetPathColorGenivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetPathColorGenivNV");
	if(!_ptrc_glGetPathColorGenivNV) numFailed++;
	_ptrc_glGetPathCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte *))IntGetProcAddress("glGetPathCommandsNV");
	if(!_ptrc_glGetPathCommandsNV) numFailed++;
	_ptrc_glGetPathCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat *))IntGetProcAddress("glGetPathCoordsNV");
	if(!_ptrc_glGetPathCoordsNV) numFailed++;
	_ptrc_glGetPathDashArrayNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat *))IntGetProcAddress("glGetPathDashArrayNV");
	if(!_ptrc_glGetPathDashArrayNV) numFailed++;
	_ptrc_glGetPathLengthNV = (GLfloat (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei))IntGetProcAddress("glGetPathLengthNV");
	if(!_ptrc_glGetPathLengthNV) numFailed++;
	_ptrc_glGetPathMetricRangeNV = (void (CODEGEN_FUNCPTR *)(GLbitfield, GLuint, GLsizei, GLsizei, GLfloat *))IntGetProcAddress("glGetPathMetricRangeNV");
	if(!_ptrc_glGetPathMetricRangeNV) numFailed++;
	_ptrc_glGetPathMetricsNV = (void (CODEGEN_FUNCPTR *)(GLbitfield, GLsizei, GLenum, const void *, GLuint, GLsizei, GLfloat *))IntGetProcAddress("glGetPathMetricsNV");
	if(!_ptrc_glGetPathMetricsNV) numFailed++;
	_ptrc_glGetPathParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetPathParameterfvNV");
	if(!_ptrc_glGetPathParameterfvNV) numFailed++;
	_ptrc_glGetPathParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetPathParameterivNV");
	if(!_ptrc_glGetPathParameterivNV) numFailed++;
	_ptrc_glGetPathSpacingNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLuint, GLfloat, GLfloat, GLenum, GLfloat *))IntGetProcAddress("glGetPathSpacingNV");
	if(!_ptrc_glGetPathSpacingNV) numFailed++;
	_ptrc_glGetPathTexGenfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetPathTexGenfvNV");
	if(!_ptrc_glGetPathTexGenfvNV) numFailed++;
	_ptrc_glGetPathTexGenivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetPathTexGenivNV");
	if(!_ptrc_glGetPathTexGenivNV) numFailed++;
	_ptrc_glGetProgramResourcefvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLfloat *))IntGetProcAddress("glGetProgramResourcefvNV");
	if(!_ptrc_glGetProgramResourcefvNV) numFailed++;
	_ptrc_glInterpolatePathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLfloat))IntGetProcAddress("glInterpolatePathsNV");
	if(!_ptrc_glInterpolatePathsNV) numFailed++;
	_ptrc_glIsPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsPathNV");
	if(!_ptrc_glIsPathNV) numFailed++;
	_ptrc_glIsPointInFillPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat))IntGetProcAddress("glIsPointInFillPathNV");
	if(!_ptrc_glIsPointInFillPathNV) numFailed++;
	_ptrc_glIsPointInStrokePathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glIsPointInStrokePathNV");
	if(!_ptrc_glIsPointInStrokePathNV) numFailed++;
	_ptrc_glMatrixLoad3x2fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoad3x2fNV");
	if(!_ptrc_glMatrixLoad3x2fNV) numFailed++;
	_ptrc_glMatrixLoad3x3fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoad3x3fNV");
	if(!_ptrc_glMatrixLoad3x3fNV) numFailed++;
	_ptrc_glMatrixLoadTranspose3x3fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoadTranspose3x3fNV");
	if(!_ptrc_glMatrixLoadTranspose3x3fNV) numFailed++;
	_ptrc_glMatrixMult3x2fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMult3x2fNV");
	if(!_ptrc_glMatrixMult3x2fNV) numFailed++;
	_ptrc_glMatrixMult3x3fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMult3x3fNV");
	if(!_ptrc_glMatrixMult3x3fNV) numFailed++;
	_ptrc_glMatrixMultTranspose3x3fNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMultTranspose3x3fNV");
	if(!_ptrc_glMatrixMultTranspose3x3fNV) numFailed++;
	_ptrc_glPathColorGenNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glPathColorGenNV");
	if(!_ptrc_glPathColorGenNV) numFailed++;
	_ptrc_glPathCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLsizei, GLenum, const void *))IntGetProcAddress("glPathCommandsNV");
	if(!_ptrc_glPathCommandsNV) numFailed++;
	_ptrc_glPathCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, const void *))IntGetProcAddress("glPathCoordsNV");
	if(!_ptrc_glPathCoordsNV) numFailed++;
	_ptrc_glPathCoverDepthFuncNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glPathCoverDepthFuncNV");
	if(!_ptrc_glPathCoverDepthFuncNV) numFailed++;
	_ptrc_glPathDashArrayNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glPathDashArrayNV");
	if(!_ptrc_glPathDashArrayNV) numFailed++;
	_ptrc_glPathFogGenNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glPathFogGenNV");
	if(!_ptrc_glPathFogGenNV) numFailed++;
	_ptrc_glPathGlyphIndexArrayNV = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum, const void *, GLbitfield, GLuint, GLsizei, GLuint, GLfloat))IntGetProcAddress("glPathGlyphIndexArrayNV");
	if(!_ptrc_glPathGlyphIndexArrayNV) numFailed++;
	_ptrc_glPathGlyphIndexRangeNV = (GLenum (CODEGEN_FUNCPTR *)(GLenum, const void *, GLbitfield, GLuint, GLfloat, GLuint))IntGetProcAddress("glPathGlyphIndexRangeNV");
	if(!_ptrc_glPathGlyphIndexRangeNV) numFailed++;
	_ptrc_glPathGlyphRangeNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const void *, GLbitfield, GLuint, GLsizei, GLenum, GLuint, GLfloat))IntGetProcAddress("glPathGlyphRangeNV");
	if(!_ptrc_glPathGlyphRangeNV) numFailed++;
	_ptrc_glPathGlyphsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const void *, GLbitfield, GLsizei, GLenum, const void *, GLenum, GLuint, GLfloat))IntGetProcAddress("glPathGlyphsNV");
	if(!_ptrc_glPathGlyphsNV) numFailed++;
	_ptrc_glPathMemoryGlyphIndexArrayNV = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizeiptr, const void *, GLsizei, GLuint, GLsizei, GLuint, GLfloat))IntGetProcAddress("glPathMemoryGlyphIndexArrayNV");
	if(!_ptrc_glPathMemoryGlyphIndexArrayNV) numFailed++;
	_ptrc_glPathParameterfNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glPathParameterfNV");
	if(!_ptrc_glPathParameterfNV) numFailed++;
	_ptrc_glPathParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glPathParameterfvNV");
	if(!_ptrc_glPathParameterfvNV) numFailed++;
	_ptrc_glPathParameteriNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glPathParameteriNV");
	if(!_ptrc_glPathParameteriNV) numFailed++;
	_ptrc_glPathParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glPathParameterivNV");
	if(!_ptrc_glPathParameterivNV) numFailed++;
	_ptrc_glPathStencilDepthOffsetNV = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPathStencilDepthOffsetNV");
	if(!_ptrc_glPathStencilDepthOffsetNV) numFailed++;
	_ptrc_glPathStencilFuncNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint))IntGetProcAddress("glPathStencilFuncNV");
	if(!_ptrc_glPathStencilFuncNV) numFailed++;
	_ptrc_glPathStringNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, const void *))IntGetProcAddress("glPathStringNV");
	if(!_ptrc_glPathStringNV) numFailed++;
	_ptrc_glPathSubCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLsizei, const GLubyte *, GLsizei, GLenum, const void *))IntGetProcAddress("glPathSubCommandsNV");
	if(!_ptrc_glPathSubCommandsNV) numFailed++;
	_ptrc_glPathSubCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLenum, const void *))IntGetProcAddress("glPathSubCoordsNV");
	if(!_ptrc_glPathSubCoordsNV) numFailed++;
	_ptrc_glPathTexGenNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, const GLfloat *))IntGetProcAddress("glPathTexGenNV");
	if(!_ptrc_glPathTexGenNV) numFailed++;
	_ptrc_glPointAlongPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLfloat, GLfloat *, GLfloat *, GLfloat *, GLfloat *))IntGetProcAddress("glPointAlongPathNV");
	if(!_ptrc_glPointAlongPathNV) numFailed++;
	_ptrc_glProgramPathFragmentInputGenNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLint, const GLfloat *))IntGetProcAddress("glProgramPathFragmentInputGenNV");
	if(!_ptrc_glProgramPathFragmentInputGenNV) numFailed++;
	_ptrc_glStencilFillPathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLenum, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glStencilFillPathInstancedNV");
	if(!_ptrc_glStencilFillPathInstancedNV) numFailed++;
	_ptrc_glStencilFillPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glStencilFillPathNV");
	if(!_ptrc_glStencilFillPathNV) numFailed++;
	_ptrc_glStencilStrokePathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glStencilStrokePathInstancedNV");
	if(!_ptrc_glStencilStrokePathInstancedNV) numFailed++;
	_ptrc_glStencilStrokePathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glStencilStrokePathNV");
	if(!_ptrc_glStencilStrokePathNV) numFailed++;
	_ptrc_glStencilThenCoverFillPathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLenum, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glStencilThenCoverFillPathInstancedNV");
	if(!_ptrc_glStencilThenCoverFillPathInstancedNV) numFailed++;
	_ptrc_glStencilThenCoverFillPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum))IntGetProcAddress("glStencilThenCoverFillPathNV");
	if(!_ptrc_glStencilThenCoverFillPathNV) numFailed++;
	_ptrc_glStencilThenCoverStrokePathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const void *, GLuint, GLint, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glStencilThenCoverStrokePathInstancedNV");
	if(!_ptrc_glStencilThenCoverStrokePathInstancedNV) numFailed++;
	_ptrc_glStencilThenCoverStrokePathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLenum))IntGetProcAddress("glStencilThenCoverStrokePathNV");
	if(!_ptrc_glStencilThenCoverStrokePathNV) numFailed++;
	_ptrc_glTransformPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glTransformPathNV");
	if(!_ptrc_glTransformPathNV) numFailed++;
	_ptrc_glWeightPathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLfloat *))IntGetProcAddress("glWeightPathsNV");
	if(!_ptrc_glWeightPathsNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushPixelDataRangeNV)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelDataRangeNV)(GLenum target, GLsizei length, const void * pointer) = NULL;

static int Load_NV_pixel_data_range(void)
{
	int numFailed = 0;
	_ptrc_glFlushPixelDataRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glFlushPixelDataRangeNV");
	if(!_ptrc_glFlushPixelDataRangeNV) numFailed++;
	_ptrc_glPixelDataRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const void *))IntGetProcAddress("glPixelDataRangeNV");
	if(!_ptrc_glPixelDataRangeNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriNV)(GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterivNV)(GLenum pname, const GLint * params) = NULL;

static int Load_NV_point_sprite(void)
{
	int numFailed = 0;
	_ptrc_glPointParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPointParameteriNV");
	if(!_ptrc_glPointParameteriNV) numFailed++;
	_ptrc_glPointParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glPointParameterivNV");
	if(!_ptrc_glPointParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndexNV)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartNV)(void) = NULL;

static int Load_NV_primitive_restart(void)
{
	int numFailed = 0;
	_ptrc_glPrimitiveRestartIndexNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glPrimitiveRestartIndexNV");
	if(!_ptrc_glPrimitiveRestartIndexNV) numFailed++;
	_ptrc_glPrimitiveRestartNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPrimitiveRestartNV");
	if(!_ptrc_glPrimitiveRestartNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCombinerInputNV)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerOutputNV)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfNV)(GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfvNV)(GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameteriNV)(GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterivNV)(GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinalCombinerInputNV)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterfvNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterivNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterfvNV)(GLenum stage, GLenum portion, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterivNV)(GLenum stage, GLenum portion, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterfvNV)(GLenum variable, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterivNV)(GLenum variable, GLenum pname, GLint * params) = NULL;

static int Load_NV_register_combiners(void)
{
	int numFailed = 0;
	_ptrc_glCombinerInputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glCombinerInputNV");
	if(!_ptrc_glCombinerInputNV) numFailed++;
	_ptrc_glCombinerOutputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glCombinerOutputNV");
	if(!_ptrc_glCombinerOutputNV) numFailed++;
	_ptrc_glCombinerParameterfNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glCombinerParameterfNV");
	if(!_ptrc_glCombinerParameterfNV) numFailed++;
	_ptrc_glCombinerParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glCombinerParameterfvNV");
	if(!_ptrc_glCombinerParameterfvNV) numFailed++;
	_ptrc_glCombinerParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glCombinerParameteriNV");
	if(!_ptrc_glCombinerParameteriNV) numFailed++;
	_ptrc_glCombinerParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glCombinerParameterivNV");
	if(!_ptrc_glCombinerParameterivNV) numFailed++;
	_ptrc_glFinalCombinerInputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glFinalCombinerInputNV");
	if(!_ptrc_glFinalCombinerInputNV) numFailed++;
	_ptrc_glGetCombinerInputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerInputParameterfvNV");
	if(!_ptrc_glGetCombinerInputParameterfvNV) numFailed++;
	_ptrc_glGetCombinerInputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetCombinerInputParameterivNV");
	if(!_ptrc_glGetCombinerInputParameterivNV) numFailed++;
	_ptrc_glGetCombinerOutputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerOutputParameterfvNV");
	if(!_ptrc_glGetCombinerOutputParameterfvNV) numFailed++;
	_ptrc_glGetCombinerOutputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetCombinerOutputParameterivNV");
	if(!_ptrc_glGetCombinerOutputParameterivNV) numFailed++;
	_ptrc_glGetFinalCombinerInputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetFinalCombinerInputParameterfvNV");
	if(!_ptrc_glGetFinalCombinerInputParameterfvNV) numFailed++;
	_ptrc_glGetFinalCombinerInputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFinalCombinerInputParameterivNV");
	if(!_ptrc_glGetFinalCombinerInputParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCombinerStageParameterfvNV)(GLenum stage, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerStageParameterfvNV)(GLenum stage, GLenum pname, GLfloat * params) = NULL;

static int Load_NV_register_combiners2(void)
{
	int numFailed = 0;
	_ptrc_glCombinerStageParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCombinerStageParameterfvNV");
	if(!_ptrc_glCombinerStageParameterfvNV) numFailed++;
	_ptrc_glGetCombinerStageParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerStageParameterfvNV");
	if(!_ptrc_glGetCombinerStageParameterfvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterui64vNV)(GLenum target, GLenum pname, GLuint64EXT * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64vNV)(GLenum value, GLuint64EXT * result) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterui64vNV)(GLuint buffer, GLenum pname, GLuint64EXT * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vNV)(GLuint program, GLint location, GLuint64EXT * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferResidentNV)(GLenum target) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedBufferResidentNV)(GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferNonResidentNV)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferResidentNV)(GLenum target, GLenum access) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferNonResidentNV)(GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferResidentNV)(GLuint buffer, GLenum access) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64NV)(GLuint program, GLint location, GLuint64EXT value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformui64NV)(GLint location, GLuint64EXT value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value) = NULL;

static int Load_NV_shader_buffer_load(void)
{
	int numFailed = 0;
	_ptrc_glGetBufferParameterui64vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint64EXT *))IntGetProcAddress("glGetBufferParameterui64vNV");
	if(!_ptrc_glGetBufferParameterui64vNV) numFailed++;
	_ptrc_glGetIntegerui64vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint64EXT *))IntGetProcAddress("glGetIntegerui64vNV");
	if(!_ptrc_glGetIntegerui64vNV) numFailed++;
	_ptrc_glGetNamedBufferParameterui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetNamedBufferParameterui64vNV");
	if(!_ptrc_glGetNamedBufferParameterui64vNV) numFailed++;
	_ptrc_glGetUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT *))IntGetProcAddress("glGetUniformui64vNV");
	if(!_ptrc_glGetUniformui64vNV) numFailed++;
	_ptrc_glIsBufferResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glIsBufferResidentNV");
	if(!_ptrc_glIsBufferResidentNV) numFailed++;
	_ptrc_glIsNamedBufferResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsNamedBufferResidentNV");
	if(!_ptrc_glIsNamedBufferResidentNV) numFailed++;
	_ptrc_glMakeBufferNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMakeBufferNonResidentNV");
	if(!_ptrc_glMakeBufferNonResidentNV) numFailed++;
	_ptrc_glMakeBufferResidentNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMakeBufferResidentNV");
	if(!_ptrc_glMakeBufferResidentNV) numFailed++;
	_ptrc_glMakeNamedBufferNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glMakeNamedBufferNonResidentNV");
	if(!_ptrc_glMakeNamedBufferNonResidentNV) numFailed++;
	_ptrc_glMakeNamedBufferResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMakeNamedBufferResidentNV");
	if(!_ptrc_glMakeNamedBufferResidentNV) numFailed++;
	_ptrc_glProgramUniformui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT))IntGetProcAddress("glProgramUniformui64NV");
	if(!_ptrc_glProgramUniformui64NV) numFailed++;
	_ptrc_glProgramUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniformui64vNV");
	if(!_ptrc_glProgramUniformui64vNV) numFailed++;
	_ptrc_glUniformui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT))IntGetProcAddress("glUniformui64NV");
	if(!_ptrc_glUniformui64NV) numFailed++;
	_ptrc_glUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniformui64vNV");
	if(!_ptrc_glUniformui64vNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrierNV)(void) = NULL;

static int Load_NV_texture_barrier(void)
{
	int numFailed = 0;
	_ptrc_glTextureBarrierNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glTextureBarrierNV");
	if(!_ptrc_glTextureBarrierNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) = NULL;

static int Load_NV_texture_multisample(void)
{
	int numFailed = 0;
	_ptrc_glTexImage2DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisampleCoverageNV");
	if(!_ptrc_glTexImage2DMultisampleCoverageNV) numFailed++;
	_ptrc_glTexImage3DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisampleCoverageNV");
	if(!_ptrc_glTexImage3DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage2DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage2DMultisampleCoverageNV");
	if(!_ptrc_glTextureImage2DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage2DMultisampleNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage2DMultisampleNV");
	if(!_ptrc_glTextureImage2DMultisampleNV) numFailed++;
	_ptrc_glTextureImage3DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage3DMultisampleCoverageNV");
	if(!_ptrc_glTextureImage3DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage3DMultisampleNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage3DMultisampleNV");
	if(!_ptrc_glTextureImage3DMultisampleNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveVaryingNV)(GLuint program, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackNV)(GLenum primitiveMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseNV)(GLenum target, GLuint index, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackNV)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveVaryingNV)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingNV)(GLuint program, GLuint index, GLint * location) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetVaryingLocationNV)(GLuint program, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackAttribsNV)(GLsizei count, const GLint * attribs, GLenum bufferMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackStreamAttribsNV)(GLsizei count, const GLint * attribs, GLsizei nbuffers, const GLint * bufstreams, GLenum bufferMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsNV)(GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode) = NULL;

static int Load_NV_transform_feedback(void)
{
	int numFailed = 0;
	_ptrc_glActiveVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glActiveVaryingNV");
	if(!_ptrc_glActiveVaryingNV) numFailed++;
	_ptrc_glBeginTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBeginTransformFeedbackNV");
	if(!_ptrc_glBeginTransformFeedbackNV) numFailed++;
	_ptrc_glBindBufferBaseNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBaseNV");
	if(!_ptrc_glBindBufferBaseNV) numFailed++;
	_ptrc_glBindBufferOffsetNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr))IntGetProcAddress("glBindBufferOffsetNV");
	if(!_ptrc_glBindBufferOffsetNV) numFailed++;
	_ptrc_glBindBufferRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRangeNV");
	if(!_ptrc_glBindBufferRangeNV) numFailed++;
	_ptrc_glEndTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndTransformFeedbackNV");
	if(!_ptrc_glEndTransformFeedbackNV) numFailed++;
	_ptrc_glGetActiveVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveVaryingNV");
	if(!_ptrc_glGetActiveVaryingNV) numFailed++;
	_ptrc_glGetTransformFeedbackVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint *))IntGetProcAddress("glGetTransformFeedbackVaryingNV");
	if(!_ptrc_glGetTransformFeedbackVaryingNV) numFailed++;
	_ptrc_glGetVaryingLocationNV = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetVaryingLocationNV");
	if(!_ptrc_glGetVaryingLocationNV) numFailed++;
	_ptrc_glTransformFeedbackAttribsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackAttribsNV");
	if(!_ptrc_glTransformFeedbackAttribsNV) numFailed++;
	_ptrc_glTransformFeedbackStreamAttribsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLint *, GLsizei, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackStreamAttribsNV");
	if(!_ptrc_glTransformFeedbackStreamAttribsNV) numFailed++;
	_ptrc_glTransformFeedbackVaryingsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackVaryingsNV");
	if(!_ptrc_glTransformFeedbackVaryingsNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedbackNV)(GLenum target, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacksNV)(GLsizei n, const GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackNV)(GLenum mode, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacksNV)(GLsizei n, GLuint * ids) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedbackNV)(GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedbackNV)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedbackNV)(void) = NULL;

static int Load_NV_transform_feedback2(void)
{
	int numFailed = 0;
	_ptrc_glBindTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedbackNV");
	if(!_ptrc_glBindTransformFeedbackNV) numFailed++;
	_ptrc_glDeleteTransformFeedbacksNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacksNV");
	if(!_ptrc_glDeleteTransformFeedbacksNV) numFailed++;
	_ptrc_glDrawTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedbackNV");
	if(!_ptrc_glDrawTransformFeedbackNV) numFailed++;
	_ptrc_glGenTransformFeedbacksNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacksNV");
	if(!_ptrc_glGenTransformFeedbacksNV) numFailed++;
	_ptrc_glIsTransformFeedbackNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedbackNV");
	if(!_ptrc_glIsTransformFeedbackNV) numFailed++;
	_ptrc_glPauseTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPauseTransformFeedbackNV");
	if(!_ptrc_glPauseTransformFeedbackNV) numFailed++;
	_ptrc_glResumeTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glResumeTransformFeedbackNV");
	if(!_ptrc_glResumeTransformFeedbackNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeNV)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeNV)(GLsizei length, const void * pointer) = NULL;

static int Load_NV_vertex_array_range(void)
{
	int numFailed = 0;
	_ptrc_glFlushVertexArrayRangeNV = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glFlushVertexArrayRangeNV");
	if(!_ptrc_glFlushVertexArrayRangeNV) numFailed++;
	_ptrc_glVertexArrayRangeNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const void *))IntGetProcAddress("glVertexArrayRangeNV");
	if(!_ptrc_glVertexArrayRangeNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLi64vNV)(GLuint index, GLenum pname, GLint64EXT * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vNV)(GLuint index, GLenum pname, GLuint64EXT * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64NV)(GLuint index, GLint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64vNV)(GLuint index, const GLint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64NV)(GLuint index, GLuint64EXT x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vNV)(GLuint index, const GLuint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64NV)(GLuint index, GLint64EXT x, GLint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64vNV)(GLuint index, const GLint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64vNV)(GLuint index, const GLuint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64vNV)(GLuint index, const GLint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64vNV)(GLuint index, const GLuint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64vNV)(GLuint index, const GLint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64vNV)(GLuint index, const GLuint64EXT * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride) = NULL;

static int Load_NV_vertex_attrib_integer_64bit(void)
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLi64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64EXT *))IntGetProcAddress("glGetVertexAttribLi64vNV");
	if(!_ptrc_glGetVertexAttribLi64vNV) numFailed++;
	_ptrc_glGetVertexAttribLui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetVertexAttribLui64vNV");
	if(!_ptrc_glGetVertexAttribLui64vNV) numFailed++;
	_ptrc_glVertexAttribL1i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT))IntGetProcAddress("glVertexAttribL1i64NV");
	if(!_ptrc_glVertexAttribL1i64NV) numFailed++;
	_ptrc_glVertexAttribL1i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL1i64vNV");
	if(!_ptrc_glVertexAttribL1i64vNV) numFailed++;
	_ptrc_glVertexAttribL1ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT))IntGetProcAddress("glVertexAttribL1ui64NV");
	if(!_ptrc_glVertexAttribL1ui64NV) numFailed++;
	_ptrc_glVertexAttribL1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL1ui64vNV");
	if(!_ptrc_glVertexAttribL1ui64vNV) numFailed++;
	_ptrc_glVertexAttribL2i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL2i64NV");
	if(!_ptrc_glVertexAttribL2i64NV) numFailed++;
	_ptrc_glVertexAttribL2i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL2i64vNV");
	if(!_ptrc_glVertexAttribL2i64vNV) numFailed++;
	_ptrc_glVertexAttribL2ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL2ui64NV");
	if(!_ptrc_glVertexAttribL2ui64NV) numFailed++;
	_ptrc_glVertexAttribL2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL2ui64vNV");
	if(!_ptrc_glVertexAttribL2ui64vNV) numFailed++;
	_ptrc_glVertexAttribL3i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL3i64NV");
	if(!_ptrc_glVertexAttribL3i64NV) numFailed++;
	_ptrc_glVertexAttribL3i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL3i64vNV");
	if(!_ptrc_glVertexAttribL3i64vNV) numFailed++;
	_ptrc_glVertexAttribL3ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL3ui64NV");
	if(!_ptrc_glVertexAttribL3ui64NV) numFailed++;
	_ptrc_glVertexAttribL3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL3ui64vNV");
	if(!_ptrc_glVertexAttribL3ui64vNV) numFailed++;
	_ptrc_glVertexAttribL4i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL4i64NV");
	if(!_ptrc_glVertexAttribL4i64NV) numFailed++;
	_ptrc_glVertexAttribL4i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL4i64vNV");
	if(!_ptrc_glVertexAttribL4i64vNV) numFailed++;
	_ptrc_glVertexAttribL4ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL4ui64NV");
	if(!_ptrc_glVertexAttribL4ui64NV) numFailed++;
	_ptrc_glVertexAttribL4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL4ui64vNV");
	if(!_ptrc_glVertexAttribL4ui64vNV) numFailed++;
	_ptrc_glVertexAttribLFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei))IntGetProcAddress("glVertexAttribLFormatNV");
	if(!_ptrc_glVertexAttribLFormatNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferAddressRangeNV)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorFormatNV)(GLint size, GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagFormatNV)(GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordFormatNV)(GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64i_vNV)(GLenum value, GLuint index, GLuint64EXT * result) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexFormatNV)(GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalFormatNV)(GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorFormatNV)(GLint size, GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordFormatNV)(GLint size, GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormatNV)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexFormatNV)(GLint size, GLenum type, GLsizei stride) = NULL;

static int Load_NV_vertex_buffer_unified_memory(void)
{
	int numFailed = 0;
	_ptrc_glBufferAddressRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint64EXT, GLsizeiptr))IntGetProcAddress("glBufferAddressRangeNV");
	if(!_ptrc_glBufferAddressRangeNV) numFailed++;
	_ptrc_glColorFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glColorFormatNV");
	if(!_ptrc_glColorFormatNV) numFailed++;
	_ptrc_glEdgeFlagFormatNV = (void (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glEdgeFlagFormatNV");
	if(!_ptrc_glEdgeFlagFormatNV) numFailed++;
	_ptrc_glFogCoordFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glFogCoordFormatNV");
	if(!_ptrc_glFogCoordFormatNV) numFailed++;
	_ptrc_glGetIntegerui64i_vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint64EXT *))IntGetProcAddress("glGetIntegerui64i_vNV");
	if(!_ptrc_glGetIntegerui64i_vNV) numFailed++;
	_ptrc_glIndexFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glIndexFormatNV");
	if(!_ptrc_glIndexFormatNV) numFailed++;
	_ptrc_glNormalFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glNormalFormatNV");
	if(!_ptrc_glNormalFormatNV) numFailed++;
	_ptrc_glSecondaryColorFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glSecondaryColorFormatNV");
	if(!_ptrc_glSecondaryColorFormatNV) numFailed++;
	_ptrc_glTexCoordFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glTexCoordFormatNV");
	if(!_ptrc_glTexCoordFormatNV) numFailed++;
	_ptrc_glVertexAttribFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei))IntGetProcAddress("glVertexAttribFormatNV");
	if(!_ptrc_glVertexAttribFormatNV) numFailed++;
	_ptrc_glVertexAttribIFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei))IntGetProcAddress("glVertexAttribIFormatNV");
	if(!_ptrc_glVertexAttribIFormatNV) numFailed++;
	_ptrc_glVertexFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glVertexFormatNV");
	if(!_ptrc_glVertexFormatNV) numFailed++;
	return numFailed;
}

GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreProgramsResidentNV)(GLsizei n, const GLuint * programs, GLboolean * residences) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindProgramNV)(GLenum target, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsNV)(GLsizei n, const GLuint * programs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glExecuteProgramNV)(GLenum target, GLuint id, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsNV)(GLsizei n, GLuint * programs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterdvNV)(GLenum target, GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterfvNV)(GLenum target, GLuint index, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringNV)(GLuint id, GLenum pname, GLubyte * program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivNV)(GLuint id, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTrackMatrixivNV)(GLenum target, GLuint address, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervNV)(GLuint index, GLenum pname, void ** pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvNV)(GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvNV)(GLuint index, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivNV)(GLuint index, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramNV)(GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadProgramNV)(GLenum target, GLuint id, GLsizei len, const GLubyte * program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dNV)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dvNV)(GLenum target, GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fNV)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fvNV)(GLenum target, GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4dvNV)(GLenum target, GLuint index, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4fvNV)(GLenum target, GLuint index, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRequestResidentProgramsNV)(GLsizei n, const GLuint * programs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTrackMatrixNV)(GLenum target, GLuint address, GLenum matrix, GLenum transform) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dNV)(GLuint index, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvNV)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fNV)(GLuint index, GLfloat x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvNV)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sNV)(GLuint index, GLshort x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svNV)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dNV)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvNV)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fNV)(GLuint index, GLfloat x, GLfloat y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvNV)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sNV)(GLuint index, GLshort x, GLshort y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svNV)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvNV)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvNV)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sNV)(GLuint index, GLshort x, GLshort y, GLshort z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svNV)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvNV)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvNV)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sNV)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svNV)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubNV)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvNV)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerNV)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void * pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1dvNV)(GLuint index, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1fvNV)(GLuint index, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1svNV)(GLuint index, GLsizei count, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2dvNV)(GLuint index, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2fvNV)(GLuint index, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2svNV)(GLuint index, GLsizei count, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3dvNV)(GLuint index, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3fvNV)(GLuint index, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3svNV)(GLuint index, GLsizei count, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4dvNV)(GLuint index, GLsizei count, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4fvNV)(GLuint index, GLsizei count, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4svNV)(GLuint index, GLsizei count, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4ubvNV)(GLuint index, GLsizei count, const GLubyte * v) = NULL;

static int Load_NV_vertex_program(void)
{
	int numFailed = 0;
	_ptrc_glAreProgramsResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLboolean *))IntGetProcAddress("glAreProgramsResidentNV");
	if(!_ptrc_glAreProgramsResidentNV) numFailed++;
	_ptrc_glBindProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramNV");
	if(!_ptrc_glBindProgramNV) numFailed++;
	_ptrc_glDeleteProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsNV");
	if(!_ptrc_glDeleteProgramsNV) numFailed++;
	_ptrc_glExecuteProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glExecuteProgramNV");
	if(!_ptrc_glExecuteProgramNV) numFailed++;
	_ptrc_glGenProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsNV");
	if(!_ptrc_glGenProgramsNV) numFailed++;
	_ptrc_glGetProgramParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetProgramParameterdvNV");
	if(!_ptrc_glGetProgramParameterdvNV) numFailed++;
	_ptrc_glGetProgramParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetProgramParameterfvNV");
	if(!_ptrc_glGetProgramParameterfvNV) numFailed++;
	_ptrc_glGetProgramStringNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLubyte *))IntGetProcAddress("glGetProgramStringNV");
	if(!_ptrc_glGetProgramStringNV) numFailed++;
	_ptrc_glGetProgramivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramivNV");
	if(!_ptrc_glGetProgramivNV) numFailed++;
	_ptrc_glGetTrackMatrixivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetTrackMatrixivNV");
	if(!_ptrc_glGetTrackMatrixivNV) numFailed++;
	_ptrc_glGetVertexAttribPointervNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetVertexAttribPointervNV");
	if(!_ptrc_glGetVertexAttribPointervNV) numFailed++;
	_ptrc_glGetVertexAttribdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdvNV");
	if(!_ptrc_glGetVertexAttribdvNV) numFailed++;
	_ptrc_glGetVertexAttribfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfvNV");
	if(!_ptrc_glGetVertexAttribfvNV) numFailed++;
	_ptrc_glGetVertexAttribivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribivNV");
	if(!_ptrc_glGetVertexAttribivNV) numFailed++;
	_ptrc_glIsProgramNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramNV");
	if(!_ptrc_glIsProgramNV) numFailed++;
	_ptrc_glLoadProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLubyte *))IntGetProcAddress("glLoadProgramNV");
	if(!_ptrc_glLoadProgramNV) numFailed++;
	_ptrc_glProgramParameter4dNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramParameter4dNV");
	if(!_ptrc_glProgramParameter4dNV) numFailed++;
	_ptrc_glProgramParameter4dvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramParameter4dvNV");
	if(!_ptrc_glProgramParameter4dvNV) numFailed++;
	_ptrc_glProgramParameter4fNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramParameter4fNV");
	if(!_ptrc_glProgramParameter4fNV) numFailed++;
	_ptrc_glProgramParameter4fvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramParameter4fvNV");
	if(!_ptrc_glProgramParameter4fvNV) numFailed++;
	_ptrc_glProgramParameters4dvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramParameters4dvNV");
	if(!_ptrc_glProgramParameters4dvNV) numFailed++;
	_ptrc_glProgramParameters4fvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramParameters4fvNV");
	if(!_ptrc_glProgramParameters4fvNV) numFailed++;
	_ptrc_glRequestResidentProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glRequestResidentProgramsNV");
	if(!_ptrc_glRequestResidentProgramsNV) numFailed++;
	_ptrc_glTrackMatrixNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLenum))IntGetProcAddress("glTrackMatrixNV");
	if(!_ptrc_glTrackMatrixNV) numFailed++;
	_ptrc_glVertexAttrib1dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1dNV");
	if(!_ptrc_glVertexAttrib1dNV) numFailed++;
	_ptrc_glVertexAttrib1dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dvNV");
	if(!_ptrc_glVertexAttrib1dvNV) numFailed++;
	_ptrc_glVertexAttrib1fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1fNV");
	if(!_ptrc_glVertexAttrib1fNV) numFailed++;
	_ptrc_glVertexAttrib1fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fvNV");
	if(!_ptrc_glVertexAttrib1fvNV) numFailed++;
	_ptrc_glVertexAttrib1sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1sNV");
	if(!_ptrc_glVertexAttrib1sNV) numFailed++;
	_ptrc_glVertexAttrib1svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1svNV");
	if(!_ptrc_glVertexAttrib1svNV) numFailed++;
	_ptrc_glVertexAttrib2dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2dNV");
	if(!_ptrc_glVertexAttrib2dNV) numFailed++;
	_ptrc_glVertexAttrib2dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dvNV");
	if(!_ptrc_glVertexAttrib2dvNV) numFailed++;
	_ptrc_glVertexAttrib2fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2fNV");
	if(!_ptrc_glVertexAttrib2fNV) numFailed++;
	_ptrc_glVertexAttrib2fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fvNV");
	if(!_ptrc_glVertexAttrib2fvNV) numFailed++;
	_ptrc_glVertexAttrib2sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2sNV");
	if(!_ptrc_glVertexAttrib2sNV) numFailed++;
	_ptrc_glVertexAttrib2svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2svNV");
	if(!_ptrc_glVertexAttrib2svNV) numFailed++;
	_ptrc_glVertexAttrib3dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3dNV");
	if(!_ptrc_glVertexAttrib3dNV) numFailed++;
	_ptrc_glVertexAttrib3dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dvNV");
	if(!_ptrc_glVertexAttrib3dvNV) numFailed++;
	_ptrc_glVertexAttrib3fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3fNV");
	if(!_ptrc_glVertexAttrib3fNV) numFailed++;
	_ptrc_glVertexAttrib3fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fvNV");
	if(!_ptrc_glVertexAttrib3fvNV) numFailed++;
	_ptrc_glVertexAttrib3sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3sNV");
	if(!_ptrc_glVertexAttrib3sNV) numFailed++;
	_ptrc_glVertexAttrib3svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3svNV");
	if(!_ptrc_glVertexAttrib3svNV) numFailed++;
	_ptrc_glVertexAttrib4dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4dNV");
	if(!_ptrc_glVertexAttrib4dNV) numFailed++;
	_ptrc_glVertexAttrib4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dvNV");
	if(!_ptrc_glVertexAttrib4dvNV) numFailed++;
	_ptrc_glVertexAttrib4fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4fNV");
	if(!_ptrc_glVertexAttrib4fNV) numFailed++;
	_ptrc_glVertexAttrib4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fvNV");
	if(!_ptrc_glVertexAttrib4fvNV) numFailed++;
	_ptrc_glVertexAttrib4sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4sNV");
	if(!_ptrc_glVertexAttrib4sNV) numFailed++;
	_ptrc_glVertexAttrib4svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4svNV");
	if(!_ptrc_glVertexAttrib4svNV) numFailed++;
	_ptrc_glVertexAttrib4ubNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4ubNV");
	if(!_ptrc_glVertexAttrib4ubNV) numFailed++;
	_ptrc_glVertexAttrib4ubvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubvNV");
	if(!_ptrc_glVertexAttrib4ubvNV) numFailed++;
	_ptrc_glVertexAttribPointerNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glVertexAttribPointerNV");
	if(!_ptrc_glVertexAttribPointerNV) numFailed++;
	_ptrc_glVertexAttribs1dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs1dvNV");
	if(!_ptrc_glVertexAttribs1dvNV) numFailed++;
	_ptrc_glVertexAttribs1fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs1fvNV");
	if(!_ptrc_glVertexAttribs1fvNV) numFailed++;
	_ptrc_glVertexAttribs1svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs1svNV");
	if(!_ptrc_glVertexAttribs1svNV) numFailed++;
	_ptrc_glVertexAttribs2dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs2dvNV");
	if(!_ptrc_glVertexAttribs2dvNV) numFailed++;
	_ptrc_glVertexAttribs2fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs2fvNV");
	if(!_ptrc_glVertexAttribs2fvNV) numFailed++;
	_ptrc_glVertexAttribs2svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs2svNV");
	if(!_ptrc_glVertexAttribs2svNV) numFailed++;
	_ptrc_glVertexAttribs3dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs3dvNV");
	if(!_ptrc_glVertexAttribs3dvNV) numFailed++;
	_ptrc_glVertexAttribs3fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs3fvNV");
	if(!_ptrc_glVertexAttribs3fvNV) numFailed++;
	_ptrc_glVertexAttribs3svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs3svNV");
	if(!_ptrc_glVertexAttribs3svNV) numFailed++;
	_ptrc_glVertexAttribs4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs4dvNV");
	if(!_ptrc_glVertexAttribs4dvNV) numFailed++;
	_ptrc_glVertexAttribs4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs4fvNV");
	if(!_ptrc_glVertexAttribs4fvNV) numFailed++;
	_ptrc_glVertexAttribs4svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs4svNV");
	if(!_ptrc_glVertexAttribs4svNV) numFailed++;
	_ptrc_glVertexAttribs4ubvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *))IntGetProcAddress("glVertexAttribs4ubvNV");
	if(!_ptrc_glVertexAttribs4ubvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginVideoCaptureNV)(GLuint video_capture_slot) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamBufferNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamTextureNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndVideoCaptureNV)(GLuint video_capture_slot) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureivNV)(GLuint video_capture_slot, GLenum pname, GLint * params) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureNV)(GLuint video_capture_slot, GLuint * sequence_num, GLuint64EXT * capture_time) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint * params) = NULL;

static int Load_NV_video_capture(void)
{
	int numFailed = 0;
	_ptrc_glBeginVideoCaptureNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginVideoCaptureNV");
	if(!_ptrc_glBeginVideoCaptureNV) numFailed++;
	_ptrc_glBindVideoCaptureStreamBufferNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptrARB))IntGetProcAddress("glBindVideoCaptureStreamBufferNV");
	if(!_ptrc_glBindVideoCaptureStreamBufferNV) numFailed++;
	_ptrc_glBindVideoCaptureStreamTextureNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glBindVideoCaptureStreamTextureNV");
	if(!_ptrc_glBindVideoCaptureStreamTextureNV) numFailed++;
	_ptrc_glEndVideoCaptureNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEndVideoCaptureNV");
	if(!_ptrc_glEndVideoCaptureNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVideoCaptureStreamdvNV");
	if(!_ptrc_glGetVideoCaptureStreamdvNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVideoCaptureStreamfvNV");
	if(!_ptrc_glGetVideoCaptureStreamfvNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVideoCaptureStreamivNV");
	if(!_ptrc_glGetVideoCaptureStreamivNV) numFailed++;
	_ptrc_glGetVideoCaptureivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVideoCaptureivNV");
	if(!_ptrc_glGetVideoCaptureivNV) numFailed++;
	_ptrc_glVideoCaptureNV = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLuint *, GLuint64EXT *))IntGetProcAddress("glVideoCaptureNV");
	if(!_ptrc_glVideoCaptureNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLdouble *))IntGetProcAddress("glVideoCaptureStreamParameterdvNV");
	if(!_ptrc_glVideoCaptureStreamParameterdvNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glVideoCaptureStreamParameterfvNV");
	if(!_ptrc_glVideoCaptureStreamParameterfvNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLint *))IntGetProcAddress("glVideoCaptureStreamParameterivNV");
	if(!_ptrc_glVideoCaptureStreamParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNVX)(GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNVX)(void) = NULL;

static int Load_NVX_conditional_render(void)
{
	int numFailed = 0;
	_ptrc_glBeginConditionalRenderNVX = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginConditionalRenderNVX");
	if(!_ptrc_glBeginConditionalRenderNVX) numFailed++;
	_ptrc_glEndConditionalRenderNVX = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndConditionalRenderNVX");
	if(!_ptrc_glEndConditionalRenderNVX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierKHR)(void) = NULL;

static int Load_KHR_blend_equation_advanced(void)
{
	int numFailed = 0;
	_ptrc_glBlendBarrierKHR = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glBlendBarrierKHR");
	if(!_ptrc_glBlendBarrierKHR) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendFunc)(GLenum sfactor, GLenum dfactor) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClear)(GLbitfield mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearDepth)(GLdouble depth) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearStencil)(GLint s) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCullFace)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthFunc)(GLenum func) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthMask)(GLboolean flag) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRange)(GLdouble ren_near, GLdouble ren_far) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisable)(GLenum cap) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffer)(GLenum buf) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnable)(GLenum cap) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinish)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlush)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFrontFace)(GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanv)(GLenum pname, GLboolean * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublev)(GLenum pname, GLdouble * data) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glGetError)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloatv)(GLenum pname, GLfloat * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerv)(GLenum pname, GLint * data) = NULL;
const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetString)(GLenum name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glHint)(GLenum target, GLenum mode) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabled)(GLenum cap) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLineWidth)(GLfloat width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLogicOp)(GLenum opcode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelStoref)(GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelStorei)(GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointSize)(GLfloat size) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonMode)(GLenum face, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadBuffer)(GLenum src) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFunc)(GLenum func, GLint ref, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilMask)(GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameteri)(GLenum target, GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameteriv)(GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBindTexture)(GLenum target, GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTextures)(GLsizei n, const GLuint * textures) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawArrays)(GLenum mode, GLint first, GLsizei count) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void * indices) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTextures)(GLsizei n, GLuint * textures) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTexture)(GLuint texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffset)(GLfloat factor, GLfloat units) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glActiveTexture)(GLenum texture) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImage)(GLenum target, GLint level, void * img) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverage)(GLfloat value, GLboolean invert) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterf)(GLenum pname, GLfloat param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfv)(GLenum pname, const GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameteri)(GLenum pname, GLint param) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriv)(GLenum pname, const GLint * params) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBeginQuery)(GLenum target, GLuint id) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBuffer)(GLenum target, GLuint buffer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffers)(GLsizei n, const GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueries)(GLsizei n, const GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQuery)(GLenum target) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenBuffers)(GLsizei n, GLuint * buffers) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenQueries)(GLsizei n, GLuint * ids) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointerv)(GLenum target, GLenum pname, void ** params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryiv)(GLenum target, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBuffer)(GLuint buffer) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQuery)(GLuint id) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBuffer)(GLenum target, GLenum access) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBuffer)(GLenum target) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glAttachShader)(GLuint program, GLuint shader) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocation)(GLuint program, GLuint index, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompileShader)(GLuint shader) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateProgram)(void) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShader)(GLenum type) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgram)(GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteShader)(GLuint shader) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDetachShader)(GLuint program, GLuint shader) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArray)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffers)(GLsizei n, const GLenum * bufs) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArray)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocation)(GLuint program, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramiv)(GLuint program, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderiv)(GLuint shader, GLenum pname, GLint * params) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocation)(GLuint program, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfv)(GLuint program, GLint location, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformiv)(GLuint program, GLint location, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void ** pointer) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgram)(GLuint program) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsShader)(GLuint shader) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLinkProgram)(GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilMaskSeparate)(GLenum face, GLuint mask) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1f)(GLint location, GLfloat v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i)(GLint location, GLint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1iv)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i)(GLint location, GLint v0, GLint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2iv)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3iv)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4iv)(GLint location, GLsizei count, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgram)(GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgram)(GLuint program) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1d)(GLuint index, GLdouble x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1f)(GLuint index, GLfloat x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fv)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1s)(GLuint index, GLshort x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fv)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fv)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nbv)(GLuint index, const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Niv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nsv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nubv)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nuiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nusv)(GLuint index, const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bv)(GLuint index, const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dv)(GLuint index, const GLdouble * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fv)(GLuint index, const GLfloat * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4iv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubv)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usv)(GLuint index, const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRender)(GLuint id, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedback)(GLenum primitiveMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClampColor)(GLenum target, GLenum clamp) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisablei)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnablei)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRender)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedback)(void) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleani_v)(GLenum target, GLuint index, GLboolean * data) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocation)(GLuint program, const GLchar * name) = NULL;
const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetStringi)(GLenum name, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuiv)(GLuint program, GLint location, GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint * params) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledi)(GLenum target, GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIiv)(GLenum target, GLenum pname, const GLint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui)(GLint location, GLuint v0) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui)(GLint location, GLuint v0, GLuint v1) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1i)(GLuint index, GLint x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ui)(GLuint index, GLuint x) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2i)(GLuint index, GLint x, GLint y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bv)(GLuint index, const GLbyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iv)(GLuint index, const GLint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4sv)(GLuint index, const GLshort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubv)(GLuint index, const GLubyte * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiv)(GLuint index, const GLuint * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usv)(GLuint index, const GLushort * v) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndex)(GLuint index) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 * data) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisor)(GLuint index, GLuint divisor) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationi)(GLuint buf, GLenum mode) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFunci)(GLuint buf, GLenum src, GLenum dst) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShading)(GLfloat value) = NULL;





void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) = NULL;

static int Load_Version_4_5(void)
{
	int numFailed = 0;
	_ptrc_glBlendFunc = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendFunc");
	if(!_ptrc_glBlendFunc) numFailed++;
	_ptrc_glClear = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glClear");
	if(!_ptrc_glClear) numFailed++;
	_ptrc_glClearColor = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glClearColor");
	if(!_ptrc_glClearColor) numFailed++;
	_ptrc_glClearDepth = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glClearDepth");
	if(!_ptrc_glClearDepth) numFailed++;
	_ptrc_glClearStencil = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glClearStencil");
	if(!_ptrc_glClearStencil) numFailed++;
	_ptrc_glColorMask = (void (CODEGEN_FUNCPTR *)(GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMask");
	if(!_ptrc_glColorMask) numFailed++;
	_ptrc_glCullFace = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCullFace");
	if(!_ptrc_glCullFace) numFailed++;
	_ptrc_glDepthFunc = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDepthFunc");
	if(!_ptrc_glDepthFunc) numFailed++;
	_ptrc_glDepthMask = (void (CODEGEN_FUNCPTR *)(GLboolean))IntGetProcAddress("glDepthMask");
	if(!_ptrc_glDepthMask) numFailed++;
	_ptrc_glDepthRange = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthRange");
	if(!_ptrc_glDepthRange) numFailed++;
	_ptrc_glDisable = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDisable");
	if(!_ptrc_glDisable) numFailed++;
	_ptrc_glDrawBuffer = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDrawBuffer");
	if(!_ptrc_glDrawBuffer) numFailed++;
	_ptrc_glEnable = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEnable");
	if(!_ptrc_glEnable) numFailed++;
	_ptrc_glFinish = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glFinish");
	if(!_ptrc_glFinish) numFailed++;
	_ptrc_glFlush = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glFlush");
	if(!_ptrc_glFlush) numFailed++;
	_ptrc_glFrontFace = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glFrontFace");
	if(!_ptrc_glFrontFace) numFailed++;
	_ptrc_glGetBooleanv = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean *))IntGetProcAddress("glGetBooleanv");
	if(!_ptrc_glGetBooleanv) numFailed++;
	_ptrc_glGetDoublev = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble *))IntGetProcAddress("glGetDoublev");
	if(!_ptrc_glGetDoublev) numFailed++;
	_ptrc_glGetError = (GLenum (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glGetError");
	if(!_ptrc_glGetError) numFailed++;
	_ptrc_glGetFloatv = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetFloatv");
	if(!_ptrc_glGetFloatv) numFailed++;
	_ptrc_glGetIntegerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetIntegerv");
	if(!_ptrc_glGetIntegerv) numFailed++;
	_ptrc_glGetString = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGetString");
	if(!_ptrc_glGetString) numFailed++;
	_ptrc_glGetTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLenum, void *))IntGetProcAddress("glGetTexImage");
	if(!_ptrc_glGetTexImage) numFailed++;
	_ptrc_glGetTexLevelParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTexLevelParameterfv");
	if(!_ptrc_glGetTexLevelParameterfv) numFailed++;
	_ptrc_glGetTexLevelParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetTexLevelParameteriv");
	if(!_ptrc_glGetTexLevelParameteriv) numFailed++;
	_ptrc_glGetTexParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTexParameterfv");
	if(!_ptrc_glGetTexParameterfv) numFailed++;
	_ptrc_glGetTexParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameteriv");
	if(!_ptrc_glGetTexParameteriv) numFailed++;
	_ptrc_glHint = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glHint");
	if(!_ptrc_glHint) numFailed++;
	_ptrc_glIsEnabled = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glIsEnabled");
	if(!_ptrc_glIsEnabled) numFailed++;
	_ptrc_glLineWidth = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glLineWidth");
	if(!_ptrc_glLineWidth) numFailed++;
	_ptrc_glLogicOp = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glLogicOp");
	if(!_ptrc_glLogicOp) numFailed++;
	_ptrc_glPixelStoref = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPixelStoref");
	if(!_ptrc_glPixelStoref) numFailed++;
	_ptrc_glPixelStorei = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPixelStorei");
	if(!_ptrc_glPixelStorei) numFailed++;
	_ptrc_glPointSize = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glPointSize");
	if(!_ptrc_glPointSize) numFailed++;
	_ptrc_glPolygonMode = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glPolygonMode");
	if(!_ptrc_glPolygonMode) numFailed++;
	_ptrc_glReadBuffer = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glReadBuffer");
	if(!_ptrc_glReadBuffer) numFailed++;
	_ptrc_glReadPixels = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *))IntGetProcAddress("glReadPixels");
	if(!_ptrc_glReadPixels) numFailed++;
	_ptrc_glScissor = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissor");
	if(!_ptrc_glScissor) numFailed++;
	_ptrc_glStencilFunc = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint))IntGetProcAddress("glStencilFunc");
	if(!_ptrc_glStencilFunc) numFailed++;
	_ptrc_glStencilMask = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glStencilMask");
	if(!_ptrc_glStencilMask) numFailed++;
	_ptrc_glStencilOp = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum))IntGetProcAddress("glStencilOp");
	if(!_ptrc_glStencilOp) numFailed++;
	_ptrc_glTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTexImage1D");
	if(!_ptrc_glTexImage1D) numFailed++;
	_ptrc_glTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTexImage2D");
	if(!_ptrc_glTexImage2D) numFailed++;
	_ptrc_glTexParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glTexParameterf");
	if(!_ptrc_glTexParameterf) numFailed++;
	_ptrc_glTexParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTexParameterfv");
	if(!_ptrc_glTexParameterfv) numFailed++;
	_ptrc_glTexParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glTexParameteri");
	if(!_ptrc_glTexParameteri) numFailed++;
	_ptrc_glTexParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameteriv");
	if(!_ptrc_glTexParameteriv) numFailed++;
	_ptrc_glViewport = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glViewport");
	if(!_ptrc_glViewport) numFailed++;
	_ptrc_glBindTexture = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTexture");
	if(!_ptrc_glBindTexture) numFailed++;
	_ptrc_glCopyTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyTexImage1D");
	if(!_ptrc_glCopyTexImage1D) numFailed++;
	_ptrc_glCopyTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyTexImage2D");
	if(!_ptrc_glCopyTexImage2D) numFailed++;
	_ptrc_glCopyTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTexSubImage1D");
	if(!_ptrc_glCopyTexSubImage1D) numFailed++;
	_ptrc_glCopyTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage2D");
	if(!_ptrc_glCopyTexSubImage2D) numFailed++;
	_ptrc_glDeleteTextures = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTextures");
	if(!_ptrc_glDeleteTextures) numFailed++;
	_ptrc_glDrawArrays = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei))IntGetProcAddress("glDrawArrays");
	if(!_ptrc_glDrawArrays) numFailed++;
	_ptrc_glDrawElements = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *))IntGetProcAddress("glDrawElements");
	if(!_ptrc_glDrawElements) numFailed++;
	_ptrc_glGenTextures = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTextures");
	if(!_ptrc_glGenTextures) numFailed++;
	_ptrc_glGetPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, void **))IntGetProcAddress("glGetPointerv");
	if(!_ptrc_glGetPointerv) numFailed++;
	_ptrc_glIsTexture = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTexture");
	if(!_ptrc_glIsTexture) numFailed++;
	_ptrc_glPolygonOffset = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPolygonOffset");
	if(!_ptrc_glPolygonOffset) numFailed++;
	_ptrc_glTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTexSubImage1D");
	if(!_ptrc_glTexSubImage1D) numFailed++;
	_ptrc_glTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTexSubImage2D");
	if(!_ptrc_glTexSubImage2D) numFailed++;
	_ptrc_glCopyTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage3D");
	if(!_ptrc_glCopyTexSubImage3D) numFailed++;
	_ptrc_glDrawRangeElements = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *))IntGetProcAddress("glDrawRangeElements");
	if(!_ptrc_glDrawRangeElements) numFailed++;
	_ptrc_glTexImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glTexImage3D");
	if(!_ptrc_glTexImage3D) numFailed++;
	_ptrc_glTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTexSubImage3D");
	if(!_ptrc_glTexSubImage3D) numFailed++;
	_ptrc_glActiveTexture = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveTexture");
	if(!_ptrc_glActiveTexture) numFailed++;
	_ptrc_glCompressedTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage1D");
	if(!_ptrc_glCompressedTexImage1D) numFailed++;
	_ptrc_glCompressedTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage2D");
	if(!_ptrc_glCompressedTexImage2D) numFailed++;
	_ptrc_glCompressedTexImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *))IntGetProcAddress("glCompressedTexImage3D");
	if(!_ptrc_glCompressedTexImage3D) numFailed++;
	_ptrc_glCompressedTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage1D");
	if(!_ptrc_glCompressedTexSubImage1D) numFailed++;
	_ptrc_glCompressedTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage2D");
	if(!_ptrc_glCompressedTexSubImage2D) numFailed++;
	_ptrc_glCompressedTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTexSubImage3D");
	if(!_ptrc_glCompressedTexSubImage3D) numFailed++;
	_ptrc_glGetCompressedTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, void *))IntGetProcAddress("glGetCompressedTexImage");
	if(!_ptrc_glGetCompressedTexImage) numFailed++;
	_ptrc_glSampleCoverage = (void (CODEGEN_FUNCPTR *)(GLfloat, GLboolean))IntGetProcAddress("glSampleCoverage");
	if(!_ptrc_glSampleCoverage) numFailed++;
	_ptrc_glBlendColor = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBlendColor");
	if(!_ptrc_glBlendColor) numFailed++;
	_ptrc_glBlendEquation = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBlendEquation");
	if(!_ptrc_glBlendEquation) numFailed++;
	_ptrc_glBlendFuncSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparate");
	if(!_ptrc_glBlendFuncSeparate) numFailed++;
	_ptrc_glMultiDrawArrays = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawArrays");
	if(!_ptrc_glMultiDrawArrays) numFailed++;
	_ptrc_glMultiDrawElements = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei))IntGetProcAddress("glMultiDrawElements");
	if(!_ptrc_glMultiDrawElements) numFailed++;
	_ptrc_glPointParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterf");
	if(!_ptrc_glPointParameterf) numFailed++;
	_ptrc_glPointParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfv");
	if(!_ptrc_glPointParameterfv) numFailed++;
	_ptrc_glPointParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPointParameteri");
	if(!_ptrc_glPointParameteri) numFailed++;
	_ptrc_glPointParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glPointParameteriv");
	if(!_ptrc_glPointParameteriv) numFailed++;
	_ptrc_glBeginQuery = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBeginQuery");
	if(!_ptrc_glBeginQuery) numFailed++;
	_ptrc_glBindBuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindBuffer");
	if(!_ptrc_glBindBuffer) numFailed++;
	_ptrc_glBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const void *, GLenum))IntGetProcAddress("glBufferData");
	if(!_ptrc_glBufferData) numFailed++;
	_ptrc_glBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, const void *))IntGetProcAddress("glBufferSubData");
	if(!_ptrc_glBufferSubData) numFailed++;
	_ptrc_glDeleteBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteBuffers");
	if(!_ptrc_glDeleteBuffers) numFailed++;
	_ptrc_glDeleteQueries = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteQueries");
	if(!_ptrc_glDeleteQueries) numFailed++;
	_ptrc_glEndQuery = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEndQuery");
	if(!_ptrc_glEndQuery) numFailed++;
	_ptrc_glGenBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenBuffers");
	if(!_ptrc_glGenBuffers) numFailed++;
	_ptrc_glGenQueries = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenQueries");
	if(!_ptrc_glGenQueries) numFailed++;
	_ptrc_glGetBufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetBufferParameteriv");
	if(!_ptrc_glGetBufferParameteriv) numFailed++;
	_ptrc_glGetBufferPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, void **))IntGetProcAddress("glGetBufferPointerv");
	if(!_ptrc_glGetBufferPointerv) numFailed++;
	_ptrc_glGetBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, void *))IntGetProcAddress("glGetBufferSubData");
	if(!_ptrc_glGetBufferSubData) numFailed++;
	_ptrc_glGetQueryObjectiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryObjectiv");
	if(!_ptrc_glGetQueryObjectiv) numFailed++;
	_ptrc_glGetQueryObjectuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetQueryObjectuiv");
	if(!_ptrc_glGetQueryObjectuiv) numFailed++;
	_ptrc_glGetQueryiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetQueryiv");
	if(!_ptrc_glGetQueryiv) numFailed++;
	_ptrc_glIsBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsBuffer");
	if(!_ptrc_glIsBuffer) numFailed++;
	_ptrc_glIsQuery = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsQuery");
	if(!_ptrc_glIsQuery) numFailed++;
	_ptrc_glMapBuffer = (void * (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMapBuffer");
	if(!_ptrc_glMapBuffer) numFailed++;
	_ptrc_glUnmapBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glUnmapBuffer");
	if(!_ptrc_glUnmapBuffer) numFailed++;
	_ptrc_glAttachShader = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glAttachShader");
	if(!_ptrc_glAttachShader) numFailed++;
	_ptrc_glBindAttribLocation = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindAttribLocation");
	if(!_ptrc_glBindAttribLocation) numFailed++;
	_ptrc_glBlendEquationSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparate");
	if(!_ptrc_glBlendEquationSeparate) numFailed++;
	_ptrc_glCompileShader = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glCompileShader");
	if(!_ptrc_glCompileShader) numFailed++;
	_ptrc_glCreateProgram = (GLuint (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glCreateProgram");
	if(!_ptrc_glCreateProgram) numFailed++;
	_ptrc_glCreateShader = (GLuint (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCreateShader");
	if(!_ptrc_glCreateShader) numFailed++;
	_ptrc_glDeleteProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteProgram");
	if(!_ptrc_glDeleteProgram) numFailed++;
	_ptrc_glDeleteShader = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteShader");
	if(!_ptrc_glDeleteShader) numFailed++;
	_ptrc_glDetachShader = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDetachShader");
	if(!_ptrc_glDetachShader) numFailed++;
	_ptrc_glDisableVertexAttribArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVertexAttribArray");
	if(!_ptrc_glDisableVertexAttribArray) numFailed++;
	_ptrc_glDrawBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffers");
	if(!_ptrc_glDrawBuffers) numFailed++;
	_ptrc_glEnableVertexAttribArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVertexAttribArray");
	if(!_ptrc_glEnableVertexAttribArray) numFailed++;
	_ptrc_glGetActiveAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveAttrib");
	if(!_ptrc_glGetActiveAttrib) numFailed++;
	_ptrc_glGetActiveUniform = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveUniform");
	if(!_ptrc_glGetActiveUniform) numFailed++;
	_ptrc_glGetAttachedShaders = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLuint *))IntGetProcAddress("glGetAttachedShaders");
	if(!_ptrc_glGetAttachedShaders) numFailed++;
	_ptrc_glGetAttribLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetAttribLocation");
	if(!_ptrc_glGetAttribLocation) numFailed++;
	_ptrc_glGetProgramInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramInfoLog");
	if(!_ptrc_glGetProgramInfoLog) numFailed++;
	_ptrc_glGetProgramiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramiv");
	if(!_ptrc_glGetProgramiv) numFailed++;
	_ptrc_glGetShaderInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetShaderInfoLog");
	if(!_ptrc_glGetShaderInfoLog) numFailed++;
	_ptrc_glGetShaderSource = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetShaderSource");
	if(!_ptrc_glGetShaderSource) numFailed++;
	_ptrc_glGetShaderiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetShaderiv");
	if(!_ptrc_glGetShaderiv) numFailed++;
	_ptrc_glGetUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformLocation");
	if(!_ptrc_glGetUniformLocation) numFailed++;
	_ptrc_glGetUniformfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat *))IntGetProcAddress("glGetUniformfv");
	if(!_ptrc_glGetUniformfv) numFailed++;
	_ptrc_glGetUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint *))IntGetProcAddress("glGetUniformiv");
	if(!_ptrc_glGetUniformiv) numFailed++;
	_ptrc_glGetVertexAttribPointerv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetVertexAttribPointerv");
	if(!_ptrc_glGetVertexAttribPointerv) numFailed++;
	_ptrc_glGetVertexAttribdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdv");
	if(!_ptrc_glGetVertexAttribdv) numFailed++;
	_ptrc_glGetVertexAttribfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfv");
	if(!_ptrc_glGetVertexAttribfv) numFailed++;
	_ptrc_glGetVertexAttribiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribiv");
	if(!_ptrc_glGetVertexAttribiv) numFailed++;
	_ptrc_glIsProgram = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgram");
	if(!_ptrc_glIsProgram) numFailed++;
	_ptrc_glIsShader = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsShader");
	if(!_ptrc_glIsShader) numFailed++;
	_ptrc_glLinkProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glLinkProgram");
	if(!_ptrc_glLinkProgram) numFailed++;
	_ptrc_glShaderSource = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, const GLint *))IntGetProcAddress("glShaderSource");
	if(!_ptrc_glShaderSource) numFailed++;
	_ptrc_glStencilFuncSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLuint))IntGetProcAddress("glStencilFuncSeparate");
	if(!_ptrc_glStencilFuncSeparate) numFailed++;
	_ptrc_glStencilMaskSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glStencilMaskSeparate");
	if(!_ptrc_glStencilMaskSeparate) numFailed++;
	_ptrc_glStencilOpSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glStencilOpSeparate");
	if(!_ptrc_glStencilOpSeparate) numFailed++;
	_ptrc_glUniform1f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat))IntGetProcAddress("glUniform1f");
	if(!_ptrc_glUniform1f) numFailed++;
	_ptrc_glUniform1fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform1fv");
	if(!_ptrc_glUniform1fv) numFailed++;
	_ptrc_glUniform1i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glUniform1i");
	if(!_ptrc_glUniform1i) numFailed++;
	_ptrc_glUniform1iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform1iv");
	if(!_ptrc_glUniform1iv) numFailed++;
	_ptrc_glUniform2f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat))IntGetProcAddress("glUniform2f");
	if(!_ptrc_glUniform2f) numFailed++;
	_ptrc_glUniform2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform2fv");
	if(!_ptrc_glUniform2fv) numFailed++;
	_ptrc_glUniform2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glUniform2i");
	if(!_ptrc_glUniform2i) numFailed++;
	_ptrc_glUniform2iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform2iv");
	if(!_ptrc_glUniform2iv) numFailed++;
	_ptrc_glUniform3f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform3f");
	if(!_ptrc_glUniform3f) numFailed++;
	_ptrc_glUniform3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform3fv");
	if(!_ptrc_glUniform3fv) numFailed++;
	_ptrc_glUniform3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform3i");
	if(!_ptrc_glUniform3i) numFailed++;
	_ptrc_glUniform3iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform3iv");
	if(!_ptrc_glUniform3iv) numFailed++;
	_ptrc_glUniform4f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform4f");
	if(!_ptrc_glUniform4f) numFailed++;
	_ptrc_glUniform4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform4fv");
	if(!_ptrc_glUniform4fv) numFailed++;
	_ptrc_glUniform4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform4i");
	if(!_ptrc_glUniform4i) numFailed++;
	_ptrc_glUniform4iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform4iv");
	if(!_ptrc_glUniform4iv) numFailed++;
	_ptrc_glUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2fv");
	if(!_ptrc_glUniformMatrix2fv) numFailed++;
	_ptrc_glUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3fv");
	if(!_ptrc_glUniformMatrix3fv) numFailed++;
	_ptrc_glUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4fv");
	if(!_ptrc_glUniformMatrix4fv) numFailed++;
	_ptrc_glUseProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUseProgram");
	if(!_ptrc_glUseProgram) numFailed++;
	_ptrc_glValidateProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgram");
	if(!_ptrc_glValidateProgram) numFailed++;
	_ptrc_glVertexAttrib1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1d");
	if(!_ptrc_glVertexAttrib1d) numFailed++;
	_ptrc_glVertexAttrib1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dv");
	if(!_ptrc_glVertexAttrib1dv) numFailed++;
	_ptrc_glVertexAttrib1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1f");
	if(!_ptrc_glVertexAttrib1f) numFailed++;
	_ptrc_glVertexAttrib1fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fv");
	if(!_ptrc_glVertexAttrib1fv) numFailed++;
	_ptrc_glVertexAttrib1s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1s");
	if(!_ptrc_glVertexAttrib1s) numFailed++;
	_ptrc_glVertexAttrib1sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1sv");
	if(!_ptrc_glVertexAttrib1sv) numFailed++;
	_ptrc_glVertexAttrib2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2d");
	if(!_ptrc_glVertexAttrib2d) numFailed++;
	_ptrc_glVertexAttrib2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dv");
	if(!_ptrc_glVertexAttrib2dv) numFailed++;
	_ptrc_glVertexAttrib2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2f");
	if(!_ptrc_glVertexAttrib2f) numFailed++;
	_ptrc_glVertexAttrib2fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fv");
	if(!_ptrc_glVertexAttrib2fv) numFailed++;
	_ptrc_glVertexAttrib2s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2s");
	if(!_ptrc_glVertexAttrib2s) numFailed++;
	_ptrc_glVertexAttrib2sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2sv");
	if(!_ptrc_glVertexAttrib2sv) numFailed++;
	_ptrc_glVertexAttrib3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3d");
	if(!_ptrc_glVertexAttrib3d) numFailed++;
	_ptrc_glVertexAttrib3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dv");
	if(!_ptrc_glVertexAttrib3dv) numFailed++;
	_ptrc_glVertexAttrib3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3f");
	if(!_ptrc_glVertexAttrib3f) numFailed++;
	_ptrc_glVertexAttrib3fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fv");
	if(!_ptrc_glVertexAttrib3fv) numFailed++;
	_ptrc_glVertexAttrib3s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3s");
	if(!_ptrc_glVertexAttrib3s) numFailed++;
	_ptrc_glVertexAttrib3sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3sv");
	if(!_ptrc_glVertexAttrib3sv) numFailed++;
	_ptrc_glVertexAttrib4Nbv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4Nbv");
	if(!_ptrc_glVertexAttrib4Nbv) numFailed++;
	_ptrc_glVertexAttrib4Niv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4Niv");
	if(!_ptrc_glVertexAttrib4Niv) numFailed++;
	_ptrc_glVertexAttrib4Nsv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4Nsv");
	if(!_ptrc_glVertexAttrib4Nsv) numFailed++;
	_ptrc_glVertexAttrib4Nub = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4Nub");
	if(!_ptrc_glVertexAttrib4Nub) numFailed++;
	_ptrc_glVertexAttrib4Nubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4Nubv");
	if(!_ptrc_glVertexAttrib4Nubv) numFailed++;
	_ptrc_glVertexAttrib4Nuiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4Nuiv");
	if(!_ptrc_glVertexAttrib4Nuiv) numFailed++;
	_ptrc_glVertexAttrib4Nusv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4Nusv");
	if(!_ptrc_glVertexAttrib4Nusv) numFailed++;
	_ptrc_glVertexAttrib4bv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4bv");
	if(!_ptrc_glVertexAttrib4bv) numFailed++;
	_ptrc_glVertexAttrib4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4d");
	if(!_ptrc_glVertexAttrib4d) numFailed++;
	_ptrc_glVertexAttrib4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dv");
	if(!_ptrc_glVertexAttrib4dv) numFailed++;
	_ptrc_glVertexAttrib4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4f");
	if(!_ptrc_glVertexAttrib4f) numFailed++;
	_ptrc_glVertexAttrib4fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fv");
	if(!_ptrc_glVertexAttrib4fv) numFailed++;
	_ptrc_glVertexAttrib4iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4iv");
	if(!_ptrc_glVertexAttrib4iv) numFailed++;
	_ptrc_glVertexAttrib4s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4s");
	if(!_ptrc_glVertexAttrib4s) numFailed++;
	_ptrc_glVertexAttrib4sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4sv");
	if(!_ptrc_glVertexAttrib4sv) numFailed++;
	_ptrc_glVertexAttrib4ubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubv");
	if(!_ptrc_glVertexAttrib4ubv) numFailed++;
	_ptrc_glVertexAttrib4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4uiv");
	if(!_ptrc_glVertexAttrib4uiv) numFailed++;
	_ptrc_glVertexAttrib4usv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4usv");
	if(!_ptrc_glVertexAttrib4usv) numFailed++;
	_ptrc_glVertexAttribPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *))IntGetProcAddress("glVertexAttribPointer");
	if(!_ptrc_glVertexAttribPointer) numFailed++;
	_ptrc_glUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2x3fv");
	if(!_ptrc_glUniformMatrix2x3fv) numFailed++;
	_ptrc_glUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2x4fv");
	if(!_ptrc_glUniformMatrix2x4fv) numFailed++;
	_ptrc_glUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3x2fv");
	if(!_ptrc_glUniformMatrix3x2fv) numFailed++;
	_ptrc_glUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3x4fv");
	if(!_ptrc_glUniformMatrix3x4fv) numFailed++;
	_ptrc_glUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4x2fv");
	if(!_ptrc_glUniformMatrix4x2fv) numFailed++;
	_ptrc_glUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4x3fv");
	if(!_ptrc_glUniformMatrix4x3fv) numFailed++;
	_ptrc_glBeginConditionalRender = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBeginConditionalRender");
	if(!_ptrc_glBeginConditionalRender) numFailed++;
	_ptrc_glBeginTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBeginTransformFeedback");
	if(!_ptrc_glBeginTransformFeedback) numFailed++;
	_ptrc_glBindBufferBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBase");
	if(!_ptrc_glBindBufferBase) numFailed++;
	_ptrc_glBindBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRange");
	if(!_ptrc_glBindBufferRange) numFailed++;
	_ptrc_glBindFragDataLocation = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocation");
	if(!_ptrc_glBindFragDataLocation) numFailed++;
	_ptrc_glBindFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebuffer");
	if(!_ptrc_glBindFramebuffer) numFailed++;
	_ptrc_glBindRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbuffer");
	if(!_ptrc_glBindRenderbuffer) numFailed++;
	_ptrc_glBindVertexArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexArray");
	if(!_ptrc_glBindVertexArray) numFailed++;
	_ptrc_glBlitFramebuffer = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebuffer");
	if(!_ptrc_glBlitFramebuffer) numFailed++;
	_ptrc_glCheckFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatus");
	if(!_ptrc_glCheckFramebufferStatus) numFailed++;
	_ptrc_glClampColor = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClampColor");
	if(!_ptrc_glClampColor) numFailed++;
	_ptrc_glClearBufferfi = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLfloat, GLint))IntGetProcAddress("glClearBufferfi");
	if(!_ptrc_glClearBufferfi) numFailed++;
	_ptrc_glClearBufferfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLfloat *))IntGetProcAddress("glClearBufferfv");
	if(!_ptrc_glClearBufferfv) numFailed++;
	_ptrc_glClearBufferiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLint *))IntGetProcAddress("glClearBufferiv");
	if(!_ptrc_glClearBufferiv) numFailed++;
	_ptrc_glClearBufferuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLuint *))IntGetProcAddress("glClearBufferuiv");
	if(!_ptrc_glClearBufferuiv) numFailed++;
	_ptrc_glColorMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMaski");
	if(!_ptrc_glColorMaski) numFailed++;
	_ptrc_glDeleteFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffers");
	if(!_ptrc_glDeleteFramebuffers) numFailed++;
	_ptrc_glDeleteRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffers");
	if(!_ptrc_glDeleteRenderbuffers) numFailed++;
	_ptrc_glDeleteVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteVertexArrays");
	if(!_ptrc_glDeleteVertexArrays) numFailed++;
	_ptrc_glDisablei = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisablei");
	if(!_ptrc_glDisablei) numFailed++;
	_ptrc_glEnablei = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnablei");
	if(!_ptrc_glEnablei) numFailed++;
	_ptrc_glEndConditionalRender = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndConditionalRender");
	if(!_ptrc_glEndConditionalRender) numFailed++;
	_ptrc_glEndTransformFeedback = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glEndTransformFeedback");
	if(!_ptrc_glEndTransformFeedback) numFailed++;
	_ptrc_glFlushMappedBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedBufferRange");
	if(!_ptrc_glFlushMappedBufferRange) numFailed++;
	_ptrc_glFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbuffer");
	if(!_ptrc_glFramebufferRenderbuffer) numFailed++;
	_ptrc_glFramebufferTexture1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1D");
	if(!_ptrc_glFramebufferTexture1D) numFailed++;
	_ptrc_glFramebufferTexture2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2D");
	if(!_ptrc_glFramebufferTexture2D) numFailed++;
	_ptrc_glFramebufferTexture3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3D");
	if(!_ptrc_glFramebufferTexture3D) numFailed++;
	_ptrc_glFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayer");
	if(!_ptrc_glFramebufferTextureLayer) numFailed++;
	_ptrc_glGenFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffers");
	if(!_ptrc_glGenFramebuffers) numFailed++;
	_ptrc_glGenRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffers");
	if(!_ptrc_glGenRenderbuffers) numFailed++;
	_ptrc_glGenVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenVertexArrays");
	if(!_ptrc_glGenVertexArrays) numFailed++;
	_ptrc_glGenerateMipmap = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmap");
	if(!_ptrc_glGenerateMipmap) numFailed++;
	_ptrc_glGetBooleani_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleani_v");
	if(!_ptrc_glGetBooleani_v) numFailed++;
	_ptrc_glGetFragDataLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataLocation");
	if(!_ptrc_glGetFragDataLocation) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetIntegeri_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegeri_v");
	if(!_ptrc_glGetIntegeri_v) numFailed++;
	_ptrc_glGetRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameteriv");
	if(!_ptrc_glGetRenderbufferParameteriv) numFailed++;
	_ptrc_glGetStringi = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glGetStringi");
	if(!_ptrc_glGetStringi) numFailed++;
	_ptrc_glGetTexParameterIiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameterIiv");
	if(!_ptrc_glGetTexParameterIiv) numFailed++;
	_ptrc_glGetTexParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTexParameterIuiv");
	if(!_ptrc_glGetTexParameterIuiv) numFailed++;
	_ptrc_glGetTransformFeedbackVarying = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *))IntGetProcAddress("glGetTransformFeedbackVarying");
	if(!_ptrc_glGetTransformFeedbackVarying) numFailed++;
	_ptrc_glGetUniformuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint *))IntGetProcAddress("glGetUniformuiv");
	if(!_ptrc_glGetUniformuiv) numFailed++;
	_ptrc_glGetVertexAttribIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribIiv");
	if(!_ptrc_glGetVertexAttribIiv) numFailed++;
	_ptrc_glGetVertexAttribIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetVertexAttribIuiv");
	if(!_ptrc_glGetVertexAttribIuiv) numFailed++;
	_ptrc_glIsEnabledi = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledi");
	if(!_ptrc_glIsEnabledi) numFailed++;
	_ptrc_glIsFramebuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebuffer");
	if(!_ptrc_glIsFramebuffer) numFailed++;
	_ptrc_glIsRenderbuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbuffer");
	if(!_ptrc_glIsRenderbuffer) numFailed++;
	_ptrc_glIsVertexArray = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsVertexArray");
	if(!_ptrc_glIsVertexArray) numFailed++;
	_ptrc_glMapBufferRange = (void * (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapBufferRange");
	if(!_ptrc_glMapBufferRange) numFailed++;
	_ptrc_glRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorage");
	if(!_ptrc_glRenderbufferStorage) numFailed++;
	_ptrc_glRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisample");
	if(!_ptrc_glRenderbufferStorageMultisample) numFailed++;
	_ptrc_glTexParameterIiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameterIiv");
	if(!_ptrc_glTexParameterIiv) numFailed++;
	_ptrc_glTexParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glTexParameterIuiv");
	if(!_ptrc_glTexParameterIuiv) numFailed++;
	_ptrc_glTransformFeedbackVaryings = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLenum))IntGetProcAddress("glTransformFeedbackVaryings");
	if(!_ptrc_glTransformFeedbackVaryings) numFailed++;
	_ptrc_glUniform1ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint))IntGetProcAddress("glUniform1ui");
	if(!_ptrc_glUniform1ui) numFailed++;
	_ptrc_glUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform1uiv");
	if(!_ptrc_glUniform1uiv) numFailed++;
	_ptrc_glUniform2ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint))IntGetProcAddress("glUniform2ui");
	if(!_ptrc_glUniform2ui) numFailed++;
	_ptrc_glUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform2uiv");
	if(!_ptrc_glUniform2uiv) numFailed++;
	_ptrc_glUniform3ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform3ui");
	if(!_ptrc_glUniform3ui) numFailed++;
	_ptrc_glUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform3uiv");
	if(!_ptrc_glUniform3uiv) numFailed++;
	_ptrc_glUniform4ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform4ui");
	if(!_ptrc_glUniform4ui) numFailed++;
	_ptrc_glUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform4uiv");
	if(!_ptrc_glUniform4uiv) numFailed++;
	_ptrc_glVertexAttribI1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glVertexAttribI1i");
	if(!_ptrc_glVertexAttribI1i) numFailed++;
	_ptrc_glVertexAttribI1iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI1iv");
	if(!_ptrc_glVertexAttribI1iv) numFailed++;
	_ptrc_glVertexAttribI1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribI1ui");
	if(!_ptrc_glVertexAttribI1ui) numFailed++;
	_ptrc_glVertexAttribI1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI1uiv");
	if(!_ptrc_glVertexAttribI1uiv) numFailed++;
	_ptrc_glVertexAttribI2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glVertexAttribI2i");
	if(!_ptrc_glVertexAttribI2i) numFailed++;
	_ptrc_glVertexAttribI2iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI2iv");
	if(!_ptrc_glVertexAttribI2iv) numFailed++;
	_ptrc_glVertexAttribI2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI2ui");
	if(!_ptrc_glVertexAttribI2ui) numFailed++;
	_ptrc_glVertexAttribI2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI2uiv");
	if(!_ptrc_glVertexAttribI2uiv) numFailed++;
	_ptrc_glVertexAttribI3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI3i");
	if(!_ptrc_glVertexAttribI3i) numFailed++;
	_ptrc_glVertexAttribI3iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI3iv");
	if(!_ptrc_glVertexAttribI3iv) numFailed++;
	_ptrc_glVertexAttribI3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI3ui");
	if(!_ptrc_glVertexAttribI3ui) numFailed++;
	_ptrc_glVertexAttribI3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI3uiv");
	if(!_ptrc_glVertexAttribI3uiv) numFailed++;
	_ptrc_glVertexAttribI4bv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttribI4bv");
	if(!_ptrc_glVertexAttribI4bv) numFailed++;
	_ptrc_glVertexAttribI4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI4i");
	if(!_ptrc_glVertexAttribI4i) numFailed++;
	_ptrc_glVertexAttribI4iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI4iv");
	if(!_ptrc_glVertexAttribI4iv) numFailed++;
	_ptrc_glVertexAttribI4sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttribI4sv");
	if(!_ptrc_glVertexAttribI4sv) numFailed++;
	_ptrc_glVertexAttribI4ubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttribI4ubv");
	if(!_ptrc_glVertexAttribI4ubv) numFailed++;
	_ptrc_glVertexAttribI4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI4ui");
	if(!_ptrc_glVertexAttribI4ui) numFailed++;
	_ptrc_glVertexAttribI4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI4uiv");
	if(!_ptrc_glVertexAttribI4uiv) numFailed++;
	_ptrc_glVertexAttribI4usv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttribI4usv");
	if(!_ptrc_glVertexAttribI4usv) numFailed++;
	_ptrc_glVertexAttribIPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glVertexAttribIPointer");
	if(!_ptrc_glVertexAttribIPointer) numFailed++;
	_ptrc_glCopyBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyBufferSubData");
	if(!_ptrc_glCopyBufferSubData) numFailed++;
	_ptrc_glDrawArraysInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstanced");
	if(!_ptrc_glDrawArraysInstanced) numFailed++;
	_ptrc_glDrawElementsInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei))IntGetProcAddress("glDrawElementsInstanced");
	if(!_ptrc_glDrawElementsInstanced) numFailed++;
	_ptrc_glGetActiveUniformBlockName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformBlockName");
	if(!_ptrc_glGetActiveUniformBlockName) numFailed++;
	_ptrc_glGetActiveUniformBlockiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformBlockiv");
	if(!_ptrc_glGetActiveUniformBlockiv) numFailed++;
	_ptrc_glGetActiveUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformName");
	if(!_ptrc_glGetActiveUniformName) numFailed++;
	_ptrc_glGetActiveUniformsiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformsiv");
	if(!_ptrc_glGetActiveUniformsiv) numFailed++;
	_ptrc_glGetUniformBlockIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformBlockIndex");
	if(!_ptrc_glGetUniformBlockIndex) numFailed++;
	_ptrc_glGetUniformIndices = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLuint *))IntGetProcAddress("glGetUniformIndices");
	if(!_ptrc_glGetUniformIndices) numFailed++;
	_ptrc_glPrimitiveRestartIndex = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glPrimitiveRestartIndex");
	if(!_ptrc_glPrimitiveRestartIndex) numFailed++;
	_ptrc_glTexBuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBuffer");
	if(!_ptrc_glTexBuffer) numFailed++;
	_ptrc_glUniformBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glUniformBlockBinding");
	if(!_ptrc_glUniformBlockBinding) numFailed++;
	_ptrc_glClientWaitSync = (GLenum (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glClientWaitSync");
	if(!_ptrc_glClientWaitSync) numFailed++;
	_ptrc_glDeleteSync = (void (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glDeleteSync");
	if(!_ptrc_glDeleteSync) numFailed++;
	_ptrc_glDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLint))IntGetProcAddress("glDrawElementsBaseVertex");
	if(!_ptrc_glDrawElementsBaseVertex) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint))IntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!_ptrc_glDrawElementsInstancedBaseVertex) numFailed++;
	_ptrc_glDrawRangeElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint))IntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!_ptrc_glDrawRangeElementsBaseVertex) numFailed++;
	_ptrc_glFenceSync = (GLsync (CODEGEN_FUNCPTR *)(GLenum, GLbitfield))IntGetProcAddress("glFenceSync");
	if(!_ptrc_glFenceSync) numFailed++;
	_ptrc_glFramebufferTexture = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture");
	if(!_ptrc_glFramebufferTexture) numFailed++;
	_ptrc_glGetBufferParameteri64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint64 *))IntGetProcAddress("glGetBufferParameteri64v");
	if(!_ptrc_glGetBufferParameteri64v) numFailed++;
	_ptrc_glGetInteger64i_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint64 *))IntGetProcAddress("glGetInteger64i_v");
	if(!_ptrc_glGetInteger64i_v) numFailed++;
	_ptrc_glGetInteger64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLint64 *))IntGetProcAddress("glGetInteger64v");
	if(!_ptrc_glGetInteger64v) numFailed++;
	_ptrc_glGetMultisamplefv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefv");
	if(!_ptrc_glGetMultisamplefv) numFailed++;
	_ptrc_glGetSynciv = (void (CODEGEN_FUNCPTR *)(GLsync, GLenum, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetSynciv");
	if(!_ptrc_glGetSynciv) numFailed++;
	_ptrc_glIsSync = (GLboolean (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glIsSync");
	if(!_ptrc_glIsSync) numFailed++;
	_ptrc_glMultiDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei, const GLint *))IntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!_ptrc_glMultiDrawElementsBaseVertex) numFailed++;
	_ptrc_glProvokingVertex = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertex");
	if(!_ptrc_glProvokingVertex) numFailed++;
	_ptrc_glSampleMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaski");
	if(!_ptrc_glSampleMaski) numFailed++;
	_ptrc_glTexImage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisample");
	if(!_ptrc_glTexImage2DMultisample) numFailed++;
	_ptrc_glTexImage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisample");
	if(!_ptrc_glTexImage3DMultisample) numFailed++;
	_ptrc_glWaitSync = (void (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glWaitSync");
	if(!_ptrc_glWaitSync) numFailed++;
	_ptrc_glBindFragDataLocationIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationIndexed");
	if(!_ptrc_glBindFragDataLocationIndexed) numFailed++;
	_ptrc_glBindSampler = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindSampler");
	if(!_ptrc_glBindSampler) numFailed++;
	_ptrc_glDeleteSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteSamplers");
	if(!_ptrc_glDeleteSamplers) numFailed++;
	_ptrc_glGenSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenSamplers");
	if(!_ptrc_glGenSamplers) numFailed++;
	_ptrc_glGetFragDataIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataIndex");
	if(!_ptrc_glGetFragDataIndex) numFailed++;
	_ptrc_glGetQueryObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64v");
	if(!_ptrc_glGetQueryObjecti64v) numFailed++;
	_ptrc_glGetQueryObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64v");
	if(!_ptrc_glGetQueryObjectui64v) numFailed++;
	_ptrc_glGetSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameterIiv");
	if(!_ptrc_glGetSamplerParameterIiv) numFailed++;
	_ptrc_glGetSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetSamplerParameterIuiv");
	if(!_ptrc_glGetSamplerParameterIuiv) numFailed++;
	_ptrc_glGetSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetSamplerParameterfv");
	if(!_ptrc_glGetSamplerParameterfv) numFailed++;
	_ptrc_glGetSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameteriv");
	if(!_ptrc_glGetSamplerParameteriv) numFailed++;
	_ptrc_glIsSampler = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsSampler");
	if(!_ptrc_glIsSampler) numFailed++;
	_ptrc_glQueryCounter = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glQueryCounter");
	if(!_ptrc_glQueryCounter) numFailed++;
	_ptrc_glSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameterIiv");
	if(!_ptrc_glSamplerParameterIiv) numFailed++;
	_ptrc_glSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glSamplerParameterIuiv");
	if(!_ptrc_glSamplerParameterIuiv) numFailed++;
	_ptrc_glSamplerParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glSamplerParameterf");
	if(!_ptrc_glSamplerParameterf) numFailed++;
	_ptrc_glSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glSamplerParameterfv");
	if(!_ptrc_glSamplerParameterfv) numFailed++;
	_ptrc_glSamplerParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glSamplerParameteri");
	if(!_ptrc_glSamplerParameteri) numFailed++;
	_ptrc_glSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameteriv");
	if(!_ptrc_glSamplerParameteriv) numFailed++;
	_ptrc_glVertexAttribDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribDivisor");
	if(!_ptrc_glVertexAttribDivisor) numFailed++;
	_ptrc_glVertexAttribP1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP1ui");
	if(!_ptrc_glVertexAttribP1ui) numFailed++;
	_ptrc_glVertexAttribP1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP1uiv");
	if(!_ptrc_glVertexAttribP1uiv) numFailed++;
	_ptrc_glVertexAttribP2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP2ui");
	if(!_ptrc_glVertexAttribP2ui) numFailed++;
	_ptrc_glVertexAttribP2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP2uiv");
	if(!_ptrc_glVertexAttribP2uiv) numFailed++;
	_ptrc_glVertexAttribP3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP3ui");
	if(!_ptrc_glVertexAttribP3ui) numFailed++;
	_ptrc_glVertexAttribP3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP3uiv");
	if(!_ptrc_glVertexAttribP3uiv) numFailed++;
	_ptrc_glVertexAttribP4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP4ui");
	if(!_ptrc_glVertexAttribP4ui) numFailed++;
	_ptrc_glVertexAttribP4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP4uiv");
	if(!_ptrc_glVertexAttribP4uiv) numFailed++;
	_ptrc_glBeginQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBeginQueryIndexed");
	if(!_ptrc_glBeginQueryIndexed) numFailed++;
	_ptrc_glBindTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedback");
	if(!_ptrc_glBindTransformFeedback) numFailed++;
	_ptrc_glBlendEquationSeparatei = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparatei");
	if(!_ptrc_glBlendEquationSeparatei) numFailed++;
	_ptrc_glBlendEquationi = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBlendEquationi");
	if(!_ptrc_glBlendEquationi) numFailed++;
	_ptrc_glBlendFuncSeparatei = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparatei");
	if(!_ptrc_glBlendFuncSeparatei) numFailed++;
	_ptrc_glBlendFunci = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendFunci");
	if(!_ptrc_glBlendFunci) numFailed++;
	_ptrc_glDeleteTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacks");
	if(!_ptrc_glDeleteTransformFeedbacks) numFailed++;
	_ptrc_glDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *))IntGetProcAddress("glDrawArraysIndirect");
	if(!_ptrc_glDrawArraysIndirect) numFailed++;
	_ptrc_glDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *))IntGetProcAddress("glDrawElementsIndirect");
	if(!_ptrc_glDrawElementsIndirect) numFailed++;
	_ptrc_glDrawTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedback");
	if(!_ptrc_glDrawTransformFeedback) numFailed++;
	_ptrc_glDrawTransformFeedbackStream = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glDrawTransformFeedbackStream");
	if(!_ptrc_glDrawTransformFeedbackStream) numFailed++;
	_ptrc_glEndQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEndQueryIndexed");
	if(!_ptrc_glEndQueryIndexed) numFailed++;
	_ptrc_glGenTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacks");
	if(!_ptrc_glGenTransformFeedbacks) numFailed++;
	_ptrc_glGetActiveSubroutineName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineName");
	if(!_ptrc_glGetActiveSubroutineName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!_ptrc_glGetActiveSubroutineUniformName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!_ptrc_glGetActiveSubroutineUniformiv) numFailed++;
	_ptrc_glGetProgramStageiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramStageiv");
	if(!_ptrc_glGetProgramStageiv) numFailed++;
	_ptrc_glGetQueryIndexediv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryIndexediv");
	if(!_ptrc_glGetQueryIndexediv) numFailed++;
	_ptrc_glGetSubroutineIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineIndex");
	if(!_ptrc_glGetSubroutineIndex) numFailed++;
	_ptrc_glGetSubroutineUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineUniformLocation");
	if(!_ptrc_glGetSubroutineUniformLocation) numFailed++;
	_ptrc_glGetUniformSubroutineuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint *))IntGetProcAddress("glGetUniformSubroutineuiv");
	if(!_ptrc_glGetUniformSubroutineuiv) numFailed++;
	_ptrc_glGetUniformdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble *))IntGetProcAddress("glGetUniformdv");
	if(!_ptrc_glGetUniformdv) numFailed++;
	_ptrc_glIsTransformFeedback = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedback");
	if(!_ptrc_glIsTransformFeedback) numFailed++;
	_ptrc_glMinSampleShading = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glMinSampleShading");
	if(!_ptrc_glMinSampleShading) numFailed++;
	_ptrc_glPatchParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPatchParameterfv");
	if(!_ptrc_glPatchParameterfv) numFailed++;
	_ptrc_glPatchParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPatchParameteri");
	if(!_ptrc_glPatchParameteri) numFailed++;
	_ptrc_glPauseTransformFeedback = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPauseTransformFeedback");
	if(!_ptrc_glPauseTransformFeedback) numFailed++;
	_ptrc_glResumeTransformFeedback = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glResumeTransformFeedback");
	if(!_ptrc_glResumeTransformFeedback) numFailed++;
	_ptrc_glUniform1d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble))IntGetProcAddress("glUniform1d");
	if(!_ptrc_glUniform1d) numFailed++;
	_ptrc_glUniform1dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform1dv");
	if(!_ptrc_glUniform1dv) numFailed++;
	_ptrc_glUniform2d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble))IntGetProcAddress("glUniform2d");
	if(!_ptrc_glUniform2d) numFailed++;
	_ptrc_glUniform2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform2dv");
	if(!_ptrc_glUniform2dv) numFailed++;
	_ptrc_glUniform3d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform3d");
	if(!_ptrc_glUniform3d) numFailed++;
	_ptrc_glUniform3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform3dv");
	if(!_ptrc_glUniform3dv) numFailed++;
	_ptrc_glUniform4d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform4d");
	if(!_ptrc_glUniform4d) numFailed++;
	_ptrc_glUniform4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform4dv");
	if(!_ptrc_glUniform4dv) numFailed++;
	_ptrc_glUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2dv");
	if(!_ptrc_glUniformMatrix2dv) numFailed++;
	_ptrc_glUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x3dv");
	if(!_ptrc_glUniformMatrix2x3dv) numFailed++;
	_ptrc_glUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x4dv");
	if(!_ptrc_glUniformMatrix2x4dv) numFailed++;
	_ptrc_glUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3dv");
	if(!_ptrc_glUniformMatrix3dv) numFailed++;
	_ptrc_glUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x2dv");
	if(!_ptrc_glUniformMatrix3x2dv) numFailed++;
	_ptrc_glUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x4dv");
	if(!_ptrc_glUniformMatrix3x4dv) numFailed++;
	_ptrc_glUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4dv");
	if(!_ptrc_glUniformMatrix4dv) numFailed++;
	_ptrc_glUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x2dv");
	if(!_ptrc_glUniformMatrix4x2dv) numFailed++;
	_ptrc_glUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x3dv");
	if(!_ptrc_glUniformMatrix4x3dv) numFailed++;
	_ptrc_glUniformSubroutinesuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glUniformSubroutinesuiv");
	if(!_ptrc_glUniformSubroutinesuiv) numFailed++;
	_ptrc_glActiveShaderProgram = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glActiveShaderProgram");
	if(!_ptrc_glActiveShaderProgram) numFailed++;
	_ptrc_glBindProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindProgramPipeline");
	if(!_ptrc_glBindProgramPipeline) numFailed++;
	_ptrc_glClearDepthf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glClearDepthf");
	if(!_ptrc_glClearDepthf) numFailed++;
	_ptrc_glCreateShaderProgramv = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLchar *const*))IntGetProcAddress("glCreateShaderProgramv");
	if(!_ptrc_glCreateShaderProgramv) numFailed++;
	_ptrc_glDeleteProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramPipelines");
	if(!_ptrc_glDeleteProgramPipelines) numFailed++;
	_ptrc_glDepthRangeArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glDepthRangeArrayv");
	if(!_ptrc_glDepthRangeArrayv) numFailed++;
	_ptrc_glDepthRangeIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glDepthRangeIndexed");
	if(!_ptrc_glDepthRangeIndexed) numFailed++;
	_ptrc_glDepthRangef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glDepthRangef");
	if(!_ptrc_glDepthRangef) numFailed++;
	_ptrc_glGenProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramPipelines");
	if(!_ptrc_glGenProgramPipelines) numFailed++;
	_ptrc_glGetDoublei_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_v");
	if(!_ptrc_glGetDoublei_v) numFailed++;
	_ptrc_glGetFloati_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_v");
	if(!_ptrc_glGetFloati_v) numFailed++;
	_ptrc_glGetProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLenum *, void *))IntGetProcAddress("glGetProgramBinary");
	if(!_ptrc_glGetProgramBinary) numFailed++;
	_ptrc_glGetProgramPipelineInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!_ptrc_glGetProgramPipelineInfoLog) numFailed++;
	_ptrc_glGetProgramPipelineiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramPipelineiv");
	if(!_ptrc_glGetProgramPipelineiv) numFailed++;
	_ptrc_glGetShaderPrecisionFormat = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *, GLint *))IntGetProcAddress("glGetShaderPrecisionFormat");
	if(!_ptrc_glGetShaderPrecisionFormat) numFailed++;
	_ptrc_glGetVertexAttribLdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdv");
	if(!_ptrc_glGetVertexAttribLdv) numFailed++;
	_ptrc_glIsProgramPipeline = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramPipeline");
	if(!_ptrc_glIsProgramPipeline) numFailed++;
	_ptrc_glProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const void *, GLsizei))IntGetProcAddress("glProgramBinary");
	if(!_ptrc_glProgramBinary) numFailed++;
	_ptrc_glProgramParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteri");
	if(!_ptrc_glProgramParameteri) numFailed++;
	_ptrc_glProgramUniform1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1d");
	if(!_ptrc_glProgramUniform1d) numFailed++;
	_ptrc_glProgramUniform1dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dv");
	if(!_ptrc_glProgramUniform1dv) numFailed++;
	_ptrc_glProgramUniform1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1f");
	if(!_ptrc_glProgramUniform1f) numFailed++;
	_ptrc_glProgramUniform1fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fv");
	if(!_ptrc_glProgramUniform1fv) numFailed++;
	_ptrc_glProgramUniform1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1i");
	if(!_ptrc_glProgramUniform1i) numFailed++;
	_ptrc_glProgramUniform1iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1iv");
	if(!_ptrc_glProgramUniform1iv) numFailed++;
	_ptrc_glProgramUniform1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1ui");
	if(!_ptrc_glProgramUniform1ui) numFailed++;
	_ptrc_glProgramUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uiv");
	if(!_ptrc_glProgramUniform1uiv) numFailed++;
	_ptrc_glProgramUniform2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2d");
	if(!_ptrc_glProgramUniform2d) numFailed++;
	_ptrc_glProgramUniform2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dv");
	if(!_ptrc_glProgramUniform2dv) numFailed++;
	_ptrc_glProgramUniform2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2f");
	if(!_ptrc_glProgramUniform2f) numFailed++;
	_ptrc_glProgramUniform2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fv");
	if(!_ptrc_glProgramUniform2fv) numFailed++;
	_ptrc_glProgramUniform2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2i");
	if(!_ptrc_glProgramUniform2i) numFailed++;
	_ptrc_glProgramUniform2iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2iv");
	if(!_ptrc_glProgramUniform2iv) numFailed++;
	_ptrc_glProgramUniform2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2ui");
	if(!_ptrc_glProgramUniform2ui) numFailed++;
	_ptrc_glProgramUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uiv");
	if(!_ptrc_glProgramUniform2uiv) numFailed++;
	_ptrc_glProgramUniform3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3d");
	if(!_ptrc_glProgramUniform3d) numFailed++;
	_ptrc_glProgramUniform3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dv");
	if(!_ptrc_glProgramUniform3dv) numFailed++;
	_ptrc_glProgramUniform3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3f");
	if(!_ptrc_glProgramUniform3f) numFailed++;
	_ptrc_glProgramUniform3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fv");
	if(!_ptrc_glProgramUniform3fv) numFailed++;
	_ptrc_glProgramUniform3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3i");
	if(!_ptrc_glProgramUniform3i) numFailed++;
	_ptrc_glProgramUniform3iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3iv");
	if(!_ptrc_glProgramUniform3iv) numFailed++;
	_ptrc_glProgramUniform3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3ui");
	if(!_ptrc_glProgramUniform3ui) numFailed++;
	_ptrc_glProgramUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uiv");
	if(!_ptrc_glProgramUniform3uiv) numFailed++;
	_ptrc_glProgramUniform4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4d");
	if(!_ptrc_glProgramUniform4d) numFailed++;
	_ptrc_glProgramUniform4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dv");
	if(!_ptrc_glProgramUniform4dv) numFailed++;
	_ptrc_glProgramUniform4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4f");
	if(!_ptrc_glProgramUniform4f) numFailed++;
	_ptrc_glProgramUniform4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fv");
	if(!_ptrc_glProgramUniform4fv) numFailed++;
	_ptrc_glProgramUniform4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4i");
	if(!_ptrc_glProgramUniform4i) numFailed++;
	_ptrc_glProgramUniform4iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4iv");
	if(!_ptrc_glProgramUniform4iv) numFailed++;
	_ptrc_glProgramUniform4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4ui");
	if(!_ptrc_glProgramUniform4ui) numFailed++;
	_ptrc_glProgramUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uiv");
	if(!_ptrc_glProgramUniform4uiv) numFailed++;
	_ptrc_glProgramUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dv");
	if(!_ptrc_glProgramUniformMatrix2dv) numFailed++;
	_ptrc_glProgramUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fv");
	if(!_ptrc_glProgramUniformMatrix2fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!_ptrc_glProgramUniformMatrix2x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!_ptrc_glProgramUniformMatrix2x3fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!_ptrc_glProgramUniformMatrix2x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!_ptrc_glProgramUniformMatrix2x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dv");
	if(!_ptrc_glProgramUniformMatrix3dv) numFailed++;
	_ptrc_glProgramUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fv");
	if(!_ptrc_glProgramUniformMatrix3fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!_ptrc_glProgramUniformMatrix3x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!_ptrc_glProgramUniformMatrix3x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!_ptrc_glProgramUniformMatrix3x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!_ptrc_glProgramUniformMatrix3x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dv");
	if(!_ptrc_glProgramUniformMatrix4dv) numFailed++;
	_ptrc_glProgramUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fv");
	if(!_ptrc_glProgramUniformMatrix4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!_ptrc_glProgramUniformMatrix4x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!_ptrc_glProgramUniformMatrix4x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!_ptrc_glProgramUniformMatrix4x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!_ptrc_glProgramUniformMatrix4x3fv) numFailed++;
	_ptrc_glReleaseShaderCompiler = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glReleaseShaderCompiler");
	if(!_ptrc_glReleaseShaderCompiler) numFailed++;
	_ptrc_glScissorArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *))IntGetProcAddress("glScissorArrayv");
	if(!_ptrc_glScissorArrayv) numFailed++;
	_ptrc_glScissorIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissorIndexed");
	if(!_ptrc_glScissorIndexed) numFailed++;
	_ptrc_glScissorIndexedv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glScissorIndexedv");
	if(!_ptrc_glScissorIndexedv) numFailed++;
	_ptrc_glShaderBinary = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLenum, const void *, GLsizei))IntGetProcAddress("glShaderBinary");
	if(!_ptrc_glShaderBinary) numFailed++;
	_ptrc_glUseProgramStages = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield, GLuint))IntGetProcAddress("glUseProgramStages");
	if(!_ptrc_glUseProgramStages) numFailed++;
	_ptrc_glValidateProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgramPipeline");
	if(!_ptrc_glValidateProgramPipeline) numFailed++;
	_ptrc_glVertexAttribL1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1d");
	if(!_ptrc_glVertexAttribL1d) numFailed++;
	_ptrc_glVertexAttribL1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dv");
	if(!_ptrc_glVertexAttribL1dv) numFailed++;
	_ptrc_glVertexAttribL2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2d");
	if(!_ptrc_glVertexAttribL2d) numFailed++;
	_ptrc_glVertexAttribL2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dv");
	if(!_ptrc_glVertexAttribL2dv) numFailed++;
	_ptrc_glVertexAttribL3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3d");
	if(!_ptrc_glVertexAttribL3d) numFailed++;
	_ptrc_glVertexAttribL3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dv");
	if(!_ptrc_glVertexAttribL3dv) numFailed++;
	_ptrc_glVertexAttribL4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4d");
	if(!_ptrc_glVertexAttribL4d) numFailed++;
	_ptrc_glVertexAttribL4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dv");
	if(!_ptrc_glVertexAttribL4dv) numFailed++;
	_ptrc_glVertexAttribLPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const void *))IntGetProcAddress("glVertexAttribLPointer");
	if(!_ptrc_glVertexAttribLPointer) numFailed++;
	_ptrc_glViewportArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glViewportArrayv");
	if(!_ptrc_glViewportArrayv) numFailed++;
	_ptrc_glViewportIndexedf = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glViewportIndexedf");
	if(!_ptrc_glViewportIndexedf) numFailed++;
	_ptrc_glViewportIndexedfv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glViewportIndexedfv");
	if(!_ptrc_glViewportIndexedfv) numFailed++;
	_ptrc_glBindImageTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum))IntGetProcAddress("glBindImageTexture");
	if(!_ptrc_glBindImageTexture) numFailed++;
	_ptrc_glDrawArraysInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei, GLuint))IntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!_ptrc_glDrawArraysInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertexBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseVertexBaseInstance) numFailed++;
	_ptrc_glDrawTransformFeedbackInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!_ptrc_glDrawTransformFeedbackInstanced) numFailed++;
	_ptrc_glDrawTransformFeedbackStreamInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!_ptrc_glDrawTransformFeedbackStreamInstanced) numFailed++;
	_ptrc_glGetActiveAtomicCounterBufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!_ptrc_glGetActiveAtomicCounterBufferiv) numFailed++;
	_ptrc_glGetInternalformativ = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetInternalformativ");
	if(!_ptrc_glGetInternalformativ) numFailed++;
	_ptrc_glMemoryBarrier = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrier");
	if(!_ptrc_glMemoryBarrier) numFailed++;
	_ptrc_glTexStorage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTexStorage1D");
	if(!_ptrc_glTexStorage1D) numFailed++;
	_ptrc_glTexStorage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTexStorage2D");
	if(!_ptrc_glTexStorage2D) numFailed++;
	_ptrc_glTexStorage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTexStorage3D");
	if(!_ptrc_glTexStorage3D) numFailed++;
	_ptrc_glBindVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glBindVertexBuffer");
	if(!_ptrc_glBindVertexBuffer) numFailed++;
	_ptrc_glClearBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferData");
	if(!_ptrc_glClearBufferData) numFailed++;
	_ptrc_glClearBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferSubData");
	if(!_ptrc_glClearBufferSubData) numFailed++;
	_ptrc_glCopyImageSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubData");
	if(!_ptrc_glCopyImageSubData) numFailed++;
	_ptrc_glDebugMessageCallback = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROC, const void *))IntGetProcAddress("glDebugMessageCallback");
	if(!_ptrc_glDebugMessageCallback) numFailed++;
	_ptrc_glDebugMessageControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControl");
	if(!_ptrc_glDebugMessageControl) numFailed++;
	_ptrc_glDebugMessageInsert = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsert");
	if(!_ptrc_glDebugMessageInsert) numFailed++;
	_ptrc_glDispatchCompute = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchCompute");
	if(!_ptrc_glDispatchCompute) numFailed++;
	_ptrc_glDispatchComputeIndirect = (void (CODEGEN_FUNCPTR *)(GLintptr))IntGetProcAddress("glDispatchComputeIndirect");
	if(!_ptrc_glDispatchComputeIndirect) numFailed++;
	_ptrc_glFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFramebufferParameteri");
	if(!_ptrc_glFramebufferParameteri) numFailed++;
	_ptrc_glGetDebugMessageLog = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLog");
	if(!_ptrc_glGetDebugMessageLog) numFailed++;
	_ptrc_glGetFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameteriv");
	if(!_ptrc_glGetFramebufferParameteriv) numFailed++;
	_ptrc_glGetInternalformati64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint64 *))IntGetProcAddress("glGetInternalformati64v");
	if(!_ptrc_glGetInternalformati64v) numFailed++;
	_ptrc_glGetObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectLabel");
	if(!_ptrc_glGetObjectLabel) numFailed++;
	_ptrc_glGetObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectPtrLabel");
	if(!_ptrc_glGetObjectPtrLabel) numFailed++;
	_ptrc_glGetProgramInterfaceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramInterfaceiv");
	if(!_ptrc_glGetProgramInterfaceiv) numFailed++;
	_ptrc_glGetProgramResourceIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceIndex");
	if(!_ptrc_glGetProgramResourceIndex) numFailed++;
	_ptrc_glGetProgramResourceLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocation");
	if(!_ptrc_glGetProgramResourceLocation) numFailed++;
	_ptrc_glGetProgramResourceLocationIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!_ptrc_glGetProgramResourceLocationIndex) numFailed++;
	_ptrc_glGetProgramResourceName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramResourceName");
	if(!_ptrc_glGetProgramResourceName) numFailed++;
	_ptrc_glGetProgramResourceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetProgramResourceiv");
	if(!_ptrc_glGetProgramResourceiv) numFailed++;
	_ptrc_glInvalidateBufferData = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glInvalidateBufferData");
	if(!_ptrc_glInvalidateBufferData) numFailed++;
	_ptrc_glInvalidateBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glInvalidateBufferSubData");
	if(!_ptrc_glInvalidateBufferSubData) numFailed++;
	_ptrc_glInvalidateFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateFramebuffer");
	if(!_ptrc_glInvalidateFramebuffer) numFailed++;
	_ptrc_glInvalidateSubFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateSubFramebuffer");
	if(!_ptrc_glInvalidateSubFramebuffer) numFailed++;
	_ptrc_glInvalidateTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glInvalidateTexImage");
	if(!_ptrc_glInvalidateTexImage) numFailed++;
	_ptrc_glInvalidateTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glInvalidateTexSubImage");
	if(!_ptrc_glInvalidateTexSubImage) numFailed++;
	_ptrc_glMultiDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirect");
	if(!_ptrc_glMultiDrawArraysIndirect) numFailed++;
	_ptrc_glMultiDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirect");
	if(!_ptrc_glMultiDrawElementsIndirect) numFailed++;
	_ptrc_glObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glObjectLabel");
	if(!_ptrc_glObjectLabel) numFailed++;
	_ptrc_glObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, const GLchar *))IntGetProcAddress("glObjectPtrLabel");
	if(!_ptrc_glObjectPtrLabel) numFailed++;
	_ptrc_glPopDebugGroup = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glPopDebugGroup");
	if(!_ptrc_glPopDebugGroup) numFailed++;
	_ptrc_glPushDebugGroup = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glPushDebugGroup");
	if(!_ptrc_glPushDebugGroup) numFailed++;
	_ptrc_glShaderStorageBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glShaderStorageBlockBinding");
	if(!_ptrc_glShaderStorageBlockBinding) numFailed++;
	_ptrc_glTexBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTexBufferRange");
	if(!_ptrc_glTexBufferRange) numFailed++;
	_ptrc_glTexStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage2DMultisample");
	if(!_ptrc_glTexStorage2DMultisample) numFailed++;
	_ptrc_glTexStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage3DMultisample");
	if(!_ptrc_glTexStorage3DMultisample) numFailed++;
	_ptrc_glTextureView = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glTextureView");
	if(!_ptrc_glTextureView) numFailed++;
	_ptrc_glVertexAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribBinding");
	if(!_ptrc_glVertexAttribBinding) numFailed++;
	_ptrc_glVertexAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribFormat");
	if(!_ptrc_glVertexAttribFormat) numFailed++;
	_ptrc_glVertexAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribIFormat");
	if(!_ptrc_glVertexAttribIFormat) numFailed++;
	_ptrc_glVertexAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribLFormat");
	if(!_ptrc_glVertexAttribLFormat) numFailed++;
	_ptrc_glVertexBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexBindingDivisor");
	if(!_ptrc_glVertexBindingDivisor) numFailed++;
	_ptrc_glBindBuffersBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindBuffersBase");
	if(!_ptrc_glBindBuffersBase) numFailed++;
	_ptrc_glBindBuffersRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *))IntGetProcAddress("glBindBuffersRange");
	if(!_ptrc_glBindBuffersRange) numFailed++;
	_ptrc_glBindImageTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindImageTextures");
	if(!_ptrc_glBindImageTextures) numFailed++;
	_ptrc_glBindSamplers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindSamplers");
	if(!_ptrc_glBindSamplers) numFailed++;
	_ptrc_glBindTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindTextures");
	if(!_ptrc_glBindTextures) numFailed++;
	_ptrc_glBindVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glBindVertexBuffers");
	if(!_ptrc_glBindVertexBuffers) numFailed++;
	_ptrc_glBufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glBufferStorage");
	if(!_ptrc_glBufferStorage) numFailed++;
	_ptrc_glClearTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexImage");
	if(!_ptrc_glClearTexImage) numFailed++;
	_ptrc_glClearTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexSubImage");
	if(!_ptrc_glClearTexSubImage) numFailed++;
	_ptrc_glBindTextureUnit = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindTextureUnit");
	if(!_ptrc_glBindTextureUnit) numFailed++;
	_ptrc_glBlitNamedFramebuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitNamedFramebuffer");
	if(!_ptrc_glBlitNamedFramebuffer) numFailed++;
	_ptrc_glCheckNamedFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCheckNamedFramebufferStatus");
	if(!_ptrc_glCheckNamedFramebufferStatus) numFailed++;
	_ptrc_glClearNamedBufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferData");
	if(!_ptrc_glClearNamedBufferData) numFailed++;
	_ptrc_glClearNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferSubData");
	if(!_ptrc_glClearNamedBufferSubData) numFailed++;
	_ptrc_glClearNamedFramebufferfi = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLfloat, GLint))IntGetProcAddress("glClearNamedFramebufferfi");
	if(!_ptrc_glClearNamedFramebufferfi) numFailed++;
	_ptrc_glClearNamedFramebufferfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLfloat *))IntGetProcAddress("glClearNamedFramebufferfv");
	if(!_ptrc_glClearNamedFramebufferfv) numFailed++;
	_ptrc_glClearNamedFramebufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLint *))IntGetProcAddress("glClearNamedFramebufferiv");
	if(!_ptrc_glClearNamedFramebufferiv) numFailed++;
	_ptrc_glClearNamedFramebufferuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, const GLuint *))IntGetProcAddress("glClearNamedFramebufferuiv");
	if(!_ptrc_glClearNamedFramebufferuiv) numFailed++;
	_ptrc_glClipControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClipControl");
	if(!_ptrc_glClipControl) numFailed++;
	_ptrc_glCompressedTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage1D");
	if(!_ptrc_glCompressedTextureSubImage1D) numFailed++;
	_ptrc_glCompressedTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage2D");
	if(!_ptrc_glCompressedTextureSubImage2D) numFailed++;
	_ptrc_glCompressedTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *))IntGetProcAddress("glCompressedTextureSubImage3D");
	if(!_ptrc_glCompressedTextureSubImage3D) numFailed++;
	_ptrc_glCopyNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyNamedBufferSubData");
	if(!_ptrc_glCopyNamedBufferSubData) numFailed++;
	_ptrc_glCopyTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTextureSubImage1D");
	if(!_ptrc_glCopyTextureSubImage1D) numFailed++;
	_ptrc_glCopyTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage2D");
	if(!_ptrc_glCopyTextureSubImage2D) numFailed++;
	_ptrc_glCopyTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage3D");
	if(!_ptrc_glCopyTextureSubImage3D) numFailed++;
	_ptrc_glCreateBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateBuffers");
	if(!_ptrc_glCreateBuffers) numFailed++;
	_ptrc_glCreateFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateFramebuffers");
	if(!_ptrc_glCreateFramebuffers) numFailed++;
	_ptrc_glCreateProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateProgramPipelines");
	if(!_ptrc_glCreateProgramPipelines) numFailed++;
	_ptrc_glCreateQueries = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glCreateQueries");
	if(!_ptrc_glCreateQueries) numFailed++;
	_ptrc_glCreateRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateRenderbuffers");
	if(!_ptrc_glCreateRenderbuffers) numFailed++;
	_ptrc_glCreateSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateSamplers");
	if(!_ptrc_glCreateSamplers) numFailed++;
	_ptrc_glCreateTextures = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glCreateTextures");
	if(!_ptrc_glCreateTextures) numFailed++;
	_ptrc_glCreateTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateTransformFeedbacks");
	if(!_ptrc_glCreateTransformFeedbacks) numFailed++;
	_ptrc_glCreateVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glCreateVertexArrays");
	if(!_ptrc_glCreateVertexArrays) numFailed++;
	_ptrc_glDisableVertexArrayAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDisableVertexArrayAttrib");
	if(!_ptrc_glDisableVertexArrayAttrib) numFailed++;
	_ptrc_glEnableVertexArrayAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glEnableVertexArrayAttrib");
	if(!_ptrc_glEnableVertexArrayAttrib) numFailed++;
	_ptrc_glFlushMappedNamedBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedNamedBufferRange");
	if(!_ptrc_glFlushMappedNamedBufferRange) numFailed++;
	_ptrc_glGenerateTextureMipmap = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGenerateTextureMipmap");
	if(!_ptrc_glGenerateTextureMipmap) numFailed++;
	_ptrc_glGetCompressedTextureImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, void *))IntGetProcAddress("glGetCompressedTextureImage");
	if(!_ptrc_glGetCompressedTextureImage) numFailed++;
	_ptrc_glGetCompressedTextureSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, void *))IntGetProcAddress("glGetCompressedTextureSubImage");
	if(!_ptrc_glGetCompressedTextureSubImage) numFailed++;
	_ptrc_glGetGraphicsResetStatus = (GLenum (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glGetGraphicsResetStatus");
	if(!_ptrc_glGetGraphicsResetStatus) numFailed++;
	_ptrc_glGetNamedBufferParameteri64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetNamedBufferParameteri64v");
	if(!_ptrc_glGetNamedBufferParameteri64v) numFailed++;
	_ptrc_glGetNamedBufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedBufferParameteriv");
	if(!_ptrc_glGetNamedBufferParameteriv) numFailed++;
	_ptrc_glGetNamedBufferPointerv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, void **))IntGetProcAddress("glGetNamedBufferPointerv");
	if(!_ptrc_glGetNamedBufferPointerv) numFailed++;
	_ptrc_glGetNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, void *))IntGetProcAddress("glGetNamedBufferSubData");
	if(!_ptrc_glGetNamedBufferSubData) numFailed++;
	_ptrc_glGetNamedFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetNamedFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetNamedFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferParameteriv");
	if(!_ptrc_glGetNamedFramebufferParameteriv) numFailed++;
	_ptrc_glGetNamedRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedRenderbufferParameteriv");
	if(!_ptrc_glGetNamedRenderbufferParameteriv) numFailed++;
	_ptrc_glGetQueryBufferObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjecti64v");
	if(!_ptrc_glGetQueryBufferObjecti64v) numFailed++;
	_ptrc_glGetQueryBufferObjectiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectiv");
	if(!_ptrc_glGetQueryBufferObjectiv) numFailed++;
	_ptrc_glGetQueryBufferObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectui64v");
	if(!_ptrc_glGetQueryBufferObjectui64v) numFailed++;
	_ptrc_glGetQueryBufferObjectuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptr))IntGetProcAddress("glGetQueryBufferObjectuiv");
	if(!_ptrc_glGetQueryBufferObjectuiv) numFailed++;
	_ptrc_glGetTextureImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetTextureImage");
	if(!_ptrc_glGetTextureImage) numFailed++;
	_ptrc_glGetTextureLevelParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureLevelParameterfv");
	if(!_ptrc_glGetTextureLevelParameterfv) numFailed++;
	_ptrc_glGetTextureLevelParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLint *))IntGetProcAddress("glGetTextureLevelParameteriv");
	if(!_ptrc_glGetTextureLevelParameteriv) numFailed++;
	_ptrc_glGetTextureParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterIiv");
	if(!_ptrc_glGetTextureParameterIiv) numFailed++;
	_ptrc_glGetTextureParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetTextureParameterIuiv");
	if(!_ptrc_glGetTextureParameterIuiv) numFailed++;
	_ptrc_glGetTextureParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureParameterfv");
	if(!_ptrc_glGetTextureParameterfv) numFailed++;
	_ptrc_glGetTextureParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTextureParameteriv");
	if(!_ptrc_glGetTextureParameteriv) numFailed++;
	_ptrc_glGetTextureSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetTextureSubImage");
	if(!_ptrc_glGetTextureSubImage) numFailed++;
	_ptrc_glGetTransformFeedbacki64_v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint64 *))IntGetProcAddress("glGetTransformFeedbacki64_v");
	if(!_ptrc_glGetTransformFeedbacki64_v) numFailed++;
	_ptrc_glGetTransformFeedbacki_v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint *))IntGetProcAddress("glGetTransformFeedbacki_v");
	if(!_ptrc_glGetTransformFeedbacki_v) numFailed++;
	_ptrc_glGetTransformFeedbackiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetTransformFeedbackiv");
	if(!_ptrc_glGetTransformFeedbackiv) numFailed++;
	_ptrc_glGetVertexArrayIndexed64iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetVertexArrayIndexed64iv");
	if(!_ptrc_glGetVertexArrayIndexed64iv) numFailed++;
	_ptrc_glGetVertexArrayIndexediv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIndexediv");
	if(!_ptrc_glGetVertexArrayIndexediv) numFailed++;
	_ptrc_glGetVertexArrayiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayiv");
	if(!_ptrc_glGetVertexArrayiv) numFailed++;
	_ptrc_glGetnCompressedTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, void *))IntGetProcAddress("glGetnCompressedTexImage");
	if(!_ptrc_glGetnCompressedTexImage) numFailed++;
	_ptrc_glGetnTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glGetnTexImage");
	if(!_ptrc_glGetnTexImage) numFailed++;
	_ptrc_glGetnUniformdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLdouble *))IntGetProcAddress("glGetnUniformdv");
	if(!_ptrc_glGetnUniformdv) numFailed++;
	_ptrc_glGetnUniformfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLfloat *))IntGetProcAddress("glGetnUniformfv");
	if(!_ptrc_glGetnUniformfv) numFailed++;
	_ptrc_glGetnUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLint *))IntGetProcAddress("glGetnUniformiv");
	if(!_ptrc_glGetnUniformiv) numFailed++;
	_ptrc_glGetnUniformuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLuint *))IntGetProcAddress("glGetnUniformuiv");
	if(!_ptrc_glGetnUniformuiv) numFailed++;
	_ptrc_glInvalidateNamedFramebufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateNamedFramebufferData");
	if(!_ptrc_glInvalidateNamedFramebufferData) numFailed++;
	_ptrc_glInvalidateNamedFramebufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateNamedFramebufferSubData");
	if(!_ptrc_glInvalidateNamedFramebufferSubData) numFailed++;
	_ptrc_glMapNamedBuffer = (void * (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMapNamedBuffer");
	if(!_ptrc_glMapNamedBuffer) numFailed++;
	_ptrc_glMapNamedBufferRange = (void * (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapNamedBufferRange");
	if(!_ptrc_glMapNamedBufferRange) numFailed++;
	_ptrc_glMemoryBarrierByRegion = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrierByRegion");
	if(!_ptrc_glMemoryBarrierByRegion) numFailed++;
	_ptrc_glNamedBufferData = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLenum))IntGetProcAddress("glNamedBufferData");
	if(!_ptrc_glNamedBufferData) numFailed++;
	_ptrc_glNamedBufferStorage = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glNamedBufferStorage");
	if(!_ptrc_glNamedBufferStorage) numFailed++;
	_ptrc_glNamedBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, const void *))IntGetProcAddress("glNamedBufferSubData");
	if(!_ptrc_glNamedBufferSubData) numFailed++;
	_ptrc_glNamedFramebufferDrawBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glNamedFramebufferDrawBuffer");
	if(!_ptrc_glNamedFramebufferDrawBuffer) numFailed++;
	_ptrc_glNamedFramebufferDrawBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glNamedFramebufferDrawBuffers");
	if(!_ptrc_glNamedFramebufferDrawBuffers) numFailed++;
	_ptrc_glNamedFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glNamedFramebufferParameteri");
	if(!_ptrc_glNamedFramebufferParameteri) numFailed++;
	_ptrc_glNamedFramebufferReadBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glNamedFramebufferReadBuffer");
	if(!_ptrc_glNamedFramebufferReadBuffer) numFailed++;
	_ptrc_glNamedFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glNamedFramebufferRenderbuffer");
	if(!_ptrc_glNamedFramebufferRenderbuffer) numFailed++;
	_ptrc_glNamedFramebufferTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture");
	if(!_ptrc_glNamedFramebufferTexture) numFailed++;
	_ptrc_glNamedFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTextureLayer");
	if(!_ptrc_glNamedFramebufferTextureLayer) numFailed++;
	_ptrc_glNamedRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorage");
	if(!_ptrc_glNamedRenderbufferStorage) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisample");
	if(!_ptrc_glNamedRenderbufferStorageMultisample) numFailed++;
	_ptrc_glReadnPixels = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *))IntGetProcAddress("glReadnPixels");
	if(!_ptrc_glReadnPixels) numFailed++;
	_ptrc_glTextureBarrier = (void (CODEGEN_FUNCPTR *)(void))IntGetProcAddress("glTextureBarrier");
	if(!_ptrc_glTextureBarrier) numFailed++;
	_ptrc_glTextureBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glTextureBuffer");
	if(!_ptrc_glTextureBuffer) numFailed++;
	_ptrc_glTextureBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTextureBufferRange");
	if(!_ptrc_glTextureBufferRange) numFailed++;
	_ptrc_glTextureParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glTextureParameterIiv");
	if(!_ptrc_glTextureParameterIiv) numFailed++;
	_ptrc_glTextureParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glTextureParameterIuiv");
	if(!_ptrc_glTextureParameterIuiv) numFailed++;
	_ptrc_glTextureParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glTextureParameterf");
	if(!_ptrc_glTextureParameterf) numFailed++;
	_ptrc_glTextureParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glTextureParameterfv");
	if(!_ptrc_glTextureParameterfv) numFailed++;
	_ptrc_glTextureParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glTextureParameteri");
	if(!_ptrc_glTextureParameteri) numFailed++;
	_ptrc_glTextureParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glTextureParameteriv");
	if(!_ptrc_glTextureParameteriv) numFailed++;
	_ptrc_glTextureStorage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTextureStorage1D");
	if(!_ptrc_glTextureStorage1D) numFailed++;
	_ptrc_glTextureStorage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage2D");
	if(!_ptrc_glTextureStorage2D) numFailed++;
	_ptrc_glTextureStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage2DMultisample");
	if(!_ptrc_glTextureStorage2DMultisample) numFailed++;
	_ptrc_glTextureStorage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage3D");
	if(!_ptrc_glTextureStorage3D) numFailed++;
	_ptrc_glTextureStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage3DMultisample");
	if(!_ptrc_glTextureStorage3DMultisample) numFailed++;
	_ptrc_glTextureSubImage1D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage1D");
	if(!_ptrc_glTextureSubImage1D) numFailed++;
	_ptrc_glTextureSubImage2D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage2D");
	if(!_ptrc_glTextureSubImage2D) numFailed++;
	_ptrc_glTextureSubImage3D = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glTextureSubImage3D");
	if(!_ptrc_glTextureSubImage3D) numFailed++;
	_ptrc_glTransformFeedbackBufferBase = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glTransformFeedbackBufferBase");
	if(!_ptrc_glTransformFeedbackBufferBase) numFailed++;
	_ptrc_glTransformFeedbackBufferRange = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTransformFeedbackBufferRange");
	if(!_ptrc_glTransformFeedbackBufferRange) numFailed++;
	_ptrc_glUnmapNamedBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUnmapNamedBuffer");
	if(!_ptrc_glUnmapNamedBuffer) numFailed++;
	_ptrc_glVertexArrayAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayAttribBinding");
	if(!_ptrc_glVertexArrayAttribBinding) numFailed++;
	_ptrc_glVertexArrayAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexArrayAttribFormat");
	if(!_ptrc_glVertexArrayAttribFormat) numFailed++;
	_ptrc_glVertexArrayAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayAttribIFormat");
	if(!_ptrc_glVertexArrayAttribIFormat) numFailed++;
	_ptrc_glVertexArrayAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayAttribLFormat");
	if(!_ptrc_glVertexArrayAttribLFormat) numFailed++;
	_ptrc_glVertexArrayBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayBindingDivisor");
	if(!_ptrc_glVertexArrayBindingDivisor) numFailed++;
	_ptrc_glVertexArrayElementBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexArrayElementBuffer");
	if(!_ptrc_glVertexArrayElementBuffer) numFailed++;
	_ptrc_glVertexArrayVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glVertexArrayVertexBuffer");
	if(!_ptrc_glVertexArrayVertexBuffer) numFailed++;
	_ptrc_glVertexArrayVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glVertexArrayVertexBuffers");
	if(!_ptrc_glVertexArrayVertexBuffers) numFailed++;
	return numFailed;
}

typedef int (*PFN_LOADFUNCPOINTERS)(void);
typedef struct ogl_StrToExtMap_s
{
	char *extensionName;
	int *extensionVariable;
	PFN_LOADFUNCPOINTERS LoadExtension;
} ogl_StrToExtMap;

static ogl_StrToExtMap ExtensionMap[301] = {
	{"GL_AMD_multi_draw_indirect", &ogl_ext_AMD_multi_draw_indirect, Load_AMD_multi_draw_indirect},
	{"GL_ARB_arrays_of_arrays", &ogl_ext_ARB_arrays_of_arrays, NULL},
	{"GL_ARB_base_instance", &ogl_ext_ARB_base_instance, Load_ARB_base_instance},
	{"GL_ARB_blend_func_extended", &ogl_ext_ARB_blend_func_extended, Load_ARB_blend_func_extended},
	{"GL_ARB_buffer_storage", &ogl_ext_ARB_buffer_storage, Load_ARB_buffer_storage},
	{"GL_ARB_cl_event", &ogl_ext_ARB_cl_event, Load_ARB_cl_event},
	{"GL_ARB_clear_buffer_object", &ogl_ext_ARB_clear_buffer_object, Load_ARB_clear_buffer_object},
	{"GL_ARB_clear_texture", &ogl_ext_ARB_clear_texture, Load_ARB_clear_texture},
	{"GL_ARB_clip_control", &ogl_ext_ARB_clip_control, Load_ARB_clip_control},
	{"GL_ARB_color_buffer_float", &ogl_ext_ARB_color_buffer_float, Load_ARB_color_buffer_float},
	{"GL_ARB_compatibility", &ogl_ext_ARB_compatibility, NULL},
	{"GL_ARB_compressed_texture_pixel_storage", &ogl_ext_ARB_compressed_texture_pixel_storage, NULL},
	{"GL_ARB_conservative_depth", &ogl_ext_ARB_conservative_depth, NULL},
	{"GL_ARB_compute_shader", &ogl_ext_ARB_compute_shader, Load_ARB_compute_shader},
	{"GL_ARB_compute_variable_group_size", &ogl_ext_ARB_compute_variable_group_size, Load_ARB_compute_variable_group_size},
	{"GL_ARB_conditional_render_inverted", &ogl_ext_ARB_conditional_render_inverted, NULL},
	{"GL_ARB_copy_buffer", &ogl_ext_ARB_copy_buffer, Load_ARB_copy_buffer},
	{"GL_ARB_copy_image", &ogl_ext_ARB_copy_image, Load_ARB_copy_image},
	{"GL_ARB_cull_distance", &ogl_ext_ARB_cull_distance, NULL},
	{"GL_ARB_debug_output", &ogl_ext_ARB_debug_output, Load_ARB_debug_output},
	{"GL_ARB_depth_buffer_float", &ogl_ext_ARB_depth_buffer_float, NULL},
	{"GL_ARB_depth_clamp", &ogl_ext_ARB_depth_clamp, NULL},
	{"GL_ARB_depth_texture", &ogl_ext_ARB_depth_texture, NULL},
	{"GL_ARB_derivative_control", &ogl_ext_ARB_derivative_control, NULL},
	{"GL_ARB_direct_state_access", &ogl_ext_ARB_direct_state_access, Load_ARB_direct_state_access},
	{"GL_ARB_draw_buffers", &ogl_ext_ARB_draw_buffers, Load_ARB_draw_buffers},
	{"GL_ARB_draw_buffers_blend", &ogl_ext_ARB_draw_buffers_blend, Load_ARB_draw_buffers_blend},
	{"GL_ARB_draw_indirect", &ogl_ext_ARB_draw_indirect, Load_ARB_draw_indirect},
	{"GL_ARB_draw_elements_base_vertex", &ogl_ext_ARB_draw_elements_base_vertex, Load_ARB_draw_elements_base_vertex},
	{"GL_ARB_draw_instanced", &ogl_ext_ARB_draw_instanced, Load_ARB_draw_instanced},
	{"GL_ARB_enhanced_layouts", &ogl_ext_ARB_enhanced_layouts, NULL},
	{"GL_ARB_ES2_compatibility", &ogl_ext_ARB_ES2_compatibility, Load_ARB_ES2_compatibility},
	{"GL_ARB_ES3_compatibility", &ogl_ext_ARB_ES3_compatibility, NULL},
	{"GL_ARB_ES3_1_compatibility", &ogl_ext_ARB_ES3_1_compatibility, Load_ARB_ES3_1_compatibility},
	{"GL_ARB_ES3_2_compatibility", &ogl_ext_ARB_ES3_2_compatibility, Load_ARB_ES3_2_compatibility},
	{"GL_ARB_explicit_attrib_location", &ogl_ext_ARB_explicit_attrib_location, NULL},
	{"GL_ARB_explicit_uniform_location", &ogl_ext_ARB_explicit_uniform_location, NULL},
	{"GL_ARB_fragment_coord_conventions", &ogl_ext_ARB_fragment_coord_conventions, NULL},
	{"GL_ARB_fragment_layer_viewport", &ogl_ext_ARB_fragment_layer_viewport, NULL},
	{"GL_ARB_fragment_program", &ogl_ext_ARB_fragment_program, Load_ARB_fragment_program},
	{"GL_ARB_fragment_program_shadow", &ogl_ext_ARB_fragment_program_shadow, NULL},
	{"GL_ARB_fragment_shader", &ogl_ext_ARB_fragment_shader, NULL},
	{"GL_ARB_framebuffer_no_attachments", &ogl_ext_ARB_framebuffer_no_attachments, Load_ARB_framebuffer_no_attachments},
	{"GL_ARB_framebuffer_object", &ogl_ext_ARB_framebuffer_object, Load_ARB_framebuffer_object},
	{"GL_ARB_framebuffer_sRGB", &ogl_ext_ARB_framebuffer_sRGB, NULL},
	{"GL_ARB_geometry_shader4", &ogl_ext_ARB_geometry_shader4, Load_ARB_geometry_shader4},
	{"GL_ARB_get_program_binary", &ogl_ext_ARB_get_program_binary, Load_ARB_get_program_binary},
	{"GL_ARB_get_texture_sub_image", &ogl_ext_ARB_get_texture_sub_image, Load_ARB_get_texture_sub_image},
	{"GL_ARB_gpu_shader5", &ogl_ext_ARB_gpu_shader5, NULL},
	{"GL_ARB_gpu_shader_fp64", &ogl_ext_ARB_gpu_shader_fp64, Load_ARB_gpu_shader_fp64},
	{"GL_ARB_gpu_shader_int64", &ogl_ext_ARB_gpu_shader_int64, Load_ARB_gpu_shader_int64},
	{"GL_ARB_half_float_pixel", &ogl_ext_ARB_half_float_pixel, NULL},
	{"GL_ARB_half_float_vertex", &ogl_ext_ARB_half_float_vertex, NULL},
	{"GL_ARB_imaging", &ogl_ext_ARB_imaging, Load_ARB_imaging},
	{"GL_ARB_indirect_parameters", &ogl_ext_ARB_indirect_parameters, Load_ARB_indirect_parameters},
	{"GL_ARB_instanced_arrays", &ogl_ext_ARB_instanced_arrays, Load_ARB_instanced_arrays},
	{"GL_ARB_internalformat_query", &ogl_ext_ARB_internalformat_query, Load_ARB_internalformat_query},
	{"GL_ARB_internalformat_query2", &ogl_ext_ARB_internalformat_query2, Load_ARB_internalformat_query2},
	{"GL_ARB_invalidate_subdata", &ogl_ext_ARB_invalidate_subdata, Load_ARB_invalidate_subdata},
	{"GL_ARB_map_buffer_alignment", &ogl_ext_ARB_map_buffer_alignment, NULL},
	{"GL_ARB_map_buffer_range", &ogl_ext_ARB_map_buffer_range, Load_ARB_map_buffer_range},
	{"GL_ARB_multi_bind", &ogl_ext_ARB_multi_bind, Load_ARB_multi_bind},
	{"GL_ARB_multi_draw_indirect", &ogl_ext_ARB_multi_draw_indirect, Load_ARB_multi_draw_indirect},
	{"GL_ARB_multisample", &ogl_ext_ARB_multisample, Load_ARB_multisample},
	{"GL_ARB_multitexture", &ogl_ext_ARB_multitexture, Load_ARB_multitexture},
	{"GL_ARB_occlusion_query", &ogl_ext_ARB_occlusion_query, Load_ARB_occlusion_query},
	{"GL_ARB_occlusion_query2", &ogl_ext_ARB_occlusion_query2, NULL},
	{"GL_ARB_parallel_shader_compile", &ogl_ext_ARB_parallel_shader_compile, Load_ARB_parallel_shader_compile},
	{"GL_ARB_pipeline_statistics_query", &ogl_ext_ARB_pipeline_statistics_query, NULL},
	{"GL_ARB_pixel_buffer_object", &ogl_ext_ARB_pixel_buffer_object, NULL},
	{"GL_ARB_point_parameters", &ogl_ext_ARB_point_parameters, Load_ARB_point_parameters},
	{"GL_ARB_point_sprite", &ogl_ext_ARB_point_sprite, NULL},
	{"GL_ARB_program_interface_query", &ogl_ext_ARB_program_interface_query, Load_ARB_program_interface_query},
	{"GL_ARB_provoking_vertex", &ogl_ext_ARB_provoking_vertex, Load_ARB_provoking_vertex},
	{"GL_ARB_query_buffer_object", &ogl_ext_ARB_query_buffer_object, NULL},
	{"GL_ARB_robust_buffer_access_behavior", &ogl_ext_ARB_robust_buffer_access_behavior, NULL},
	{"GL_ARB_robustness", &ogl_ext_ARB_robustness, Load_ARB_robustness},
	{"GL_ARB_sample_shading", &ogl_ext_ARB_sample_shading, Load_ARB_sample_shading},
	{"GL_ARB_sampler_objects", &ogl_ext_ARB_sampler_objects, Load_ARB_sampler_objects},
	{"GL_ARB_seamless_cube_map", &ogl_ext_ARB_seamless_cube_map, NULL},
	{"GL_ARB_separate_shader_objects", &ogl_ext_ARB_separate_shader_objects, Load_ARB_separate_shader_objects},
	{"GL_ARB_shader_atomic_counter_ops", &ogl_ext_ARB_shader_atomic_counter_ops, NULL},
	{"GL_ARB_shader_atomic_counters", &ogl_ext_ARB_shader_atomic_counters, Load_ARB_shader_atomic_counters},
	{"GL_ARB_shader_bit_encoding", &ogl_ext_ARB_shader_bit_encoding, NULL},
	{"GL_ARB_shader_draw_parameters", &ogl_ext_ARB_shader_draw_parameters, NULL},
	{"GL_ARB_shader_group_vote", &ogl_ext_ARB_shader_group_vote, NULL},
	{"GL_ARB_shader_image_load_store", &ogl_ext_ARB_shader_image_load_store, Load_ARB_shader_image_load_store},
	{"GL_ARB_shader_image_size", &ogl_ext_ARB_shader_image_size, NULL},
	{"GL_ARB_shader_objects", &ogl_ext_ARB_shader_objects, Load_ARB_shader_objects},
	{"GL_ARB_shader_precision", &ogl_ext_ARB_shader_precision, NULL},
	{"GL_ARB_shader_storage_buffer_object", &ogl_ext_ARB_shader_storage_buffer_object, Load_ARB_shader_storage_buffer_object},
	{"GL_ARB_shader_subroutine", &ogl_ext_ARB_shader_subroutine, Load_ARB_shader_subroutine},
	{"GL_ARB_shader_texture_image_samples", &ogl_ext_ARB_shader_texture_image_samples, NULL},
	{"GL_ARB_shader_texture_lod", &ogl_ext_ARB_shader_texture_lod, NULL},
	{"GL_ARB_shading_language_100", &ogl_ext_ARB_shading_language_100, NULL},
	{"GL_ARB_shading_language_420pack", &ogl_ext_ARB_shading_language_420pack, NULL},
	{"GL_ARB_shading_language_include", &ogl_ext_ARB_shading_language_include, Load_ARB_shading_language_include},
	{"GL_ARB_shading_language_packing", &ogl_ext_ARB_shading_language_packing, NULL},
	{"GL_ARB_shadow", &ogl_ext_ARB_shadow, NULL},
	{"GL_ARB_sparse_buffer", &ogl_ext_ARB_sparse_buffer, Load_ARB_sparse_buffer},
	{"GL_ARB_sparse_texture", &ogl_ext_ARB_sparse_texture, Load_ARB_sparse_texture},
	{"GL_ARB_stencil_texturing", &ogl_ext_ARB_stencil_texturing, NULL},
	{"GL_ARB_sync", &ogl_ext_ARB_sync, Load_ARB_sync},
	{"GL_ARB_tessellation_shader", &ogl_ext_ARB_tessellation_shader, Load_ARB_tessellation_shader},
	{"GL_ARB_texture_barrier", &ogl_ext_ARB_texture_barrier, Load_ARB_texture_barrier},
	{"GL_ARB_texture_border_clamp", &ogl_ext_ARB_texture_border_clamp, NULL},
	{"GL_ARB_texture_buffer_object", &ogl_ext_ARB_texture_buffer_object, Load_ARB_texture_buffer_object},
	{"GL_ARB_texture_buffer_object_rgb32", &ogl_ext_ARB_texture_buffer_object_rgb32, NULL},
	{"GL_ARB_texture_buffer_range", &ogl_ext_ARB_texture_buffer_range, Load_ARB_texture_buffer_range},
	{"GL_ARB_texture_compression", &ogl_ext_ARB_texture_compression, Load_ARB_texture_compression},
	{"GL_ARB_texture_compression_bptc", &ogl_ext_ARB_texture_compression_bptc, NULL},
	{"GL_ARB_texture_compression_rgtc", &ogl_ext_ARB_texture_compression_rgtc, NULL},
	{"GL_ARB_texture_cube_map", &ogl_ext_ARB_texture_cube_map, NULL},
	{"GL_ARB_texture_cube_map_array", &ogl_ext_ARB_texture_cube_map_array, NULL},
	{"GL_ARB_texture_env_add", &ogl_ext_ARB_texture_env_add, NULL},
	{"GL_ARB_texture_env_combine", &ogl_ext_ARB_texture_env_combine, NULL},
	{"GL_ARB_texture_env_crossbar", &ogl_ext_ARB_texture_env_crossbar, NULL},
	{"GL_ARB_texture_env_dot3", &ogl_ext_ARB_texture_env_dot3, NULL},
	{"GL_ARB_texture_float", &ogl_ext_ARB_texture_float, NULL},
	{"GL_ARB_texture_gather", &ogl_ext_ARB_texture_gather, NULL},
	{"GL_ARB_texture_mirror_clamp_to_edge", &ogl_ext_ARB_texture_mirror_clamp_to_edge, NULL},
	{"GL_ARB_texture_mirrored_repeat", &ogl_ext_ARB_texture_mirrored_repeat, NULL},
	{"GL_ARB_texture_multisample", &ogl_ext_ARB_texture_multisample, Load_ARB_texture_multisample},
	{"GL_ARB_texture_non_power_of_two", &ogl_ext_ARB_texture_non_power_of_two, NULL},
	{"GL_ARB_texture_query_levels", &ogl_ext_ARB_texture_query_levels, NULL},
	{"GL_ARB_texture_query_lod", &ogl_ext_ARB_texture_query_lod, NULL},
	{"GL_ARB_texture_rectangle", &ogl_ext_ARB_texture_rectangle, NULL},
	{"GL_ARB_texture_rg", &ogl_ext_ARB_texture_rg, NULL},
	{"GL_ARB_texture_rgb10_a2ui", &ogl_ext_ARB_texture_rgb10_a2ui, NULL},
	{"GL_ARB_texture_stencil8", &ogl_ext_ARB_texture_stencil8, NULL},
	{"GL_ARB_texture_storage", &ogl_ext_ARB_texture_storage, Load_ARB_texture_storage},
	{"GL_ARB_texture_storage_multisample", &ogl_ext_ARB_texture_storage_multisample, Load_ARB_texture_storage_multisample},
	{"GL_ARB_texture_swizzle", &ogl_ext_ARB_texture_swizzle, NULL},
	{"GL_ARB_texture_view", &ogl_ext_ARB_texture_view, Load_ARB_texture_view},
	{"GL_ARB_timer_query", &ogl_ext_ARB_timer_query, Load_ARB_timer_query},
	{"GL_ARB_transform_feedback2", &ogl_ext_ARB_transform_feedback2, Load_ARB_transform_feedback2},
	{"GL_ARB_transform_feedback3", &ogl_ext_ARB_transform_feedback3, Load_ARB_transform_feedback3},
	{"GL_ARB_transform_feedback_instanced", &ogl_ext_ARB_transform_feedback_instanced, Load_ARB_transform_feedback_instanced},
	{"GL_ARB_transform_feedback_overflow_query", &ogl_ext_ARB_transform_feedback_overflow_query, NULL},
	{"GL_ARB_transpose_matrix", &ogl_ext_ARB_transpose_matrix, Load_ARB_transpose_matrix},
	{"GL_ARB_uniform_buffer_object", &ogl_ext_ARB_uniform_buffer_object, Load_ARB_uniform_buffer_object},
	{"GL_ARB_vertex_array_bgra", &ogl_ext_ARB_vertex_array_bgra, NULL},
	{"GL_ARB_vertex_array_object", &ogl_ext_ARB_vertex_array_object, Load_ARB_vertex_array_object},
	{"GL_ARB_vertex_attrib_64bit", &ogl_ext_ARB_vertex_attrib_64bit, Load_ARB_vertex_attrib_64bit},
	{"GL_ARB_vertex_attrib_binding", &ogl_ext_ARB_vertex_attrib_binding, Load_ARB_vertex_attrib_binding},
	{"GL_ARB_vertex_buffer_object", &ogl_ext_ARB_vertex_buffer_object, Load_ARB_vertex_buffer_object},
	{"GL_ARB_vertex_program", &ogl_ext_ARB_vertex_program, Load_ARB_vertex_program},
	{"GL_ARB_vertex_shader", &ogl_ext_ARB_vertex_shader, Load_ARB_vertex_shader},
	{"GL_ARB_vertex_type_10f_11f_11f_rev", &ogl_ext_ARB_vertex_type_10f_11f_11f_rev, NULL},
	{"GL_ARB_vertex_type_2_10_10_10_rev", &ogl_ext_ARB_vertex_type_2_10_10_10_rev, Load_ARB_vertex_type_2_10_10_10_rev},
	{"GL_ARB_viewport_array", &ogl_ext_ARB_viewport_array, Load_ARB_viewport_array},
	{"GL_ARB_window_pos", &ogl_ext_ARB_window_pos, Load_ARB_window_pos},
	{"GL_ATI_draw_buffers", &ogl_ext_ATI_draw_buffers, Load_ATI_draw_buffers},
	{"GL_ATI_texture_float", &ogl_ext_ATI_texture_float, NULL},
	{"GL_ATI_texture_mirror_once", &ogl_ext_ATI_texture_mirror_once, NULL},
	{"GL_S3_s3tc", &ogl_ext_S3_s3tc, NULL},
	{"GL_EXT_texture_env_add", &ogl_ext_EXT_texture_env_add, NULL},
	{"GL_EXT_abgr", &ogl_ext_EXT_abgr, NULL},
	{"GL_EXT_bgra", &ogl_ext_EXT_bgra, NULL},
	{"GL_EXT_bindable_uniform", &ogl_ext_EXT_bindable_uniform, Load_EXT_bindable_uniform},
	{"GL_EXT_blend_color", &ogl_ext_EXT_blend_color, Load_EXT_blend_color},
	{"GL_EXT_blend_equation_separate", &ogl_ext_EXT_blend_equation_separate, Load_EXT_blend_equation_separate},
	{"GL_EXT_blend_func_separate", &ogl_ext_EXT_blend_func_separate, Load_EXT_blend_func_separate},
	{"GL_EXT_blend_minmax", &ogl_ext_EXT_blend_minmax, Load_EXT_blend_minmax},
	{"GL_EXT_blend_subtract", &ogl_ext_EXT_blend_subtract, NULL},
	{"GL_EXT_compiled_vertex_array", &ogl_ext_EXT_compiled_vertex_array, Load_EXT_compiled_vertex_array},
	{"GL_EXT_depth_bounds_test", &ogl_ext_EXT_depth_bounds_test, Load_EXT_depth_bounds_test},
	{"GL_EXT_direct_state_access", &ogl_ext_EXT_direct_state_access, Load_EXT_direct_state_access},
	{"GL_EXT_draw_buffers2", &ogl_ext_EXT_draw_buffers2, Load_EXT_draw_buffers2},
	{"GL_EXT_draw_instanced", &ogl_ext_EXT_draw_instanced, Load_EXT_draw_instanced},
	{"GL_EXT_draw_range_elements", &ogl_ext_EXT_draw_range_elements, Load_EXT_draw_range_elements},
	{"GL_EXT_fog_coord", &ogl_ext_EXT_fog_coord, Load_EXT_fog_coord},
	{"GL_EXT_framebuffer_blit", &ogl_ext_EXT_framebuffer_blit, Load_EXT_framebuffer_blit},
	{"GL_EXT_framebuffer_multisample", &ogl_ext_EXT_framebuffer_multisample, Load_EXT_framebuffer_multisample},
	{"GL_EXT_framebuffer_multisample_blit_scaled", &ogl_ext_EXT_framebuffer_multisample_blit_scaled, NULL},
	{"GL_EXT_framebuffer_object", &ogl_ext_EXT_framebuffer_object, Load_EXT_framebuffer_object},
	{"GL_EXT_framebuffer_sRGB", &ogl_ext_EXT_framebuffer_sRGB, NULL},
	{"GL_EXT_geometry_shader4", &ogl_ext_EXT_geometry_shader4, Load_EXT_geometry_shader4},
	{"GL_EXT_gpu_program_parameters", &ogl_ext_EXT_gpu_program_parameters, Load_EXT_gpu_program_parameters},
	{"GL_EXT_gpu_shader4", &ogl_ext_EXT_gpu_shader4, Load_EXT_gpu_shader4},
	{"GL_EXT_multi_draw_arrays", &ogl_ext_EXT_multi_draw_arrays, Load_EXT_multi_draw_arrays},
	{"GL_EXT_packed_depth_stencil", &ogl_ext_EXT_packed_depth_stencil, NULL},
	{"GL_EXT_packed_float", &ogl_ext_EXT_packed_float, NULL},
	{"GL_EXT_packed_pixels", &ogl_ext_EXT_packed_pixels, NULL},
	{"GL_EXT_pixel_buffer_object", &ogl_ext_EXT_pixel_buffer_object, NULL},
	{"GL_EXT_point_parameters", &ogl_ext_EXT_point_parameters, Load_EXT_point_parameters},
	{"GL_EXT_polygon_offset_clamp", &ogl_ext_EXT_polygon_offset_clamp, Load_EXT_polygon_offset_clamp},
	{"GL_EXT_provoking_vertex", &ogl_ext_EXT_provoking_vertex, Load_EXT_provoking_vertex},
	{"GL_EXT_rescale_normal", &ogl_ext_EXT_rescale_normal, NULL},
	{"GL_EXT_secondary_color", &ogl_ext_EXT_secondary_color, Load_EXT_secondary_color},
	{"GL_EXT_separate_shader_objects", &ogl_ext_EXT_separate_shader_objects, Load_EXT_separate_shader_objects},
	{"GL_EXT_separate_specular_color", &ogl_ext_EXT_separate_specular_color, NULL},
	{"GL_EXT_shader_image_load_store", &ogl_ext_EXT_shader_image_load_store, Load_EXT_shader_image_load_store},
	{"GL_EXT_shader_integer_mix", &ogl_ext_EXT_shader_integer_mix, NULL},
	{"GL_EXT_shadow_funcs", &ogl_ext_EXT_shadow_funcs, NULL},
	{"GL_EXT_stencil_two_side", &ogl_ext_EXT_stencil_two_side, Load_EXT_stencil_two_side},
	{"GL_EXT_stencil_wrap", &ogl_ext_EXT_stencil_wrap, NULL},
	{"GL_EXT_texture3D", &ogl_ext_EXT_texture3D, Load_EXT_texture3D},
	{"GL_EXT_texture_array", &ogl_ext_EXT_texture_array, Load_EXT_texture_array},
	{"GL_EXT_texture_buffer_object", &ogl_ext_EXT_texture_buffer_object, Load_EXT_texture_buffer_object},
	{"GL_EXT_texture_compression_latc", &ogl_ext_EXT_texture_compression_latc, NULL},
	{"GL_EXT_texture_compression_rgtc", &ogl_ext_EXT_texture_compression_rgtc, NULL},
	{"GL_EXT_texture_compression_s3tc", &ogl_ext_EXT_texture_compression_s3tc, NULL},
	{"GL_EXT_texture_cube_map", &ogl_ext_EXT_texture_cube_map, NULL},
	{"GL_EXT_texture_env_combine", &ogl_ext_EXT_texture_env_combine, NULL},
	{"GL_EXT_texture_env_dot3", &ogl_ext_EXT_texture_env_dot3, NULL},
	{"GL_EXT_texture_filter_anisotropic", &ogl_ext_EXT_texture_filter_anisotropic, NULL},
	{"GL_EXT_texture_integer", &ogl_ext_EXT_texture_integer, Load_EXT_texture_integer},
	{"GL_EXT_texture_lod_bias", &ogl_ext_EXT_texture_lod_bias, NULL},
	{"GL_EXT_texture_mirror_clamp", &ogl_ext_EXT_texture_mirror_clamp, NULL},
	{"GL_EXT_texture_object", &ogl_ext_EXT_texture_object, Load_EXT_texture_object},
	{"GL_EXT_texture_shared_exponent", &ogl_ext_EXT_texture_shared_exponent, NULL},
	{"GL_EXT_texture_sRGB", &ogl_ext_EXT_texture_sRGB, NULL},
	{"GL_EXT_texture_sRGB_decode", &ogl_ext_EXT_texture_sRGB_decode, NULL},
	{"GL_EXT_texture_swizzle", &ogl_ext_EXT_texture_swizzle, NULL},
	{"GL_EXT_timer_query", &ogl_ext_EXT_timer_query, Load_EXT_timer_query},
	{"GL_EXT_vertex_array", &ogl_ext_EXT_vertex_array, Load_EXT_vertex_array},
	{"GL_EXT_vertex_array_bgra", &ogl_ext_EXT_vertex_array_bgra, NULL},
	{"GL_EXT_vertex_attrib_64bit", &ogl_ext_EXT_vertex_attrib_64bit, Load_EXT_vertex_attrib_64bit},
	{"GL_IBM_rasterpos_clip", &ogl_ext_IBM_rasterpos_clip, NULL},
	{"GL_IBM_texture_mirrored_repeat", &ogl_ext_IBM_texture_mirrored_repeat, NULL},
	{"GL_KHR_context_flush_control", &ogl_ext_KHR_context_flush_control, NULL},
	{"GL_KHR_debug", &ogl_ext_KHR_debug, Load_KHR_debug},
	{"GL_KHR_no_error", &ogl_ext_KHR_no_error, NULL},
	{"GL_KHR_robust_buffer_access_behavior", &ogl_ext_KHR_robust_buffer_access_behavior, NULL},
	{"GL_KHR_robustness", &ogl_ext_KHR_robustness, Load_KHR_robustness},
	{"GL_NV_bindless_multi_draw_indirect", &ogl_ext_NV_bindless_multi_draw_indirect, Load_NV_bindless_multi_draw_indirect},
	{"GL_NV_bindless_multi_draw_indirect_count", &ogl_ext_NV_bindless_multi_draw_indirect_count, Load_NV_bindless_multi_draw_indirect_count},
	{"GL_NV_blend_equation_advanced", &ogl_ext_NV_blend_equation_advanced, Load_NV_blend_equation_advanced},
	{"GL_NV_blend_square", &ogl_ext_NV_blend_square, NULL},
	{"GL_NV_command_list", &ogl_ext_NV_command_list, Load_NV_command_list},
	{"GL_NV_compute_program5", &ogl_ext_NV_compute_program5, NULL},
	{"GL_NV_conditional_render", &ogl_ext_NV_conditional_render, Load_NV_conditional_render},
	{"GL_NV_copy_depth_to_color", &ogl_ext_NV_copy_depth_to_color, NULL},
	{"GL_NV_copy_image", &ogl_ext_NV_copy_image, Load_NV_copy_image},
	{"GL_NV_depth_buffer_float", &ogl_ext_NV_depth_buffer_float, Load_NV_depth_buffer_float},
	{"GL_NV_depth_clamp", &ogl_ext_NV_depth_clamp, NULL},
	{"GL_NV_draw_texture", &ogl_ext_NV_draw_texture, Load_NV_draw_texture},
	{"GL_NV_explicit_multisample", &ogl_ext_NV_explicit_multisample, Load_NV_explicit_multisample},
	{"GL_NV_fence", &ogl_ext_NV_fence, Load_NV_fence},
	{"GL_NV_float_buffer", &ogl_ext_NV_float_buffer, NULL},
	{"GL_NV_fog_distance", &ogl_ext_NV_fog_distance, NULL},
	{"GL_NV_fragment_program", &ogl_ext_NV_fragment_program, Load_NV_fragment_program},
	{"GL_NV_fragment_program_option", &ogl_ext_NV_fragment_program_option, NULL},
	{"GL_NV_fragment_program2", &ogl_ext_NV_fragment_program2, NULL},
	{"GL_NV_framebuffer_multisample_coverage", &ogl_ext_NV_framebuffer_multisample_coverage, Load_NV_framebuffer_multisample_coverage},
	{"GL_NV_geometry_shader4", &ogl_ext_NV_geometry_shader4, NULL},
	{"GL_NV_gpu_program4", &ogl_ext_NV_gpu_program4, Load_NV_gpu_program4},
	{"GL_NV_internalformat_sample_query", &ogl_ext_NV_internalformat_sample_query, Load_NV_internalformat_sample_query},
	{"GL_NV_gpu_program5", &ogl_ext_NV_gpu_program5, Load_NV_gpu_program5},
	{"GL_NV_gpu_program5_mem_extended", &ogl_ext_NV_gpu_program5_mem_extended, NULL},
	{"GL_NV_gpu_shader5", &ogl_ext_NV_gpu_shader5, Load_NV_gpu_shader5},
	{"GL_NV_half_float", &ogl_ext_NV_half_float, Load_NV_half_float},
	{"GL_NV_light_max_exponent", &ogl_ext_NV_light_max_exponent, NULL},
	{"GL_NV_multisample_coverage", &ogl_ext_NV_multisample_coverage, NULL},
	{"GL_NV_multisample_filter_hint", &ogl_ext_NV_multisample_filter_hint, NULL},
	{"GL_NV_occlusion_query", &ogl_ext_NV_occlusion_query, Load_NV_occlusion_query},
	{"GL_NV_packed_depth_stencil", &ogl_ext_NV_packed_depth_stencil, NULL},
	{"GL_NV_parameter_buffer_object", &ogl_ext_NV_parameter_buffer_object, Load_NV_parameter_buffer_object},
	{"GL_NV_parameter_buffer_object2", &ogl_ext_NV_parameter_buffer_object2, NULL},
	{"GL_NV_path_rendering", &ogl_ext_NV_path_rendering, Load_NV_path_rendering},
	{"GL_NV_pixel_data_range", &ogl_ext_NV_pixel_data_range, Load_NV_pixel_data_range},
	{"GL_NV_point_sprite", &ogl_ext_NV_point_sprite, Load_NV_point_sprite},
	{"GL_NV_primitive_restart", &ogl_ext_NV_primitive_restart, Load_NV_primitive_restart},
	{"GL_NV_register_combiners", &ogl_ext_NV_register_combiners, Load_NV_register_combiners},
	{"GL_NV_register_combiners2", &ogl_ext_NV_register_combiners2, Load_NV_register_combiners2},
	{"GL_NV_shader_atomic_counters", &ogl_ext_NV_shader_atomic_counters, NULL},
	{"GL_NV_shader_atomic_float", &ogl_ext_NV_shader_atomic_float, NULL},
	{"GL_NV_shader_buffer_load", &ogl_ext_NV_shader_buffer_load, Load_NV_shader_buffer_load},
	{"GL_NV_shader_storage_buffer_object", &ogl_ext_NV_shader_storage_buffer_object, NULL},
	{"GL_NV_texgen_reflection", &ogl_ext_NV_texgen_reflection, NULL},
	{"GL_NV_texture_barrier", &ogl_ext_NV_texture_barrier, Load_NV_texture_barrier},
	{"GL_NV_texture_compression_vtc", &ogl_ext_NV_texture_compression_vtc, NULL},
	{"GL_NV_texture_env_combine4", &ogl_ext_NV_texture_env_combine4, NULL},
	{"GL_NV_texture_multisample", &ogl_ext_NV_texture_multisample, Load_NV_texture_multisample},
	{"GL_NV_texture_rectangle", &ogl_ext_NV_texture_rectangle, NULL},
	{"GL_NV_texture_shader", &ogl_ext_NV_texture_shader, NULL},
	{"GL_NV_texture_shader2", &ogl_ext_NV_texture_shader2, NULL},
	{"GL_NV_texture_shader3", &ogl_ext_NV_texture_shader3, NULL},
	{"GL_NV_transform_feedback", &ogl_ext_NV_transform_feedback, Load_NV_transform_feedback},
	{"GL_NV_transform_feedback2", &ogl_ext_NV_transform_feedback2, Load_NV_transform_feedback2},
	{"GL_NV_uniform_buffer_unified_memory", &ogl_ext_NV_uniform_buffer_unified_memory, NULL},
	{"GL_NV_vertex_array_range", &ogl_ext_NV_vertex_array_range, Load_NV_vertex_array_range},
	{"GL_NV_vertex_array_range2", &ogl_ext_NV_vertex_array_range2, NULL},
	{"GL_NV_vertex_attrib_integer_64bit", &ogl_ext_NV_vertex_attrib_integer_64bit, Load_NV_vertex_attrib_integer_64bit},
	{"GL_NV_vertex_buffer_unified_memory", &ogl_ext_NV_vertex_buffer_unified_memory, Load_NV_vertex_buffer_unified_memory},
	{"GL_NV_vertex_program", &ogl_ext_NV_vertex_program, Load_NV_vertex_program},
	{"GL_NV_vertex_program1_1", &ogl_ext_NV_vertex_program1_1, NULL},
	{"GL_NV_vertex_program2", &ogl_ext_NV_vertex_program2, NULL},
	{"GL_NV_vertex_program2_option", &ogl_ext_NV_vertex_program2_option, NULL},
	{"GL_NV_vertex_program3", &ogl_ext_NV_vertex_program3, NULL},
	{"GL_NV_video_capture", &ogl_ext_NV_video_capture, Load_NV_video_capture},
	{"GL_NVX_conditional_render", &ogl_ext_NVX_conditional_render, Load_NVX_conditional_render},
	{"GL_NVX_gpu_memory_info", &ogl_ext_NVX_gpu_memory_info, NULL},
	{"GL_NV_shader_thread_group", &ogl_ext_NV_shader_thread_group, NULL},
	{"GL_KHR_blend_equation_advanced", &ogl_ext_KHR_blend_equation_advanced, Load_KHR_blend_equation_advanced},
	{"GL_SGIS_generate_mipmap", &ogl_ext_SGIS_generate_mipmap, NULL},
	{"GL_SGIS_texture_lod", &ogl_ext_SGIS_texture_lod, NULL},
	{"GL_SGIX_depth_texture", &ogl_ext_SGIX_depth_texture, NULL},
	{"GL_SGIX_shadow", &ogl_ext_SGIX_shadow, NULL},
	{"GL_SUN_slice_accum", &ogl_ext_SUN_slice_accum, NULL},
};

static int g_extensionMapSize = 301;

static ogl_StrToExtMap *FindExtEntry(const char *extensionName)
{
	int loop;
	ogl_StrToExtMap *currLoc = ExtensionMap;
	for(loop = 0; loop < g_extensionMapSize; ++loop, ++currLoc)
	{
		if(strcmp(extensionName, currLoc->extensionName) == 0)
			return currLoc;
	}
	
	return NULL;
}

static void ClearExtensionVars(void)
{
	ogl_ext_AMD_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_ARB_arrays_of_arrays = ogl_LOAD_FAILED;
	ogl_ext_ARB_base_instance = ogl_LOAD_FAILED;
	ogl_ext_ARB_blend_func_extended = ogl_LOAD_FAILED;
	ogl_ext_ARB_buffer_storage = ogl_LOAD_FAILED;
	ogl_ext_ARB_cl_event = ogl_LOAD_FAILED;
	ogl_ext_ARB_clear_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_clear_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_clip_control = ogl_LOAD_FAILED;
	ogl_ext_ARB_color_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_compressed_texture_pixel_storage = ogl_LOAD_FAILED;
	ogl_ext_ARB_conservative_depth = ogl_LOAD_FAILED;
	ogl_ext_ARB_compute_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_compute_variable_group_size = ogl_LOAD_FAILED;
	ogl_ext_ARB_conditional_render_inverted = ogl_LOAD_FAILED;
	ogl_ext_ARB_copy_buffer = ogl_LOAD_FAILED;
	ogl_ext_ARB_copy_image = ogl_LOAD_FAILED;
	ogl_ext_ARB_cull_distance = ogl_LOAD_FAILED;
	ogl_ext_ARB_debug_output = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_clamp = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_derivative_control = ogl_LOAD_FAILED;
	ogl_ext_ARB_direct_state_access = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_buffers = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_buffers_blend = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_elements_base_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_instanced = ogl_LOAD_FAILED;
	ogl_ext_ARB_enhanced_layouts = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES2_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES3_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES3_1_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES3_2_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_explicit_attrib_location = ogl_LOAD_FAILED;
	ogl_ext_ARB_explicit_uniform_location = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_coord_conventions = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_layer_viewport = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_program = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_program_shadow = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_no_attachments = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_sRGB = ogl_LOAD_FAILED;
	ogl_ext_ARB_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_ARB_get_program_binary = ogl_LOAD_FAILED;
	ogl_ext_ARB_get_texture_sub_image = ogl_LOAD_FAILED;
	ogl_ext_ARB_gpu_shader5 = ogl_LOAD_FAILED;
	ogl_ext_ARB_gpu_shader_fp64 = ogl_LOAD_FAILED;
	ogl_ext_ARB_gpu_shader_int64 = ogl_LOAD_FAILED;
	ogl_ext_ARB_half_float_pixel = ogl_LOAD_FAILED;
	ogl_ext_ARB_half_float_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_imaging = ogl_LOAD_FAILED;
	ogl_ext_ARB_indirect_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_instanced_arrays = ogl_LOAD_FAILED;
	ogl_ext_ARB_internalformat_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_internalformat_query2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_invalidate_subdata = ogl_LOAD_FAILED;
	ogl_ext_ARB_map_buffer_alignment = ogl_LOAD_FAILED;
	ogl_ext_ARB_map_buffer_range = ogl_LOAD_FAILED;
	ogl_ext_ARB_multi_bind = ogl_LOAD_FAILED;
	ogl_ext_ARB_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_ARB_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_multitexture = ogl_LOAD_FAILED;
	ogl_ext_ARB_occlusion_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_occlusion_query2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_parallel_shader_compile = ogl_LOAD_FAILED;
	ogl_ext_ARB_pipeline_statistics_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_pixel_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_point_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_point_sprite = ogl_LOAD_FAILED;
	ogl_ext_ARB_program_interface_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_provoking_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_query_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_robust_buffer_access_behavior = ogl_LOAD_FAILED;
	ogl_ext_ARB_robustness = ogl_LOAD_FAILED;
	ogl_ext_ARB_sample_shading = ogl_LOAD_FAILED;
	ogl_ext_ARB_sampler_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_seamless_cube_map = ogl_LOAD_FAILED;
	ogl_ext_ARB_separate_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_atomic_counter_ops = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_atomic_counters = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_bit_encoding = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_draw_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_group_vote = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_image_load_store = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_image_size = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_precision = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_storage_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_subroutine = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_texture_image_samples = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_texture_lod = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_100 = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_420pack = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_include = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_packing = ogl_LOAD_FAILED;
	ogl_ext_ARB_shadow = ogl_LOAD_FAILED;
	ogl_ext_ARB_sparse_buffer = ogl_LOAD_FAILED;
	ogl_ext_ARB_sparse_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_stencil_texturing = ogl_LOAD_FAILED;
	ogl_ext_ARB_sync = ogl_LOAD_FAILED;
	ogl_ext_ARB_tessellation_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_barrier = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_border_clamp = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_object_rgb32 = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_range = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression_bptc = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression_rgtc = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_cube_map = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_cube_map_array = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_add = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_combine = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_crossbar = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_dot3 = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_gather = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_mirror_clamp_to_edge = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_mirrored_repeat = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_non_power_of_two = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_query_levels = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_query_lod = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rectangle = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rg = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rgb10_a2ui = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_stencil8 = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_storage = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_storage_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_swizzle = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_view = ogl_LOAD_FAILED;
	ogl_ext_ARB_timer_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback3 = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback_instanced = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback_overflow_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_transpose_matrix = ogl_LOAD_FAILED;
	ogl_ext_ARB_uniform_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_array_bgra = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_array_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_attrib_64bit = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_attrib_binding = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_program = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_type_10f_11f_11f_rev = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_type_2_10_10_10_rev = ogl_LOAD_FAILED;
	ogl_ext_ARB_viewport_array = ogl_LOAD_FAILED;
	ogl_ext_ARB_window_pos = ogl_LOAD_FAILED;
	ogl_ext_ATI_draw_buffers = ogl_LOAD_FAILED;
	ogl_ext_ATI_texture_float = ogl_LOAD_FAILED;
	ogl_ext_ATI_texture_mirror_once = ogl_LOAD_FAILED;
	ogl_ext_S3_s3tc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_add = ogl_LOAD_FAILED;
	ogl_ext_EXT_abgr = ogl_LOAD_FAILED;
	ogl_ext_EXT_bgra = ogl_LOAD_FAILED;
	ogl_ext_EXT_bindable_uniform = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_equation_separate = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_func_separate = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_minmax = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_subtract = ogl_LOAD_FAILED;
	ogl_ext_EXT_compiled_vertex_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_depth_bounds_test = ogl_LOAD_FAILED;
	ogl_ext_EXT_direct_state_access = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_buffers2 = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_instanced = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_range_elements = ogl_LOAD_FAILED;
	ogl_ext_EXT_fog_coord = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_blit = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_multisample = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_multisample_blit_scaled = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_sRGB = ogl_LOAD_FAILED;
	ogl_ext_EXT_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_EXT_gpu_program_parameters = ogl_LOAD_FAILED;
	ogl_ext_EXT_gpu_shader4 = ogl_LOAD_FAILED;
	ogl_ext_EXT_multi_draw_arrays = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_depth_stencil = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_float = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_pixels = ogl_LOAD_FAILED;
	ogl_ext_EXT_pixel_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_point_parameters = ogl_LOAD_FAILED;
	ogl_ext_EXT_polygon_offset_clamp = ogl_LOAD_FAILED;
	ogl_ext_EXT_provoking_vertex = ogl_LOAD_FAILED;
	ogl_ext_EXT_rescale_normal = ogl_LOAD_FAILED;
	ogl_ext_EXT_secondary_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_separate_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_EXT_separate_specular_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_shader_image_load_store = ogl_LOAD_FAILED;
	ogl_ext_EXT_shader_integer_mix = ogl_LOAD_FAILED;
	ogl_ext_EXT_shadow_funcs = ogl_LOAD_FAILED;
	ogl_ext_EXT_stencil_two_side = ogl_LOAD_FAILED;
	ogl_ext_EXT_stencil_wrap = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture3D = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_latc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_rgtc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_s3tc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_cube_map = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_combine = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_dot3 = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_filter_anisotropic = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_integer = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_lod_bias = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_mirror_clamp = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_shared_exponent = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_sRGB = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_sRGB_decode = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_swizzle = ogl_LOAD_FAILED;
	ogl_ext_EXT_timer_query = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_array_bgra = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_attrib_64bit = ogl_LOAD_FAILED;
	ogl_ext_IBM_rasterpos_clip = ogl_LOAD_FAILED;
	ogl_ext_IBM_texture_mirrored_repeat = ogl_LOAD_FAILED;
	ogl_ext_KHR_context_flush_control = ogl_LOAD_FAILED;
	ogl_ext_KHR_debug = ogl_LOAD_FAILED;
	ogl_ext_KHR_no_error = ogl_LOAD_FAILED;
	ogl_ext_KHR_robust_buffer_access_behavior = ogl_LOAD_FAILED;
	ogl_ext_KHR_robustness = ogl_LOAD_FAILED;
	ogl_ext_NV_bindless_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_NV_bindless_multi_draw_indirect_count = ogl_LOAD_FAILED;
	ogl_ext_NV_blend_equation_advanced = ogl_LOAD_FAILED;
	ogl_ext_NV_blend_square = ogl_LOAD_FAILED;
	ogl_ext_NV_command_list = ogl_LOAD_FAILED;
	ogl_ext_NV_compute_program5 = ogl_LOAD_FAILED;
	ogl_ext_NV_conditional_render = ogl_LOAD_FAILED;
	ogl_ext_NV_copy_depth_to_color = ogl_LOAD_FAILED;
	ogl_ext_NV_copy_image = ogl_LOAD_FAILED;
	ogl_ext_NV_depth_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_NV_depth_clamp = ogl_LOAD_FAILED;
	ogl_ext_NV_draw_texture = ogl_LOAD_FAILED;
	ogl_ext_NV_explicit_multisample = ogl_LOAD_FAILED;
	ogl_ext_NV_fence = ogl_LOAD_FAILED;
	ogl_ext_NV_float_buffer = ogl_LOAD_FAILED;
	ogl_ext_NV_fog_distance = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program_option = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program2 = ogl_LOAD_FAILED;
	ogl_ext_NV_framebuffer_multisample_coverage = ogl_LOAD_FAILED;
	ogl_ext_NV_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program4 = ogl_LOAD_FAILED;
	ogl_ext_NV_internalformat_sample_query = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program5 = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program5_mem_extended = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_shader5 = ogl_LOAD_FAILED;
	ogl_ext_NV_half_float = ogl_LOAD_FAILED;
	ogl_ext_NV_light_max_exponent = ogl_LOAD_FAILED;
	ogl_ext_NV_multisample_coverage = ogl_LOAD_FAILED;
	ogl_ext_NV_multisample_filter_hint = ogl_LOAD_FAILED;
	ogl_ext_NV_occlusion_query = ogl_LOAD_FAILED;
	ogl_ext_NV_packed_depth_stencil = ogl_LOAD_FAILED;
	ogl_ext_NV_parameter_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_NV_parameter_buffer_object2 = ogl_LOAD_FAILED;
	ogl_ext_NV_path_rendering = ogl_LOAD_FAILED;
	ogl_ext_NV_pixel_data_range = ogl_LOAD_FAILED;
	ogl_ext_NV_point_sprite = ogl_LOAD_FAILED;
	ogl_ext_NV_primitive_restart = ogl_LOAD_FAILED;
	ogl_ext_NV_register_combiners = ogl_LOAD_FAILED;
	ogl_ext_NV_register_combiners2 = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_atomic_counters = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_atomic_float = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_buffer_load = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_storage_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_NV_texgen_reflection = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_barrier = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_compression_vtc = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_env_combine4 = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_multisample = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_rectangle = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader2 = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader3 = ogl_LOAD_FAILED;
	ogl_ext_NV_transform_feedback = ogl_LOAD_FAILED;
	ogl_ext_NV_transform_feedback2 = ogl_LOAD_FAILED;
	ogl_ext_NV_uniform_buffer_unified_memory = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_array_range = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_array_range2 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_attrib_integer_64bit = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_buffer_unified_memory = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program1_1 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program2 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program2_option = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program3 = ogl_LOAD_FAILED;
	ogl_ext_NV_video_capture = ogl_LOAD_FAILED;
	ogl_ext_NVX_conditional_render = ogl_LOAD_FAILED;
	ogl_ext_NVX_gpu_memory_info = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_thread_group = ogl_LOAD_FAILED;
	ogl_ext_KHR_blend_equation_advanced = ogl_LOAD_FAILED;
	ogl_ext_SGIS_generate_mipmap = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_lod = ogl_LOAD_FAILED;
	ogl_ext_SGIX_depth_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIX_shadow = ogl_LOAD_FAILED;
	ogl_ext_SUN_slice_accum = ogl_LOAD_FAILED;
}


static void LoadExtByName(const char *extensionName)
{
	ogl_StrToExtMap *entry = NULL;
	entry = FindExtEntry(extensionName);
	if(entry)
	{
		if(entry->LoadExtension)
		{
			int numFailed = entry->LoadExtension();
			if(numFailed == 0)
			{
				*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED;
			}
			else
			{
				*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED + numFailed;
			}
		}
		else
		{
			*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED;
		}
	}
}


static void ProcExtsFromExtList(void)
{
	GLint iLoop;
	GLint iNumExtensions = 0;
	_ptrc_glGetIntegerv(GL_NUM_EXTENSIONS, &iNumExtensions);

	for(iLoop = 0; iLoop < iNumExtensions; iLoop++)
	{
		const char *strExtensionName = (const char *)_ptrc_glGetStringi(GL_EXTENSIONS, iLoop);
		LoadExtByName(strExtensionName);
	}
}

int ogl_LoadFunctions()
{
	int numFailed = 0;
	ClearExtensionVars();
	
	_ptrc_glGetIntegerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetIntegerv");
	if(!_ptrc_glGetIntegerv) return ogl_LOAD_FAILED;
	_ptrc_glGetStringi = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glGetStringi");
	if(!_ptrc_glGetStringi) return ogl_LOAD_FAILED;
	
	ProcExtsFromExtList();
	numFailed = Load_Version_4_5();
	
	if(numFailed == 0)
		return ogl_LOAD_SUCCEEDED;
	else
		return ogl_LOAD_SUCCEEDED + numFailed;
}

static int g_major_version = 0;
static int g_minor_version = 0;

static void GetGLVersion(void)
{
	glGetIntegerv(GL_MAJOR_VERSION, &g_major_version);
	glGetIntegerv(GL_MINOR_VERSION, &g_minor_version);
}

int ogl_GetMajorVersion(void)
{
	if(g_major_version == 0)
		GetGLVersion();
	return g_major_version;
}

int ogl_GetMinorVersion(void)
{
	if(g_major_version == 0) /*Yes, check the major version to get the minor one.*/
		GetGLVersion();
	return g_minor_version;
}

int ogl_IsVersionGEQ(int majorVersion, int minorVersion)
{
	if(g_major_version == 0)
		GetGLVersion();
	
	if(majorVersion < g_major_version) return 1;
	if(majorVersion > g_major_version) return 0;
	if(minorVersion <= g_minor_version) return 1;
	return 0;
}

