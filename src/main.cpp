#include "hospital.h"
#include "parsing.h"
#include "user_prefs.h"
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>
#include <iostream>

void compute(std::vector<Hospital> &hospitals, double userlat, double userlon, const UserPreferences &user_prefs);


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

int main() {
  std::vector<Hospital> hospitals = parseHospitalCSV("hospitals.csv");
  std::unordered_map<std::string, std::pair<double, double>> coords;
  assignCoordinates(hospitals, coords);
  return 0;
}