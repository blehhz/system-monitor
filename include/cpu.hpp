#pragma once
#include <string>

namespace cpu {

struct CpuStats {
    long user;
    long nice;
    long system;
    long idle;
};

CpuStats getCpuStats();

std::string getCpuModel();
} // namespace cpu