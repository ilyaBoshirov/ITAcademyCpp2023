#pragma once
#include <map>
#include <string>

typedef std::map<std::string, std::string> CONF;

class RobotConfigurationLoader {
protected:
	CONF configuration;

public:
	virtual void loadConfiguration() = 0;
	virtual CONF getConfiguration() = 0;
};