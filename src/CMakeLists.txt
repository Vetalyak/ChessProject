set(SOURCE_FILES 
    Pieces/Piece.cpp
    Pieces/Pawn.cpp
    Pieces/Rook.cpp
    Pieces/Knight.cpp
    Pieces/Bishop.cpp
    Pieces/Queen.cpp
    Pieces/King.cpp
    Board.cpp
    PieceFactory.cpp
)

add_library(chess ${SOURCE_FILES})
target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(chess_app main.cpp)
target_link_libraries(chess_app PRIVATE chess)
