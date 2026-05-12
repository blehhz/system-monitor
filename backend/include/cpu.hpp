#pragma once
#include <string>

namespace cpu {

struct CpuInfo {
    long user;
    long nice;
    long system;
    long idle;
    std::string cpuModel;
};

CpuInfo getCpuInfo();
} // namespace cpu