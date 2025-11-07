#pragma once

#include "hospital.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <utility> // For std::pair

void assignCoordinates(
    std::vector<Hospital>& hospitals,
    const std::unordered_map<std::string, std::pair<double, double>>& cityCoords);