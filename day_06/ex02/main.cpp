#include "iostream"
#include "Base.hpp"
#include "One.hpp"
#include "Two.hpp"
#include "Three.hpp"
#include <cstdlib>


Base* generate(void)
{
	int	ran = rand();
	if (ran % 3 == 0)
		return (new One());
	else if (ran % 3 == 1)
		return (new Two());
	else if (ran % 3 == 2)
		return (new Three());
	return (0);
}

void identify(Base* p)
{
	Base* tmp;
	tmp = dynamic_cast<One*>(p);
	if (tmp)
		std::cout << "One\n";
	tmp = dynamic_cast<Two*>(p);
	if (tmp)
		std::cout << "Two\n";
	tmp = dynamic_cast<Three*>(p);
	if (tmp)
		std::cout << "Three\n";
}

void identify(Base& p)
{
	try {
		dynamic_cast<One&>(p);
		std::cout << "One\n";
	}
	catch (std::exception &err){}
	try {
		dynamic_cast<Two&>(p);
		std::cout << "Two\n";
	}
	catch (std::exception &err){}
	try {
		dynamic_cast<Three&>(p);
		std::cout << "Three\n";
	}
	catch (std::exception &err){}
}

void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	Base* obj = new One();

	identify(obj);
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	Base* obj = new Three();

	identify(obj);
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	Base* obj = new Two();

	identify(*obj);
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	test1();
	test2();
	test3();
	return (0);
}
