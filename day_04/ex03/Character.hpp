#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		AMateria	*slots[4];
		std::string	name;
	public:
		Character();
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		virtual ~Character();
};
