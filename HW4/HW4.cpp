#include <iostream>
#include <string>
#include <windows.h>

#include "Knight.h"
#include "Orc.h"
#include "Sword.h"

constexpr auto SLEEP_TIME = 1000;


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
	std::cout << std::endl;
	std::cout << "1 - print hero status;" << std::endl;
	std::cout << "2 - kill some orc;" << std::endl;
	std::cout << "3 - cure the hero;" << std::endl;
	std::cout << "4 - fight with boss;" << std::endl;
	std::cout << "0 - exit game." << std::endl;
}

int fightWithOrc(Knight& knight, Orc& orc, bool isBoss) {
	/*
	Function return:
	0 - if you win
	1 - if you lose
	*/

	std::string enemyType = isBoss ? "orc leader " + orc.getName() : "orc";

	std::cout << "Oh no, you met " << enemyType << " with " << orc.getHealth() << " HP and " << orc.getStrength() << " strength" << std::endl;
	std::cout << "Let's fight!" << std::endl;

	int damage;
	while (knight.getHealth() > 0 || orc.getHealth() > 0) {
		Sleep(SLEEP_TIME);
		damage = knight.makeDamage();
		orc.getDamage(damage);
		std::cout << "You dealt " << damage << " damage to the orc" << std::endl;

		if (orc.getHealth() == 0) {
			break;
		}

		Sleep(SLEEP_TIME);
		damage = orc.makeDamage();
		knight.getDamage(damage);
		std::cout << "You took " << damage << " damage from the orc" << std::endl;
		
		std::cout << "Your HP: " << knight.getHealth() << "; Enemy HP: " << orc.getHealth() << "." << std::endl;
		
		std::cout << std::endl;
	}

	if (knight.getHealth() == 0) {
		std::cout << "Oh no, you lose!" << std::endl;
		return 1;
	}

	std::cout << "Congratulations you killed the " << enemyType << "!" << std::endl;
	knight.addVictory();
	return 0;

}

void playGame(Knight knight, Orc boss) {
	printIntroduction(knight.getName(), boss.getName());
	system("pause");

	bool gameEnd = false;
	int userChoice;
	int fightResult;
	Orc ordinaryOrc;

	while (!gameEnd) {
		printGameMenu();

		std::cout << "Enter: ";
		std::cin >> userChoice;
		std::cout << std::endl;

		switch (userChoice)
		{
		case 1:
			std::cout << knight.getStatus() << std::endl;
			break;
		case 2:
			system("cls");
			ordinaryOrc = createOrdinaryOrc();
			fightResult = fightWithOrc(knight, ordinaryOrc, false);
			if (fightResult) {
				std::cout << "You died without saving the princess. Try another time. Bye!" << std::endl;
				exit(0);
			}
			system("pause");
			system("cls");
			break;
		case 3:
			std::cout << "Healing hero..." << std::endl;
			knight.healing();
			break;
		case 4:
			system("cls");
			fightResult = fightWithOrc(knight, boss, true);
			if (fightResult) {
				std::cout << "Boss kill you. You so weak. Try another time. Bye!" << std::endl;
				exit(0);
			}
			gameEnd = true;
			system("pause");
			system("cls");
			break;
		case 0:
			std::cout << "You didn't want to save the princess. Goodbye..." << std::endl;
			gameEnd = true;
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







