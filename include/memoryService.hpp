#include "memory.hpp"

#pragma once

namespace memoryService {
void start();

void stop();

memory::MemoryInfo getMemoryInfo();
} // namespace memoryService