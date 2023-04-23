std::string spam(std::string payload,std::string url) {
    CURL *curl;
    curl_global_cleanup();
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return "";
}

int webhook_spammer() {
    std::cout << red << "HIT CTRL+C TO STOP" << reset << "\n";
    std::string url;
    std::cout << "webhook url >: ";
    std::cin >> url;
    std::string message;
    std::cout << "Message >: ";
    std::getline(std::cin >> std::ws, message);
    std::string payload = "{"
        "\"username\": \"SpiderBot\"," //funny asf
        "\"content\":  \"" + message + "\""
    "}";
    int i = 0;
    while (true) {
    	i++;
    	std::cout << red << "[" << cyan << i << red << "]" << " Spammed " << message << reset << "\n";
    	spam(payload,url);
    }
    return 0;
}