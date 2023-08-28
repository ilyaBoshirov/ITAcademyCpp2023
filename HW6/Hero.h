#pragma once
#include <functional>
#include <map>
#include <string>

#include "Weapon.h"


class Hero {
	std::string name;
	unsigned int health;
	unsigned int strength;
	size_t capacity;
	std::map<uint32_t, std::function<unsigned int(Weapon&)>> weapons{};

public:
	Hero();
	Hero(std::string name);
	Hero(std::string name, unsigned int health, unsigned int strength);
	Hero(std::string name, unsigned int health, unsigned int strength, size_t capacity);

	unsigned int getDamage();
	unsigned int getWeaponInfo();

	void addWeapon(const std::function<unsigned int(Weapon&)>& effect);

	void dropWeapon();
	void dropWeapon(size_t id);
	void dropWeapon(std::string name);
};

