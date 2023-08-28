#include "Hero.h"


Hero::Hero() {
	this->name = "Arthur";
	this->health = 100;
	this->strength = 10;
	this->capacity = 7;
}

Hero::Hero(std::string name) {
	this->name = name;
	this->health = 100;
	this->strength = 10;
	this->capacity = 7;
}

Hero::Hero(std::string name, unsigned int health, unsigned int strength) {
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->capacity = 7;
}

Hero::Hero(std::string name, unsigned int health, unsigned int strength, size_t capacity) {
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->capacity = capacity;
}

unsigned int Hero::getDamage() {
	
	auto generalDamage = this->strength;
	
	for (const auto& item : this->weapon) {
		generalDamage += item.second();
	}
}

unsigned int getWeaponInfo();

void Hero::addWeapon(const std::function<unsigned int(Weapon&)>& effect) {
	this->weapons.''
}



void AddEffect(const std::function<void(Target&)>& effect)
{
	m_effects.push_back(effect);
}

void dropWeapon();
void dropWeapon(size_t id);
void dropWeapon(std::string name);