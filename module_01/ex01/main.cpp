#include "iostream"
#include "Zombie.hpp"

void test()
{
	
}

int main()
{
	Zombie *arr = zombieHorde(10, "UBA");
	for (int i = 0; i < 10; i++)
		arr[i].announce();
	std::cout << "by\n";
	delete[] arr;
	return (0);
}
