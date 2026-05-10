#include "system.hpp"
#include <cstddef>
#include <sstream>
#include <string>

namespace cpu {
std::string getCpuModel() {
    std::string content = sys::readFile("/proc/cpuinfo");
    if (content.empty()) {
        return "No info!";
    }

    std::istringstream stringStream(content);
    std::string line;

    while (std::getline(stringStream, line)) {
        if (line.starts_with("model name")) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                return line.substr(pos + 2);
            }
        }
    }

    return "Not Found!";
}
} // namespace cpu