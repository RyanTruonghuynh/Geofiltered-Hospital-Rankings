#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <iostream>

std::unordered_map<std::string, std::pair<double, double>> loadCityCoords(const std::string& filename) {
    std::unordered_map<std::string, std::pair<double, double>> coords;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open city coordinates file " << filename << ". Check the file path." << std::endl;
        return coords;
    }

    std::string line;
    bool isHeader = true;
    while (std::getline(file, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }

        // Remove trailing carriage return if present
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        std::stringstream ss(line);
        std::string field;

        // 1. Read City (0)
        std::getline(ss, field, ',');
        std::string city = field.substr(1, field.length() - 2); // Remove quotes

        // 2. Read city_ascii (1) - Discard
        std::getline(ss, field, ',');

        // 3. Read State ID (2) - Store
        std::getline(ss, field, ',');
        std::string state = field.substr(1, field.length() - 2); // Remove quotes

        // 4. Read state_name (3) - Discard
        std::getline(ss, field, ',');

        // 5. Read county_fips (4) - Discard
        std::getline(ss, field, ',');

        // 6. Read county_name (5) - Discard
        std::getline(ss, field, ',');

        // 7. Read Latitude (6) - Store
        std::getline(ss, field, ',');
        std::string lat = field.substr(1, field.length() - 2); // Remove quotes

        // 8. Read Longitude (7) - Store
        std::getline(ss, field, ',');
        std::string lon = field.substr(1, field.length() - 2); // Remove quotes

        // Now process the extracted fields
        if (city.empty() || state.empty() || lat.empty() || lon.empty()) continue;

        try {
            double latitude = std::stod(lat);
            double longitude = std::stod(lon);

            coords[city + "," + state] = {latitude, longitude};
        } catch (...) {
            std::cerr << "Skipping row due to non-numeric coordinates or data error for: " << city << ", " << state << "\n";
            continue;
        }
    }

    std::cout << "Loaded " << coords.size() << " city coordinates.\n";
    return coords;
}