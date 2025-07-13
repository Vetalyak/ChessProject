#include "rook.h"

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

char Rook::getSymbol() const { return color == PieceColor::WHITE ? 'R' : 'r'; }
