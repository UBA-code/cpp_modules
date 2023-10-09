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


// ? static-cast 
//		* compile-time cast
//		* allow cast from basic type like from int to float or from float to int
//		* allow cast from pointer to void* and vice versa
//		* allow cast from pointer to base class to pointer to derived class and vice versa
//		* show compile-time error in case of protected or private inheritance
// ? dynamic-cast 
//		* run-time cast
//		* used specialy in downcasting (from base class to derived class)
//		* thow exception in case of reference

// * In summary, static_cast is used for safe and well-defined type conversions,
// * dynamic_cast is used for type-safe downcasting in polymorphic hierarchies,
// * and reinterpret_cast is used for low-level type-unsafe conversions