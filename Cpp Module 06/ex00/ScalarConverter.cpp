#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor called." << std::endl;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called." << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	std::cout << "ScalarConverter assignment operator called." << std::endl;
	return (*this);
}
void nothingType() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
void toInt(std::string str) {
	std::stringstream stream(str);

	int value = static_cast<int>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
void toFloat(std::string str) {
	std::stringstream stream(str);
	float value = static_cast<float>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double d = static_cast<double>(value);

	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
void toDouble(std::string str) {
	std::stringstream stream(str);
	double value = static_cast<double>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);

	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
void toChar(std::string str) {
	int n = 0;
	double d = static_cast<double>(str[n]);
	int i = static_cast<int>(str[n]);
	float f = static_cast<float>(str[n]);
	if (str[n] >= 32 && str[n] <= 127) {
		std::cout << "char: " << "'" << str << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} else {
		std::cout << "This character aren't printable" << std::endl;
	}
}
void checkType(const std::string& str){
	char type = 'i', flag = 0;
	std::strtod(str.c_str(), NULL);
	if (!std::isdigit(str.c_str()[0]) && str.length() == 1){
		toChar(str);
		return;
	}
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (;str[i];i++){
		if ((i == (str.length() - 1)) && str[i] == 'f'){
			if (type != 'x') {
				toFloat(str);
				return;
			}
			return nothingType();
		}
		else if (str[i] == '.' && flag == 0){
			type = 'd';
			flag = 1;
		}
		else if (!std::isdigit(str[i]))
			type = 'x';
	}
	switch (type)
	{
	case 'x':
		nothingType();
		break;
	case 'd':
		toDouble(str);
		break;
	case 'i':
		toInt(str);
		break;
	default:
		break;
	}
	return;
}
void specialCase(const std::string str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nanf") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inff") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inff") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}
void ScalarConverter::convert(const std::string &str) {
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		specialCase(str);
	else
		checkType(str);
}