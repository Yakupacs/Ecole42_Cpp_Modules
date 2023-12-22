#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		RobotomyRequestForm robot("yakup");
		ShrubberyCreationForm shrub("a");
		Bureaucrat b("yorgun", 1);
		b.executeForm(robot);
		b.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}