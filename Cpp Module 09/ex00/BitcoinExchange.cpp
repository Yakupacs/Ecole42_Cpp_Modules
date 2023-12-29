#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }
BitcoinExchange::~BitcoinExchange(void) { }
BitcoinExchange::BitcoinExchange(const std::string& fileBitcoinExchangeRates) {
	std::ifstream	dataCsvFile(fileBitcoinExchangeRates.c_str());
	if (!dataCsvFile.good())
		throw std::runtime_error("Error: could not open data.csv file.");
	if (!dataCsvFile.is_open())
		throw std::runtime_error("Error: could not open data.csv file.");
	std::string		dataCsvLine;
	while (std::getline(dataCsvFile, dataCsvLine))
	{
		std::stringstream	ss_line(dataCsvLine);
		std::string			ss_date;
		float				ss_price;

		if (std::getline(ss_line, ss_date, ',') && (ss_line >> ss_price))
			this->_exchangeRateData[ss_date] = ss_price;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_exchangeRateData = other._exchangeRateData;
	return (*this);
}

int isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 != 0)
			return (1);
		else {
			if (year % 400 == 0)
				return (1);
			else
				return (0);
		}
	} else
		return (0);
}

int BitcoinExchange::isDateValid(const std::string& date) const {
	std::vector<std::string>	date_vector;
	std::istringstream			iss_date(date);
	std::string					date_part;
	
	while (std::getline(iss_date, date_part, '-'))
		date_vector.push_back(date_part);

	if (date_vector.size() != 3)
		return (0);

	int	year = std::atoi(date_vector[0].c_str());
	int	month = std::atoi(date_vector[1].c_str());
	int	day = std::atoi(date_vector[2].c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (0);

	if (month == 4 || month == 6 || month == 9 || month == 11) { 
		if (day > 30)
			return (0);
	} else if (month == 2) {
		if ((!isLeapYear(year)) && (day > 28))
			return (0);
		else if ((isLeapYear(year)) && (day > 29))
			return (0);
	}
	return (1);
}

float BitcoinExchange::getExchangeRate(const std::string& date, float value) const {
	if (value < -FLT_MAX || value > FLT_MAX || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		throw std::runtime_error("Error: too large a number.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (!isDateValid(date))
		throw std::runtime_error("Error: bad input.");

	std::map<std::string, float>::const_iterator it = _exchangeRateData.find(date);

	if (it != _exchangeRateData.end()) {
		float exchangeRate = it->second;
		return (exchangeRate);
	}

	std::map<std::string, float>::const_iterator lower = _exchangeRateData.begin();
	std::map<std::string, float>::const_iterator iter;
	
	for (iter = _exchangeRateData.begin(); iter != _exchangeRateData.end(); ++iter)
		if ((iter->first < date) && (iter->first > lower->first))
			lower = iter;

	if (lower != _exchangeRateData.end()) {
		float exchangeRate = lower->second;
		return (exchangeRate);
	} else
		throw std::runtime_error("Error: nonexistent date.");
}

void BitcoinExchange::printAllDetails(const std::string& date, float value) const {
	try {
		float exchangeRate = this->getExchangeRate(date, value);
		float result = value * exchangeRate;

		std::cout << "Date: " << date << std::endl;
		std::cout << "Bitcoin Value: " << value << std::endl;
		std::cout << "Exchange Rate: " << exchangeRate << std::endl;
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}