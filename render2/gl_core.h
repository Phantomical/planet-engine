#ifndef POINTER_C_GENERATED_HEADER_OPENGL_H
#define POINTER_C_GENERATED_HEADER_OPENGL_H

#if defined(__glew_h__) || defined(__GLEW_H__)
#error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
#error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

#ifndef APIENTRY
	#if defined(__MINGW32__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#else
		#define APIENTRY
	#endif
#endif /*APIENTRY*/

#ifndef CODEGEN_FUNCPTR
	#define CODEGEN_REMOVE_FUNCPTR
	#if defined(_WIN32)
		#define CODEGEN_FUNCPTR APIENTRY
	#else
		#define CODEGEN_FUNCPTR
	#endif
#endif /*CODEGEN_FUNCPTR*/

#ifndef GLAPI
	#define GLAPI extern
#endif


#ifndef GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS
#define GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS


#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/


#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef void GLvoid;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef int GLsizei;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	typedef char GLchar;
	typedef char GLcharARB;
	#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
		typedef unsigned short GLhalfARB;
		typedef unsigned short GLhalf;
		typedef GLint GLfixed;
		typedef ptrdiff_t GLintptr;
		typedef ptrdiff_t GLsizeiptr;
		typedef int64_t GLint64;
		typedef uint64_t GLuint64;
		typedef ptrdiff_t GLintptrARB;
		typedef ptrdiff_t GLsizeiptrARB;
		typedef int64_t GLint64EXT;
		typedef uint64_t GLuint64EXT;
		typedef struct __GLsync *GLsync;
		struct _cl_context;
		struct _cl_event;
		typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
		typedef unsigned short GLhalfNV;
		typedef GLintptr GLvdpauSurfaceNV;

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

extern int ogl_ext_AMD_multi_draw_indirect;
extern int ogl_ext_ARB_arrays_of_arrays;
extern int ogl_ext_ARB_base_instance;
extern int ogl_ext_ARB_blend_func_extended;
extern int ogl_ext_ARB_buffer_storage;
extern int ogl_ext_ARB_cl_event;
extern int ogl_ext_ARB_clear_buffer_object;
extern int ogl_ext_ARB_clear_texture;
extern int ogl_ext_ARB_clip_control;
extern int ogl_ext_ARB_color_buffer_float;
extern int ogl_ext_ARB_compatibility;
extern int ogl_ext_ARB_compressed_texture_pixel_storage;
extern int ogl_ext_ARB_conservative_depth;
extern int ogl_ext_ARB_compute_shader;
extern int ogl_ext_ARB_compute_variable_group_size;
extern int ogl_ext_ARB_conditional_render_inverted;
extern int ogl_ext_ARB_copy_buffer;
extern int ogl_ext_ARB_copy_image;
extern int ogl_ext_ARB_cull_distance;
extern int ogl_ext_ARB_debug_output;
extern int ogl_ext_ARB_depth_buffer_float;
extern int ogl_ext_ARB_depth_clamp;
extern int ogl_ext_ARB_depth_texture;
extern int ogl_ext_ARB_derivative_control;
extern int ogl_ext_ARB_direct_state_access;
extern int ogl_ext_ARB_draw_buffers;
extern int ogl_ext_ARB_draw_buffers_blend;
extern int ogl_ext_ARB_draw_indirect;
extern int ogl_ext_ARB_draw_elements_base_vertex;
extern int ogl_ext_ARB_draw_instanced;
extern int ogl_ext_ARB_enhanced_layouts;
extern int ogl_ext_ARB_ES2_compatibility;
extern int ogl_ext_ARB_ES3_compatibility;
extern int ogl_ext_ARB_ES3_1_compatibility;
extern int ogl_ext_ARB_ES3_2_compatibility;
extern int ogl_ext_ARB_explicit_attrib_location;
extern int ogl_ext_ARB_explicit_uniform_location;
extern int ogl_ext_ARB_fragment_coord_conventions;
extern int ogl_ext_ARB_fragment_layer_viewport;
extern int ogl_ext_ARB_fragment_program;
extern int ogl_ext_ARB_fragment_program_shadow;
extern int ogl_ext_ARB_fragment_shader;
extern int ogl_ext_ARB_framebuffer_no_attachments;
extern int ogl_ext_ARB_framebuffer_object;
extern int ogl_ext_ARB_framebuffer_sRGB;
extern int ogl_ext_ARB_geometry_shader4;
extern int ogl_ext_ARB_get_program_binary;
extern int ogl_ext_ARB_get_texture_sub_image;
extern int ogl_ext_ARB_gpu_shader5;
extern int ogl_ext_ARB_gpu_shader_fp64;
extern int ogl_ext_ARB_gpu_shader_int64;
extern int ogl_ext_ARB_half_float_pixel;
extern int ogl_ext_ARB_half_float_vertex;
extern int ogl_ext_ARB_imaging;
extern int ogl_ext_ARB_indirect_parameters;
extern int ogl_ext_ARB_instanced_arrays;
extern int ogl_ext_ARB_internalformat_query;
extern int ogl_ext_ARB_internalformat_query2;
extern int ogl_ext_ARB_invalidate_subdata;
extern int ogl_ext_ARB_map_buffer_alignment;
extern int ogl_ext_ARB_map_buffer_range;
extern int ogl_ext_ARB_multi_bind;
extern int ogl_ext_ARB_multi_draw_indirect;
extern int ogl_ext_ARB_multisample;
extern int ogl_ext_ARB_multitexture;
extern int ogl_ext_ARB_occlusion_query;
extern int ogl_ext_ARB_occlusion_query2;
extern int ogl_ext_ARB_parallel_shader_compile;
extern int ogl_ext_ARB_pipeline_statistics_query;
extern int ogl_ext_ARB_pixel_buffer_object;
extern int ogl_ext_ARB_point_parameters;
extern int ogl_ext_ARB_point_sprite;
extern int ogl_ext_ARB_program_interface_query;
extern int ogl_ext_ARB_provoking_vertex;
extern int ogl_ext_ARB_query_buffer_object;
extern int ogl_ext_ARB_robust_buffer_access_behavior;
extern int ogl_ext_ARB_robustness;
extern int ogl_ext_ARB_sample_shading;
extern int ogl_ext_ARB_sampler_objects;
extern int ogl_ext_ARB_seamless_cube_map;
extern int ogl_ext_ARB_separate_shader_objects;
extern int ogl_ext_ARB_shader_atomic_counter_ops;
extern int ogl_ext_ARB_shader_atomic_counters;
extern int ogl_ext_ARB_shader_bit_encoding;
extern int ogl_ext_ARB_shader_draw_parameters;
extern int ogl_ext_ARB_shader_group_vote;
extern int ogl_ext_ARB_shader_image_load_store;
extern int ogl_ext_ARB_shader_image_size;
extern int ogl_ext_ARB_shader_objects;
extern int ogl_ext_ARB_shader_precision;
extern int ogl_ext_ARB_shader_storage_buffer_object;
extern int ogl_ext_ARB_shader_subroutine;
extern int ogl_ext_ARB_shader_texture_image_samples;
extern int ogl_ext_ARB_shader_texture_lod;
extern int ogl_ext_ARB_shading_language_100;
extern int ogl_ext_ARB_shading_language_420pack;
extern int ogl_ext_ARB_shading_language_include;
extern int ogl_ext_ARB_shading_language_packing;
extern int ogl_ext_ARB_shadow;
extern int ogl_ext_ARB_sparse_buffer;
extern int ogl_ext_ARB_sparse_texture;
extern int ogl_ext_ARB_stencil_texturing;
extern int ogl_ext_ARB_sync;
extern int ogl_ext_ARB_tessellation_shader;
extern int ogl_ext_ARB_texture_barrier;
extern int ogl_ext_ARB_texture_border_clamp;
extern int ogl_ext_ARB_texture_buffer_object;
extern int ogl_ext_ARB_texture_buffer_object_rgb32;
extern int ogl_ext_ARB_texture_buffer_range;
extern int ogl_ext_ARB_texture_compression;
extern int ogl_ext_ARB_texture_compression_bptc;
extern int ogl_ext_ARB_texture_compression_rgtc;
extern int ogl_ext_ARB_texture_cube_map;
extern int ogl_ext_ARB_texture_cube_map_array;
extern int ogl_ext_ARB_texture_env_add;
extern int ogl_ext_ARB_texture_env_combine;
extern int ogl_ext_ARB_texture_env_crossbar;
extern int ogl_ext_ARB_texture_env_dot3;
extern int ogl_ext_ARB_texture_float;
extern int ogl_ext_ARB_texture_gather;
extern int ogl_ext_ARB_texture_mirror_clamp_to_edge;
extern int ogl_ext_ARB_texture_mirrored_repeat;
extern int ogl_ext_ARB_texture_multisample;
extern int ogl_ext_ARB_texture_non_power_of_two;
extern int ogl_ext_ARB_texture_query_levels;
extern int ogl_ext_ARB_texture_query_lod;
extern int ogl_ext_ARB_texture_rectangle;
extern int ogl_ext_ARB_texture_rg;
extern int ogl_ext_ARB_texture_rgb10_a2ui;
extern int ogl_ext_ARB_texture_stencil8;
extern int ogl_ext_ARB_texture_storage;
extern int ogl_ext_ARB_texture_storage_multisample;
extern int ogl_ext_ARB_texture_swizzle;
extern int ogl_ext_ARB_texture_view;
extern int ogl_ext_ARB_timer_query;
extern int ogl_ext_ARB_transform_feedback2;
extern int ogl_ext_ARB_transform_feedback3;
extern int ogl_ext_ARB_transform_feedback_instanced;
extern int ogl_ext_ARB_transform_feedback_overflow_query;
extern int ogl_ext_ARB_transpose_matrix;
extern int ogl_ext_ARB_uniform_buffer_object;
extern int ogl_ext_ARB_vertex_array_bgra;
extern int ogl_ext_ARB_vertex_array_object;
extern int ogl_ext_ARB_vertex_attrib_64bit;
extern int ogl_ext_ARB_vertex_attrib_binding;
extern int ogl_ext_ARB_vertex_buffer_object;
extern int ogl_ext_ARB_vertex_program;
extern int ogl_ext_ARB_vertex_shader;
extern int ogl_ext_ARB_vertex_type_10f_11f_11f_rev;
extern int ogl_ext_ARB_vertex_type_2_10_10_10_rev;
extern int ogl_ext_ARB_viewport_array;
extern int ogl_ext_ARB_window_pos;
extern int ogl_ext_ATI_draw_buffers;
extern int ogl_ext_ATI_texture_float;
extern int ogl_ext_ATI_texture_mirror_once;
extern int ogl_ext_S3_s3tc;
extern int ogl_ext_EXT_texture_env_add;
extern int ogl_ext_EXT_abgr;
extern int ogl_ext_EXT_bgra;
extern int ogl_ext_EXT_bindable_uniform;
extern int ogl_ext_EXT_blend_color;
extern int ogl_ext_EXT_blend_equation_separate;
extern int ogl_ext_EXT_blend_func_separate;
extern int ogl_ext_EXT_blend_minmax;
extern int ogl_ext_EXT_blend_subtract;
extern int ogl_ext_EXT_compiled_vertex_array;
extern int ogl_ext_EXT_depth_bounds_test;
extern int ogl_ext_EXT_direct_state_access;
extern int ogl_ext_EXT_draw_buffers2;
extern int ogl_ext_EXT_draw_instanced;
extern int ogl_ext_EXT_draw_range_elements;
extern int ogl_ext_EXT_fog_coord;
extern int ogl_ext_EXT_framebuffer_blit;
extern int ogl_ext_EXT_framebuffer_multisample;
extern int ogl_ext_EXT_framebuffer_multisample_blit_scaled;
extern int ogl_ext_EXT_framebuffer_object;
extern int ogl_ext_EXT_framebuffer_sRGB;
extern int ogl_ext_EXT_geometry_shader4;
extern int ogl_ext_EXT_gpu_program_parameters;
extern int ogl_ext_EXT_gpu_shader4;
extern int ogl_ext_EXT_multi_draw_arrays;
extern int ogl_ext_EXT_packed_depth_stencil;
extern int ogl_ext_EXT_packed_float;
extern int ogl_ext_EXT_packed_pixels;
extern int ogl_ext_EXT_pixel_buffer_object;
extern int ogl_ext_EXT_point_parameters;
extern int ogl_ext_EXT_polygon_offset_clamp;
extern int ogl_ext_EXT_provoking_vertex;
extern int ogl_ext_EXT_rescale_normal;
extern int ogl_ext_EXT_secondary_color;
extern int ogl_ext_EXT_separate_shader_objects;
extern int ogl_ext_EXT_separate_specular_color;
extern int ogl_ext_EXT_shader_image_load_store;
extern int ogl_ext_EXT_shader_integer_mix;
extern int ogl_ext_EXT_shadow_funcs;
extern int ogl_ext_EXT_stencil_two_side;
extern int ogl_ext_EXT_stencil_wrap;
extern int ogl_ext_EXT_texture3D;
extern int ogl_ext_EXT_texture_array;
extern int ogl_ext_EXT_texture_buffer_object;
extern int ogl_ext_EXT_texture_compression_latc;
extern int ogl_ext_EXT_texture_compression_rgtc;
extern int ogl_ext_EXT_texture_compression_s3tc;
extern int ogl_ext_EXT_texture_cube_map;
extern int ogl_ext_EXT_texture_env_combine;
extern int ogl_ext_EXT_texture_env_dot3;
extern int ogl_ext_EXT_texture_filter_anisotropic;
extern int ogl_ext_EXT_texture_integer;
extern int ogl_ext_EXT_texture_lod_bias;
extern int ogl_ext_EXT_texture_mirror_clamp;
extern int ogl_ext_EXT_texture_object;
extern int ogl_ext_EXT_texture_shared_exponent;
extern int ogl_ext_EXT_texture_sRGB;
extern int ogl_ext_EXT_texture_sRGB_decode;
extern int ogl_ext_EXT_texture_swizzle;
extern int ogl_ext_EXT_timer_query;
extern int ogl_ext_EXT_vertex_array;
extern int ogl_ext_EXT_vertex_array_bgra;
extern int ogl_ext_EXT_vertex_attrib_64bit;
extern int ogl_ext_IBM_rasterpos_clip;
extern int ogl_ext_IBM_texture_mirrored_repeat;
extern int ogl_ext_KHR_context_flush_control;
extern int ogl_ext_KHR_debug;
extern int ogl_ext_KHR_no_error;
extern int ogl_ext_KHR_robust_buffer_access_behavior;
extern int ogl_ext_KHR_robustness;
extern int ogl_ext_NV_bindless_multi_draw_indirect;
extern int ogl_ext_NV_bindless_multi_draw_indirect_count;
extern int ogl_ext_NV_blend_equation_advanced;
extern int ogl_ext_NV_blend_square;
extern int ogl_ext_NV_command_list;
extern int ogl_ext_NV_compute_program5;
extern int ogl_ext_NV_conditional_render;
extern int ogl_ext_NV_copy_depth_to_color;
extern int ogl_ext_NV_copy_image;
extern int ogl_ext_NV_depth_buffer_float;
extern int ogl_ext_NV_depth_clamp;
extern int ogl_ext_NV_draw_texture;
extern int ogl_ext_NV_explicit_multisample;
extern int ogl_ext_NV_fence;
extern int ogl_ext_NV_float_buffer;
extern int ogl_ext_NV_fog_distance;
extern int ogl_ext_NV_fragment_program;
extern int ogl_ext_NV_fragment_program_option;
extern int ogl_ext_NV_fragment_program2;
extern int ogl_ext_NV_framebuffer_multisample_coverage;
extern int ogl_ext_NV_geometry_shader4;
extern int ogl_ext_NV_gpu_program4;
extern int ogl_ext_NV_internalformat_sample_query;
extern int ogl_ext_NV_gpu_program5;
extern int ogl_ext_NV_gpu_program5_mem_extended;
extern int ogl_ext_NV_gpu_shader5;
extern int ogl_ext_NV_half_float;
extern int ogl_ext_NV_light_max_exponent;
extern int ogl_ext_NV_multisample_coverage;
extern int ogl_ext_NV_multisample_filter_hint;
extern int ogl_ext_NV_occlusion_query;
extern int ogl_ext_NV_packed_depth_stencil;
extern int ogl_ext_NV_parameter_buffer_object;
extern int ogl_ext_NV_parameter_buffer_object2;
extern int ogl_ext_NV_path_rendering;
extern int ogl_ext_NV_pixel_data_range;
extern int ogl_ext_NV_point_sprite;
extern int ogl_ext_NV_primitive_restart;
extern int ogl_ext_NV_register_combiners;
extern int ogl_ext_NV_register_combiners2;
extern int ogl_ext_NV_shader_atomic_counters;
extern int ogl_ext_NV_shader_atomic_float;
extern int ogl_ext_NV_shader_buffer_load;
extern int ogl_ext_NV_shader_storage_buffer_object;
extern int ogl_ext_NV_texgen_reflection;
extern int ogl_ext_NV_texture_barrier;
extern int ogl_ext_NV_texture_compression_vtc;
extern int ogl_ext_NV_texture_env_combine4;
extern int ogl_ext_NV_texture_multisample;
extern int ogl_ext_NV_texture_rectangle;
extern int ogl_ext_NV_texture_shader;
extern int ogl_ext_NV_texture_shader2;
extern int ogl_ext_NV_texture_shader3;
extern int ogl_ext_NV_transform_feedback;
extern int ogl_ext_NV_transform_feedback2;
extern int ogl_ext_NV_uniform_buffer_unified_memory;
extern int ogl_ext_NV_vertex_array_range;
extern int ogl_ext_NV_vertex_array_range2;
extern int ogl_ext_NV_vertex_attrib_integer_64bit;
extern int ogl_ext_NV_vertex_buffer_unified_memory;
extern int ogl_ext_NV_vertex_program;
extern int ogl_ext_NV_vertex_program1_1;
extern int ogl_ext_NV_vertex_program2;
extern int ogl_ext_NV_vertex_program2_option;
extern int ogl_ext_NV_vertex_program3;
extern int ogl_ext_NV_video_capture;
extern int ogl_ext_NVX_conditional_render;
extern int ogl_ext_NVX_gpu_memory_info;
extern int ogl_ext_NV_shader_thread_group;
extern int ogl_ext_KHR_blend_equation_advanced;
extern int ogl_ext_SGIS_generate_mipmap;
extern int ogl_ext_SGIS_texture_lod;
extern int ogl_ext_SGIX_depth_texture;
extern int ogl_ext_SGIX_shadow;
extern int ogl_ext_SUN_slice_accum;

#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_SRC1_ALPHA 0x8589
#define GL_SRC1_COLOR 0x88F9

#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_MAP_PERSISTENT_BIT 0x0040
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002

#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241

#define GL_CLEAR_TEXTURE 0x9365

#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_CLIP_ORIGIN 0x935C
#define GL_LOWER_LEFT 0x8CA1
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_UPPER_LEFT 0x8CA2
#define GL_ZERO_TO_ONE 0x935F

#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_FIXED_ONLY_ARB 0x891D
#define GL_RGBA_FLOAT_MODE_ARB 0x8820

#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127

#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_COMPUTE_SHADER 0x91B9
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC

#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345

#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_QUERY_WAIT_INVERTED 0x8E17

#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37

#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_MAX_CULL_DISTANCES 0x82F9

#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143

#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD

#define GL_DEPTH_CLAMP 0x864F

#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A

#define GL_QUERY_TARGET 0x82EA
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_TEXTURE_TARGET 0x1006

#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_MAX_DRAW_BUFFERS_ARB 0x8824

#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43

#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C

#define GL_FIXED 0x140C
#define GL_HIGH_FLOAT 0x8DF2
#define GL_HIGH_INT 0x8DF5
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_LOW_FLOAT 0x8DF0
#define GL_LOW_INT 0x8DF3
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_MEDIUM_INT 0x8DF4
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_RGB565 0x8D62
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_SHADER_COMPILER 0x8DFA

#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69

#define GL_BACK 0x0405

#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_PRIMITIVE_BOUNDING_BOX_ARB 0x92BE

#define GL_MAX_UNIFORM_LOCATIONS 0x826E

#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7

#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49

#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315

#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_STENCIL 0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER 0x8D40
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_INDEX 0x8222
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_MAX_SAMPLES 0x8D57
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX16 0x8D49
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_UNSIGNED_NORMALIZED 0x8C17

#define GL_FRAMEBUFFER_SRGB 0x8DB9

#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER From: ARB_framebuffer_object*/
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D

#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257

#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B

#define GL_DOUBLE 0x140A
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE

#define GL_INT64_ARB 0x140E
#define GL_INT64_VEC2_ARB 0x8FE9
#define GL_INT64_VEC3_ARB 0x8FEA
#define GL_INT64_VEC4_ARB 0x8FEB
#define GL_UNSIGNED_INT64_ARB 0x140F
#define GL_UNSIGNED_INT64_VEC2_ARB 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB 0x8FF7

#define GL_HALF_FLOAT_ARB 0x140B

#define GL_HALF_FLOAT 0x140B

#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_COLOR_TABLE 0x80D0
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_CONSTANT_ALPHA 0x8003
#define GL_CONSTANT_BORDER 0x8151
#define GL_CONSTANT_COLOR 0x8001
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_CONVOLUTION_BORDER_COLOR 0x8154
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_HISTOGRAM 0x8024
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_SINK 0x802D
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_MAX 0x8008
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MIN 0x8007
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_REDUCE 0x8016
#define GL_REPLICATE_BORDER 0x8153
#define GL_SEPARABLE_2D 0x8012
#define GL_TABLE_TOO_LARGE 0x8031

#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE

#define GL_NUM_SAMPLE_COUNTS 0x9380

#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_CLEAR_BUFFER 0x82B4
#define GL_COLOR_COMPONENTS 0x8283
#define GL_COLOR_ENCODING 0x8296
#define GL_COLOR_RENDERABLE 0x8286
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_FILTER 0x829A
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FULL_SUPPORT 0x82B7
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_WIDTH 0x827E
#define GL_MIPMAP 0x8293
/*Copied GL_NUM_SAMPLE_COUNTS From: ARB_internalformat_query*/
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
/*Copied GL_RENDERBUFFER From: ARB_framebuffer_object*/
#define GL_SAMPLES 0x80A9
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VERTEX_TEXTURE 0x829B
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6

#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC

#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
/*Copied GL_MAP_READ_BIT From: ARB_buffer_storage*/
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
/*Copied GL_MAP_WRITE_BIT From: ARB_buffer_storage*/

#define GL_MULTISAMPLE_ARB 0x809D
#define GL_MULTISAMPLE_BIT_ARB 0x20000000
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA

#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9

#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914

#define GL_ANY_SAMPLES_PASSED 0x8C2F

#define GL_COMPLETION_STATUS_ARB 0x91B1
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0

#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
/*Copied GL_GEOMETRY_SHADER_INVOCATIONS From: ARB_gpu_shader5*/
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_VERTICES_SUBMITTED_ARB 0x82EE

#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF

#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_SIZE_MIN_ARB 0x8126

#define GL_COORD_REPLACE_ARB 0x8862
#define GL_POINT_SPRITE_ARB 0x8861

#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_ARRAY_SIZE 0x92FB
#define GL_ARRAY_STRIDE 0x92FE
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BLOCK_INDEX 0x92FD
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_IS_PER_PATCH 0x92E7
#define GL_IS_ROW_MAJOR 0x9300
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_MATRIX_STRIDE 0x92FF
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_OFFSET 0x92FC
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_TYPE 0x92FA
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE

#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C

#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_NO_ERROR 0
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255

#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
#define GL_SAMPLE_SHADING_ARB 0x8C36

#define GL_SAMPLER_BINDING 0x8919

#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F

#define GL_ACTIVE_PROGRAM 0x8259
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_VERTEX_SHADER_BIT 0x00000001

#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
/*Copied GL_ATOMIC_COUNTER_BUFFER From: ARB_program_interface_query*/
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB

#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_TYPE From: ARB_internalformat_query2*/
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001

#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SHADER_OBJECT_ARB 0x8B48

/*Copied GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS From: ARB_shader_image_load_store*/
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4

#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
/*Copied GL_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
/*Copied GL_NUM_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_SIZE 0x8A38

#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C

#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
#define GL_SHADER_INCLUDE_ARB 0x8DAE

#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C

#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8
#define GL_SPARSE_STORAGE_BIT_ARB 0x0400

#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197

#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA

#define GL_ALREADY_SIGNALED 0x911A
#define GL_CONDITION_SATISFIED 0x911C
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SIGNALED 0x9119
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_SYNC_STATUS 0x9114
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_UNSIGNALED 0x9118
#define GL_WAIT_FAILED 0x911D

#define GL_CCW 0x0901
#define GL_CW 0x0900
#define GL_EQUAL 0x0202
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_ISOLINES 0x8E7A
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_PATCHES 0x000E
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_PATCH_VERTICES 0x8E72
#define GL_QUADS 0x0007
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TRIANGLES 0x0004
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1

#define GL_CLAMP_TO_BORDER_ARB 0x812D

#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E

#define GL_RGB32F 0x8815
#define GL_RGB32I 0x8D83
#define GL_RGB32UI 0x8D71

#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_BUFFER_SIZE 0x919E

#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D

#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE

#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C
#define GL_NORMAL_MAP_ARB 0x8511
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519

#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F

#define GL_ADD_SIGNED_ARB 0x8574
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_CONSTANT_ARB 0x8576
#define GL_INTERPOLATE_ARB 0x8575
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_PREVIOUS_ARB 0x8578
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_RGB_SCALE_ARB 0x8573
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SUBTRACT_ARB 0x84E7

#define GL_DOT3_RGBA_ARB 0x86AF
#define GL_DOT3_RGB_ARB 0x86AE

#define GL_ALPHA16F_ARB 0x881C
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY16F_ARB 0x881D
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGB16F_ARB 0x881B
#define GL_RGB32F_ARB 0x8815
#define GL_RGBA16F_ARB 0x881A
#define GL_RGBA32F_ARB 0x8814
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17

#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E

#define GL_MIRROR_CLAMP_TO_EDGE 0x8743

#define GL_MIRRORED_REPEAT_ARB 0x8370

#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_SAMPLE_POSITION 0x8E50
/*Copied GL_TEXTURE_2D_MULTISAMPLE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY From: ARB_direct_state_access*/
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D

#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5

#define GL_R16 0x822A
#define GL_R16F 0x822D
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32F 0x822E
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_R8 0x8229
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_RG 0x8227
#define GL_RG16 0x822C
#define GL_RG16F 0x822F
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32F 0x8230
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_RG8 0x822B
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG_INTEGER 0x8228

#define GL_RGB10_A2UI 0x906F

#define GL_STENCIL_INDEX 0x1901
/*Copied GL_STENCIL_INDEX8 From: ARB_framebuffer_object*/

#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46

#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC

#define GL_TIMESTAMP 0x8E28
#define GL_TIME_ELAPSED 0x88BF

#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23

#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
/*Copied GL_MAX_VERTEX_STREAMS From: ARB_gpu_shader5*/

#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED

#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5

#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
/*Copied GL_UNIFORM_NAME_LENGTH From: ARB_shader_subroutine*/
#define GL_UNIFORM_OFFSET 0x8A3B
/*Copied GL_UNIFORM_SIZE From: ARB_shader_subroutine*/
#define GL_UNIFORM_TYPE 0x8A37

#define GL_BGRA 0x80E1

#define GL_VERTEX_ARRAY_BINDING 0x85B5

/*Copied GL_DOUBLE_MAT2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT2x3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT2x4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3x2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3x4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4x2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4x3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC4 From: ARB_gpu_shader_fp64*/
/*Copied GL_RGB32I From: ARB_texture_buffer_object_rgb32*/

#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8

#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_DYNAMIC_COPY_ARB 0x88EA
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_READ_ONLY_ARB 0x88B8
#define GL_READ_WRITE_ARB 0x88BA
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_WRITE_ONLY_ARB 0x88B9

#define GL_COLOR_SUM_ARB 0x8458
/*Copied GL_CURRENT_MATRIX_ARB From: ARB_fragment_program*/
/*Copied GL_CURRENT_MATRIX_STACK_DEPTH_ARB From: ARB_fragment_program*/
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
/*Copied GL_MATRIX0_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX10_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX11_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX12_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX13_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX14_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX15_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX16_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX17_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX18_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX19_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX1_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX20_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX21_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX22_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX23_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX24_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX25_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX26_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX27_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX28_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX29_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX2_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX30_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX31_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX3_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX4_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX5_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX6_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX7_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX8_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX9_ARB From: ARB_fragment_program*/
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
/*Copied GL_MAX_PROGRAM_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_ENV_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_MATRICES_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB From: ARB_fragment_program*/
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
/*Copied GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_TEMPORARIES_ARB From: ARB_fragment_program*/
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
/*Copied GL_PROGRAM_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_BINDING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_ERROR_POSITION_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_ERROR_STRING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_FORMAT_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_FORMAT_ASCII_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_LENGTH_ARB From: ARB_fragment_program*/
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
/*Copied GL_PROGRAM_NATIVE_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_STRING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB From: ARB_fragment_program*/
/*Copied GL_TRANSPOSE_CURRENT_MATRIX_ARB From: ARB_fragment_program*/
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643

/*Copied GL_CURRENT_VERTEX_ATTRIB_ARB From: ARB_vertex_program*/
#define GL_FLOAT 0x1406
/*Copied GL_FLOAT_MAT2_ARB From: ARB_shader_objects*/
/*Copied GL_FLOAT_MAT3_ARB From: ARB_shader_objects*/
/*Copied GL_FLOAT_MAT4_ARB From: ARB_shader_objects*/
/*Copied GL_FLOAT_VEC2_ARB From: ARB_shader_objects*/
/*Copied GL_FLOAT_VEC3_ARB From: ARB_shader_objects*/
/*Copied GL_FLOAT_VEC4_ARB From: ARB_shader_objects*/
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
/*Copied GL_MAX_TEXTURE_COORDS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_TEXTURE_IMAGE_UNITS_ARB From: ARB_fragment_program*/
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
/*Copied GL_MAX_VERTEX_ATTRIBS_ARB From: ARB_vertex_program*/
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
/*Copied GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_PROGRAM_POINT_SIZE_ARB From: ARB_vertex_program*/
/*Copied GL_VERTEX_PROGRAM_TWO_SIDE_ARB From: ARB_vertex_program*/
#define GL_VERTEX_SHADER_ARB 0x8B31

#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B

#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368

#define GL_DEPTH_RANGE 0x0B70
/*Copied GL_FIRST_VERTEX_CONVENTION From: ARB_provoking_vertex*/
/*Copied GL_LAST_VERTEX_CONVENTION From: ARB_provoking_vertex*/
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_MAX_VIEWPORTS 0x825B
/*Copied GL_PROVOKING_VERTEX From: ARB_provoking_vertex*/
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_VIEWPORT 0x0BA2
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C

#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_DRAW_BUFFER15_ATI 0x8834
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_MAX_DRAW_BUFFERS_ATI 0x8824

#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_RGB_FLOAT32_ATI 0x8815

#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743

#define GL_RGB4_S3TC 0x83A1
#define GL_RGBA4_DXT5_S3TC 0x83A5
#define GL_RGBA4_S3TC 0x83A3
#define GL_RGBA_DXT5_S3TC 0x83A4
#define GL_RGBA_S3TC 0x83A2
#define GL_RGB_S3TC 0x83A0

#define GL_ABGR_EXT 0x8000

#define GL_BGRA_EXT 0x80E1
#define GL_BGR_EXT 0x80E0

#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF
#define GL_UNIFORM_BUFFER_EXT 0x8DEE

#define GL_BLEND_COLOR_EXT 0x8005
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002

#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D
#define GL_BLEND_EQUATION_RGB_EXT 0x8009

#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB
#define GL_BLEND_SRC_RGB_EXT 0x80C9

#define GL_BLEND_EQUATION_EXT 0x8009
#define GL_FUNC_ADD_EXT 0x8006
#define GL_MAX_EXT 0x8008
#define GL_MIN_EXT 0x8007

#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B
#define GL_FUNC_SUBTRACT_EXT 0x800A

#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8

#define GL_DEPTH_BOUNDS_EXT 0x8891
#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890

#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E

#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9
#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8

#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FRAGMENT_DEPTH_EXT 0x8452

#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA
#define GL_READ_FRAMEBUFFER_EXT 0x8CA8

#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT 0x8D57
#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB

#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB

#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48

#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA
#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9

#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D

#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT 0x8905
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT 0x8904
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT 0x88FD

#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA

#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B

#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034

#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC

#define GL_DISTANCE_ATTENUATION_EXT 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_SIZE_MIN_EXT 0x8126

#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B

#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C

#define GL_RESCALE_NORMAL_EXT 0x803A

#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B

#define GL_ACTIVE_PROGRAM_EXT 0x8B8D

#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
#define GL_SINGLE_COLOR_EXT 0x81F9

#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001

#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911
#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910

#define GL_DECR_WRAP_EXT 0x8508
#define GL_INCR_WRAP_EXT 0x8507

#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D

#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT From: EXT_geometry_shader4*/
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D

#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E

#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71

#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC

#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0

#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C
#define GL_NORMAL_MAP_EXT 0x8511
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519

#define GL_ADD_SIGNED_EXT 0x8574
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_CONSTANT_EXT 0x8576
#define GL_INTERPOLATE_EXT 0x8575
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_ALPHA_EXT 0x859A
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_PREVIOUS_EXT 0x8578
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_RGB_SCALE_EXT 0x8573
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_SOURCE2_RGB_EXT 0x8582

#define GL_DOT3_RGBA_EXT 0x8741
#define GL_DOT3_RGB_EXT 0x8740

#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE

#define GL_ALPHA16I_EXT 0x8D8A
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_ALPHA32I_EXT 0x8D84
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_ALPHA8I_EXT 0x8D90
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_RGB16I_EXT 0x8D89
#define GL_RGB16UI_EXT 0x8D77
#define GL_RGB32I_EXT 0x8D83
#define GL_RGB32UI_EXT 0x8D71
#define GL_RGB8I_EXT 0x8D8F
#define GL_RGB8UI_EXT 0x8D7D
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E
#define GL_RGB_INTEGER_EXT 0x8D98

#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501

#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743

#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A
#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067

#define GL_RGB9_E5_EXT 0x8C3D
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E

