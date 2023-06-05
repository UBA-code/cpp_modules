#include  "Animal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"

int main()
{
	Animal**	arr = new Animal*[100];
	int			i = 0;
	int			size = 10;

	for (; i < size / 2; i++)
		arr[i] = new Dog();

	for (; i < size; i++)
		arr[i] = new Cat();

	for (i = 0; i < size; i++)
		arr[i]->makeSound();

	for (i = 0; i < size; i++)
		delete arr[i];
	delete []arr;
	return 0;
}
