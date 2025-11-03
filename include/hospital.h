#pragma once
#include <string>

struct Hospital {
    std::string name;
    std::string city;
    std::string state;
    std::string type;

    int overall_rating;
    std::string mortality;
    std::string safety;
    std::string readmission;
    std::string experience;
    std::string effectiveness;
    std::string timeliness;
    std::string imaging;

    double heart_attack_cost;
    std::string heart_attack_quality;
    std::string heart_attack_value;

    double heart_failure_cost;
    std::string heart_failure_quality;
    std::string heart_failure_value;

    double pneumonia_cost;
    std::string pneumonia_quality;
    std::string pneumonia_value;

    double hip_knee_cost;
    std::string hip_knee_quality;
    std::string hip_knee_value;

    double latitude = 0.0;
    double longitude = 0.0;
};