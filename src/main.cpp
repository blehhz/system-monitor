#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>

#include "api.hpp"
#include "cpuService.hpp"
#include "diskService.hpp"
#include "memoryService.hpp"
#include "systemService.hpp"

namespace {

std::atomic<bool> shutdownRequested = false;

void handleSignal(int) {
    shutdownRequested.store(true);
}

}

int main() {

    cpuService::start();
    memoryService::start();
    diskService::start();
    systemService::start();

    std::signal(SIGINT, handleSignal);
    std::signal(SIGTERM, handleSignal);

    std::thread apiThread([] {
        api::startServer();
    });

    while (!shutdownRequested.load()) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(100)
        );
    }

    api::stopServer();

    if (apiThread.joinable()) {
        apiThread.join();
    }
    
    cpuService::stop();
    memoryService::stop();
    diskService::stop();
    systemService::stop();


    return 0;
}