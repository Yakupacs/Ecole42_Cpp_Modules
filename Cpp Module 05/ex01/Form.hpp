#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int gradeSign;
		const int gradeExecute;
	public:
		Form();
		~Form();
		Form(const std::string name, const int gradeSign, const int gradeExecute);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		const std::string getName() const;
		bool getSign() const;
		const int getGradeSign() const;
		const int getGradeExecute() const;

		void beSigned(const Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif