#include "Array.hpp"

int main(void) {
	Array<int> arrayInt(3);
	Array<int> arrayIntEmpty;
	Array<std::string> arrayString(4);

	arrayInt[0] = 32;
	arrayInt[1] = 33;
	arrayInt[2] = 34;

	arrayString[0] = "Yakup";
	arrayString[1] = "Acis";
	arrayString[2] = "Hello";
	arrayString[3] = "World";

	arrayIntEmpty = arrayInt;

	for (int i = 0; i < arrayIntEmpty.size(); i++) {
		std::cout << i << ".index: " << arrayIntEmpty[i] << std::endl;
	}
	for (int i = 0; i < arrayString.size(); i++) {
		std::cout << i << ".index: " << arrayString[i] << std::endl;
	}

	try {
		arrayInt[2] = 41;
		std::cout << "41 added!" << std::endl;

		arrayInt[3] = 42;
		std::cout << "42 added!" << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}