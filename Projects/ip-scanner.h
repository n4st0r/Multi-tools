
std::string ipinfo(std::string ip) {
    std::string url = "http://ip-api.com/json/" + ip + "?fields=66846719";
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL" << "\n" << reset;
        return "";
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(res) << "\n" << reset;
        curl_easy_cleanup(curl);
        return "";
    }
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        std::cerr << "Error: HTTP " << http_code << "\n" << reset;
        curl_easy_cleanup(curl);
        return "";
    }
    curl_easy_cleanup(curl);
    return response;
}

template <typename T>
void get_json_value(const json& j, const std::string& key, T& value) {
    if (!j[key].is_null()) {
        value = j[key].get<T>();
    }
}

int ip_info() {
    SetConsoleOutputCP(65001);
	std::string ip;
	std::cout << "Enter ip u want to scan >: ";
	std::cin >> ip;
	std::string response = ipinfo(ip);
	json res = json::parse(response);
	system("cls");
	const std::string status = res["status"].get<std::string>();
	if (status == "success"){
	    std::string status;
	    get_json_value(res, "status", status);
	    std::cout << "Status: " << red << status << "\n" << reset;

	    std::string continentCode;
	    get_json_value(res, "continentCode", continentCode);
	    std::cout << "Continent Code: " << red << continentCode << "\n" << reset;

	    std::string continent;
	    get_json_value(res, "continent", continent);
	    std::cout << "Continent: " << red << continent << "\n" << reset;

	    std::string country;
	    get_json_value(res, "country", country);
	    std::cout << "Country: " << red << country << "\n" << reset;

	    std::string countryCode;
	    get_json_value(res, "countryCode", countryCode);
	    std::cout << "Country Code: " << red << countryCode << "\n" << reset;

	    std::string region;
	    get_json_value(res, "region", region);
	    std::cout << "Region: " << red << region << "\n" << reset;

	    std::string regionName;
	    get_json_value(res, "regionName", regionName);
	    std::cout << "Region Name: " << red << regionName << "\n" << reset;

	    std::string city;
	    get_json_value(res, "city", city);
	    std::cout << "City: " << red << city << "\n" << reset;

	    std::string district;
	    get_json_value(res, "district", district);
	    std::cout << "District: " << red << district << "\n" << reset;

	    std::string zip;
	    get_json_value(res, "zip", zip);
	    std::cout << "Zip Code: " << red << zip << "\n" << reset;

	    double lat;
	    get_json_value(res, "lat", lat);
	    std::cout << "Latitude: " << red << lat << "\n" << reset;

	    double lon;
	    get_json_value(res, "lon", lon);
	    std::cout << "Longitude: " << red << lon << "\n" << reset;

	    std::string timezone;
	    get_json_value(res, "timezone", timezone);
	    std::cout << "Timezone: " << red << timezone << "\n" << reset;

	    int offset;
	    get_json_value(res, "offset", offset);
	    std::cout << "Offset: " << red << offset << "\n" << reset;

	    std::string currency;
	    get_json_value(res, "currency", currency);
	    std::cout << "Currency: " << red << currency << "\n" << reset;

	    std::string isp;
	    get_json_value(res, "isp", isp);
	    std::cout << "ISP: " << red << isp << "\n" << reset;

	    std::string org;
	    get_json_value(res, "org", org);
	    std::cout << "Organization: " << red << org << "\n" << reset;
		
	    std::string as;
	    get_json_value(res, "as", as);
	    std::cout << "AS Number: " << red << as << "\n" << reset;

	    std::string asname;
	    get_json_value(res, "asname", asname);
	    std::cout << "AS Name: " << red << asname << "\n" << reset;

	    std::string reverse;
	    get_json_value(res, "reverse", reverse);
	    std::cout << "Reverse DNS: " << red << reverse << "\n" << reset;

		bool mobile;
		get_json_value(res, "mobile", mobile);
		std::string mobile_str = mobile ? "True" : "False";
		std::cout << "Mobile: " << red << std::boolalpha << mobile_str << "\n" << reset;

		bool proxy;
		get_json_value(res, "proxy", proxy);
		std::string proxy_str = proxy ? "True" : "False";
		std::cout << "Proxy: " << red << proxy_str << "\n" << reset;

		bool hosting;
		get_json_value(res, "hosting", hosting);
		std::string hosting_str = hosting ? "True" : "False";
		std::cout << "Hosting: " << red << hosting_str << "\n" << reset;

	    std::string query;
	    get_json_value(res, "query", query);
	    std::cout << "Query IP Address: " << red << query << "\n" << reset;
	} else {
		std::cout << red << "--- Error ---\n" << reset;
	}
	return 0;
}