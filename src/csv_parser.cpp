#include "hospital.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Hospital> parseHospitalCSV(const std::string& filename) {
    std::vector<Hospital> hospitals;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return hospitals;
    }

    std::string line;
    bool isHeader = true;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        // Split line by tab
        while (std::getline(ss, field, '\t')) {
            // Remove potential trailing carriage return (\r) if dataset uses Windows line endings
            if (!field.empty() && field.back() == '\r') {
                field.pop_back();
            }
            fields.push_back(field);
        }

        // Skip header row
        if (isHeader) {
            isHeader = false;
            continue;
        }

        // Expecting at least 24 columns based on dataset structure
        if (fields.size() < 24) {
            std::cerr << "Skipping malformed row with " << fields.size() << " columns.\n";
            continue;
        }

        Hospital h;
        h.name = fields[0];
        h.city = fields[1];
        h.state = fields[2];
        h.type = fields[3];
        h.overall_rating = std::stoi(fields[4].empty() ? "0" : fields[4]);
        h.mortality = fields[5];
        h.safety = fields[6];
        h.readmission = fields[7];
        h.experience = fields[8];
        h.effectiveness = fields[9];
        h.timeliness = fields[10];
        h.imaging = fields[11];

        // Convert numeric values safely
        auto toDouble = [](const std::string& s) {
            try { return std::stod(s); } catch (...) { return 0.0; }
        };

        h.heart_attack_cost = toDouble(fields[12]);
        h.heart_attack_quality = fields[13];
        h.heart_attack_value = fields[14];

        h.heart_failure_cost = toDouble(fields[15]);
        h.heart_failure_quality = fields[16];
        h.heart_failure_value = fields[17];

        h.pneumonia_cost = toDouble(fields[18]);
        h.pneumonia_quality = fields[19];
        h.pneumonia_value = fields[20];

        h.hip_knee_cost = toDouble(fields[21]);
        h.hip_knee_quality = fields[22];
        h.hip_knee_value = fields[23];

        hospitals.push_back(h);
    }

    return hospitals;
}
