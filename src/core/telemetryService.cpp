#include "telemetryService.hpp"
#include "monitor.hpp"

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

namespace {
monitor::SystemInfo cachedInfo;

std::mutex telemetryMutex;

std::atomic<bool> running = false;

std::thread telemetryThread;

} // namespace

namespace telemetryService {
void start() {
    running = true;
    cachedInfo = monitor::getSystemInfo();
    telemetryThread = std::thread([]() {
        while (running) {
            monitor::SystemInfo newInfo = monitor::getSystemInfo();

            {
                std::lock_guard<std::mutex> lock(telemetryMutex);

                cachedInfo = newInfo;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
}

monitor::SystemInfo getSystemInfo() {

    std::lock_guard<std::mutex> lock(telemetryMutex);

    return cachedInfo;
}

void stop() {
    running = false;

    if (telemetryThread.joinable()) {
        telemetryThread.join();
    }
}
} // namespace telemetryService