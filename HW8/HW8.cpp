#include <iostream>
#include <regex>
#include <string>
#include <Windows.h>

#include "Bruter.h"
#include "LFSR.h"

constexpr size_t minUserSequenceLength = 7;

size_t getConsoleWidth() {
	auto width{ 0 };
	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(STD_OUTPUT_HANDLE)) {
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
			width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
		}
		else {
			std::cout << "Error: " << GetLastError() << std::endl;
		}
	}
	else {
		std::cout << "Error: " << GetLastError() << std::endl;
	}

	return width;
}

void helloMsg() {
	std::cout << std::string(getConsoleWidth(), '=') << std::endl;
	std::cout << "Welcome to LFSR bruter!" << std::endl;
	std::cout << "LFSR - linear feedback shift register. It is type of stream ciphers" << std::endl;
	std::cout << "The feedback of this cipher is calculated by the formula:" << std::endl << std::endl;
	std::cout << "x^16 + x^15 + x^13 + x^4 + 1" << std::endl << std::endl;
	std::cout << "This polynomial is primitive, which provides the period of the generated gamma equal to 2^16" << std::endl;
	std::cout << "You can enter some gamma and the program, using parallelized enumeration, will find the filling of the register, which will result in the desired sequence of bits" << std::endl;
	std::cout << std::string(getConsoleWidth(), '=') << std::endl << std::endl;
}

void checkSequence(const std::string& sequence, int minLength) {
	if (sequence.length() < minLength) {
		std::cout << "Your sequence is too small" << std::endl;
		std::cout << "Try another time, bye..." << std::endl;
		exit(1);
	}

	std::regex reg("[01]*");

	if (!std::regex_match(sequence, reg)) {
		std::cout << "Why you enetr characters other than 0 and 1?" << std::endl;
		std::cout << "Try another time, bye..." << std::endl;
		exit(2);
	}

}

void fillDesiredSequence(std::string& sequence) {
	auto minLength = 1;
	std::cout << "Enter sequence from 0 and 1 to find lfsr state, that generate your sequence (length must be not less than " << minLength << "):" << std::endl;
	std::cin >> sequence;
	checkSequence(sequence, minLength);
}

size_t getThreadNumber() {
	size_t threadNumber{ 0 };

	std::cout << "Enter thread number: " << std::endl;
	std::cin >> threadNumber;
	std::cout << std::endl;

	return threadNumber;
}

void start() {
	std::string sequence;
	fillDesiredSequence(sequence);
	checkSequence(sequence, minUserSequenceLength);

	auto threadNumber = getThreadNumber();

	Bruter bruter{ sequence , threadNumber };
	bruter.startBruteforce();
	bruter.endWaiting();
	bruter.printResults();
}

int main() {
	helloMsg();
	start();
	return 0;
}
