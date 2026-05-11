#pragma once

namespace memory {

struct MemoryInfo {
    long totalKB;
    long availableKB;
    long usedKB;
    double usagePercentage;
};

MemoryInfo getMemoryInfo();
} // namespace memory