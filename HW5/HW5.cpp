#include <algorithm>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
#include <Windows.h>

#include "CLIRobotConfigurationLoader.h"
#include "FileRobotConfigurationLoader.h"
#include "Game.h"


constexpr auto minFieldWidth = 10;
constexpr auto minFieldHeight = 10;


Robot initRobot(std::pair<int, int> gameFieldSize) {
    std::cout << "Select robot initialization type:" << std::endl;
    std::cout << "1 - CLI" << std::endl;
    std::cout << "2 - FILE" << std::endl;
    std::cout << "3 - DEFAULT" << std::endl;

    char ch;
    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3');

    Robot robot{};

    // cli enter
    if (ch == '1') {
        CLIRobotConfigurationLoader robotLoader{};
        robotLoader.loadConfiguration();

        auto configuration = robotLoader.getConfiguration();
        
        robot = Robot{ configuration };
    }

    // file enter
    if (ch == '2') {
        std::cout << "Enter file name: ";
        std::string fileName;
        std::cin >> fileName;
        std::cout << std::endl;

        FileRobotConfigurationLoader robotLoader{ fileName };
        robotLoader.loadConfiguration();

        auto configuration = robotLoader.getConfiguration();

        robot = Robot{ configuration };
    }

    // default robot
    if (ch == '3') {
        robot = Robot{};
    }

    // check robot position in game field
    auto newPosition{ 0 };
    
    while (robot.getPositionX() < 0 || robot.getPositionX() > gameFieldSize.first - 1) {
        std::cout << "Wrong robon position x. It must be in range [0, " << gameFieldSize.first - 1 << "]." << std::endl;
        std::cout << "New position x: ";
        std::cin >> newPosition;
        std::cout << std::endl;

        robot.setPositionX(newPosition);
    }

    while (robot.getPositionY() < 0 || robot.getPositionY() > gameFieldSize.second - 1) {
        std::cout << "Wrong robon position y. It must be in range [0, " << gameFieldSize.second - 1 << "]." << std::endl;
        std::cout << "New position y: ";
        std::cin >> newPosition;
        std::cout << std::endl;

        robot.setPositionY(newPosition);
    }         

    return robot;
}

void showMenu() {
    system("cls");
    std::cout << "Welcome to Scavenger Robot Simulator." << std::endl;
    std::cout << std::endl;
    std::cout << "1 - START NEW GAME" << std::endl;
    std::cout << "2 - SHOW RULES" << std::endl;
    std::cout << "3 - EXIT" << std::endl;
}

void showRules() {
    system("cls");
    std::cout << "Your goal is to clear the field of debris(stones)." << std::endl;
    std::cout << "# --- ROBOT." << std::endl;
    std::cout << "* --- STONE." << std::endl;
    std::cout << "Your goal is to clear the field of debris(stones)." << std::endl;
    std::cout << "Robot control:" << std::endl;
    std::cout << "w - UP" << std::endl;
    std::cout << "s - DOWN" << std::endl;
    std::cout << "a - LEFT" << std::endl;
    std::cout << "d - RIGHT" << std::endl;
    std::cout << "e - pick up an item(if you are near it)" << std::endl;
    std::cout << "q - exit" << std::endl;
}

std::pair<int, int> getConsoleSize() {
    int width, height;
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(STD_OUTPUT_HANDLE)) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
            width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;

        }
        else {
            std::cout << "Error: " << GetLastError() << std::endl;
        }
    }
    else {
        std::cout << "Error: " << GetLastError() << std::endl;
    }

    return std::make_pair(width, height);
}

void initGame(Game& game) {
    auto width{ 0 }, height{ 0 };

    auto consoleSize = getConsoleSize();

    // enter game field width
    while (true) {
        std::cout << "Field width: ";
        std::cin >> width;

        if (width < minFieldWidth || width > (consoleSize.first - 2)) {
            std::cout << "Wrong value of width. It must be in range [0, " << consoleSize.first - 2 << "]." << std::endl;
        }
        else {
            break;
        }
    }

    // enter game field height
    while (true) {
        std::cout << "Field height: ";
        std::cin >> height;

        if (height < minFieldHeight || height >(consoleSize.second - 3)) {
            std::cout << "Wrong value of height. It must be in range [0, " << consoleSize.second - 3 << "]." << std::endl;
        }
        else {
            break;
        }
    }

    game.setFieldWidth(width);
    game.setFieldHeight(height);

    game.rebuild();

    Robot robot = initRobot(game.getFieldSize());

    game.setRobot(robot);
}

void init() {
    showMenu();
     
    char ch;
    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3'); 

    // show rukes
    if (ch == '2') {
        showRules();
        exit(2);
    }
    // exit
    if (ch == '3') {
        exit(2);
    }
}

void runGame(Game& game) {
    for (auto i{ 0 }; i < 3; i++) {
        std::cout << "Start in " << 3 - i << "..." << "\r";
        Sleep(1000);
    }

    game.startGame();
    std::thread thread(&Game::keypressListener, &game);

    thread.join();
}

int main(int argc, char* argv[]) {
    init();
    Game currGame{};
    initGame(currGame);
    runGame(currGame);
	return 0;
}
