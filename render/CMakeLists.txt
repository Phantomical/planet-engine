# render project CMake file

file(GLOB render_sources
	"*.cpp"
	"*.h"
	"*.c"
)

file(GLOB shaders
	"*.glsl"
)

add_library(render ${render_sources} ${shaders})

set(RENDER_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} 
	CACHE INTERNAL "" FORCE)

# We depend on OpenGL
find_package(OpenGL REQUIRED)
# GLM is also a dependency
find_package(GLM REQUIRED)

# Add OpenGL to link libraries
target_link_libraries(render PRIVATE ${OPENGL_gl_LIBRARY})

# Indicate the other targets we depend on
add_dependencies(render surface utils rcmgr glslpp)

# Make sure to include the utils include files
target_include_directories(render PRIVATE ${UTILS_INCLUDE_DIRS})

# Add include dirs
target_include_directories(render PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(render PUBLIC ${GLM_INCLUDE_DIRS})
target_include_directories(render PUBLIC ${SURFACE_INCLUDE_DIRS})
target_include_directories(render PRIVATE ${RCMGR_INCLUDE_DIRS})

# $(SolutionDir)glslpp "$(ProjectDir)%(Identity)" "$(TargetDir)%(Identity)" -I$(ProjectDir)

foreach(file ${shaders})
	get_filename_component(filename ${file} NAME)
	add_custom_command(TARGET render POST_BUILD
		COMMAND $<TARGET_FILE:glslpp>
			${file} ${CMAKE_CURRENT_BINARY_DIR}/${filename} 
			-I${CMAKE_CURRENT_SOURCE_DIR}/
	)
endforeach()
