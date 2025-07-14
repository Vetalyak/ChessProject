#pragma once

#include <memory>

#include "pieces/piece.h"
#include "pieces/rook.h"
#include "pieces/knight.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "pieces/pawn.h"

class PieceFactory {
public:
    static std::unique_ptr<Piece> create(int row, int col, PieceType type, PieceColor color);
};