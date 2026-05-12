#include "monitor.hpp"
#include "system.hpp"

namespace monitor {
SystemInfo getSystemInfo() {
    SystemInfo info;
    info.cpu = cpu::getCpuInfo();
    info.memory = memory::getMemoryInfo();
    info.disk = disk::getDiskInfo();
    info.system = sys::getSystemMeta();

    return info;
}
} // namespace monitor