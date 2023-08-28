#pragma once
#include <iostream>
#include <string>


class MyException: public std::exception {

public:
	MyException();
	MyException(const std::string& message);
};

