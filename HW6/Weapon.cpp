#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string name, unsigned int damage) {
	this->name = name;
	this->damage = damage;
}

std::string Weapon::getName() {
	return this->name;
}

unsigned int Weapon::getDamage() {
	return this->damage;
}