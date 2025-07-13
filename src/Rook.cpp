#include "Rook.h"

bool Rook::isValidMove(int newRow, int newCol, const Board& board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
        return false;
    }

    if (row != newRow && col != newCol) {
        return false;
    }

    if (board.hasPieceOnPath(row, col, newRow, newCol)) {
        return false;
    }
    return true;
}