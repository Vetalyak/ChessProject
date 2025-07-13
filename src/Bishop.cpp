#include "Bishop.h"
#include <cmath>

bool Bishop::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
        return false;
    }

    int dx = abs(col - newCol);
    int dy = abs(row - newRow);
    if (dx != dy) {
        return false;
    }

    if (board.hasPieceOnPath(row, col, newRow, newCol)) {
        return false;
    }
    return true;
}