#pragma once
class Creature {

protected:
	int initHealth;
	int currentHealth;
	int strength;

public:

	Creature();
	Creature(int health, int strength);

	int getHealth();
	void setHealth(int health);
	int getStrength();
	void setStrength(int strength);

	virtual int makeDamage();
	void getDamage(int damage);
};

