#include <iostream>
#include <string>

#include "Board.h"
#include "Pieces/Piece.h"
#include "Renderer.h"
#include "utilities/FEN.h"

int main() {
	std::cout << std::boolalpha << "Chess Program VERSION 0.0.1" << std::endl;
	Board board;
	FEN::applyPosition(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	ConsoleBoardRenderer renderer;
	renderer.render(board);
	return 0;
}
