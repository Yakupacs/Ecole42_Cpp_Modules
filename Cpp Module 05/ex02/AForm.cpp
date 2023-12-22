#include "AForm.hpp"

AForm::AForm(): name("AForm"), gradeSign(150), gradeExecute(150)
{
	this->sign = false;
}
AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute): name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	this->sign = false;
}
AForm::AForm(const AForm &copy): name(copy.name), gradeSign(copy.gradeSign), gradeExecute(copy.gradeExecute)
{
	*this = copy;
}
AForm &AForm::operator=(const AForm &copy)
{
	this->sign = copy.sign;
	return (*this);
}
AForm::~AForm()
{
}
const std::string AForm::getName() const
{
	return this->name;
}
bool AForm::getSign() const
{
	return this->sign;
}
const int AForm::getGradeSign() const
{
	return this->gradeSign;
}
const int AForm::getGradeExecute() const
{
	return this->gradeExecute;
}
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeSign)
		throw AForm::GradeTooHighException();
	if (this->sign == false)
	{
		this->sign = true;
		std::cout << "The form " << this->name << " signed now!" << std::endl;
	}
	else
		throw AForm::AlreadySignedException();
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high exception called.";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low exception called.";
}
const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form already signed!";
}
std::ostream &operator<<(std::ostream &output, const AForm &f)
{
	if (f.getSign())
		output << f.getName() << ": The AForm signed.";
	else
		output << f.getName() << ": The AForm is not signed!";
	return (output);
}