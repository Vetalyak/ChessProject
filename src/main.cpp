#include <iostream>
#include <string>

#include "Piece.h"
#include "Queen.h"

int main() {
	std::cout << std::boolalpha << "Chess Program VERSION 1.0" << std::endl;
	Board board;
	board.setUpDefaultPosition();
	return 0;
}
