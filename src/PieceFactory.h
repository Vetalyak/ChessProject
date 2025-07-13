#pragma once

#include <memory>

#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/Pawn.h"

class PieceFactory {
public:
	static std::unique_ptr<Piece> create(int row, int col, PieceType type, PieceColor color);
};