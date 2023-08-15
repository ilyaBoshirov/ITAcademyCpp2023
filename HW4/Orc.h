#pragma once
#include <string>
#include "Creature.h"

class Orc : public Creature {
	std::string name;

public:

	Orc();
	Orc(std::string name);
	Orc(int health, int strength, std::string name);

	std::string getName();

	Orc& operator= (const Orc& orc);
};

