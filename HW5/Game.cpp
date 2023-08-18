#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <random>
#include <conio.h>
#include <vector>


Game::Game() {
    this->createDefaultFiled();
    this->clearField();

    this->robot = Robot{};
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = robotValue;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(Robot robot) {
    this->createDefaultFiled();
    this->clearField();

    this->robot = robot;
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = robotValue;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(int fieldWidth, int fieldHeight) {
    this->createFiled(fieldWidth, fieldHeight);
    this->clearField();

    this->robot = Robot{};
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = robotValue;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(int fieldWidth, int fieldHeight, Robot robot) {
    this->createFiled(fieldWidth, fieldHeight);
    this->clearField();

    this->robot = robot;
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = robotValue;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::~Game() {
    for (auto i = 0; i < this->fieldHeight; ++i) {
        delete[] this->filed[i];
    }
    
    delete[] this->filed;
}

bool Game::getIsRunning() {
    return this->gameIsRunning;
}

void Game::setIsRunning(bool isRunning) {
    this->gameIsRunning = isRunning;
}

void Game::startGame() {
    // todo
    system("cls");
    this->gameIsRunning = true;
}

void Game::drowField() {
    for (auto j = 0; j < this->fieldWidth + 1; ++j) {
        std::cout << '_';
    }
    std::cout << std::endl;

    for (auto i = 0; i < this->fieldHeight; ++i) {
        for (auto j = 0; j < this->fieldWidth; ++j) {
            std::cout << (this->filed[i][j] == 0 ? ' ' : (this->filed[i][j] == 1 ? '#' : '*'));
        }
        std::cout << '|' << std::endl;
    }

    for (auto j = 0; j < this->fieldWidth + 1; ++j) {
        std::cout << '_';
    }
    std::cout << std::endl;
}

void Game::keypressListener() {
    char ch;

    int x, y;

    while (this->gameIsRunning) {
        system("cls");
        this->drowField();

        x = robot.getPositionX();
        y = robot.getPositionY();

        ch = _getch();
        
        // move UP
        if (ch == 'w' || ch == 'W') {
            if (x - 1 >= 0 && this->filed[x - 1][y] == 0) {
                robot.moveLeft();
                this->filed[x][y] = 0;
                this->filed[x - 1][y] = 1;
            }
        }

        // move DOWN
        if (ch == 's' || ch == 'S') {
            if (x + 1 < this->fieldHeight && this->filed[x + 1][y] == 0) {
                robot.moveRight();
                this->filed[x][y] = 0;
                this->filed[x + 1][y] = 1;
            }
        }

        // move LEFT
        if (ch == 'a' || ch == 'A') {
            if (y - 1 >= 0 && this->filed[x][y -1] == 0) {
                robot.moveUp();
                this->filed[x][y] = 0;
                this->filed[x][y - 1] = 1;
            }
        }

        // move RIGHT
        if (ch == 'd' || ch == 'D') {
            if (y + 1 < this->fieldWidth && this->filed[x][y + 1] == 0) {
                robot.moveDown();
                this->filed[x][y] = 0;
                this->filed[x][y + 1] = 1;
            }
        }     

        //TAKE 1 STONE
        if (ch == 'e' || ch == 'E') {

            int stoneIndex{};

            auto iStart = (x - 1 >= 0) ? x - 1 : x;
            auto jStart = (y - 1 >= 0) ? y - 1 : y;

            auto iLast = (x + 1 < this->fieldHeight) ? x + 1 : x;
            auto jLast = (y + 1 < this->fieldWidth) ? y + 1 : y;
            
            for (auto i = iStart; i <= iLast; ++i) {
                for (auto j = jStart; j <= jLast; ++j) {
                    if (this->filed[i][j] == stoneValue) {
                        stoneIndex = this->getStoneIndexByPosition(std::make_pair(i, j));
                        this->robot.takeItem(this->stones.at(stoneIndex));
                        this->stones.erase(this->stones.begin() + stoneIndex);
                        this->filed[i][j] = 0;
                        break;
                    }
                }
            }
        }

        //QUIT GAME
        if (ch == 'q' || ch == 'Q') {
            std::cout << "EXIT..." << std::endl;
            this->gameIsRunning = false;
        }
    }
}

int Game::getStoneIndexByPosition(std::pair<int,int> position) {
    int stoneIndex = 0;

    for (auto& it : this->stones) {
       if (it.getPositionX() == position.first && it.getPositionY() == position.second) {
           return stoneIndex;
       }
       ++stoneIndex;
    }

    return stoneIndex;
}

void Game::showMenu() {
    
}

void Game::showRules() {

}

void Game::createFiled(int fieldWidth, int fieldHeight) {
    this->fieldWidth = fieldWidth;
    this->fieldHeight = fieldHeight;

    this->filed = new uint8_t* [fieldHeight];
    for (auto i = 0; i < fieldHeight; ++i) {
        filed[i] = new uint8_t[fieldWidth];
    }
}

void Game::createDefaultFiled() {
    std::pair<int, int> consoleSize = this->getConsoleSize();

    createFiled(consoleSize.first, consoleSize.second);
}

void Game::addStonesToFiled(int stonesNumber) {
    int x, y;
    srand(time(NULL));
    
    for (auto i = 0; i < stonesNumber; ++i) {
        do {
            x = rand() % this->fieldHeight;
            y = rand() % this->fieldWidth;

        } while (this->filed[x][y] != 0);

        this->stones.push_back(Stone{ x,y });
        this->filed[x][y] = stoneValue;
    }
}

void Game::clearField() {
    for (auto i = 0; i < this->fieldHeight; ++i) {
        for (auto j = 0; j < this->fieldWidth; ++j) {
            filed[i][j] = 0;
        }
    }
}

std::pair<int, int> Game::getConsoleSize() {
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
