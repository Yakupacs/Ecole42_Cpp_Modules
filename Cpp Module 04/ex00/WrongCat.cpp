#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignment operator called." << std::endl;
	this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "Miyav!" << std::endl;
}