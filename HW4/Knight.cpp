#include "Knight.h"


Knight::Knight() : Creature(), sword() {
	this->name = "Arthur";
	this->killedEnemyCounter = 0;
}

Knight::Knight(std::string name) : Creature(), sword(), name(name), killedEnemyCounter{0} {};

Knight::Knight(int health, int strength, std::string name) : Creature(health, strength), sword(), name(name), killedEnemyCounter{ 0 } {};

Knight::Knight(int health, int strength, std::string name, Sword sword) : Creature(health, strength), sword(sword), name(name), killedEnemyCounter{ 0 } {};

int Knight::makeDamage() {
	return this->getStrength() + this->sword.getDamage();
}

void Knight::addVictory() {
	this->killedEnemyCounter += 1;
	if (killedEnemyCounter % 3 == 0) {
		this->sword.update();
	}
}

void Knight::healing() {
	this->currentHealth = this->initHealth;
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
