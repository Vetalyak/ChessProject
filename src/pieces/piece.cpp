#include "piece.h"

Piece::Piece(int row, int col, PieceType type, PieceColor color) : row(row), col(col), type(type), color(color) {}

bool Piece::isValidMove(int newRow, int newCol, const Board& board) const {
     if (!Board::isValidCoords(newRow, newCol)) {
        return false;
    }

    Piece* target = board.getPieceAt(newRow, newCol);
    if (target != nullptr && target->getColor() == this->color) {
        return false;
    }
    return true;
}

void Piece::setPosition(int newRow, int newCol) {
    this->row = newRow;
    this->col = newCol;
}
