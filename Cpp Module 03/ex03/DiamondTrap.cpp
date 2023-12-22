#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called." << std::endl;
	this->name = name;
	energyPoints = ScavTrap::energyPoints;
	hitPoints = FragTrap::hitPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called." << std::endl; 
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap assignment operator called." << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	FragTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << this->name << std::endl;
}