cmake_minimum_required(VERSION 3.5.0)
include(CMakePrintHelpers)

project(my_cmake_project VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_compile_definitions(-DLINKED_LIST)

set(CMAKE_CXX_FLAGS  "-Wextra -Wall")

enable_testing()

add_subdirectory(app)
add_subdirectory(datastructures)
# add_subdirectory(tests)
