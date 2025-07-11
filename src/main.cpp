#include <iostream>
#include <string>

#include "Piece.h"
#include "Rook.h"

int main() {
	std::cout << "Hello world" << std::endl;
	Board board;
	board.placePiece(std::make_unique<Rook>(0, 0, PieceType::ROOK, PieceColor::WHITE), 0, 0);
	Piece* piece = board.getPieceAt(0, 0);
	
	return 0;
}
