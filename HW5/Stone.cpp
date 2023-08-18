#include "Stone.h"
#include <ctime>
#include <random>

Stone::Stone(): GameObject("stone") {
	srand(time(NULL));
	this->weight = rand() % 11 + 5;
}

Stone::Stone(int weight): GameObject("stone") {
	this->weight = weight;
}

Stone::Stone(int posotionX, int posotionY) : GameObject("stone", posotionX, posotionY) {
	srand(time(NULL));
	
	this->weight = rand() % 11 + 5; 
	this->positionX = positionX;
	this->positionY = positionY;
}

Stone::Stone(int posotionX, int posotionY, int weight) : GameObject("stone", posotionX, posotionY) {
	this->weight = weight;
}

int Stone::getWeight() {
	return this->weight;
}

Stone& Stone::operator= (const Stone& stone) {
	if (this == &stone) {
		return *this;
	}

	this->weight = stone.weight;
	this->positionX = stone.positionX;
	this->positionY = stone.positionY;
	
	return *this;
}