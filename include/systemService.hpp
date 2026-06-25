#pragma once

#include "system.hpp"

namespace systemService {

void start();

void stop();

sys::SystemMeta getSystemInfo();

} // namespace systemService