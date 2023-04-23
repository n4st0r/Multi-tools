int webhook_checker() {
  std::string webhook, oak;
  std::cout << "webhook url >:";
  std::getline(std::cin, webhook);
  oak = webhook;

  CURL* curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, oak.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    CURLcode res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      if (response_code == 404 || webhook.find("discord.com/api/webhooks") == std::string::npos) {
        std::cout << "Invalid webhook FR" << std::endl;
        return EXIT_FAILURE;
      }
      else if (response_code == 200) {
        std::cout << "Valid webhook FR" << std::endl;
        return EXIT_SUCCESS;
      }
      else {
        std::cerr << "Invalid Webhook fr" << std::endl;
        return EXIT_FAILURE;
      }
    }
    else {
      std::cerr << "Invalid Webhook fr"<< std::endl;
      return EXIT_FAILURE;
    }
    curl_easy_cleanup(curl);
  }

  return EXIT_FAILURE;
}
