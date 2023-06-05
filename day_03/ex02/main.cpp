#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap scav("Yassine");

	scav.attack("staff");
	scav.attack("staff");
	scav.beRepaired(100);
	scav.takeDamage(100);
	return (0);
}
