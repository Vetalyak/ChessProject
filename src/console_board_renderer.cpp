#include "renderer.h"
#include "board.h"
#include "pieces/piece.h"
#include <iostream>

void ConsoleBoardRenderer::render(const Board& board) {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = board.getPieceAt(row, col);
            if (piece) {
                std::cout << piece->getSymbol();
            } else {
                std::cout << "*";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}