#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB_EXT 0x8C40

#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48

#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46
#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42

#define GL_TIME_ELAPSED_EXT 0x88BF

#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B

/*Copied GL_BGRA From: ARB_vertex_array_bgra*/

/*Copied GL_DOUBLE From: ARB_gpu_shader_fp64*/
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE

#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262

#define GL_MIRRORED_REPEAT_IBM 0x8370

#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#define GL_NONE 0

#define GL_BUFFER 0x82E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DISPLAY_LIST 0x82E7
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_PROGRAM 0x82E2
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_QUERY 0x82E3
#define GL_SAMPLER 0x82E6
#define GL_SHADER 0x82E1
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_VERTEX_ARRAY 0x8074

#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR 0x00000008

#define GL_CONTEXT_LOST 0x0507
#define GL_CONTEXT_ROBUST_ACCESS 0x90F3
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
/*Copied GL_NO_ERROR From: ARB_robustness*/
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_UNKNOWN_CONTEXT_RESET 0x8255

#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
#define GL_BLUE_NV 0x1905
#define GL_COLORBURN_NV 0x929A
#define GL_COLORDODGE_NV 0x9299
#define GL_CONJOINT_NV 0x9284
#define GL_CONTRAST_NV 0x92A1
#define GL_DARKEN_NV 0x9297
#define GL_DIFFERENCE_NV 0x929E
#define GL_DISJOINT_NV 0x9283
#define GL_DST_ATOP_NV 0x928F
#define GL_DST_IN_NV 0x928B
#define GL_DST_NV 0x9287
#define GL_DST_OUT_NV 0x928D
#define GL_DST_OVER_NV 0x9289
#define GL_EXCLUSION_NV 0x92A0
#define GL_GREEN_NV 0x1904
#define GL_HARDLIGHT_NV 0x929B
#define GL_HARDMIX_NV 0x92A9
#define GL_HSL_COLOR_NV 0x92AF
#define GL_HSL_HUE_NV 0x92AD
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_INVERT 0x150A
#define GL_INVERT_OVG_NV 0x92B4
#define GL_INVERT_RGB_NV 0x92A3
#define GL_LIGHTEN_NV 0x9298
#define GL_LINEARBURN_NV 0x92A5
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_MINUS_NV 0x929F
#define GL_MULTIPLY_NV 0x9294
#define GL_OVERLAY_NV 0x9296
#define GL_PINLIGHT_NV 0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_PLUS_DARKER_NV 0x9292
#define GL_PLUS_NV 0x9291
#define GL_RED_NV 0x1903
#define GL_SCREEN_NV 0x9295
#define GL_SOFTLIGHT_NV 0x929C
#define GL_SRC_ATOP_NV 0x928E
#define GL_SRC_IN_NV 0x928A
#define GL_SRC_NV 0x9286
#define GL_SRC_OUT_NV 0x928C
#define GL_SRC_OVER_NV 0x9288
#define GL_UNCORRELATED_NV 0x9282
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_XOR_NV 0x1506
#define GL_ZERO 0

#define GL_ALPHA_REF_COMMAND_NV 0x000F
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV 0x0009
#define GL_BLEND_COLOR_COMMAND_NV 0x000B
#define GL_DRAW_ARRAYS_COMMAND_NV 0x0003
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV 0x0005
#define GL_DRAW_ELEMENTS_COMMAND_NV 0x0002
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_ELEMENT_ADDRESS_COMMAND_NV 0x0008
#define GL_FRONT_FACE_COMMAND_NV 0x0012
#define GL_LINE_WIDTH_COMMAND_NV 0x000D
#define GL_NOP_COMMAND_NV 0x0001
#define GL_POLYGON_OFFSET_COMMAND_NV 0x000E
#define GL_SCISSOR_COMMAND_NV 0x0011
#define GL_STENCIL_REF_COMMAND_NV 0x000C
#define GL_TERMINATE_SEQUENCE_COMMAND_NV 0x0000
#define GL_UNIFORM_ADDRESS_COMMAND_NV 0x000A
#define GL_VIEWPORT_COMMAND_NV 0x0010

#define GL_COMPUTE_PROGRAM_NV 0x90FB
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV 0x90FC

#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_WAIT_NV 0x8E13

#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F
#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E

#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD

#define GL_DEPTH_CLAMP_NV 0x864F

#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58

#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_CONDITION_NV 0x84F4
#define GL_FENCE_STATUS_NV 0x84F3

#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_FLOAT_R16_NV 0x8884
#define GL_FLOAT_R32_NV 0x8885
#define GL_FLOAT_RG16_NV 0x8886
#define GL_FLOAT_RG32_NV 0x8887
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_FLOAT_RGBA_MODE_NV 0x888E
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_FLOAT_RGB_NV 0x8882
#define GL_FLOAT_RG_NV 0x8881
#define GL_FLOAT_R_NV 0x8880
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C

#define GL_EYE_PLANE 0x2502
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C
#define GL_EYE_RADIAL_NV 0x855B
#define GL_FOG_DISTANCE_MODE_NV 0x855A

#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_PROGRAM_ERROR_STRING_NV 0x8874

#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7

#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB

#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907

#define GL_CONFORMANT_NV 0x9374
#define GL_MULTISAMPLES_NV 0x9371
/*Copied GL_RENDERBUFFER From: ARB_internalformat_query2*/
#define GL_SUPERSAMPLE_SCALE_X_NV 0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV 0x9373
/*Copied GL_TEXTURE_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/

#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E

#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_NV 0x140E
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
/*Copied GL_PATCHES From: ARB_tessellation_shader*/
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF

#define GL_HALF_FLOAT_NV 0x140B

#define GL_MAX_SHININESS_NV 0x8504
#define GL_MAX_SPOT_EXPONENT_NV 0x8505

#define GL_COLOR_SAMPLES_NV 0x8E20
/*Copied GL_SAMPLES_ARB From: ARB_multisample*/

#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534

#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867
#define GL_PIXEL_COUNT_NV 0x8866

#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_UNSIGNED_INT_24_8_NV 0x84FA

#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2

#define GL_2_BYTES_NV 0x1407
#define GL_3_BYTES_NV 0x1408
#define GL_4_BYTES_NV 0x1409
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_AFFINE_2D_NV 0x9092
#define GL_AFFINE_3D_NV 0x9094
#define GL_ARC_TO_NV 0xFE
#define GL_BEVEL_NV 0x90A6
#define GL_BOLD_BIT_NV 0x01
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_CLOSE_PATH_NV 0x00
#define GL_CONIC_CURVE_TO_NV 0x1A
#define GL_CONSTANT_NV 0x8576
#define GL_CONVEX_HULL_NV 0x908B
#define GL_COUNT_DOWN_NV 0x9089
#define GL_COUNT_UP_NV 0x9088
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_EYE_LINEAR_NV 0x2400
#define GL_FILE_NAME_NV 0x9074
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_FONT_GLYPHS_AVAILABLE_NV 0x9368
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV 0x20000000
#define GL_FONT_TARGET_UNAVAILABLE_NV 0x9369
#define GL_FONT_UNAVAILABLE_NV 0x936A
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_UNINTELLIGIBLE_NV 0x936B
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_FRAGMENT_INPUT_NV 0x936D
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_ITALIC_BIT_NV 0x02
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_LINE_TO_NV 0x04
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_MOVE_TO_NV 0x02
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_OBJECT_LINEAR_NV 0x2401
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_MODELVIEW_MATRIX_NV 0x0BA6
#define GL_PATH_MODELVIEW_NV 0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV 0x0BA3
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_PATH_PROJECTION_MATRIX_NV 0x0BA7
#define GL_PATH_PROJECTION_NV 0x1701
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_PRIMARY_COLOR 0x8577
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RECT_NV 0xF6
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_RELATIVE_CONIC_CURVE_TO_NV 0x1B
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_RELATIVE_RECT_NV 0xF7
#define GL_RELATIVE_ROUNDED_RECT2_NV 0xEB
#define GL_RELATIVE_ROUNDED_RECT4_NV 0xED
#define GL_RELATIVE_ROUNDED_RECT8_NV 0xEF
#define GL_RELATIVE_ROUNDED_RECT_NV 0xE9
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_RESTART_PATH_NV 0xF0
#define GL_ROUNDED_RECT2_NV 0xEA
#define GL_ROUNDED_RECT4_NV 0xEC
#define GL_ROUNDED_RECT8_NV 0xEE
#define GL_ROUNDED_RECT_NV 0xE8
#define GL_ROUND_NV 0x90A4
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_SQUARE_NV 0x90A3
#define GL_STANDARD_FONT_FORMAT_NV 0x936C
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_TRIANGULAR_NV 0x90A5
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_UTF16_NV 0x909B
#define GL_UTF8_NV 0x909A
#define GL_VERTICAL_LINE_TO_NV 0x08

#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C

#define GL_COORD_REPLACE_NV 0x8862
#define GL_POINT_SPRITE_NV 0x8861
#define GL_POINT_SPRITE_R_MODE_NV 0x8863

#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559
#define GL_PRIMITIVE_RESTART_NV 0x8558

#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_DISCARD_NV 0x8530
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_E_TIMES_F_NV 0x8531
#define GL_FOG 0x0B60
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
/*Copied GL_NONE From: KHR_context_flush_control*/
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
/*Copied GL_PRIMARY_COLOR_NV From: NV_path_rendering*/
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_SCALE_BY_TWO_NV 0x853E
/*Copied GL_SECONDARY_COLOR_NV From: NV_path_rendering*/
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_SPARE1_NV 0x852F
/*Copied GL_TEXTURE0_ARB From: ARB_multitexture*/
/*Copied GL_TEXTURE1_ARB From: ARB_multitexture*/
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
/*Copied GL_ZERO From: NV_blend_equation_advanced*/

#define GL_PER_STAGE_CONSTANTS_NV 0x8535

#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35

#define GL_NORMAL_MAP_NV 0x8511
#define GL_REFLECTION_MAP_NV 0x8512

#define GL_COMBINE4_NV 0x8503
#define GL_OPERAND3_ALPHA_NV 0x859B
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_SOURCE3_RGB_NV 0x8583

#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046
#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045

#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_TEXTURE_RECTANGLE_NV 0x84F5

#define GL_CONST_EYE_NV 0x86E5
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_CULL_MODES_NV 0x86E0
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_DSDT8_NV 0x8709
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_DSDT_MAG_NV 0x86F6
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_DSDT_NV 0x86F5
#define GL_DS_BIAS_NV 0x8716
#define GL_DS_SCALE_NV 0x8710
#define GL_DT_BIAS_NV 0x8717
#define GL_DT_SCALE_NV 0x8711
#define GL_HILO16_NV 0x86F8
#define GL_HILO_NV 0x86F4
#define GL_HI_BIAS_NV 0x8714
#define GL_HI_SCALE_NV 0x870E
#define GL_LO_BIAS_NV 0x8715
#define GL_LO_SCALE_NV 0x870F
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_OFFSET_TEXTURE_2D_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_OFFSET_TEXTURE_2D_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_TEXTURE_MAG_SIZE_NV 0x871F
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_VIBRANCE_SCALE_NV 0x8713

#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF

#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860
#define GL_HILO8_NV 0x885E
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_SIGNED_HILO8_NV 0x885F

#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_LAYER_NV 0x8DAA
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_NEXT_BUFFER_NV -2
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_SKIP_COMPONENTS1_NV -6
#define GL_SKIP_COMPONENTS2_NV -5
#define GL_SKIP_COMPONENTS3_NV -4
#define GL_SKIP_COMPONENTS4_NV -3
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_VERTEX_ID_NV 0x8C7B

#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_NV 0x8E22

#define GL_UNIFORM_BUFFER_ADDRESS_NV 0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV 0x9370
#define GL_UNIFORM_BUFFER_UNIFIED_NV 0x936E

#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F

#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533

/*Copied GL_INT64_NV From: NV_gpu_shader5*/
/*Copied GL_UNSIGNED_INT64_NV From: NV_gpu_shader5*/

#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E

#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_IDENTITY_NV 0x862A
#define GL_INVERSE_NV 0x862B
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_MATRIX0_NV 0x8630
#define GL_MATRIX1_NV 0x8631
#define GL_MATRIX2_NV 0x8632
#define GL_MATRIX3_NV 0x8633
#define GL_MATRIX4_NV 0x8634
#define GL_MATRIX5_NV 0x8635
#define GL_MATRIX6_NV 0x8636
#define GL_MATRIX7_NV 0x8637
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_TRANSPOSE_NV 0x862C
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621

/*Copied GL_MAX_PROGRAM_CALL_DEPTH_NV From: NV_fragment_program2*/
/*Copied GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV From: NV_fragment_program2*/

/*Copied GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB From: ARB_vertex_shader*/

#define GL_FAILURE_NV 0x9030
#define GL_FIELD_LOWER_NV 0x9023
#define GL_FIELD_UPPER_NV 0x9022
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_SUCCESS_NV 0x902F
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_YCBYCR8_422_NV 0x9031
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033

#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX 0x9049
#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX 0x9047
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX 0x904B
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX 0x904A
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX 0x9048

#define GL_SM_COUNT_NV 0x933B
#define GL_WARPS_PER_SM_NV 0x933A
#define GL_WARP_SIZE_NV 0x9339

#define GL_COLORBURN_KHR 0x929A
#define GL_COLORDODGE_KHR 0x9299
#define GL_DARKEN_KHR 0x9297
#define GL_DIFFERENCE_KHR 0x929E
#define GL_EXCLUSION_KHR 0x92A0
#define GL_HARDLIGHT_KHR 0x929B
#define GL_HSL_COLOR_KHR 0x92AF
#define GL_HSL_HUE_KHR 0x92AD
#define GL_HSL_LUMINOSITY_KHR 0x92B0
#define GL_HSL_SATURATION_KHR 0x92AE
#define GL_LIGHTEN_KHR 0x9298
#define GL_MULTIPLY_KHR 0x9294
#define GL_OVERLAY_KHR 0x9296
#define GL_SCREEN_KHR 0x9295
#define GL_SOFTLIGHT_KHR 0x929C

#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192
#define GL_GENERATE_MIPMAP_SGIS 0x8191

#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_TEXTURE_MIN_LOD_SGIS 0x813A

#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7

#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C

#define GL_SLICE_ACCUM_SUN 0x85CC

#define GL_ALPHA 0x1906
#define GL_ALWAYS 0x0207
#define GL_AND 0x1501
#define GL_AND_INVERTED 0x1504
#define GL_AND_REVERSE 0x1502
/*Copied GL_BACK From: ARB_ES3_1_compatibility*/
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_BLEND 0x0BE2
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLUE 0x1905
#define GL_BYTE 0x1400
/*Copied GL_CCW From: ARB_tessellation_shader*/
#define GL_CLEAR 0x1500
#define GL_COLOR 0x1800
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_COPY 0x1503
#define GL_COPY_INVERTED 0x150C
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
/*Copied GL_CW From: ARB_tessellation_shader*/
#define GL_DECR 0x1E03
#define GL_DEPTH 0x1801
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_COMPONENT 0x1902
#define GL_DEPTH_FUNC 0x0B74
/*Copied GL_DEPTH_RANGE From: ARB_viewport_array*/
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DITHER 0x0BD0
#define GL_DONT_CARE 0x1100
/*Copied GL_DOUBLE From: EXT_vertex_attrib_64bit*/
#define GL_DOUBLEBUFFER 0x0C32
#define GL_DRAW_BUFFER 0x0C01
#define GL_DST_ALPHA 0x0304
#define GL_DST_COLOR 0x0306
/*Copied GL_EQUAL From: ARB_tessellation_shader*/
#define GL_EQUIV 0x1509
#define GL_EXTENSIONS 0x1F03
#define GL_FALSE 0
#define GL_FASTEST 0x1101
#define GL_FILL 0x1B02
/*Copied GL_FLOAT From: ARB_vertex_shader*/
#define GL_FRONT 0x0404
#define GL_FRONT_AND_BACK 0x0408
#define GL_FRONT_FACE 0x0B46
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_GEQUAL 0x0206
#define GL_GREATER 0x0204
#define GL_GREEN 0x1904
#define GL_INCR 0x1E02
#define GL_INT 0x1404
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_OPERATION 0x0502
#define GL_INVALID_VALUE 0x0501
/*Copied GL_INVERT From: NV_blend_equation_advanced*/
#define GL_KEEP 0x1E00
#define GL_LEFT 0x0406
#define GL_LEQUAL 0x0203
#define GL_LESS 0x0201
#define GL_LINE 0x1B01
#define GL_LINEAR 0x2601
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_LINE_STRIP 0x0003
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_NAND 0x150E
#define GL_NEAREST 0x2600
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_NEVER 0x0200
#define GL_NICEST 0x1102
/*Copied GL_NONE From: NV_register_combiners*/
#define GL_NOOP 0x1505
#define GL_NOR 0x1508
#define GL_NOTEQUAL 0x0205
/*Copied GL_NO_ERROR From: KHR_robustness*/
#define GL_ONE 1
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_OR 0x1507
#define GL_OR_INVERTED 0x150D
#define GL_OR_REVERSE 0x150B
#define GL_OUT_OF_MEMORY 0x0505
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_POINT 0x1B00
#define GL_POINTS 0x0000
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
/*Copied GL_QUADS From: ARB_tessellation_shader*/
#define GL_R3_G3_B2 0x2A10
#define GL_READ_BUFFER 0x0C02
#define GL_RED 0x1903
#define GL_RENDERER 0x1F01
#define GL_REPEAT 0x2901
#define GL_REPLACE 0x1E01
#define GL_RGB 0x1907
#define GL_RGB10 0x8052
#define GL_RGB10_A2 0x8059
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB5_A1 0x8057
#define GL_RGB8 0x8051
#define GL_RGBA 0x1908
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGBA8 0x8058
#define GL_RIGHT 0x0407
/*Copied GL_SCISSOR_BOX From: ARB_viewport_array*/
/*Copied GL_SCISSOR_TEST From: ARB_viewport_array*/
#define GL_SET 0x150F
#define GL_SHORT 0x1402
#define GL_SRC_ALPHA 0x0302
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_SRC_COLOR 0x0300
/*Copied GL_STACK_OVERFLOW From: KHR_debug*/
/*Copied GL_STACK_UNDERFLOW From: KHR_debug*/
#define GL_STENCIL 0x1802
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_FUNC 0x0B92
/*Copied GL_STENCIL_INDEX From: ARB_texture_stencil8*/
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_STEREO 0x0C33
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE 0x1702
/*Copied GL_TEXTURE_1D From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D From: ARB_internalformat_query2*/
#define GL_TEXTURE_ALPHA_SIZE 0x805F
/*Copied GL_TEXTURE_BINDING_1D From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_BINDING_2D From: ARB_direct_state_access*/
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
/*Copied GL_TRIANGLES From: ARB_tessellation_shader*/
#define GL_TRIANGLE_FAN 0x0006
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRUE 1
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_UNSIGNED_SHORT 0x1403
#define GL_VENDOR 0x1F00
#define GL_VERSION 0x1F02
/*Copied GL_VERTEX_ARRAY From: KHR_debug*/
/*Copied GL_VIEWPORT From: ARB_viewport_array*/
#define GL_XOR 0x1506
/*Copied GL_ZERO From: NV_register_combiners*/

#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_BGR 0x80E0
/*Copied GL_BGRA From: EXT_vertex_array_bgra*/
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
/*Copied GL_TEXTURE_3D From: ARB_internalformat_query2*/
#define GL_TEXTURE_BASE_LEVEL 0x813C
/*Copied GL_TEXTURE_BINDING_3D From: ARB_direct_state_access*/
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
/*Copied GL_UNSIGNED_INT_2_10_10_10_REV From: ARB_vertex_type_2_10_10_10_rev*/
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364

#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_MULTISAMPLE 0x809D
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
/*Copied GL_SAMPLES From: ARB_internalformat_query2*/
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
/*Copied GL_TEXTURE_BINDING_CUBE_MAP From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_COMPRESSED From: ARB_internalformat_query2*/
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
/*Copied GL_TEXTURE_CUBE_MAP From: ARB_internalformat_query2*/
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519

/*Copied GL_BLEND_COLOR From: ARB_imaging*/
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_BLEND_SRC_RGB 0x80C9
/*Copied GL_CONSTANT_ALPHA From: ARB_imaging*/
/*Copied GL_CONSTANT_COLOR From: ARB_imaging*/
#define GL_DECR_WRAP 0x8508
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
/*Copied GL_FUNC_ADD From: ARB_imaging*/
/*Copied GL_FUNC_REVERSE_SUBTRACT From: ARB_imaging*/
/*Copied GL_FUNC_SUBTRACT From: ARB_imaging*/
#define GL_INCR_WRAP 0x8507
/*Copied GL_MAX From: ARB_imaging*/
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
/*Copied GL_MIN From: ARB_imaging*/
#define GL_MIRRORED_REPEAT 0x8370
/*Copied GL_ONE_MINUS_CONSTANT_ALPHA From: ARB_imaging*/
/*Copied GL_ONE_MINUS_CONSTANT_COLOR From: ARB_imaging*/
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_LOD_BIAS 0x8501

#define GL_ARRAY_BUFFER 0x8892
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_CURRENT_QUERY 0x8865
#define GL_DYNAMIC_COPY 0x88EA
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_READ_ONLY 0x88B8
#define GL_READ_WRITE 0x88BA
#define GL_SAMPLES_PASSED 0x8914
/*Copied GL_SRC1_ALPHA From: ARB_blend_func_extended*/
#define GL_STATIC_COPY 0x88E6
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STREAM_COPY 0x88E2
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_WRITE_ONLY 0x88B9

#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_COMPILE_STATUS 0x8B81
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_DELETE_STATUS 0x8B80
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_LINK_STATUS 0x8B82
/*Copied GL_LOWER_LEFT From: ARB_clip_control*/
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_SHADER_TYPE 0x8B4F
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
/*Copied GL_UPPER_LEFT From: ARB_clip_control*/
#define GL_VALIDATE_STATUS 0x8B83
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_SHADER 0x8B31

#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SRGB_ALPHA 0x8C42

#define GL_BGRA_INTEGER 0x8D9B
#define GL_BGR_INTEGER 0x8D9A
#define GL_BLUE_INTEGER 0x8D96
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
/*Copied GL_COLOR_ATTACHMENT0 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT1 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT10 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT11 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT12 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT13 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT14 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT15 From: ARB_framebuffer_object*/
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_COLOR_ATTACHMENT19 0x8CF3
/*Copied GL_COLOR_ATTACHMENT2 From: ARB_framebuffer_object*/
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
/*Copied GL_COLOR_ATTACHMENT3 From: ARB_framebuffer_object*/
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_COLOR_ATTACHMENT31 0x8CFF
/*Copied GL_COLOR_ATTACHMENT4 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT5 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT6 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT7 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT8 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT9 From: ARB_framebuffer_object*/
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_COMPRESSED_RED 0x8225
/*Copied GL_COMPRESSED_RED_RGTC1 From: ARB_texture_compression_rgtc*/
#define GL_COMPRESSED_RG 0x8226
/*Copied GL_COMPRESSED_RG_RGTC2 From: ARB_texture_compression_rgtc*/
/*Copied GL_COMPRESSED_SIGNED_RED_RGTC1 From: ARB_texture_compression_rgtc*/
/*Copied GL_COMPRESSED_SIGNED_RG_RGTC2 From: ARB_texture_compression_rgtc*/
#define GL_CONTEXT_FLAGS 0x821E
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
/*Copied GL_DEPTH24_STENCIL8 From: ARB_framebuffer_object*/
/*Copied GL_DEPTH32F_STENCIL8 From: ARB_depth_buffer_float*/
/*Copied GL_DEPTH_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_DEPTH_COMPONENT32F From: ARB_depth_buffer_float*/
/*Copied GL_DEPTH_STENCIL From: ARB_framebuffer_object*/
/*Copied GL_DEPTH_STENCIL_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_DRAW_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_DRAW_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
#define GL_FIXED_ONLY 0x891D
/*Copied GL_FLOAT_32_UNSIGNED_INT_24_8_REV From: ARB_depth_buffer_float*/
/*Copied GL_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER From: ARB_geometry_shader4*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_COMPLETE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_DEFAULT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_SRGB From: ARB_framebuffer_sRGB*/
/*Copied GL_FRAMEBUFFER_UNDEFINED From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_UNSUPPORTED From: ARB_framebuffer_object*/
#define GL_GREEN_INTEGER 0x8D95
/*Copied GL_HALF_FLOAT From: ARB_half_float_vertex*/
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
/*Copied GL_INVALID_FRAMEBUFFER_OPERATION From: ARB_framebuffer_object*/
#define GL_MAJOR_VERSION 0x821B
/*Copied GL_MAP_FLUSH_EXPLICIT_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_INVALIDATE_BUFFER_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_INVALIDATE_RANGE_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_READ_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_UNSYNCHRONIZED_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_WRITE_BIT From: ARB_map_buffer_range*/
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MAX_CLIP_DISTANCES 0x0D32
/*Copied GL_MAX_COLOR_ATTACHMENTS From: ARB_framebuffer_object*/
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
/*Copied GL_MAX_RENDERBUFFER_SIZE From: ARB_framebuffer_object*/
/*Copied GL_MAX_SAMPLES From: ARB_framebuffer_object*/
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
/*Copied GL_MAX_VARYING_COMPONENTS From: ARB_geometry_shader4*/
#define GL_MINOR_VERSION 0x821C
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_NUM_EXTENSIONS 0x821D
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_WAIT 0x8E13
#define GL_R11F_G11F_B10F 0x8C3A
/*Copied GL_R16 From: ARB_texture_rg*/
/*Copied GL_R16F From: ARB_texture_rg*/
/*Copied GL_R16I From: ARB_texture_rg*/
/*Copied GL_R16UI From: ARB_texture_rg*/
/*Copied GL_R32F From: ARB_texture_rg*/
/*Copied GL_R32I From: ARB_texture_rg*/
/*Copied GL_R32UI From: ARB_texture_rg*/
/*Copied GL_R8 From: ARB_texture_rg*/
/*Copied GL_R8I From: ARB_texture_rg*/
/*Copied GL_R8UI From: ARB_texture_rg*/
#define GL_RASTERIZER_DISCARD 0x8C89
/*Copied GL_READ_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_READ_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
#define GL_RED_INTEGER 0x8D94
/*Copied GL_RENDERBUFFER From: NV_internalformat_sample_query*/
/*Copied GL_RENDERBUFFER_ALPHA_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_BINDING From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_BLUE_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_DEPTH_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_GREEN_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_HEIGHT From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_INTERNAL_FORMAT From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_RED_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_SAMPLES From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_WIDTH From: ARB_framebuffer_object*/
/*Copied GL_RG From: ARB_texture_rg*/
/*Copied GL_RG16 From: ARB_texture_rg*/
/*Copied GL_RG16F From: ARB_texture_rg*/
/*Copied GL_RG16I From: ARB_texture_rg*/
/*Copied GL_RG16UI From: ARB_texture_rg*/
/*Copied GL_RG32F From: ARB_texture_rg*/
/*Copied GL_RG32I From: ARB_texture_rg*/
/*Copied GL_RG32UI From: ARB_texture_rg*/
/*Copied GL_RG8 From: ARB_texture_rg*/
/*Copied GL_RG8I From: ARB_texture_rg*/
/*Copied GL_RG8UI From: ARB_texture_rg*/
#define GL_RGB16F 0x881B
#define GL_RGB16I 0x8D89
#define GL_RGB16UI 0x8D77
/*Copied GL_RGB32F From: ARB_texture_buffer_object_rgb32*/
/*Copied GL_RGB32I From: ARB_vertex_attrib_64bit*/
/*Copied GL_RGB32UI From: ARB_texture_buffer_object_rgb32*/
#define GL_RGB8I 0x8D8F
#define GL_RGB8UI 0x8D7D
#define GL_RGB9_E5 0x8C3D
#define GL_RGBA16F 0x881A
#define GL_RGBA16I 0x8D88
#define GL_RGBA16UI 0x8D76
#define GL_RGBA32F 0x8814
#define GL_RGBA32I 0x8D82
#define GL_RGBA32UI 0x8D70
#define GL_RGBA8I 0x8D8E
#define GL_RGBA8UI 0x8D7C
#define GL_RGBA_INTEGER 0x8D99
#define GL_RGB_INTEGER 0x8D98
/*Copied GL_RG_INTEGER From: ARB_texture_rg*/
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_SEPARATE_ATTRIBS 0x8C8D
/*Copied GL_STENCIL_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX1 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX16 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX4 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX8 From: ARB_texture_stencil8*/
/*Copied GL_TEXTURE_1D_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D_ARRAY From: ARB_internalformat_query2*/
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
/*Copied GL_TEXTURE_BINDING_1D_ARRAY From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_BINDING_2D_ARRAY From: ARB_direct_state_access*/
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
/*Copied GL_TEXTURE_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER From: ARB_enhanced_layouts*/
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
/*Copied GL_UNSIGNED_INT_10F_11F_11F_REV From: ARB_vertex_type_10f_11f_11f_rev*/
/*Copied GL_UNSIGNED_INT_24_8 From: ARB_framebuffer_object*/
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
/*Copied GL_UNSIGNED_NORMALIZED From: ARB_framebuffer_object*/
/*Copied GL_VERTEX_ARRAY_BINDING From: ARB_vertex_array_object*/
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD

/*Copied GL_ACTIVE_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
/*Copied GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_COPY_READ_BUFFER From: ARB_copy_buffer*/
/*Copied GL_COPY_WRITE_BUFFER From: ARB_copy_buffer*/
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
/*Copied GL_INVALID_INDEX From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_FRAGMENT_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_GEOMETRY_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
/*Copied GL_MAX_UNIFORM_BLOCK_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_UNIFORM_BUFFER_BINDINGS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_VERTEX_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_R16_SNORM 0x8F98
#define GL_R8_SNORM 0x8F94
#define GL_RG16_SNORM 0x8F99
#define GL_RG8_SNORM 0x8F95
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA16_SNORM 0x8F9B
#define GL_RGBA8_SNORM 0x8F97
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_SIGNED_NORMALIZED 0x8F9C
/*Copied GL_TEXTURE_BINDING_BUFFER From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_BINDING_RECTANGLE From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_BUFFER From: ARB_internalformat_query2*/
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
/*Copied GL_TEXTURE_RECTANGLE From: ARB_internalformat_query2*/
/*Copied GL_UNIFORM_ARRAY_STRIDE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_BINDING From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_DATA_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_INDEX From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_BINDING From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_START From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_IS_ROW_MAJOR From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_MATRIX_STRIDE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_OFFSET From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_TYPE From: ARB_uniform_buffer_object*/
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8

/*Copied GL_ALREADY_SIGNALED From: ARB_sync*/
/*Copied GL_CONDITION_SATISFIED From: ARB_sync*/
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_PROFILE_MASK 0x9126
/*Copied GL_DEPTH_CLAMP From: ARB_depth_clamp*/
/*Copied GL_FIRST_VERTEX_CONVENTION From: ARB_viewport_array*/
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
/*Copied GL_INT_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_LAST_VERTEX_CONVENTION From: ARB_viewport_array*/
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
/*Copied GL_MAX_COLOR_TEXTURE_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_MAX_DEPTH_TEXTURE_SAMPLES From: ARB_texture_multisample*/
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
/*Copied GL_MAX_INTEGER_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_MAX_SAMPLE_MASK_WORDS From: ARB_texture_multisample*/
/*Copied GL_MAX_SERVER_WAIT_TIMEOUT From: ARB_sync*/
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
/*Copied GL_OBJECT_TYPE From: ARB_sync*/
#define GL_PROGRAM_POINT_SIZE 0x8642
/*Copied GL_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_PROXY_TEXTURE_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION From: ARB_provoking_vertex*/
/*Copied GL_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_MASK From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_MASK_VALUE From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_POSITION From: ARB_texture_multisample*/
/*Copied GL_SIGNALED From: ARB_sync*/
/*Copied GL_SYNC_CONDITION From: ARB_sync*/
/*Copied GL_SYNC_FENCE From: ARB_sync*/
/*Copied GL_SYNC_FLAGS From: ARB_sync*/
/*Copied GL_SYNC_FLUSH_COMMANDS_BIT From: ARB_sync*/
/*Copied GL_SYNC_GPU_COMMANDS_COMPLETE From: ARB_sync*/
/*Copied GL_SYNC_STATUS From: ARB_sync*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE From: NV_internalformat_sample_query*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE_ARRAY From: NV_internalformat_sample_query*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_CUBE_MAP_SEAMLESS From: ARB_seamless_cube_map*/
/*Copied GL_TEXTURE_FIXED_SAMPLE_LOCATIONS From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_TIMEOUT_EXPIRED From: ARB_sync*/
/*Copied GL_TIMEOUT_IGNORED From: ARB_sync*/
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
/*Copied GL_UNSIGNALED From: ARB_sync*/
/*Copied GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_WAIT_FAILED From: ARB_sync*/

/*Copied GL_ANY_SAMPLES_PASSED From: ARB_occlusion_query2*/
/*Copied GL_INT_2_10_10_10_REV From: ARB_vertex_type_2_10_10_10_rev*/
/*Copied GL_MAX_DUAL_SOURCE_DRAW_BUFFERS From: ARB_blend_func_extended*/
/*Copied GL_ONE_MINUS_SRC1_ALPHA From: ARB_blend_func_extended*/
/*Copied GL_ONE_MINUS_SRC1_COLOR From: ARB_blend_func_extended*/
/*Copied GL_RGB10_A2UI From: ARB_texture_rgb10_a2ui*/
/*Copied GL_SAMPLER_BINDING From: ARB_sampler_objects*/
/*Copied GL_SRC1_COLOR From: ARB_blend_func_extended*/
/*Copied GL_TEXTURE_SWIZZLE_A From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_B From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_G From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_R From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_RGBA From: ARB_texture_swizzle*/
/*Copied GL_TIMESTAMP From: ARB_timer_query*/
/*Copied GL_TIME_ELAPSED From: ARB_timer_query*/
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE

