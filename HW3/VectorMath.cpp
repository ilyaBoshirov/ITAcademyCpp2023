#include "VectorMath.h"


void VectorMath::minEvenElement(std::vector<int>* vec) {
	auto minEven = 0;
	auto hasEvenElement = false;
	auto minOdd = vec->at(0);

	for (auto element : *vec) {
		if (!hasEvenElement && element % 2 == 0) {
			minEven = element;
			hasEvenElement = true;
			continue;
		}

		if (hasEvenElement && element < minEven && element % 2 == 0) {
			minEven = element;
			continue;
		}

		if (element < minOdd) {
			minOdd = element;
			continue;
		}
	}

	if (hasEvenElement) {
		std::cout << "Minimal even elemnt: " << minEven << std::endl;
	}
	else {
		std::cout << "No even elements in vector" << std::endl;
		std::cout << "Minimal odd elemnt: " << minOdd << std::endl;
	}
}

uint32_t VectorMath::getMinAndMaxSumNuber(std::vector<int>* vec) {
	auto minValue = vec->at(0);
	auto minIndex = 0;
	auto maxValue = vec->at(0);
	auto maxIndex = 0;
	auto tempFlag = false;

	auto vecSize = vec->size();
	for (auto i = 0; i < vecSize; ++i) {
		tempFlag = vec->at(i) < minValue;
		minValue = tempFlag ? vec->at(i) : minValue;
		minIndex = tempFlag ? i : minIndex;
		
		tempFlag = vec->at(i) > maxValue;
		maxValue = tempFlag ? vec->at(i) : maxValue;
		maxIndex = tempFlag ? i : maxIndex;
	}

	return minIndex + maxIndex;
}

int VectorMath::getOddElementsProduct(std::vector<int>* vec) {
	auto vecSize = vec->size();
	auto resultProduct = 1;
	for (auto i = 1; i < vecSize; i += 2) {
		resultProduct *= vec->at(i);
	}

	return resultProduct;
}

// classic swap
void VectorMath::simpleSwap(std::vector<int>* vec, int i, int j) {
	auto temp = vec->at(i);
	vec[0][i] = vec[0][j];
	vec[0][j] = temp;
}

// smart swap without "temp"
void VectorMath::smartSwap(std::vector<int>* vec, int i, int j) {
	vec[0][i] ^= vec[0][j];
	vec[0][j] ^= vec[0][i];
	vec[0][i] ^= vec[0][j];
}

// use std::swap
void VectorMath::stdSwap(std::vector<int>* vec, int i, int j) {
	std::swap(vec[0][i], vec[0][j]);
}