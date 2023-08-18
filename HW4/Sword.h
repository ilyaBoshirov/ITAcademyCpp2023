#pragma once

constexpr auto SWORD_MAX_LEVEL = 3;

class Sword {
	int level;
	int damage;

	int maxLevel = SWORD_MAX_LEVEL;

public:

	Sword();
	Sword(int damage);
	Sword(const Sword& sword);

	int getDamage();
	void update();

	Sword& operator= (const Sword& sword);
};
