void random_ip() {
    std::string ip;
    std::string chars = "0123456789";

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(static_cast<unsigned int>(seed));
    std::uniform_int_distribution<> dis(0, 255);

    // Generate four random numbers between 0 and 255
    for (int i = 0; i < 4; ++i) {
        ip += std::to_string(dis(gen));
        if (i != 3) {
            ip += ".";
        }
    }
    std::cout << ip << "\n";

    return;
}