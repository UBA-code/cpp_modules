#include "iostream"
#include "PmergeMe.hpp"

void test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";

	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";

	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";

	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main(int ac, char **av)
{
	(void)ac;
	pMergeMe(av + 1);
	//  6 8 9 2 4 7 3 1 5 8
	// std::vector<int>::iterator l = vect.begin();
	// for (; l != vect.end();l++)
	// 	std::cout << *l << ", ";
	// std::cout << "\n";
	// test1();
	// test2();
	// test3();
	return (0);
}
