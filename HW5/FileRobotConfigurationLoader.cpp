#include "FileRobotConfigurationLoader.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <set>

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
	}

	std::string line;

	while (!fin.eof()) {
		fin >> line;
		toLowerCase(line);
		if (line.find("name") != std::string::npos) {
			this->configuration["name"] = splitLine(line).back();
			continue;
		}
		if (line.find("position x") != std::string::npos) {
			this->configuration["positionX"] = std::stoi(splitLine(line).back());
			continue;
		}
		if (line.find("position y") != std::string::npos) {
			this->configuration["positionY"] = std::stoi(splitLine(line).back());
			continue;
		}
		if (line.find("load capacity") != std::string::npos) {
			this->configuration["loadCapacity"] = std::stoi(splitLine(line).back());
			continue;
		}
	}
}

CONF FileRobotConfigurationLoader::getConfiguration() {
	return this->configuration;
}
