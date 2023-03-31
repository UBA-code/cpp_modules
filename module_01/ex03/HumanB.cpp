#include "HumanB.hpp"

void HumanB::attack()
{
	std::string sla7 = "hand";
	if (this->weapon)
		sla7 = this->weapon->getType();
	std::cout << this->name
			  << " attacks with their "
			  << sla7 << std::endl;
}

void HumanB::setWeapon(Weapon &sla7)
{
	this->weapon = &sla7;
}

HumanB::HumanB(std::string str)
{
	this->weapon = 0;
	this->name = str;
};