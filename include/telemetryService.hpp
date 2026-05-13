#pragma once
#include "monitor.hpp"

namespace telemetryService {

void start();
monitor::SystemInfo getSystemInfo();
} // namespace telemetryService