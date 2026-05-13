#include "telemetryService.hpp"
#include "monitor.hpp"
#include <chrono>
#include <mutex>
#include <thread>

namespace {
monitor::SystemInfo cachedInfo;

std::mutex telemetryMutex;

} // namespace

namespace telemetryService {
void start() {
    cachedInfo = monitor::getSystemInfo();
    std::thread([]() {
        while (true) {
            monitor::SystemInfo newInfo = monitor::getSystemInfo();

            {
                std::lock_guard<std::mutex> lock(telemetryMutex);

                cachedInfo = newInfo;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach();
}

monitor::SystemInfo getSystemInfo() {

    std::lock_guard<std::mutex> lock(telemetryMutex);

    return cachedInfo;
}
} // namespace telemetryService