#include <iostream>
#include <vector>
#include <string>
#include <fstream>


#include "FindPattern.h"

constexpr auto task1VectorDataFileName = "task1_vector_data.txt";

void fillVector(std::vector<std::string>& lines) {

	std::ifstream fin(task1VectorDataFileName);

	std::string str;
	while (std::getline(fin, str)) {
		lines.push_back(str);
	}
}

void printVector(const std::vector<std::string>& lines) {
	size_t counter{ 0 };
	for (const auto& it : lines) {
		std::cout << "[" << counter << "]: " << it << std::endl;
		++counter;
	}
}

void task1() {
	std::vector<std::string> lines;
	fillVector(lines);
	printVector(lines);

	std::cout << std::endl << "Enter pattern you want to search: ";
	
	std::string pattern;
	std::cin >> pattern;

	std::cout << "NUmber of elements contains pattern [" << pattern << "] : " << getNumberOfMatches(lines, pattern) << std::endl;
}

int main() {
	// task 1 
	task1();
	

	return 0;
}