#include "iostream"
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	std::vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	try {
		easyfind(v, 3);
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
	std::list<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	try {
		easyfind(v, 0);
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
	std::deque<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	try {
		easyfind(v, -15);
	}
	catch (std::exception &err)
	{
		std::cerr << err.what();
	}
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main()
{
	test1();
	test2();
	test3();
	return (0);
}