/*Copied GL_ACTIVE_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_MAX_LENGTH From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORMS From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH From: ARB_shader_subroutine*/
/*Copied GL_COMPATIBLE_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_DOUBLE_MAT2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT2x3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT2x4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3x2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3x4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4x2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4x3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DRAW_INDIRECT_BUFFER From: ARB_draw_indirect*/
/*Copied GL_DRAW_INDIRECT_BUFFER_BINDING From: ARB_draw_indirect*/
/*Copied GL_FRACTIONAL_EVEN From: ARB_tessellation_shader*/
/*Copied GL_FRACTIONAL_ODD From: ARB_tessellation_shader*/
/*Copied GL_FRAGMENT_INTERPOLATION_OFFSET_BITS From: ARB_gpu_shader5*/
/*Copied GL_GEOMETRY_SHADER_INVOCATIONS From: ARB_pipeline_statistics_query*/
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
/*Copied GL_ISOLINES From: ARB_tessellation_shader*/
/*Copied GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_FRAGMENT_INTERPOLATION_OFFSET From: ARB_gpu_shader5*/
/*Copied GL_MAX_GEOMETRY_SHADER_INVOCATIONS From: ARB_gpu_shader5*/
/*Copied GL_MAX_PATCH_VERTICES From: ARB_tessellation_shader*/
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
/*Copied GL_MAX_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS From: ARB_shader_subroutine*/
/*Copied GL_MAX_TESS_CONTROL_INPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_GEN_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_PATCH_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TRANSFORM_FEEDBACK_BUFFERS From: ARB_transform_feedback3*/
/*Copied GL_MAX_VERTEX_STREAMS From: ARB_transform_feedback3*/
/*Copied GL_MIN_FRAGMENT_INTERPOLATION_OFFSET From: ARB_gpu_shader5*/
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
/*Copied GL_NUM_COMPATIBLE_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_PATCHES From: NV_gpu_shader5*/
/*Copied GL_PATCH_DEFAULT_INNER_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_PATCH_DEFAULT_OUTER_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_PATCH_VERTICES From: ARB_tessellation_shader*/
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_SAMPLE_SHADING 0x8C36
/*Copied GL_TESS_CONTROL_OUTPUT_VERTICES From: ARB_tessellation_shader*/
/*Copied GL_TESS_CONTROL_SHADER From: ARB_tessellation_shader*/
/*Copied GL_TESS_EVALUATION_SHADER From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_MODE From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_POINT_MODE From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_SPACING From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_VERTEX_ORDER From: ARB_tessellation_shader*/
/*Copied GL_TEXTURE_BINDING_CUBE_MAP_ARRAY From: ARB_direct_state_access*/
/*Copied GL_TEXTURE_CUBE_MAP_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TRANSFORM_FEEDBACK From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BINDING From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED From: ARB_transform_feedback2*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_tessellation_shader*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_tessellation_shader*/
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

/*Copied GL_ACTIVE_PROGRAM From: ARB_separate_shader_objects*/
/*Copied GL_ALL_SHADER_BITS From: ARB_separate_shader_objects*/
/*Copied GL_FIXED From: ARB_ES2_compatibility*/
/*Copied GL_FRAGMENT_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_GEOMETRY_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_HIGH_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_HIGH_INT From: ARB_ES2_compatibility*/
/*Copied GL_IMPLEMENTATION_COLOR_READ_FORMAT From: ARB_ES2_compatibility*/
/*Copied GL_IMPLEMENTATION_COLOR_READ_TYPE From: ARB_ES2_compatibility*/
/*Copied GL_LAYER_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_LOW_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_LOW_INT From: ARB_ES2_compatibility*/
/*Copied GL_MAX_FRAGMENT_UNIFORM_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VARYING_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VERTEX_UNIFORM_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VIEWPORTS From: ARB_viewport_array*/
/*Copied GL_MEDIUM_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_MEDIUM_INT From: ARB_ES2_compatibility*/
/*Copied GL_NUM_PROGRAM_BINARY_FORMATS From: ARB_get_program_binary*/
/*Copied GL_NUM_SHADER_BINARY_FORMATS From: ARB_ES2_compatibility*/
/*Copied GL_PROGRAM_BINARY_FORMATS From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_BINARY_LENGTH From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_BINARY_RETRIEVABLE_HINT From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_PIPELINE_BINDING From: ARB_separate_shader_objects*/
/*Copied GL_PROGRAM_SEPARABLE From: ARB_separate_shader_objects*/
/*Copied GL_RGB565 From: ARB_ES2_compatibility*/
/*Copied GL_SHADER_BINARY_FORMATS From: ARB_ES2_compatibility*/
/*Copied GL_SHADER_COMPILER From: ARB_ES2_compatibility*/
/*Copied GL_TESS_CONTROL_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_TESS_EVALUATION_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_UNDEFINED_VERTEX From: ARB_viewport_array*/
/*Copied GL_VERTEX_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_VIEWPORT_BOUNDS_RANGE From: ARB_viewport_array*/
/*Copied GL_VIEWPORT_INDEX_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_VIEWPORT_SUBPIXEL_BITS From: ARB_viewport_array*/

/*Copied GL_ACTIVE_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_ALL_BARRIER_BITS From: ARB_shader_image_load_store*/
/*Copied GL_ATOMIC_COUNTER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_ATOMIC_COUNTER_BUFFER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_BINDING From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_START From: ARB_shader_atomic_counters*/
/*Copied GL_BUFFER_UPDATE_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_COMMAND_BARRIER_BIT From: ARB_shader_image_load_store*/
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
/*Copied GL_ELEMENT_ARRAY_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_FRAMEBUFFER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_ACCESS From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_FORMAT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LAYER From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LAYERED From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LEVEL From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_NAME From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_TYPE From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_FRAGMENT_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_FRAGMENT_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_GEOMETRY_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_GEOMETRY_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_IMAGE_SAMPLES From: ARB_shader_image_load_store*/
/*Copied GL_MAX_IMAGE_UNITS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_VERTEX_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_VERTEX_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MIN_MAP_BUFFER_ALIGNMENT From: ARB_map_buffer_alignment*/
/*Copied GL_NUM_SAMPLE_COUNTS From: ARB_internalformat_query2*/
/*Copied GL_PACK_COMPRESSED_BLOCK_DEPTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_HEIGHT From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_SIZE From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_WIDTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PIXEL_BUFFER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_SHADER_IMAGE_ACCESS_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_TEXTURE_FETCH_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_TEXTURE_IMMUTABLE_FORMAT From: ARB_texture_storage*/
/*Copied GL_TEXTURE_UPDATE_BARRIER_BIT From: ARB_shader_image_load_store*/
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
/*Copied GL_TRANSFORM_FEEDBACK_BARRIER_BIT From: ARB_shader_image_load_store*/
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
/*Copied GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX From: ARB_shader_atomic_counters*/
/*Copied GL_UNIFORM_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_DEPTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_HEIGHT From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_SIZE From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_WIDTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNSIGNED_INT_ATOMIC_COUNTER From: ARB_shader_atomic_counters*/
/*Copied GL_UNSIGNED_INT_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT From: ARB_shader_image_load_store*/

/*Copied GL_ACTIVE_RESOURCES From: ARB_program_interface_query*/
/*Copied GL_ACTIVE_VARIABLES From: ARB_program_interface_query*/
/*Copied GL_ANY_SAMPLES_PASSED_CONSERVATIVE From: ARB_ES3_compatibility*/
/*Copied GL_ARRAY_SIZE From: ARB_program_interface_query*/
/*Copied GL_ARRAY_STRIDE From: ARB_program_interface_query*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_INDEX From: ARB_program_interface_query*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER From: ARB_compute_shader*/
/*Copied GL_AUTO_GENERATE_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_BLOCK_INDEX From: ARB_program_interface_query*/
/*Copied GL_BUFFER From: KHR_debug*/
/*Copied GL_BUFFER_BINDING From: ARB_program_interface_query*/
/*Copied GL_BUFFER_DATA_SIZE From: ARB_program_interface_query*/
/*Copied GL_BUFFER_VARIABLE From: ARB_program_interface_query*/
/*Copied GL_CAVEAT_SUPPORT From: ARB_internalformat_query2*/
/*Copied GL_CLEAR_BUFFER From: ARB_internalformat_query2*/
/*Copied GL_COLOR_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_COLOR_ENCODING From: ARB_internalformat_query2*/
/*Copied GL_COLOR_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_COMPRESSED_R11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RG11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGB8_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGBA8_ETC2_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SIGNED_R11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SIGNED_RG11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPUTE_SHADER From: ARB_compute_shader*/
/*Copied GL_COMPUTE_SHADER_BIT From: ARB_compute_shader*/
/*Copied GL_COMPUTE_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_COMPUTE_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_COMPUTE_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_COMPUTE_WORK_GROUP_SIZE From: ARB_compute_shader*/
/*Copied GL_CONTEXT_FLAG_DEBUG_BIT From: KHR_debug*/
/*Copied GL_DEBUG_CALLBACK_FUNCTION From: KHR_debug*/
/*Copied GL_DEBUG_CALLBACK_USER_PARAM From: KHR_debug*/
/*Copied GL_DEBUG_GROUP_STACK_DEPTH From: KHR_debug*/
/*Copied GL_DEBUG_LOGGED_MESSAGES From: KHR_debug*/
/*Copied GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH From: KHR_debug*/
/*Copied GL_DEBUG_OUTPUT From: KHR_debug*/
/*Copied GL_DEBUG_OUTPUT_SYNCHRONOUS From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_HIGH From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_LOW From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_MEDIUM From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_NOTIFICATION From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_API From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_APPLICATION From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_OTHER From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_SHADER_COMPILER From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_THIRD_PARTY From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_WINDOW_SYSTEM From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_ERROR From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_MARKER From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_OTHER From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PERFORMANCE From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_POP_GROUP From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PORTABILITY From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PUSH_GROUP From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR From: KHR_debug*/
/*Copied GL_DEPTH_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_DEPTH_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_DEPTH_STENCIL_TEXTURE_MODE From: ARB_stencil_texturing*/
/*Copied GL_DISPATCH_INDIRECT_BUFFER From: ARB_compute_shader*/
/*Copied GL_DISPATCH_INDIRECT_BUFFER_BINDING From: ARB_compute_shader*/
/*Copied GL_FILTER From: ARB_internalformat_query2*/
/*Copied GL_FRAGMENT_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_FRAGMENT_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_FRAGMENT_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_BLEND From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_HEIGHT From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_LAYERS From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_SAMPLES From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_WIDTH From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_RENDERABLE_LAYERED From: ARB_internalformat_query2*/
/*Copied GL_FULL_SUPPORT From: ARB_internalformat_query2*/
/*Copied GL_GEOMETRY_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_GEOMETRY_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_GEOMETRY_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_GET_TEXTURE_IMAGE_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_GET_TEXTURE_IMAGE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_10_10_10_2 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_11_11_10 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_COMPATIBILITY_CLASS From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_PIXEL_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_PIXEL_TYPE From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_TEXEL_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_ALPHA_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_ALPHA_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_BLUE_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_BLUE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_DEPTH_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_DEPTH_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_GREEN_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_GREEN_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_PREFERRED From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_RED_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_RED_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_SHARED_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_STENCIL_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_STENCIL_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_SUPPORTED From: ARB_internalformat_query2*/
/*Copied GL_IS_PER_PATCH From: ARB_program_interface_query*/
/*Copied GL_IS_ROW_MAJOR From: ARB_program_interface_query*/
/*Copied GL_LOCATION From: ARB_program_interface_query*/
/*Copied GL_LOCATION_INDEX From: ARB_program_interface_query*/
/*Copied GL_MANUAL_GENERATE_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_MATRIX_STRIDE From: ARB_program_interface_query*/
/*Copied GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS From: ARB_compute_shader*/
/*Copied GL_MAX_COMBINED_DIMENSIONS From: ARB_internalformat_query2*/
/*Copied GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMPUTE_ATOMIC_COUNTERS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_IMAGE_UNIFORMS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMPUTE_SHARED_MEMORY_SIZE From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_UNIFORM_BLOCKS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_UNIFORM_COMPONENTS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_WORK_GROUP_COUNT From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_WORK_GROUP_SIZE From: ARB_compute_shader*/
/*Copied GL_MAX_DEBUG_GROUP_STACK_DEPTH From: KHR_debug*/
/*Copied GL_MAX_DEBUG_LOGGED_MESSAGES From: KHR_debug*/
/*Copied GL_MAX_DEBUG_MESSAGE_LENGTH From: KHR_debug*/
/*Copied GL_MAX_DEPTH From: ARB_internalformat_query2*/
/*Copied GL_MAX_ELEMENT_INDEX From: ARB_ES3_compatibility*/
/*Copied GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_FRAMEBUFFER_HEIGHT From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_LAYERS From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_SAMPLES From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_WIDTH From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_HEIGHT From: ARB_internalformat_query2*/
/*Copied GL_MAX_LABEL_LENGTH From: KHR_debug*/
/*Copied GL_MAX_LAYERS From: ARB_internalformat_query2*/
/*Copied GL_MAX_NAME_LENGTH From: ARB_program_interface_query*/
/*Copied GL_MAX_NUM_ACTIVE_VARIABLES From: ARB_program_interface_query*/
/*Copied GL_MAX_NUM_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
/*Copied GL_MAX_SHADER_STORAGE_BLOCK_SIZE From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_UNIFORM_LOCATIONS From: ARB_explicit_uniform_location*/
/*Copied GL_MAX_VERTEX_ATTRIB_BINDINGS From: ARB_vertex_attrib_binding*/
/*Copied GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET From: ARB_vertex_attrib_binding*/
/*Copied GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_WIDTH From: ARB_internalformat_query2*/
/*Copied GL_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_NAME_LENGTH From: ARB_program_interface_query*/
/*Copied GL_NUM_ACTIVE_VARIABLES From: ARB_program_interface_query*/
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
/*Copied GL_OFFSET From: ARB_program_interface_query*/
/*Copied GL_PRIMITIVE_RESTART_FIXED_INDEX From: ARB_ES3_compatibility*/
/*Copied GL_PROGRAM From: KHR_debug*/
/*Copied GL_PROGRAM_INPUT From: ARB_program_interface_query*/
/*Copied GL_PROGRAM_OUTPUT From: ARB_program_interface_query*/
/*Copied GL_PROGRAM_PIPELINE From: KHR_debug*/
/*Copied GL_QUERY From: KHR_debug*/
/*Copied GL_READ_PIXELS From: ARB_internalformat_query2*/
/*Copied GL_READ_PIXELS_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_READ_PIXELS_TYPE From: ARB_internalformat_query2*/
/*Copied GL_REFERENCED_BY_COMPUTE_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_FRAGMENT_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_GEOMETRY_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_VERTEX_SHADER From: ARB_program_interface_query*/
/*Copied GL_SAMPLER From: KHR_debug*/
/*Copied GL_SHADER From: KHR_debug*/
/*Copied GL_SHADER_IMAGE_ATOMIC From: ARB_internalformat_query2*/
/*Copied GL_SHADER_IMAGE_LOAD From: ARB_internalformat_query2*/
/*Copied GL_SHADER_IMAGE_STORE From: ARB_internalformat_query2*/
/*Copied GL_SHADER_STORAGE_BARRIER_BIT From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BLOCK From: ARB_program_interface_query*/
/*Copied GL_SHADER_STORAGE_BUFFER From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_BINDING From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_SIZE From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_START From: ARB_shader_storage_buffer_object*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE From: ARB_internalformat_query2*/
/*Copied GL_SRGB_READ From: ARB_internalformat_query2*/
/*Copied GL_SRGB_WRITE From: ARB_internalformat_query2*/
/*Copied GL_STENCIL_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_STENCIL_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_TESS_CONTROL_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_TESS_CONTROL_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_TESS_CONTROL_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_TESS_EVALUATION_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_TESS_EVALUATION_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_TESS_EVALUATION_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_BUFFER_OFFSET From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_BUFFER_SIZE From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_SIZE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_WIDTH From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_GATHER From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_GATHER_SHADOW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMAGE_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMAGE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMMUTABLE_LEVELS From: ARB_texture_view*/
/*Copied GL_TEXTURE_SHADOW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_VIEW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_VIEW_MIN_LAYER From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_MIN_LEVEL From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_NUM_LAYERS From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_NUM_LEVELS From: ARB_texture_view*/
/*Copied GL_TOP_LEVEL_ARRAY_SIZE From: ARB_program_interface_query*/
/*Copied GL_TOP_LEVEL_ARRAY_STRIDE From: ARB_program_interface_query*/
/*Copied GL_TRANSFORM_FEEDBACK_VARYING From: ARB_program_interface_query*/
/*Copied GL_TYPE From: ARB_program_interface_query*/
/*Copied GL_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_UNIFORM_BLOCK From: ARB_program_interface_query*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER From: ARB_compute_shader*/
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
/*Copied GL_VERTEX_ATTRIB_BINDING From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_ATTRIB_RELATIVE_OFFSET From: ARB_vertex_attrib_binding*/
#define GL_VERTEX_BINDING_BUFFER 0x8F4F
/*Copied GL_VERTEX_BINDING_DIVISOR From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_BINDING_OFFSET From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_BINDING_STRIDE From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_VERTEX_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_VERTEX_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_128_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_16_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_24_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_32_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_48_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_64_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_8_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_96_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_BPTC_FLOAT From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_BPTC_UNORM From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_RGTC1_RED From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_RGTC2_RG From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT1_RGB From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT1_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT3_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT5_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_COMPATIBILITY_CLASS From: ARB_internalformat_query2*/

/*Copied GL_BUFFER_IMMUTABLE_STORAGE From: ARB_buffer_storage*/
/*Copied GL_BUFFER_STORAGE_FLAGS From: ARB_buffer_storage*/
/*Copied GL_CLEAR_TEXTURE From: ARB_clear_texture*/
/*Copied GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT From: ARB_buffer_storage*/
/*Copied GL_CLIENT_STORAGE_BIT From: ARB_buffer_storage*/
/*Copied GL_DYNAMIC_STORAGE_BIT From: ARB_buffer_storage*/
/*Copied GL_LOCATION_COMPONENT From: ARB_enhanced_layouts*/
/*Copied GL_MAP_COHERENT_BIT From: ARB_buffer_storage*/
/*Copied GL_MAP_PERSISTENT_BIT From: ARB_buffer_storage*/
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
/*Copied GL_MIRROR_CLAMP_TO_EDGE From: ARB_texture_mirror_clamp_to_edge*/
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
/*Copied GL_QUERY_BUFFER From: ARB_query_buffer_object*/
/*Copied GL_QUERY_BUFFER_BARRIER_BIT From: ARB_query_buffer_object*/
/*Copied GL_QUERY_BUFFER_BINDING From: ARB_query_buffer_object*/
/*Copied GL_QUERY_RESULT_NO_WAIT From: ARB_query_buffer_object*/
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_INDEX From: ARB_enhanced_layouts*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE From: ARB_enhanced_layouts*/

/*Copied GL_CLIP_DEPTH_MODE From: ARB_clip_control*/
/*Copied GL_CLIP_ORIGIN From: ARB_clip_control*/
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
/*Copied GL_CONTEXT_LOST From: KHR_robustness*/
/*Copied GL_CONTEXT_RELEASE_BEHAVIOR From: KHR_context_flush_control*/
/*Copied GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH From: KHR_context_flush_control*/
/*Copied GL_GUILTY_CONTEXT_RESET From: KHR_robustness*/
/*Copied GL_INNOCENT_CONTEXT_RESET From: KHR_robustness*/
/*Copied GL_LOSE_CONTEXT_ON_RESET From: KHR_robustness*/
/*Copied GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES From: ARB_cull_distance*/
/*Copied GL_MAX_CULL_DISTANCES From: ARB_cull_distance*/
/*Copied GL_NEGATIVE_ONE_TO_ONE From: ARB_clip_control*/
/*Copied GL_NO_RESET_NOTIFICATION From: KHR_robustness*/
/*Copied GL_QUERY_BY_REGION_NO_WAIT_INVERTED From: ARB_conditional_render_inverted*/
/*Copied GL_QUERY_BY_REGION_WAIT_INVERTED From: ARB_conditional_render_inverted*/
/*Copied GL_QUERY_NO_WAIT_INVERTED From: ARB_conditional_render_inverted*/
/*Copied GL_QUERY_TARGET From: ARB_direct_state_access*/
/*Copied GL_QUERY_WAIT_INVERTED From: ARB_conditional_render_inverted*/
/*Copied GL_RESET_NOTIFICATION_STRATEGY From: KHR_robustness*/
/*Copied GL_TEXTURE_TARGET From: ARB_direct_state_access*/
/*Copied GL_UNKNOWN_CONTEXT_RESET From: KHR_robustness*/
/*Copied GL_ZERO_TO_ONE From: ARB_clip_control*/

#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectAMD)(GLenum mode, const void * indirect, GLsizei primcount, GLsizei stride);
#define glMultiDrawArraysIndirectAMD _ptrc_glMultiDrawArraysIndirectAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectAMD)(GLenum mode, GLenum type, const void * indirect, GLsizei primcount, GLsizei stride);
#define glMultiDrawElementsIndirectAMD _ptrc_glMultiDrawElementsIndirectAMD
#endif /*GL_AMD_multi_draw_indirect*/ 


#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
#define glDrawArraysInstancedBaseInstance _ptrc_glDrawArraysInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance _ptrc_glDrawElementsInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance _ptrc_glDrawElementsInstancedBaseVertexBaseInstance
#endif /*GL_ARB_base_instance*/ 

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed _ptrc_glBindFragDataLocationIndexed
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint program, const GLchar * name);
#define glGetFragDataIndex _ptrc_glGetFragDataIndex
#endif /*GL_ARB_blend_func_extended*/ 

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#define glBufferStorage _ptrc_glBufferStorage
#endif /*GL_ARB_buffer_storage*/ 

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glCreateSyncFromCLeventARB)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
#define glCreateSyncFromCLeventARB _ptrc_glCreateSyncFromCLeventARB
#endif /*GL_ARB_cl_event*/ 

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearBufferData _ptrc_glClearBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData _ptrc_glClearBufferSubData
#endif /*GL_ARB_clear_buffer_object*/ 

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage _ptrc_glClearTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage _ptrc_glClearTexSubImage
#endif /*GL_ARB_clear_texture*/ 

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClipControl)(GLenum origin, GLenum depth);
#define glClipControl _ptrc_glClipControl
#endif /*GL_ARB_clip_control*/ 

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClampColorARB)(GLenum target, GLenum clamp);
#define glClampColorARB _ptrc_glClampColorARB
#endif /*GL_ARB_color_buffer_float*/ 




#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute _ptrc_glDispatchCompute
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr indirect);
#define glDispatchComputeIndirect _ptrc_glDispatchComputeIndirect
#endif /*GL_ARB_compute_shader*/ 

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeGroupSizeARB)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#define glDispatchComputeGroupSizeARB _ptrc_glDispatchComputeGroupSizeARB
#endif /*GL_ARB_compute_variable_group_size*/ 


#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData _ptrc_glCopyBufferSubData
#endif /*GL_ARB_copy_buffer*/ 

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData _ptrc_glCopyImageSubData
#endif /*GL_ARB_copy_image*/ 


#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const void * userParam);
#define glDebugMessageCallbackARB _ptrc_glDebugMessageCallbackARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControlARB _ptrc_glDebugMessageControlARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsertARB _ptrc_glDebugMessageInsertARB
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogARB)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLogARB _ptrc_glGetDebugMessageLogARB
#endif /*GL_ARB_debug_output*/ 





#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextureUnit)(GLuint unit, GLuint texture);
#define glBindTextureUnit _ptrc_glBindTextureUnit
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer _ptrc_glBlitNamedFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus _ptrc_glCheckNamedFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData _ptrc_glClearNamedBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData _ptrc_glClearNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi _ptrc_glClearNamedFramebufferfi
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv _ptrc_glClearNamedFramebufferfv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv _ptrc_glClearNamedFramebufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv _ptrc_glClearNamedFramebufferuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D _ptrc_glCompressedTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D _ptrc_glCompressedTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D _ptrc_glCompressedTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData _ptrc_glCopyNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D _ptrc_glCopyTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D _ptrc_glCopyTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D _ptrc_glCopyTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateBuffers)(GLsizei n, GLuint * buffers);
#define glCreateBuffers _ptrc_glCreateBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateFramebuffers)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers _ptrc_glCreateFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateProgramPipelines)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines _ptrc_glCreateProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateQueries)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries _ptrc_glCreateQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateRenderbuffers)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers _ptrc_glCreateRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateSamplers)(GLsizei n, GLuint * samplers);
#define glCreateSamplers _ptrc_glCreateSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateTextures)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures _ptrc_glCreateTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateTransformFeedbacks)(GLsizei n, GLuint * ids);
#define glCreateTransformFeedbacks _ptrc_glCreateTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateVertexArrays)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays _ptrc_glCreateVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib _ptrc_glDisableVertexArrayAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib _ptrc_glEnableVertexArrayAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange _ptrc_glFlushMappedNamedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmap)(GLuint texture);
#define glGenerateTextureMipmap _ptrc_glGenerateTextureMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage _ptrc_glGetCompressedTextureImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v _ptrc_glGetNamedBufferParameteri64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv _ptrc_glGetNamedBufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv _ptrc_glGetNamedBufferPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData _ptrc_glGetNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv _ptrc_glGetNamedFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv _ptrc_glGetNamedFramebufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv _ptrc_glGetNamedRenderbufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v _ptrc_glGetQueryBufferObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv _ptrc_glGetQueryBufferObjectiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v _ptrc_glGetQueryBufferObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv _ptrc_glGetQueryBufferObjectuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage _ptrc_glGetTextureImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv _ptrc_glGetTextureLevelParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv _ptrc_glGetTextureLevelParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv _ptrc_glGetTextureParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv _ptrc_glGetTextureParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv _ptrc_glGetTextureParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv _ptrc_glGetTextureParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v _ptrc_glGetTransformFeedbacki64_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v _ptrc_glGetTransformFeedbacki_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv _ptrc_glGetTransformFeedbackiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv _ptrc_glGetVertexArrayIndexed64iv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv _ptrc_glGetVertexArrayIndexediv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv _ptrc_glGetVertexArrayiv
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData _ptrc_glInvalidateNamedFramebufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData _ptrc_glInvalidateNamedFramebufferSubData
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBuffer)(GLuint buffer, GLenum access);
#define glMapNamedBuffer _ptrc_glMapNamedBuffer
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange _ptrc_glMapNamedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData _ptrc_glNamedBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage _ptrc_glNamedBufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData _ptrc_glNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer _ptrc_glNamedFramebufferDrawBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers _ptrc_glNamedFramebufferDrawBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri _ptrc_glNamedFramebufferParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer _ptrc_glNamedFramebufferReadBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer _ptrc_glNamedFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture _ptrc_glNamedFramebufferTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer _ptrc_glNamedFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage _ptrc_glNamedRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample _ptrc_glNamedRenderbufferStorageMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer _ptrc_glTextureBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange _ptrc_glTextureBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv _ptrc_glTextureParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv _ptrc_glTextureParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf _ptrc_glTextureParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv _ptrc_glTextureParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri _ptrc_glTextureParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv _ptrc_glTextureParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D _ptrc_glTextureStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D _ptrc_glTextureStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample _ptrc_glTextureStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D _ptrc_glTextureStorage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample _ptrc_glTextureStorage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D _ptrc_glTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D _ptrc_glTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D _ptrc_glTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase _ptrc_glTransformFeedbackBufferBase
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange _ptrc_glTransformFeedbackBufferRange
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBuffer)(GLuint buffer);
#define glUnmapNamedBuffer _ptrc_glUnmapNamedBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding _ptrc_glVertexArrayAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat _ptrc_glVertexArrayAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat _ptrc_glVertexArrayAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat _ptrc_glVertexArrayAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor _ptrc_glVertexArrayBindingDivisor
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer _ptrc_glVertexArrayElementBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer _ptrc_glVertexArrayVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers _ptrc_glVertexArrayVertexBuffers
#endif /*GL_ARB_direct_state_access*/ 

#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersARB)(GLsizei n, const GLenum * bufs);
#define glDrawBuffersARB _ptrc_glDrawBuffersARB
#endif /*GL_ARB_draw_buffers*/ 

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparateiARB _ptrc_glBlendEquationSeparateiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationiARB)(GLuint buf, GLenum mode);
#define glBlendEquationiARB _ptrc_glBlendEquationiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparateiARB _ptrc_glBlendFuncSeparateiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunciARB _ptrc_glBlendFunciARB
#endif /*GL_ARB_draw_buffers_blend*/ 

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect _ptrc_glDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect _ptrc_glDrawElementsIndirect
#endif /*GL_ARB_draw_indirect*/ 

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawElementsBaseVertex _ptrc_glDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex _ptrc_glDrawElementsInstancedBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex _ptrc_glDrawRangeElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex _ptrc_glMultiDrawElementsBaseVertex
#endif /*GL_ARB_draw_elements_base_vertex*/ 

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedARB)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
#define glDrawArraysInstancedARB _ptrc_glDrawArraysInstancedARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedARB)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#define glDrawElementsInstancedARB _ptrc_glDrawElementsInstancedARB
#endif /*GL_ARB_draw_instanced*/ 


#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat d);
#define glClearDepthf _ptrc_glClearDepthf
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat n, GLfloat f);
#define glDepthRangef _ptrc_glDepthRangef
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat _ptrc_glGetShaderPrecisionFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)(void);
#define glReleaseShaderCompiler _ptrc_glReleaseShaderCompiler
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
#define glShaderBinary _ptrc_glShaderBinary
#endif /*GL_ARB_ES2_compatibility*/ 


#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierByRegion)(GLbitfield barriers);
#define glMemoryBarrierByRegion _ptrc_glMemoryBarrierByRegion
#endif /*GL_ARB_ES3_1_compatibility*/ 

#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveBoundingBoxARB)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#define glPrimitiveBoundingBoxARB _ptrc_glPrimitiveBoundingBoxARB
#endif /*GL_ARB_ES3_2_compatibility*/ 





#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum target, GLuint program);
#define glBindProgramARB _ptrc_glBindProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei n, const GLuint * programs);
#define glDeleteProgramsARB _ptrc_glDeleteProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei n, GLuint * programs);
#define glGenProgramsARB _ptrc_glGenProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum target, GLuint index, GLdouble * params);
#define glGetProgramEnvParameterdvARB _ptrc_glGetProgramEnvParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum target, GLuint index, GLfloat * params);
#define glGetProgramEnvParameterfvARB _ptrc_glGetProgramEnvParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum target, GLuint index, GLdouble * params);
#define glGetProgramLocalParameterdvARB _ptrc_glGetProgramLocalParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum target, GLuint index, GLfloat * params);
#define glGetProgramLocalParameterfvARB _ptrc_glGetProgramLocalParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum target, GLenum pname, void * string);
#define glGetProgramStringARB _ptrc_glGetProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum target, GLenum pname, GLint * params);
#define glGetProgramivARB _ptrc_glGetProgramivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint program);
#define glIsProgramARB _ptrc_glIsProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramEnvParameter4dARB _ptrc_glProgramEnvParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params);
#define glProgramEnvParameter4dvARB _ptrc_glProgramEnvParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramEnvParameter4fARB _ptrc_glProgramEnvParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params);
#define glProgramEnvParameter4fvARB _ptrc_glProgramEnvParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramLocalParameter4dARB _ptrc_glProgramLocalParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params);
#define glProgramLocalParameter4dvARB _ptrc_glProgramLocalParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramLocalParameter4fARB _ptrc_glProgramLocalParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params);
#define glProgramLocalParameter4fvARB _ptrc_glProgramLocalParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum target, GLenum format, GLsizei len, const void * string);
#define glProgramStringARB _ptrc_glProgramStringARB
#endif /*GL_ARB_fragment_program*/ 



#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri _ptrc_glFramebufferParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv _ptrc_glGetFramebufferParameteriv
#endif /*GL_ARB_framebuffer_no_attachments*/ 

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer _ptrc_glBindFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer _ptrc_glBindRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer _ptrc_glBlitFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum target);
#define glCheckFramebufferStatus _ptrc_glCheckFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers _ptrc_glDeleteFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers _ptrc_glDeleteRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer _ptrc_glFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D _ptrc_glFramebufferTexture1D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D _ptrc_glFramebufferTexture2D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D _ptrc_glFramebufferTexture3D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer _ptrc_glFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers _ptrc_glGenFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers _ptrc_glGenRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum target);
#define glGenerateMipmap _ptrc_glGenerateMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv _ptrc_glGetFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv _ptrc_glGetRenderbufferParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint framebuffer);
#define glIsFramebuffer _ptrc_glIsFramebuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint renderbuffer);
#define glIsRenderbuffer _ptrc_glIsRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage _ptrc_glRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample _ptrc_glRenderbufferStorageMultisample
#endif /*GL_ARB_framebuffer_object*/ 


#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureARB)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTextureARB _ptrc_glFramebufferTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#define glFramebufferTextureFaceARB _ptrc_glFramebufferTextureFaceARB
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayerARB _ptrc_glFramebufferTextureLayerARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriARB)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteriARB _ptrc_glProgramParameteriARB
#endif /*GL_ARB_geometry_shader4*/ 

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary _ptrc_glGetProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary _ptrc_glProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri _ptrc_glProgramParameteri
#endif /*GL_ARB_get_program_binary*/ 

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage _ptrc_glGetCompressedTextureSubImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage _ptrc_glGetTextureSubImage
#endif /*GL_ARB_get_texture_sub_image*/ 


#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv _ptrc_glGetUniformdv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint location, GLdouble x);
#define glUniform1d _ptrc_glUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv _ptrc_glUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d _ptrc_glUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv _ptrc_glUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d _ptrc_glUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv _ptrc_glUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d _ptrc_glUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv _ptrc_glUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv _ptrc_glUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv _ptrc_glUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv _ptrc_glUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv _ptrc_glUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv _ptrc_glUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv _ptrc_glUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv _ptrc_glUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv _ptrc_glUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv _ptrc_glUniformMatrix4x3dv
#endif /*GL_ARB_gpu_shader_fp64*/ 

