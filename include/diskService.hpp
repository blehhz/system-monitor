#pragma once

#include "disk.hpp"

namespace diskService {

void start();

void stop();

disk::DiskInfo getDiskInfo();
} // namespace diskService