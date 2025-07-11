#pragma once

#include <vector>
#include <memory>

class Piece;

using PiecePtr = std::unique_ptr<Piece>;

class Board {
private:
    std::vector<std::vector<PiecePtr>> chessBoard;

public:
    Board();

    static bool isValidCoords(int row, int col);

    bool hasPieceOnPath(int startRow, int startCol, int endRow, int endCol) const;
    Piece* getPieceAt(int row, int col) const;

    void placePiece(PiecePtr piece, int row, int col);

};