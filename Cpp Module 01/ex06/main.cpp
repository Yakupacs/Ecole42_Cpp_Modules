#include "Harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");
	return (0);
}