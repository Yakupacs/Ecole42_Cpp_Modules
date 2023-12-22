#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		AForm *makeForm(const std::string &name, const std::string &target);
		class UnknowFormNameException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif