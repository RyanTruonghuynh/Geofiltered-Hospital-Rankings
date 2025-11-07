#pragma once

#include "hospital.h"
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::pair<double, double>> loadCityCoords(const std::string& filename);