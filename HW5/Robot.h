#pragma once

#include <string>
#include <stack>

#include "GameObject.h"
#include "Stone.h"

constexpr auto defaultLoadCapacity = 100;
constexpr auto defaultRobotName = "WALL-E";

class Robot: public GameObject {
	std::string name;
	int loadCapacity;
	int currentWeight;
	std::stack<Stone> trunk{};
	
public:
	Robot();
	Robot(std::string name);
	Robot(std::string name, int loadCapacity);
	Robot(std::string name, int posotionX, int posotionY);
	Robot(int loadCapacity, int posotionX, int posotionY);
	Robot(std::string name, int loadCapacity, int posotionX, int posotionY);

	void setName();
	void setLoadCapacity();
	void setPositionX();
	void setPositionY();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool takeItem(Stone stone);
	Stone putItem();

	Robot& operator= (const Robot& robot);
};

