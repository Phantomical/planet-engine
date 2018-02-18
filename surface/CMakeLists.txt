# surface project CMake file

file (GLOB surface_sources
	"*.h"
	"*.cpp"
)

add_library(surface ${surface_sources})

add_dependencies(surface utils rcmgr)

# Find OpenGL libraries
find_package(glm REQUIRED)

# Add include dirs
target_include_directories(surface PUBLIC ${GLM_INCLUDE_DIRS})
target_include_directories(surface PRIVATE ${UTILS_INCLUDE_DIRS})

# Set include directories globally
set(SURFACE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
	CACHE INTERNAL "" FORCE
)
