#include "board.h"
#include "piece_factory.h"

#include <cmath>
#include <stdexcept>

Board::Board() {
    chessBoard.resize(8);
    for (int i = 0; i < 8; ++i) {
        chessBoard[i].resize(8);
    }
}

Board::Board(const Board &other) {
    chessBoard.resize(8);
    for (int i = 0; i < 8; ++i) {
        chessBoard[i].resize(8);
    }

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (other.chessBoard[row][col]) {
                chessBoard[row][col] = other.chessBoard[row][col]->clone();
            }
        }
    }
}

Board& Board::operator=(const Board &other) {
    if (this == &other) return *this;
        for (auto& row : chessBoard) {
            for (auto& cell : row) {
                cell.reset();
            }
        }
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                if (other.chessBoard[row][col]) {
                    chessBoard[row][col] = other.chessBoard[row][col]->clone();
                }
            }
        }
    return *this;
}

void Board::setUpDefaultPosition() {
    for (int i = 0; i < 8; ++i) {
        placePiece(PieceFactory::create(1, i, PieceType::PAWN, PieceColor::WHITE));
        placePiece(PieceFactory::create(6, i, PieceType::PAWN, PieceColor::BLACK));
    }

    placePiece(PieceFactory::create(0, 7, PieceType::ROOK, PieceColor::WHITE));
    placePiece(PieceFactory::create(0, 0, PieceType::ROOK, PieceColor::WHITE));
    placePiece(PieceFactory::create(7, 0, PieceType::ROOK, PieceColor::BLACK));
    placePiece(PieceFactory::create(7, 7, PieceType::ROOK, PieceColor::BLACK));

    placePiece(PieceFactory::create(0, 1, PieceType::KNIGHT, PieceColor::WHITE));
    placePiece(PieceFactory::create(0, 6, PieceType::KNIGHT, PieceColor::WHITE));
    placePiece(PieceFactory::create(7, 1, PieceType::KNIGHT, PieceColor::BLACK));
    placePiece(PieceFactory::create(7, 6, PieceType::KNIGHT, PieceColor::BLACK));

    placePiece(PieceFactory::create(0, 2, PieceType::BISHOP, PieceColor::WHITE));
    placePiece(PieceFactory::create(0, 5, PieceType::BISHOP, PieceColor::WHITE));
    placePiece(PieceFactory::create(7, 2, PieceType::BISHOP, PieceColor::BLACK));
    placePiece(PieceFactory::create(7, 5, PieceType::BISHOP, PieceColor::BLACK));

    placePiece(PieceFactory::create(0, 3, PieceType::QUEEN, PieceColor::WHITE));
    placePiece(PieceFactory::create(7, 3, PieceType::QUEEN, PieceColor::BLACK));

    placePiece(PieceFactory::create(0, 4, PieceType::KING, PieceColor::WHITE));
    placePiece(PieceFactory::create(7, 4, PieceType::KING, PieceColor::BLACK));
}

bool Board::isValidCoords(int row, int col) {
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

void Board::movePiece(int startRow, int startCol, int endRow, int endCol) {
    
}

bool Board::isKingInCheck(PieceColor color) const {
    int kingRow = -1;
    int kingCol = -1;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            const auto piece = getPieceAt(row, col);
            if (piece && piece->getType() == PieceType::KING && piece->getColor() == color) {
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }

    if (kingRow == -1 || kingCol == -1) 
        throw std::runtime_error("King not found on the board!");

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            const auto piece = getPieceAt(row, col);
            if (piece && piece->getColor() != color) {
                if (piece->canMoveAccordingToRules(kingRow, kingCol, *this)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::hasPieceOnPath(int startRow, int startCol, int endRow, int endCol) const
{
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

bool Board::isValidMove(const Piece *piece, int newRow, int newCol) const {
    return piece->isValidMove(newRow, newCol, *this);
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

void Board::removePieceAt(int row, int col) {
    if (!isValidCoords(row, col)) return;
    chessBoard[row][col] = nullptr;
}

void Board::clear() {
    for (auto& row : chessBoard) {
        for (auto& cell : row) {
            cell.reset();
        }
    }
}
