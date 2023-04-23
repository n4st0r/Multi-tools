std::string ip() {
    std::string url = "https://ipinfo.io/city";
    std::string response_data;
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return "London";
        }
        curl_easy_cleanup(curl);
        return response_data;
    }
    return "fr";
}

int weather() {
    std::string city = ip();
    std::string url = "https://api.weatherapi.com/v1/current.json?key=3a431b2fbb5c4276a1a163525233103&q=" + std::string(city) + "&aqi=no";
    url.erase(std::remove(url.begin(), url.end(), '\n'), url.end());
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        std::string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            json data = json::parse(response_data);
            json current = data["current"];
            std::string location = data["location"]["name"].get<std::string>();
            std::string country = data["location"]["country"].get<std::string>();
            double temperature_c = current["temp_c"].get<double>();
            double temperature_f = current["temp_f"].get<double>();
            int humidity = current["humidity"].get<int>();
            double wind_speed_kph = current["wind_kph"].get<double>();
            std::string wind_direction = current["wind_dir"].get<std::string>();
            double pressure_mb = current["pressure_mb"].get<double>();
            std::string condition = current["condition"]["text"].get<std::string>();
            std::string icon = current["condition"]["icon"].get<std::string>();
            double feels_like_c = current["feelslike_c"].get<double>();
            double feels_like_f = current["feelslike_f"].get<double>();
            double visibility_km = current["vis_km"].get<double>();
            double visibility_miles = current["vis_miles"].get<double>();
            double gust_kph = current["gust_kph"].get<double>();
            double gust_mph = current["gust_mph"].get<double>();

            std::cout << "Location: " << location << ", " << country << std::endl;
            std::cout << "Temperature: " << temperature_c << " C (" << temperature_f << " F)" << std::endl;
            std::cout << "Feels like: " << feels_like_c << " C (" << feels_like_f << " F)" << std::endl;
            std::cout << "Humidity: " << humidity << "%" << std::endl;
            std::cout << "Wind Speed: " << wind_speed_kph << " kph, " << wind_direction << std::endl;
            std::cout << "Gust: " << gust_kph << " kph (" << gust_mph << " mph)" << std::endl;
            std::cout << "Pressure: " << pressure_mb << " mb" << std::endl;
            std::cout << "Condition: " << condition << std::endl;
            std::cout << "Visibility: " << visibility_km << " km (" << visibility_miles << " miles)" << std::endl;
            std::cout << "Icon URL: " << icon << std::endl;
        }
        curl_easy_cleanup(curl);
    }

    return 0;
}
