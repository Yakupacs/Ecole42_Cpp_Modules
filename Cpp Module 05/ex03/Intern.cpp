#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern &Intern::operator=(const Intern &copy) { return *this;}

const char *Intern::UnknowFormNameException::what() const throw()
{
	return "The form's name is not found.";
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	int i = 0;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	while (i < 3 && name != forms[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << target << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		case 1:
			std::cout << "Intern creates " << target << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		case 2:
			std::cout << "Intern creates " << target << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		default:
			throw UnknowFormNameException();
			break;
	}	
}
