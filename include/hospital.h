#pragma once
#include <string>

struct Hospital {
    std::string name;
    std::string city;
    std::string state;
    std::string type;

    double overall_rating = 0.0;
    double mortality = 0.0;
    double safety = 0.0;
    double readmission = 0.0;
    double experience = 0.0;
    double effectiveness = 0.0;
    double timeliness = 0.0;
    double imaging = 0.0;

    double latitude = 0.0;
    double longitude = 0.0;
};