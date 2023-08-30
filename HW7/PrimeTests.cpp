// PrimeTests.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "PrimeTests.h"


// Пример экспортированной переменной
PRIMETESTS_API int nPrimeTests=0;

// Пример экспортированной функции.
PRIMETESTS_API int fnPrimeTests(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CPrimeTests::CPrimeTests()
{
    return;
}

bool CPrimeTests::divisorIterationTest(uint64_t number)
{
	uint64_t root = sqrt(number);
	for (uint64_t i = 2; i <= root; i++) {

		if ((uint64_t)(number % i) == 0) {
			return false;
		}
	}
	return true;
}

bool CPrimeTests::pFarmTest(uint64_t number, uint64_t accuracy) {
	/*
	
	accuracy - precision to reduce the chance of error
	
	*/
	std::uniform_int_distribution<> die( 2, number );

	std::vector<uint64_t> values{};
	uint64_t temp{};

	while (values.size() < accuracy) {
		temp = die(this->mersenne);

		if (this->gcd(number, temp) != 1) {
			continue;
		}
		values.push_back(temp);
	}

	for (auto i = 0; i < accuracy; ++i) {
		if (this->fastModulePow(values[i], number - 1, number) != 1) {
			return false;
		}
	}

	std::cout << "Numer " << number << " is prime with probability " << 1 - (1 / pow(2, accuracy)) << std::endl;

	return true;
}

bool CPrimeTests::pMillerRabinTest(uint64_t number, uint64_t accuracy) {
	/*

	accuracy - precision to reduce the chance of error

	*/

	if (number == 2 || number == 3) {
		return true;
	}

	if (number == 1 || number % 2 == 0) {
		return false;
	}

	uint64_t t{ number - 1 };
	uint64_t s{ 0 };

	while (t % 2 == 0) {
		t /= 2;
		s += 1;
	}

	std::uniform_int_distribution<> die(2, number - 2);

	for (auto i = 0; i < accuracy; ++i) {
		uint64_t a = die(this->mersenne);

		uint64_t x = this->fastModulePow(a, t, number);

		if (x == 1 || x == number - 1) {
			continue;
		}

		for (auto j = 0; j < s - 1; ++j) {
			x = this->fastModulePow(x, 2, number);

			if (x == 1) {
				return false;
			}

			if (x == number - 1) {
				break;
			}
		}

		if (x != number - 1) {
			return false;
		}
	}

	std::cout << "Numer " << number << " is prime with probability " << 1 - pow(4, -1 * accuracy) << std::endl;

	return true;
}

uint64_t CPrimeTests::gcd(uint64_t a, uint64_t b) {
	return b ? this->gcd(b, a % b) : a;
}

uint64_t CPrimeTests::fastModulePow(uint64_t base, uint64_t degree, uint64_t mod) {
	/*
	
	result = base ^ degree mod (mod)

	*/
	uint64_t result{ 1 };
	uint64_t temp{ base };

	for (uint64_t i = degree; i > 0; i >>= 1) {
		if (i & 0x1 == 1) {
			result = (result * temp) % mod;
		}
		temp *= temp;
		temp %= mod;
	}

	return result;
}
