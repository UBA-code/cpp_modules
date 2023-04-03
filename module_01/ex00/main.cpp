#include "iostream"
#include "Zombie.hpp"

int main()
{
	{
		Zombie z = newZombie("Yassine");
		z.announce();
		randomChump("UBA");
	}
	std::cout << "by\n";
	return (0);
}
