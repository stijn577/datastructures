cmake_minimum_required(VERSION 3.5.0)
include(CMakePrintHelpers)

project(datatructures VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(app)

add_compile_definitions(-DLINKED_LIST)

set(CMAKE_CXX_FLAGS  "-Wextra -Wall")

target_include_directories(app PUBLIC "lib")

FILE(GLOB_RECURSE SRC_FILES "src/*.cpp")
target_sources(app PRIVATE ${SRC_FILES})
target_sources(app PRIVATE main.cpp)

enable_testing()


