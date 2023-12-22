#include "ClapTrap.hpp"

int main()
{
    ClapTrap soldier("Soldier1");
	
	soldier.attack("Enemy1");
	soldier.beRepaired(30);
	soldier.takeDamage(150);
}