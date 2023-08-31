#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

#include "LFSR.h"

struct Answer {
	uint16_t candidate{ 0x1 };
	std::vector<uint16_t> solution{};
};

void bruteFunction() {
	LFSR lfsr{};
	auto state = 0x1;

	while (state != 0) {



		state = 0x1;
	}
}


int main() {

	uint16_t initialState = 0x1;

	LFSR lfsr{initialState};


	return 0;
}