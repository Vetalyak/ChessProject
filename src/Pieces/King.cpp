#include "King.h"

bool King::isValidMove(int newRow, int newCol, const Board &board) const {
    if (!Piece::isValidMove(newRow, newCol, board)) {
        return false;
    }
    
    return true;
}

bool King::isChecked(const Board &board)
{
    return true;
}
