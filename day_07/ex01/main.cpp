#include "iostream"
#include "iter.hpp"


void func (std::string &s)
{
	s[0] = 'X';
}

void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	std::string arr[3] = {"Hello", "World", "UBA"};

	iter(arr, 3, func);
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << "\n";
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void func2(int& i)
{
	i = 1337;
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	int arr[3] = {0, 1, 2};

	iter(arr, 3, func2);
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << "\n";
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void func3(bool &b)
{
	b = 1;
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	bool arr[3] = {0, 1, 0};

	iter(arr, 3, func3);
	for (int i = 0; i < 3; i++)
		std::cout << arr[i] << "\n";
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	test1();
	test2();
	test3();
	return (0);
}
