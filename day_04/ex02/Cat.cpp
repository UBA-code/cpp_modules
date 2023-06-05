#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal("Cat")
{
	(void)type;
	this->brain = new Brain();
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat copy constructor called\n";
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
	std::cout << "Cat copy assigment operator called\n";
	Animal::operator=(obj);
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << this->type << " Say 'MEOW MEOW'\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->brain;
}
