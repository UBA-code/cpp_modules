#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);
		void makeSound() const;
		~WrongCat();
};

#endif