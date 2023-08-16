#pragma once
#include "RobotConfigurationLoader.h"

class CLIRobotConfigurationLoader : public RobotConfigurationLoader {
public:
	CLIRobotConfigurationLoader();

	void loadConfiguration() override;
	CONF getConfiguration() override;
};

