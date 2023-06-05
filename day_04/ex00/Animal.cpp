#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal copy constructor called\n";
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
	std::cout << "Animal copy Assigment operator called\n";
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destrutor called\n";
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << this->type << " Is Silence\n";
}
