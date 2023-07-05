#include "ArrayMath.h"


void ArrayMath::minEvenElement(int* arr, size_t arraySize) {
	auto minEven = 0;
	auto hasEvenElement = false;
	auto minOdd = arr[0];

	for (auto i = 0; i < arraySize; ++i) {
		if (!hasEvenElement && arr[i] % 2 == 0) {
			minEven = arr[i];
			hasEvenElement = true;
			continue;
		}

		if (hasEvenElement && arr[i] < minEven && arr[i] % 2 == 0) {
			minEven = arr[i];
			continue;
		}

		if (arr[i] < minOdd) {
			minOdd = arr[i];
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

uint32_t ArrayMath::getMinAndMaxSumNuber(int* arr, size_t arraySize) {
	auto minValue = arr[0];
	auto minIndex = 0;
	auto maxValue = arr[0];
	auto maxIndex = 0;
	auto tempFlag = false;

	for (auto i = 0; i < arraySize; ++i) {
		tempFlag = arr[i] < minValue;
		minValue = tempFlag ? arr[i] : minValue;
		minIndex = tempFlag ? i : minIndex;

		tempFlag = arr[i] > maxValue;
		maxValue = tempFlag ? arr[i] : maxValue;
		maxIndex = tempFlag ? i : maxIndex;
	}

	return minIndex + maxIndex;
}

int ArrayMath::getOddElementsProduct(int* arr, size_t arraySize) {
	auto resultProduct = 1;
	for (auto i = 1; i < arraySize; i += 2) {
		resultProduct *= arr[i];
	}

	return resultProduct;
}

void ArrayMath::simpleSwap(int* arr, int i, int j) { 
	auto temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void ArrayMath::smartSwap(int* arr, int i, int j) {
	arr[i] ^= arr[j];
	arr[j] ^= arr[i];
	arr[i] ^= arr[j];
}