#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <limits.h>

using namespace std;


int main() {
    char hostname[HOST_NAME_MAX]; // I'm using char!
    gethostname(hostname, HOST_NAME_MAX);

    const char* username = getenv("USER");
    cout << "____________________________________________" << endl;
    cout << "\033[1;36m" << "               Computer Fetch               " << "\033[0;0m" << endl;
    cout << "____________________________________________" << endl;
    cout << "\033[1;36m";
    cout << "             ";
    if (username) cout << username;
    else cout << "idk";
    cout << "@" << hostname << endl;
    cout << "   .--.      OS: " << flush;
    system("grep '^PRETTY_NAME=' /etc/os-release | cut -d= -f2- | tr -d '\"'");
    cout << "  |o_o |     Bash: " << flush;
    system("bash --version | head -n1 | awk '{print $4}'");
    cout << "  |:_/ |     Now Playing: " << flush;
    system("playerctl metadata --format '{{artist}} - {{title}}'");
    cout << " //   \\ \\    Packages: " << flush;
    system("pacman -Q | wc -l");
    cout << "(|     | )   Uptime:" << flush;
    system("uptime -p | sed 's/up//'");
    cout << "/'\\_   _/`\\  DE: " << flush;
    system("echo $XDG_CURRENT_DESKTOP");
    cout << "\\___)=(___/  Kernel Version: " << flush;
    system("uname -r");
    cout << "             Kitty Version: " << flush;
    system("kitty -v");
    cout << "\033[1;36m";
    cout << "             Memory: " << flush;
    system("free -h | awk '/Mem:/ {print $3 \"/\" $2}'");
    cout << "\033[0;0m";
    string coloursFirstRow[] = {
        "\033[0;30m", "\033[0;31m", "\033[0;32m", "\033[0;33m",
        "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m"
    };
    string coloursSecondRow[] = {
        "\033[1;30m", "\033[1;31m", "\033[1;32m", "\033[1;33m",
        "\033[1;34m", "\033[1;35m", "\033[1;36m", "\033[1;37m"
    };

    cout << "             ";
    for (int i = 0; i < 8; i++) {
        cout << coloursFirstRow[i] << "███" << "\033[0m";
    }
    cout << endl;
    cout << "             ";
    for (int i = 0; i < 8; i++) {
        cout << coloursSecondRow[i] << "███" << "\033[0m";
    }
    cout << endl;
    cout << "____________________________________________" << endl;
    return 0;
}
