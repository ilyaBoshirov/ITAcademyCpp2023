#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>


template <typename T>
class VectorAnalyzer {
	std::vector<T> data;

public:

	VectorAnalyzer() {
		this->data = std::vector<T>{};
	};

	VectorAnalyzer(std::vector<T> data) {
		this->data = data;
	};

	void square() {
		std::transform(this->data.cbegin(), this->data.cend(), this->data.cbegin(), this->data.begin(), std::multiplies<T>{});
	};

	void showData() {
		std::cout << "DATA:";

		for (const auto& item : this->data) {
			std::cout << ' ' << item;
		}

		std::cout << std::endl;
	};

	void plus(T value) {
		std::transform(this->data.cbegin(), this->data.cend(), this->data.begin(), std::bind2nd(std::plus<T>(), value));
	};	

	void findIdenticalNeighbors() {
		auto pointer = std::adjacent_find(this->data.cbegin(), this->data.cend());

		if (pointer == this->data.end()) {
			std::cout << "No identical neighbors in your vector" << std::endl;
			return;
		}

		std::cout << "Identical neighbors is (" << *pointer << "; " << *(pointer + 1) << ")" << std::endl;
	}

	void pushBack(T value) {
		this->data.push_back(value);
	}
};
