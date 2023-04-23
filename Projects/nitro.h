std::string random_code() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int len = 16;
    std::string code(len, ' ');

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(static_cast<unsigned int>(seed));
    std::uniform_int_distribution<> dis(0, chars.length() - 1);

    for (int i = 0; i < len; i++) {
        code[i] = chars[dis(gen)];
    }

    return code;
}
std::string check(std::string url) {

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << "\n";
        return "";
    }
    curl_mime* mime;

    mime = curl_mime_init(curl);

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(res) << "\n";
        curl_easy_cleanup(curl);
        curl_mime_free(mime);
        return "";
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        curl_easy_cleanup(curl);
        curl_mime_free(mime);
        return "invalid";
    } else {
    	return "valid";
    }
    curl_mime_free(mime);
    curl_easy_cleanup(curl);
    return response;
}


int nitro(){
	while (true) {
		system("cls");
		int valid = 0;
		int invalid = 0;
		SetConsoleOutputCP(65001);
		SetConsoleTitleA("Made by nagogy | Valid: 0 | InValid: 0");
		std::string banner = R"(			███╗   ██╗ █████╗  ██████╗  ██████╗  ██████╗██╗   ██╗     ██████╗ ███████╗███╗   ██╗
			████╗  ██║██╔══██╗██╔════╝ ██╔═══██╗██╔════╝╚██╗ ██╔╝    ██╔════╝ ██╔════╝████╗  ██║
			██╔██╗ ██║███████║██║  ███╗██║   ██║██║  ███╗╚████╔╝     ██║  ███╗█████╗  ██╔██╗ ██║
			██║╚██╗██║██╔══██║██║   ██║██║   ██║██║   ██║ ╚██╔╝      ██║   ██║██╔══╝  ██║╚██╗██║
			██║ ╚████║██║  ██║╚██████╔╝╚██████╔╝╚██████╔╝  ██║       ╚██████╔╝███████╗██║ ╚████║
			╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝  ╚═════╝   ╚═╝        ╚═════╝ ╚══════╝╚═╝  ╚═══╝)";
	    std::cout << "\u001b[35m" << banner << "\u001b[0m\n";
	    int number_of_nitros; // <= number of how many nitros to gen
	    std::cout << "Number of Nitros u want to gen? >: ";
	    std::cin >> number_of_nitros;
	    for (int i = 0; i < number_of_nitros; i++) {
	    	std::string code = random_code();
	    	std::string url = "https://discordapp.com/api/v6/entitlements/gift-codes/" + code;
	    	std::string checked = check(url);
	    	if (checked == "valid") {
	    		std::cout << "\u001b[32m [+] https://discord.gift/" << code << " | Valid\u001b[0m" << "\n";
	    		system("pause"); // fr
	    		valid++;
	        	SetConsoleTitle(("Made by nagogy | Valid: " + std::to_string(valid) + " | InValid: " + std::to_string(invalid)).c_str());
	    	} else {
	    	    std::cout << "\u001b[31m [-] https://discord.gift/" << code << " | InValid\u001b[0m" << "\n";
	    	    invalid++;
	    	    SetConsoleTitle(("Made by nagogy | Valid: " + std::to_string(valid) + " | InValid: " + std::to_string(invalid)).c_str());
	    	}
	    }
	    std::string a;
	    std::cout << "Done again? (y/n) >: ";
	    std::cin >> a;
	    if (a == "n") {
	    	break;
	    } 
	}
    return 0;   
}