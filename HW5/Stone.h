#pragma once

#include <string>

#include "GameObject.h"

class Stone: public GameObject {
	int weight;

public:
	Stone();
	Stone(int weight);
	Stone(int posotionX, int posotionY);
	Stone(int posotionX, int posotionY, int weight);

	int getWeight();

	Stone& operator= (const Stone& stone);
};

