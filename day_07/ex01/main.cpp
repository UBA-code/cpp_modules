#include "iostream"
#include "whatever.hpp"


void	test1()
{
	std::cout << "\033[0;31m<====\ttest 1 started\t====>\n\033[0;37m";
	int	a = 10;
	int b = 48;

	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	swap(a, b);
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";


	// compilation error
	// int	a2 = 10;
	// char b2 = 48;

	// std::cout << "a = " << a2 << "\n";
	// std::cout << "b = " << b2 << "\n";
	// swap(a2, b2);
	// std::cout << "a = " << a2 << "\n";
	// std::cout << "b = " << b2 << "\n";
	std::cout << "\033[0;31m<====\ttest 1 ended\t====>\n\n\033[0;37m";
}

void	test2()
{
	std::cout << " \033[0;32m<====\ttest 2 started\t====>\n\033[0;37m";
	int	a = 1337;
	int b = 42;

	std::cout << "min is: " << min(a, b) << "\n";

	// compilation error
	// int	a2 = 1337;
	// char b2 = 42;

	// std::cout << "min is: " << min(a2, b2) << "\n";
	std::cout << " \033[0;32m<====\ttest 2 ended\t====>\n\n\033[0;37m";
}

void	test3()
{
	std::cout << "\033[0;33m<====\ttest 3 started\t====>\n\033[0;37m";
	int	a = 1337;
	int b = 42;

	std::cout << "max is: " << max(a, b) << "\n";

	// compilation error
	// int	a2 = 1337;
	// char b2 = 42;

	// std::cout << "max is: " << max(a2, b2) << "\n";
	std::cout << "\033[0;33m<====\ttest 3 ended\t====>\n\n\033[0;37m";
}

int main ()
{
	test1();
	test2();
	test3();
	return (0);
}


// int main( void ) {
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }