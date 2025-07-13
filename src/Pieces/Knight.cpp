#include "Knight.h"
#include <cmath>

bool Knight::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
        return false;
    }

    int dx = abs(col - newCol);
    int dy = abs(row - newRow);
    if ((dx != 2 && dy != 1) || (dx != 1 && dy != 2)) {
        return false;
    }
    return true;
}

char Knight::getSymbol() const { return color == PieceColor::WHITE ? 'N' : 'n'; }