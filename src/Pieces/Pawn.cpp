#include "Pawn.h"

bool Pawn::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
        return false;
    }
    return true;
}

char Pawn::getSymbol() const { return color == PieceColor::WHITE ? 'P' : 'p'; }