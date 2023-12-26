#include "PmergeMe.hpp"

/*
make re ; ./PmergeMe $(shuf -i 10-100 -n 30) ;
make re ; ./PmergeMe $(shuf -i 1-100000 -n 3000) ;
*/

int isPositiveNumber(const std::string &s)
{
	if (s.empty())
		return (0);
	for (std::size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (0);
	}
	return (1);
}

int isInputValid(char **argv) {
	for (int i = 1; argv[i]; i++) {
		if (!isPositiveNumber(argv[i]))
			return (0);
	}
	return (1);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe <positive_number_sequence>" << std::endl;
		return 1;
	}
	if (!isInputValid(argv)) {
		std::cout << "Error: invalid input!" << std::endl;
		return 2;
	}
	PmergeMe pmergeMe;
	pmergeMe.readInput(argv);
	pmergeMe.fordJohnsonSortWrapper();
}