#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>

class BitcoinExchange {
	private:
		unsigned int rate;
		std::string fileName;
		std::vector<std::string> lineVector;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		void getDataLines(std::ifstream &file);
		void getInputLines(std::ifstream &file);
		bool checkFile();
		void checkDateValue();
		void start();
		class TheFileEmpty: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Error: the file is empty!";
				}
		};
		class CouldNotOpen: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Error: could not open file.";
				}
		};
		class BadFormat: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Error: the file is not formatted properly.";
				}
		};
};

#endif