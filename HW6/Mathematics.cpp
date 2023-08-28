#include "Mathematics.h"
#include "MyException.h"
#include <math.h>


uint32_t Mathematics::factorial(int n) {
	if (n < 0) {
		throw MyException("It is not possible to calculate the factorial of a negative value");
	}
	
	if (n == 0) {
		return 1;
	}

	return n * this->factorial(n - 1);
}

double Mathematics::hyperbolicCotangent(double x) {
	if (x == 0) {
		throw MyException("The value 0 is not contained in the scope of the function");
	}

	double constantValue = std::exp(2 * x);

	return (constantValue + 1) / (constantValue - 1);
}

uint32_t Mathematics::binomialCoefficient(int n, int m) {
	if (n < 0) {
		throw MyException("The value n can't be negative");
	}
	if (m < 0) {
		throw MyException("The value m can't be negative");
	}
	if (n - m < 0) {
		throw MyException("The value m can't be greater then n");
	}
	return this->factorial(n) / (this->factorial(n - m) * this->factorial(m));
}
