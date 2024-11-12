add_library(datastructures STATIC)

# include directories
target_include_directories(datastructures PUBLIC ${CMAKE_SOURCE_DIR}/datastructures/lib)

# source files
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
target_sources(datastructures PRIVATE ${SRC_FILES})
