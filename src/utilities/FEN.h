#pragma once

#include <string>
#include "Board.h"

class FEN {
public:
    static void applyPosition(Board& board, const std::string& fen);
};