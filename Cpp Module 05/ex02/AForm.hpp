#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool sign;
		const int gradeSign;
		const int gradeExecute;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string name, const int gradeSign, const int gradeExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		const std::string getName() const;
		bool getSign() const;
		const int getGradeSign() const;
		const int getGradeExecute() const;

		virtual void beSigned(const Bureaucrat &b) = 0;
		virtual void execute(Bureaucrat const &e) = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const AForm &f);

#endif