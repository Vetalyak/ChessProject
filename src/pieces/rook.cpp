#include "rook.h"

PiecePtr Rook::clone() const {
    return std::make_unique<Rook>(*this);
}

bool Rook::canMoveAccordingToRules(int newRow, int newCol, const Board &board) const
{
    if (row != newRow && col != newCol) {
        return false;
    }

    return !board.hasPieceOnPath(row, col, newRow, newCol);
}

char Rook::getSymbol() const { return color == PieceColor::WHITE ? 'R' : 'r'; }
