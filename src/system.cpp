#include "system.hpp"
#include <fstream>
#include <sstream>
#include <string>
namespace sys {
std::string readFile(const std::string &path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

std::string getOs() {
    std::string content = readFile("/etc/os-release");

    if (content.empty()) {
        return "";
    }

    std::istringstream stringStream(content);
    std::string line;

    while (std::getline(stringStream, line)) {
        if (line.starts_with("PRETTY_NAME")) {
            size_t pos = line.find("=");

            if (pos != std::string::npos) {
                line.pop_back();
                return line.substr(pos + 2);
            }
        }
    }

    return "Not Found!";
}
} // namespace sys
