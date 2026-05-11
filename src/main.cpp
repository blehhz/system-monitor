#include "monitor.hpp"
#include <iostream>
// #include <chrono>
// #include <string>
// #include <thread>

int main() {

    monitor::SystemInfo info = monitor::getSystemInfo();

    std::cout << "Host Name : " << info.system.hostName << '\n';

    return 0;
}