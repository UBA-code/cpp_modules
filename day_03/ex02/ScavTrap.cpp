#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default Constructor called" << std::endl;
	this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy Constructor called" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	ClapTrap::operator=(obj);
	std::cout << "ScavTrap Copy Assigment Operator called" << std::endl;
	return (*this);
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap Attacking: ";
	ClapTrap::attack(target);
}

void ScavTrap::guardGate()
{
	std::cout << this->name << " ScavTrap is now in Gate keeper mode" << std::endl;
}
