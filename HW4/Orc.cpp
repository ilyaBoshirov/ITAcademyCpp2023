#include "Orc.h"

Orc::Orc(): Creature() {
	this->name = "Kegigoth";
}

Orc::Orc(std::string name) : Creature(), name(name) {}

Orc::Orc(int health, int strength, std::string name) : Creature(health, strength), name(name) {}

std::string Orc::getName() {
	return this->name;
}

Orc& Orc::operator= (const Orc& orc) {
	if (this == &orc) {
		return *this;
	}

	this->initHealth = orc.initHealth;
	this->currentHealth = orc.currentHealth;
	this->strength = orc.strength;
	this->name = orc.name;

	return *this;
}