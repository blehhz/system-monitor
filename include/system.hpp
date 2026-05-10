#pragma once
#include <string>

namespace sys {
std::string readFile(const std::string &path);

std::string getOs();
} // namespace sys