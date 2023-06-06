#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	slots[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		virtual ~MateriaSource();
		void learnMateria(AMateria* obj);
		AMateria* createMateria(std::string const & type);
};
