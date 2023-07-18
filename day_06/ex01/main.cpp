#include "iostream"
#include "Serializer.hpp"

void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";

	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";

	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest ex013 started\t====>\n\033[0;37m";

	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	Data a;
	a.a = 1;
	a.b = 2;
	a.c = 3;

	uintptr_t p = Serializer::serialize(&a);
	int *x = reinterpret_cast<int*>(p);
	std::cout << *x << "\n";
	x++;
	std::cout << *x << "\n";
	x++;
	std::cout << *x << "\n";
	return (0);
}
