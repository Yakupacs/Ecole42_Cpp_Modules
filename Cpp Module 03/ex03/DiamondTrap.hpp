#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& copy);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& copy);
		void whoAmI();
		void attack(const std::string &target);
};

#endif