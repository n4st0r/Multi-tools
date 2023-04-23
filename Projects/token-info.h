
std::string personalinfo(std::string token) {
    std::string url = "https://discordapp.com/api/v6/users/@me";
    CURL* curl = curl_easy_init();
    if (!curl) {
        return "";
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
        curl_easy_cleanup(curl);
        return "";
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        curl_easy_cleanup(curl);
        return "";
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return response;
}

void token_info() {
    std::string token;
    std::cout << "\033[1;34mEnter token:\033[0m ";
    std::cin >> token;

    std::string personal_info_json = personalinfo(token);
    json personal_info_obj = json::parse(personal_info_json);

    std::cout << "\033[1;31mID:\033[0m ";
    std::cout << personal_info_obj["id"].get<std::string>() << "\n";

    std::cout << "\033[1;31mUsername:\033[0m ";
    std::cout << personal_info_obj["username"].get<std::string>() << "\n";

    std::string avatar_url = "https://cdn.discordapp.com/avatars/" + personal_info_obj["id"].get<std::string>() + "/" + personal_info_obj["avatar"].get<std::string>() + ".png";
    std::cout << "\033[1;31mAvatar URL:\033[0m ";
    std::cout << avatar_url << "\n";

    std::cout << "\033[1;31mBanner Color:\033[0m ";
    std::string banner_color = personal_info_obj["banner_color"].is_null() ? "NONE" : personal_info_obj["banner_color"].get<std::string>();
    std::cout << banner_color << "\n";

    std::cout << "\033[1;31mBio:\033[0m ";
    std::string bio = personal_info_obj["bio"].is_null() ? "NONE" : personal_info_obj["bio"].get<std::string>();
    std::cout << bio << "\n";

    std::cout << "\033[1;31mLocale:\033[0m ";
    std::string locale = personal_info_obj["locale"].is_null() ? "NONE" : personal_info_obj["locale"].get<std::string>();
    std::cout << locale << "\n";

    std::cout << "\033[1;31mNSFW Allowed:\033[0m ";
    bool nsfw_allowed = personal_info_obj["nsfw_allowed"].is_null() ? false : personal_info_obj["nsfw_allowed"].get<bool>();
    std::cout << (nsfw_allowed ? "YES" : "NO") << "\n";

    std::cout << "\033[1;31mMFA Enabled:\033[0m ";
    bool mfa_enabled = personal_info_obj["mfa_enabled"].is_null() ? false : personal_info_obj["mfa_enabled"].get<bool>();
    std::cout << (mfa_enabled ? "YES" : "NO") << "\n";

    std::cout << "\033[1;31mEmail:\033[0m ";
    std::string email = personal_info_obj["email"].is_null() ? "NONE" : personal_info_obj["email"].get<std::string>();
    std::cout << email << "\n";

    std::cout << "\033[1;31mVerified:\033[0m ";
    bool verified = personal_info_obj["verified"].is_null() ? false : personal_info_obj["verified"].get<bool>();
    std::cout << (verified ? "YES" : "NO") << "\n";

    std::cout << "\033[1;31mPhone:\033[0m ";
    std::string phone = personal_info_obj["phone"].is_null() ? "NONE" : personal_info_obj["phone"].get<std::string>();
    std::cout << phone << "\n";
}
