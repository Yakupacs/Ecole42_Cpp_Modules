#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called!!" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignment operator called." << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	*(this->brain) = *(copy.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!!" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Miyav!" << std::endl;
}
