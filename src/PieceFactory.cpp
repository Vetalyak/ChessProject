#include "PieceFactory.h"
#include <stdexcept>

std::unique_ptr<Piece> PieceFactory::create(int row, int col, PieceType type, PieceColor color)
{
    switch (type)
    {
    case PieceType::ROOK: return std::make_unique<Rook>(row, col, type, color);
    case PieceType::KNIGHT: return std::make_unique<Knight>(row, col, type, color);
    case PieceType::BISHOP: return std::make_unique<Bishop>(row, col, type, color);
    case PieceType::QUEEN: return std::make_unique<Queen>(row, col, type, color);
    case PieceType::KING: return std::make_unique<King>(row, col, type, color);
    case PieceType::PAWN: return std::make_unique<Pawn>(row, col, type, color);
    default:
        throw std::invalid_argument("Unknown piece type");
    }
}