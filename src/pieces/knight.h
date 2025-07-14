#pragma once

#include "piece.h"

class Knight : public Piece {
public:
    Knight(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    bool canMoveAccordingToRules(int newRow, int newCol, const Board& board) const override;
    char getSymbol() const override;
};