#include "system.hpp"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/utsname.h>

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

long getUptime() {
    std::string content = readFile("/proc/uptime");

    if (content.empty()) {
        return -1;
    }

    std::istringstream stringStream(content);
    long uptime = 0;
    long idleTime = 0;

    stringStream >> uptime >> idleTime;

    return uptime;
}

SystemMeta getSystemMeta() {
    SystemMeta sysInfo;
    struct utsname info;
    if (uname(&info) == -1) {
        sysInfo.osName = "Unknown";
        sysInfo.kernelVersion = "Unknown";
        sysInfo.hostName = "Unknown";
        sysInfo.uptimeSeconds = -1;

        return sysInfo;
    }

    sysInfo.osName = getOs();
    sysInfo.kernelVersion = info.release;
    sysInfo.hostName = info.nodename;
    sysInfo.uptimeSeconds = getUptime();

    return sysInfo;
}
} // namespace sys
