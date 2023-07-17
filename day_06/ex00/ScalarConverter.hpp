#pragma once
#include "iostream"
#include "cstring"
#include <float.h>
#include <iomanip>
#include <limits.h>
#include <cstdlib>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& obj);
		ScalarConverter& operator=(ScalarConverter& obj);
		~ScalarConverter();
	public:
		static void	convert(std::string s);
};
