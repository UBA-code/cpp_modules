#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	type		= -1;
	c_char		= -1;
	n_int		= 0;
	n_float		= 0;
	n_double	= 0;
}

ScalarConverter::ScalarConverter(ScalarConverter& obj){(void)obj;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

ScalarConverter::~ScalarConverter(){};

bool	ScalarConverter::is_char(std::string s)
{
	if (type == -1 && s.length() == 1 && isascii(s[0]) && !std::isdigit(s[0])
		&& s[0] != '+' && s[0] != '-')
	{
		this->type = 0;
		this->c_char = s[0];
		return (1);
	}
	std::cout << "not char\n";
	return 0;
}

bool	ScalarConverter::is_int(std::string s)
{
	if (type == -1 && !ScalarConverter::check_num(s))
		return (0);
	long n = atol(s.c_str());
	if (type == -1 && s.find('.') < s.length())
		return (0);
	if (type == -1 && n > INT_MIN && n < INT_MAX)
	{
		this->type = 1;
		this->n_int = n;
		return (1);
	}
	std::cout << "not int\n";
	return (0);
}

bool	ScalarConverter::is_float(std::string s)
{
	if (type == -1 && (!ScalarConverter::check_num(s) || s.find('f') > s.length()))
		return (0);
	double n = atof(s.c_str());
	if (type == -1 && n > -FLT_MAX && n < FLT_MAX)
	{
		this->type = 2;
		this->n_float = n;
		return (1);
	}
	std::cout << "not float\n";
	return (0);
}

bool	ScalarConverter::is_double(std::string s)
{
	if (type == -1 && !ScalarConverter::check_num(s))
		return (0);
	double n = atof(s.c_str());
	if (type == -1 && n > -DBL_MAX && n < DBL_MAX)
	{
		this->type = 3;
		this->n_double = n;
		return (1);
	}
	std::cout << "not double\n";
	return (0);
}

int	ScalarConverter::check_num(std::string s)
{
	int	sign = 0;
	int	pointCount = 0;
	int	fCount = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (!std::isdigit(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != '.' && s[i] != 'f')
			return (0);
		if (s[i] == '+' || s[i] == '-')
			sign++;
		if (s[i] == '.')
			pointCount++;
		if (s[i] == 'f')
			fCount++;
	}
	if (s.find('.') == s.length() - 1 || s[s.find('.') + 1] == 'f')
		return (0);
	else if (s.find('f') < s.length() && s[s.find('f') - 1] == '.')
		return (0);
	else if ((s.find("+") < s.length() || s.find("-") < s.length())
			&& (s[0] != '+' || s[0] != '-'))
		return (0);
	return (sign > 1 || pointCount > 1  || fCount > 1 ? 0 : 1);
}

void	ScalarConverter::check_type(std::string s)
{
	is_char(s);
	is_int(s);
	is_float(s);
	is_double(s);
	if (type != 0 && this->check_num(s) == 0)
		this->type = -1;
	if (type == -1)
	{
		if (!s.compare("-inff") || !s.compare("+inff") || !s.compare("nan")
			|| !s.compare("nanf") || !s.compare("+inf") || !s.compare("-inf"))
			type = -2;
	}
}

void	ScalarConverter::printChar()
{
	if (std::isprint(static_cast<char>(this->c_char)))
		std::cout << "char: " << static_cast<char>(this->c_char) << "\n";
	else
		std::cout << "char: " << "Not displayable\n";
	std::cout << std::setprecision(1);
    std::cout << "int: " << static_cast<int>(this->c_char) << "\n";
    std::cout << "float: " << static_cast<float>(this->c_char) << "f" << "\n";
    std::cout << "double: " << static_cast<double>(this->c_char) << "\n";
}

void	ScalarConverter::printInt()
{
	if (std::isprint(static_cast<char>(this->n_int)))
		std::cout << "char: " << static_cast<char>(this->n_int) << "\n";
	else
		std::cout << "char: " << "Not displayable\n";
	// std::cout << std::setprecision(1);
    std::cout << "int: " << static_cast<int>(this->n_int) << "\n";
    std::cout << "float: " << static_cast<float>(this->n_int) << "f" << "\n";
    std::cout << "double: " << static_cast<double>(this->n_int) << "\n";
}

void	ScalarConverter::printFloat()
{
	if (std::isprint(static_cast<char>(this->n_float)))
		std::cout << "char: " << static_cast<char>(this->n_float) << "\n";
	else
		std::cout << "char: " << "Not displayable\n";
	// std::cout << std::setprecision(1);
    std::cout << "int: " << static_cast<int>(this->n_float) << "\n";
    std::cout << "float: " << static_cast<float>(this->n_float) << "f" << "\n";
    std::cout << "double: " << static_cast<double>(this->n_float) << "\n";
}

void	ScalarConverter::printDoublle()
{
	if (std::isprint(static_cast<char>(this->n_double)))
		std::cout << "char: " << static_cast<char>(this->n_double) << "\n";
	else
		std::cout << "char: " << "Not displayable\n";
	// std::cout << std::setprecision(1);
    std::cout << "int: " << static_cast<int>(this->n_double) << "\n";
    std::cout << "float: " << static_cast<float>(this->n_double) << "f" << "\n";
    std::cout << "double: " << static_cast<double>(this->n_double) << "\n";
}

void	ScalarConverter::unvalidPrint()
{
	std::cout << "char: " << "impossible\n";
    std::cout << "int: " << "impossible" << "\n";
    std::cout << "float: " << "impossible" << "\n";
    std::cout << "double: " << "impossible" << "\n";
}

void	ScalarConverter::literals()
{
	std::cout << "char: " << "impossible\n";
    std::cout << "int: " << "impossible" << "\n";
    std::cout << "float: " << _s << "\n";
    std::cout << "double: " << _s << "\n";
}

void ScalarConverter::print_result()
{
	if (type == 0)
		printChar();
	else if (type == 1)
		printInt();
	else if (type == 2)
		printFloat();
	else if (type == 3)
		printDoublle();
	else if (type == -1)
		unvalidPrint();
	else if (type == -2)
		literals();
}

void	ScalarConverter::convert(std::string s)
{
	_s = s;
	check_type(s);
	print_result();
}
