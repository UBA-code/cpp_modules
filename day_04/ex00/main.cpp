#include  "Animal.hpp"
#include  "WrongAnimal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"
#include  "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	// WrongAnimal*	animal = new WrongAnimal();
	// WrongAnimal*	cat = new WrongCat();

	// animal->makeSound();
	// cat->makeSound();
	// delete animal;
	// delete cat;
	return 0;
}
