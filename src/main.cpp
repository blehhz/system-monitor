#include "api.hpp"
#include "cpuService.hpp"
#include "diskService.hpp"
#include "memoryService.hpp"
#include "telemetryService.hpp"
#include <csignal>

void handleSignal(int) {

    cpuService::stop();

    memoryService::stop();

    diskService::stop();

    telemetryService::stop();

    api::stopServer();
}

int main() {
    cpuService::start();
    memoryService::start();
    diskService::start();
    telemetryService::start();

    std::signal(SIGINT, handleSignal);
    api::startServer();
    return 0;
}