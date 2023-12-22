#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called." << std::endl;
	this->name = "ClapTrap";
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called." << std::endl;
	this->name = name;
	this->attackDamage = 0;
	this->hitPoints = 10;
	this->energyPoints = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &element)
{
	std::cout << "ClapTrap copy assignment called." << std::endl;
	this->hitPoints = element.hitPoints;
	this->energyPoints = element.energyPoints;
	this->name = element.name;
	this->attackDamage = element.attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap: Not enough energy point." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " took " << amount << " damage." << std::endl;
		this->hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " points." << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap: Not enought energy point." << std::endl;
}