#include "Game.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <random>


Game::Game() {
    this->createDefaultFiled();
    this->clearField();

    this->robot = Robot{};
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = 1;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(Robot robot) {
    this->createDefaultFiled();
    this->clearField();

    this->robot = robot;
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = 1;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(int fieldWidth, int fieldHeight) {
    this->createFiled(fieldWidth, fieldHeight);
    this->clearField();

    this->robot = Robot{};
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = 1;

    srand(time(NULL));
    auto stoneNumber = rand() % 11 + 5;

    this->addStonesToFiled(stoneNumber);
}

Game::Game(int fieldWidth, int fieldHeight, Robot robot) {
    this->createFiled(fieldWidth, fieldHeight);
    this->clearField();

    this->robot = robot;
    this->filed[this->robot.getPositionX()][this->robot.getPositionY()] = 1;

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

//void startGame();
//void showRules();
//void startKeypressHandler();

void Game::createFiled(int fieldWidth, int fieldHeight) {
    this->fieldWidth = fieldWidth;
    this->fieldHeight = fieldHeight;

    this->filed = new bool* [fieldHeight];
    for (auto i = 0; i < fieldHeight; ++i) {
        filed[i] = new bool[fieldWidth];
    }
}

void Game::createDefaultFiled() {
    std::pair<int, int> consoleSize = this->getConsoleSize();

    createFiled(this->fieldWidth, this->fieldHeight);
}

void Game::addStonesToFiled(int stonesNumber) {
    int x, y;
    srand(time(NULL));
    
    for (auto i = 0; i < stonesNumber; ++i) {
        do {
            x = rand() % this->fieldWidth;
            y = rand() % this->fieldWidth;

        } while (this->filed[x][y] != 0);
        
        this->stones.push_back(Stone{ x,y });
        this->filed[x][y] = 1;
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
