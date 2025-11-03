#pragma once

#include "hospital.h"
#include <string>
#include <vector>
#include <unordered_map>


std::vector<Hospital> parseHospitalCSV(const std::string& filename);
std::unordered_map<std::string, std::pair<double, double>> 
loadCityCoords(const std::string& filename);

void assignCoordinates(
    std::vector<Hospital>& hospitals,
    const std::unordered_map<std::string, std::pair<double, double>>& cityCoords);