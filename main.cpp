#include <iostream>
#include <curl/curl.h>

int main() {
    const char* url = "https://checkip.amazonaws.com/";

    // Initialize libcurl for each thread
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize libcurl." << std::endl;
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* buffer, size_t size, size_t nmemb, void* userp) -> size_t {
        std::cout.write(static_cast<const char*>(buffer), size * nmemb);
        return size * nmemb;
    });

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    // Cleanup libcurl for each thread
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
