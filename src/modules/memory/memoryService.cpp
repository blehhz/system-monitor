#include "memoryService.hpp"
#include "memory.hpp"

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

namespace {
memory::MemoryInfo cachedInfo;

std::atomic<bool> running = false;

std::mutex memoryMutex;

std::thread memoryThread;
} // namespace

namespace memoryService {
void start() {
    
    if(running.load()){
        return;
    }
    
    running = true;
    cachedInfo = memory::getMemoryInfo();

    memoryThread = std::thread([]() {
        while (running.load()) {
            memory::MemoryInfo newInfo = memory::getMemoryInfo();

            {
                std::lock_guard<std::mutex> lock(memoryMutex);

                cachedInfo = newInfo;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });
}

void stop() {
    running = false;

    if (memoryThread.joinable()) {
        memoryThread.join();
    }
}

memory::MemoryInfo getMemoryInfo() {
    std::lock_guard<std::mutex> lock(memoryMutex);

    return cachedInfo;
}
} // namespace memoryService