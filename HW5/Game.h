#pragma once
#include <vector>
#include "Robot.h"
#include "Stone.h"

constexpr uint8_t robotValue = 1;
constexpr uint8_t stoneValue = 2;

class Game {
	int fieldWidth;
	int fieldHeight;
	uint8_t** filed;
	Robot robot;
	std::vector<Stone> stones;
	bool gameIsRunning;

	void drowField();

public:
	Game();
	Game(Robot robot);
	Game(int fieldWidth, int fieldHeight);
	Game(int fieldWidth, int fieldHeight, Robot robot);
	~Game();

	bool getIsRunning();
	void setIsRunning(bool isRunning);
	void setRobot(const Robot& robot);
	void setFieldWidth(int fieldWidth);
	void setFieldHeight(int fieldHeight);
	std::pair<int, int> getFieldSize();
	void rebuild();

	int getStoneIndexByPosition(std::pair<int, int> position);
	void createDefaultFiled();
	void createFiled(int fieldWidth, int fieldHeight);
	void startGame();
	void keypressListener();
	void clearField();
	void addStonesToFiled(int stonesNumber);
	std::pair<int, int> getConsoleSize();

	Game& operator= (const Game& game);
};

