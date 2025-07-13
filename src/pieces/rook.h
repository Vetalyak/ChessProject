#pragma once

#include "piece.h"

class Rook : public Piece {
public:
    Rook(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    bool isValidMove(int newRow, int newCol, const Board& board) const override;
    char getSymbol() const override;
};