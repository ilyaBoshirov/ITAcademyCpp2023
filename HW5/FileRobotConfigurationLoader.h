#pragma once
#include <string>

#include "RobotConfigurationLoader.h"
/*
CONFIG FILE FORMAT:

Name: <value>
PositionX: <value>
PositionY: <value>
LoadCapacity: <value>
*/

constexpr auto defaultConfigurationFileName = "config.txt";

class FileRobotConfigurationLoader : public RobotConfigurationLoader {
	std::string configFileName;

public:
	FileRobotConfigurationLoader();
	FileRobotConfigurationLoader(std::string configFileName);

	void loadConfiguration() override;
	CONF getConfiguration() override;
};

