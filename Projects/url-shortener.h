std::string get_url(std::string url) {
    std::string link = "https://tinyurl.com/api-create.php?url=" + url;
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << "\n";
        return "";
    }
    curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(res) << "\n";
        curl_easy_cleanup(curl);
        return "";
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        std::cerr << "Error: HTTP " << http_code << "\n";
        curl_easy_cleanup(curl);
        return "";
    }
    curl_easy_cleanup(curl);
    return response;
}

int url_shortener() {
    std::string url;
    std::cout << "Enter the url u want to shorten >: ";
    std::cin >> url;
    std::string link = get_url(url);
    std::cout << link << "\n";
    return 0;
}
