#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "default";
}

Brain::Brain(std::string arr[100])
{
	std::cout << "Brain constructor called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = arr[i];
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor called\n";
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain copy assigment operator called\n";
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}
