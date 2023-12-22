#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int randomNumber = rand() % 3;
	if (randomNumber == 0)
		return new A();
	else if (randomNumber == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer object is of type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer object is of type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer object is of type C" << std::endl;
    else
        std::cout << "An error was found!" << std::endl;
}

void identify(Base& p)
{
    char type = 'X';
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        type = 'A';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        type = 'B';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        type = 'C';
    }
    catch(const std::exception& e)
    {
    }
    if (type != 'X')
        std::cout << "Reference object type: " << type << std::endl;
    else
        std::cout << "Reference object type not identified." << std::endl; 
}

int main()
{
	srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
}