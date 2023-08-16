#include "GameObject.h"

GameObject::GameObject() {
	this->type = "game_object";
	this->positionX = 0;
	this->positionY = 0;
}

GameObject::GameObject(std::string type) {
	this->type = type;
	this->positionX = 0;
	this->positionY = 0;
}

GameObject::GameObject(std::string type, int posotionX, int posotionY) {
	this->type = type;
	this->positionX = posotionX;
	this->positionY = posotionY;
}

int GameObject::getPositionX() {
	return this->positionX;
}

int GameObject::getPositionY() {
	return this->positionY;
}

std::pair<int, int> GameObject::getPosition() {
	return std::make_pair(this->positionX, this->positionY);
}