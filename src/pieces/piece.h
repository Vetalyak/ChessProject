#pragma once

#include "board.h"

enum class PieceColor { WHITE, BLACK};
enum class PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

class Piece {
public:
    Piece(int row, int col, PieceType type, PieceColor color);
    virtual ~Piece() = default;

    bool isValidMove(int newRow, int newCol, const Board& board) const;
    virtual bool canMoveAccordingToRules(int newRow, int newCol, const Board& board) const = 0;

    virtual char getSymbol() const = 0;
    PieceColor getColor() const { return color; }
    PieceType getType() const { return type; }
    int getRow() const { return row; }
    int getCol() const { return col; }

    void setPosition(int newRow, int newCol);
    
protected:
    const PieceColor color;
    const PieceType type;
    int row;
    int col;

    bool basicMoveCheks(int newRow, int newCol, const Board& board) const;
};
