#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual void makeSound() const = 0;
		virtual ~Animal();
		std::string getType() const;
};
#endif