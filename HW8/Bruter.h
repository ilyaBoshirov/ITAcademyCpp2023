#pragma once
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <vector>

#include "LFSR.h"

class Bruter {
	uint32_t candidate{ 0x1 };
	std::vector<LFSRSTATE> solution{};
	std::string desiredSequence;
	size_t threadNumber{ 0 };
	std::vector<bool> isComplete{};
	// mutexes
	std::shared_mutex readCandidateMutex;  // mutex for reading state 
	std::mutex writeCandidateMutex;  // mutex for reading state 
	std::mutex addSolutionMutex;  // mutex for adding solution in structure
	std::mutex completeAddMutex;  // mutex for adding true in vector when thread end working
	
public:
	Bruter(const std::string desiredSequence, size_t threadNumber);

	uint32_t getCandidate();
	void incCandidate();

	std::vector<LFSRSTATE> getSolutions();
	size_t getSolutionsLength();
	void addSolution(LFSRSTATE answ);
		
	void bruteFunction();
	void startBruteforce();
	void endWaiting();
	void printResults();
};
