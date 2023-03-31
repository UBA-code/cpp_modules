#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Zombie.hpp"
#include "iostream"

class Zombie{
	private:
		std::string name;
	public:
		void	announce(void);
		Zombie(std::string str);
		~Zombie();
};

void	randomChump( std::string name );
Zombie	newZombie( std::string name );

#endif