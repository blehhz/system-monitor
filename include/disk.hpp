#pragma once

namespace disk {

struct DiskInfo {
    unsigned long long totalBytes;
    unsigned long long availableBytes;
    unsigned long long usedBytes;
    double usagePercentage;
};

DiskInfo getDiskInfo();
} // namespace disk