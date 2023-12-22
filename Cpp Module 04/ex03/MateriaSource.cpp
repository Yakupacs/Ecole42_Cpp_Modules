#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	this->count = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->materia[i];
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	*this = copy;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = copy.materia[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->count < 4)
	{
		this->materia[this->count] = m;
		this->count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	}
	std::cout << "Sorry! Materia is not found." << std::endl;
	return (NULL);
}