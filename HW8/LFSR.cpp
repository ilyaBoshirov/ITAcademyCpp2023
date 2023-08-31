#include "LFSR.h"

LFSR::LFSR() {
	this->initState = 0x1;
	this->state = this->initState;
}

LFSR::LFSR(uint16_t state) {
	this->initState = state;
	this->state = this->initState;
}

uint16_t LFSR::getState() {
	return this->state;
}

void LFSR::setState(uint16_t state) {
	this->state = state;
}

uint16_t LFSR::getBit() {
	uint16_t x1 = (this->state >> (this->lfsrLength - 1)) & 0x1;
	uint16_t x2 = (this->state >> (this->lfsrLength - 5)) & 0x1;
	uint16_t x3 = this->state & 0x1;

	return (x1 & x2) ^ (x1 & x3) ^ (x2 & x3);
}

void LFSR::init() {
	for (auto i{ 0 }; i < INITROUND; ++i) {
		this->rotate();
	}
}

void LFSR::rotate() {
	uint16_t x16 = (this->state >> (this->lfsrLength - 1)) & 0x1;
	uint16_t x15 = (this->state >> (this->lfsrLength - 2)) & 0x1;
	uint16_t x13 = (this->state >> (this->lfsrLength - 4)) & 0x1;
	uint16_t x4 = (this->state >> (this->lfsrLength - 13)) & 0x1;

	this->state = ((this->state << 1) & 0xfffe) | (x16 ^ x15 ^ x13 ^ x4 );
}

void LFSR::reset() {
	this->state = this->initState;
}

uint16_t LFSR::round() {
	auto bit = getBit();
	this->rotate();

	return bit;
}
