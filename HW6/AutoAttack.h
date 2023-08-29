#pragma once
#include <map>
#include <functional>

#include "Target.h"


class AutoAttack {
	std::map<size_t, std::function<void(Target&)>> effects{};
	 
public:

	void attack(Target& target);

	void addEffect(const std::function<void(Target&)>& effect);

	void removeEffect();
	void removeEffect(size_t id);
};

