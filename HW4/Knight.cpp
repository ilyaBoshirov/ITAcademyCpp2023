#include "Knight.h"


Knight::Knight() : Creature(), sword() {
	this->name = "Arthur";
}

Knight::Knight(std::string name) : Creature(), sword(), name(name) {};

Knight::Knight(int health, int strength, std::string name) : Creature(health, strength), sword(), name(name) {};

Knight::Knight(int health, int strength, std::string name, Sword sword) : Creature(health, strength), sword(sword), name(name) {};

int Knight::makeDamage() {
	return this->getStrength() + this->sword.getDamage();
}
