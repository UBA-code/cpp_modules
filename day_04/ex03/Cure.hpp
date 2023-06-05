#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const std::string& type);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		virtual ~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};
