#include "Form.hpp"

Form::Form(): name("Form"), gradeSign(150), gradeExecute(150)
{
	this->sign = false;
}
Form::Form(const std::string name, const int gradeSign, const int gradeExecute): name(name), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	this->sign = false;
}
Form::Form(const Form &copy): name(copy.name), gradeSign(copy.gradeSign), gradeExecute(copy.gradeExecute)
{
	*this = copy;
}
Form &Form::operator=(const Form &copy)
{
	this->sign = copy.sign;
	return (*this);
}
Form::~Form()
{
}
const std::string Form::getName() const
{
	return this->name;
}
bool Form::getSign() const
{
	return this->sign;
}
const int Form::getGradeSign() const
{
	return this->gradeSign;
}
const int Form::getGradeExecute() const
{
	return this->gradeExecute;
}
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeSign)
		throw Form::GradeTooHighException();
	if (this->sign == false)
	{
		this->sign = true;
		std::cout << "The form " << this->name << " signed now!" << std::endl;
	}
	else
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because the form already signed before!" << std::endl;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high exception called.";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low exception called.";
}
std::ostream &operator<<(std::ostream &output, const Form &f)
{
	if (f.getSign())
		output << f.getName() << ": The form signed.";
	else
		output << f.getName() << ": The form is not signed!";
	return (output);
}