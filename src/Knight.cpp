#include "Knight.h"
#include <cmath>

bool Knight::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Board::isValidCoords(newRow, newCol)) {
        return false;
    }
    
    Piece* target = board.getPieceAt(newRow, newCol);
    if (target != nullptr && target->getColor() == this->color) {
        return false;
    }

    int dx = abs(col - newCol);
    int dy = abs(row - newRow);
    if ((dx != 2 && dy != 1) || (dx != 1 && dy != 2)) {
        return false;
    }
    
    
    return true;
}