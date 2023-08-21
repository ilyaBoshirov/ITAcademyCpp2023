#include "FileRobotConfigurationLoader.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <sstream>


FileRobotConfigurationLoader::FileRobotConfigurationLoader() {
	this->configFileName = defaultConfigurationFileName;
}

FileRobotConfigurationLoader::FileRobotConfigurationLoader(std::string configFileName) {
	this->configFileName = configFileName;
}

void toLowerCase(std::string& line) {
	std::transform(line.begin(), line.end(), line.begin(),
		[](unsigned char c) { return std::tolower(c); });
}

std::list<std::string> splitLine(std::string line) {
	std::stringstream ss(line);

	std::list<std::string> elements{};
	std::string token;
	while (ss >> token) {
		elements.push_back(token);
	}

	return elements;
}

void FileRobotConfigurationLoader::loadConfiguration() {
	std::ifstream fin(this->configFileName);

	if (!fin) {
		std::cout << "Can't open file " << this->configFileName << std::endl;
		std::cout << "Use default parameters " << std::endl;
		return;
	}

	std::string line;

	while (std::getline(fin, line)) {
		toLowerCase(line);
		if (line.find("name") != std::string::npos) {
			this->configuration["name"] = splitLine(line).back();
			continue;
		}
		if (line.find("positionx") != std::string::npos) {
			this->configuration["positionX"] = splitLine(line).back();
			continue;
		}
		if (line.find("positiony") != std::string::npos) {
			this->configuration["positionY"] = splitLine(line).back();
			continue;
		}
		if (line.find("loadcapacity") != std::string::npos) {
			this->configuration["loadCapacity"] = splitLine(line).back();
			continue;
		}
	}
}

CONF FileRobotConfigurationLoader::getConfiguration() {
	return this->configuration;
}
