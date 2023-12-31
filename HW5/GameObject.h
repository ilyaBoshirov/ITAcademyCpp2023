#pragma once

#include <string>

class GameObject {
	std::string type;

protected:
	int positionX;
	int positionY;

public:
	GameObject();
	GameObject(std::string type);
	GameObject(std::string type, int posotionX, int posotionY);

	int getPositionX();
	int getPositionY();

	void setPositionX(int positionX);
	void setPositionY(int positionY);

	std::pair<int, int> getPosition();
};

