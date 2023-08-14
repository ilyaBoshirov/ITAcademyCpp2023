#include <iostream>
#include <string>

#include "Knight.h"
#include "Orc.h"
#include "Sword.h"


Knight createKnightHero() {
	int health = 200;
	int strength = 10;
	std::string name = "Arthur";
	Sword heroSword{ 20 };

	return Knight{ health, strength, name, heroSword };
}

Orc createBossOrc() {
	int health = 150;
	int strength = 50;
	std::string name = "Ekganit";

	return Orc{ health, strength, name };
}

Orc createOrdinaryOrc() {
	return Orc{};
}

void menu() {
	Knight hero = createKnightHero();
	Orc boss = createBossOrc();

}

int main() {
	menu();
	return 0;
}