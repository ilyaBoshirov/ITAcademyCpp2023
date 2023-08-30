// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа PRIMETESTS_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции PRIMETESTS_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef PRIMETESTS_EXPORTS
#define PRIMETESTS_API __declspec(dllexport)
#else
#define PRIMETESTS_API __declspec(dllimport)
#endif

#include <iostream>
#include <random>

// Этот класс экспортирован из библиотеки DLL
// class containing a check for primality
class PRIMETESTS_API CPrimeTests {

	std::mt19937_64 mersenne{ static_cast<std::mt19937_64::result_type>(std::time(nullptr)) };

public:
	CPrimeTests(void);
	
	bool divisorIterationTest(uint64_t number);

	bool pFarmTest(uint64_t number, uint64_t accuracy);  // probabilistic test

	bool pMillerRabinTest(uint64_t number, uint64_t accuracy);  // probabilistic test

	uint64_t gcd(uint64_t a, uint64_t b);  // calculating the greatest common divisor

	uint64_t fastModulePow(uint64_t base, uint64_t degree, uint64_t mod);  // fast exponentiation modulo
};

extern PRIMETESTS_API int nPrimeTests;

PRIMETESTS_API int fnPrimeTests(void);
