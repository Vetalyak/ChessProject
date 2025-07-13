#include "Pawn.h"
#include <cmath>

bool Pawn::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Board::isValidCoords(newRow, newCol)) {
        return false;
    }
    int dir = (color == PieceColor::WHITE) ? 1 : -1;
    int dy = newRow - row;
    int dx = newCol - col;

    auto target = board.getPieceAt(newRow, newCol);

    // 1 square forward
    if (dx == 0 && dy == dir) {
        if (target == nullptr) return true;
    }

    // 2 squares forward
    if (dx == 0 && dy == 2 * dir) {
        int startRow = (color == PieceColor::WHITE) ? 1 : 6;
        if (row == startRow) {
            if (target == nullptr && board.getPieceAt(row + dir, col) == nullptr) {
                return true;
            }
        }
    }

    // 3 diagonal capture
    if (abs(dx) == 1 && dy == dir) {
        if (target != nullptr && target->getColor() != color) {
            return true;
        }
    }

    return false;
}

char Pawn::getSymbol() const { return color == PieceColor::WHITE ? 'P' : 'p'; }