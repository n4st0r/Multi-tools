std::string countdown() {
    int hours = 0, minutes = 0, seconds = 0;
    std::cout << "Enter the countdown time in hours, minutes, and seconds (e.g., 1h 10m 30s): ";
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string token;
    std::getline(iss, token, 'h');
    if (!token.empty()) {
        hours = std::stoi(token);
    }
    std::getline(iss, token, 'm');
    if (!token.empty()) {
        minutes = std::stoi(token);
    }
    std::getline(iss, token, 's');
    if (!token.empty()) {
        seconds = std::stoi(token);
    }

    minutes += hours * 60; 
    seconds += minutes * 60; 
    system("cls");
    while (seconds >= 1) {
        int remainingHours = seconds / 3600;
        int remainingMinutes = (seconds % 3600) / 60;
        int remainingSeconds = seconds % 60;
        if (remainingHours > 0) {
            std::cout << remainingHours << " hours, ";
        }
        if (remainingMinutes > 0) {
            std::cout << remainingMinutes << " minutes, ";
        }
        std::cout << remainingSeconds << " seconds\n";

        Sleep(1000);
        seconds--;
        system("cls");
    }
    return "";
}
