include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(test_linked_list test_linked_list.cpp)

target_link_libraries(test_linked_list PRIVATE GTest::GTest datastructures)

add_test(NAME test_linked_list COMMAND ${CMAKE_BINARY_DIR}/bin/test_linked_list)

enable_testing()
