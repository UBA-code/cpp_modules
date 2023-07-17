#pragma once
#include "ScalarConverter.hpp"

class converter{
		std::string	_s;
		int			type;
		char		c_char;
		int			n_int;
		float		n_float;
		double		n_double;
	public:
		converter();
		converter(converter& obj);
		converter& operator=(converter& obj);
		~converter();
		void	print_result();
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
