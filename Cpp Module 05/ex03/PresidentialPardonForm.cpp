#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	*this = copy;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return *this;
}
void PresidentialPardonForm::beSigned(Bureaucrat const &b)
{
	AForm::beSigned(b);
}
void PresidentialPardonForm::execute(Bureaucrat const &e)
{
	if (e.getGrade() > this->gradeExecute)
		throw AForm::GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox!" << std::endl;
}