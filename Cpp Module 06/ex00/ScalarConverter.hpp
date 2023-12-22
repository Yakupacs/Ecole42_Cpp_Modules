#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

class ScalarConverter {
	private:

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		static void convert(const std::string &str);
};

#endif