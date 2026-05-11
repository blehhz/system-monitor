#include "monitor.hpp"
#include "system.hpp"

namespace monitor {
SystemInfo getSystemInfo() {
    SystemInfo info;
    info.cpu = cpu::getCpuStats();
    info.memory = memory::getMemoryInfo();
    info.disk = disk::getDiskInfo();
    info.system = sys::getSystemMeta();

    info.cpuModel = cpu::getCpuModel();

    return info;
}
} // namespace monitor