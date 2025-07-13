set(SOURCE_FILES 
    pieces/piece.cpp
    pieces/pawn.cpp
    pieces/rook.cpp
    pieces/knight.cpp
    pieces/bishop.cpp
    pieces/queen.cpp
    pieces/king.cpp
    board.cpp
    console_board_renderer.cpp
    piece_factory.cpp
    utilities/fen.cpp
    utilities/coords.cpp
)

add_library(chess ${SOURCE_FILES})
target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(chess_app main.cpp)
target_link_libraries(chess_app PRIVATE chess)
