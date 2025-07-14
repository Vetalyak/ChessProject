#include "bishop.h"
#include <cmath>

bool Bishop::canMoveAccordingToRules(int newRow, int newCol, const Board &board) const {
    int dx = abs(col - newCol);
    int dy = abs(row - newRow);
    if (dx != dy) {
        return false;
    }
    return !board.hasPieceOnPath(row, col, newRow, newCol);
}

char Bishop::getSymbol() const { return color == PieceColor::WHITE ? 'B' : 'b'; }