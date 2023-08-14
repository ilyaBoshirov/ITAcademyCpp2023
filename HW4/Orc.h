#pragma once
#include <string>
#include "Creature.h"

class Orc : public Creature {
	std::string name;

public:

	Orc();
	Orc(std::string name);
};

