#include "jsonBuilder.hpp"
#include "cpu.hpp"

namespace jsonBuilder {
json memoryToJson(const memory::MemoryInfo &info) {
    json data;

    data["totalKB"] = info.totalKB;
    data["availableKB"] = info.availableKB;
    data["usedKB"] = info.usedKB;
    data["usagePercentage"] = info.usagePercentage;

    return data;
}

json systemToJson(const sys::SystemMeta &info) {
    json data;
    data["osName"] = info.osName;
    data["kernelVersion"] = info.kernelVersion;
    data["hostName"] = info.hostName;
    data["uptimeSeconds"] = info.uptimeSeconds;

    return data;
}

json cpuToJson(const cpu::CpuInfo &info) {
    json data;
    data["usagePercentage"] = info.usagePercentage;
    data["cpuModel"] = info.cpuModel;

    return data;
}

json diskToJson(const disk::DiskInfo &info) {
    json data;
    data["totalBytes"] = info.totalBytes;
    data["availableBytes"] = info.availableBytes;
    data["usedBytes"] = info.usedBytes;
    data["usagePercentage"] = info.usagePercentage;

    return data;
}
} // namespace jsonBuilder