#pragma once

#include "cpu.hpp"

namespace cpuService {

void start();

void stop();

cpu::CpuInfo getCpuInfo();

} // namespace cpuService