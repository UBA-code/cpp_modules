#pragma once
#include "iostream"
#include "cstring"
#include <float.h>
#include <iomanip>
class ScalarConverter {
	private:
		std::string	_s;
		int			type;
		char		c_char;
		int			n_int;
		float		n_float;
		double		n_double;
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& obj);
		ScalarConverter& operator=(ScalarConverter& obj);
		~ScalarConverter();
		class Impossible : public std::exception {
			public:
				const char* what() const throw(){return ("Impossible\n");};
		};
		void	print_result();
		void	convert(std::string s);
		bool	is_char(std::string s);
		bool	is_int(std::string s);
		bool	is_float(std::string s);
		bool	is_double(std::string s);
		int		check_num(std::string s);
		void	check_type(std::string s);
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDoublle();
		void	unvalidPrint();
		void	literals();
};