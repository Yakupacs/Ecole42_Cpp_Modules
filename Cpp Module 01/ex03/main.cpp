#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon  club = Weapon("Axe");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Knife");
		bob.attack();
	}
	{
		Weapon  club = Weapon("Axe");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Knife");
		jim.attack();
	}
	return 0;
}