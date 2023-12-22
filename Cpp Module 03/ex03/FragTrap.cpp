#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called." << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << ": High Five!" << std::endl;
}