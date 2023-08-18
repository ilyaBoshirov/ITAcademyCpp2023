#include "Robot.h"
#include <iostream>
#include <set>

Robot::Robot() : GameObject("robot") {
	this->name = defaultRobotName;
	this->loadCapacity = defaultLoadCapacity;
	this->currentWeight = 0;
}

Robot::Robot(CONF& robotConfiguration) : GameObject("robot") {
	// get all keys
	std::set<std::string> keys;
	for (const auto it : robotConfiguration) {
		keys.insert(it.first);
	}

	this->name = (keys.find("name") != keys.end()) ? robotConfiguration[std::string("name")] : defaultRobotName;

	this->positionX = (keys.find("positionX") != keys.end()) ? std::stoi(robotConfiguration[std::string("positionX")]) : this->positionX;

	this->positionY = (keys.find("positionY") != keys.end()) ? std::stoi(robotConfiguration[std::string("positionY")]) : this->positionX;

	this->loadCapacity = (keys.find("loadCapacity") != keys.end()) ? std::stoi(robotConfiguration[std::string("loadCapacity")]) : defaultLoadCapacity;

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

void Robot::setName(std::string name) {
	this->name = name;
}

void Robot::setLoadCapacity(int loadCapacity) {
	this->loadCapacity = loadCapacity;
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
