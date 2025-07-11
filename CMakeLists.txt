cmake_minimum_required(VERSION 3.15)

project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
