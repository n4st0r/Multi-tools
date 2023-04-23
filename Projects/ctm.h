std::string getmoney(std::string c,std::string c2) {
    std::string url = "https://api.coinbase.com/v2/prices/" + c + "-" + c2 + "/spot";
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

std::string ctm() {
    system("cls");
    std::vector<std::string> currencyList = {"USD","EUR","GBP","AUD","CAD","SGD","HKD","JPY","NZD","CHF","CZK","DKK","HUF","NOK","PLN","SEK","SAR","KRW","INR","MXN","BRL","RUB"};
    std::vector<std::string> cryptoList = {"BTC", "ETH", "LTC", "BCH", "ETC", "ZRX", "BAT", "ZEC", "USDC", "LINK", "REP", "DAI", "ATOM", "XTZ", "ALGO", "OMG", "KNC", "COMP", "DASH", "NMR", "MKR", "UMA", "CGLD", "FIL", "AAVE", "GRT", "SNX", "BAND", "REN", "UNI", "YFI", "BAL", "NU", "LRC", "BNT", "ANKR", "SKL", "1INCH", "CLV", "MATIC"};
    std::string cc = "Cryptocurrency:\n[\033[33;1m1\033[0m] Bitcoin                               [\033[33;1m21\033[0m] Maker\n[\033[33;1m2\033[0m] Ethereum                              [\033[33;1m22\033[0m] UMA\n[\033[33;1m3\033[0m] Litecoin                              [\033[33;1m23\033[0m] Celo\n[\033[33;1m4\033[0m] Bitcoin Cash                          [\033[33;1m24\033[0m] Filecoin\n[\033[33;1m5\033[0m] Ethereum Classic                      [\033[33;1m25\033[0m] Aave\n[\033[33;1m6\033[0m] 0x                                    [\033[33;1m26\033[0m] The Graph\n[\033[33;1m7\033[0m] Basic Attention Token                 [\033[33;1m27\033[0m] Synthetix\n[\033[33;1m8\033[0m] Zcash                                 [\033[33;1m28\033[0m] Band Protocol\n[\033[33;1m9\033[0m] USD Coin                              [\033[33;1m29\033[0m] Ren\n[\033[33;1m10\033[0m] Chainlink                            [\033[33;1m30\033[0m] Uniswap\n[\033[33;1m11\033[0m] Augur                                [\033[33;1m31\033[0m] Yearn.finance\n[\033[33;1m12\033[0m] Dai                                  [\033[33;1m32\033[0m] Balancer\n[\033[33;1m13\033[0m] Cosmos                               [\033[33;1m33\033[0m] NuCypher\n[\033[33;1m14\033[0m] Tezos                                [\033[33;1m34\033[0m] Loopring\n[\033[33;1m15\033[0m] Algorand                             [\033[33;1m35\033[0m] Bancor\n[\033[33;1m16\033[0m] OmiseGO                              [\033[33;1m36\033[0m] Ankr\n[\033[33;1m17\033[0m] Kyber Network                        [\033[33;1m37\033[0m] SKALE Network\n[\033[33;1m18\033[0m] Compound                             [\033[33;1m38\033[0m] 1inch\n[\033[33;1m19\033[0m] Dash                                 [\033[33;1m39\033[0m] Clover\n[\033[33;1m20\033[0m] Numeraire                            [\033[33;1m40\033[0m] Polygon\n\n";
    std::string currency = "Currencies:\n[\033[33;1m1\033[0m] United States Dollar: USD                            [\033[33;1m2\033[0m] Euro: EUR\n[\033[33;1m3\033[0m] British Pound Sterling: GBP                          [\033[33;1m4\033[0m] Australian Dollar: AUD\n[\033[33;1m5\033[0m] Canadian Dollar: CAD                                 [\033[33;1m6\033[0m] Singapore Dollar: SGD\n[\033[33;1m7\033[0m] Hong Kong Dollar: HKD                                [\033[33;1m8\033[0m] Japanese Yen: JPY\n[\033[33;1m9\033[0m] New Zealand Dollar: NZD                              [\033[33;1m10\033[0m] Swiss Franc: CHF\n[\033[33;1m11\033[0m] Czech Koruna: CZK                                   [\033[33;1m12\033[0m] Danish Krone: DKK\n[\033[33;1m13\033[0m] Hungarian Forint: HUF                               [\033[33;1m14\033[0m] Norwegian Krone: NOK\n[\033[33;1m15\033[0m] Polish Zloty: PLN                                   [\033[33;1m16\033[0m] Swedish Krona: SEK\n[\033[33;1m17\033[0m] Saudi Riyal: SAR                                    [\033[33;1m18\033[0m] South Korean Won: KRW\n[\033[33;1m19\033[0m] Indian Rupee: INR                                   [\033[33;1m20\033[0m] Mexican Peso: MXN\n[\033[33;1m21\033[0m] Brazilian Real: BRL                                 [\033[33;1m22\033[0m] Russian Ruble: RUB\n\n";
    std::cout << cc;
    int choice;
    std::cout << "Choose the Cryptocurrency you want to convert >: ";
    std::cin >> choice;
    std::string c;
    if (choice > 0 && choice <= 40) {
        c = cryptoList[choice-1];
    } else {
        std::cout << "Invalid choice." << std::endl;
        return "";
    }
    system("cls");
    std::cout << currency;
    int choice2;
    std::cout << "Choose the Currency you want to convert >: ";
    std::cin >> choice2;
    std::string c2;
    if (choice2 > 0 && choice2 <= 22) {
        c2 = currencyList[choice2-1];
    } else {
        std::cout << "Invalid choice." << std::endl;
        return "";
    }
    std::string response = getmoney(c,c2);
    json j = json::parse(response);
    double final = std::stod(j["data"]["amount"].get<std::string>());
    std::cout << final <<" " << c2 <<" \n";
    return "";
} 