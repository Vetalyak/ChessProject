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
	return std::string();
}
