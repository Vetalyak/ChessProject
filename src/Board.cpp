#include "Board.h"
#include "Piece.h"

Board::Board() {
    chessBoard.resize(8);
    for (int i = 0; i < 8; ++i) {
        chessBoard[i].resize(8);
    }
}

bool Board::isValidCoords(int row, int col) {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

bool Board::hasPieceOnPath(int row, int col, int newRow, int newCol) const {
    return false;
}

Piece* Board::getPieceAt(int row, int col) const
{
    if (isValidCoords(row, col)) {
        return chessBoard[row][col].get();
    }
    return nullptr;
}

void Board::placePiece(PiecePtr piece, int row, int col)
{
    if (isValidCoords(row, col)) {
        chessBoard[row][col] = std::move(piece);
    }
}
