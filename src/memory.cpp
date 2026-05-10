#include "memory.hpp"
#include "system.hpp"
#include <cstddef>
#include <sstream>
#include <string>

namespace {
std::string getData(std::string key) {
    std::string content = sys::readFile("/proc/meminfo");
    if (content.empty()) {
        return "No info!";
    }

    std::istringstream stringStream(content);
    std::string line;
    long value;
    std::string unit;
    while (std::getline(stringStream, line)) {
        if (line.starts_with(key + ":")) {
            size_t pos = line.find(":");
            std::string fullVal = line.substr(pos + 1);
            std::istringstream stream(fullVal);

            stream >> value >> unit;
        }
    }
    return (std::to_string(value) + " " + unit);
}
} // namespace

namespace memory {
std::string getTotalMemory() {

    std::string data = getData("MemTotal");

    return data;
}

std::string getAvailableMemory() {
    std::string data = getData("MemAvailable");

    return data;
}
} // namespace memory