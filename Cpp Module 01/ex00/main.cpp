#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main()
{
	Zombie *zombie = newZombie("Zoo");
	Zombie *zombie2 = newZombie("Phoo");

	zombie->announce();
	zombie2->announce();

	delete zombie;
	delete zombie2;

	randomChump("Random");
	return (0);
}