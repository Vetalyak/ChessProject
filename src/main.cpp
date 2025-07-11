#include <iostream>
#include <string>

#include "Piece.h"
#include "Rook.h"

int main() {
	std::cout << "Hello world" << std::endl;
	Piece* piece = new Rook(0, 0, PieceType::ROOK, PieceColor::WHITE);

	bool isvalid = piece->isValidMove(1, 1, 1);
	std::cout << std::boolalpha << isvalid << std::endl;

	delete piece;

	return 0;
}