#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vARB)(GLuint program, GLint location, GLint64 * params);
#define glGetUniformi64vARB _ptrc_glGetUniformi64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vARB)(GLuint program, GLint location, GLuint64 * params);
#define glGetUniformui64vARB _ptrc_glGetUniformui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformi64vARB)(GLuint program, GLint location, GLsizei bufSize, GLint64 * params);
#define glGetnUniformi64vARB _ptrc_glGetnUniformi64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformui64vARB)(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params);
#define glGetnUniformui64vARB _ptrc_glGetnUniformui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64ARB)(GLuint program, GLint location, GLint64 x);
#define glProgramUniform1i64ARB _ptrc_glProgramUniform1i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform1i64vARB _ptrc_glProgramUniform1i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64ARB)(GLuint program, GLint location, GLuint64 x);
#define glProgramUniform1ui64ARB _ptrc_glProgramUniform1ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform1ui64vARB _ptrc_glProgramUniform1ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y);
#define glProgramUniform2i64ARB _ptrc_glProgramUniform2i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform2i64vARB _ptrc_glProgramUniform2i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
#define glProgramUniform2ui64ARB _ptrc_glProgramUniform2ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform2ui64vARB _ptrc_glProgramUniform2ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
#define glProgramUniform3i64ARB _ptrc_glProgramUniform3i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform3i64vARB _ptrc_glProgramUniform3i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
#define glProgramUniform3ui64ARB _ptrc_glProgramUniform3ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform3ui64vARB _ptrc_glProgramUniform3ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64ARB)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
#define glProgramUniform4i64ARB _ptrc_glProgramUniform4i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vARB)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform4i64vARB _ptrc_glProgramUniform4i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64ARB)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
#define glProgramUniform4ui64ARB _ptrc_glProgramUniform4ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vARB)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform4ui64vARB _ptrc_glProgramUniform4ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64ARB)(GLint location, GLint64 x);
#define glUniform1i64ARB _ptrc_glUniform1i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vARB)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform1i64vARB _ptrc_glUniform1i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64ARB)(GLint location, GLuint64 x);
#define glUniform1ui64ARB _ptrc_glUniform1ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vARB)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform1ui64vARB _ptrc_glUniform1ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64ARB)(GLint location, GLint64 x, GLint64 y);
#define glUniform2i64ARB _ptrc_glUniform2i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vARB)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform2i64vARB _ptrc_glUniform2i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64ARB)(GLint location, GLuint64 x, GLuint64 y);
#define glUniform2ui64ARB _ptrc_glUniform2ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vARB)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform2ui64vARB _ptrc_glUniform2ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z);
#define glUniform3i64ARB _ptrc_glUniform3i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vARB)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform3i64vARB _ptrc_glUniform3i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
#define glUniform3ui64ARB _ptrc_glUniform3ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vARB)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform3ui64vARB _ptrc_glUniform3ui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64ARB)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
#define glUniform4i64ARB _ptrc_glUniform4i64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vARB)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform4i64vARB _ptrc_glUniform4i64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64ARB)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
#define glUniform4ui64ARB _ptrc_glUniform4ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vARB)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform4ui64vARB _ptrc_glUniform4ui64vARB
#endif /*GL_ARB_gpu_shader_int64*/ 



#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor _ptrc_glBlendColor
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquation)(GLenum mode);
#define glBlendEquation _ptrc_glBlendEquation
extern void (CODEGEN_FUNCPTR *_ptrc_glColorSubTable)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
#define glColorSubTable _ptrc_glColorSubTable
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTable)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table);
#define glColorTable _ptrc_glColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfv)(GLenum target, GLenum pname, const GLfloat * params);
#define glColorTableParameterfv _ptrc_glColorTableParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameteriv)(GLenum target, GLenum pname, const GLint * params);
#define glColorTableParameteriv _ptrc_glColorTableParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1D)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
#define glConvolutionFilter1D _ptrc_glConvolutionFilter1D
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
#define glConvolutionFilter2D _ptrc_glConvolutionFilter2D
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterf)(GLenum target, GLenum pname, GLfloat params);
#define glConvolutionParameterf _ptrc_glConvolutionParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfv)(GLenum target, GLenum pname, const GLfloat * params);
#define glConvolutionParameterfv _ptrc_glConvolutionParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteri)(GLenum target, GLenum pname, GLint params);
#define glConvolutionParameteri _ptrc_glConvolutionParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriv)(GLenum target, GLenum pname, const GLint * params);
#define glConvolutionParameteriv _ptrc_glConvolutionParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTable)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
#define glCopyColorSubTable _ptrc_glCopyColorSubTable
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTable)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyColorTable _ptrc_glCopyColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyConvolutionFilter1D _ptrc_glCopyConvolutionFilter1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyConvolutionFilter2D _ptrc_glCopyConvolutionFilter2D
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTable)(GLenum target, GLenum format, GLenum type, void * table);
#define glGetColorTable _ptrc_glGetColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfv)(GLenum target, GLenum pname, GLfloat * params);
#define glGetColorTableParameterfv _ptrc_glGetColorTableParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetColorTableParameteriv _ptrc_glGetColorTableParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilter)(GLenum target, GLenum format, GLenum type, void * image);
#define glGetConvolutionFilter _ptrc_glGetConvolutionFilter
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfv)(GLenum target, GLenum pname, GLfloat * params);
#define glGetConvolutionParameterfv _ptrc_glGetConvolutionParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetConvolutionParameteriv _ptrc_glGetConvolutionParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
#define glGetHistogram _ptrc_glGetHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfv)(GLenum target, GLenum pname, GLfloat * params);
#define glGetHistogramParameterfv _ptrc_glGetHistogramParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetHistogramParameteriv _ptrc_glGetHistogramParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
#define glGetMinmax _ptrc_glGetMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfv)(GLenum target, GLenum pname, GLfloat * params);
#define glGetMinmaxParameterfv _ptrc_glGetMinmaxParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetMinmaxParameteriv _ptrc_glGetMinmaxParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilter)(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
#define glGetSeparableFilter _ptrc_glGetSeparableFilter
extern void (CODEGEN_FUNCPTR *_ptrc_glHistogram)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
#define glHistogram _ptrc_glHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glMinmax)(GLenum target, GLenum internalformat, GLboolean sink);
#define glMinmax _ptrc_glMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glResetHistogram)(GLenum target);
#define glResetHistogram _ptrc_glResetHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glResetMinmax)(GLenum target);
#define glResetMinmax _ptrc_glResetMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
#define glSeparableFilter2D _ptrc_glSeparableFilter2D
#endif /*GL_ARB_imaging*/ 

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectCountARB)(GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawArraysIndirectCountARB _ptrc_glMultiDrawArraysIndirectCountARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectCountARB)(GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawElementsIndirectCountARB _ptrc_glMultiDrawElementsIndirectCountARB
#endif /*GL_ARB_indirect_parameters*/ 

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisorARB)(GLuint index, GLuint divisor);
#define glVertexAttribDivisorARB _ptrc_glVertexAttribDivisorARB
#endif /*GL_ARB_instanced_arrays*/ 

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
#define glGetInternalformativ _ptrc_glGetInternalformativ
#endif /*GL_ARB_internalformat_query*/ 

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
#define glGetInternalformati64v _ptrc_glGetInternalformati64v
#endif /*GL_ARB_internalformat_query2*/ 

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint buffer);
#define glInvalidateBufferData _ptrc_glInvalidateBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData _ptrc_glInvalidateBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer _ptrc_glInvalidateFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer _ptrc_glInvalidateSubFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint texture, GLint level);
#define glInvalidateTexImage _ptrc_glInvalidateTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage _ptrc_glInvalidateTexSubImage
#endif /*GL_ARB_invalidate_subdata*/ 


#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange _ptrc_glFlushMappedBufferRange
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange _ptrc_glMapBufferRange
#endif /*GL_ARB_map_buffer_range*/ 

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase _ptrc_glBindBuffersBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange _ptrc_glBindBuffersRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures _ptrc_glBindImageTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers _ptrc_glBindSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures _ptrc_glBindTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers _ptrc_glBindVertexBuffers
#endif /*GL_ARB_multi_bind*/ 

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect _ptrc_glMultiDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect _ptrc_glMultiDrawElementsIndirect
#endif /*GL_ARB_multi_draw_indirect*/ 

#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageARB)(GLfloat value, GLboolean invert);
#define glSampleCoverageARB _ptrc_glSampleCoverageARB
#endif /*GL_ARB_multisample*/ 

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveTextureARB)(GLenum texture);
#define glActiveTextureARB _ptrc_glActiveTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTextureARB)(GLenum texture);
#define glClientActiveTextureARB _ptrc_glClientActiveTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dARB)(GLenum target, GLdouble s);
#define glMultiTexCoord1dARB _ptrc_glMultiTexCoord1dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dvARB)(GLenum target, const GLdouble * v);
#define glMultiTexCoord1dvARB _ptrc_glMultiTexCoord1dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fARB)(GLenum target, GLfloat s);
#define glMultiTexCoord1fARB _ptrc_glMultiTexCoord1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fvARB)(GLenum target, const GLfloat * v);
#define glMultiTexCoord1fvARB _ptrc_glMultiTexCoord1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iARB)(GLenum target, GLint s);
#define glMultiTexCoord1iARB _ptrc_glMultiTexCoord1iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1ivARB)(GLenum target, const GLint * v);
#define glMultiTexCoord1ivARB _ptrc_glMultiTexCoord1ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sARB)(GLenum target, GLshort s);
#define glMultiTexCoord1sARB _ptrc_glMultiTexCoord1sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1svARB)(GLenum target, const GLshort * v);
#define glMultiTexCoord1svARB _ptrc_glMultiTexCoord1svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dARB)(GLenum target, GLdouble s, GLdouble t);
#define glMultiTexCoord2dARB _ptrc_glMultiTexCoord2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dvARB)(GLenum target, const GLdouble * v);
#define glMultiTexCoord2dvARB _ptrc_glMultiTexCoord2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fARB)(GLenum target, GLfloat s, GLfloat t);
#define glMultiTexCoord2fARB _ptrc_glMultiTexCoord2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fvARB)(GLenum target, const GLfloat * v);
#define glMultiTexCoord2fvARB _ptrc_glMultiTexCoord2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iARB)(GLenum target, GLint s, GLint t);
#define glMultiTexCoord2iARB _ptrc_glMultiTexCoord2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2ivARB)(GLenum target, const GLint * v);
#define glMultiTexCoord2ivARB _ptrc_glMultiTexCoord2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sARB)(GLenum target, GLshort s, GLshort t);
#define glMultiTexCoord2sARB _ptrc_glMultiTexCoord2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2svARB)(GLenum target, const GLshort * v);
#define glMultiTexCoord2svARB _ptrc_glMultiTexCoord2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
#define glMultiTexCoord3dARB _ptrc_glMultiTexCoord3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dvARB)(GLenum target, const GLdouble * v);
#define glMultiTexCoord3dvARB _ptrc_glMultiTexCoord3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
#define glMultiTexCoord3fARB _ptrc_glMultiTexCoord3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fvARB)(GLenum target, const GLfloat * v);
#define glMultiTexCoord3fvARB _ptrc_glMultiTexCoord3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iARB)(GLenum target, GLint s, GLint t, GLint r);
#define glMultiTexCoord3iARB _ptrc_glMultiTexCoord3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3ivARB)(GLenum target, const GLint * v);
#define glMultiTexCoord3ivARB _ptrc_glMultiTexCoord3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sARB)(GLenum target, GLshort s, GLshort t, GLshort r);
#define glMultiTexCoord3sARB _ptrc_glMultiTexCoord3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3svARB)(GLenum target, const GLshort * v);
#define glMultiTexCoord3svARB _ptrc_glMultiTexCoord3svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glMultiTexCoord4dARB _ptrc_glMultiTexCoord4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dvARB)(GLenum target, const GLdouble * v);
#define glMultiTexCoord4dvARB _ptrc_glMultiTexCoord4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glMultiTexCoord4fARB _ptrc_glMultiTexCoord4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fvARB)(GLenum target, const GLfloat * v);
#define glMultiTexCoord4fvARB _ptrc_glMultiTexCoord4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iARB)(GLenum target, GLint s, GLint t, GLint r, GLint q);
#define glMultiTexCoord4iARB _ptrc_glMultiTexCoord4iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4ivARB)(GLenum target, const GLint * v);
#define glMultiTexCoord4ivARB _ptrc_glMultiTexCoord4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sARB)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
#define glMultiTexCoord4sARB _ptrc_glMultiTexCoord4sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4svARB)(GLenum target, const GLshort * v);
#define glMultiTexCoord4svARB _ptrc_glMultiTexCoord4svARB
#endif /*GL_ARB_multitexture*/ 

#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryARB)(GLenum target, GLuint id);
#define glBeginQueryARB _ptrc_glBeginQueryARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueriesARB)(GLsizei n, const GLuint * ids);
#define glDeleteQueriesARB _ptrc_glDeleteQueriesARB
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryARB)(GLenum target);
#define glEndQueryARB _ptrc_glEndQueryARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenQueriesARB)(GLsizei n, GLuint * ids);
#define glGenQueriesARB _ptrc_glGenQueriesARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectivARB)(GLuint id, GLenum pname, GLint * params);
#define glGetQueryObjectivARB _ptrc_glGetQueryObjectivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuivARB)(GLuint id, GLenum pname, GLuint * params);
#define glGetQueryObjectuivARB _ptrc_glGetQueryObjectuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryivARB)(GLenum target, GLenum pname, GLint * params);
#define glGetQueryivARB _ptrc_glGetQueryivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQueryARB)(GLuint id);
#define glIsQueryARB _ptrc_glIsQueryARB
#endif /*GL_ARB_occlusion_query*/ 


#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMaxShaderCompilerThreadsARB)(GLuint count);
#define glMaxShaderCompilerThreadsARB _ptrc_glMaxShaderCompilerThreadsARB
#endif /*GL_ARB_parallel_shader_compile*/ 



#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfARB)(GLenum pname, GLfloat param);
#define glPointParameterfARB _ptrc_glPointParameterfARB
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvARB)(GLenum pname, const GLfloat * params);
#define glPointParameterfvARB _ptrc_glPointParameterfvARB
#endif /*GL_ARB_point_parameters*/ 


#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv _ptrc_glGetProgramInterfaceiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex _ptrc_glGetProgramResourceIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation _ptrc_glGetProgramResourceLocation
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex _ptrc_glGetProgramResourceLocationIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName _ptrc_glGetProgramResourceName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
#define glGetProgramResourceiv _ptrc_glGetProgramResourceiv
#endif /*GL_ARB_program_interface_query*/ 

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum mode);
#define glProvokingVertex _ptrc_glProvokingVertex
#endif /*GL_ARB_provoking_vertex*/ 



#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatusARB)(void);
#define glGetGraphicsResetStatusARB _ptrc_glGetGraphicsResetStatusARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnColorTableARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
#define glGetnColorTableARB _ptrc_glGetnColorTableARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, void * img);
#define glGetnCompressedTexImageARB _ptrc_glGetnCompressedTexImageARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnConvolutionFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
#define glGetnConvolutionFilterARB _ptrc_glGetnConvolutionFilterARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnHistogramARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnHistogramARB _ptrc_glGetnHistogramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapdvARB)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
#define glGetnMapdvARB _ptrc_glGetnMapdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapfvARB)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
#define glGetnMapfvARB _ptrc_glGetnMapfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapivARB)(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
#define glGetnMapivARB _ptrc_glGetnMapivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMinmaxARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnMinmaxARB _ptrc_glGetnMinmaxARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapfvARB)(GLenum map, GLsizei bufSize, GLfloat * values);
#define glGetnPixelMapfvARB _ptrc_glGetnPixelMapfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapuivARB)(GLenum map, GLsizei bufSize, GLuint * values);
#define glGetnPixelMapuivARB _ptrc_glGetnPixelMapuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapusvARB)(GLenum map, GLsizei bufSize, GLushort * values);
#define glGetnPixelMapusvARB _ptrc_glGetnPixelMapusvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPolygonStippleARB)(GLsizei bufSize, GLubyte * pattern);
#define glGetnPolygonStippleARB _ptrc_glGetnPolygonStippleARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnSeparableFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
#define glGetnSeparableFilterARB _ptrc_glGetnSeparableFilterARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img);
#define glGetnTexImageARB _ptrc_glGetnTexImageARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdvARB _ptrc_glGetnUniformdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfvARB _ptrc_glGetnUniformfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformivARB _ptrc_glGetnUniformivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuivARB _ptrc_glGetnUniformuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixelsARB _ptrc_glReadnPixelsARB
#endif /*GL_ARB_robustness*/ 

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShadingARB)(GLfloat value);
#define glMinSampleShadingARB _ptrc_glMinSampleShadingARB
#endif /*GL_ARB_sample_shading*/ 

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint unit, GLuint sampler);
#define glBindSampler _ptrc_glBindSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers _ptrc_glDeleteSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei count, GLuint * samplers);
#define glGenSamplers _ptrc_glGenSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv _ptrc_glGetSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv _ptrc_glGetSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv _ptrc_glGetSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv _ptrc_glGetSamplerParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint sampler);
#define glIsSampler _ptrc_glIsSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv _ptrc_glSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv _ptrc_glSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf _ptrc_glSamplerParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv _ptrc_glSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri _ptrc_glSamplerParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv _ptrc_glSamplerParameteriv
#endif /*GL_ARB_sampler_objects*/ 


#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram _ptrc_glActiveShaderProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint pipeline);
#define glBindProgramPipeline _ptrc_glBindProgramPipeline
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv _ptrc_glCreateShaderProgramv
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines _ptrc_glDeleteProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines _ptrc_glGenProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog _ptrc_glGetProgramPipelineInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv _ptrc_glGetProgramPipelineiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint pipeline);
#define glIsProgramPipeline _ptrc_glIsProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d _ptrc_glProgramUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv _ptrc_glProgramUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f _ptrc_glProgramUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv _ptrc_glProgramUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i _ptrc_glProgramUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv _ptrc_glProgramUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui _ptrc_glProgramUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv _ptrc_glProgramUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d _ptrc_glProgramUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv _ptrc_glProgramUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f _ptrc_glProgramUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv _ptrc_glProgramUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i _ptrc_glProgramUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv _ptrc_glProgramUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui _ptrc_glProgramUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv _ptrc_glProgramUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d _ptrc_glProgramUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv _ptrc_glProgramUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f _ptrc_glProgramUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv _ptrc_glProgramUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i _ptrc_glProgramUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv _ptrc_glProgramUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui _ptrc_glProgramUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv _ptrc_glProgramUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d _ptrc_glProgramUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv _ptrc_glProgramUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f _ptrc_glProgramUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv _ptrc_glProgramUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i _ptrc_glProgramUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv _ptrc_glProgramUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui _ptrc_glProgramUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv _ptrc_glProgramUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv _ptrc_glProgramUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv _ptrc_glProgramUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv _ptrc_glProgramUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv _ptrc_glProgramUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv _ptrc_glProgramUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv _ptrc_glProgramUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv _ptrc_glProgramUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv _ptrc_glProgramUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv _ptrc_glProgramUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv _ptrc_glProgramUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv _ptrc_glProgramUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv _ptrc_glProgramUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv _ptrc_glProgramUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv _ptrc_glProgramUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv _ptrc_glProgramUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv _ptrc_glProgramUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv _ptrc_glProgramUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv _ptrc_glProgramUniformMatrix4x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages _ptrc_glUseProgramStages
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint pipeline);
#define glValidateProgramPipeline _ptrc_glValidateProgramPipeline
#endif /*GL_ARB_separate_shader_objects*/ 


#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv _ptrc_glGetActiveAtomicCounterBufferiv
#endif /*GL_ARB_shader_atomic_counters*/ 




#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture _ptrc_glBindImageTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield barriers);
#define glMemoryBarrier _ptrc_glMemoryBarrier
#endif /*GL_ARB_shader_image_load_store*/ 


#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glAttachObjectARB)(GLhandleARB containerObj, GLhandleARB obj);
#define glAttachObjectARB _ptrc_glAttachObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderARB)(GLhandleARB shaderObj);
#define glCompileShaderARB _ptrc_glCompileShaderARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateProgramObjectARB)(void);
#define glCreateProgramObjectARB _ptrc_glCreateProgramObjectARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateShaderObjectARB)(GLenum shaderType);
#define glCreateShaderObjectARB _ptrc_glCreateShaderObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteObjectARB)(GLhandleARB obj);
#define glDeleteObjectARB _ptrc_glDeleteObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDetachObjectARB)(GLhandleARB containerObj, GLhandleARB attachedObj);
#define glDetachObjectARB _ptrc_glDetachObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
#define glGetActiveUniformARB _ptrc_glGetActiveUniformARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedObjectsARB)(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj);
#define glGetAttachedObjectsARB _ptrc_glGetAttachedObjectsARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glGetHandleARB)(GLenum pname);
#define glGetHandleARB _ptrc_glGetHandleARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInfoLogARB)(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog);
#define glGetInfoLogARB _ptrc_glGetInfoLogARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterfvARB)(GLhandleARB obj, GLenum pname, GLfloat * params);
#define glGetObjectParameterfvARB _ptrc_glGetObjectParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivARB)(GLhandleARB obj, GLenum pname, GLint * params);
#define glGetObjectParameterivARB _ptrc_glGetObjectParameterivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSourceARB)(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source);
#define glGetShaderSourceARB _ptrc_glGetShaderSourceARB
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocationARB)(GLhandleARB programObj, const GLcharARB * name);
#define glGetUniformLocationARB _ptrc_glGetUniformLocationARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfvARB)(GLhandleARB programObj, GLint location, GLfloat * params);
#define glGetUniformfvARB _ptrc_glGetUniformfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformivARB)(GLhandleARB programObj, GLint location, GLint * params);
#define glGetUniformivARB _ptrc_glGetUniformivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glLinkProgramARB)(GLhandleARB programObj);
#define glLinkProgramARB _ptrc_glLinkProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderSourceARB)(GLhandleARB shaderObj, GLsizei count, const GLcharARB ** string, const GLint * length);
#define glShaderSourceARB _ptrc_glShaderSourceARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fARB)(GLint location, GLfloat v0);
#define glUniform1fARB _ptrc_glUniform1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fvARB)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform1fvARB _ptrc_glUniform1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1iARB)(GLint location, GLint v0);
#define glUniform1iARB _ptrc_glUniform1iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ivARB)(GLint location, GLsizei count, const GLint * value);
#define glUniform1ivARB _ptrc_glUniform1ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fARB)(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2fARB _ptrc_glUniform2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fvARB)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform2fvARB _ptrc_glUniform2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2iARB)(GLint location, GLint v0, GLint v1);
#define glUniform2iARB _ptrc_glUniform2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ivARB)(GLint location, GLsizei count, const GLint * value);
#define glUniform2ivARB _ptrc_glUniform2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3fARB _ptrc_glUniform3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fvARB)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform3fvARB _ptrc_glUniform3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3iARB)(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3iARB _ptrc_glUniform3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ivARB)(GLint location, GLsizei count, const GLint * value);
#define glUniform3ivARB _ptrc_glUniform3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4fARB _ptrc_glUniform4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fvARB)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform4fvARB _ptrc_glUniform4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4iARB)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4iARB _ptrc_glUniform4iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ivARB)(GLint location, GLsizei count, const GLint * value);
#define glUniform4ivARB _ptrc_glUniform4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2fvARB _ptrc_glUniformMatrix2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3fvARB _ptrc_glUniformMatrix3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4fvARB _ptrc_glUniformMatrix4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramObjectARB)(GLhandleARB programObj);
#define glUseProgramObjectARB _ptrc_glUseProgramObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramARB)(GLhandleARB programObj);
#define glValidateProgramARB _ptrc_glValidateProgramARB
#endif /*GL_ARB_shader_objects*/ 


#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding _ptrc_glShaderStorageBlockBinding
#endif /*GL_ARB_shader_storage_buffer_object*/ 

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName _ptrc_glGetActiveSubroutineName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName _ptrc_glGetActiveSubroutineUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv _ptrc_glGetActiveSubroutineUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv _ptrc_glGetProgramStageiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex _ptrc_glGetSubroutineIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineUniformLocation _ptrc_glGetSubroutineUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv _ptrc_glGetUniformSubroutineuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv _ptrc_glUniformSubroutinesuiv
#endif /*GL_ARB_shader_subroutine*/ 





#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar *const* path, const GLint * length);
#define glCompileShaderIncludeARB _ptrc_glCompileShaderIncludeARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamedStringARB)(GLint namelen, const GLchar * name);
#define glDeleteNamedStringARB _ptrc_glDeleteNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringARB)(GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string);
#define glGetNamedStringARB _ptrc_glGetNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringivARB)(GLint namelen, const GLchar * name, GLenum pname, GLint * params);
#define glGetNamedStringivARB _ptrc_glGetNamedStringivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedStringARB)(GLint namelen, const GLchar * name);
#define glIsNamedStringARB _ptrc_glIsNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedStringARB)(GLenum type, GLint namelen, const GLchar * name, GLint stringlen, const GLchar * string);
#define glNamedStringARB _ptrc_glNamedStringARB
#endif /*GL_ARB_shading_language_include*/ 



#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferPageCommitmentARB)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glBufferPageCommitmentARB _ptrc_glBufferPageCommitmentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferPageCommitmentARB)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glNamedBufferPageCommitmentARB _ptrc_glNamedBufferPageCommitmentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferPageCommitmentEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glNamedBufferPageCommitmentEXT _ptrc_glNamedBufferPageCommitmentEXT
#endif /*GL_ARB_sparse_buffer*/ 

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexPageCommitmentARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#define glTexPageCommitmentARB _ptrc_glTexPageCommitmentARB
#endif /*GL_ARB_sparse_texture*/ 


#ifndef GL_ARB_sync
#define GL_ARB_sync 1
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync _ptrc_glClientWaitSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync sync);
#define glDeleteSync _ptrc_glDeleteSync
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum condition, GLbitfield flags);
#define glFenceSync _ptrc_glFenceSync
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum pname, GLint64 * data);
#define glGetInteger64v _ptrc_glGetInteger64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
#define glGetSynciv _ptrc_glGetSynciv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync sync);
#define glIsSync _ptrc_glIsSync
extern void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync _ptrc_glWaitSync
#endif /*GL_ARB_sync*/ 

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv _ptrc_glPatchParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum pname, GLint value);
#define glPatchParameteri _ptrc_glPatchParameteri
#endif /*GL_ARB_tessellation_shader*/ 

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrier)(void);
#define glTextureBarrier _ptrc_glTextureBarrier
#endif /*GL_ARB_texture_barrier*/ 


#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferARB)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBufferARB _ptrc_glTexBufferARB
#endif /*GL_ARB_texture_buffer_object*/ 


#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange _ptrc_glTexBufferRange
#endif /*GL_ARB_texture_buffer_range*/ 

#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage1DARB _ptrc_glCompressedTexImage1DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage2DARB _ptrc_glCompressedTexImage2DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage3DARB _ptrc_glCompressedTexImage3DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1DARB)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage1DARB _ptrc_glCompressedTexSubImage1DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage2DARB _ptrc_glCompressedTexSubImage2DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage3DARB _ptrc_glCompressedTexSubImage3DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImageARB)(GLenum target, GLint level, void * img);
#define glGetCompressedTexImageARB _ptrc_glGetCompressedTexImageARB
#endif /*GL_ARB_texture_compression*/ 













#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv _ptrc_glGetMultisamplefv
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski _ptrc_glSampleMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample _ptrc_glTexImage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample _ptrc_glTexImage3DMultisample
#endif /*GL_ARB_texture_multisample*/ 








#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D _ptrc_glTexStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D _ptrc_glTexStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D _ptrc_glTexStorage3D
#endif /*GL_ARB_texture_storage*/ 

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample _ptrc_glTexStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample _ptrc_glTexStorage3DMultisample
#endif /*GL_ARB_texture_storage_multisample*/ 


#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView _ptrc_glTextureView
#endif /*GL_ARB_texture_view*/ 

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v _ptrc_glGetQueryObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v _ptrc_glGetQueryObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint id, GLenum target);
#define glQueryCounter _ptrc_glQueryCounter
#endif /*GL_ARB_timer_query*/ 

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum target, GLuint id);
#define glBindTransformFeedback _ptrc_glBindTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks _ptrc_glDeleteTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum mode, GLuint id);
#define glDrawTransformFeedback _ptrc_glDrawTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks _ptrc_glGenTransformFeedbacks
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint id);
#define glIsTransformFeedback _ptrc_glIsTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)(void);
#define glPauseTransformFeedback _ptrc_glPauseTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)(void);
#define glResumeTransformFeedback _ptrc_glResumeTransformFeedback
#endif /*GL_ARB_transform_feedback2*/ 

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed _ptrc_glBeginQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream _ptrc_glDrawTransformFeedbackStream
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum target, GLuint index);
#define glEndQueryIndexed _ptrc_glEndQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv _ptrc_glGetQueryIndexediv
#endif /*GL_ARB_transform_feedback3*/ 

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced _ptrc_glDrawTransformFeedbackInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced _ptrc_glDrawTransformFeedbackStreamInstanced
#endif /*GL_ARB_transform_feedback_instanced*/ 


#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixdARB)(const GLdouble * m);
#define glLoadTransposeMatrixdARB _ptrc_glLoadTransposeMatrixdARB
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixfARB)(const GLfloat * m);
#define glLoadTransposeMatrixfARB _ptrc_glLoadTransposeMatrixfARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixdARB)(const GLdouble * m);
#define glMultTransposeMatrixdARB _ptrc_glMultTransposeMatrixdARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixfARB)(const GLfloat * m);
#define glMultTransposeMatrixfARB _ptrc_glMultTransposeMatrixfARB
#endif /*GL_ARB_transpose_matrix*/ 

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase _ptrc_glBindBufferBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange _ptrc_glBindBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName _ptrc_glGetActiveUniformBlockName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv _ptrc_glGetActiveUniformBlockiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName _ptrc_glGetActiveUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv _ptrc_glGetActiveUniformsiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegeri_v)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v _ptrc_glGetIntegeri_v
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex _ptrc_glGetUniformBlockIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
#define glGetUniformIndices _ptrc_glGetUniformIndices
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding _ptrc_glUniformBlockBinding
#endif /*GL_ARB_uniform_buffer_object*/ 


#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint ren_array);
#define glBindVertexArray _ptrc_glBindVertexArray
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays _ptrc_glDeleteVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays _ptrc_glGenVertexArrays
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint ren_array);
#define glIsVertexArray _ptrc_glIsVertexArray
#endif /*GL_ARB_vertex_array_object*/ 

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv _ptrc_glGetVertexAttribLdv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint index, GLdouble x);
#define glVertexAttribL1d _ptrc_glVertexAttribL1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv _ptrc_glVertexAttribL1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d _ptrc_glVertexAttribL2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv _ptrc_glVertexAttribL2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d _ptrc_glVertexAttribL3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv _ptrc_glVertexAttribL3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d _ptrc_glVertexAttribL4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv _ptrc_glVertexAttribL4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer _ptrc_glVertexAttribLPointer
#endif /*GL_ARB_vertex_attrib_64bit*/ 

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer _ptrc_glBindVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding _ptrc_glVertexAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat _ptrc_glVertexAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat _ptrc_glVertexAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat _ptrc_glVertexAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor _ptrc_glVertexBindingDivisor
#endif /*GL_ARB_vertex_attrib_binding*/ 

#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferARB)(GLenum target, GLuint buffer);
#define glBindBufferARB _ptrc_glBindBufferARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferDataARB)(GLenum target, GLsizeiptrARB size, const void * data, GLenum usage);
#define glBufferDataARB _ptrc_glBufferDataARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data);
#define glBufferSubDataARB _ptrc_glBufferSubDataARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffersARB)(GLsizei n, const GLuint * buffers);
#define glDeleteBuffersARB _ptrc_glDeleteBuffersARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenBuffersARB)(GLsizei n, GLuint * buffers);
#define glGenBuffersARB _ptrc_glGenBuffersARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterivARB)(GLenum target, GLenum pname, GLint * params);
#define glGetBufferParameterivARB _ptrc_glGetBufferParameterivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointervARB)(GLenum target, GLenum pname, void ** params);
#define glGetBufferPointervARB _ptrc_glGetBufferPointervARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data);
#define glGetBufferSubDataARB _ptrc_glGetBufferSubDataARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferARB)(GLuint buffer);
#define glIsBufferARB _ptrc_glIsBufferARB
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferARB)(GLenum target, GLenum access);
#define glMapBufferARB _ptrc_glMapBufferARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBufferARB)(GLenum target);
#define glUnmapBufferARB _ptrc_glUnmapBufferARB
#endif /*GL_ARB_vertex_buffer_object*/ 

