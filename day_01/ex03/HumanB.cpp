#include "HumanB.hpp"

void HumanB::attack()
{
	std::string sla7 = this->weapon ? this->weapon->getType() : "walo";
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

HumanB::HumanB(std::string str, Weapon &sla7)
{
	this->weapon = &sla7;
	this->name = str;
};
