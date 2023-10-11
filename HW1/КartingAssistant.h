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

void printHelpMessage(const std::string& programmName);

void printMenu();

RACEINFO startNewRace();

void printAllResults(const RACEINFO& history);

void printLastResult(const RACEINFO& history);

RACEINFO loadResults();

void saveResults(const RACEINFO& raceResult);

void clearCmd();

void backToMenu();
