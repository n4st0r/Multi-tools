#include "includes.h" // include header files for other functions

// include functions
#include "Projects/ascii.h"
#include "Projects/countdown.h"
#include "Projects/ctm.h"
#include "Projects/decode-encode.h"
#include "Projects/discord-backup.h"
#include "Projects/fake-miner.h"
#include "Projects/gofile.h"
#include "Projects/ip-scanner.h"
#include "Projects/nitro.h"
#include "Projects/password.h"
#include "Projects/quote.h"
#include "Projects/url-shortener.h"
#include "Projects/weather.h"
#include "Projects/webhook-checker.h"
#include "Projects/webhook-spammer.h"
#include "Projects/webhook-deleter.h"
#include "Projects/token-checker.h"
#include "Projects/ip-gen.h"
#include "Projects/wifi-pass.h"
#include "Projects/token-info.h"

void pause() {
    system("pause");
}

void clear() {
    system("cls");
}

int main() {
    SetConsoleOutputCP(65001); //cp

    while (true) {
        clear();
        // banner
        std::cout << reset << "\n                                 ╔╗╔╔═╗╔═╗╔═╗╔═╗╦ ╦\n                                 ║║║╠═╣║ ╦║ ║║ ╦╚╦╝\n                                 ╝╚╝╩ ╩╚═╝╚═╝╚═╝ ╩ " << std::endl;
        std::cout << cyan << "                      ══╦═══════════════════════════════════╦══\n             ╔══════════╩═══════════════════════════════════╩══════════╗\n";
        std::cout << "             ║                         " << magenta << "OPTIONS" << cyan << "                         ║\n             ║                                                         ║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m1\u001b[35m]  Ascii                         [\u001b[36m2\u001b[35m]  Countdown timer \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m3\u001b[35m]  Crypto to currency converter  [\u001b[36m4\u001b[35m]  Encode/Decode   \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m5\u001b[35m]  Discord backup tool           [\u001b[36m6\u001b[35m]  Fake BTC miner  \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m7\u001b[35m]  Gofile uploader               [\u001b[36m8\u001b[35m]  IP scanner      \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m9\u001b[35m]  Nitro generator               [\u001b[36m10\u001b[35m] PassGen         \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m11\u001b[35m] Random quote                  [\u001b[36m12\u001b[35m] URL shortener   \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m13\u001b[35m] Weather app                   [\u001b[36m14\u001b[35m] Webhook checker \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m15\u001b[35m] Webhook spammer               [\u001b[36m16\u001b[35m] Webhook deleter \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m17\u001b[35m] Token checker                 [\u001b[36m18\u001b[35m] IP generator    \u001b[36m║\n";
        std::cout << "             ║ \u001b[35m[\u001b[36m19\u001b[35m] Show Wifi Passowrds           [\u001b[36m20\u001b[35m] Token info      \u001b[36m║\n";
        std::cout << "             ╚═════════════════════════════════════════════════════════╝\n";
        std::cout << "             BY: DreamyOak\n             Github: https://github.com/dreamyoak\n\n";
        int menuOption;
        std::cout << cyan << "╔═══[root" << green << "@" << cyan << "nagogy]\n" << "╚══>" << reset << " " << red;
        std::cin >> menuOption;
        std::cin.ignore();

        if (std::cin.fail()) { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Invalid Option\n";
            sleep(3);
            continue;
        }
        switch (menuOption) {
            case 1:
                clear();
                ascii();
                pause();
                break;
            case 2:
                clear();
                countdown();
                pause();
                break;
            case 3:
                clear();
                ctm();
                pause();
                break;
            case 4:
                clear();
                decode();
                pause();
                break;
            case 5:
                clear();
                discord_backup();
                pause();
                break;
            case 6:
                clear();
                fake_btc_miner();
                pause();
                break;
            case 7:
                clear();
                gofile();
                pause();
                break;
            case 8:
                clear();
                ip_info();
                pause();
                break;
            case 9:
                clear();
                nitro();
                pause();
                break;
            case 10:
                clear();
                password();
                break;
            case 11:
                clear();
                random_qoute();
                pause();
                break;
            case 12:
                clear();
                url_shortener();
                pause();
                break;
            case 13:
                clear();
                weather();
                pause();
                break;
            case 14:
                clear();
                webhook_checker();
                pause();
                break;
            case 15:
                clear();
                webhook_spammer();
                pause();
                break;
            case 16:
                clear();
                webhook_deleter();
                pause();
                break;
            case 17:
                clear();
                token_check();
                pause();
                break;
            case 18:
                clear();
                random_ip();
                pause();
                break;
            case 19:
                clear();
                wifi_passwords();
                pause();
                break;
            case 20:
                clear();
                token_info();
                pause();
                break;
            default:
                std::cout << "Invalid Option\n";
                sleep(3);
                break;
        }
    }

    return 0;
}
