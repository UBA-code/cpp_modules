#include  "Animal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"

int main()
{
	// Animal* a = new Animal(); // ! Error you can't create object from abstract class
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	return 0;
}