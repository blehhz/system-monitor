#pragma once

#include "cpu.hpp"
#include "disk.hpp"
#include "memory.hpp"
#include "monitor.hpp"
#include "system.hpp"
#include <nlohmann/json.hpp>

namespace jsonBuilder {
using json = nlohmann::json;

json memoryToJson(const memory::MemoryInfo &info);
json systemToJson(const sys::SystemMeta &info);
json cpuToJson(const cpu::CpuInfo &info);
json diskToJson(const disk::DiskInfo &info);

json systemInfoToJson(const monitor::SystemInfo &info);
} // namespace jsonBuilder