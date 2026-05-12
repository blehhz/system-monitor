#pragma once
#include <string>

namespace cpu {

struct CpuInfo {
    long user;
    long nice;
    long system;
    long idle;
    double usagePercentage;
    std::string cpuModel;
};

CpuInfo getCpuInfo();
} // namespace cpu