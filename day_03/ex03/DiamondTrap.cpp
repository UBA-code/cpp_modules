#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called\n";
	this->name = "default";
	this->EnergyPoint = 30;
}

DiamondTrap::DiamondTrap(const std::string& name)
{
	std::cout << "DiamondTrap constructor called\n";
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->EnergyPoint = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(const std::string& name)
{
	ScavTrap::attack(name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << " and ClapTrap name is "
	<< ClapTrap::name << " !!" << std::endl;
}
