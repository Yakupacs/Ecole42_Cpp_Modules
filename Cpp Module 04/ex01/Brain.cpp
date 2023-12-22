#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignment operator called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}