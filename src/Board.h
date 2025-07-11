#pragma once

#include <vector>
#include <memory>

#include "Piece.h"
#include "Rook.h"

using PiecePtr = std::unique_ptr<Piece>;

class Board {
private:
    std::vector<std::vector<PiecePtr>> chessBoard;

public:
    Board();    

    static bool isValidCoords(int row, int col);

    bool hasPieceOnPath(int row, int col, int newRow, int newCol) const;
    Piece* getPieceAt(int row, int col) const;

    void placePiece(PiecePtr piece, int row, int col);

};