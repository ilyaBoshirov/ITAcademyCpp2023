#include "Sword.h"
#include <iostream>

Sword::Sword() {
	this->level = 1;
	this->damage = 10;
}

Sword::Sword(int damage) {
	this->level = 1;
	this->damage = damage;
}

Sword::Sword(const Sword& sword) {
	this->level = sword.level;
	this->damage = sword.damage;
}

int Sword::getDamage() {
	return this->damage;
}

void Sword::update() {
	if (this->level < this->maxLevel) {
		this->level += 1;
		this->damage += 10;

		std::cout << "Now you have sword of level " << this->level << "! New damage: " << this->damage << std::endl;
	}
	else {
		std::cout << "You have sword of maximum level! (damage of your sword: " << this->damage << ")" << std::endl;
	}
}

Sword& Sword::operator= (const Sword& sword) {
	if (this == &sword) {
		return *this;
	}
		
	this->level = sword.level;
	this->damage = sword.damage;
	this->maxLevel = sword.maxLevel;

	return *this;
}