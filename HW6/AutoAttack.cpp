#include "AutoAttack.h"
#include <string>
#include <iostream>


void AutoAttack::attack(Target & target) {
	for (const auto& effect : this->effects){
		effect.second(target);
	}
}

void AutoAttack::addEffect(const std::function<void(Target&)>& effect) {
	this->effects[this->effects.size()] = effect;
}

void AutoAttack::removeEffect() {
	size_t effectsSize = this->effects.size();
	
	if (effectsSize == 0) {
		std::cout << "No effects" << std::endl;
		return;
	}

	this->effects.erase(effectsSize - 1);
}

void AutoAttack::removeEffect(size_t id) {
	size_t effectsSize = this->effects.size();

	if (id < 0 || id >= effectsSize) {
		std::cout << "Wrogn value of id. Not in [" << 0 << ", " << effectsSize - 1 << "]" << std::endl;
		return;
	}

	this->effects.erase(id);
}

