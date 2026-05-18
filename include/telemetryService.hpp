#pragma once
#include "monitor.hpp"

namespace telemetryService {

void start();

void stop();

monitor::SystemInfo getSystemInfo();
} // namespace telemetryService