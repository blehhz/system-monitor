#include "api.hpp"
#include <httplib.h>
#include "jsonBuilder.hpp"

#include "cpuService.hpp"
#include "diskService.hpp"
#include "memoryService.hpp"
#include "systemService.hpp"

namespace {
httplib::Server server;

void respondJson(httplib::Response& res, const jsonBuilder::json& data) {
    res.set_header("Access-Control-Allow-Origin", "*");

    res.set_content(data.dump(), "application/json");
}
}

namespace api {
void startServer() {

    server.Get("/metrics", [](const httplib::Request&, httplib::Response& res) {

        jsonBuilder::json data;
    
        data["cpu"] = jsonBuilder::cpuToJson(cpuService::getCpuInfo());
    
        data["memory"] = jsonBuilder::memoryToJson(memoryService::getMemoryInfo());
    
        data["disk"] = jsonBuilder::diskToJson(diskService::getDiskInfo());
    
        data["system"] = jsonBuilder::systemToJson(systemService::getSystemInfo());
    
        respondJson(res,data);
    });

    server.Get("/cpu", [](const httplib::Request&, httplib::Response& res) {
        cpu::CpuInfo info = cpuService::getCpuInfo();

        respondJson(
            res,
            jsonBuilder::cpuToJson(info)
        );
    });

    server.Get("/memory", [](const httplib::Request&, httplib::Response& res) {
        memory::MemoryInfo info = memoryService::getMemoryInfo();

        respondJson(
            res,
            jsonBuilder::memoryToJson(info)
        );
    });

    server.Get("/disk", [](const httplib::Request&, httplib::Response& res) {
        disk::DiskInfo info = diskService::getDiskInfo();

        respondJson(
            res,
            jsonBuilder::diskToJson(info)
        );
    });

    server.Get("/system", [](const httplib::Request&, httplib::Response& res) {
        sys::SystemMeta info = systemService::getSystemInfo();

        respondJson(
            res,
            jsonBuilder::systemToJson(info)
        );
    });
    
    server.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("ok", "text/plain");
    });

    server.listen("127.0.0.1", 8080);
}

void stopServer() { server.stop(); }
} // namespace api