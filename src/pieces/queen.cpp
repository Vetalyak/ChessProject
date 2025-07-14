#include "queen.h"
#include <cmath>

bool Queen::canMoveAccordingToRules(int newRow, int newCol, const Board &board) const {
    int dx = abs(newCol - col);
    int dy = abs(newRow - row);
    if ((dx != dy) && (row != newRow && col != newCol)) {
        return false;
    }
    return !board.hasPieceOnPath(row, col, newRow, newCol);
}

char Queen::getSymbol() const { return color == PieceColor::WHITE ? 'Q' : 'q'; }