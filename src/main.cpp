#include "hospital.h"
#include "parsing.h"
#include <vector>
#include <unordered_map>
#include <iostream>

void assignCoordinates(std::vector<Hospital>& hospitals,
                       const std::unordered_map<std::string, std::pair<double, double>>& coords)
{
    int matched = 0;
    for (auto& h : hospitals) {
        std::string key = h.city + "," + h.state;
        if (coords.count(key)) {
            h.latitude = coords.at(key).first;
            h.longitude = coords.at(key).second;
            matched++;
        }
    }
    std::cout << "Coordinates matched for " << matched << " of " << hospitals.size() << " hospitals.\n";
}
