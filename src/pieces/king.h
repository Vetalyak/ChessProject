#pragma once

#include "piece.h"

class King : public Piece {
public:
    King(int row, int col, PieceType type, PieceColor color) : Piece(row, col, type, color) {}

    PiecePtr clone() const override;

    bool canMoveAccordingToRules(int newRow, int newCol, const Board& board) const override;

    char getSymbol() const override;
};