#include "Rook.h"

bool Rook::isValidMove(int newRow, int newCol, const Board& board) const {

    // 1. Only vertical or horizontal
    if (row != newRow && col != newCol) {
        return false;
    }

    // 2. Check path on board
    if (board.hasPieceOnPath(row, col, newRow, newCol)) {
        return false;
    }

    // 3. Check self beating
    Piece* target = board.getPieceAt(newRow, newCol);
    if (target != nullptr && target->getColor() == this->color) {
        return false;
    }
    
    return true;
}