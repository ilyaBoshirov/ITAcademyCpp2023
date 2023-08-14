#include "Creature.h"

Creature::Creature() {
	this->health = 100;
	this->strength = 5;
}

Creature::Creature(int health, int strength) {
	this->health = health;
	this->strength = strength;
}

int Creature::getHealth() {
	return this->health;
}

void Creature::setHealth(int health) {
	this->health = health;
}

int Creature::getStrength() {
	return this->strength;
}

void Creature::setStrength(int strength) {
	this->strength = strength;
}

int Creature::makeDamage() {
	return this->strength;
}

void Creature::getDamage(int damage) {
	this->health = damage < this->health ? this->health - damage : 0;
}
