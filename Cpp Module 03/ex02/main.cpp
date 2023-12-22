#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap s("Soldier1");
	s.attack("enemy1");
	s.takeDamage(70);
	s.beRepaired(30);
	s.guardGate();
	FragTrap f("Soldier2");
	f.attack("enemy2");
	f.takeDamage(15);
	f.beRepaired(10);
	f.highFivesGuys();
	return (0);
}