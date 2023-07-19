#include "iostream"
#include "Array.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Array<std::string> l(5);
		std::string s = "hello";
		l.set_value(s);
		for (size_t i = 0; i < l.size(); i++)
			std::cout << l[i] << "\n";
	}
	catch (std::exception &err)
	{
		std::cerr << err.what();
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Array<int> l(5);
		int			num = 1337;
		l.set_value(num);
		for (size_t i = 0; i < l.size(); i++)
			std::cout << l[i] << "\n";
	}
	catch (std::exception &err)
	{
		std::cerr << err.what();
	}
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	try {
		Array<char> l(5);
		char		num = 'X';
		l.set_value(num);
		std::cout << l[-10] << "\n";
	}
	catch (std::exception &err)
	{
		std::cerr << err.what();
	}
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	test1();
	test2();
	test3();
	return (0);
}
