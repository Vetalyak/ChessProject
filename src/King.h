#pragma once

#include "Piece.h"

class King : public Piece {
public:
    King(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    bool isValidMove(int newRow, int newCol, const Board& board) const override;
};