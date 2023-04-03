#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
	this->name			= "undefined";
	this->HitPoint		= 10;
	this->EnergyPoint	= 10;
	this->AttackDamage	= 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->name	= name;
	this->HitPoint		= 10;
	this->EnergyPoint	= 10;
	this->AttackDamage	= 10;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy Assigment Operator called" << std::endl;
	if (this != &obj)
	{
		this->name			= obj.name;
		this->HitPoint		= obj.HitPoint;
		this->EnergyPoint	= obj.EnergyPoint;
		this->AttackDamage	= obj.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoint > 0)
	{
		std::cout << name << " attacks " << target <<  "," << " causing "
		<< AttackDamage << " points of damage!" << std::endl;
		(this->EnergyPoint)--;
	}
	else
		std::cout << "out of energy point's" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoint > 0)
	{
		std::cout << name << " takes " << amount << " damage" << std::endl;
		EnergyPoint--; //! this line need check
	}
	else
		std::cout << name << " is out of energy" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoint > 0)
	{
		this->HitPoint += amount;
		(this->EnergyPoint)--;
	}
	else
		std::cout << "out of energy points" << std::endl;
}
