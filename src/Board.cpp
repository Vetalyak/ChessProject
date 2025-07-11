#include "Board.h"

Board::Board() {
    chessBoard.resize(8, std::vector<PiecePtr>(8, nullptr));
}

bool Board::isValidCoords(int row, int col) {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

Piece *Board::getPieceAt(int row, int col) const {
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
