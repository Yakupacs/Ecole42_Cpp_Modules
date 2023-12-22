#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called!!" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignment operator called!" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	*(this->brain) = *(copy.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!!" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Hav Hav!" << std::endl;
}
