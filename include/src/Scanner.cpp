#include "Scanner.hpp"
#include <curl/curl.h>
#include <iostream>
#include <algorithm>

ApiScanner::ApiScanner(const std::string& targetUrl) : url(targetUrl) {}

size_t ApiScanner::HeaderCallback(char* buffer, size_t size, size_t nitems, void* userdata) {
    size_t totalSize = size * nitems;
    std::string header(buffer, totalSize);
    auto* headersList = static_cast<std::vector<std::string>*>(userdata);
    headersList->push_back(header);
    return totalSize;
}

void ApiScanner::checkSecurityHeaders(const std::vector<std::string>& headers) {
    std::vector<std::string> requiredHeaders = {
        "Strict-Transport-Security", 
        "Content-Security-Policy", 
        "X-Frame-Options", 
        "X-Content-Type-Options"
    };

    std::cout << "\n[+] Analyzing Security Headers..." << std::endl;
    for (const auto& req : requiredHeaders) {
        bool found = false;
        for (const auto& h : headers) {
            if (h.find(req) != std::string::npos) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << " [!] MISSING: " << req << " (OWASP API Security Risk)" << std::endl;
        } else {
            std::cout << " [V] OK: " << req << std::endl;
        }
    }
}

void ApiScanner::runFullScan() {
    CURL* curl = curl_easy_init();
    if (!curl) return;

    std::vector<std::string> headers;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, HeaderCallback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headers);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Pobierz tylko nagłówki dla szybkości

    std::cout << "--- API SECURITY SCAN START ---" << std::endl;
    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
        checkSecurityHeaders(headers);
    } else {
        std::cerr << "[!] Error connecting to target: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
}
