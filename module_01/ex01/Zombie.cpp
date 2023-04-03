#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_value(std::string value)
{
	this->name = value;
}

Zombie::Zombie(std::string str)
{
	this->name = str;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": distractor called\n";
}