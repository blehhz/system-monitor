#include "cpu.hpp"
#include "memory.hpp"
#include "system.hpp"
#include <iostream>
#include <string>

int main() {

    std::string osName = sys::getOs();
    std::string cpuModel = cpu::getCpuModel();

    std::cout << "Os : " << osName << '\n';
    std::cout << "Cpu Model : " << cpuModel << '\n';
    std::cout << "Total Memory : " <<memory::getTotalMemory() << '\n';
    std::cout << "Available Memory : " << memory::getAvailableMemory() << '\n';
    std::cout << "Memory Usage : " << memory::getMemoryUsagePercentage() << '\n';

    return 0;
}