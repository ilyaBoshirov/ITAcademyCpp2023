#pragma once

#include <string>

#include "Creature.h"
#include "Sword.h"

constexpr auto LEVEL_UP_NUMBER = 2;

class Knight : public Creature {
	std::string name;
	Sword sword;
	uint32_t killedEnemyCounter;

public:

	Knight();
	Knight(std::string name);
	Knight(int health, int strength, std::string name);
	Knight(int health, int strength, std::string name, const Sword& sword);

	std::string getName();

	void addVictory();
	void healing();
	std::string getStatus();
	
	Knight& operator= (const Knight& knight);

	virtual int makeDamage();
};

