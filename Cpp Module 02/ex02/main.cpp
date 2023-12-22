#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(Fixed(5.05f) * Fixed(2));
	Fixed c(21);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	return 0;
}