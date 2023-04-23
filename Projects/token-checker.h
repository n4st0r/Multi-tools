void token_check() {
    std::string token;
    std::cout << "Enter token: ";
    std::cin >> token;
    std::string url = "https://discordapp.com/api/v6/users/@me";
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cout << red << "Invalid token" << "\n";
        return;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    std::string auth_header = "Authorization: " + token;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, auth_header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cout << red << "Invalid token" << "\n";
        curl_easy_cleanup(curl);
        return;
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        std::cout << red << "Invalid token" << "\n";
        curl_easy_cleanup(curl);
        return;
    }
    std::cout << green << "Valid token\n";
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return;
}