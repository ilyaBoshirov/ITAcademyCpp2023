#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>

typedef std::pair<std::string, std::string> LAPINFO;
typedef std::vector<LAPINFO> RACEINFO;

constexpr auto storageFile = "data.txt";
constexpr auto fileSeparator = "********************";
constexpr auto lapsNumber = 5;

void printHelpMessage(std::string programmName);

void printMenu();

RACEINFO startNewRace();

void printAllResults(RACEINFO history);

void printLastResult(RACEINFO history);

RACEINFO loadResults();

void saveResults(RACEINFO raceInfo);

void clearCmd();

void backToMenu();
