# C++ High-Performance API Vulnerability Scanner

## 🛡️ Project Overview
A multi-threaded security tool designed to perform rapid reconnaissance and vulnerability assessment of REST APIs. Built with C++ for maximum performance and low-level control over network operations.

### Key Features
* **OWASP API Top 10 Mapping:** Detects security misconfigurations and broken object-level authorization patterns.
* **Header Analysis:** Checks for missing security headers (HSTS, CSP, X-Frame-Options, etc.).
* **Method Tampering:** Identifies insecure HTTP methods allowed on sensitive endpoints.
* **Performance:** Utilizes `libcurl` for efficient, asynchronous network communication.

##  Tech Stack
* **Language:** C++17
* **Networking:** [libcurl](https://curl.se/libcurl/)
* **Build System:** CMake
* **JSON Parsing:** [nlohmann/json](https://github.com/nlohmann/json)

##  Installation & Build
1. Install dependencies: `sudo apt install libcurl4-openssl-dev`
2. Clone the repo: `git clone https://github.com/TWOJA_NAZWA/CppApiScanner.git`
3. Build:
   ```bash
   mkdir build && cd build
   cmake ..
   make
