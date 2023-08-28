#include "MyException.h"
#include <string>


MyException::MyException(): std::exception() {}

MyException::MyException(const std::string& message):std::exception(message.c_str()) {}
