#include <iostream>
#include "VectorMath.h"
#include "ArrayMath.h"

bool indexIsCorrect(int i, size_t size) {
	if (i < 0 || i >= size) {
		return false;
	}

	return true;
}

void printVector(std::vector<int> *vec) {
	for (auto element : *vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

void showVectorOperations() {
	size_t vectorSize;
	std::cout << "Enter vector size: ";
	std::cin >> vectorSize;

	auto vec = std::make_unique<std::vector<int>>();
	std::cout << "Enter vector elements: " << std::endl;
	
	int element;
	for (auto i = 0; i < vectorSize; ++i) {
		std::cin >> element;
		vec->push_back(element);
	}

	std::cout << "VECTOR ELEMENTS" << std::endl;
	printVector(vec.get());

	std::cout << std::endl << "#1. GET MINIMAL EVEN (ODD) ELEMENT" << std::endl;
	VectorMath::minEvenElement(vec.get());

	std::cout << std::endl << "#2. SUM OF NUMBERS OF MINIMUM AND MAXIMUM ELEMENTS" << std::endl;
	auto sum = VectorMath::getMinAndMaxSumNuber(vec.get());
	std::cout << "Sum: " << sum << std::endl;

	std::cout << std::endl << "#3. PRODUCT OF ELEMENTS WITH ODD INDEXES" << std::endl;
	auto product = VectorMath::getOddElementsProduct(vec.get());
	std::cout << "Product: " << product << std::endl;

	std::cout << std::endl << "#4. SWAP 2 ELEMENTS" << std::endl;
	std::cout << "ENTER INDEXES TO SWAP: ";

	size_t i = 0, j = 0;
	std::cin >> i >> j;

	if (i == j) {
		std::cout << "You enter same i and j" << std::endl;
		return;
	}
	if (!indexIsCorrect(i, vectorSize)) {
		std::cout << "You enter wrong value of i" << std::endl;
		return;
	}
	if (!indexIsCorrect(j, vectorSize)) {
		std::cout << "You enter wrong value of j" << std::endl;
		return;
	}

	VectorMath::simpleSwap(vec.get(), i, j);
	std::cout << "#4.1. classic swap:" << std::endl;
	printVector(vec.get());

	VectorMath::smartSwap(vec.get(), i, j);
	std::cout << "#4.2. smart (xor) swap:" << std::endl;
	printVector(vec.get());

	VectorMath::stdSwap(vec.get(), i, j);
	std::cout << "#4.3. std swap:" << std::endl;
	printVector(vec.get());
}

void printArray(int* arr, size_t arraySize) {
	for (auto i = 0; i < arraySize; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void showArrayOperations() {
	size_t arraySize;
	std::cout << "Enter array size: ";
	std::cin >> arraySize;

	int* arr = new int[arraySize];
	std::cout << "Enter array elements: " << std::endl;

	for (auto i = 0; i < arraySize; ++i) {
		std::cin >> arr[i];
	}

	std::cout << "ARRAY ELEMENTS" << std::endl;
	printArray(arr, arraySize);

	std::cout << std::endl << "#1. GET MINIMAL EVEN (ODD) ELEMENT" << std::endl;
	ArrayMath::minEvenElement(arr, arraySize);

	std::cout << std::endl << "#2. SUM OF NUMBERS OF MINIMUM AND MAXIMUM ELEMENTS" << std::endl;
	auto sum = ArrayMath::getMinAndMaxSumNuber(arr, arraySize);
	std::cout << "Sum: " << sum << std::endl;

	std::cout << std::endl << "#3. PRODUCT OF ELEMENTS WITH ODD INDEXES" << std::endl;
	auto product = ArrayMath::getOddElementsProduct(arr, arraySize);
	std::cout << "Product: " << product << std::endl;

	std::cout << std::endl << "#4. SWAP 2 ELEMENTS" << std::endl;
	std::cout << "ENTER INDEXES TO SWAP: ";

	size_t i = 0, j = 0;
	std::cin >> i >> j;

	if (i == j) {
		std::cout << "You enter same i and j" << std::endl;
		return;
	}
	if (!indexIsCorrect(i, arraySize)) {
		std::cout << "You enter wrong value of i" << std::endl;
		return;
	}
	if (!indexIsCorrect(j, arraySize)) {
		std::cout << "You enter wrong value of j" << std::endl;
		return;
	}

	ArrayMath::simpleSwap(arr, i, j);
	std::cout << "#4.1. classic swap:" << std::endl;
	printArray(arr, arraySize);

	ArrayMath::smartSwap(arr, i, j);
	std::cout << "#4.2. smart (xor) swap:" << std::endl;
	printArray(arr, arraySize);
}

int main() {
	showVectorOperations();
	showArrayOperations();

	return 0;
}