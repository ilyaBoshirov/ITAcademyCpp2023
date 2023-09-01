#include "LFSR.h"

LFSR::LFSR() {
	this->initState = 0x1;
	this->state = this->initState;
}

LFSR::LFSR(LFSRSTATE state) {
	this->initState = state;
	this->state = this->initState;
}

LFSRSTATE LFSR::getState() {
	return this->state;
}

void LFSR::setState(LFSRSTATE state) {
	this->state = state;
}

LFSRSTATE LFSR::getBit() {
	LFSRSTATE x1 = (this->state >> (this->lfsrLength - 1)) & 0x1;
	LFSRSTATE x2 = (this->state >> (this->lfsrLength - 5)) & 0x1;
	LFSRSTATE x3 = this->state & 0x1;

	return (x1 & x2) ^ (x1 & x3) ^ (x2 & x3);
}

void LFSR::init() {
	for (auto i{ 0 }; i < INITROUND; ++i) {
		this->rotate();
	}
}

void LFSR::rotate() {
	LFSRSTATE x16 = (this->state >> (this->lfsrLength - 1)) & 0x1;
	LFSRSTATE x15 = (this->state >> (this->lfsrLength - 2)) & 0x1;
	LFSRSTATE x13 = (this->state >> (this->lfsrLength - 4)) & 0x1;
	LFSRSTATE x4 = (this->state >> (this->lfsrLength - 13)) & 0x1;

	this->state = ((this->state << 1) & 0xfffe) | (x16 ^ x15 ^ x13 ^ x4 );
}

void LFSR::reset() {
	this->state = this->initState;
}

LFSRSTATE LFSR::round() {
	auto bit = getBit();
	this->rotate();

	return bit;
}
