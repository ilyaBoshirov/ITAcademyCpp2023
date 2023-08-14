#pragma once
class Sword {
	int level;
	int damage;

	const int maxLevel = 3;

public:

	Sword();
	Sword(int damage);

	Sword(const Sword& sword);

	int getDamage();

	void update();
};


