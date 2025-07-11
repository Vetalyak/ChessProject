#pragma once

enum class PieceColor { WHITE, BLACK};
enum class PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

class Piece {
protected:
	const PieceColor color;
	const PieceType type;
	int row;
	int col;

public:
	Piece();
	virtual ~Piece() = default;

	virtual bool isValidMoove(int newRow, int newCol, const int& board) const = 0;

	PieceColor getColor() const { return color; }
	PieceType getType() const { return type; }
	int getRow() const { return row; }
	int getCol() const { return col; }

	void setPosition(int newRow, int newCol);
};
