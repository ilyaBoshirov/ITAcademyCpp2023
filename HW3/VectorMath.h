#pragma once
#include <iostream>
#include <vector>

typedef std::unique_ptr<std::vector<int>> VectorPtr;

namespace VectorMath {
	void minEvenElement(std::vector<int>* vec);

	uint32_t getMinAndMaxSumNuber(std::vector<int>* vec);

	int getOddElementsProduct(std::vector<int>* vec);

	void simpleSwap(std::vector<int>* vec, int i, int j);

	void smartSwap(std::vector<int>* vec, int i, int j);

	void stdSwap(std::vector<int>* vec, int i, int j);
}
