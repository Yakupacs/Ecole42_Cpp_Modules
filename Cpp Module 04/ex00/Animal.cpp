#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called!!" << std::endl;
	this->type = "Default";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called!!" << std::endl;
	this->type = type;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignment operator called." << std::endl;
	this->type = copy.type;
	return (*this);
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!!" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound!" << std::endl;
}