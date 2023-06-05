#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Youssef");

	scav.attack("staff");
	scav.attack("staff");
	scav.beRepaired(100);
	scav.takeDamage(100);
	return (0);
}
