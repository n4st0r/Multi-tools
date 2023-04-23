std::string quote() {
    std::string url = "https://zenquotes.io/api/random";
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << "\n";
        return "";
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
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

int random_qoute() {
    std::string response = quote();
    json res = json::parse(response);
    const std::string quote = res[0]["q"].get<std::string>();
    const std::string author = res[0]["a"].get<std::string>();
    std::cout << "“" << quote << "”" << "\n";
    std::cout << "― " << author << "\n"; // nagogy nagooogy nagogyyyyy - nagie 🥵
    return 0;
}