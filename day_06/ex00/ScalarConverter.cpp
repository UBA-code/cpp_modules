#include "ScalarConverter.hpp"
#include "converter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& obj){
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& obj)
{
	(void)obj;
    return (*this);
}

ScalarConverter::~ScalarConverter(){};

void	ScalarConverter::convert(std::string s)
{
	converter o;

	o.check_type(s);
	o.print_result();
}
