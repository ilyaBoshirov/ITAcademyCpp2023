#pragma once
#include <iostream>

typedef uint16_t LFSRSTATE;
constexpr auto INITROUND = 30;

class LFSR
{
	LFSRSTATE initState;
	LFSRSTATE state;

	size_t lfsrLength{ 16 };

public:
	LFSR();
	LFSR(LFSRSTATE state);

	LFSRSTATE getState();
	void setState(LFSRSTATE state);

	LFSRSTATE getBit();
	LFSRSTATE round();
	void init();
	void rotate();
	void reset();
};
