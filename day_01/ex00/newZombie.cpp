#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *littleZombie = new Zombie(name);
	return (littleZombie);
}
