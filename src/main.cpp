#include <iostream>
#include <string>

#include "Board.h"
#include "Pieces/Piece.h"
#include "Renderer.h"

int main() {
	std::cout << std::boolalpha << "Chess Program VERSION 0.0.1" << std::endl;
	Board board;
	board.setUpDefaultPosition();
	ConsoleBoardRenderer renderer;
	renderer.render(board);
	return 0;
}
