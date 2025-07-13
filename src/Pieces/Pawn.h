#pragma once

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    bool isValidMove(int newRow, int newCol, const Board& board) const override;
    char getSymbol() const override;
};