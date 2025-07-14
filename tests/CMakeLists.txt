enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(chess_tests
    board_tests.cc
)

target_link_libraries(chess_tests PRIVATE chess GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(chess_tests)
