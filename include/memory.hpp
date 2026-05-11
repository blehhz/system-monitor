#pragma once
#include <string>

namespace memory {

struct MemoryInfo {
    long totalKB;
    long availableKB;
};

MemoryInfo getMemoryInfo();

std::string getTotalMemory();

std::string getAvailableMemory();

std::string getMemoryUsagePercentage();
} // namespace memory