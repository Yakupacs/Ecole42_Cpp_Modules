#include "Span.hpp"

int main(void) {
	std::vector<int> numbers;

	for (int i = 0; i < 9999999; i += 5)
		numbers.push_back(i);

	Span sp = Span(numbers.size());

	try {
		sp.addRange(numbers.begin(), numbers.end());
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}