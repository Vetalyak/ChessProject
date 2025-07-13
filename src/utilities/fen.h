#pragma once

#include <string>

class Board;

class FEN {
public:
    static void applyPosition(Board& board, const std::string& fen);
};