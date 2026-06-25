#pragma once

#include "memory.hpp"

namespace memoryService {
void start();

void stop();

memory::MemoryInfo getMemoryInfo();
} // namespace memoryService