#include "Target.h"
#include <iostream>


void Target::doDamage(int damage) {
	this->health -= damage;
};

void Target::setDebuf(const std::string& debuff) {
	this->debuffs.push_back(debuff);
};

void Target::status() {
	std::cout << std::endl << "-----------------------------------" << std::endl;

	std::cout << "Health: " << health << std::endl;
	std::cout << "Debuffs: " << std::endl;

	for (const auto& defuf : debuffs)
	{
		std::cout << defuf << std::endl;
	}

	std::cout << std::endl << "-----------------------------------" << std::endl;
}

void Target::clear() {
	debuffs.clear();
}
