#include "easyfind.hpp"

void print(int i) {
	std::cout << i << std::endl;
}

int main(void) {
	// VECTOR
	std::vector<int> vector;

	for (int i = 0; i <= 42; i++)
		vector.push_back(i);
	
	try {
		std::vector<int>::iterator it_vector = easyfind(vector, 39);
		std::cout << "Vector start counting...39" << std::endl;

		for_each(it_vector, vector.end(), print);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// LIST
	std::list<int> list;

	for (int i = 0; i <= 42; i++)
		list.push_back(i);
	
	try {
		std::list<int>::iterator it_list = easyfind(list, 39);
		std::cout << "List start counting...39" << std::endl;
		for_each(it_list, list.end(), print);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}