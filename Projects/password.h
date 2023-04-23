std::string generatePassword() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int len = 12;
    std::string password(len, ' ');

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(static_cast<unsigned int>(seed));
    std::uniform_int_distribution<> dis(0, chars.length() - 1);

    for (int i = 0; i < len; i++) {
        password[i] = chars[dis(gen)];
    }

    return password;
}
int password() {
    while (true) {
        std::cout << "Your random password is: " << generatePassword() << std::endl;
        std::string a;
        std::cout << "Again? (y/n) >: ";
        std::cin >> a;
        if (a == "y") {
        } else {
            break;
        }
    }
    return 0;
}