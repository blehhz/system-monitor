#include "memory.hpp"
#include "system.hpp"
#include <sstream>
#include <string>

namespace {
long getValue(const std::string &key) {
    std::string content = sys::readFile("/proc/meminfo");

    if (content.empty()) {
        return -1;
    }

    std::istringstream stringStream(content);
    std::string line;

    while (std::getline(stringStream, line)) {
        if (line.starts_with(key + ":")) {
            long value = -1;

            size_t pos = line.find(":");
            std::string fullVal = line.substr(pos + 1);

            std::istringstream stream(fullVal);
            stream >> value;

            return value;
        }
    }
    return -1;
}
} // namespace

namespace memory {

MemoryInfo getMemoryInfo() {
    MemoryInfo info;
    info.totalKB = getValue("MemTotal");
    info.availableKB = getValue("MemAvailable");
    info.usedKB = info.totalKB - info.availableKB;
    info.usagePercentage = (static_cast<double>(info.usedKB) / info.totalKB) * 100;

    return info;
}
} // namespace memory