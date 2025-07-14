#include "knight.h"
#include <cmath>

bool Knight::canMoveAccordingToRules(int newRow, int newCol, const Board &board) const {
    int dx = abs(newCol - col);
    int dy = abs(newRow - row);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

char Knight::getSymbol() const { return color == PieceColor::WHITE ? 'N' : 'n'; }