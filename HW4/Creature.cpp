#include "Creature.h"
#include <ctime>
#include <random>

Creature::Creature() {
	srand(time(NULL));

	this->initHealth = rand() % 41 + 80;
	this->currentHealth = this->initHealth;
	this->strength = rand() % 11 + 5;
}

Creature::Creature(int health, int strength) {
	this->initHealth = health;
	this->currentHealth = this->initHealth;
	this->strength = strength;
}

int Creature::getHealth() {
	return this->currentHealth;
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
	this->currentHealth = damage < this->currentHealth ? this->currentHealth - damage : 0;
}
