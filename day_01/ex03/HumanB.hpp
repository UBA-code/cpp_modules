#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "iostream"
#include "Weapon.hpp"

class HumanB{
	private:
		Weapon		*weapon;
		std::string	name;
	public:
		void	attack();
		void	setWeapon(Weapon& sla7);
	HumanB(std::string str);
	HumanB(std::string str, Weapon &sla7);
	HumanB();
};

#endif