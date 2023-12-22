#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap soldier("Soldier");
	soldier.attack("Enemy");
	soldier.guardGate();
	soldier.highFivesGuys();
	soldier.takeDamage(5);
	soldier.beRepaired(15);
	soldier.whoAmI();
}