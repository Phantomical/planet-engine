# App CMake build file

file (GLOB app_sources
	"*.cpp"
	"*.h"
	"*.c"
)

add_executable(app ${app_sources})

find_package(GLFW3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

# Dependency include directories
target_include_directories(app PRIVATE ${UTILS_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${RCMGR_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${SURFACE_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${RENDER_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${OPENGL_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${GLFW3_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${GLM_INCLUDE_DIRS})

# Dependencies
add_dependencies(app utils rcmgr surface render)

# Linker Libraries
target_link_libraries(app PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(app PRIVATE glfw utils rcmgr surface render)

# Copy rcmgr DLL to output directory
add_custom_command(TARGET app POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
		$<TARGET_FILE:rcmgr>
		$<TARGET_FILE_DIR:app>/$<TARGET_FILE_NAME:rcmgr>
)

# Copy shaders to output directory
file(GLOB shaders
	${CMAKE_CURRENT_SOURCE_DIR}/../render/*.glsl
)
foreach(file ${shaders})
	get_filename_component(shader ${file} NAME)
	add_custom_command(TARGET app POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
			${CMAKE_CURRENT_BINARY_DIR}/../render/${shader}
			$<TARGET_FILE_DIR:app>
	)
endforeach()
