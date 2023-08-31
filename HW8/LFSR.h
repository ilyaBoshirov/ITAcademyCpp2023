#pragma once
#include <iostream>

constexpr auto INITROUND = 30;

class LFSR
{
	uint16_t initState;
	uint16_t state;

	size_t lfsrLength{ 16 };

public:
	LFSR();
	LFSR(uint16_t state);

	uint16_t getState();
	void setState(uint16_t state);

	uint16_t getBit();
	uint16_t round();
	void init();
	void rotate();
	void reset();
};
