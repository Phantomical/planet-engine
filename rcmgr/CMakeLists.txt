# rcmgr project CMake file

cmake_minimum_required(VERSION 2.8)

file(GLOB RCMGR_SRCS
	"*.cpp"
	"*.h"
)

# Get source files
set (RCMGR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} 
	CACHE INTERNAL "" FORCE
)

# Set output library
add_library(rcmgr SHARED ${RCMGR_SRCS})

# Find OpenGL libraries
find_package(OpenGL REQUIRED)

# Add OpenGL to link libraries
target_link_libraries(rcmgr PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(rcmgr PRIVATE utils)

target_include_directories(rcmgr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../utils)

# Indicate that we are building rcmgr
add_definitions(-DRCMGR_EXPORTS)

# rcmgr depends on utils
add_dependencies(rcmgr utils)

# Set some global variable so the rest of the projects can include the headers
set (RCMGR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
	CACHE INTERNAL "" FORCE
)
