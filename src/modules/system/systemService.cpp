#include "systemService.hpp"

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

namespace {

sys::SystemMeta cachedInfo;

std::mutex systemMutex;

std::atomic<bool> running = false;

std::thread systemThread;

}

namespace systemService {

void start() {

    if (running.load()){
        return;
    }

    running = true;

    cachedInfo = sys::getSystemMeta();

    systemThread = std::thread([]() {

        while (running.load()) {

            sys::SystemMeta newInfo =
                sys::getSystemMeta();

            {
                std::lock_guard lock(systemMutex);

                cachedInfo = newInfo;
            }

            std::this_thread::sleep_for(std::chrono::seconds(30));
        }

    });

}

sys::SystemMeta getSystemInfo() {

    std::lock_guard lock(systemMutex);

    return cachedInfo;
}

void stop() {

    running = false;

    if(systemThread.joinable()){
        systemThread.join();
    }
}

}