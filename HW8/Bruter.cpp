#include "Bruter.h"

#include <chrono>
#include <thread>

Bruter::Bruter(std::string desiredSequence, size_t threadNumber) {
	this->desiredSequence = desiredSequence;
	this->threadNumber = threadNumber;
}

void Bruter::addSolution(LFSRSTATE answ) {
	std::lock_guard<std::mutex> lg(this->addSolutionMutex);
	solution.push_back(answ);
}

std::vector<LFSRSTATE> Bruter::getSolutions() {
	return this->solution;
}

size_t Bruter::getSolutionsLength() {
	return this->solution.size();
}

uint32_t Bruter::getCandidate() {
	std::shared_lock<std::shared_mutex> sl(this->readCandidateMutex);
	return this->candidate;
}

void Bruter::incCandidate() {
	std::lock_guard<std::mutex> lg(this->writeCandidateMutex);
	++this->candidate;
}

void Bruter::printResults() {
	auto solutionLength = this->getSolutionsLength();
	std::cout << std::endl << "Number of find solutions: " << solutionLength << std::endl;

	if (solutionLength > 0) {
		std::cout << "SOLUTION LIST:" << std::endl;

		for (auto i{ 0 }; i < solutionLength; ++i) {
			std::cout << "[" << std::dec << int(i) << "] ";
			std::cout << "0x" << std::hex << this->solution[i] << std::endl;
		}
	}
}

void Bruter::endWaiting() {
	if (this->threadNumber != 0) {
		while (this->isComplete.size() != this->threadNumber) {
			auto candidate = this->getCandidate();
			std::cout << "\rComplete " << (candidate * 100 / 0xffff) << "%";
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	
	std::cout << "\rComplete 100%";
}

void Bruter::startBruteforce() {
	if (this->threadNumber == 0) {
		this->bruteFunction();
		return;
	}

	for (auto i{ 0 }; i < threadNumber; ++i) {
		std::thread bruter(&Bruter::bruteFunction, this);
		bruter.detach();
	}
}

void Bruter::bruteFunction() {
	LFSR lfsr{};

	auto currentCandidate = this->getCandidate();
	this->incCandidate();

	auto seqLength = desiredSequence.length();

	while (currentCandidate <= 0xffff) {

		lfsr.setState(currentCandidate & 0xffff);
		lfsr.init();

		std::string generatedSequence{ "" };
		for (auto i{ 0 }; i < seqLength; ++i) {
			generatedSequence += std::to_string(lfsr.round());
		}

		if (generatedSequence == desiredSequence) {
			this->addSolution(currentCandidate);
		}

		// get next state
		currentCandidate = this->getCandidate();
		this->incCandidate();
	}

	std::lock_guard<std::mutex> lg(completeAddMutex);
	this->isComplete.push_back(true);
}
