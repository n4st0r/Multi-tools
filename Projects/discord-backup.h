std::string getconn(std::string token) {
    std::string url = "https://discord.com/api/v9/users/@me/connections";
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

std::string basicinfo(std::string token) {
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

std::string getdms(std::string token) {
    std::string url = "https://discord.com/api/v9/users/@me/channels";
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

std::string getguilds(std::string token) {
    std::string url = "https://discord.com/api/v9/users/@me/guilds";
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

std::string getinvites(std::string token,std::string id) {
    std::string url = "https://discord.com/api/v9/guilds/" + id + "/invites";
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
        return "Error"; //idc
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        curl_easy_cleanup(curl);
        return "Error";
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return response;
}

std::string getfriends(std::string token) {
    std::string url = "https://discord.com/api/v9/users/@me/relationships"; // like me and ur mom
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

int discord_backup() {
    try {
        int connections_number = 0;
        int dms_number = 0;
        int friends_number = 0;  // bet its 0
        int guilds_number = 0;
        int invites_number = 0;
        int info_number = 11; // IDAGF

        const std::string folder_name = "discord-backup";
        mkdir(folder_name.c_str());
        std::string token;
        std::cout << "Enter token: ";
        std::cin >> token;
        
        std::string friendslist = getfriends(token); 
        json friend_obj = json::parse(friendslist);
        std::string friends_str = "";
        std::cout << red << "[+] Backingup friends...\n" << reset;
        for (auto& relationship : friend_obj) {
            std::string username = relationship["user"]["username"];
            std::string id = relationship["user"]["id"];
            std::string tag = relationship["user"]["discriminator"];
            std::string friend_str = username + "#" + tag + " (" + id + ")\n";
            friends_str += friend_str;
            friends_number++;
        }
        std::string frndsfn = folder_name + "\\friends.txt";
        std::ofstream friendsfile(frndsfn); 
        friendsfile << friends_str;
        friendsfile.close();
        std::cout << green << friends_number << " Friends Backedup\n" << reset;

        std::string guildslist = getguilds(token); 
        json guild_obj = json::parse(guildslist);
        std::string guild = ""; 
        std::string invites = "";
        std::cout << red << "[+] Backingup Guilds And Invites...\n" << reset;
        for (auto& guilds : guild_obj) {
            std::string guild_id = guilds["id"].get<std::string>();
            std::string guild_name = guilds["name"].get<std::string>();
            std::string guild_str = guild_name + " (" + guild_id + ")\n";
            guild += guild_str;
            std::string invite = getinvites(token,guild_id);
            guilds_number++;
            try {
                json invites_obj = json::parse(invite);
                for (const auto& invites_data : invites_obj) {
                    std::string invite_code = invites_data["code"].get<std::string>();
                    std::string invites_str = "Name: " + guild_name + "\nInvite: " + "https://discord.gg/" + invite_code + "\n\n";
                    invites += invites_str;
                    invites_number++;
                }
            } catch (...) {
                // nagogy
            }
        }
        std::string guildsfn = folder_name + "\\guilds.txt";
        std::ofstream guildsfile(guildsfn); 
        guildsfile << guild;
        guildsfile.close();
        std::cout << green << guilds_number << " Guilds Backedup\n" << reset;
        std::string invitesfn = folder_name + "\\invites.txt";
        std::ofstream invitesfile(invitesfn); 
        invitesfile << invites;
        invitesfile.close();
        std::cout << green << invites_number << " Invites Backedup\n" << reset;
        std::string dmlist = getdms(token); 
        json dm_obj = json::parse(dmlist);
        std::string dms_str = ""; 
        std::cout << red << "[+] Backingup Dms...\n" << reset;
        for (auto& channel : dm_obj) {
            std::string id = channel["id"];
            std::string recipient = channel["recipients"][0]["username"].get<std::string>() + "#" + channel["recipients"][0]["discriminator"].get<std::string>();
            std::string dm_str = recipient + " (" + id + ")\n";
            dms_str += dm_str;
            dms_number++;
        }
        std::string dmsfn = folder_name + "\\dms.txt";
        std::ofstream dmsfile(dmsfn); 
        dmsfile << dms_str;
        dmsfile.close();
        std::cout << green << dms_number << " Dms Backedup\n" << reset;

        std::string connlist = getconn(token); 
        json conn_obj = json::parse(connlist);
        std::string conn_str = ""; 
        std::cout << red << "[+] Backingup connections...\n" << reset;
        for (auto& conn : conn_obj) {
            std::string type = conn["type"].get<std::string>();
            std::string name = conn["name"].get<std::string>();
            std::string id = conn["id"].get<std::string>();
            conn_str += "Name: "+ name + "\nType: " + type + "\nID: " + id + "\n\n";
            connections_number++;
        }
        std::string connfn = folder_name + "\\connections.txt";
        std::ofstream connfile(connfn); 
        connfile << conn_str;
        connfile.close();
        std::cout << green << connections_number << " connections Backedup\n" << reset;

        std::string basicinfo_str = ""; 
        std::string personal_info_json = basicinfo(token);
        json personal_info_obj = json::parse(personal_info_json);
        std::cout << red << "[+] Backingup Basic info...\n" << reset;
        basicinfo_str += "ID: ";
        basicinfo_str += personal_info_obj["id"].get<std::string>() + "\n";

        basicinfo_str += "Username: ";
        basicinfo_str += personal_info_obj["username"].get<std::string>() + "\n";

        std::string avatar_url = "https://cdn.discordapp.com/avatars/" + personal_info_obj["id"].get<std::string>() + "/" + personal_info_obj["avatar"].get<std::string>() + ".png";
        basicinfo_str += "Avatar URL: ";
        basicinfo_str += avatar_url + "\n";

        basicinfo_str += "Banner Color: ";
        std::string banner_color = personal_info_obj["banner_color"].is_null() ? "NONE" : personal_info_obj["banner_color"].get<std::string>();
        basicinfo_str += banner_color + "\n";

        basicinfo_str += "Bio: ";
        std::string bio = personal_info_obj["bio"].is_null() ? "NONE" : personal_info_obj["bio"].get<std::string>();
        basicinfo_str += bio + "\n";

        basicinfo_str += "Locale: ";
        std::string locale = personal_info_obj["locale"].is_null() ? "NONE" : personal_info_obj["locale"].get<std::string>();
        basicinfo_str += locale + "\n";

        basicinfo_str += "NSFW Allowed: ";
        bool nsfw_allowed = personal_info_obj["nsfw_allowed"].is_null() ? false : personal_info_obj["nsfw_allowed"].get<bool>();
        basicinfo_str += (nsfw_allowed ? "YES" : "NO") + std::string("\n");

        basicinfo_str += "MFA Enabled: ";
        bool mfa_enabled = personal_info_obj["mfa_enabled"].is_null() ? false : personal_info_obj["mfa_enabled"].get<bool>();
        basicinfo_str += (mfa_enabled ? "YES" : "NO") + std::string("\n");

        basicinfo_str += "Email: ";
        std::string email = personal_info_obj["email"].is_null() ? "NONE" : personal_info_obj["email"].get<std::string>();
        basicinfo_str += email +"\n";

        basicinfo_str += "Verified: ";
        bool verified = personal_info_obj["verified"].is_null() ? false : personal_info_obj["verified"].get<bool>();
        basicinfo_str += (verified ? "YES" : "NO") + std::string("\n");

        basicinfo_str += "Phone: ";
        std::string phone = personal_info_obj["phone"].is_null() ? "NONE" : personal_info_obj["phone"].get<std::string>();
        basicinfo_str += phone + "\n";
        std::string basicfn = folder_name + "\\basic info.txt";
        std::ofstream basicfile(basicfn); 
        basicfile << basicinfo_str;
        basicfile.close();
        std::cout << green << info_number << " Basic info Backedup\n" << reset;

        std::cout << magenta << "Backup Done Check discord-backup folder\n" << reset;
        return 0;
    } catch(...) {
        std::cout << red << "Invalid token\n" << reset;
        return 0;
    }
}


