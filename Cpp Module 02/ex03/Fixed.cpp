#include "Fixed.hpp"

Fixed::Fixed()
{
	content = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int intVal)
{
	content = intVal * pow(2, bits);
}

Fixed::Fixed(const float floatVal)
{
	content = roundf(floatVal * pow(2, bits));
}

Fixed &Fixed::operator=(const Fixed &number)
{
	this->content = number.content;
	return (*this);
}

int Fixed::toInt() const
{
	return (content / pow(2, bits));
}

float Fixed::toFloat() const
{
	return (float(content) / pow(2, bits));
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed sum(this->toFloat() + other.toFloat());
	return (sum);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed sub(this->toFloat() - other.toFloat());
	return (sub);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed mul(this->toFloat() * other.toFloat());
	return (mul);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed div(this->toFloat() / other.toFloat());
	return (div);
}

Fixed Fixed::operator++(int)
{
	Fixed rtn = *this;
	this->content++;
	return (rtn);
}

Fixed &Fixed::operator++()
{
	this->content++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed rtn = *this;
	this->content--;
	return (rtn);
}

Fixed &Fixed::operator--()
{
	this->content--;
	return (*this);
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->content > number.content);
}

bool Fixed::operator<(const Fixed &number)
{
	return (this->content < number.content);
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->content <= number.content);
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->content >= number.content);
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->content == number.content);
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->content != number.content);
}

Fixed &Fixed::min(Fixed &s1, Fixed &s2)
{
	if (s1.content > s2.content)
		return (s2);
	else
		return (s1);
}

Fixed &Fixed::max(Fixed &s1, Fixed &s2)
{
	if (s1.content < s2.content)
		return (s2);
	else
		return (s1);
}

const Fixed &Fixed::min(const Fixed &s1, const Fixed &s2)
{
	if (s1.content > s2.content)
		return (s2);
	else
		return (s1);	
}

const Fixed &Fixed::max(const Fixed &s1, const Fixed &s2)
{
	if (s1.content < s2.content)
		return (s2);
	else
		return (s1);	
}

int Fixed::getRawBits(void) const
{
	return content;
}

void Fixed::setRawBits(int const raw)
{
	content = raw;
}