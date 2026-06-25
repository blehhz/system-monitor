#include "disk.hpp"
#include <sys/statvfs.h>

namespace disk {

DiskInfo getDiskInfo() {
    DiskInfo diskInfo{};
    struct statvfs info;

    if (statvfs("/", &info) == -1) {
        diskInfo.totalBytes = 0;
        diskInfo.availableBytes = 0;
        diskInfo.usedBytes = 0;
        diskInfo.usagePercentage = 0;

        return diskInfo;
    }

    diskInfo.totalBytes = info.f_blocks * info.f_frsize;
    diskInfo.availableBytes = info.f_bavail * info.f_frsize;
    diskInfo.usedBytes = diskInfo.totalBytes - diskInfo.availableBytes;
    if(diskInfo.totalBytes==0) {
        diskInfo.usagePercentage=0;
    }
    else {
        diskInfo.usagePercentage= static_cast<double>(diskInfo.usedBytes) / diskInfo.totalBytes * 100;
    }

    return diskInfo;
}
} // namespace disk
