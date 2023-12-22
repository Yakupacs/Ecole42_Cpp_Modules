#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern intern;
		AForm *form;
		Bureaucrat br("bürokrat", 1);
		form = intern.makeForm("presidential pardon", "Bender");
		form->execute(br);
		form = intern.makeForm("robotomy request", "Bender");
		form->execute(br);
		form = intern.makeForm("kafama göre", "Sender");
		form->execute(br);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}