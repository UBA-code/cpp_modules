#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "default";
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& name)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	ClapTrap::operator=(obj);
	std::cout << "FragTrap Copy Assigment Operator called" << std::endl;
	return (*this);
};

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap Attacking: ";
	ClapTrap::attack(target);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "highFivesGuy" << std::endl;
}
