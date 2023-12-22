#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void my_little_farm(int size)
{
	const AAnimal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	for (int i = 0; i < size; i++)
		delete animals[i];
}

int main(void)
{
	my_little_farm(10);
	return (0);
}