#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum target, GLuint program);
#define glBindProgramARB _ptrc_glBindProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei n, const GLuint * programs);
#define glDeleteProgramsARB _ptrc_glDeleteProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArrayARB)(GLuint index);
#define glDisableVertexAttribArrayARB _ptrc_glDisableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArrayARB)(GLuint index);
#define glEnableVertexAttribArrayARB _ptrc_glEnableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei n, GLuint * programs);
#define glGenProgramsARB _ptrc_glGenProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum target, GLuint index, GLdouble * params);
#define glGetProgramEnvParameterdvARB _ptrc_glGetProgramEnvParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum target, GLuint index, GLfloat * params);
#define glGetProgramEnvParameterfvARB _ptrc_glGetProgramEnvParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum target, GLuint index, GLdouble * params);
#define glGetProgramLocalParameterdvARB _ptrc_glGetProgramLocalParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum target, GLuint index, GLfloat * params);
#define glGetProgramLocalParameterfvARB _ptrc_glGetProgramLocalParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum target, GLenum pname, void * string);
#define glGetProgramStringARB _ptrc_glGetProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum target, GLenum pname, GLint * params);
#define glGetProgramivARB _ptrc_glGetProgramivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervARB)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointervARB _ptrc_glGetVertexAttribPointervARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvARB)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdvARB _ptrc_glGetVertexAttribdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvARB)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfvARB _ptrc_glGetVertexAttribfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivARB)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribivARB _ptrc_glGetVertexAttribivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint program);
#define glIsProgramARB _ptrc_glIsProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramEnvParameter4dARB _ptrc_glProgramEnvParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params);
#define glProgramEnvParameter4dvARB _ptrc_glProgramEnvParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramEnvParameter4fARB _ptrc_glProgramEnvParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params);
#define glProgramEnvParameter4fvARB _ptrc_glProgramEnvParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramLocalParameter4dARB _ptrc_glProgramLocalParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum target, GLuint index, const GLdouble * params);
#define glProgramLocalParameter4dvARB _ptrc_glProgramLocalParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramLocalParameter4fARB _ptrc_glProgramLocalParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum target, GLuint index, const GLfloat * params);
#define glProgramLocalParameter4fvARB _ptrc_glProgramLocalParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum target, GLenum format, GLsizei len, const void * string);
#define glProgramStringARB _ptrc_glProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dARB)(GLuint index, GLdouble x);
#define glVertexAttrib1dARB _ptrc_glVertexAttrib1dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dvARB _ptrc_glVertexAttrib1dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fARB)(GLuint index, GLfloat x);
#define glVertexAttrib1fARB _ptrc_glVertexAttrib1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fvARB _ptrc_glVertexAttrib1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sARB)(GLuint index, GLshort x);
#define glVertexAttrib1sARB _ptrc_glVertexAttrib1sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib1svARB _ptrc_glVertexAttrib1svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dARB)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2dARB _ptrc_glVertexAttrib2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dvARB _ptrc_glVertexAttrib2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fARB)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2fARB _ptrc_glVertexAttrib2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fvARB _ptrc_glVertexAttrib2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sARB)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2sARB _ptrc_glVertexAttrib2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib2svARB _ptrc_glVertexAttrib2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3dARB _ptrc_glVertexAttrib3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dvARB _ptrc_glVertexAttrib3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3fARB _ptrc_glVertexAttrib3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fvARB _ptrc_glVertexAttrib3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sARB)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3sARB _ptrc_glVertexAttrib3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib3svARB _ptrc_glVertexAttrib3svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NbvARB)(GLuint index, const GLbyte * v);
#define glVertexAttrib4NbvARB _ptrc_glVertexAttrib4NbvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NivARB)(GLuint index, const GLint * v);
#define glVertexAttrib4NivARB _ptrc_glVertexAttrib4NivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NsvARB)(GLuint index, const GLshort * v);
#define glVertexAttrib4NsvARB _ptrc_glVertexAttrib4NsvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubARB)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4NubARB _ptrc_glVertexAttrib4NubARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubvARB)(GLuint index, const GLubyte * v);
#define glVertexAttrib4NubvARB _ptrc_glVertexAttrib4NubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NuivARB)(GLuint index, const GLuint * v);
#define glVertexAttrib4NuivARB _ptrc_glVertexAttrib4NuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NusvARB)(GLuint index, const GLushort * v);
#define glVertexAttrib4NusvARB _ptrc_glVertexAttrib4NusvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bvARB)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bvARB _ptrc_glVertexAttrib4bvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4dARB _ptrc_glVertexAttrib4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dvARB _ptrc_glVertexAttrib4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4fARB _ptrc_glVertexAttrib4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fvARB _ptrc_glVertexAttrib4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ivARB)(GLuint index, const GLint * v);
#define glVertexAttrib4ivARB _ptrc_glVertexAttrib4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sARB)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4sARB _ptrc_glVertexAttrib4sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib4svARB _ptrc_glVertexAttrib4svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvARB)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubvARB _ptrc_glVertexAttrib4ubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uivARB)(GLuint index, const GLuint * v);
#define glVertexAttrib4uivARB _ptrc_glVertexAttrib4uivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usvARB)(GLuint index, const GLushort * v);
#define glVertexAttrib4usvARB _ptrc_glVertexAttrib4usvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerARB)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointerARB _ptrc_glVertexAttribPointerARB
#endif /*GL_ARB_vertex_program*/ 

#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocationARB)(GLhandleARB programObj, GLuint index, const GLcharARB * name);
#define glBindAttribLocationARB _ptrc_glBindAttribLocationARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArrayARB)(GLuint index);
#define glDisableVertexAttribArrayARB _ptrc_glDisableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArrayARB)(GLuint index);
#define glEnableVertexAttribArrayARB _ptrc_glEnableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttribARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
#define glGetActiveAttribARB _ptrc_glGetActiveAttribARB
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocationARB)(GLhandleARB programObj, const GLcharARB * name);
#define glGetAttribLocationARB _ptrc_glGetAttribLocationARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervARB)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointervARB _ptrc_glGetVertexAttribPointervARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvARB)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdvARB _ptrc_glGetVertexAttribdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvARB)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfvARB _ptrc_glGetVertexAttribfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivARB)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribivARB _ptrc_glGetVertexAttribivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dARB)(GLuint index, GLdouble x);
#define glVertexAttrib1dARB _ptrc_glVertexAttrib1dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dvARB _ptrc_glVertexAttrib1dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fARB)(GLuint index, GLfloat x);
#define glVertexAttrib1fARB _ptrc_glVertexAttrib1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fvARB _ptrc_glVertexAttrib1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sARB)(GLuint index, GLshort x);
#define glVertexAttrib1sARB _ptrc_glVertexAttrib1sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib1svARB _ptrc_glVertexAttrib1svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dARB)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2dARB _ptrc_glVertexAttrib2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dvARB _ptrc_glVertexAttrib2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fARB)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2fARB _ptrc_glVertexAttrib2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fvARB _ptrc_glVertexAttrib2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sARB)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2sARB _ptrc_glVertexAttrib2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib2svARB _ptrc_glVertexAttrib2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3dARB _ptrc_glVertexAttrib3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dvARB _ptrc_glVertexAttrib3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3fARB _ptrc_glVertexAttrib3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fvARB _ptrc_glVertexAttrib3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sARB)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3sARB _ptrc_glVertexAttrib3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib3svARB _ptrc_glVertexAttrib3svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NbvARB)(GLuint index, const GLbyte * v);
#define glVertexAttrib4NbvARB _ptrc_glVertexAttrib4NbvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NivARB)(GLuint index, const GLint * v);
#define glVertexAttrib4NivARB _ptrc_glVertexAttrib4NivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NsvARB)(GLuint index, const GLshort * v);
#define glVertexAttrib4NsvARB _ptrc_glVertexAttrib4NsvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubARB)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4NubARB _ptrc_glVertexAttrib4NubARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubvARB)(GLuint index, const GLubyte * v);
#define glVertexAttrib4NubvARB _ptrc_glVertexAttrib4NubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NuivARB)(GLuint index, const GLuint * v);
#define glVertexAttrib4NuivARB _ptrc_glVertexAttrib4NuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NusvARB)(GLuint index, const GLushort * v);
#define glVertexAttrib4NusvARB _ptrc_glVertexAttrib4NusvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bvARB)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bvARB _ptrc_glVertexAttrib4bvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4dARB _ptrc_glVertexAttrib4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvARB)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dvARB _ptrc_glVertexAttrib4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4fARB _ptrc_glVertexAttrib4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvARB)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fvARB _ptrc_glVertexAttrib4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ivARB)(GLuint index, const GLint * v);
#define glVertexAttrib4ivARB _ptrc_glVertexAttrib4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sARB)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4sARB _ptrc_glVertexAttrib4sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svARB)(GLuint index, const GLshort * v);
#define glVertexAttrib4svARB _ptrc_glVertexAttrib4svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvARB)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubvARB _ptrc_glVertexAttrib4ubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uivARB)(GLuint index, const GLuint * v);
#define glVertexAttrib4uivARB _ptrc_glVertexAttrib4uivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usvARB)(GLuint index, const GLushort * v);
#define glVertexAttrib4usvARB _ptrc_glVertexAttrib4usvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerARB)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointerARB _ptrc_glVertexAttribPointerARB
#endif /*GL_ARB_vertex_shader*/ 


#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP3ui)(GLenum type, GLuint color);
#define glColorP3ui _ptrc_glColorP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP3uiv)(GLenum type, const GLuint * color);
#define glColorP3uiv _ptrc_glColorP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP4ui)(GLenum type, GLuint color);
#define glColorP4ui _ptrc_glColorP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP4uiv)(GLenum type, const GLuint * color);
#define glColorP4uiv _ptrc_glColorP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui _ptrc_glMultiTexCoordP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP1uiv _ptrc_glMultiTexCoordP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui _ptrc_glMultiTexCoordP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP2uiv _ptrc_glMultiTexCoordP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui _ptrc_glMultiTexCoordP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP3uiv _ptrc_glMultiTexCoordP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui _ptrc_glMultiTexCoordP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP4uiv _ptrc_glMultiTexCoordP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalP3ui)(GLenum type, GLuint coords);
#define glNormalP3ui _ptrc_glNormalP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalP3uiv)(GLenum type, const GLuint * coords);
#define glNormalP3uiv _ptrc_glNormalP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3ui)(GLenum type, GLuint color);
#define glSecondaryColorP3ui _ptrc_glSecondaryColorP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3uiv)(GLenum type, const GLuint * color);
#define glSecondaryColorP3uiv _ptrc_glSecondaryColorP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1ui)(GLenum type, GLuint coords);
#define glTexCoordP1ui _ptrc_glTexCoordP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1uiv)(GLenum type, const GLuint * coords);
#define glTexCoordP1uiv _ptrc_glTexCoordP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2ui)(GLenum type, GLuint coords);
#define glTexCoordP2ui _ptrc_glTexCoordP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2uiv)(GLenum type, const GLuint * coords);
#define glTexCoordP2uiv _ptrc_glTexCoordP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3ui)(GLenum type, GLuint coords);
#define glTexCoordP3ui _ptrc_glTexCoordP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3uiv)(GLenum type, const GLuint * coords);
#define glTexCoordP3uiv _ptrc_glTexCoordP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4ui)(GLenum type, GLuint coords);
#define glTexCoordP4ui _ptrc_glTexCoordP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4uiv)(GLenum type, const GLuint * coords);
#define glTexCoordP4uiv _ptrc_glTexCoordP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui _ptrc_glVertexAttribP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv _ptrc_glVertexAttribP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui _ptrc_glVertexAttribP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv _ptrc_glVertexAttribP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui _ptrc_glVertexAttribP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv _ptrc_glVertexAttribP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui _ptrc_glVertexAttribP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv _ptrc_glVertexAttribP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP2ui)(GLenum type, GLuint value);
#define glVertexP2ui _ptrc_glVertexP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP2uiv)(GLenum type, const GLuint * value);
#define glVertexP2uiv _ptrc_glVertexP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP3ui)(GLenum type, GLuint value);
#define glVertexP3ui _ptrc_glVertexP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP3uiv)(GLenum type, const GLuint * value);
#define glVertexP3uiv _ptrc_glVertexP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP4ui)(GLenum type, GLuint value);
#define glVertexP4ui _ptrc_glVertexP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP4uiv)(GLenum type, const GLuint * value);
#define glVertexP4uiv _ptrc_glVertexP4uiv
#endif /*GL_ARB_vertex_type_2_10_10_10_rev*/ 

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv _ptrc_glDepthRangeArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed _ptrc_glDepthRangeIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v _ptrc_glGetDoublei_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v _ptrc_glGetFloati_v
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv _ptrc_glScissorArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed _ptrc_glScissorIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint index, const GLint * v);
#define glScissorIndexedv _ptrc_glScissorIndexedv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv _ptrc_glViewportArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf _ptrc_glViewportIndexedf
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv _ptrc_glViewportIndexedfv
#endif /*GL_ARB_viewport_array*/ 

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dARB)(GLdouble x, GLdouble y);
#define glWindowPos2dARB _ptrc_glWindowPos2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvARB)(const GLdouble * v);
#define glWindowPos2dvARB _ptrc_glWindowPos2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fARB)(GLfloat x, GLfloat y);
#define glWindowPos2fARB _ptrc_glWindowPos2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvARB)(const GLfloat * v);
#define glWindowPos2fvARB _ptrc_glWindowPos2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iARB)(GLint x, GLint y);
#define glWindowPos2iARB _ptrc_glWindowPos2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivARB)(const GLint * v);
#define glWindowPos2ivARB _ptrc_glWindowPos2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sARB)(GLshort x, GLshort y);
#define glWindowPos2sARB _ptrc_glWindowPos2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svARB)(const GLshort * v);
#define glWindowPos2svARB _ptrc_glWindowPos2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dARB)(GLdouble x, GLdouble y, GLdouble z);
#define glWindowPos3dARB _ptrc_glWindowPos3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvARB)(const GLdouble * v);
#define glWindowPos3dvARB _ptrc_glWindowPos3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fARB)(GLfloat x, GLfloat y, GLfloat z);
#define glWindowPos3fARB _ptrc_glWindowPos3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvARB)(const GLfloat * v);
#define glWindowPos3fvARB _ptrc_glWindowPos3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iARB)(GLint x, GLint y, GLint z);
#define glWindowPos3iARB _ptrc_glWindowPos3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivARB)(const GLint * v);
#define glWindowPos3ivARB _ptrc_glWindowPos3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sARB)(GLshort x, GLshort y, GLshort z);
#define glWindowPos3sARB _ptrc_glWindowPos3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svARB)(const GLshort * v);
#define glWindowPos3svARB _ptrc_glWindowPos3svARB
#endif /*GL_ARB_window_pos*/ 

#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersATI)(GLsizei n, const GLenum * bufs);
#define glDrawBuffersATI _ptrc_glDrawBuffersATI
#endif /*GL_ATI_draw_buffers*/ 







#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBufferSizeEXT)(GLuint program, GLint location);
#define glGetUniformBufferSizeEXT _ptrc_glGetUniformBufferSizeEXT
extern GLintptr (CODEGEN_FUNCPTR *_ptrc_glGetUniformOffsetEXT)(GLuint program, GLint location);
#define glGetUniformOffsetEXT _ptrc_glGetUniformOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBufferEXT)(GLuint program, GLint location, GLuint buffer);
#define glUniformBufferEXT _ptrc_glUniformBufferEXT
#endif /*GL_EXT_bindable_uniform*/ 

#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColorEXT)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColorEXT _ptrc_glBlendColorEXT
#endif /*GL_EXT_blend_color*/ 

#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateEXT)(GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparateEXT _ptrc_glBlendEquationSeparateEXT
#endif /*GL_EXT_blend_equation_separate*/ 

#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateEXT)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparateEXT _ptrc_glBlendFuncSeparateEXT
#endif /*GL_EXT_blend_func_separate*/ 

#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationEXT)(GLenum mode);
#define glBlendEquationEXT _ptrc_glBlendEquationEXT
#endif /*GL_EXT_blend_minmax*/ 


#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glLockArraysEXT)(GLint first, GLsizei count);
#define glLockArraysEXT _ptrc_glLockArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUnlockArraysEXT)(void);
#define glUnlockArraysEXT _ptrc_glUnlockArraysEXT
#endif /*GL_EXT_compiled_vertex_array*/ 

#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsEXT)(GLclampd zmin, GLclampd zmax);
#define glDepthBoundsEXT _ptrc_glDepthBoundsEXT
#endif /*GL_EXT_depth_bounds_test*/ 

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindMultiTextureEXT)(GLenum texunit, GLenum target, GLuint texture);
#define glBindMultiTextureEXT _ptrc_glBindMultiTextureEXT
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatusEXT)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatusEXT _ptrc_glCheckNamedFramebufferStatusEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferDataEXT)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferDataEXT _ptrc_glClearNamedBufferDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubDataEXT)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubDataEXT _ptrc_glClearNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClientAttribDefaultEXT)(GLbitfield mask);
#define glClientAttribDefaultEXT _ptrc_glClientAttribDefaultEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage1DEXT _ptrc_glCompressedMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage2DEXT _ptrc_glCompressedMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage3DEXT _ptrc_glCompressedMultiTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage1DEXT _ptrc_glCompressedMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage2DEXT _ptrc_glCompressedMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage3DEXT _ptrc_glCompressedMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage1DEXT _ptrc_glCompressedTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage2DEXT _ptrc_glCompressedTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage3DEXT _ptrc_glCompressedTextureImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage1DEXT _ptrc_glCompressedTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage2DEXT _ptrc_glCompressedTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage3DEXT _ptrc_glCompressedTextureSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyMultiTexImage1DEXT _ptrc_glCopyMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyMultiTexImage2DEXT _ptrc_glCopyMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyMultiTexSubImage1DEXT _ptrc_glCopyMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyMultiTexSubImage2DEXT _ptrc_glCopyMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyMultiTexSubImage3DEXT _ptrc_glCopyMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTextureImage1DEXT _ptrc_glCopyTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTextureImage2DEXT _ptrc_glCopyTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1DEXT _ptrc_glCopyTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2DEXT _ptrc_glCopyTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3DEXT _ptrc_glCopyTextureSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateIndexedEXT)(GLenum ren_array, GLuint index);
#define glDisableClientStateIndexedEXT _ptrc_glDisableClientStateIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateiEXT)(GLenum ren_array, GLuint index);
#define glDisableClientStateiEXT _ptrc_glDisableClientStateiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum target, GLuint index);
#define glDisableIndexedEXT _ptrc_glDisableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttribEXT)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttribEXT _ptrc_glDisableVertexArrayAttribEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayEXT)(GLuint vaobj, GLenum ren_array);
#define glDisableVertexArrayEXT _ptrc_glDisableVertexArrayEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateIndexedEXT)(GLenum ren_array, GLuint index);
#define glEnableClientStateIndexedEXT _ptrc_glEnableClientStateIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateiEXT)(GLenum ren_array, GLuint index);
#define glEnableClientStateiEXT _ptrc_glEnableClientStateiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum target, GLuint index);
#define glEnableIndexedEXT _ptrc_glEnableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttribEXT)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttribEXT _ptrc_glEnableVertexArrayAttribEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayEXT)(GLuint vaobj, GLenum ren_array);
#define glEnableVertexArrayEXT _ptrc_glEnableVertexArrayEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRangeEXT _ptrc_glFlushMappedNamedBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBufferEXT)(GLuint framebuffer, GLenum mode);
#define glFramebufferDrawBufferEXT _ptrc_glFramebufferDrawBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBuffersEXT)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glFramebufferDrawBuffersEXT _ptrc_glFramebufferDrawBuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferReadBufferEXT)(GLuint framebuffer, GLenum mode);
#define glFramebufferReadBufferEXT _ptrc_glFramebufferReadBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMultiTexMipmapEXT)(GLenum texunit, GLenum target);
#define glGenerateMultiTexMipmapEXT _ptrc_glGenerateMultiTexMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmapEXT)(GLuint texture, GLenum target);
#define glGenerateTextureMipmapEXT _ptrc_glGenerateTextureMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleanIndexedvEXT _ptrc_glGetBooleanIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedMultiTexImageEXT)(GLenum texunit, GLenum target, GLint lod, void * img);
#define glGetCompressedMultiTexImageEXT _ptrc_glGetCompressedMultiTexImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImageEXT)(GLuint texture, GLenum target, GLint lod, void * img);
#define glGetCompressedTextureImageEXT _ptrc_glGetCompressedTextureImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoubleIndexedvEXT)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoubleIndexedvEXT _ptrc_glGetDoubleIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_vEXT)(GLenum pname, GLuint index, GLdouble * params);
#define glGetDoublei_vEXT _ptrc_glGetDoublei_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloatIndexedvEXT)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloatIndexedvEXT _ptrc_glGetFloatIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_vEXT)(GLenum pname, GLuint index, GLfloat * params);
#define glGetFloati_vEXT _ptrc_glGetFloati_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint * params);
#define glGetFramebufferParameterivEXT _ptrc_glGetFramebufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum target, GLuint index, GLint * data);
#define glGetIntegerIndexedvEXT _ptrc_glGetIntegerIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
#define glGetMultiTexEnvfvEXT _ptrc_glGetMultiTexEnvfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexEnvivEXT _ptrc_glGetMultiTexEnvivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params);
#define glGetMultiTexGendvEXT _ptrc_glGetMultiTexGendvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params);
#define glGetMultiTexGenfvEXT _ptrc_glGetMultiTexGenfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint * params);
#define glGetMultiTexGenivEXT _ptrc_glGetMultiTexGenivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexImageEXT)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetMultiTexImageEXT _ptrc_glGetMultiTexImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterfvEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetMultiTexLevelParameterfvEXT _ptrc_glGetMultiTexLevelParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterivEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetMultiTexLevelParameterivEXT _ptrc_glGetMultiTexLevelParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexParameterIivEXT _ptrc_glGetMultiTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, GLuint * params);
#define glGetMultiTexParameterIuivEXT _ptrc_glGetMultiTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
#define glGetMultiTexParameterfvEXT _ptrc_glGetMultiTexParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexParameterivEXT _ptrc_glGetMultiTexParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterivEXT)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameterivEXT _ptrc_glGetNamedBufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointervEXT)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointervEXT _ptrc_glGetNamedBufferPointervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubDataEXT _ptrc_glGetNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameterivEXT _ptrc_glGetNamedFramebufferAttachmentParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint * params);
#define glGetNamedFramebufferParameterivEXT _ptrc_glGetNamedFramebufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIivEXT)(GLuint program, GLenum target, GLuint index, GLint * params);
#define glGetNamedProgramLocalParameterIivEXT _ptrc_glGetNamedProgramLocalParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIuivEXT)(GLuint program, GLenum target, GLuint index, GLuint * params);
#define glGetNamedProgramLocalParameterIuivEXT _ptrc_glGetNamedProgramLocalParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterdvEXT)(GLuint program, GLenum target, GLuint index, GLdouble * params);
#define glGetNamedProgramLocalParameterdvEXT _ptrc_glGetNamedProgramLocalParameterdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterfvEXT)(GLuint program, GLenum target, GLuint index, GLfloat * params);
#define glGetNamedProgramLocalParameterfvEXT _ptrc_glGetNamedProgramLocalParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramStringEXT)(GLuint program, GLenum target, GLenum pname, void * string);
#define glGetNamedProgramStringEXT _ptrc_glGetNamedProgramStringEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramivEXT)(GLuint program, GLenum target, GLenum pname, GLint * params);
#define glGetNamedProgramivEXT _ptrc_glGetNamedProgramivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameterivEXT)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameterivEXT _ptrc_glGetNamedRenderbufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerIndexedvEXT)(GLenum target, GLuint index, void ** data);
#define glGetPointerIndexedvEXT _ptrc_glGetPointerIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointeri_vEXT)(GLenum pname, GLuint index, void ** params);
#define glGetPointeri_vEXT _ptrc_glGetPointeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImageEXT)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTextureImageEXT _ptrc_glGetTextureImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfvEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfvEXT _ptrc_glGetTextureLevelParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterivEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameterivEXT _ptrc_glGetTextureLevelParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, GLint * params);
#define glGetTextureParameterIivEXT _ptrc_glGetTextureParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, GLuint * params);
#define glGetTextureParameterIuivEXT _ptrc_glGetTextureParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat * params);
#define glGetTextureParameterfvEXT _ptrc_glGetTextureParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, GLint * params);
#define glGetTextureParameterivEXT _ptrc_glGetTextureParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIntegeri_vEXT _ptrc_glGetVertexArrayIntegeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegervEXT)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayIntegervEXT _ptrc_glGetVertexArrayIntegervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointeri_vEXT)(GLuint vaobj, GLuint index, GLenum pname, void ** param);
#define glGetVertexArrayPointeri_vEXT _ptrc_glGetVertexArrayPointeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointervEXT)(GLuint vaobj, GLenum pname, void ** param);
#define glGetVertexArrayPointervEXT _ptrc_glGetVertexArrayPointervEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum target, GLuint index);
#define glIsEnabledIndexedEXT _ptrc_glIsEnabledIndexedEXT
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferEXT)(GLuint buffer, GLenum access);
#define glMapNamedBufferEXT _ptrc_glMapNamedBufferEXT
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRangeEXT _ptrc_glMapNamedBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixFrustumEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixFrustumEXT _ptrc_glMatrixFrustumEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadIdentityEXT)(GLenum mode);
#define glMatrixLoadIdentityEXT _ptrc_glMatrixLoadIdentityEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposedEXT)(GLenum mode, const GLdouble * m);
#define glMatrixLoadTransposedEXT _ptrc_glMatrixLoadTransposedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposefEXT)(GLenum mode, const GLfloat * m);
#define glMatrixLoadTransposefEXT _ptrc_glMatrixLoadTransposefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoaddEXT)(GLenum mode, const GLdouble * m);
#define glMatrixLoaddEXT _ptrc_glMatrixLoaddEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadfEXT)(GLenum mode, const GLfloat * m);
#define glMatrixLoadfEXT _ptrc_glMatrixLoadfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposedEXT)(GLenum mode, const GLdouble * m);
#define glMatrixMultTransposedEXT _ptrc_glMatrixMultTransposedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposefEXT)(GLenum mode, const GLfloat * m);
#define glMatrixMultTransposefEXT _ptrc_glMatrixMultTransposefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultdEXT)(GLenum mode, const GLdouble * m);
#define glMatrixMultdEXT _ptrc_glMatrixMultdEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultfEXT)(GLenum mode, const GLfloat * m);
#define glMatrixMultfEXT _ptrc_glMatrixMultfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixOrthoEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixOrthoEXT _ptrc_glMatrixOrthoEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixPopEXT)(GLenum mode);
#define glMatrixPopEXT _ptrc_glMatrixPopEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixPushEXT)(GLenum mode);
#define glMatrixPushEXT _ptrc_glMatrixPushEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatedEXT)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixRotatedEXT _ptrc_glMatrixRotatedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatefEXT)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixRotatefEXT _ptrc_glMatrixRotatefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixScaledEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixScaledEXT _ptrc_glMatrixScaledEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixScalefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixScalefEXT _ptrc_glMatrixScalefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatedEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixTranslatedEXT _ptrc_glMatrixTranslatedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixTranslatefEXT _ptrc_glMatrixTranslatefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexBufferEXT)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
#define glMultiTexBufferEXT _ptrc_glMultiTexBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordPointerEXT)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glMultiTexCoordPointerEXT _ptrc_glMultiTexCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
#define glMultiTexEnvfEXT _ptrc_glMultiTexEnvfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
#define glMultiTexEnvfvEXT _ptrc_glMultiTexEnvfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnviEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
#define glMultiTexEnviEXT _ptrc_glMultiTexEnviEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexEnvivEXT _ptrc_glMultiTexEnvivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
#define glMultiTexGendEXT _ptrc_glMultiTexGendEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params);
#define glMultiTexGendvEXT _ptrc_glMultiTexGendvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
#define glMultiTexGenfEXT _ptrc_glMultiTexGenfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params);
#define glMultiTexGenfvEXT _ptrc_glMultiTexGenfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGeniEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
#define glMultiTexGeniEXT _ptrc_glMultiTexGeniEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLint * params);
#define glMultiTexGenivEXT _ptrc_glMultiTexGenivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage1DEXT _ptrc_glMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage2DEXT _ptrc_glMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage3DEXT _ptrc_glMultiTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexParameterIivEXT _ptrc_glMultiTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLuint * params);
#define glMultiTexParameterIuivEXT _ptrc_glMultiTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
#define glMultiTexParameterfEXT _ptrc_glMultiTexParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
#define glMultiTexParameterfvEXT _ptrc_glMultiTexParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameteriEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
#define glMultiTexParameteriEXT _ptrc_glMultiTexParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexParameterivEXT _ptrc_glMultiTexParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexRenderbufferEXT)(GLenum texunit, GLenum target, GLuint renderbuffer);
#define glMultiTexRenderbufferEXT _ptrc_glMultiTexRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage1DEXT _ptrc_glMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage2DEXT _ptrc_glMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage3DEXT _ptrc_glMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferDataEXT)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferDataEXT _ptrc_glNamedBufferDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferStorageEXT)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorageEXT _ptrc_glNamedBufferStorageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubDataEXT _ptrc_glNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedCopyBufferSubDataEXT)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glNamedCopyBufferSubDataEXT _ptrc_glNamedCopyBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteriEXT)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteriEXT _ptrc_glNamedFramebufferParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbufferEXT)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbufferEXT _ptrc_glNamedFramebufferRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture1DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glNamedFramebufferTexture1DEXT _ptrc_glNamedFramebufferTexture1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture2DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glNamedFramebufferTexture2DEXT _ptrc_glNamedFramebufferTexture2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture3DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glNamedFramebufferTexture3DEXT _ptrc_glNamedFramebufferTexture3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTextureEXT _ptrc_glNamedFramebufferTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureFaceEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
#define glNamedFramebufferTextureFaceEXT _ptrc_glNamedFramebufferTextureFaceEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayerEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayerEXT _ptrc_glNamedFramebufferTextureLayerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dEXT)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glNamedProgramLocalParameter4dEXT _ptrc_glNamedProgramLocalParameter4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dvEXT)(GLuint program, GLenum target, GLuint index, const GLdouble * params);
#define glNamedProgramLocalParameter4dvEXT _ptrc_glNamedProgramLocalParameter4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fEXT)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glNamedProgramLocalParameter4fEXT _ptrc_glNamedProgramLocalParameter4fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fvEXT)(GLuint program, GLenum target, GLuint index, const GLfloat * params);
#define glNamedProgramLocalParameter4fvEXT _ptrc_glNamedProgramLocalParameter4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4iEXT)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glNamedProgramLocalParameterI4iEXT _ptrc_glNamedProgramLocalParameterI4iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4ivEXT)(GLuint program, GLenum target, GLuint index, const GLint * params);
#define glNamedProgramLocalParameterI4ivEXT _ptrc_glNamedProgramLocalParameterI4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uiEXT)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glNamedProgramLocalParameterI4uiEXT _ptrc_glNamedProgramLocalParameterI4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uivEXT)(GLuint program, GLenum target, GLuint index, const GLuint * params);
#define glNamedProgramLocalParameterI4uivEXT _ptrc_glNamedProgramLocalParameterI4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameters4fvEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
#define glNamedProgramLocalParameters4fvEXT _ptrc_glNamedProgramLocalParameters4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4ivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params);
#define glNamedProgramLocalParametersI4ivEXT _ptrc_glNamedProgramLocalParametersI4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4uivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params);
#define glNamedProgramLocalParametersI4uivEXT _ptrc_glNamedProgramLocalParametersI4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramStringEXT)(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string);
#define glNamedProgramStringEXT _ptrc_glNamedProgramStringEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageEXT)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageEXT _ptrc_glNamedRenderbufferStorageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisampleCoverageEXT _ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisampleEXT _ptrc_glNamedRenderbufferStorageMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dEXT)(GLuint program, GLint location, GLdouble x);
#define glProgramUniform1dEXT _ptrc_glProgramUniform1dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dvEXT _ptrc_glProgramUniform1dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fEXT)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1fEXT _ptrc_glProgramUniform1fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fvEXT _ptrc_glProgramUniform1fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iEXT)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1iEXT _ptrc_glProgramUniform1iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1ivEXT _ptrc_glProgramUniform1ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiEXT)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1uiEXT _ptrc_glProgramUniform1uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uivEXT _ptrc_glProgramUniform1uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y);
#define glProgramUniform2dEXT _ptrc_glProgramUniform2dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dvEXT _ptrc_glProgramUniform2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2fEXT _ptrc_glProgramUniform2fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fvEXT _ptrc_glProgramUniform2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iEXT)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2iEXT _ptrc_glProgramUniform2iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2ivEXT _ptrc_glProgramUniform2ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2uiEXT _ptrc_glProgramUniform2uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uivEXT _ptrc_glProgramUniform2uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glProgramUniform3dEXT _ptrc_glProgramUniform3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dvEXT _ptrc_glProgramUniform3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3fEXT _ptrc_glProgramUniform3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fvEXT _ptrc_glProgramUniform3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3iEXT _ptrc_glProgramUniform3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3ivEXT _ptrc_glProgramUniform3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3uiEXT _ptrc_glProgramUniform3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uivEXT _ptrc_glProgramUniform3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramUniform4dEXT _ptrc_glProgramUniform4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dvEXT _ptrc_glProgramUniform4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4fEXT _ptrc_glProgramUniform4fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fvEXT _ptrc_glProgramUniform4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4iEXT _ptrc_glProgramUniform4iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ivEXT)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4ivEXT _ptrc_glProgramUniform4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4uiEXT _ptrc_glProgramUniform4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uivEXT _ptrc_glProgramUniform4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dvEXT _ptrc_glProgramUniformMatrix2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fvEXT _ptrc_glProgramUniformMatrix2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dvEXT _ptrc_glProgramUniformMatrix2x3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fvEXT _ptrc_glProgramUniformMatrix2x3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dvEXT _ptrc_glProgramUniformMatrix2x4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fvEXT _ptrc_glProgramUniformMatrix2x4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dvEXT _ptrc_glProgramUniformMatrix3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fvEXT _ptrc_glProgramUniformMatrix3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dvEXT _ptrc_glProgramUniformMatrix3x2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fvEXT _ptrc_glProgramUniformMatrix3x2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dvEXT _ptrc_glProgramUniformMatrix3x4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fvEXT _ptrc_glProgramUniformMatrix3x4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dvEXT _ptrc_glProgramUniformMatrix4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fvEXT _ptrc_glProgramUniformMatrix4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dvEXT _ptrc_glProgramUniformMatrix4x2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fvEXT _ptrc_glProgramUniformMatrix4x2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dvEXT _ptrc_glProgramUniformMatrix4x3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fvEXT _ptrc_glProgramUniformMatrix4x3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttribDefaultEXT)(GLbitfield mask);
#define glPushClientAttribDefaultEXT _ptrc_glPushClientAttribDefaultEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
#define glTextureBufferEXT _ptrc_glTextureBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRangeEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRangeEXT _ptrc_glTextureBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage1DEXT _ptrc_glTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage2DEXT _ptrc_glTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage3DEXT _ptrc_glTextureImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexturePageCommitmentEXT)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#define glTexturePageCommitmentEXT _ptrc_glTexturePageCommitmentEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint * params);
#define glTextureParameterIivEXT _ptrc_glTextureParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, const GLuint * params);
#define glTextureParameterIuivEXT _ptrc_glTextureParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
#define glTextureParameterfEXT _ptrc_glTextureParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, const GLfloat * params);
#define glTextureParameterfvEXT _ptrc_glTextureParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriEXT)(GLuint texture, GLenum target, GLenum pname, GLint param);
#define glTextureParameteriEXT _ptrc_glTextureParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint * params);
#define glTextureParameterivEXT _ptrc_glTextureParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureRenderbufferEXT)(GLuint texture, GLenum target, GLuint renderbuffer);
#define glTextureRenderbufferEXT _ptrc_glTextureRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1DEXT _ptrc_glTextureStorage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2DEXT _ptrc_glTextureStorage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisampleEXT _ptrc_glTextureStorage2DMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3DEXT _ptrc_glTextureStorage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisampleEXT _ptrc_glTextureStorage3DMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1DEXT _ptrc_glTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2DEXT _ptrc_glTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3DEXT _ptrc_glTextureSubImage3DEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBufferEXT)(GLuint buffer);
#define glUnmapNamedBufferEXT _ptrc_glUnmapNamedBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindVertexBufferEXT)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayBindVertexBufferEXT _ptrc_glVertexArrayBindVertexBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayColorOffsetEXT _ptrc_glVertexArrayColorOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayEdgeFlagOffsetEXT)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
#define glVertexArrayEdgeFlagOffsetEXT _ptrc_glVertexArrayEdgeFlagOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayFogCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayFogCoordOffsetEXT _ptrc_glVertexArrayFogCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayIndexOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayIndexOffsetEXT _ptrc_glVertexArrayIndexOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayMultiTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayMultiTexCoordOffsetEXT _ptrc_glVertexArrayMultiTexCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayNormalOffsetEXT)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayNormalOffsetEXT _ptrc_glVertexArrayNormalOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArraySecondaryColorOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArraySecondaryColorOffsetEXT _ptrc_glVertexArraySecondaryColorOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayTexCoordOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayTexCoordOffsetEXT _ptrc_glVertexArrayTexCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribBindingEXT)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayVertexAttribBindingEXT _ptrc_glVertexArrayVertexAttribBindingEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribDivisorEXT)(GLuint vaobj, GLuint index, GLuint divisor);
#define glVertexArrayVertexAttribDivisorEXT _ptrc_glVertexArrayVertexAttribDivisorEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayVertexAttribFormatEXT _ptrc_glVertexArrayVertexAttribFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayVertexAttribIFormatEXT _ptrc_glVertexArrayVertexAttribIFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribIOffsetEXT _ptrc_glVertexArrayVertexAttribIOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayVertexAttribLFormatEXT _ptrc_glVertexArrayVertexAttribLFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribLOffsetEXT _ptrc_glVertexArrayVertexAttribLOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribOffsetEXT _ptrc_glVertexArrayVertexAttribOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBindingDivisorEXT)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayVertexBindingDivisorEXT _ptrc_glVertexArrayVertexBindingDivisorEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexOffsetEXT)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexOffsetEXT _ptrc_glVertexArrayVertexOffsetEXT
#endif /*GL_EXT_direct_state_access*/ 

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMaskIndexedEXT)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#define glColorMaskIndexedEXT _ptrc_glColorMaskIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum target, GLuint index);
#define glDisableIndexedEXT _ptrc_glDisableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum target, GLuint index);
#define glEnableIndexedEXT _ptrc_glEnableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleanIndexedvEXT _ptrc_glGetBooleanIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum target, GLuint index, GLint * data);
#define glGetIntegerIndexedvEXT _ptrc_glGetIntegerIndexedvEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum target, GLuint index);
#define glIsEnabledIndexedEXT _ptrc_glIsEnabledIndexedEXT
#endif /*GL_EXT_draw_buffers2*/ 

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedEXT)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
#define glDrawArraysInstancedEXT _ptrc_glDrawArraysInstancedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedEXT)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#define glDrawElementsInstancedEXT _ptrc_glDrawElementsInstancedEXT
#endif /*GL_EXT_draw_instanced*/ 

