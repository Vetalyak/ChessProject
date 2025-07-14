#include "king.h"
#include <cmath>

PiecePtr King::clone() const {
    return std::make_unique<King>(*this);;
}

bool King::canMoveAccordingToRules(int newRow, int newCol, const Board &board) const
{
    int dx = abs(newCol - col);
    int dy = abs(newRow - row);

    return dx <= 1 && dy <= 1 && !(dx == 0 && dy == 0);
}

char King::getSymbol() const { return color == PieceColor::WHITE ? 'K' : 'k'; }
