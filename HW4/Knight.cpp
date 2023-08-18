#include "Knight.h"


Knight::Knight() : Creature(), sword() {
	this->name = "Arthur";
	this->killedEnemyCounter = 0;
}

Knight::Knight(std::string name) : Creature(), sword(), name(name), killedEnemyCounter{0} {};

Knight::Knight(int health, int strength, std::string name) : Creature(health, strength), sword(), name(name), killedEnemyCounter{ 0 } {};

Knight::Knight(int health, int strength, std::string name, const Sword& sword) : Creature(health, strength), sword(sword), name(name), killedEnemyCounter{ 0 } {};

std::string Knight::getName() {
	return this->name;
}

int Knight::makeDamage() {
	return this->getStrength() + this->sword.getDamage();
}

void Knight::addVictory() {
	this->killedEnemyCounter += 1;
	if (killedEnemyCounter % LEVEL_UP_NUMBER == 0) {
		this->sword.update();
	}
}

void Knight::healing() {
	this->currentHealth = this->initHealth;
}

std::string Knight::getStatus() {
	return (this->name + ". HP: " + std::to_string(this->currentHealth) + ", damage: " + std::to_string(this->makeDamage()) + ".");
}

Knight& Knight::operator= (const Knight& knight) {
	if (this == &knight) {
		return *this;
	}

	this->initHealth = knight.initHealth;
	this->currentHealth = knight.currentHealth;
	this->strength = knight.strength;
	this->sword = knight.sword;
	this->name = knight.name;

	return *this;
}
