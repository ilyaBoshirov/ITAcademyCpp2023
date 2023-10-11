#include "КartingAssistant.h"

void printHelpMessage(const std::string& programmName) {
	std::cout << "This is help message for " << programmName << std::endl;
	std::cout << "Press 1 for start new race. To start stopwotch and fix lap time use SPACE;" << std::endl;
	std::cout << "Press 2 for printing result of last race;" << std::endl;
	std::cout << "Press 3 for printing result of all races;" << std::endl;
	std::cout << "Press 4 for printing this help message;" << std::endl;
	std::cout << "Press 5 for cleaning cmd;" << std::endl;
	std::cout << "Press 6 for quit." << std::endl;
	std::cout << std::endl;
}

void printLastResult(const RACEINFO& history) {
	int numberOfRaces = (history.size() - (history.size() % lapsNumber)) / lapsNumber;

	if (numberOfRaces == 0) {
		std::cout << "No results" << std::endl;
		return;
	}

	std::cout << "Race #" << numberOfRaces << " result" << std::endl;

	for (auto j = 0; j < lapsNumber; ++j) {
		auto lapIndex = lapsNumber * (numberOfRaces - 1) + j;
		std::cout << "Lap " << j + 1 << "; Time: " << history[lapIndex].first;

		if (history[lapIndex].second.length() > 0) {
			std::cout << " ; Comment: " << history[lapIndex].second;
		}

		std::cout << ";" << std::endl;
	}

	std::cout << std::endl;
}

void printAllResults(const RACEINFO& history) {
	int numberOfRaces = (history.size() - (history.size() % lapsNumber)) / lapsNumber;

	if (numberOfRaces == 0) {
		std::cout << "No results" << std::endl;
		return;
	}

	for (auto i{ 0 }; i < numberOfRaces; ++i) {
		std::cout << "Race #" << i + 1 << " result" << std::endl;

		for (auto j = 0; j < lapsNumber; ++j) {
			auto lapIndex = lapsNumber * i + j;
			std::cout << "Lap " << j + 1 << "; Time: " << history[lapIndex].first;
			
			if (history[lapIndex].second.length() > 0) {
				std::cout << "; Comment:" << history[lapIndex].second;
			}

			std::cout << ";" << std::endl;
		}
	}

	std::cout << std::endl;
}

RACEINFO startNewRace() {
	std::cout << "Press SPACE to start race (and fix lap time)" << std::endl;

	bool tempFlag = false;
	while (!tempFlag) {
		switch (_getch())
		{
		case 32:
			std::cout << "START!!!" << std::endl;
			tempFlag = true;
		default:
			break;
		}
	}

	// fix time of race
	RACEINFO raceInfo{};

	for (auto i = 0; i < lapsNumber; ++i) {
		tempFlag = false;
		clock_t tStart = clock();

		std::cout << (i + 1) << " lap time - ";

		double lapTime{};

		while (!tempFlag) {
			switch (_getch())
			{
			case 32:
				lapTime = (double)(clock() - tStart) / CLOCKS_PER_SEC;
				raceInfo.push_back(std::make_pair(std::to_string(lapTime), ""));

				std::cout << lapTime << std::endl;
				tempFlag = true;

			default:
				break;
			}
		}
	}

	tempFlag = false;

	// add comment to laps

	while (!tempFlag) {
		std::string userChoice;
		std::string comment;

		std::cout << "Do you want to add some comment to laps?" << std::endl;
		std::cout << "1 - yes" << std::endl;
		std::cout << "2 - no" << std::endl;
		std::cout << std::endl << "Your choise: ";
		std::cin >> userChoice;
		std::cout << std::endl;

		try {
			std::string strLapIndex;
			switch (std::stoi(userChoice)) {
			case 1:
			lapChoise:
				std::cout << "lap number (1 - " << lapsNumber << "): ";
				std::cin >> strLapIndex;
				if (std::stoi(strLapIndex) < 1 || std::stoi(strLapIndex) > lapsNumber) {
					std::cout << "Wrong lap index! Please, try again" << std::endl;
					break;
				}
				std::cout << std::endl;

				std::cout << "Comment: ";
				std::cin >> comment;
				raceInfo[std::stoi(strLapIndex) - 1].second += (" " + comment);
				break;

			case 2:
				tempFlag = true;
				break;
			default:
				std::cout << "Wrong value! Please, try again" << std::endl;
				continue;
			}
		}
		catch (std::invalid_argument const& e) {
			std::cout << "Please, type integer value. Try again" << std::endl;
		}
		catch (std::exception const& e) {
			std::cout << "Something get wrong. Bye!" << std::endl;
			std::cout << "Message: " << e.what() << std::endl;
			std::cout << "Type:    " << typeid(e).name() << std::endl;
		}
	}

	std::cout << "Race complete!" << std::endl;

	return raceInfo;
}

void backToMenu() {
	std::cout << "Press any key to back to menu..." << std::endl;
	clearCmd();
}

void clearCmd() {
	system("cls");
}

void printMenu() {
	std::cout << "Plese, choose what you want to do:" << std::endl;
	std::cout << "1 - start new race" << std::endl;
	std::cout << "2 - print last result" << std::endl;
	std::cout << "3 - print all results" << std::endl;
	std::cout << "4 - help" << std::endl;
	std::cout << "5 - clear cmd" << std::endl;
	std::cout << "6 - quit" << std::endl;
}

void saveResults(const RACEINFO& raceResult) {
	std::ofstream fout(storageFile, std::ios::app);
	if (!fout) {
		std::cout << "Error when open file. Please, try again" << std::endl;
	}

	fout << "********************";
	for (const auto& lapInfo : raceResult) {
		fout << std::endl << lapInfo.first << "\t" << lapInfo.second;
	}
	fout << std::endl;

	fout.close();
}

LAPINFO splitLine(const std::string& line) {
	auto tabIndex = line.find('\t');
	return std::make_pair(line.substr(0, tabIndex), line.substr(tabIndex + 1));
}

RACEINFO loadResults() {
	std::ifstream fin(storageFile);
	if (!fin) {
		std::cout << "Error when open file" << std::endl;
		fin.close();

		// create file
		std::cout << "Create new storage file" << std::endl;
		std::ofstream fout(storageFile, std::ios::app);
		fout.close();

		return RACEINFO{};
	}

	RACEINFO raceHistory{};
	std::string fileStr{};
	while (!fin.eof()) {
		std::getline(fin, fileStr);

		if (fileStr.find(fileSeparator) != -1 || fileStr.length() == 0 ) {
			continue;
		}
		raceHistory.push_back(splitLine(fileStr));
	}
	fin.close();

	return raceHistory;
}
