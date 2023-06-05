#include "HumanA.hpp"

void HumanA::attack()
{
	if (this->weapon.getType().empty())
	{
		std::cerr << "Error\nthere's no weapon" << std::endl;
		return;
	}
	std::cout << this->name
				<< " attacks with their "
				<< this->weapon.getType() << std::endl;
}


HumanA::HumanA(std::string str, Weapon &sla7): weapon(sla7), name(str){}