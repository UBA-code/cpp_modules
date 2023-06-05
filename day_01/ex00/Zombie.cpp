#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": destructor called\n";
}

Zombie::Zombie()
{
	std::cout << this->name << ": constructor called\n";
	this->name = "default";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
