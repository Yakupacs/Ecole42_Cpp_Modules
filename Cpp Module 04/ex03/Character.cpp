#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->count = 0;
	this->name = "Default";
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character::Character(std::string const &name)
{
	this->name = name;
	this->count = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character &Character::operator=(const Character &copy)
{
	this->count = copy.count;
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = copy.inventory[i];
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete (this->inventory[i]);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->count < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
				this->inventory[this->count] = m;
		}
		this->count++;
	}
	else
		std::cout << "Sorry! The inventory is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->inventory[idx] = NULL;
		this->count--;
	}
	else
		std::cout << "Sorry! The slot is invalid." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx]->use(target);
	else
		std::cout << "Sorry! The slot is invalid." << std::endl;
}