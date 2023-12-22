#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *inventory[4];
		std::string name;
		int count;
	public:
		Character();
		Character(std::string const &name);
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif