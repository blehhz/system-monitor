#include "api.hpp"
#include "telemetryService.hpp"

int main() {
    telemetryService::start();

    api::startServer();
    return 0;
}