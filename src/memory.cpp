#include "memory.hpp"
#include "system.hpp"
#include <iomanip>
#include <sstream>
#include <string>

namespace {
long getValue(std::string key) {
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

double toGB(long memoryKB) { return static_cast<double>(memoryKB) / 1024 / 1024; }

std::string formatMemory(double memoryKB) {
    double memoryGB = toGB(memoryKB);

    std::ostringstream outStream;

    outStream << std::fixed;
    outStream << std::setprecision(2);
    outStream << memoryGB << " GB";

    return outStream.str();
}
} // namespace

namespace memory {

MemoryInfo getMemoryInfo() {
    MemoryInfo info;
    info.totalKB = getValue("MemTotal");
    info.availableKB = getValue("MemAvailable");

    return info;
}

std::string getTotalMemory(const MemoryInfo &info) { return formatMemory(info.totalKB); }

std::string getAvailableMemory(const MemoryInfo &info) { return formatMemory(info.availableKB); }

std::string getMemoryUsagePercentage(const MemoryInfo &info) {
    long memoryUsed = info.totalKB - info.availableKB;
    double memoryUsagePercentage = (static_cast<double>(memoryUsed) / info.totalKB) * 100;
    std::ostringstream outStream;
    outStream << std::fixed;
    outStream << std::setprecision(1);
    outStream << memoryUsagePercentage << "%";

    return outStream.str();
}
} // namespace memory