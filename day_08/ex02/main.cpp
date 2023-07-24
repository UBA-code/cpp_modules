#include "iostream"
#include "Span.hpp"
#include <vector>

void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	try {
		Span o;

		srand((unsigned)time(0));
		for (int i = 0; i < 10; i++)
			o.addNumber(rand() % 100);
		o.print();
		std::cout << "shortest distance: " << o.shortestSpan() << "\n";
		std::cout << "longest distance: " << o.longestSpan() << "\n";
	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	try {
		Span o;
		std::vector<int> container;

		srand((unsigned)time(0));
		for (int i = 0; i < 12000; i++)
			container.push_back(rand() % 12000);
		o.addArray(container);
		o.print();
		std::cout << "shortest distance: " << o.shortestSpan() << "\n";
		std::cout << "longest distance: " << o.longestSpan() << "\n";
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
		Span o;
	
		o.print();
		std::cout << "shortest distance: " << o.shortestSpan() << "\n";
		std::cout << "longest distance: " << o.longestSpan() << "\n";
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

/*
* How srand() and rand() are related to each other?
* - srand() sets the seed which is used by rand to generate “random” numbers. If you don’t call srand before your first call to rand, it’s as if you had called srand(1) to set the seed to one. 
*   In short, srand() — Set Seed for rand() Function. 
*/