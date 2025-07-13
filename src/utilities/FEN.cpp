#include "FEN.h"
#include "PieceFactory.h"
#include <cctype>
#include <stdexcept>


void FEN::applyPosition(Board &board, const std::string &fen) {
    int row = 7;
    int col = 0;

    for (char c : fen) {
        if (c == ' ') break;

        if (c == '/') {
            --row;
            col = 0;
        } else if(isdigit(c)) {
            col += c - '0';
        } else {
            PieceColor color = isupper(c) ? PieceColor::WHITE : PieceColor::BLACK;
            PieceType type;

            switch (tolower(c)) {
                case 'p': type = PieceType::PAWN; break;
                case 'r': type = PieceType::ROOK; break;
                case 'n': type = PieceType::KNIGHT; break;
                case 'b': type = PieceType::BISHOP; break;
                case 'q': type = PieceType::QUEEN; break;
                case 'k': type = PieceType::KING; break;
                default:
                    throw std::runtime_error("Invalid FEN char");
            }
            auto piece = PieceFactory::create(row, col, type, color);
            board.placePiece(std::move(piece));
            ++col;
        }
    }
}