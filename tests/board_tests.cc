#include <gtest/gtest.h>

#include "board.h"

#include "piece_factory.h"

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
    board.placePiece(PieceFactory::create(1, 2, PieceType::KING, PieceColor::BLACK));
    Piece* piece = board.getPieceAt(1, 2);
    EXPECT_EQ(piece->getType(), PieceType::KING);
    EXPECT_EQ(piece->getColor(), PieceColor::BLACK);
}

TEST(BoardTest, HasPieceOnPath) {
    Board board;
    board.placePiece(PieceFactory::create(4, 4, PieceType::PAWN, PieceColor::WHITE));
    EXPECT_TRUE(board.hasPieceOnPath(1, 1, 7, 7));
    EXPECT_TRUE(board.hasPieceOnPath(4, 0, 4, 7));
    EXPECT_TRUE(board.hasPieceOnPath(0, 4, 5, 4));

    EXPECT_FALSE(board.hasPieceOnPath(0, 0, 7, 1));
    EXPECT_FALSE(board.hasPieceOnPath(2, 2, 4, 4));
    EXPECT_FALSE(board.hasPieceOnPath(4, 4, 4, 5));
}

TEST(BoardTest, WhiteKingInCheckByRook) {
    Board board;

    board.placePiece(PieceFactory::create(0, 4, PieceType::KING, PieceColor::WHITE)); // e1
    board.placePiece(PieceFactory::create(0, 7, PieceType::ROOK, PieceColor::BLACK)); // h1

    EXPECT_TRUE(board.isKingInCheck(PieceColor::WHITE));
}

TEST(PawnTest, PawnForwardMove) {
    Board board;
    auto pawn = PieceFactory::create(1, 4, PieceType::PAWN, PieceColor::WHITE);

    EXPECT_TRUE(pawn->canMoveAccordingToRules(2, 4, board)); // e2 → e3
    EXPECT_TRUE(pawn->canMoveAccordingToRules(3, 4, board)); // e2 → e4 (перший хід)

    EXPECT_FALSE(pawn->canMoveAccordingToRules(2, 5, board)); // e2 → f3
}

TEST(RookTest, RookStraightMoves) {
    Board board;
    auto rook = PieceFactory::create(0, 0, PieceType::ROOK, PieceColor::WHITE);

    EXPECT_TRUE(rook->canMoveAccordingToRules(0, 5, board)); // a1 → f1
    EXPECT_TRUE(rook->canMoveAccordingToRules(7, 0, board)); // a1 → a8

    // Непрямий хід — не можна
    EXPECT_FALSE(rook->canMoveAccordingToRules(3, 3, board)); // a1 → d4
}