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

void printIntroduction(std::string heroName, std::string bossName) {
	std::cout << "Hello, Knight " << heroName << "!" << std::endl << std::endl;
	std::cout << "You have to fight with the leader of the orcs" << bossName << "to free the beautiful princess." << std::endl;
	std::cout << "However remember that at the beginning of the journey, your strength may be small, so it's worth walking around and pumping up your combat abilities before fighting the boss." << std::endl;
	std::cout << "Good luck!" << std::endl << std::endl;
}

void printGameMenu() {
	std::cout << "1 - print hero status;" << std::endl;
	std::cout << "2 - kill some orc;" << std::endl;
	std::cout << "3 - cure the hero;" << std::endl;
	std::cout << "4 - fight with boss;" << std::endl;
	std::cout << "0 - exit game." << std::endl;
}

void playGame(Knight knight, Orc boss) {
	printIntroduction(knight.getName(), boss.getName());
	system("pause");

	bool gameStatus = true;
	int userChoice;
	while (gameStatus) {
		system("cls");
		printGameMenu();

		std::cout << "Enter: ";
		std::cin >> userChoice;
		std::cout << std::endl;

		switch (userChoice)
		{
		case 1:
			std::cout << knight.getStatus() << std::endl;
			system("pause");
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}

void startGame() {
	Knight hero = createKnightHero();
	Orc boss = createBossOrc();

	playGame(hero, boss);
}

int main() {
	startGame();
	return 0;
}




