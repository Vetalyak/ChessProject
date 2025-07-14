#include <iostream>
#include <string>

#include "board.h"
#include "pieces/piece.h"
#include "renderer.h"
#include "utilities/fen.h"

int main() {
    std::cout << std::boolalpha << "Chess Program VERSION 0.0.1" << std::endl;
    Board board;
    FEN::applyPosition(board, "rnb1kbnr/pppppppp/q7/4K3/4P3/1P2P3/PPP3PP/RNBQ1BNR w kq - 0 1");
    ConsoleBoardRenderer renderer;
    renderer.render(board);
    return 0;
}
