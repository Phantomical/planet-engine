# utils project CMake file

cmake_minimum_required(VERSION 2.8)

file(GLOB UTILS_SRCS
	"*.cpp"
	"*.h"
	"*.c"
)

set (UTILS_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} 
		CACHE INTERNAL "" FORCE
)

add_library(utils STATIC ${UTILS_SRCS})

# Find OpenGL libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Add OpenGL to link libraries
target_link_libraries(utils PRIVATE ${OPENGL_gl_LIBRARY})

# Add include dirs
target_include_directories(utils PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(utils PRIVATE ${GLFW_INCLUDE_DIRS})
target_include_directories(utils PUBLIC ${GLM_INCLUDE_DIRS})
