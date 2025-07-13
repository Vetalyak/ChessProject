#pragma once

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    bool isValidMove(int newRow, int newCol, const Board& board) const override;
};