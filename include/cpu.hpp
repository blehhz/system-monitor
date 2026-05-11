#pragma once
#include <string>

namespace cpu {

struct CpuStats {
    std::string label;
    long user;
    long nice;
    long system;
    long idle;
};

CpuStats getCpuStatsInfo();

std::string getCpuModel();

std::string getStats();

std::string getCpuUsagePercentage();
} // namespace cpu