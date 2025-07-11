cmake_minimum_required(VERSION 3.15)

project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Chess 
    src/main.cpp
    src/Piece.cpp
    src/Pawn.cpp
    src/Rook.cpp
    src/Knight.cpp
    src/Bishop.cpp
    src/Queen.cpp
    src/King.cpp
    src/Board.cpp
)

target_include_directories(Chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()

add_executable(hello_test tests/hello_test.cc)
target_link_libraries(hello_test GTest::gtest_main)