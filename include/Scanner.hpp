#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <string>
#include <vector>

// Klasa odpowiedzialna za silnik skanujący
class ApiScanner {
public:
    ApiScanner(const std::string& targetUrl);
    void runFullScan();

private:
    std::string url;
    static size_t HeaderCallback(char* buffer, size_t size, size_t nitems, void* userdata);
    void checkSecurityHeaders(const std::vector<std::string>& headers);
    void checkMethodTampering();
};

#endif
