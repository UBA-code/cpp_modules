#include "Weapon.hpp"

const	std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

Weapon::Weapon(std::string str)
{
	this->setType(str);
};

Weapon::Weapon()
{
	this->type = "default";
};

Weapon::~Weapon()
{
	std::cout << "destructor called" << std::endl;
};
