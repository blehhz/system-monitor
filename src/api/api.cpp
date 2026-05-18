#include "api.hpp"
#include "cpuService.hpp"
#include "disk.hpp"
#include "diskService.hpp"
#include "jsonBuilder.hpp"
#include "memory.hpp"
#include "memoryService.hpp"
#include "system.hpp"
#include "telemetryService.hpp"
#include <httplib.h>

namespace {
httplib::Server server;

}

namespace api {
void startServer() {

    server.Get("/metrics", [](const httplib::Request, httplib::Response &res) {
        monitor::SystemInfo info = telemetryService::getSystemInfo();

        jsonBuilder::json data = jsonBuilder::systemInfoToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.Get("/cpu", [](const httplib::Request, httplib::Response &res) {
        cpu::CpuInfo info = cpuService::getCpuInfo();

        jsonBuilder::json data = jsonBuilder::cpuToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.Get("/memory", [](const httplib::Request, httplib::Response &res) {
        memory::MemoryInfo info = memoryService::getMemoryInfo();

        jsonBuilder::json data = jsonBuilder::memoryToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.Get("/disk", [](const httplib::Request, httplib::Response &res) {
        disk::DiskInfo info = diskService::getDiskInfo();

        jsonBuilder::json data = jsonBuilder::diskToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.Get("/system", [](const httplib::Request, httplib::Response &res) {
        sys::SystemMeta info = sys::getSystemMeta();

        jsonBuilder::json data = jsonBuilder::systemToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.listen("localhost", 8080);
}

void stopServer() { server.stop(); }
} // namespace api