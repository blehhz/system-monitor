# System Monitor

A modular Linux system monitoring service written in modern C++.

The project collects real-time system information such as CPU, memory, disk, and host metadata using Linux interfaces and exposes the data through a lightweight HTTP API.

## Features

* Real-time CPU, memory, disk, and system monitoring
* Independent background workers for each module
* Thread-safe caching using mutexes and atomics
* REST API built with `cpp-httplib`
* Graceful shutdown with signal handling
* Modular and extensible architecture
* Built with CMake and Ninja
* Compatible with Arch Linux and NixOS

---

## Technologies Used

* C++23
* CMake
* Ninja
* cpp-httplib
* nlohmann/json
* Linux `/proc`
* `statvfs`
* `std::thread`
* `std::mutex`
* `std::atomic`

---

## Project Structure

```text
include/
├── api.hpp
├── cpu.hpp
├── cpuService.hpp
├── disk.hpp
├── diskService.hpp
├── jsonBuilder.hpp
├── memory.hpp
├── memoryService.hpp
├── system.hpp
└── systemService.hpp

src/
├── api/
│   ├── api.cpp
│   └── jsonBuilder.cpp
├── modules/
│   ├── cpu/
│   ├── memory/
│   ├── disk/
│   └── system/
└── main.cpp
```

---

## API Endpoints

| Endpoint   | Description                        |
| ---------- | ---------------------------------- |
| `/health`  | Service health check               |
| `/metrics` | Full system snapshot               |
| `/cpu`     | CPU information                    |
| `/memory`  | Memory information                 |
| `/disk`    | Disk information                   |
| `/system`  | Host and operating system metadata |

---

## Build Instructions

### Configure

```bash
cmake -B build -G Ninja
```

### Build

```bash
cmake --build build
```

### Run

```bash
./build/system-monitor
```

---

## Example Response

```json
{
  "cpu": {
    "cpuModel": "AMD Ryzen 7 7735HS",
    "usagePercentage": 2.15
  }
}
```
