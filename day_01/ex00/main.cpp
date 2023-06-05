#include "iostream"
#include "Zombie.hpp"

int main()
{
	Zombie *z = newZombie("Yassine");
	z->announce();
	randomChump("UBA");
	delete z;
	return (0);
}
