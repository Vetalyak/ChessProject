#pragma once

#include <string>
#include <utility>

using Coords = std::pair<int, int>;

Coords stringToCoords(const std::string& notation);

std::string coordsToString(const Coords& coords);

