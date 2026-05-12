#include <httplib.h>

#include "api.hpp"
#include "jsonBuilder.hpp"
#include "monitor.hpp"

namespace api {
void startServer() {
    httplib::Server server;

    server.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {
        monitor::SystemInfo info = monitor::getSystemInfo();

        jsonBuilder::json data = jsonBuilder::systemInfoToJson(info);
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content(data.dump(4), "application/json");
    });

    server.listen("localhost", 8080);
}
} // namespace api