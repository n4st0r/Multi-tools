
void copyToClipboard(const std::string& str) {
  FILE* clip = _popen("clip", "w");
  if (!clip) {
    std::cerr << "Failed to open pipe to clip.exe." << std::endl;
    return;
  }
  fputs(str.c_str(), clip);
  _pclose(clip);
}

std::string ascii_req(std::string url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << std::endl;
        return "";
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return "";
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        std::cerr << "Error: HTTP " << http_code << std::endl;
        curl_easy_cleanup(curl);
        return "";
    }
    curl_easy_cleanup(curl);
    return response;
}

std::string ascii() {
	SetConsoleOutputCP(65001);
    std::string x;
    std::cout << "Enter text u want to convert to ascii text >: ";
    std::getline(std::cin, x); // Use getline to get the entire input line
    std::replace(x.begin(), x.end(), ' ', '+'); // Replace all spaces with '+'
    std::string fr = "https://asciified.thelicato.io/api?text="+ x +"&font=ANSI+Shadow";
	std::string curl = ascii_req(fr);
	std::cout << curl << "\n\n";
    copyToClipboard(curl);
    std::cout << "Copied to clipboard\n"; 
    return "";
}