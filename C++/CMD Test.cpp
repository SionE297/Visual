#include <iostream>
#include <string>
#include <cstdlib> // For system("cls")
#include <conio.h> // For _getch()
#include <cstdlib> // For system("cls")

void clearScreen() {
    std::cout << "\033[2J\033[H";
}
void hideCursor() {
    std::cout << "\033[?25l";}
void showCursor() {
    std::cout << "\033[?25h";}

void colors() {
    std::cout << "\033[31mRed\033[0m\n";
    std::cout << "\033[32mGreen\033[0m\n";
    std::cout << "\033[33mYellow\033[0m\n";
    std::cout << "\033[34mBlue\033[0m\n";
    std::cout << "\033[35mMagenta\033[0m\n";
    std::cout << "\033[36mCyan\033[0m\n";
    std::cout << "\033[91mBright Red\033[0m\n";
    std::cout << "\033[92mBright Green\033[0m\n";
    std::cout << "\033[94mBright Blue\033[0m\n";
    std::cout << "\033[7mHighlight\033[0m\n";
    std::cout << "\033[30mBlack\033[0m\n";
    std::cout << "\033[0mReset\033[0m\n";
};

/*int arr[2][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
};

int row = 0;
int column = 0;*/

namespace ansi {
    const std::string bold         = "\033[1m";
    const std::string underline    = "\033[4m";
    const std::string resetbg      = "\033[0m";
    const std::string redbg        = "\033[31m\033[7m";
    const std::string cyanbg       = "\033[36m\033[7m";
    const std::string bluebg       = "\033[34m\033[7m";
    const std::string yellowbg     = "\033[33m\033[7m";
    const std::string reset        = "\033[0m";
    const std::string red          = "\033[31m";
    const std::string green        = "\033[32m";
    const std::string yellow       = "\033[33m";
    const std::string blue         = "\033[34m";
    const std::string magenta      = "\033[35m";
    const std::string cyan         = "\033[36m";
    const std::string bright_red   = "\033[91m";
    const std::string bright_green = "\033[92m";
    const std::string bright_blue  = "\033[94m";
    const std::string highlight    = "\033[7m";
    const std::string black        = "\033[30m";
}
using namespace ansi;

std::string username="Sion";
std::string password="123";
std::string usernameInput;
std::string passwordInput;

const int tasks = 5;
std::string task[tasks] = {
    "Notes",
    "Arduino",
    "BlackBox",
    "Empty",
    "Settings"
    };
int selectedTask = 0;

void displayTasks() {
    clearScreen();
    hideCursor();
    std::cout <<red<<bold<< "Options:\n\n"<<reset;
    for (int i=0; i<tasks; i++) {
        if (i == selectedTask) {
            std::cout << redbg << task[i] << resetbg << "\n";
        } else {
            std::cout << resetbg << task[i] << resetbg << "\n";
        }
    }
}

void Notes() {
    clearScreen();
    std::cout <<red<< "Notes selected.\n";
    // Add your notes functionality here
}
void Arduino() {
    clearScreen();
    std::cout <<red<< "Arduino selected.\n";
    // Add your Arduino functionality here
}
void BlackBox() {
    clearScreen();
    std::cout <<red<< "BlackBox selected.\n";
    // Add your BlackBox functionality here
}
void Empty() {
    clearScreen();
    std::cout <<red<< "Empty selected.\n";
    // Add your Empty functionality here
}
void Settings() {
    clearScreen();
    std::cout <<red<< "Settings selected.\n";
    // users and passwords
    //
}

/*class Menu {
    public:
    Menu(const )
}


*/



int main() {

system("cls");
showCursor();

std::cout <<red<< "Username: " <<blue;
std::cin >> usernameInput;
std::cout <<red<< "Password: " <<black;
hideCursor();
std::cin >> passwordInput;
std::cout << reset;

if (usernameInput != username && passwordInput != password) {
    std::cout <<red<< "\nInvalid Username or Password\n"<<reset; 
    return 1; // Exit if the credentials are invalid
}

clearScreen();

displayTasks(); //put it here to stop reset on any key press
while (true) {

char key = _getch();
if ((key == 'w') && (selectedTask > 0)) {
    selectedTask--;
    displayTasks();
} 
else if ((key == 's') && (selectedTask < tasks - 1)) {
    selectedTask++;
    displayTasks();
} 
else if (key == '\r') { // Enter key (carriage return)
    break;
} 
}//while

system("cls");
switch (selectedTask) {
    case 0: // Notes
        Notes();
        break;
    case 1: // Arduino
        Arduino();
        break;
    case 2: // BlackBox
        BlackBox();
        break;
    case 3: // Empty
        Empty();
        break;
    case 4: // Settings
        Settings();
        break;
}








return 0;
} // main