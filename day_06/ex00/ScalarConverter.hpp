#pragma once
#include "iostream"
#include "cstring"
#include <float.h>
#include <iomanip>
class ScalarConverter {
	// private:
	// 	std::string	_s;
	// 	int			type;
	// 	char		c_char;
	// 	int			n_int;
	// 	float		n_float;
	// 	double		n_double;
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& obj);
		ScalarConverter& operator=(ScalarConverter& obj);
		~ScalarConverter();
		static void	convert(std::string s);
		static void	printChar(std::string s);
		static void	printInt(std::string s);
		static void	printFloat(std::string s);
		static void	printDouble(std::string s);
		// void	print_result();
		// bool	is_char(std::string s);
		// bool	is_int(std::string s);
		// bool	is_float(std::string s);
		// bool	is_double(std::string s);
		// int		check_num(std::string s);
		// void	check_type(std::string s);
		// void	unvalidPrint();
		// void	literals();
};