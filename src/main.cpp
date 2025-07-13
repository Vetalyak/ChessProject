#include <iostream>
#include <string>

#include "Board.h"
#include "Pieces/Piece.h"

int main() {
	std::cout << std::boolalpha << "Chess Program VERSION 0.0.1" << std::endl;
	Board board;
	board.setUpDefaultPosition();
	
	return 0;
}
