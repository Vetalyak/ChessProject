#include "Queen.h"
#include <cmath>

bool Queen::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
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

char Queen::getSymbol() const { return color == PieceColor::WHITE ? 'Q' : 'q'; }