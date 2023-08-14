#pragma once

#include <string>

#include "Creature.h"
#include "Sword.h"

class Knight : public Creature {
	std::string name;
	Sword sword;

public:

	Knight();
	Knight(std::string name);
	Knight(int health, int strength, std::string name);
	Knight(int health, int strength, std::string name, Sword sword);

	virtual int makeDamage();
};

