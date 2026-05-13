#include "monitor.hpp"
#include "cpu.hpp"
#include "system.hpp"
#include <chrono>
#include <thread>

namespace monitor {
SystemInfo getSystemInfo() {
    SystemInfo info;

    info.memory = memory::getMemoryInfo();
    info.disk = disk::getDiskInfo();
    info.system = sys::getSystemMeta();

    cpu::CpuInfo first = cpu::getCpuInfo();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cpu::CpuInfo second = cpu::getCpuInfo();

    long firstTotal = first.user + first.idle + first.nice + first.system;
    long secondTotal = second.user + second.idle + second.nice + second.system;

    long totalDiff = secondTotal - firstTotal;
    long idleDiff = second.idle - first.idle;

    second.usagePercentage = (1 - (static_cast<double>(idleDiff) / totalDiff)) * 100.0;

    info.cpu = second;

    return info;
}
} // namespace monitor