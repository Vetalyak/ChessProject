#include <iostream>
#include <string>

#include "Piece.h"
#include "Queen.h"

int main() {
	std::cout << std::boolalpha << "Chess Program VERSION 1.0" << std::endl;
	Board board;
	board.placePiece(std::make_unique<Queen>(0, 0, PieceType::QUEEN, PieceColor::WHITE), 0, 0);
	Piece* piece = board.getPieceAt(0, 0);
	std::cout << piece->isValidMove(20, 2, board) << std::endl;
	std::cout << piece->isValidMove(0, 2, board) << std::endl;
	std::cout << piece->isValidMove(3, 0, board) << std::endl;
	std::cout << piece->isValidMove(3, 4, board) << std::endl;
	std::cout << piece->isValidMove(-1, 3, board) << std::endl;
	return 0;
}
