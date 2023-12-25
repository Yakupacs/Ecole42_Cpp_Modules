#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <inverted Polish expression>" << std::endl;
		return 1;
	}
	int result;
	try {
		RPN calculator;
		result = calculator.parseExpression(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}