#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsEXT)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
#define glDrawRangeElementsEXT _ptrc_glDrawRangeElementsEXT
#endif /*GL_EXT_draw_range_elements*/ 

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerEXT)(GLenum type, GLsizei stride, const void * pointer);
#define glFogCoordPointerEXT _ptrc_glFogCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddEXT)(GLdouble coord);
#define glFogCoorddEXT _ptrc_glFogCoorddEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddvEXT)(const GLdouble * coord);
#define glFogCoorddvEXT _ptrc_glFogCoorddvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfEXT)(GLfloat coord);
#define glFogCoordfEXT _ptrc_glFogCoordfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfvEXT)(const GLfloat * coord);
#define glFogCoordfvEXT _ptrc_glFogCoordfvEXT
#endif /*GL_EXT_fog_coord*/ 

#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebufferEXT)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebufferEXT _ptrc_glBlitFramebufferEXT
#endif /*GL_EXT_framebuffer_blit*/ 

#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleEXT)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleEXT _ptrc_glRenderbufferStorageMultisampleEXT
#endif /*GL_EXT_framebuffer_multisample*/ 


#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebufferEXT)(GLenum target, GLuint framebuffer);
#define glBindFramebufferEXT _ptrc_glBindFramebufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbufferEXT)(GLenum target, GLuint renderbuffer);
#define glBindRenderbufferEXT _ptrc_glBindRenderbufferEXT
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatusEXT)(GLenum target);
#define glCheckFramebufferStatusEXT _ptrc_glCheckFramebufferStatusEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffersEXT)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffersEXT _ptrc_glDeleteFramebuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffersEXT)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffersEXT _ptrc_glDeleteRenderbuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbufferEXT)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbufferEXT _ptrc_glFramebufferRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1DEXT _ptrc_glFramebufferTexture1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2DEXT _ptrc_glFramebufferTexture2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3DEXT _ptrc_glFramebufferTexture3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffersEXT)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffersEXT _ptrc_glGenFramebuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffersEXT)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffersEXT _ptrc_glGenRenderbuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmapEXT)(GLenum target);
#define glGenerateMipmapEXT _ptrc_glGenerateMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameterivEXT)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameterivEXT _ptrc_glGetFramebufferAttachmentParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameterivEXT)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameterivEXT _ptrc_glGetRenderbufferParameterivEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebufferEXT)(GLuint framebuffer);
#define glIsFramebufferEXT _ptrc_glIsFramebufferEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbufferEXT)(GLuint renderbuffer);
#define glIsRenderbufferEXT _ptrc_glIsRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageEXT)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageEXT _ptrc_glRenderbufferStorageEXT
#endif /*GL_EXT_framebuffer_object*/ 


#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriEXT)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteriEXT _ptrc_glProgramParameteriEXT
#endif /*GL_EXT_geometry_shader4*/ 

#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat * params);
#define glProgramEnvParameters4fvEXT _ptrc_glProgramEnvParameters4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat * params);
#define glProgramLocalParameters4fvEXT _ptrc_glProgramLocalParameters4fvEXT
#endif /*GL_EXT_gpu_program_parameters*/ 

#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationEXT)(GLuint program, GLuint color, const GLchar * name);
#define glBindFragDataLocationEXT _ptrc_glBindFragDataLocationEXT
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocationEXT)(GLuint program, const GLchar * name);
#define glGetFragDataLocationEXT _ptrc_glGetFragDataLocationEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuivEXT)(GLuint program, GLint location, GLuint * params);
#define glGetUniformuivEXT _ptrc_glGetUniformuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiEXT)(GLint location, GLuint v0);
#define glUniform1uiEXT _ptrc_glUniform1uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uivEXT)(GLint location, GLsizei count, const GLuint * value);
#define glUniform1uivEXT _ptrc_glUniform1uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiEXT)(GLint location, GLuint v0, GLuint v1);
#define glUniform2uiEXT _ptrc_glUniform2uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uivEXT)(GLint location, GLsizei count, const GLuint * value);
#define glUniform2uivEXT _ptrc_glUniform2uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3uiEXT _ptrc_glUniform3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uivEXT)(GLint location, GLsizei count, const GLuint * value);
#define glUniform3uivEXT _ptrc_glUniform3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4uiEXT _ptrc_glUniform4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uivEXT)(GLint location, GLsizei count, const GLuint * value);
#define glUniform4uivEXT _ptrc_glUniform4uivEXT
#endif /*GL_EXT_gpu_shader4*/ 

#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysEXT)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount);
#define glMultiDrawArraysEXT _ptrc_glMultiDrawArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsEXT)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount);
#define glMultiDrawElementsEXT _ptrc_glMultiDrawElementsEXT
#endif /*GL_EXT_multi_draw_arrays*/ 





#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfEXT)(GLenum pname, GLfloat param);
#define glPointParameterfEXT _ptrc_glPointParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvEXT)(GLenum pname, const GLfloat * params);
#define glPointParameterfvEXT _ptrc_glPointParameterfvEXT
#endif /*GL_EXT_point_parameters*/ 

#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetClampEXT)(GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClampEXT _ptrc_glPolygonOffsetClampEXT
#endif /*GL_EXT_polygon_offset_clamp*/ 

#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertexEXT)(GLenum mode);
#define glProvokingVertexEXT _ptrc_glProvokingVertexEXT
#endif /*GL_EXT_provoking_vertex*/ 


#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bEXT)(GLbyte red, GLbyte green, GLbyte blue);
#define glSecondaryColor3bEXT _ptrc_glSecondaryColor3bEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bvEXT)(const GLbyte * v);
#define glSecondaryColor3bvEXT _ptrc_glSecondaryColor3bvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dEXT)(GLdouble red, GLdouble green, GLdouble blue);
#define glSecondaryColor3dEXT _ptrc_glSecondaryColor3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dvEXT)(const GLdouble * v);
#define glSecondaryColor3dvEXT _ptrc_glSecondaryColor3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fEXT)(GLfloat red, GLfloat green, GLfloat blue);
#define glSecondaryColor3fEXT _ptrc_glSecondaryColor3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fvEXT)(const GLfloat * v);
#define glSecondaryColor3fvEXT _ptrc_glSecondaryColor3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iEXT)(GLint red, GLint green, GLint blue);
#define glSecondaryColor3iEXT _ptrc_glSecondaryColor3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ivEXT)(const GLint * v);
#define glSecondaryColor3ivEXT _ptrc_glSecondaryColor3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sEXT)(GLshort red, GLshort green, GLshort blue);
#define glSecondaryColor3sEXT _ptrc_glSecondaryColor3sEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3svEXT)(const GLshort * v);
#define glSecondaryColor3svEXT _ptrc_glSecondaryColor3svEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubEXT)(GLubyte red, GLubyte green, GLubyte blue);
#define glSecondaryColor3ubEXT _ptrc_glSecondaryColor3ubEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubvEXT)(const GLubyte * v);
#define glSecondaryColor3ubvEXT _ptrc_glSecondaryColor3ubvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiEXT)(GLuint red, GLuint green, GLuint blue);
#define glSecondaryColor3uiEXT _ptrc_glSecondaryColor3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uivEXT)(const GLuint * v);
#define glSecondaryColor3uivEXT _ptrc_glSecondaryColor3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usEXT)(GLushort red, GLushort green, GLushort blue);
#define glSecondaryColor3usEXT _ptrc_glSecondaryColor3usEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usvEXT)(const GLushort * v);
#define glSecondaryColor3usvEXT _ptrc_glSecondaryColor3usvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerEXT)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glSecondaryColorPointerEXT _ptrc_glSecondaryColorPointerEXT
#endif /*GL_EXT_secondary_color*/ 

#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveProgramEXT)(GLuint program);
#define glActiveProgramEXT _ptrc_glActiveProgramEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramEXT)(GLenum type, const GLchar * string);
#define glCreateShaderProgramEXT _ptrc_glCreateShaderProgramEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUseShaderProgramEXT)(GLenum type, GLuint program);
#define glUseShaderProgramEXT _ptrc_glUseShaderProgramEXT
#endif /*GL_EXT_separate_shader_objects*/ 


#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextureEXT)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
#define glBindImageTextureEXT _ptrc_glBindImageTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierEXT)(GLbitfield barriers);
#define glMemoryBarrierEXT _ptrc_glMemoryBarrierEXT
#endif /*GL_EXT_shader_image_load_store*/ 



#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveStencilFaceEXT)(GLenum face);
#define glActiveStencilFaceEXT _ptrc_glActiveStencilFaceEXT
#endif /*GL_EXT_stencil_two_side*/ 


#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DEXT)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage3DEXT _ptrc_glTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3DEXT)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage3DEXT _ptrc_glTexSubImage3DEXT
#endif /*GL_EXT_texture3D*/ 

#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerEXT)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayerEXT _ptrc_glFramebufferTextureLayerEXT
#endif /*GL_EXT_texture_array*/ 

#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferEXT)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBufferEXT _ptrc_glTexBufferEXT
#endif /*GL_EXT_texture_buffer_object*/ 








#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColorIiEXT)(GLint red, GLint green, GLint blue, GLint alpha);
#define glClearColorIiEXT _ptrc_glClearColorIiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColorIuiEXT)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glClearColorIuiEXT _ptrc_glClearColorIuiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIivEXT)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameterIivEXT _ptrc_glGetTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuivEXT)(GLenum target, GLenum pname, GLuint * params);
#define glGetTexParameterIuivEXT _ptrc_glGetTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIivEXT)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameterIivEXT _ptrc_glTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuivEXT)(GLenum target, GLenum pname, const GLuint * params);
#define glTexParameterIuivEXT _ptrc_glTexParameterIuivEXT
#endif /*GL_EXT_texture_integer*/ 



#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResidentEXT)(GLsizei n, const GLuint * textures, GLboolean * residences);
#define glAreTexturesResidentEXT _ptrc_glAreTexturesResidentEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextureEXT)(GLenum target, GLuint texture);
#define glBindTextureEXT _ptrc_glBindTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTexturesEXT)(GLsizei n, const GLuint * textures);
#define glDeleteTexturesEXT _ptrc_glDeleteTexturesEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTexturesEXT)(GLsizei n, GLuint * textures);
#define glGenTexturesEXT _ptrc_glGenTexturesEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureEXT)(GLuint texture);
#define glIsTextureEXT _ptrc_glIsTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesEXT)(GLsizei n, const GLuint * textures, const GLclampf * priorities);
#define glPrioritizeTexturesEXT _ptrc_glPrioritizeTexturesEXT
#endif /*GL_EXT_texture_object*/ 





#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64vEXT)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64vEXT _ptrc_glGetQueryObjecti64vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64vEXT)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64vEXT _ptrc_glGetQueryObjectui64vEXT
#endif /*GL_EXT_timer_query*/ 

#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glArrayElementEXT)(GLint i);
#define glArrayElementEXT _ptrc_glArrayElementEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glColorPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#define glColorPointerEXT _ptrc_glColorPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysEXT)(GLenum mode, GLint first, GLsizei count);
#define glDrawArraysEXT _ptrc_glDrawArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerEXT)(GLsizei stride, GLsizei count, const GLboolean * pointer);
#define glEdgeFlagPointerEXT _ptrc_glEdgeFlagPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointervEXT)(GLenum pname, void ** params);
#define glGetPointervEXT _ptrc_glGetPointervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#define glIndexPointerEXT _ptrc_glIndexPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#define glNormalPointerEXT _ptrc_glNormalPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#define glTexCoordPointerEXT _ptrc_glTexCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
#define glVertexPointerEXT _ptrc_glVertexPointerEXT
#endif /*GL_EXT_vertex_array*/ 


#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdvEXT)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdvEXT _ptrc_glGetVertexAttribLdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dEXT)(GLuint index, GLdouble x);
#define glVertexAttribL1dEXT _ptrc_glVertexAttribL1dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dvEXT)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dvEXT _ptrc_glVertexAttribL1dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dEXT)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2dEXT _ptrc_glVertexAttribL2dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dvEXT)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dvEXT _ptrc_glVertexAttribL2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3dEXT _ptrc_glVertexAttribL3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dvEXT)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dvEXT _ptrc_glVertexAttribL3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4dEXT _ptrc_glVertexAttribL4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dvEXT)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dvEXT _ptrc_glVertexAttribL4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointerEXT)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointerEXT _ptrc_glVertexAttribLPointerEXT
#endif /*GL_EXT_vertex_attrib_64bit*/ 




#ifndef GL_KHR_debug
#define GL_KHR_debug 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback _ptrc_glDebugMessageCallback
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl _ptrc_glDebugMessageControl
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert _ptrc_glDebugMessageInsert
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog _ptrc_glGetDebugMessageLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel _ptrc_glGetObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel _ptrc_glGetObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum pname, void ** params);
#define glGetPointerv _ptrc_glGetPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel _ptrc_glObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel _ptrc_glObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)(void);
#define glPopDebugGroup _ptrc_glPopDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup _ptrc_glPushDebugGroup
#endif /*GL_KHR_debug*/ 



#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatus)(void);
#define glGetGraphicsResetStatus _ptrc_glGetGraphicsResetStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv _ptrc_glGetnUniformfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv _ptrc_glGetnUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv _ptrc_glGetnUniformuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels _ptrc_glReadnPixels
#endif /*GL_KHR_robustness*/ 

#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessNV)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawArraysIndirectBindlessNV _ptrc_glMultiDrawArraysIndirectBindlessNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessNV)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawElementsIndirectBindlessNV _ptrc_glMultiDrawElementsIndirectBindlessNV
#endif /*GL_NV_bindless_multi_draw_indirect*/ 

#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessCountNV)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawArraysIndirectBindlessCountNV _ptrc_glMultiDrawArraysIndirectBindlessCountNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessCountNV)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawElementsIndirectBindlessCountNV _ptrc_glMultiDrawElementsIndirectBindlessCountNV
#endif /*GL_NV_bindless_multi_draw_indirect_count*/ 

#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierNV)(void);
#define glBlendBarrierNV _ptrc_glBlendBarrierNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendParameteriNV)(GLenum pname, GLint value);
#define glBlendParameteriNV _ptrc_glBlendParameteriNV
#endif /*GL_NV_blend_equation_advanced*/ 


#ifndef GL_NV_command_list
#define GL_NV_command_list 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCallCommandListNV)(GLuint list);
#define glCallCommandListNV _ptrc_glCallCommandListNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCommandListSegmentsNV)(GLuint list, GLuint segments);
#define glCommandListSegmentsNV _ptrc_glCommandListSegmentsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileCommandListNV)(GLuint list);
#define glCompileCommandListNV _ptrc_glCompileCommandListNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateCommandListsNV)(GLsizei n, GLuint * lists);
#define glCreateCommandListsNV _ptrc_glCreateCommandListsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateStatesNV)(GLsizei n, GLuint * states);
#define glCreateStatesNV _ptrc_glCreateStatesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteCommandListsNV)(GLsizei n, const GLuint * lists);
#define glDeleteCommandListsNV _ptrc_glDeleteCommandListsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteStatesNV)(GLsizei n, const GLuint * states);
#define glDeleteStatesNV _ptrc_glDeleteStatesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsAddressNV)(GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count);
#define glDrawCommandsAddressNV _ptrc_glDrawCommandsAddressNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsNV)(GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count);
#define glDrawCommandsNV _ptrc_glDrawCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsStatesAddressNV)(const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glDrawCommandsStatesAddressNV _ptrc_glDrawCommandsStatesAddressNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawCommandsStatesNV)(GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glDrawCommandsStatesNV _ptrc_glDrawCommandsStatesNV
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetCommandHeaderNV)(GLenum tokenID, GLuint size);
#define glGetCommandHeaderNV _ptrc_glGetCommandHeaderNV
extern GLushort (CODEGEN_FUNCPTR *_ptrc_glGetStageIndexNV)(GLenum shadertype);
#define glGetStageIndexNV _ptrc_glGetStageIndexNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsCommandListNV)(GLuint list);
#define glIsCommandListNV _ptrc_glIsCommandListNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsStateNV)(GLuint state);
#define glIsStateNV _ptrc_glIsStateNV
extern void (CODEGEN_FUNCPTR *_ptrc_glListDrawCommandsStatesClientNV)(GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glListDrawCommandsStatesClientNV _ptrc_glListDrawCommandsStatesClientNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStateCaptureNV)(GLuint state, GLenum mode);
#define glStateCaptureNV _ptrc_glStateCaptureNV
#endif /*GL_NV_command_list*/ 


#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNV)(GLuint id, GLenum mode);
#define glBeginConditionalRenderNV _ptrc_glBeginConditionalRenderNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNV)(void);
#define glEndConditionalRenderNV _ptrc_glEndConditionalRenderNV
#endif /*GL_NV_conditional_render*/ 


#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubDataNV)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#define glCopyImageSubDataNV _ptrc_glCopyImageSubDataNV
#endif /*GL_NV_copy_image*/ 

#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthdNV)(GLdouble depth);
#define glClearDepthdNV _ptrc_glClearDepthdNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsdNV)(GLdouble zmin, GLdouble zmax);
#define glDepthBoundsdNV _ptrc_glDepthBoundsdNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangedNV)(GLdouble zNear, GLdouble zFar);
#define glDepthRangedNV _ptrc_glDepthRangedNV
#endif /*GL_NV_depth_buffer_float*/ 


#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTextureNV)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#define glDrawTextureNV _ptrc_glDrawTextureNV
#endif /*GL_NV_draw_texture*/ 

#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefvNV)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefvNV _ptrc_glGetMultisamplefvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskIndexedNV)(GLuint index, GLbitfield mask);
#define glSampleMaskIndexedNV _ptrc_glSampleMaskIndexedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexRenderbufferNV)(GLenum target, GLuint renderbuffer);
#define glTexRenderbufferNV _ptrc_glTexRenderbufferNV
#endif /*GL_NV_explicit_multisample*/ 

#ifndef GL_NV_fence
#define GL_NV_fence 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesNV)(GLsizei n, const GLuint * fences);
#define glDeleteFencesNV _ptrc_glDeleteFencesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceNV)(GLuint fence);
#define glFinishFenceNV _ptrc_glFinishFenceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFencesNV)(GLsizei n, GLuint * fences);
#define glGenFencesNV _ptrc_glGenFencesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFenceivNV)(GLuint fence, GLenum pname, GLint * params);
#define glGetFenceivNV _ptrc_glGetFenceivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceNV)(GLuint fence);
#define glIsFenceNV _ptrc_glIsFenceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSetFenceNV)(GLuint fence, GLenum condition);
#define glSetFenceNV _ptrc_glSetFenceNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceNV)(GLuint fence);
#define glTestFenceNV _ptrc_glTestFenceNV
#endif /*GL_NV_fence*/ 



#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterdvNV)(GLuint id, GLsizei len, const GLubyte * name, GLdouble * params);
#define glGetProgramNamedParameterdvNV _ptrc_glGetProgramNamedParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterfvNV)(GLuint id, GLsizei len, const GLubyte * name, GLfloat * params);
#define glGetProgramNamedParameterfvNV _ptrc_glGetProgramNamedParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dNV)(GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramNamedParameter4dNV _ptrc_glProgramNamedParameter4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dvNV)(GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v);
#define glProgramNamedParameter4dvNV _ptrc_glProgramNamedParameter4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fNV)(GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramNamedParameter4fNV _ptrc_glProgramNamedParameter4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fvNV)(GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v);
#define glProgramNamedParameter4fvNV _ptrc_glProgramNamedParameter4fvNV
#endif /*GL_NV_fragment_program*/ 



#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleCoverageNV _ptrc_glRenderbufferStorageMultisampleCoverageNV
#endif /*GL_NV_framebuffer_multisample_coverage*/ 


#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIivNV)(GLenum target, GLuint index, GLint * params);
#define glGetProgramEnvParameterIivNV _ptrc_glGetProgramEnvParameterIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIuivNV)(GLenum target, GLuint index, GLuint * params);
#define glGetProgramEnvParameterIuivNV _ptrc_glGetProgramEnvParameterIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIivNV)(GLenum target, GLuint index, GLint * params);
#define glGetProgramLocalParameterIivNV _ptrc_glGetProgramLocalParameterIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIuivNV)(GLenum target, GLuint index, GLuint * params);
#define glGetProgramLocalParameterIuivNV _ptrc_glGetProgramLocalParameterIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glProgramEnvParameterI4iNV _ptrc_glProgramEnvParameterI4iNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4ivNV)(GLenum target, GLuint index, const GLint * params);
#define glProgramEnvParameterI4ivNV _ptrc_glProgramEnvParameterI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glProgramEnvParameterI4uiNV _ptrc_glProgramEnvParameterI4uiNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uivNV)(GLenum target, GLuint index, const GLuint * params);
#define glProgramEnvParameterI4uivNV _ptrc_glProgramEnvParameterI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint * params);
#define glProgramEnvParametersI4ivNV _ptrc_glProgramEnvParametersI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint * params);
#define glProgramEnvParametersI4uivNV _ptrc_glProgramEnvParametersI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glProgramLocalParameterI4iNV _ptrc_glProgramLocalParameterI4iNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4ivNV)(GLenum target, GLuint index, const GLint * params);
#define glProgramLocalParameterI4ivNV _ptrc_glProgramLocalParameterI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glProgramLocalParameterI4uiNV _ptrc_glProgramLocalParameterI4uiNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uivNV)(GLenum target, GLuint index, const GLuint * params);
#define glProgramLocalParameterI4uivNV _ptrc_glProgramLocalParameterI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint * params);
#define glProgramLocalParametersI4ivNV _ptrc_glProgramLocalParametersI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint * params);
#define glProgramLocalParametersI4uivNV _ptrc_glProgramLocalParametersI4uivNV
#endif /*GL_NV_gpu_program4*/ 

#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformatSampleivNV)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint * params);
#define glGetInternalformatSampleivNV _ptrc_glGetInternalformatSampleivNV
#endif /*GL_NV_internalformat_sample_query*/ 

#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramSubroutineParameteruivNV)(GLenum target, GLuint index, GLuint * param);
#define glGetProgramSubroutineParameteruivNV _ptrc_glGetProgramSubroutineParameteruivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramSubroutineParametersuivNV)(GLenum target, GLsizei count, const GLuint * params);
#define glProgramSubroutineParametersuivNV _ptrc_glProgramSubroutineParametersuivNV
#endif /*GL_NV_gpu_program5*/ 


#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vNV)(GLuint program, GLint location, GLint64EXT * params);
#define glGetUniformi64vNV _ptrc_glGetUniformi64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64NV)(GLuint program, GLint location, GLint64EXT x);
#define glProgramUniform1i64NV _ptrc_glProgramUniform1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform1i64vNV _ptrc_glProgramUniform1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64NV)(GLuint program, GLint location, GLuint64EXT x);
#define glProgramUniform1ui64NV _ptrc_glProgramUniform1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform1ui64vNV _ptrc_glProgramUniform1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
#define glProgramUniform2i64NV _ptrc_glProgramUniform2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform2i64vNV _ptrc_glProgramUniform2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
#define glProgramUniform2ui64NV _ptrc_glProgramUniform2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform2ui64vNV _ptrc_glProgramUniform2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glProgramUniform3i64NV _ptrc_glProgramUniform3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform3i64vNV _ptrc_glProgramUniform3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glProgramUniform3ui64NV _ptrc_glProgramUniform3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform3ui64vNV _ptrc_glProgramUniform3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glProgramUniform4i64NV _ptrc_glProgramUniform4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform4i64vNV _ptrc_glProgramUniform4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glProgramUniform4ui64NV _ptrc_glProgramUniform4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform4ui64vNV _ptrc_glProgramUniform4ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64NV)(GLint location, GLint64EXT x);
#define glUniform1i64NV _ptrc_glUniform1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vNV)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform1i64vNV _ptrc_glUniform1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64NV)(GLint location, GLuint64EXT x);
#define glUniform1ui64NV _ptrc_glUniform1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform1ui64vNV _ptrc_glUniform1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64NV)(GLint location, GLint64EXT x, GLint64EXT y);
#define glUniform2i64NV _ptrc_glUniform2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vNV)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform2i64vNV _ptrc_glUniform2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y);
#define glUniform2ui64NV _ptrc_glUniform2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform2ui64vNV _ptrc_glUniform2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glUniform3i64NV _ptrc_glUniform3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vNV)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform3i64vNV _ptrc_glUniform3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glUniform3ui64NV _ptrc_glUniform3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform3ui64vNV _ptrc_glUniform3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glUniform4i64NV _ptrc_glUniform4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vNV)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform4i64vNV _ptrc_glUniform4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glUniform4ui64NV _ptrc_glUniform4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform4ui64vNV _ptrc_glUniform4ui64vNV
#endif /*GL_NV_gpu_shader5*/ 

#ifndef GL_NV_half_float
#define GL_NV_half_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
#define glColor3hNV _ptrc_glColor3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3hvNV)(const GLhalfNV * v);
#define glColor3hvNV _ptrc_glColor3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
#define glColor4hNV _ptrc_glColor4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4hvNV)(const GLhalfNV * v);
#define glColor4hvNV _ptrc_glColor4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhNV)(GLhalfNV fog);
#define glFogCoordhNV _ptrc_glFogCoordhNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhvNV)(const GLhalfNV * fog);
#define glFogCoordhvNV _ptrc_glFogCoordhvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hNV)(GLenum target, GLhalfNV s);
#define glMultiTexCoord1hNV _ptrc_glMultiTexCoord1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hvNV)(GLenum target, const GLhalfNV * v);
#define glMultiTexCoord1hvNV _ptrc_glMultiTexCoord1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hNV)(GLenum target, GLhalfNV s, GLhalfNV t);
#define glMultiTexCoord2hNV _ptrc_glMultiTexCoord2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hvNV)(GLenum target, const GLhalfNV * v);
#define glMultiTexCoord2hvNV _ptrc_glMultiTexCoord2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
#define glMultiTexCoord3hNV _ptrc_glMultiTexCoord3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hvNV)(GLenum target, const GLhalfNV * v);
#define glMultiTexCoord3hvNV _ptrc_glMultiTexCoord3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
#define glMultiTexCoord4hNV _ptrc_glMultiTexCoord4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hvNV)(GLenum target, const GLhalfNV * v);
#define glMultiTexCoord4hvNV _ptrc_glMultiTexCoord4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3hNV)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
#define glNormal3hNV _ptrc_glNormal3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3hvNV)(const GLhalfNV * v);
#define glNormal3hvNV _ptrc_glNormal3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
#define glSecondaryColor3hNV _ptrc_glSecondaryColor3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hvNV)(const GLhalfNV * v);
#define glSecondaryColor3hvNV _ptrc_glSecondaryColor3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hNV)(GLhalfNV s);
#define glTexCoord1hNV _ptrc_glTexCoord1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hvNV)(const GLhalfNV * v);
#define glTexCoord1hvNV _ptrc_glTexCoord1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hNV)(GLhalfNV s, GLhalfNV t);
#define glTexCoord2hNV _ptrc_glTexCoord2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hvNV)(const GLhalfNV * v);
#define glTexCoord2hvNV _ptrc_glTexCoord2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r);
#define glTexCoord3hNV _ptrc_glTexCoord3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hvNV)(const GLhalfNV * v);
#define glTexCoord3hvNV _ptrc_glTexCoord3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
#define glTexCoord4hNV _ptrc_glTexCoord4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hvNV)(const GLhalfNV * v);
#define glTexCoord4hvNV _ptrc_glTexCoord4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2hNV)(GLhalfNV x, GLhalfNV y);
#define glVertex2hNV _ptrc_glVertex2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2hvNV)(const GLhalfNV * v);
#define glVertex2hvNV _ptrc_glVertex2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z);
#define glVertex3hNV _ptrc_glVertex3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3hvNV)(const GLhalfNV * v);
#define glVertex3hvNV _ptrc_glVertex3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
#define glVertex4hNV _ptrc_glVertex4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4hvNV)(const GLhalfNV * v);
#define glVertex4hvNV _ptrc_glVertex4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hNV)(GLuint index, GLhalfNV x);
#define glVertexAttrib1hNV _ptrc_glVertexAttrib1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hvNV)(GLuint index, const GLhalfNV * v);
#define glVertexAttrib1hvNV _ptrc_glVertexAttrib1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hNV)(GLuint index, GLhalfNV x, GLhalfNV y);
#define glVertexAttrib2hNV _ptrc_glVertexAttrib2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hvNV)(GLuint index, const GLhalfNV * v);
#define glVertexAttrib2hvNV _ptrc_glVertexAttrib2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
#define glVertexAttrib3hNV _ptrc_glVertexAttrib3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hvNV)(GLuint index, const GLhalfNV * v);
#define glVertexAttrib3hvNV _ptrc_glVertexAttrib3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
#define glVertexAttrib4hNV _ptrc_glVertexAttrib4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hvNV)(GLuint index, const GLhalfNV * v);
#define glVertexAttrib4hvNV _ptrc_glVertexAttrib4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1hvNV)(GLuint index, GLsizei n, const GLhalfNV * v);
#define glVertexAttribs1hvNV _ptrc_glVertexAttribs1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2hvNV)(GLuint index, GLsizei n, const GLhalfNV * v);
#define glVertexAttribs2hvNV _ptrc_glVertexAttribs2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3hvNV)(GLuint index, GLsizei n, const GLhalfNV * v);
#define glVertexAttribs3hvNV _ptrc_glVertexAttribs3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4hvNV)(GLuint index, GLsizei n, const GLhalfNV * v);
#define glVertexAttribs4hvNV _ptrc_glVertexAttribs4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthNV)(GLhalfNV weight);
#define glVertexWeighthNV _ptrc_glVertexWeighthNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthvNV)(const GLhalfNV * weight);
#define glVertexWeighthvNV _ptrc_glVertexWeighthvNV
#endif /*GL_NV_half_float*/ 




