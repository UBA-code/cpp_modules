#pragma once
#include "iostream"
#include "cstring"
#include <float.h>
#include <iomanip>
#include <limits.h>
#include <cstdlib>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& obj);
		ScalarConverter& operator=(ScalarConverter& obj);
		~ScalarConverter();
		static void	convert(std::string s);
};
