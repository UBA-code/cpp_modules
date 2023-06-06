#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = 0;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->slots[i])
			{
				delete this->slots[i];
				this->slots[i] = 0;
			}
			if (obj.slots[i])
				this->slots[i] = obj.slots[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* obj)
{
	int i;
	for (i = 0; i < 4; i++)
		if  (!this->slots[i])
		{
			this->slots[i] = obj;
			break;
		}
	if (i == 4)
		std::cout << "full slots !!\n";
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
	// std::cout << "MateriaSource destructor called\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria*	tmp = 0;
	std::string	t = type;
	t[0] = tolower(t[0]);
	for (int i = 0; i < 4; i++)
		if (this->slots[i] && this->slots[i]->getType() == t)
			tmp = this->slots[i];
	if (tmp && (t == "ice" || t == "cure"))
		return (tmp->clone());
	std::cout << "Unknown\n";
	return (0);
}