#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginOcclusionQueryNV)(GLuint id);
#define glBeginOcclusionQueryNV _ptrc_glBeginOcclusionQueryNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteOcclusionQueriesNV)(GLsizei n, const GLuint * ids);
#define glDeleteOcclusionQueriesNV _ptrc_glDeleteOcclusionQueriesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndOcclusionQueryNV)(void);
#define glEndOcclusionQueryNV _ptrc_glEndOcclusionQueryNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenOcclusionQueriesNV)(GLsizei n, GLuint * ids);
#define glGenOcclusionQueriesNV _ptrc_glGenOcclusionQueriesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryivNV)(GLuint id, GLenum pname, GLint * params);
#define glGetOcclusionQueryivNV _ptrc_glGetOcclusionQueryivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryuivNV)(GLuint id, GLenum pname, GLuint * params);
#define glGetOcclusionQueryuivNV _ptrc_glGetOcclusionQueryuivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsOcclusionQueryNV)(GLuint id);
#define glIsOcclusionQueryNV _ptrc_glIsOcclusionQueryNV
#endif /*GL_NV_occlusion_query*/ 


#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIivNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint * params);
#define glProgramBufferParametersIivNV _ptrc_glProgramBufferParametersIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIuivNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint * params);
#define glProgramBufferParametersIuivNV _ptrc_glProgramBufferParametersIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersfvNV)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat * params);
#define glProgramBufferParametersfvNV _ptrc_glProgramBufferParametersfvNV
#endif /*GL_NV_parameter_buffer_object*/ 


#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyPathNV)(GLuint resultPath, GLuint srcPath);
#define glCopyPathNV _ptrc_glCopyPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glCoverFillPathInstancedNV _ptrc_glCoverFillPathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathNV)(GLuint path, GLenum coverMode);
#define glCoverFillPathNV _ptrc_glCoverFillPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glCoverStrokePathInstancedNV _ptrc_glCoverStrokePathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathNV)(GLuint path, GLenum coverMode);
#define glCoverStrokePathNV _ptrc_glCoverStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeletePathsNV)(GLuint path, GLsizei range);
#define glDeletePathsNV _ptrc_glDeletePathsNV
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenPathsNV)(GLsizei range);
#define glGenPathsNV _ptrc_glGenPathsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenfvNV)(GLenum color, GLenum pname, GLfloat * value);
#define glGetPathColorGenfvNV _ptrc_glGetPathColorGenfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenivNV)(GLenum color, GLenum pname, GLint * value);
#define glGetPathColorGenivNV _ptrc_glGetPathColorGenivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathCommandsNV)(GLuint path, GLubyte * commands);
#define glGetPathCommandsNV _ptrc_glGetPathCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathCoordsNV)(GLuint path, GLfloat * coords);
#define glGetPathCoordsNV _ptrc_glGetPathCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathDashArrayNV)(GLuint path, GLfloat * dashArray);
#define glGetPathDashArrayNV _ptrc_glGetPathDashArrayNV
extern GLfloat (CODEGEN_FUNCPTR *_ptrc_glGetPathLengthNV)(GLuint path, GLsizei startSegment, GLsizei numSegments);
#define glGetPathLengthNV _ptrc_glGetPathLengthNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricRangeNV)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics);
#define glGetPathMetricRangeNV _ptrc_glGetPathMetricRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricsNV)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics);
#define glGetPathMetricsNV _ptrc_glGetPathMetricsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterfvNV)(GLuint path, GLenum pname, GLfloat * value);
#define glGetPathParameterfvNV _ptrc_glGetPathParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterivNV)(GLuint path, GLenum pname, GLint * value);
#define glGetPathParameterivNV _ptrc_glGetPathParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathSpacingNV)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing);
#define glGetPathSpacingNV _ptrc_glGetPathSpacingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenfvNV)(GLenum texCoordSet, GLenum pname, GLfloat * value);
#define glGetPathTexGenfvNV _ptrc_glGetPathTexGenfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenivNV)(GLenum texCoordSet, GLenum pname, GLint * value);
#define glGetPathTexGenivNV _ptrc_glGetPathTexGenivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourcefvNV)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLfloat * params);
#define glGetProgramResourcefvNV _ptrc_glGetProgramResourcefvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glInterpolatePathsNV)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
#define glInterpolatePathsNV _ptrc_glInterpolatePathsNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPathNV)(GLuint path);
#define glIsPathNV _ptrc_glIsPathNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInFillPathNV)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
#define glIsPointInFillPathNV _ptrc_glIsPointInFillPathNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInStrokePathNV)(GLuint path, GLfloat x, GLfloat y);
#define glIsPointInStrokePathNV _ptrc_glIsPointInStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoad3x2fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoad3x2fNV _ptrc_glMatrixLoad3x2fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoad3x3fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoad3x3fNV _ptrc_glMatrixLoad3x3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTranspose3x3fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoadTranspose3x3fNV _ptrc_glMatrixLoadTranspose3x3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMult3x2fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMult3x2fNV _ptrc_glMatrixMult3x2fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMult3x3fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMult3x3fNV _ptrc_glMatrixMult3x3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTranspose3x3fNV)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMultTranspose3x3fNV _ptrc_glMatrixMultTranspose3x3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathColorGenNV)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat * coeffs);
#define glPathColorGenNV _ptrc_glPathColorGenNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCommandsNV)(GLuint path, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathCommandsNV _ptrc_glPathCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCoordsNV)(GLuint path, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathCoordsNV _ptrc_glPathCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCoverDepthFuncNV)(GLenum func);
#define glPathCoverDepthFuncNV _ptrc_glPathCoverDepthFuncNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathDashArrayNV)(GLuint path, GLsizei dashCount, const GLfloat * dashArray);
#define glPathDashArrayNV _ptrc_glPathDashArrayNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathFogGenNV)(GLenum genMode);
#define glPathFogGenNV _ptrc_glPathFogGenNV
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glPathGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphIndexArrayNV _ptrc_glPathGlyphIndexArrayNV
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glPathGlyphIndexRangeNV)(GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount);
#define glPathGlyphIndexRangeNV _ptrc_glPathGlyphIndexRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphRangeNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphRangeNV _ptrc_glPathGlyphRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphsNV)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void * charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphsNV _ptrc_glPathGlyphsNV
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glPathMemoryGlyphIndexArrayNV)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void * fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathMemoryGlyphIndexArrayNV _ptrc_glPathMemoryGlyphIndexArrayNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfNV)(GLuint path, GLenum pname, GLfloat value);
#define glPathParameterfNV _ptrc_glPathParameterfNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfvNV)(GLuint path, GLenum pname, const GLfloat * value);
#define glPathParameterfvNV _ptrc_glPathParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameteriNV)(GLuint path, GLenum pname, GLint value);
#define glPathParameteriNV _ptrc_glPathParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterivNV)(GLuint path, GLenum pname, const GLint * value);
#define glPathParameterivNV _ptrc_glPathParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStencilDepthOffsetNV)(GLfloat factor, GLfloat units);
#define glPathStencilDepthOffsetNV _ptrc_glPathStencilDepthOffsetNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStencilFuncNV)(GLenum func, GLint ref, GLuint mask);
#define glPathStencilFuncNV _ptrc_glPathStencilFuncNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStringNV)(GLuint path, GLenum format, GLsizei length, const void * pathString);
#define glPathStringNV _ptrc_glPathStringNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathSubCommandsNV)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathSubCommandsNV _ptrc_glPathSubCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathSubCoordsNV)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathSubCoordsNV _ptrc_glPathSubCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathTexGenNV)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat * coeffs);
#define glPathTexGenNV _ptrc_glPathTexGenNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glPointAlongPathNV)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat * x, GLfloat * y, GLfloat * tangentX, GLfloat * tangentY);
#define glPointAlongPathNV _ptrc_glPointAlongPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramPathFragmentInputGenNV)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat * coeffs);
#define glProgramPathFragmentInputGenNV _ptrc_glProgramPathFragmentInputGenNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues);
#define glStencilFillPathInstancedNV _ptrc_glStencilFillPathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathNV)(GLuint path, GLenum fillMode, GLuint mask);
#define glStencilFillPathNV _ptrc_glStencilFillPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues);
#define glStencilStrokePathInstancedNV _ptrc_glStencilStrokePathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathNV)(GLuint path, GLint reference, GLuint mask);
#define glStencilStrokePathNV _ptrc_glStencilStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glStencilThenCoverFillPathInstancedNV _ptrc_glStencilThenCoverFillPathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverFillPathNV)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
#define glStencilThenCoverFillPathNV _ptrc_glStencilThenCoverFillPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glStencilThenCoverStrokePathInstancedNV _ptrc_glStencilThenCoverStrokePathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilThenCoverStrokePathNV)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
#define glStencilThenCoverStrokePathNV _ptrc_glStencilThenCoverStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformPathNV)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat * transformValues);
#define glTransformPathNV _ptrc_glTransformPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightPathsNV)(GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights);
#define glWeightPathsNV _ptrc_glWeightPathsNV
#endif /*GL_NV_path_rendering*/ 

#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushPixelDataRangeNV)(GLenum target);
#define glFlushPixelDataRangeNV _ptrc_glFlushPixelDataRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelDataRangeNV)(GLenum target, GLsizei length, const void * pointer);
#define glPixelDataRangeNV _ptrc_glPixelDataRangeNV
#endif /*GL_NV_pixel_data_range*/ 

#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriNV)(GLenum pname, GLint param);
#define glPointParameteriNV _ptrc_glPointParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterivNV)(GLenum pname, const GLint * params);
#define glPointParameterivNV _ptrc_glPointParameterivNV
#endif /*GL_NV_point_sprite*/ 

#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndexNV)(GLuint index);
#define glPrimitiveRestartIndexNV _ptrc_glPrimitiveRestartIndexNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartNV)(void);
#define glPrimitiveRestartNV _ptrc_glPrimitiveRestartNV
#endif /*GL_NV_primitive_restart*/ 

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerInputNV)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
#define glCombinerInputNV _ptrc_glCombinerInputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerOutputNV)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
#define glCombinerOutputNV _ptrc_glCombinerOutputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfNV)(GLenum pname, GLfloat param);
#define glCombinerParameterfNV _ptrc_glCombinerParameterfNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfvNV)(GLenum pname, const GLfloat * params);
#define glCombinerParameterfvNV _ptrc_glCombinerParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameteriNV)(GLenum pname, GLint param);
#define glCombinerParameteriNV _ptrc_glCombinerParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterivNV)(GLenum pname, const GLint * params);
#define glCombinerParameterivNV _ptrc_glCombinerParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFinalCombinerInputNV)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
#define glFinalCombinerInputNV _ptrc_glFinalCombinerInputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterfvNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params);
#define glGetCombinerInputParameterfvNV _ptrc_glGetCombinerInputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterivNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params);
#define glGetCombinerInputParameterivNV _ptrc_glGetCombinerInputParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterfvNV)(GLenum stage, GLenum portion, GLenum pname, GLfloat * params);
#define glGetCombinerOutputParameterfvNV _ptrc_glGetCombinerOutputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterivNV)(GLenum stage, GLenum portion, GLenum pname, GLint * params);
#define glGetCombinerOutputParameterivNV _ptrc_glGetCombinerOutputParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterfvNV)(GLenum variable, GLenum pname, GLfloat * params);
#define glGetFinalCombinerInputParameterfvNV _ptrc_glGetFinalCombinerInputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterivNV)(GLenum variable, GLenum pname, GLint * params);
#define glGetFinalCombinerInputParameterivNV _ptrc_glGetFinalCombinerInputParameterivNV
#endif /*GL_NV_register_combiners*/ 

#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerStageParameterfvNV)(GLenum stage, GLenum pname, const GLfloat * params);
#define glCombinerStageParameterfvNV _ptrc_glCombinerStageParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerStageParameterfvNV)(GLenum stage, GLenum pname, GLfloat * params);
#define glGetCombinerStageParameterfvNV _ptrc_glGetCombinerStageParameterfvNV
#endif /*GL_NV_register_combiners2*/ 



#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterui64vNV)(GLenum target, GLenum pname, GLuint64EXT * params);
#define glGetBufferParameterui64vNV _ptrc_glGetBufferParameterui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64vNV)(GLenum value, GLuint64EXT * result);
#define glGetIntegerui64vNV _ptrc_glGetIntegerui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterui64vNV)(GLuint buffer, GLenum pname, GLuint64EXT * params);
#define glGetNamedBufferParameterui64vNV _ptrc_glGetNamedBufferParameterui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vNV)(GLuint program, GLint location, GLuint64EXT * params);
#define glGetUniformui64vNV _ptrc_glGetUniformui64vNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferResidentNV)(GLenum target);
#define glIsBufferResidentNV _ptrc_glIsBufferResidentNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedBufferResidentNV)(GLuint buffer);
#define glIsNamedBufferResidentNV _ptrc_glIsNamedBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferNonResidentNV)(GLenum target);
#define glMakeBufferNonResidentNV _ptrc_glMakeBufferNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferResidentNV)(GLenum target, GLenum access);
#define glMakeBufferResidentNV _ptrc_glMakeBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferNonResidentNV)(GLuint buffer);
#define glMakeNamedBufferNonResidentNV _ptrc_glMakeNamedBufferNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferResidentNV)(GLuint buffer, GLenum access);
#define glMakeNamedBufferResidentNV _ptrc_glMakeNamedBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64NV)(GLuint program, GLint location, GLuint64EXT value);
#define glProgramUniformui64NV _ptrc_glProgramUniformui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniformui64vNV _ptrc_glProgramUniformui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformui64NV)(GLint location, GLuint64EXT value);
#define glUniformui64NV _ptrc_glUniformui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformui64vNV)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniformui64vNV _ptrc_glUniformui64vNV
#endif /*GL_NV_shader_buffer_load*/ 



#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrierNV)(void);
#define glTextureBarrierNV _ptrc_glTextureBarrierNV
#endif /*GL_NV_texture_barrier*/ 



#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
#define glTexImage2DMultisampleCoverageNV _ptrc_glTexImage2DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
#define glTexImage3DMultisampleCoverageNV _ptrc_glTexImage3DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
#define glTextureImage2DMultisampleCoverageNV _ptrc_glTextureImage2DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
#define glTextureImage2DMultisampleNV _ptrc_glTextureImage2DMultisampleNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
#define glTextureImage3DMultisampleCoverageNV _ptrc_glTextureImage3DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
#define glTextureImage3DMultisampleNV _ptrc_glTextureImage3DMultisampleNV
#endif /*GL_NV_texture_multisample*/ 





#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveVaryingNV)(GLuint program, const GLchar * name);
#define glActiveVaryingNV _ptrc_glActiveVaryingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackNV)(GLenum primitiveMode);
#define glBeginTransformFeedbackNV _ptrc_glBeginTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseNV)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBaseNV _ptrc_glBindBufferBaseNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
#define glBindBufferOffsetNV _ptrc_glBindBufferOffsetNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRangeNV _ptrc_glBindBufferRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackNV)(void);
#define glEndTransformFeedbackNV _ptrc_glEndTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveVaryingNV)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#define glGetActiveVaryingNV _ptrc_glGetActiveVaryingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingNV)(GLuint program, GLuint index, GLint * location);
#define glGetTransformFeedbackVaryingNV _ptrc_glGetTransformFeedbackVaryingNV
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetVaryingLocationNV)(GLuint program, const GLchar * name);
#define glGetVaryingLocationNV _ptrc_glGetVaryingLocationNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackAttribsNV)(GLsizei count, const GLint * attribs, GLenum bufferMode);
#define glTransformFeedbackAttribsNV _ptrc_glTransformFeedbackAttribsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackStreamAttribsNV)(GLsizei count, const GLint * attribs, GLsizei nbuffers, const GLint * bufstreams, GLenum bufferMode);
#define glTransformFeedbackStreamAttribsNV _ptrc_glTransformFeedbackStreamAttribsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsNV)(GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
#define glTransformFeedbackVaryingsNV _ptrc_glTransformFeedbackVaryingsNV
#endif /*GL_NV_transform_feedback*/ 

#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedbackNV)(GLenum target, GLuint id);
#define glBindTransformFeedbackNV _ptrc_glBindTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacksNV)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacksNV _ptrc_glDeleteTransformFeedbacksNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackNV)(GLenum mode, GLuint id);
#define glDrawTransformFeedbackNV _ptrc_glDrawTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacksNV)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacksNV _ptrc_glGenTransformFeedbacksNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedbackNV)(GLuint id);
#define glIsTransformFeedbackNV _ptrc_glIsTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedbackNV)(void);
#define glPauseTransformFeedbackNV _ptrc_glPauseTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedbackNV)(void);
#define glResumeTransformFeedbackNV _ptrc_glResumeTransformFeedbackNV
#endif /*GL_NV_transform_feedback2*/ 


#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeNV)(void);
#define glFlushVertexArrayRangeNV _ptrc_glFlushVertexArrayRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeNV)(GLsizei length, const void * pointer);
#define glVertexArrayRangeNV _ptrc_glVertexArrayRangeNV
#endif /*GL_NV_vertex_array_range*/ 


#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLi64vNV)(GLuint index, GLenum pname, GLint64EXT * params);
#define glGetVertexAttribLi64vNV _ptrc_glGetVertexAttribLi64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vNV)(GLuint index, GLenum pname, GLuint64EXT * params);
#define glGetVertexAttribLui64vNV _ptrc_glGetVertexAttribLui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64NV)(GLuint index, GLint64EXT x);
#define glVertexAttribL1i64NV _ptrc_glVertexAttribL1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64vNV)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL1i64vNV _ptrc_glVertexAttribL1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64NV)(GLuint index, GLuint64EXT x);
#define glVertexAttribL1ui64NV _ptrc_glVertexAttribL1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vNV)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL1ui64vNV _ptrc_glVertexAttribL1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64NV)(GLuint index, GLint64EXT x, GLint64EXT y);
#define glVertexAttribL2i64NV _ptrc_glVertexAttribL2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64vNV)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL2i64vNV _ptrc_glVertexAttribL2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y);
#define glVertexAttribL2ui64NV _ptrc_glVertexAttribL2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64vNV)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL2ui64vNV _ptrc_glVertexAttribL2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glVertexAttribL3i64NV _ptrc_glVertexAttribL3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64vNV)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL3i64vNV _ptrc_glVertexAttribL3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glVertexAttribL3ui64NV _ptrc_glVertexAttribL3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64vNV)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL3ui64vNV _ptrc_glVertexAttribL3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glVertexAttribL4i64NV _ptrc_glVertexAttribL4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64vNV)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL4i64vNV _ptrc_glVertexAttribL4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glVertexAttribL4ui64NV _ptrc_glVertexAttribL4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64vNV)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL4ui64vNV _ptrc_glVertexAttribL4ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);
#define glVertexAttribLFormatNV _ptrc_glVertexAttribLFormatNV
#endif /*GL_NV_vertex_attrib_integer_64bit*/ 

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferAddressRangeNV)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
#define glBufferAddressRangeNV _ptrc_glBufferAddressRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColorFormatNV)(GLint size, GLenum type, GLsizei stride);
#define glColorFormatNV _ptrc_glColorFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagFormatNV)(GLsizei stride);
#define glEdgeFlagFormatNV _ptrc_glEdgeFlagFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordFormatNV)(GLenum type, GLsizei stride);
#define glFogCoordFormatNV _ptrc_glFogCoordFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64i_vNV)(GLenum value, GLuint index, GLuint64EXT * result);
#define glGetIntegerui64i_vNV _ptrc_glGetIntegerui64i_vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexFormatNV)(GLenum type, GLsizei stride);
#define glIndexFormatNV _ptrc_glIndexFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalFormatNV)(GLenum type, GLsizei stride);
#define glNormalFormatNV _ptrc_glNormalFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorFormatNV)(GLint size, GLenum type, GLsizei stride);
#define glSecondaryColorFormatNV _ptrc_glSecondaryColorFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordFormatNV)(GLint size, GLenum type, GLsizei stride);
#define glTexCoordFormatNV _ptrc_glTexCoordFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormatNV)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
#define glVertexAttribFormatNV _ptrc_glVertexAttribFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);
#define glVertexAttribIFormatNV _ptrc_glVertexAttribIFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexFormatNV)(GLint size, GLenum type, GLsizei stride);
#define glVertexFormatNV _ptrc_glVertexFormatNV
#endif /*GL_NV_vertex_buffer_unified_memory*/ 

#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreProgramsResidentNV)(GLsizei n, const GLuint * programs, GLboolean * residences);
#define glAreProgramsResidentNV _ptrc_glAreProgramsResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramNV)(GLenum target, GLuint id);
#define glBindProgramNV _ptrc_glBindProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsNV)(GLsizei n, const GLuint * programs);
#define glDeleteProgramsNV _ptrc_glDeleteProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glExecuteProgramNV)(GLenum target, GLuint id, const GLfloat * params);
#define glExecuteProgramNV _ptrc_glExecuteProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsNV)(GLsizei n, GLuint * programs);
#define glGenProgramsNV _ptrc_glGenProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterdvNV)(GLenum target, GLuint index, GLenum pname, GLdouble * params);
#define glGetProgramParameterdvNV _ptrc_glGetProgramParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterfvNV)(GLenum target, GLuint index, GLenum pname, GLfloat * params);
#define glGetProgramParameterfvNV _ptrc_glGetProgramParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringNV)(GLuint id, GLenum pname, GLubyte * program);
#define glGetProgramStringNV _ptrc_glGetProgramStringNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivNV)(GLuint id, GLenum pname, GLint * params);
#define glGetProgramivNV _ptrc_glGetProgramivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTrackMatrixivNV)(GLenum target, GLuint address, GLenum pname, GLint * params);
#define glGetTrackMatrixivNV _ptrc_glGetTrackMatrixivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervNV)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointervNV _ptrc_glGetVertexAttribPointervNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvNV)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdvNV _ptrc_glGetVertexAttribdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvNV)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfvNV _ptrc_glGetVertexAttribfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivNV)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribivNV _ptrc_glGetVertexAttribivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramNV)(GLuint id);
#define glIsProgramNV _ptrc_glIsProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadProgramNV)(GLenum target, GLuint id, GLsizei len, const GLubyte * program);
#define glLoadProgramNV _ptrc_glLoadProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dNV)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramParameter4dNV _ptrc_glProgramParameter4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dvNV)(GLenum target, GLuint index, const GLdouble * v);
#define glProgramParameter4dvNV _ptrc_glProgramParameter4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fNV)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glProgramParameter4fNV _ptrc_glProgramParameter4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fvNV)(GLenum target, GLuint index, const GLfloat * v);
#define glProgramParameter4fvNV _ptrc_glProgramParameter4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4dvNV)(GLenum target, GLuint index, GLsizei count, const GLdouble * v);
#define glProgramParameters4dvNV _ptrc_glProgramParameters4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4fvNV)(GLenum target, GLuint index, GLsizei count, const GLfloat * v);
#define glProgramParameters4fvNV _ptrc_glProgramParameters4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glRequestResidentProgramsNV)(GLsizei n, const GLuint * programs);
#define glRequestResidentProgramsNV _ptrc_glRequestResidentProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTrackMatrixNV)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
#define glTrackMatrixNV _ptrc_glTrackMatrixNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dNV)(GLuint index, GLdouble x);
#define glVertexAttrib1dNV _ptrc_glVertexAttrib1dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvNV)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dvNV _ptrc_glVertexAttrib1dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fNV)(GLuint index, GLfloat x);
#define glVertexAttrib1fNV _ptrc_glVertexAttrib1fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvNV)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fvNV _ptrc_glVertexAttrib1fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sNV)(GLuint index, GLshort x);
#define glVertexAttrib1sNV _ptrc_glVertexAttrib1sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svNV)(GLuint index, const GLshort * v);
#define glVertexAttrib1svNV _ptrc_glVertexAttrib1svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dNV)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2dNV _ptrc_glVertexAttrib2dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvNV)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dvNV _ptrc_glVertexAttrib2dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fNV)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2fNV _ptrc_glVertexAttrib2fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvNV)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fvNV _ptrc_glVertexAttrib2fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sNV)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2sNV _ptrc_glVertexAttrib2sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svNV)(GLuint index, const GLshort * v);
#define glVertexAttrib2svNV _ptrc_glVertexAttrib2svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3dNV _ptrc_glVertexAttrib3dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvNV)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dvNV _ptrc_glVertexAttrib3dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3fNV _ptrc_glVertexAttrib3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvNV)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fvNV _ptrc_glVertexAttrib3fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sNV)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3sNV _ptrc_glVertexAttrib3sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svNV)(GLuint index, const GLshort * v);
#define glVertexAttrib3svNV _ptrc_glVertexAttrib3svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4dNV _ptrc_glVertexAttrib4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvNV)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dvNV _ptrc_glVertexAttrib4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4fNV _ptrc_glVertexAttrib4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvNV)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fvNV _ptrc_glVertexAttrib4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sNV)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4sNV _ptrc_glVertexAttrib4sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svNV)(GLuint index, const GLshort * v);
#define glVertexAttrib4svNV _ptrc_glVertexAttrib4svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubNV)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4ubNV _ptrc_glVertexAttrib4ubNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvNV)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubvNV _ptrc_glVertexAttrib4ubvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerNV)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribPointerNV _ptrc_glVertexAttribPointerNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1dvNV)(GLuint index, GLsizei count, const GLdouble * v);
#define glVertexAttribs1dvNV _ptrc_glVertexAttribs1dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1fvNV)(GLuint index, GLsizei count, const GLfloat * v);
#define glVertexAttribs1fvNV _ptrc_glVertexAttribs1fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1svNV)(GLuint index, GLsizei count, const GLshort * v);
#define glVertexAttribs1svNV _ptrc_glVertexAttribs1svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2dvNV)(GLuint index, GLsizei count, const GLdouble * v);
#define glVertexAttribs2dvNV _ptrc_glVertexAttribs2dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2fvNV)(GLuint index, GLsizei count, const GLfloat * v);
#define glVertexAttribs2fvNV _ptrc_glVertexAttribs2fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2svNV)(GLuint index, GLsizei count, const GLshort * v);
#define glVertexAttribs2svNV _ptrc_glVertexAttribs2svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3dvNV)(GLuint index, GLsizei count, const GLdouble * v);
#define glVertexAttribs3dvNV _ptrc_glVertexAttribs3dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3fvNV)(GLuint index, GLsizei count, const GLfloat * v);
#define glVertexAttribs3fvNV _ptrc_glVertexAttribs3fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3svNV)(GLuint index, GLsizei count, const GLshort * v);
#define glVertexAttribs3svNV _ptrc_glVertexAttribs3svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4dvNV)(GLuint index, GLsizei count, const GLdouble * v);
#define glVertexAttribs4dvNV _ptrc_glVertexAttribs4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4fvNV)(GLuint index, GLsizei count, const GLfloat * v);
#define glVertexAttribs4fvNV _ptrc_glVertexAttribs4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4svNV)(GLuint index, GLsizei count, const GLshort * v);
#define glVertexAttribs4svNV _ptrc_glVertexAttribs4svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4ubvNV)(GLuint index, GLsizei count, const GLubyte * v);
#define glVertexAttribs4ubvNV _ptrc_glVertexAttribs4ubvNV
#endif /*GL_NV_vertex_program*/ 





#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginVideoCaptureNV)(GLuint video_capture_slot);
#define glBeginVideoCaptureNV _ptrc_glBeginVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamBufferNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
#define glBindVideoCaptureStreamBufferNV _ptrc_glBindVideoCaptureStreamBufferNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamTextureNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
#define glBindVideoCaptureStreamTextureNV _ptrc_glBindVideoCaptureStreamTextureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndVideoCaptureNV)(GLuint video_capture_slot);
#define glEndVideoCaptureNV _ptrc_glEndVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble * params);
#define glGetVideoCaptureStreamdvNV _ptrc_glGetVideoCaptureStreamdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat * params);
#define glGetVideoCaptureStreamfvNV _ptrc_glGetVideoCaptureStreamfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint * params);
#define glGetVideoCaptureStreamivNV _ptrc_glGetVideoCaptureStreamivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureivNV)(GLuint video_capture_slot, GLenum pname, GLint * params);
#define glGetVideoCaptureivNV _ptrc_glGetVideoCaptureivNV
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureNV)(GLuint video_capture_slot, GLuint * sequence_num, GLuint64EXT * capture_time);
#define glVideoCaptureNV _ptrc_glVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble * params);
#define glVideoCaptureStreamParameterdvNV _ptrc_glVideoCaptureStreamParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat * params);
#define glVideoCaptureStreamParameterfvNV _ptrc_glVideoCaptureStreamParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint * params);
#define glVideoCaptureStreamParameterivNV _ptrc_glVideoCaptureStreamParameterivNV
#endif /*GL_NV_video_capture*/ 

#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNVX)(GLuint id);
#define glBeginConditionalRenderNVX _ptrc_glBeginConditionalRenderNVX
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNVX)(void);
#define glEndConditionalRenderNVX _ptrc_glEndConditionalRenderNVX
#endif /*GL_NVX_conditional_render*/ 



#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierKHR)(void);
#define glBlendBarrierKHR _ptrc_glBlendBarrierKHR
#endif /*GL_KHR_blend_equation_advanced*/ 






extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunc)(GLenum sfactor, GLenum dfactor);
#define glBlendFunc _ptrc_glBlendFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glClear)(GLbitfield mask);
#define glClear _ptrc_glClear
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearColor _ptrc_glClearColor
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepth)(GLdouble depth);
#define glClearDepth _ptrc_glClearDepth
extern void (CODEGEN_FUNCPTR *_ptrc_glClearStencil)(GLint s);
#define glClearStencil _ptrc_glClearStencil
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask _ptrc_glColorMask
extern void (CODEGEN_FUNCPTR *_ptrc_glCullFace)(GLenum mode);
#define glCullFace _ptrc_glCullFace
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthFunc)(GLenum func);
#define glDepthFunc _ptrc_glDepthFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthMask)(GLboolean flag);
#define glDepthMask _ptrc_glDepthMask
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRange)(GLdouble ren_near, GLdouble ren_far);
#define glDepthRange _ptrc_glDepthRange
extern void (CODEGEN_FUNCPTR *_ptrc_glDisable)(GLenum cap);
#define glDisable _ptrc_glDisable
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffer)(GLenum buf);
#define glDrawBuffer _ptrc_glDrawBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glEnable)(GLenum cap);
#define glEnable _ptrc_glEnable
extern void (CODEGEN_FUNCPTR *_ptrc_glFinish)(void);
#define glFinish _ptrc_glFinish
extern void (CODEGEN_FUNCPTR *_ptrc_glFlush)(void);
#define glFlush _ptrc_glFlush
extern void (CODEGEN_FUNCPTR *_ptrc_glFrontFace)(GLenum mode);
#define glFrontFace _ptrc_glFrontFace
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanv)(GLenum pname, GLboolean * data);
#define glGetBooleanv _ptrc_glGetBooleanv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublev)(GLenum pname, GLdouble * data);
#define glGetDoublev _ptrc_glGetDoublev
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetError)(void);
#define glGetError _ptrc_glGetError
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloatv)(GLenum pname, GLfloat * data);
#define glGetFloatv _ptrc_glGetFloatv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerv)(GLenum pname, GLint * data);
#define glGetIntegerv _ptrc_glGetIntegerv
extern const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetString)(GLenum name);
#define glGetString _ptrc_glGetString
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTexImage _ptrc_glGetTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTexLevelParameterfv _ptrc_glGetTexLevelParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTexLevelParameteriv _ptrc_glGetTexLevelParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexParameterfv _ptrc_glGetTexParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameteriv _ptrc_glGetTexParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glHint)(GLenum target, GLenum mode);
#define glHint _ptrc_glHint
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabled)(GLenum cap);
#define glIsEnabled _ptrc_glIsEnabled
extern void (CODEGEN_FUNCPTR *_ptrc_glLineWidth)(GLfloat width);
#define glLineWidth _ptrc_glLineWidth
extern void (CODEGEN_FUNCPTR *_ptrc_glLogicOp)(GLenum opcode);
#define glLogicOp _ptrc_glLogicOp
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelStoref)(GLenum pname, GLfloat param);
#define glPixelStoref _ptrc_glPixelStoref
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelStorei)(GLenum pname, GLint param);
#define glPixelStorei _ptrc_glPixelStorei
extern void (CODEGEN_FUNCPTR *_ptrc_glPointSize)(GLfloat size);
#define glPointSize _ptrc_glPointSize
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonMode)(GLenum face, GLenum mode);
#define glPolygonMode _ptrc_glPolygonMode
extern void (CODEGEN_FUNCPTR *_ptrc_glReadBuffer)(GLenum src);
#define glReadBuffer _ptrc_glReadBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
#define glReadPixels _ptrc_glReadPixels
extern void (CODEGEN_FUNCPTR *_ptrc_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor _ptrc_glScissor
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
#define glStencilFunc _ptrc_glStencilFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilMask)(GLuint mask);
#define glStencilMask _ptrc_glStencilMask
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp _ptrc_glStencilOp
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage1D _ptrc_glTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage2D _ptrc_glTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf _ptrc_glTexParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexParameterfv _ptrc_glTexParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameteri)(GLenum target, GLenum pname, GLint param);
#define glTexParameteri _ptrc_glTexParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameteriv)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameteriv _ptrc_glTexParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport _ptrc_glViewport

extern void (CODEGEN_FUNCPTR *_ptrc_glBindTexture)(GLenum target, GLuint texture);
#define glBindTexture _ptrc_glBindTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D _ptrc_glCopyTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D _ptrc_glCopyTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D _ptrc_glCopyTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D _ptrc_glCopyTexSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTextures)(GLsizei n, const GLuint * textures);
#define glDeleteTextures _ptrc_glDeleteTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
#define glDrawArrays _ptrc_glDrawArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void * indices);
#define glDrawElements _ptrc_glDrawElements
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTextures)(GLsizei n, GLuint * textures);
#define glGenTextures _ptrc_glGenTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum pname, void ** params);
#define glGetPointerv _ptrc_glGetPointerv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTexture)(GLuint texture);
#define glIsTexture _ptrc_glIsTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffset)(GLfloat factor, GLfloat units);
#define glPolygonOffset _ptrc_glPolygonOffset
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage1D _ptrc_glTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage2D _ptrc_glTexSubImage2D

extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D _ptrc_glCopyTexSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
#define glDrawRangeElements _ptrc_glDrawRangeElements
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage3D _ptrc_glTexImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage3D _ptrc_glTexSubImage3D

