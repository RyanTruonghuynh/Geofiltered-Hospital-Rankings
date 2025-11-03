#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <iostream>

std::unordered_map<std::string, std::pair<double, double>> loadCityCoords(const std::string& filename) {
    std::unordered_map<std::string, std::pair<double, double>> coords;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open city coordinates file " << filename << std::endl;
        return coords;
    }

    std::string line;
    bool isHeader = true;
    while (std::getline(file, line)) {
        if (isHeader) { isHeader = false; continue; }

        std::stringstream ss(line);
        std::string city, state, lat, lon;
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, lat, ',');
        std::getline(ss, lon, ',');

        if (city.empty() || state.empty()) continue;
        try {
            double latitude = std::stod(lat);
            double longitude = std::stod(lon);
            coords[city + "," + state] = {latitude, longitude};
        } catch (...) {
            continue;
        }
    }

    std::cout << "Loaded " << coords.size() << " city coordinates.\n";
    return coords;
}