#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "iostream"

class Weapon{
	private:
		std::string type;
	public:
		const	std::string& getType();
		void	setType(std::string newType);
	Weapon(){};
	Weapon (std::string str);
};

#endif