#include <gtest/gtest.h>

#include "board.h"
#include "piece_factory.h"
#include "utilities/fen.h"

class BoardTest : public ::testing::Test {
protected:
    Board board;

    void SetUp() override {
        board.placePiece(PieceFactory::create(0, 4, PieceType::KING, PieceColor::WHITE));
        board.placePiece(PieceFactory::create(7, 4, PieceType::KING, PieceColor::BLACK));
    }

    void TearDown() override {
        // cleanup
    }
};

TEST_F(BoardTest, IsDefaultPosition) {
    FEN::applyPosition(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(board.getPieceAt(1, i)->getType(), PieceType::PAWN);
        EXPECT_EQ(board.getPieceAt(1, i)->getColor(), PieceColor::WHITE);

        EXPECT_EQ(board.getPieceAt(6, i)->getType(), PieceType::PAWN);
        EXPECT_EQ(board.getPieceAt(6, i)->getColor(), PieceColor::BLACK);
    }
}

TEST_F(BoardTest, IsPiecePlaced) {
    board.placePiece(PieceFactory::create(4, 4, PieceType::BISHOP, PieceColor::BLACK));
    Piece* piece = board.getPieceAt(4, 4);
    EXPECT_EQ(piece->getType(), PieceType::BISHOP);
    EXPECT_EQ(piece->getColor(), PieceColor::BLACK);
}

TEST_F(BoardTest, IsPieceRemoved) {
    board.placePiece(PieceFactory::create(1, 1, PieceType::KNIGHT, PieceColor::WHITE));
    board.removePieceAt(1, 1);
    EXPECT_EQ(board.getPieceAt(1, 1), nullptr);
}

TEST_F(BoardTest, HasPieceOnPath) {
    board.placePiece(PieceFactory::create(4, 4, PieceType::PAWN, PieceColor::WHITE));
    EXPECT_TRUE(board.hasPieceOnPath(1, 1, 7, 7));
    EXPECT_TRUE(board.hasPieceOnPath(4, 0, 4, 7));
    EXPECT_TRUE(board.hasPieceOnPath(0, 4, 5, 4));

    EXPECT_FALSE(board.hasPieceOnPath(0, 0, 7, 1));
    EXPECT_FALSE(board.hasPieceOnPath(2, 2, 4, 4));
    EXPECT_FALSE(board.hasPieceOnPath(4, 4, 4, 5));
}

TEST_F(BoardTest, WhiteKingInCheckByQueen) {
    FEN::applyPosition(board, "4k3/8/2b5/3p4/2P1N3/3B4/4K3/3q2r1 w - - 0 1");
    EXPECT_TRUE(board.isKingInCheck(PieceColor::WHITE));
    EXPECT_FALSE(board.isKingInCheck(PieceColor::BLACK));
}

TEST_F(BoardTest, BlackKingInCheckByKnight) {
    FEN::applyPosition(board, "4k3/8/2bN4/3p4/2P5/3B4/4K3/1q4r1 w - - 0 1");
    EXPECT_TRUE(board.isKingInCheck(PieceColor::BLACK));
    EXPECT_FALSE(board.isKingInCheck(PieceColor::WHITE));
}

TEST_F(BoardTest, PawnForwardMove) {
    FEN::applyPosition(board, "rn1qk1nr/ppp1pp1p/3p2p1/8/8/2b2b2/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Piece* pawn1 = board.getPieceAt(1, 3);
    EXPECT_FALSE(pawn1->isValidMove(2, 3, board));
    EXPECT_FALSE(pawn1->isValidMove(3, 3, board));
    EXPECT_TRUE(pawn1->isValidMove(2, 2, board));

    Piece* pawn2 = board.getPieceAt(1, 4);
    EXPECT_TRUE(pawn2->isValidMove(2, 4, board));
    EXPECT_TRUE(pawn2->isValidMove(3, 4, board));
    EXPECT_TRUE(pawn2->isValidMove(2, 5, board));
}

TEST_F(BoardTest, RookMoves) {
    FEN::applyPosition(board, "rnbqkbnr/1pppppp1/8/8/8/8/1PPPPPP1/RNBQKBNR w KQkq - 0 1");
    Piece* whiteRook = board.getPieceAt(0, 0);
    EXPECT_TRUE(whiteRook->isValidMove(7, 0, board));
    EXPECT_FALSE(whiteRook->isValidMove(0, 1, board));

    Piece* blackRook = board.getPieceAt(7, 7);
    EXPECT_TRUE(blackRook->isValidMove(0, 7, board));
    EXPECT_FALSE(blackRook->isValidMove(7, 6, board));
}