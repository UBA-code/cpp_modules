#include "Character.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
			this->slots[i] = 0;
	// std::cout << "Character default constructor called\n";
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
			this->slots[i] = 0;
	// std::cout << "Character constructor called\n";
}

Character::Character(const Character& obj)
{
	// std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
			this->slots[i] = 0;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	// std::cout << "Character copy assigment called\n";
	if (this != &obj)
	{
		this->name = obj.name;
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

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->slots[i])
			delete this->slots[i];
	// std::cout << "Character destructor called\n";
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = m;
			return ;
		}
	}
	if (i == 4)
		std::cerr << "full inventory\n";
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return (std::cerr << "out of range\n", (void)0);
	if (!this->slots[idx])
		return (std::cerr << "empty place\n", (void)0);
	this->slots[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->slots[idx])
		this->slots[idx]->use(target);
	else
		std::cerr << "empty place\n";
}

AMateria* Character::getMateriaFromInventory(int idx)
{
	return (this->slots[idx]);
}

