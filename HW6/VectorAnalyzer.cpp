#include "VectorAnalyzer.h"

//#include <algorithm>
//#include <iostream>
//
//
//template <typename T>
//VectorAnalyzer<T>::VectorAnalyzer() {
//	this->data = std::vector<T>{};
//}
//
//template <typename T>
//VectorAnalyzer<T>::VectorAnalyzer(std::vector<T> data) {
//	this->data = data;
//}
//
//template <typename T>
//void VectorAnalyzer<T>::square() {
//	std::transform(this->data.cbegin(), this->data.cend(), this->data.cbegin(), this->data.begin(), std::multiplies<>{});
//}
//
//template <typename T>
//void VectorAnalyzer<T>::showData() {
//	std::cout << "DATA:";
//
//	for (const auto& item : this->data) {
//		std::cout << ' ' << item;
//	}
//
//	std::cout << std::endl;
//}