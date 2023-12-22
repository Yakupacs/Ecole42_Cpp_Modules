#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form f("İşyeri açma formu", 5, 140);
		Form f2("İşyeri açma formu 2", 5, 140);
		Bureaucrat br("Yorgun", 1);
		Bureaucrat br2("Yorgun", 141);
		std::cout << f << std::endl;
		f.beSigned(br);
		std::cout << f << std::endl;
		f2.beSigned(br2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("İşyeri açma formu", 5, 140);
		Bureaucrat br("Yorgun", 1);
		std::cout << f << std::endl;
		f.beSigned(br);
		std::cout << f << std::endl;
		f.beSigned(br);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}