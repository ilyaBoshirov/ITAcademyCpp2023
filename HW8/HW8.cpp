#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <string>
#include <regex>
#include <chrono>

#include "LFSR.h"


std::mutex stateMutex;
std::mutex addSolutionMutex;
std::mutex completeAdd;

std::vector<bool> isComplete{};

struct Answer {

private:
	uint32_t candidate{ 0x1 };
	std::unique_ptr<std::vector<LFSRSTATE>> solution = std::make_unique<std::vector<LFSRSTATE>>();

public:
	void addSolution(LFSRSTATE answ) {
		solution.get()->push_back(answ);
	}

	std::vector<LFSRSTATE> getSolutions() {
		return *solution.get();
	}

	uint32_t getSolutionsLength() {
		return solution.get()->size();
	}

	uint32_t getCandidate() {
		return candidate;
	}

	void incCandidate() {
		++candidate;
	}
};

void bruteFunction(Answer* answerStruct, const std::string& desiredSequence) {
	LFSR lfsr{};

	stateMutex.lock();

	auto state = answerStruct->getCandidate();
	answerStruct->incCandidate();

	stateMutex.unlock();

	auto seqLength = desiredSequence.length();

	while (state <= 0xffff) {

		lfsr.setState(state & 0xffff);
		lfsr.init();

		std::string generatedSequence{ "" };
		for (auto i{ 0 }; i < seqLength; ++i) {
			generatedSequence += std::to_string( lfsr.round() );
		}

		if (generatedSequence == desiredSequence) {
			addSolutionMutex.lock();

			answerStruct->addSolution(state);

			addSolutionMutex.unlock();
		}

		// get next state

		stateMutex.lock();

		state = answerStruct->getCandidate();
		answerStruct->incCandidate();

		stateMutex.unlock();
	}

	completeAdd.lock();

	isComplete.push_back(true);

	completeAdd.unlock();
}

void runBruteforce(Answer& answerStruct, const std::string& desiredSequence) {

	unsigned int threadNumber{0};

	std::cout << "Enter thread number: " << std::endl;
	std::cin >> threadNumber;
	
	for (auto i{ 0 }; i < threadNumber; ++i) {
		std::thread bruter(bruteFunction, &answerStruct, desiredSequence);
		bruter.detach();
	}

	std::cout << std::endl;
	while (isComplete.size() != threadNumber) {
		stateMutex.lock();
		auto state = answerStruct.getCandidate();
		stateMutex.unlock();
		std::cout << "\rComplete " << (state * 100 / 0xffff) << "%";
		std::this_thread::sleep_for(std::chrono::microseconds(10));
	}

	std::cout << std::endl << "Number of find solutions: " << answerStruct.getSolutionsLength() << std::endl;
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

void fllDesiredSequence(std::string& sequence) {
	auto minLength = 1;
	std::cout << "Enter sequence from 0 and 1 to find lfsr state, that generate your sequence (length must be not less than " << minLength << "):" << std::endl;
	std::cin >> sequence;
	checkSequence(sequence, minLength);
}

int main() {	
	std::string desiredSequence;
	fllDesiredSequence(desiredSequence);

	Answer answer{};

	runBruteforce(answer, desiredSequence);

	return 0;
}