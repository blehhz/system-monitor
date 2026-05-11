#pragma once
#include "cpu.hpp"
#include "disk.hpp"
#include "memory.hpp"
#include "system.hpp"
#include <string>

namespace monitor {
struct SystemInfo {
    cpu::CpuStats cpu;
    memory::MemoryInfo memory;
    disk::DiskInfo disk;
    sys::SystemMeta system;

    std::string cpuModel;
};

SystemInfo getSystemInfo();
} // namespace monitor