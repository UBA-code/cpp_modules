#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(std::string type) : Animal("Dog")
{
	(void)type;
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog copy constructor called\n";
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assigment operator called\n";
	Animal::operator=(obj);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->type << " Say 'HOUV HOUV'\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}
