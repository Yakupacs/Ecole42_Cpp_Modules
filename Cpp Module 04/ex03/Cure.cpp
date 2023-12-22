#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
}

Cure &Cure::operator=(Cure const &copy)
{
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}