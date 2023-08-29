#pragma once
#include <functional>
#include <vector>
#include <string>


class Target {
	int health{ 1000 };
	std::vector<std::string> debuffs{};

public:
	void doDamage(int damage);
	void setDebuf(const std::string& debuff);
	void status();
	void clear();
};
