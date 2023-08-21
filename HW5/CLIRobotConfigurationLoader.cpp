#include "CLIRobotConfigurationLoader.h"

#include <iostream>
#include <string>

CLIRobotConfigurationLoader::CLIRobotConfigurationLoader() {}

void CLIRobotConfigurationLoader::loadConfiguration() {
	std::cout << "Entet robot parameters" << std::endl;
	std::cout << "Robot name: ";
	std::string name;
	std::cin >> name;
	this->configuration["name"] = name;

	std::cout << "Position X: ";
	int tempValue;
	std::cin >> tempValue;
	this->configuration["positionX"] = std::to_string(tempValue);

	std::cout << "Position Y: ";
	std::cin >> tempValue;
	this->configuration["positionY"] = std::to_string(tempValue);

	std::cout << "Load Capacity: ";
	std::cin >> tempValue;
	this->configuration["loadCapacity"] = std::to_string(tempValue);
}

CONF CLIRobotConfigurationLoader::getConfiguration() {
	return this->configuration;
}