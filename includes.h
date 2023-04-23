#include <curl/curl.h> // fr
#include <windows.h> // for SetConsoleOutputCP(65001);
#include <iostream> // output and input
#include <string> // For strings obv
#include <algorithm> // For std::replace
#include <limits>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <windows.h>
#include <conio.h>
#include <sys/stat.h>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <chrono>
#include <regex>
#include <unistd.h>
#include <cstdio>
#include <stdexcept>

#define magenta "\u001b[35m" // cool colors fr
#define green "\u001b[32m"
#define red "\u001b[31m"
#define reset "\u001b[0m"
#define cyan "\u001b[36m"

using json = nlohmann::json;

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}