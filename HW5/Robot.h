#pragma once

#include <stack>
#include <string>

#include "GameObject.h"
#include "RobotConfigurationLoader.h"
#include "Stone.h"


constexpr auto defaultLoadCapacity = 10000;
constexpr auto defaultRobotName = "WALL-E";

class Robot: public GameObject {
	std::string name;
	int loadCapacity;
	int currentWeight;
	std::stack<Stone> trunk{};
	
public:
	Robot();
	Robot(CONF& robotConfiguration);
	Robot(std::string name);
	Robot(std::string name, int loadCapacity);
	Robot(std::string name, int posotionX, int posotionY);
	Robot(int loadCapacity, int posotionX, int posotionY);
	Robot(std::string name, int loadCapacity, int posotionX, int posotionY);

	void setName(std::string name);
	void setLoadCapacity(int loadCapacity);
	
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool takeItem(Stone stone);
	Stone putItem();

	Robot& operator= (const Robot& robot);
};
