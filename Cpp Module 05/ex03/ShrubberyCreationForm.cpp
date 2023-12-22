#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return *this;
}
void ShrubberyCreationForm::beSigned(Bureaucrat const &b)
{
	AForm::beSigned(b);
}
void ShrubberyCreationForm::execute(Bureaucrat const &e)
{
	if (e.getGrade() > this->gradeExecute)
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file(this->target + "_shrubbery", std::ios::trunc);
		file << "\n\
   .------.\n\
  /        \\\n\
 |  O    O  |\n\
 |   (_)    |\n\
 |  \\___/  |\n\
  \\_______/\n\
				 " << std::endl;
		file.close();
	}
}