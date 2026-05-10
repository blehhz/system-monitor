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
    std::cout << memory::getTotalMemory() << '\n';
    std::cout << memory::getAvailableMemory() << '\n';
    return 0;
}