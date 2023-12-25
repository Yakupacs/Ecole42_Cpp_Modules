#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Error: could not open file." << std::endl;
	else {
		try {
			BitcoinExchange btc(argv[1]);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}