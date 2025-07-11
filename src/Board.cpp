#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#include <cmath>

Board::Board() {
    chessBoard.resize(8);
    for (int i = 0; i < 8; ++i) {
        chessBoard[i].resize(8);
    }
}

void Board::setUpDefaultPosition() {
    for (int i = 0; i < 8; ++i) {
        placePiece(std::make_unique<Pawn>(1, i, PieceType::PAWN, PieceColor::WHITE));
        placePiece(std::make_unique<Pawn>(6, i, PieceType::PAWN, PieceColor::BLACK));
    }

    placePiece(std::make_unique<Rook>(0, 0, PieceType::ROOK, PieceColor::WHITE));
    placePiece(std::make_unique<Rook>(0, 7, PieceType::ROOK, PieceColor::WHITE));
    placePiece(std::make_unique<Rook>(7, 0, PieceType::ROOK, PieceColor::BLACK));
    placePiece(std::make_unique<Rook>(7, 7, PieceType::ROOK, PieceColor::BLACK));

    placePiece(std::make_unique<Knight>(0, 1, PieceType::KNIGHT, PieceColor::WHITE));
    placePiece(std::make_unique<Knight>(0, 6, PieceType::KNIGHT, PieceColor::WHITE));
    placePiece(std::make_unique<Knight>(7, 1, PieceType::KNIGHT, PieceColor::BLACK));
    placePiece(std::make_unique<Knight>(7, 6, PieceType::KNIGHT, PieceColor::BLACK));

    placePiece(std::make_unique<Bishop>(0, 2, PieceType::BISHOP, PieceColor::WHITE));
    placePiece(std::make_unique<Bishop>(0, 5, PieceType::BISHOP, PieceColor::WHITE));
    placePiece(std::make_unique<Bishop>(7, 2, PieceType::BISHOP, PieceColor::BLACK));
    placePiece(std::make_unique<Bishop>(7, 5, PieceType::BISHOP, PieceColor::BLACK));

    placePiece(std::make_unique<Queen>(0, 3, PieceType::QUEEN, PieceColor::WHITE));
    placePiece(std::make_unique<Queen>(7, 3, PieceType::QUEEN, PieceColor::BLACK));

    placePiece(std::make_unique<King>(0, 4, PieceType::KING, PieceColor::WHITE));
    placePiece(std::make_unique<King>(7, 4, PieceType::KING, PieceColor::BLACK));
}

bool Board::isValidCoords(int row, int col) {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

bool Board::hasPieceOnPath(int startRow, int startCol, int endRow, int endCol) const {
    int dx = abs(startCol - endCol);
    int dy = abs(startRow - endRow);

    // horizontal
    if (dy == 0) {
        int step = (endCol > startCol) ? 1 : -1;
        for (int i = startCol + step; i != endCol; i += step) {
            if (getPieceAt(startRow, i) != nullptr) {
                return true;
            }
        }
    }

    // vertical
    else if (dx == 0) {
        int step = (endRow > startRow) ? 1 : -1;
        for (int i = startRow + step; i != endRow; i += step) {
            if (getPieceAt(i, startCol) != nullptr) {
                return true;
            }
        }
    }

    // diagonal
    else if (dx == dy) {
        int rowStep = (endRow > startRow) ? 1 : -1;
        int colStep = (endCol > startCol) ? 1 : -1;

        int currentRow = startRow + rowStep;
        int currentCol = startCol + colStep;

        while (currentRow != endRow) {
            if (getPieceAt(currentRow, currentCol) != nullptr) {
                return true;
            }
            currentRow += rowStep;
            currentCol += colStep;
        }
    }
    return false;
}

Piece* Board::getPieceAt(int row, int col) const {
    if (isValidCoords(row, col)) {
        return chessBoard[row][col].get();
    }
    return nullptr;
}

void Board::placePiece(PiecePtr piece) {
    int row = piece.get()->getRow();
    int col = piece.get()->getCol();
    if (isValidCoords(row, col)) {
        chessBoard[row][col] = std::move(piece);
    }
}
