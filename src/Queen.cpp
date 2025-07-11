#include "Queen.h"
#include <cmath>

bool Queen::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Board::isValidCoords(newRow, newCol)) {
        return false;
    }

    Piece* target = board.getPieceAt(newRow, newCol);
    if (target != nullptr && target->getColor() == this->color) {
        return false;
    }

    int dx = abs(col - newCol);
    int dy = abs(row - newRow);
    if ((dx != dy) && (row != newRow && col != newCol)) {
        return false;
    }

    if (board.hasPieceOnPath(row, col, newRow, newCol)) {
        return false;
    }
    return true;
}