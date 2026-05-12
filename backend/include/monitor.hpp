#pragma once
#include "cpu.hpp"
#include "disk.hpp"
#include "memory.hpp"
#include "system.hpp"

namespace monitor {
struct SystemInfo {
    cpu::CpuInfo cpu;
    memory::MemoryInfo memory;
    disk::DiskInfo disk;
    sys::SystemMeta system;
};

SystemInfo getSystemInfo();
} // namespace monitor