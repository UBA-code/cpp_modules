#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap scav1("Yassine");
	DiamondTrap scav2 = scav1;

	scav2.whoAmI();
	// scav.attack("staff");
	// scav.attack("staff");
	// scav.beRepaired(100);
	// scav.takeDamage(100);
	return (0);
}
