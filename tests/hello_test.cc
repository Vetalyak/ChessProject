#include <gtest/gtest.h>

#include "Board.h"

#include "Pieces/Piece.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/Pawn.h"

TEST(BoardTest, IsDefaultPosition) {
    Board board;
    board.setUpDefaultPosition();
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(board.getPieceAt(1, i)->getType(), PieceType::PAWN);
        EXPECT_EQ(board.getPieceAt(1, i)->getColor(), PieceColor::WHITE);

        EXPECT_EQ(board.getPieceAt(6, i)->getType(), PieceType::PAWN);
        EXPECT_EQ(board.getPieceAt(6, i)->getColor(), PieceColor::BLACK);
    }
}

TEST(BoardTest, IsRightPiecePlaced) {
    Board board;
    board.placePiece(std::make_unique<King>(1, 2, PieceType::KING, PieceColor::BLACK));
    Piece* piece = board.getPieceAt(1, 2);
    EXPECT_EQ(piece->getType(), PieceType::KING);
    EXPECT_EQ(piece->getColor(), PieceColor::BLACK);
}

TEST(BoardTest, HasPieceOnPath) {
    Board board;
    board.placePiece(std::make_unique<Pawn>(4, 4, PieceType::PAWN, PieceColor::WHITE));
    EXPECT_TRUE(board.hasPieceOnPath(1, 1, 7, 7));
    EXPECT_TRUE(board.hasPieceOnPath(4, 0, 4, 7));
    EXPECT_TRUE(board.hasPieceOnPath(0, 4, 5, 4));

    EXPECT_FALSE(board.hasPieceOnPath(0, 0, 7, 1));
    EXPECT_FALSE(board.hasPieceOnPath(2, 2, 4, 4));
    EXPECT_FALSE(board.hasPieceOnPath(4, 4, 4, 5));
}

TEST(PieceTest, IsValidRookMove) {
    Board board;
    board.setUpDefaultPosition();
    Piece* rock = board.getPieceAt(0, 0);
    EXPECT_FALSE(rock->isValidMove(7, 0, board));
    EXPECT_FALSE(rock->isValidMove(1, 0, board));
    EXPECT_FALSE(rock->isValidMove(2, 0, board));
    EXPECT_FALSE(rock->isValidMove(3, 2, board));

    board.placePiece(std::make_unique<Rook>(3, 3, PieceType::ROOK, PieceColor::BLACK));
    Piece* rock1 = board.getPieceAt(3, 3);
    EXPECT_TRUE(rock1->isValidMove(1, 3, board));
    EXPECT_TRUE(rock1->isValidMove(3, 5, board));
    EXPECT_TRUE(rock1->isValidMove(3, 1, board));
    EXPECT_TRUE(rock1->isValidMove(5, 3, board));
}