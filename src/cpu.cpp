#include "cpu.hpp"
#include "system.hpp"
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>
#include <thread>

namespace {

std::string getCpuInfo(std::string key) {
    std::string content = sys::readFile("/proc/cpuinfo");
    if (content.empty()) {
        return "No info!";
    }

    std::string line;
    std::istringstream stringStream(content);

    while (std::getline(stringStream, line)) {
        if (line.starts_with(key)) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                return line.substr(pos + 2);
            }
        }
    }
    return "No info!";
}

std::string getCpuStatsContent(std::string key) {
    std::string content = sys::readFile("/proc/stat");
    if (content.empty()) {
        return "No info!";
    }

    std::string line;
    std::istringstream stringStream(content);
    while (std::getline(stringStream, line)) {
        if (line.starts_with(key)) {
            return line;
        }
    }

    return "No info!";
}
} // namespace

namespace cpu {

std::string getCpuModel() { return getCpuInfo("model name"); }

CpuStats getCpuStatsInfo() {
    CpuStats stats;

    std::istringstream lineStream(getCpuStatsContent("cpu"));

    lineStream >> stats.label >> stats.user >> stats.nice >> stats.system >> stats.idle;

    return stats;
}

std::string getCpuUsagePercentage() {
    CpuStats first = getCpuStatsInfo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    CpuStats second = getCpuStatsInfo();

    long firstTotal = first.user + first.idle + first.nice + first.system;
    long secondTotal = second.user + second.idle + second.nice + second.system;

    long totalIdleDifference = second.idle - first.idle;
    long totalDifference = secondTotal - firstTotal;

    double cpuUsagePercentage =
        ((1 - (static_cast<double>(totalIdleDifference) / totalDifference)) * 100);

    std::ostringstream outStream;
    outStream << std::fixed;
    outStream << std::setprecision(1);
    outStream << cpuUsagePercentage << "%";

    return outStream.str();
}
} // namespace cpu