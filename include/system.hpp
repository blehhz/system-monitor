#pragma once
#include <string>

namespace sys {

struct SystemMeta {
    std::string osName;
    std::string kernelVersion;
    std::string hostName;
    long uptimeSeconds;
};
std::string readFile(const std::string &path);

std::string getOs();

long getUptime();

SystemMeta getSystemMeta();
} // namespace sys