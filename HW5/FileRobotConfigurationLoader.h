#pragma once
#include <string>

#include "RobotConfigurationLoader.h"

constexpr auto defaultConfigurationFileName = "config.txt";

class FileRobotConfigurationLoader : public RobotConfigurationLoader {
	std::string configFileName;

public:
	FileRobotConfigurationLoader();
	FileRobotConfigurationLoader(std::string configFileName);

	void loadConfiguration() override;
	CONF getConfiguration() override;
};

