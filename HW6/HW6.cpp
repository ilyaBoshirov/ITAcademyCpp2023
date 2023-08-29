#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <numeric>


#include "FindPattern.h"
#include "VectorAnalyzer.h"
#include "Mathematics.h"
#include "MyException.h"
#include "Target.h"
#include "AutoAttack.h"


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
	std::cout << "*********** TASK 1 ***********" << std::endl;
	std::cout << "Load lines from file " << task1VectorDataFileName << std::endl;
	
	std::vector<std::string> lines;
	fillVector(lines);
	printVector(lines);

	std::cout << std::endl << "Enter pattern you want to search: ";
	std::string pattern;
	std::cin >> pattern;

	std::cout << "NUmber of elements contains pattern [" << pattern << "] : " << getNumberOfMatches(lines, pattern) << std::endl;
}

void task2() {
	std::cout << "*********** TASK 2 ***********" << std::endl;
	std::vector<int> numbers(10);
	std::iota(numbers.begin(), numbers.end(), 1);

	VectorAnalyzer<int> analyzer{ numbers };
	analyzer.showData();

	std::cout << "Square vectoe elements with std::transform" << std::endl;
	analyzer.square();
	analyzer.showData();

	std::cout << "Enter value to add to all elements of vector: ";
	
	int value{ 0 };
	std::cin >> value;

	std::cout << std::endl << "Add " << value << " to elements elements with std::transform" << std::endl;
	analyzer.plus(value);
	analyzer.showData();

	std::cout << "Test adjacent_find" << std::endl;
	analyzer.findIdenticalNeighbors();

	std::cout << "Push back 4 to vector" << std::endl;
	analyzer.pushBack(4);
	std::cout << "Push back 4 to vector" << std::endl;
	analyzer.pushBack(4);

	std::cout << "New vector" << std::endl;
	analyzer.showData();

	analyzer.findIdenticalNeighbors();
}

void task3() {
	std::cout << "*********** TASK 3 ***********" << std::endl;

	AutoAttack autoAttack{};
	Target target{};
	
	target.status();

	autoAttack.addEffect([](Target& target) {
			target.doDamage(208);
		});

	autoAttack.addEffect([](Target& target) {
			target.setDebuf("poison");
			target.setDebuf("fire!");
		});

	autoAttack.addEffect([](Target& target) {
			target.setDebuf("fatality!");
		});

	autoAttack.attack(target);
	target.status();

	std::cout << "Remove last effect (fatality)" << std::endl;
	autoAttack.removeEffect();
	autoAttack.attack(target);
	target.status();

	autoAttack.addEffect([](Target& target) {
		target.setDebuf("fatality!");
		});

	std::cout << "Remove 2nd effect (by id)" << std::endl;
	autoAttack.removeEffect(1);
	autoAttack.attack(target);
	target.status();

	target.clear();
}

void task4() {
	std::cout << "*********** TASK 4 ***********" << std::endl;
	Mathematics math{};

	std::cout << "Enter integer for calculating hyperbolic cotangent ";
	auto value{ 0 };
	std::cin >> value;
	std::cout << std::endl;

	try {
		std:: cout << "Result: " << math.hyperbolicCotangent(value) << std::endl;
	}
	catch (MyException& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Something get wrong" << std::endl;
	}

	std::cout << "Enter integer for calculating factorial ";
	std::cin >> value;
	std::cout << std::endl;

	try {
		std::cout << "Result: " << math.factorial(value) << std::endl;
	}
	catch (MyException& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Something get wrong" << std::endl;
	}

	std::cout << "Enter n and m for calculating binomial coefficient ";
	auto m{ 0 };
	std::cin >> value >> m;
	std::cout << std::endl;

	try {
		std::cout << "Result: " << math.binomialCoefficient(value, m) << std::endl;
	}
	catch (MyException& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Something get wrong" << std::endl;
	}
}


int main() {
	task1();

	task2();

	task3();

	task4();	

	return 0;
}