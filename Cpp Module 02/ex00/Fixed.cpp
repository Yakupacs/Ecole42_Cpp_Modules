#include "Fixed.hpp"

Fixed::Fixed()
{
	data = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->data = number.data;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return data;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	data = raw;
}