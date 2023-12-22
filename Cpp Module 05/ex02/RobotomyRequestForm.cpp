#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return *this;
}
void RobotomyRequestForm::beSigned(Bureaucrat const &b)
{
	AForm::beSigned(b);
}
void RobotomyRequestForm::execute(Bureaucrat const &e)
{
	if (e.getGrade() > this->gradeExecute)
		throw AForm::GradeTooLowException();
	else
	{
		srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Robotomization failed!" << std::endl;
	}
}