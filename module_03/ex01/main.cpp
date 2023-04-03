#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav;

	scav.attack("staff");
	scav.attack("staff");
	scav.getValues();
	scav.beRepaired(100);
	scav.takeDamage(100);
	scav.getValues();
	return (0);
}
