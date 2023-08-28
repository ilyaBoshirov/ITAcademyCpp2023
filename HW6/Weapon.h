#pragma once
#include <string>


class Weapon {
	std::string name;
	unsigned int damage;

public:
	Weapon(std::string name, unsigned int damage);

	std::string getName();
	unsigned int getDamage();
};

