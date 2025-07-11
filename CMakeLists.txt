cmake_minimum_required(VERSION 3.15)

project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chess 
    src/main.cpp
    src/Piece.h
    src/Piece.cpp
    src/Rook.h
    src/Rook.cpp
    src/Board.h
    src/Board.cpp
)
