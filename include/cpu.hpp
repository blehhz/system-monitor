#pragma once
#include <string>

namespace cpu {

struct CpuInfo {
    long user;
    long nice;
    long system;
    long idle;

    long total;
    double usagePercentage;
    std::string cpuModel;
};

CpuInfo getCpuInfo();
} // namespace cpu