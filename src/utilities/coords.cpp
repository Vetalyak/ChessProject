#include "coords.h"

#include <cctype>
#include <stdexcept>

Coords stringToCoords(const std::string& notation) {
    if (notation.length() != 2) {
        throw std::invalid_argument("Notation must be 2 character long");
    }
    char fileChar = std::tolower(notation[0]);
    char rankChar = notation[1];

    if (fileChar < 'a' || fileChar > 'h' || rankChar < '1' || rankChar > '8') {
        throw std::invalid_argument("Invalid chess notation");
    }

    return {fileChar - 'a', rankChar - '1'};
}

std::string coordsToString(const Coords& coords) {
    int file = coords.first;
    int rank = coords.second;
    if (file < 0 || file > 7 || rank < 0 || rank > 7) {
        throw std::invalid_argument("Coordinates out of board range");
    }

    char fileChar = 'a' + file;
    char rankChar = '1' + rank;

    return std::string(1, fileChar) + std::string(1, rankChar);
}