#include "piece.h"

Piece::Piece(int row, int col, PieceType type, PieceColor color) : row(row), col(col), type(type), color(color) {}

bool Piece::basicMoveCheks(int newRow, int newCol, const Board &board) const {
    if (!Board::isValidCoords(newRow, newCol)) return false;
    if (newRow == row && newCol == col) return false;

    auto target = board.getPieceAt(newRow, newCol);
    if (target && target->getColor() == this->color) return false;
    return true;
}

bool Piece::isValidMove(int newRow, int newCol, const Board& board) const {
    if (!basicMoveCheks(newRow, newCol, board)) return false;
    if (!canMoveAccordingToRules(newRow, newCol, board)) return false;

    Board tempBoard = board;
    tempBoard.movePiece(row, col, newRow, newCol);

    return !tempBoard.isKingInCheck(color);
}

void Piece::setPosition(int newRow, int newCol) {
    this->row = newRow;
    this->col = newCol;
}
