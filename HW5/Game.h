#pragma once
#include <vector>
#include "Robot.h"
#include "Stone.h"

class Game {
	int fieldWidth;
	int fieldHeight;
	bool** filed;
	Robot robot;
	std::vector<Stone> stones;

public:
	Game();
	Game(Robot robot);
	Game(int fieldWidth, int fieldHeight);
	Game(int fieldWidth, int fieldHeight, Robot robot);
	~Game();

	void createDefaultFiled();
	void createFiled(int fieldWidth, int fieldHeight);
	void startGame();
	void showRules();
	void startKeypressHandler();
	void clearField();
	void addStonesToFiled(int stonesNumber);
	std::pair<int, int> getConsoleSize();

};

