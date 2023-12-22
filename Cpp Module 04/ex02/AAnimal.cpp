#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called!!" << std::endl;
	this->type = "Default";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal constructor called!!" << std::endl;
	this->type = type;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal assignment operator called." << std::endl;
	this->type = copy.type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!!" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound!" << std::endl;
}