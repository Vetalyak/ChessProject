#include "Piece.h"

Piece::Piece(int row, int col, PieceType type, PieceColor color) : row(row), col(col), type(type), color(color) {}

void Piece::setPosition(int newRow, int newCol) {
    this->row = newRow;
    this->col = newCol;
}
