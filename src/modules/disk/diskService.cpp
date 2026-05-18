#include "diskService.hpp"
#include "disk.hpp"

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

namespace {
disk::DiskInfo cachedInfo;

std::mutex diskMutex;

std::atomic<bool> running = false;

std::thread diskThread;
} // namespace

namespace diskService {
void start() {
    running = true;
    cachedInfo = disk::getDiskInfo();

    diskThread = std::thread([]() {
        while (running) {
            disk::DiskInfo newInfo = disk::getDiskInfo();

            {
                std::lock_guard<std::mutex> lock(diskMutex);

                cachedInfo = newInfo;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });
}

void stop() {
    running = false;

    if (diskThread.joinable()) {
        diskThread.join();
    }
}

disk::DiskInfo getDiskInfo() {
    std::lock_guard<std::mutex> lock(diskMutex);

    return cachedInfo;
}
} // namespace diskService