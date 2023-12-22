#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default")
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	this->grade = 150;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		std::cout << name << " bureaucrat hired with " << grade << " grade!" << std::endl;
		this->grade = grade;
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = copy;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	this->grade = copy.grade;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "The bureaucrat " << this->name << " was fired!" << std::endl;
}
const std::string Bureaucrat::getName() const
{
	return this->name;
}
int Bureaucrat::getGrade() const
{
	return this->grade;
}
std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade() << "."; 
	return (output);
}
void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooLowException();
	else
		this->grade--;
}
void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooHighException();
	else
		this->grade++;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high exception called.";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low exception called.";
}
void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->name << " could not sign " << f.getName() << " beacuse " << e.what() << std::endl;
	}
}