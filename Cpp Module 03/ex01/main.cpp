#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Soldier");
	scavTrap.attack("Enemy");
	scavTrap.takeDamage(60);
	scavTrap.beRepaired(30);
	scavTrap.takeDamage(30);
	scavTrap.guardGate();
	return 0;
}