extern void (CODEGEN_FUNCPTR *_ptrc_glActiveTexture)(GLenum texture);
#define glActiveTexture _ptrc_glActiveTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage1D _ptrc_glCompressedTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage2D _ptrc_glCompressedTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage3D _ptrc_glCompressedTexImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage1D _ptrc_glCompressedTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage2D _ptrc_glCompressedTexSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage3D _ptrc_glCompressedTexSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImage)(GLenum target, GLint level, void * img);
#define glGetCompressedTexImage _ptrc_glGetCompressedTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverage)(GLfloat value, GLboolean invert);
#define glSampleCoverage _ptrc_glSampleCoverage

extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor _ptrc_glBlendColor
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquation)(GLenum mode);
#define glBlendEquation _ptrc_glBlendEquation
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparate _ptrc_glBlendFuncSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
#define glMultiDrawArrays _ptrc_glMultiDrawArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
#define glMultiDrawElements _ptrc_glMultiDrawElements
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterf)(GLenum pname, GLfloat param);
#define glPointParameterf _ptrc_glPointParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfv)(GLenum pname, const GLfloat * params);
#define glPointParameterfv _ptrc_glPointParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteri)(GLenum pname, GLint param);
#define glPointParameteri _ptrc_glPointParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriv)(GLenum pname, const GLint * params);
#define glPointParameteriv _ptrc_glPointParameteriv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQuery)(GLenum target, GLuint id);
#define glBeginQuery _ptrc_glBeginQuery
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffer)(GLenum target, GLuint buffer);
#define glBindBuffer _ptrc_glBindBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
#define glBufferData _ptrc_glBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
#define glBufferSubData _ptrc_glBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffers)(GLsizei n, const GLuint * buffers);
#define glDeleteBuffers _ptrc_glDeleteBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueries)(GLsizei n, const GLuint * ids);
#define glDeleteQueries _ptrc_glDeleteQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQuery)(GLenum target);
#define glEndQuery _ptrc_glEndQuery
extern void (CODEGEN_FUNCPTR *_ptrc_glGenBuffers)(GLsizei n, GLuint * buffers);
#define glGenBuffers _ptrc_glGenBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenQueries)(GLsizei n, GLuint * ids);
#define glGenQueries _ptrc_glGenQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetBufferParameteriv _ptrc_glGetBufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointerv)(GLenum target, GLenum pname, void ** params);
#define glGetBufferPointerv _ptrc_glGetBufferPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
#define glGetBufferSubData _ptrc_glGetBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint * params);
#define glGetQueryObjectiv _ptrc_glGetQueryObjectiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params);
#define glGetQueryObjectuiv _ptrc_glGetQueryObjectuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryiv)(GLenum target, GLenum pname, GLint * params);
#define glGetQueryiv _ptrc_glGetQueryiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBuffer)(GLuint buffer);
#define glIsBuffer _ptrc_glIsBuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQuery)(GLuint id);
#define glIsQuery _ptrc_glIsQuery
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBuffer)(GLenum target, GLenum access);
#define glMapBuffer _ptrc_glMapBuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBuffer)(GLenum target);
#define glUnmapBuffer _ptrc_glUnmapBuffer

extern void (CODEGEN_FUNCPTR *_ptrc_glAttachShader)(GLuint program, GLuint shader);
#define glAttachShader _ptrc_glAttachShader
extern void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocation)(GLuint program, GLuint index, const GLchar * name);
#define glBindAttribLocation _ptrc_glBindAttribLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparate _ptrc_glBlendEquationSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShader)(GLuint shader);
#define glCompileShader _ptrc_glCompileShader
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateProgram)(void);
#define glCreateProgram _ptrc_glCreateProgram
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShader)(GLenum type);
#define glCreateShader _ptrc_glCreateShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgram)(GLuint program);
#define glDeleteProgram _ptrc_glDeleteProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteShader)(GLuint shader);
#define glDeleteShader _ptrc_glDeleteShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDetachShader)(GLuint program, GLuint shader);
#define glDetachShader _ptrc_glDetachShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArray)(GLuint index);
#define glDisableVertexAttribArray _ptrc_glDisableVertexAttribArray
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffers)(GLsizei n, const GLenum * bufs);
#define glDrawBuffers _ptrc_glDrawBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArray)(GLuint index);
#define glEnableVertexAttribArray _ptrc_glEnableVertexAttribArray
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveAttrib _ptrc_glGetActiveAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveUniform _ptrc_glGetActiveUniform
extern void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
#define glGetAttachedShaders _ptrc_glGetAttachedShaders
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocation)(GLuint program, const GLchar * name);
#define glGetAttribLocation _ptrc_glGetAttribLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramInfoLog _ptrc_glGetProgramInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramiv)(GLuint program, GLenum pname, GLint * params);
#define glGetProgramiv _ptrc_glGetProgramiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetShaderInfoLog _ptrc_glGetShaderInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
#define glGetShaderSource _ptrc_glGetShaderSource
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderiv)(GLuint shader, GLenum pname, GLint * params);
#define glGetShaderiv _ptrc_glGetShaderiv
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocation)(GLuint program, const GLchar * name);
#define glGetUniformLocation _ptrc_glGetUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfv)(GLuint program, GLint location, GLfloat * params);
#define glGetUniformfv _ptrc_glGetUniformfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformiv)(GLuint program, GLint location, GLint * params);
#define glGetUniformiv _ptrc_glGetUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointerv _ptrc_glGetVertexAttribPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdv _ptrc_glGetVertexAttribdv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfv _ptrc_glGetVertexAttribfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribiv _ptrc_glGetVertexAttribiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgram)(GLuint program);
#define glIsProgram _ptrc_glIsProgram
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsShader)(GLuint shader);
#define glIsShader _ptrc_glIsShader
extern void (CODEGEN_FUNCPTR *_ptrc_glLinkProgram)(GLuint program);
#define glLinkProgram _ptrc_glLinkProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
#define glShaderSource _ptrc_glShaderSource
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
#define glStencilFuncSeparate _ptrc_glStencilFuncSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilMaskSeparate)(GLenum face, GLuint mask);
#define glStencilMaskSeparate _ptrc_glStencilMaskSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
#define glStencilOpSeparate _ptrc_glStencilOpSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1f)(GLint location, GLfloat v0);
#define glUniform1f _ptrc_glUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fv)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform1fv _ptrc_glUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i)(GLint location, GLint v0);
#define glUniform1i _ptrc_glUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1iv)(GLint location, GLsizei count, const GLint * value);
#define glUniform1iv _ptrc_glUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2f _ptrc_glUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fv)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform2fv _ptrc_glUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i)(GLint location, GLint v0, GLint v1);
#define glUniform2i _ptrc_glUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2iv)(GLint location, GLsizei count, const GLint * value);
#define glUniform2iv _ptrc_glUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3f _ptrc_glUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fv)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform3fv _ptrc_glUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3i _ptrc_glUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3iv)(GLint location, GLsizei count, const GLint * value);
#define glUniform3iv _ptrc_glUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4f _ptrc_glUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fv)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform4fv _ptrc_glUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4i _ptrc_glUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4iv)(GLint location, GLsizei count, const GLint * value);
#define glUniform4iv _ptrc_glUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2fv _ptrc_glUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3fv _ptrc_glUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4fv _ptrc_glUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgram)(GLuint program);
#define glUseProgram _ptrc_glUseProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgram)(GLuint program);
#define glValidateProgram _ptrc_glValidateProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1d)(GLuint index, GLdouble x);
#define glVertexAttrib1d _ptrc_glVertexAttrib1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dv)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dv _ptrc_glVertexAttrib1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1f)(GLuint index, GLfloat x);
#define glVertexAttrib1f _ptrc_glVertexAttrib1f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fv)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fv _ptrc_glVertexAttrib1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1s)(GLuint index, GLshort x);
#define glVertexAttrib1s _ptrc_glVertexAttrib1s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sv)(GLuint index, const GLshort * v);
#define glVertexAttrib1sv _ptrc_glVertexAttrib1sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2d _ptrc_glVertexAttrib2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dv)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dv _ptrc_glVertexAttrib2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2f _ptrc_glVertexAttrib2f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fv)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fv _ptrc_glVertexAttrib2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2s _ptrc_glVertexAttrib2s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sv)(GLuint index, const GLshort * v);
#define glVertexAttrib2sv _ptrc_glVertexAttrib2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3d _ptrc_glVertexAttrib3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dv)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dv _ptrc_glVertexAttrib3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3f _ptrc_glVertexAttrib3f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fv)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fv _ptrc_glVertexAttrib3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3s _ptrc_glVertexAttrib3s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sv)(GLuint index, const GLshort * v);
#define glVertexAttrib3sv _ptrc_glVertexAttrib3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nbv)(GLuint index, const GLbyte * v);
#define glVertexAttrib4Nbv _ptrc_glVertexAttrib4Nbv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Niv)(GLuint index, const GLint * v);
#define glVertexAttrib4Niv _ptrc_glVertexAttrib4Niv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nsv)(GLuint index, const GLshort * v);
#define glVertexAttrib4Nsv _ptrc_glVertexAttrib4Nsv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4Nub _ptrc_glVertexAttrib4Nub
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nubv)(GLuint index, const GLubyte * v);
#define glVertexAttrib4Nubv _ptrc_glVertexAttrib4Nubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nuiv)(GLuint index, const GLuint * v);
#define glVertexAttrib4Nuiv _ptrc_glVertexAttrib4Nuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nusv)(GLuint index, const GLushort * v);
#define glVertexAttrib4Nusv _ptrc_glVertexAttrib4Nusv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bv)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bv _ptrc_glVertexAttrib4bv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4d _ptrc_glVertexAttrib4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dv)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dv _ptrc_glVertexAttrib4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4f _ptrc_glVertexAttrib4f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fv)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fv _ptrc_glVertexAttrib4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4iv)(GLuint index, const GLint * v);
#define glVertexAttrib4iv _ptrc_glVertexAttrib4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4s _ptrc_glVertexAttrib4s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sv)(GLuint index, const GLshort * v);
#define glVertexAttrib4sv _ptrc_glVertexAttrib4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubv)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubv _ptrc_glVertexAttrib4ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uiv)(GLuint index, const GLuint * v);
#define glVertexAttrib4uiv _ptrc_glVertexAttrib4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usv)(GLuint index, const GLushort * v);
#define glVertexAttrib4usv _ptrc_glVertexAttrib4usv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointer _ptrc_glVertexAttribPointer

extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x3fv _ptrc_glUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x4fv _ptrc_glUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x2fv _ptrc_glUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x4fv _ptrc_glUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x2fv _ptrc_glUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x3fv _ptrc_glUniformMatrix4x3fv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRender)(GLuint id, GLenum mode);
#define glBeginConditionalRender _ptrc_glBeginConditionalRender
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedback)(GLenum primitiveMode);
#define glBeginTransformFeedback _ptrc_glBeginTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase _ptrc_glBindBufferBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange _ptrc_glBindBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar * name);
#define glBindFragDataLocation _ptrc_glBindFragDataLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer _ptrc_glBindFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer _ptrc_glBindRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint ren_array);
#define glBindVertexArray _ptrc_glBindVertexArray
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer _ptrc_glBlitFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum target);
#define glCheckFramebufferStatus _ptrc_glCheckFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glClampColor)(GLenum target, GLenum clamp);
#define glClampColor _ptrc_glClampColor
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearBufferfi _ptrc_glClearBufferfi
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearBufferfv _ptrc_glClearBufferfv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearBufferiv _ptrc_glClearBufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearBufferuiv _ptrc_glClearBufferuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#define glColorMaski _ptrc_glColorMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers _ptrc_glDeleteFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers _ptrc_glDeleteRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays _ptrc_glDeleteVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDisablei)(GLenum target, GLuint index);
#define glDisablei _ptrc_glDisablei
extern void (CODEGEN_FUNCPTR *_ptrc_glEnablei)(GLenum target, GLuint index);
#define glEnablei _ptrc_glEnablei
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRender)(void);
#define glEndConditionalRender _ptrc_glEndConditionalRender
extern void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedback)(void);
#define glEndTransformFeedback _ptrc_glEndTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange _ptrc_glFlushMappedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer _ptrc_glFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D _ptrc_glFramebufferTexture1D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D _ptrc_glFramebufferTexture2D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D _ptrc_glFramebufferTexture3D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer _ptrc_glFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers _ptrc_glGenFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers _ptrc_glGenRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays _ptrc_glGenVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum target);
#define glGenerateMipmap _ptrc_glGenerateMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleani_v)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleani_v _ptrc_glGetBooleani_v
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocation)(GLuint program, const GLchar * name);
#define glGetFragDataLocation _ptrc_glGetFragDataLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv _ptrc_glGetFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegeri_v)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v _ptrc_glGetIntegeri_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv _ptrc_glGetRenderbufferParameteriv
extern const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetStringi)(GLenum name, GLuint index);
#define glGetStringi _ptrc_glGetStringi
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameterIiv _ptrc_glGetTexParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint * params);
#define glGetTexParameterIuiv _ptrc_glGetTexParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#define glGetTransformFeedbackVarying _ptrc_glGetTransformFeedbackVarying
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuiv)(GLuint program, GLint location, GLuint * params);
#define glGetUniformuiv _ptrc_glGetUniformuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribIiv _ptrc_glGetVertexAttribIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint * params);
#define glGetVertexAttribIuiv _ptrc_glGetVertexAttribIuiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledi)(GLenum target, GLuint index);
#define glIsEnabledi _ptrc_glIsEnabledi
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint framebuffer);
#define glIsFramebuffer _ptrc_glIsFramebuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint renderbuffer);
#define glIsRenderbuffer _ptrc_glIsRenderbuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint ren_array);
#define glIsVertexArray _ptrc_glIsVertexArray
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange _ptrc_glMapBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage _ptrc_glRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample _ptrc_glRenderbufferStorageMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIiv)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameterIiv _ptrc_glTexParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint * params);
#define glTexParameterIuiv _ptrc_glTexParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
#define glTransformFeedbackVaryings _ptrc_glTransformFeedbackVaryings
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui)(GLint location, GLuint v0);
#define glUniform1ui _ptrc_glUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiv)(GLint location, GLsizei count, const GLuint * value);
#define glUniform1uiv _ptrc_glUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
#define glUniform2ui _ptrc_glUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiv)(GLint location, GLsizei count, const GLuint * value);
#define glUniform2uiv _ptrc_glUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3ui _ptrc_glUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiv)(GLint location, GLsizei count, const GLuint * value);
#define glUniform3uiv _ptrc_glUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4ui _ptrc_glUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiv)(GLint location, GLsizei count, const GLuint * value);
#define glUniform4uiv _ptrc_glUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1i)(GLuint index, GLint x);
#define glVertexAttribI1i _ptrc_glVertexAttribI1i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iv)(GLuint index, const GLint * v);
#define glVertexAttribI1iv _ptrc_glVertexAttribI1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ui)(GLuint index, GLuint x);
#define glVertexAttribI1ui _ptrc_glVertexAttribI1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiv)(GLuint index, const GLuint * v);
#define glVertexAttribI1uiv _ptrc_glVertexAttribI1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
#define glVertexAttribI2i _ptrc_glVertexAttribI2i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iv)(GLuint index, const GLint * v);
#define glVertexAttribI2iv _ptrc_glVertexAttribI2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
#define glVertexAttribI2ui _ptrc_glVertexAttribI2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiv)(GLuint index, const GLuint * v);
#define glVertexAttribI2uiv _ptrc_glVertexAttribI2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
#define glVertexAttribI3i _ptrc_glVertexAttribI3i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iv)(GLuint index, const GLint * v);
#define glVertexAttribI3iv _ptrc_glVertexAttribI3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
#define glVertexAttribI3ui _ptrc_glVertexAttribI3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiv)(GLuint index, const GLuint * v);
#define glVertexAttribI3uiv _ptrc_glVertexAttribI3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bv)(GLuint index, const GLbyte * v);
#define glVertexAttribI4bv _ptrc_glVertexAttribI4bv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glVertexAttribI4i _ptrc_glVertexAttribI4i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iv)(GLuint index, const GLint * v);
#define glVertexAttribI4iv _ptrc_glVertexAttribI4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4sv)(GLuint index, const GLshort * v);
#define glVertexAttribI4sv _ptrc_glVertexAttribI4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubv)(GLuint index, const GLubyte * v);
#define glVertexAttribI4ubv _ptrc_glVertexAttribI4ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glVertexAttribI4ui _ptrc_glVertexAttribI4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiv)(GLuint index, const GLuint * v);
#define glVertexAttribI4uiv _ptrc_glVertexAttribI4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usv)(GLuint index, const GLushort * v);
#define glVertexAttribI4usv _ptrc_glVertexAttribI4usv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribIPointer _ptrc_glVertexAttribIPointer

extern void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData _ptrc_glCopyBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#define glDrawArraysInstanced _ptrc_glDrawArraysInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
#define glDrawElementsInstanced _ptrc_glDrawElementsInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName _ptrc_glGetActiveUniformBlockName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv _ptrc_glGetActiveUniformBlockiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName _ptrc_glGetActiveUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv _ptrc_glGetActiveUniformsiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex _ptrc_glGetUniformBlockIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
#define glGetUniformIndices _ptrc_glGetUniformIndices
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndex)(GLuint index);
#define glPrimitiveRestartIndex _ptrc_glPrimitiveRestartIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBuffer _ptrc_glTexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding _ptrc_glUniformBlockBinding

extern GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync _ptrc_glClientWaitSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync sync);
#define glDeleteSync _ptrc_glDeleteSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawElementsBaseVertex _ptrc_glDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex _ptrc_glDrawElementsInstancedBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex _ptrc_glDrawRangeElementsBaseVertex
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum condition, GLbitfield flags);
#define glFenceSync _ptrc_glFenceSync
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTexture _ptrc_glFramebufferTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params);
#define glGetBufferParameteri64v _ptrc_glGetBufferParameteri64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 * data);
#define glGetInteger64i_v _ptrc_glGetInteger64i_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum pname, GLint64 * data);
#define glGetInteger64v _ptrc_glGetInteger64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv _ptrc_glGetMultisamplefv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
#define glGetSynciv _ptrc_glGetSynciv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync sync);
#define glIsSync _ptrc_glIsSync
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex _ptrc_glMultiDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum mode);
#define glProvokingVertex _ptrc_glProvokingVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski _ptrc_glSampleMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample _ptrc_glTexImage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample _ptrc_glTexImage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync _ptrc_glWaitSync

extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed _ptrc_glBindFragDataLocationIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint unit, GLuint sampler);
#define glBindSampler _ptrc_glBindSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers _ptrc_glDeleteSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei count, GLuint * samplers);
#define glGenSamplers _ptrc_glGenSamplers
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint program, const GLchar * name);
#define glGetFragDataIndex _ptrc_glGetFragDataIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v _ptrc_glGetQueryObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v _ptrc_glGetQueryObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv _ptrc_glGetSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv _ptrc_glGetSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv _ptrc_glGetSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv _ptrc_glGetSamplerParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint sampler);
#define glIsSampler _ptrc_glIsSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint id, GLenum target);
#define glQueryCounter _ptrc_glQueryCounter
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv _ptrc_glSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv _ptrc_glSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf _ptrc_glSamplerParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv _ptrc_glSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri _ptrc_glSamplerParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv _ptrc_glSamplerParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisor)(GLuint index, GLuint divisor);
#define glVertexAttribDivisor _ptrc_glVertexAttribDivisor
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui _ptrc_glVertexAttribP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv _ptrc_glVertexAttribP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui _ptrc_glVertexAttribP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv _ptrc_glVertexAttribP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui _ptrc_glVertexAttribP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv _ptrc_glVertexAttribP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui _ptrc_glVertexAttribP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv _ptrc_glVertexAttribP4uiv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed _ptrc_glBeginQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum target, GLuint id);
#define glBindTransformFeedback _ptrc_glBindTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparatei _ptrc_glBlendEquationSeparatei
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationi)(GLuint buf, GLenum mode);
#define glBlendEquationi _ptrc_glBlendEquationi
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparatei _ptrc_glBlendFuncSeparatei
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunci _ptrc_glBlendFunci
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks _ptrc_glDeleteTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect _ptrc_glDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect _ptrc_glDrawElementsIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum mode, GLuint id);
#define glDrawTransformFeedback _ptrc_glDrawTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream _ptrc_glDrawTransformFeedbackStream
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum target, GLuint index);
#define glEndQueryIndexed _ptrc_glEndQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks _ptrc_glGenTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName _ptrc_glGetActiveSubroutineName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName _ptrc_glGetActiveSubroutineUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv _ptrc_glGetActiveSubroutineUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv _ptrc_glGetProgramStageiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv _ptrc_glGetQueryIndexediv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex _ptrc_glGetSubroutineIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineUniformLocation _ptrc_glGetSubroutineUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv _ptrc_glGetUniformSubroutineuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv _ptrc_glGetUniformdv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint id);
#define glIsTransformFeedback _ptrc_glIsTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShading)(GLfloat value);
#define glMinSampleShading _ptrc_glMinSampleShading
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv _ptrc_glPatchParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum pname, GLint value);
#define glPatchParameteri _ptrc_glPatchParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)(void);
#define glPauseTransformFeedback _ptrc_glPauseTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)(void);
#define glResumeTransformFeedback _ptrc_glResumeTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint location, GLdouble x);
#define glUniform1d _ptrc_glUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv _ptrc_glUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d _ptrc_glUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv _ptrc_glUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d _ptrc_glUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv _ptrc_glUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d _ptrc_glUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv _ptrc_glUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv _ptrc_glUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv _ptrc_glUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv _ptrc_glUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv _ptrc_glUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv _ptrc_glUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv _ptrc_glUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv _ptrc_glUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv _ptrc_glUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv _ptrc_glUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv _ptrc_glUniformSubroutinesuiv

extern void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram _ptrc_glActiveShaderProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint pipeline);
#define glBindProgramPipeline _ptrc_glBindProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat d);
#define glClearDepthf _ptrc_glClearDepthf
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv _ptrc_glCreateShaderProgramv
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines _ptrc_glDeleteProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv _ptrc_glDepthRangeArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed _ptrc_glDepthRangeIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat n, GLfloat f);
#define glDepthRangef _ptrc_glDepthRangef
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines _ptrc_glGenProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v _ptrc_glGetDoublei_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v _ptrc_glGetFloati_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary _ptrc_glGetProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog _ptrc_glGetProgramPipelineInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv _ptrc_glGetProgramPipelineiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat _ptrc_glGetShaderPrecisionFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv _ptrc_glGetVertexAttribLdv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint pipeline);
#define glIsProgramPipeline _ptrc_glIsProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary _ptrc_glProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri _ptrc_glProgramParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d _ptrc_glProgramUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv _ptrc_glProgramUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f _ptrc_glProgramUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv _ptrc_glProgramUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i _ptrc_glProgramUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv _ptrc_glProgramUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui _ptrc_glProgramUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv _ptrc_glProgramUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d _ptrc_glProgramUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv _ptrc_glProgramUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f _ptrc_glProgramUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv _ptrc_glProgramUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i _ptrc_glProgramUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv _ptrc_glProgramUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui _ptrc_glProgramUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv _ptrc_glProgramUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d _ptrc_glProgramUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv _ptrc_glProgramUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f _ptrc_glProgramUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv _ptrc_glProgramUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i _ptrc_glProgramUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv _ptrc_glProgramUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui _ptrc_glProgramUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv _ptrc_glProgramUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d _ptrc_glProgramUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv _ptrc_glProgramUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f _ptrc_glProgramUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv _ptrc_glProgramUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i _ptrc_glProgramUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv _ptrc_glProgramUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui _ptrc_glProgramUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv _ptrc_glProgramUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv _ptrc_glProgramUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv _ptrc_glProgramUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv _ptrc_glProgramUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv _ptrc_glProgramUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv _ptrc_glProgramUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv _ptrc_glProgramUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv _ptrc_glProgramUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv _ptrc_glProgramUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv _ptrc_glProgramUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv _ptrc_glProgramUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv _ptrc_glProgramUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv _ptrc_glProgramUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv _ptrc_glProgramUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv _ptrc_glProgramUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv _ptrc_glProgramUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv _ptrc_glProgramUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv _ptrc_glProgramUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv _ptrc_glProgramUniformMatrix4x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)(void);
#define glReleaseShaderCompiler _ptrc_glReleaseShaderCompiler
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv _ptrc_glScissorArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed _ptrc_glScissorIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint index, const GLint * v);
#define glScissorIndexedv _ptrc_glScissorIndexedv
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
#define glShaderBinary _ptrc_glShaderBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages _ptrc_glUseProgramStages
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint pipeline);
#define glValidateProgramPipeline _ptrc_glValidateProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint index, GLdouble x);
#define glVertexAttribL1d _ptrc_glVertexAttribL1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv _ptrc_glVertexAttribL1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d _ptrc_glVertexAttribL2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv _ptrc_glVertexAttribL2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d _ptrc_glVertexAttribL3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv _ptrc_glVertexAttribL3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d _ptrc_glVertexAttribL4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv _ptrc_glVertexAttribL4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer _ptrc_glVertexAttribLPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv _ptrc_glViewportArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf _ptrc_glViewportIndexedf
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv _ptrc_glViewportIndexedfv

extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture _ptrc_glBindImageTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
#define glDrawArraysInstancedBaseInstance _ptrc_glDrawArraysInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance _ptrc_glDrawElementsInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance _ptrc_glDrawElementsInstancedBaseVertexBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced _ptrc_glDrawTransformFeedbackInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced _ptrc_glDrawTransformFeedbackStreamInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv _ptrc_glGetActiveAtomicCounterBufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
#define glGetInternalformativ _ptrc_glGetInternalformativ
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield barriers);
#define glMemoryBarrier _ptrc_glMemoryBarrier
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D _ptrc_glTexStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D _ptrc_glTexStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D _ptrc_glTexStorage3D

extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer _ptrc_glBindVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearBufferData _ptrc_glClearBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData _ptrc_glClearBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData _ptrc_glCopyImageSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback _ptrc_glDebugMessageCallback
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl _ptrc_glDebugMessageControl
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert _ptrc_glDebugMessageInsert
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute _ptrc_glDispatchCompute
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr indirect);
#define glDispatchComputeIndirect _ptrc_glDispatchComputeIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri _ptrc_glFramebufferParameteri
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog _ptrc_glGetDebugMessageLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv _ptrc_glGetFramebufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
#define glGetInternalformati64v _ptrc_glGetInternalformati64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel _ptrc_glGetObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel _ptrc_glGetObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv _ptrc_glGetProgramInterfaceiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex _ptrc_glGetProgramResourceIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation _ptrc_glGetProgramResourceLocation
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex _ptrc_glGetProgramResourceLocationIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName _ptrc_glGetProgramResourceName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
#define glGetProgramResourceiv _ptrc_glGetProgramResourceiv
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint buffer);
#define glInvalidateBufferData _ptrc_glInvalidateBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData _ptrc_glInvalidateBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer _ptrc_glInvalidateFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer _ptrc_glInvalidateSubFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint texture, GLint level);
#define glInvalidateTexImage _ptrc_glInvalidateTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage _ptrc_glInvalidateTexSubImage
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect _ptrc_glMultiDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect _ptrc_glMultiDrawElementsIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel _ptrc_glObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel _ptrc_glObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)(void);
#define glPopDebugGroup _ptrc_glPopDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup _ptrc_glPushDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding _ptrc_glShaderStorageBlockBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange _ptrc_glTexBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample _ptrc_glTexStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample _ptrc_glTexStorage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView _ptrc_glTextureView
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding _ptrc_glVertexAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat _ptrc_glVertexAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat _ptrc_glVertexAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat _ptrc_glVertexAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor _ptrc_glVertexBindingDivisor

extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase _ptrc_glBindBuffersBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange _ptrc_glBindBuffersRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures _ptrc_glBindImageTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers _ptrc_glBindSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures _ptrc_glBindTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers _ptrc_glBindVertexBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#define glBufferStorage _ptrc_glBufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage _ptrc_glClearTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage _ptrc_glClearTexSubImage

extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextureUnit)(GLuint unit, GLuint texture);
#define glBindTextureUnit _ptrc_glBindTextureUnit
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer _ptrc_glBlitNamedFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus _ptrc_glCheckNamedFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData _ptrc_glClearNamedBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData _ptrc_glClearNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi _ptrc_glClearNamedFramebufferfi
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv _ptrc_glClearNamedFramebufferfv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv _ptrc_glClearNamedFramebufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv _ptrc_glClearNamedFramebufferuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glClipControl)(GLenum origin, GLenum depth);
#define glClipControl _ptrc_glClipControl
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D _ptrc_glCompressedTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D _ptrc_glCompressedTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D _ptrc_glCompressedTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData _ptrc_glCopyNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D _ptrc_glCopyTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D _ptrc_glCopyTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D _ptrc_glCopyTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateBuffers)(GLsizei n, GLuint * buffers);
#define glCreateBuffers _ptrc_glCreateBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateFramebuffers)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers _ptrc_glCreateFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateProgramPipelines)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines _ptrc_glCreateProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateQueries)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries _ptrc_glCreateQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateRenderbuffers)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers _ptrc_glCreateRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateSamplers)(GLsizei n, GLuint * samplers);
#define glCreateSamplers _ptrc_glCreateSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateTextures)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures _ptrc_glCreateTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateTransformFeedbacks)(GLsizei n, GLuint * ids);
#define glCreateTransformFeedbacks _ptrc_glCreateTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glCreateVertexArrays)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays _ptrc_glCreateVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib _ptrc_glDisableVertexArrayAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib _ptrc_glEnableVertexArrayAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange _ptrc_glFlushMappedNamedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmap)(GLuint texture);
#define glGenerateTextureMipmap _ptrc_glGenerateTextureMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage _ptrc_glGetCompressedTextureImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage _ptrc_glGetCompressedTextureSubImage
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatus)(void);
#define glGetGraphicsResetStatus _ptrc_glGetGraphicsResetStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v _ptrc_glGetNamedBufferParameteri64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv _ptrc_glGetNamedBufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv _ptrc_glGetNamedBufferPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData _ptrc_glGetNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv _ptrc_glGetNamedFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv _ptrc_glGetNamedFramebufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv _ptrc_glGetNamedRenderbufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v _ptrc_glGetQueryBufferObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv _ptrc_glGetQueryBufferObjectiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v _ptrc_glGetQueryBufferObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv _ptrc_glGetQueryBufferObjectuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage _ptrc_glGetTextureImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv _ptrc_glGetTextureLevelParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv _ptrc_glGetTextureLevelParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv _ptrc_glGetTextureParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv _ptrc_glGetTextureParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv _ptrc_glGetTextureParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv _ptrc_glGetTextureParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage _ptrc_glGetTextureSubImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v _ptrc_glGetTransformFeedbacki64_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v _ptrc_glGetTransformFeedbacki_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv _ptrc_glGetTransformFeedbackiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv _ptrc_glGetVertexArrayIndexed64iv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv _ptrc_glGetVertexArrayIndexediv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv _ptrc_glGetVertexArrayiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void * pixels);
#define glGetnCompressedTexImage _ptrc_glGetnCompressedTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetnTexImage _ptrc_glGetnTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdv _ptrc_glGetnUniformdv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv _ptrc_glGetnUniformfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv _ptrc_glGetnUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv _ptrc_glGetnUniformuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData _ptrc_glInvalidateNamedFramebufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData _ptrc_glInvalidateNamedFramebufferSubData
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBuffer)(GLuint buffer, GLenum access);
#define glMapNamedBuffer _ptrc_glMapNamedBuffer
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange _ptrc_glMapNamedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierByRegion)(GLbitfield barriers);
#define glMemoryBarrierByRegion _ptrc_glMemoryBarrierByRegion
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData _ptrc_glNamedBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage _ptrc_glNamedBufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData _ptrc_glNamedBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer _ptrc_glNamedFramebufferDrawBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers _ptrc_glNamedFramebufferDrawBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri _ptrc_glNamedFramebufferParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer _ptrc_glNamedFramebufferReadBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer _ptrc_glNamedFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture _ptrc_glNamedFramebufferTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer _ptrc_glNamedFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage _ptrc_glNamedRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample _ptrc_glNamedRenderbufferStorageMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels _ptrc_glReadnPixels
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrier)(void);
#define glTextureBarrier _ptrc_glTextureBarrier
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer _ptrc_glTextureBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange _ptrc_glTextureBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv _ptrc_glTextureParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv _ptrc_glTextureParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf _ptrc_glTextureParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv _ptrc_glTextureParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri _ptrc_glTextureParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv _ptrc_glTextureParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D _ptrc_glTextureStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D _ptrc_glTextureStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample _ptrc_glTextureStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D _ptrc_glTextureStorage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample _ptrc_glTextureStorage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D _ptrc_glTextureSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D _ptrc_glTextureSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D _ptrc_glTextureSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase _ptrc_glTransformFeedbackBufferBase
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange _ptrc_glTransformFeedbackBufferRange
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBuffer)(GLuint buffer);
#define glUnmapNamedBuffer _ptrc_glUnmapNamedBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding _ptrc_glVertexArrayAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat _ptrc_glVertexArrayAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat _ptrc_glVertexArrayAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat _ptrc_glVertexArrayAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor _ptrc_glVertexArrayBindingDivisor
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer _ptrc_glVertexArrayElementBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer _ptrc_glVertexArrayVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers _ptrc_glVertexArrayVertexBuffers

enum ogl_LoadStatus
{
	ogl_LOAD_FAILED = 0,
	ogl_LOAD_SUCCEEDED = 1,
};

int ogl_LoadFunctions();

int ogl_GetMinorVersion(void);
int ogl_GetMajorVersion(void);
int ogl_IsVersionGEQ(int majorVersion, int minorVersion);

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*POINTER_C_GENERATED_HEADER_OPENGL_H*/
