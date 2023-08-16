#include "Robot.h"
#include <iostream>

Robot::Robot() : GameObject("robot") {
	this->name = defaultRobotName;
	this->loadCapacity = defaultLoadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(std::string name) : GameObject("robot") {
	this->name = name;
	this->loadCapacity = defaultLoadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(std::string name, int loadCapacity) : GameObject("robot") {
	this->name = name;
	this->loadCapacity = loadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(std::string name, int posotionX, int posotionY) : GameObject("robot", positionX, positionY) {
	this->name = name;
	this->loadCapacity = defaultLoadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(int loadCapacity, int posotionX, int posotionY) : GameObject("robot", positionX, positionY) {
	this->name = defaultRobotName;
	this->loadCapacity = loadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(std::string name, int loadCapacity, int posotionX, int posotionY) : GameObject("robot", positionX, positionY) {
	this->name = name;
	this->loadCapacity = loadCapacity;
	this->currentWeight = 0;
}

void Robot::moveLeft() {
	this->positionX -= 1;
}

void Robot::moveRight() {
	this->positionX += 1;
}

void Robot::moveUp() {
	this->positionY -= 1;
}

void Robot::moveDown() {
	this->positionY += 1;
}

bool Robot::takeItem(Stone stone) {
	if (stone.getWeight() <= (this->loadCapacity - this->currentWeight)) {
		this->trunk.push(stone);
		return true;
	}

	std::cout << "Can't take stone. Overload." << std::endl;

	return false;
}

Stone Robot::putItem() {
	Stone stone = this->trunk.top();
	this->trunk.pop();
	return stone;
}

Robot& Robot::operator= (const Robot& robot) {
	if (this == &robot) {
		return *this;
	}

	this->name = robot.name;
	this->loadCapacity = robot.loadCapacity;
	this->currentWeight = robot.currentWeight;
	this->trunk = robot.trunk;
	this->positionX = robot.positionX;
	this->positionY = robot.positionY;

	return *this;
}