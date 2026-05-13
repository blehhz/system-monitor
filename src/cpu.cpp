#include "cpu.hpp"
#include "system.hpp"
#include <cstddef>
#include <sstream>
#include <string>

namespace {

std::string getCpuInfoValue(std::string key) {
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

std::string getCpuInfoContent(std::string key) {
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

CpuInfo getCpuInfo() {
    CpuInfo stats;

    std::istringstream lineStream(getCpuInfoContent("cpu"));
    std::string ignored;

    lineStream >> ignored >> stats.user >> stats.nice >> stats.system >> stats.idle;

    stats.cpuModel = getCpuInfoValue("model name");

    return stats;
}

} // namespace cpu