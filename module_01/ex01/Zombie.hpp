#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"

class Zombie{
	private:
		std::string name;
	public:
		void	announce(void);
		void	set_value(std::string value);
		Zombie(){};
		Zombie(std::string str);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif