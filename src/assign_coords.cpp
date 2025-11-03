#include "hospital.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

void assignCoordinates(
    std::vector<Hospital>& hospitals,
    const std::unordered_map<std::string, std::pair<double, double>>& cityCoords)
{
    int matched = 0;
    int unmatched = 0;

    for (auto& h : hospitals) {
        std::string key = h.city + "," + h.state;

        auto it = cityCoords.find(key);
        if (it != cityCoords.end()) {
            h.latitude = it->second.first;
            h.longitude = it->second.second;
            matched++;
        } else {
            unmatched++;
        }
    }

    std::cout << "Coordinate assignment complete:\n";
    std::cout << "  Matched:   " << matched << " hospitals\n";
    std::cout << "  Unmatched: " << unmatched << " hospitals\n";
}