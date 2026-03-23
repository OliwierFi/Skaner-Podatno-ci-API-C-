#include "Scanner.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./CppApiScanner <url>" << std::endl;
        std::cout << "Example: ./CppApiScanner https://google.com" << std::endl;
        return 1;
    }

    std::string target = argv[1];
    ApiScanner scanner(target);
    scanner.runFullScan();

    return 0;
}
