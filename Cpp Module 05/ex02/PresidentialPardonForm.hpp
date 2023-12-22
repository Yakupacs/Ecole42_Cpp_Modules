#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor);
};

#endif