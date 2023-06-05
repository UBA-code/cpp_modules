#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const std::string& type);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		virtual ~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};
