#include "cpu.hpp"
#include "memory.hpp"
#include "system.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

int main() {

    std::cout << "Os : " << sys::getOs() << '\n';
    std::cout << "Cpu Model : " << cpu::getCpuModel() << '\n';
    std::cout << cpu::getStats();

    memory::MemoryInfo info = memory::getMemoryInfo();
    std::cout << "\nTotal Memory : " << memory::getTotalMemory(info) << '\n';
    std::cout << "Available Memory : " << memory::getAvailableMemory(info) << '\n';
    std::cout << "Memory Usage : " << memory::getMemoryUsagePercentage(info) << '\n';

    std::cout << cpu::getCpuUsagePercentage() << '\n';

    return 0;
}