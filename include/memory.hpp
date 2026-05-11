#pragma once
#include <string>

namespace memory {

struct MemoryInfo {
    long totalKB;
    long availableKB;
};

MemoryInfo getMemoryInfo();

std::string getTotalMemory(const MemoryInfo &info);

std::string getAvailableMemory(const MemoryInfo &info);

std::string getMemoryUsagePercentage(const MemoryInfo &info);
} // namespace memory