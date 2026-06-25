#include "cpu.hpp"

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

namespace {
cpu::CpuInfo cachedInfo;

std::mutex cpuMutex;

std::atomic<bool> running = false;

std::thread cpuThread;
} // namespace

namespace cpuService {
void start() {
    
    if(running.load()){
        return;
    }

    running = true;
    cachedInfo = cpu::getCpuInfo();

    cpuThread = std::thread([]() {
        while (running.load()) {

            cpu::CpuInfo first = cpu::getCpuInfo();

            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            cpu::CpuInfo second = cpu::getCpuInfo();

            long totalDiff = second.total - first.total;
            long idleDiff = second.idle - first.idle;

            if(totalDiff <= 0){
                second.usagePercentage = 0;
            }
            else{
                second.usagePercentage = (1.0 - static_cast<double>(idleDiff)/totalDiff) * 100;
            }
            {
                std::lock_guard<std::mutex> lock(cpuMutex);

                cachedInfo = second;
            }
        }
    });
}

void stop() {
    running = false;

    if (cpuThread.joinable()) {
        cpuThread.join();
    }
}

cpu::CpuInfo getCpuInfo() {
    std::lock_guard<std::mutex> lock(cpuMutex);

    return cachedInfo;
}
} // namespace cpuService