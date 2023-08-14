#include "Creature.h"

Creature::Creature() {
	this->initHealth = 100;
	this->currentHealth = this->initHealth;
	this->strength = 5;
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

int Creature::makeDamage() {
	return this->strength;
}

void Creature::getDamage(int damage) {
	this->currentHealth = damage < this->currentHealth ? this->currentHealth - damage : 0;
}
