#include <iostream>
#include <string>

#include "board.h"
#include "pieces/piece.h"
#include "renderer.h"
#include "utilities/fen.h"

int main() {
    std::cout << std::boolalpha << "Chess Program VERSION 0.0.1" << std::endl;
    Board board;
    FEN::applyPosition(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    ConsoleBoardRenderer renderer;
    renderer.render(board);
    return 0;
}
