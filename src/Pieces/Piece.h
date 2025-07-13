#pragma once

#include "Board.h"

enum class PieceColor { WHITE, BLACK};
enum class PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

class Piece {
protected:
	const PieceColor color;
	const PieceType type;
	int row;
	int col;

public:
	Piece(int row, int col, PieceType type, PieceColor color);
	virtual ~Piece() = default;

	virtual bool isValidMove(int newRow, int newCol, const Board& board) const;

	PieceColor getColor() const { return color; }
	PieceType getType() const { return type; }
	int getRow() const { return row; }
	int getCol() const { return col; }

	void setPosition(int newRow, int newCol);
};
