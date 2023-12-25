# ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <vector>
#include <string>
#include <cstdlib> // atoi
#include <cmath>
#include <cfloat>
#include <limits> // std::numeric_limits
#include <stdexcept> // std::runtime_error
#include <algorithm> // std::max_element
#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // stringstream

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_exchangeRateData;
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(const std::string& fileBitcoinExchangeRates);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		int isDateValid(const std::string& date) const;
		float getExchangeRate(const std::string& date, float value) const;
		void printAllDetails(const std::string& date, float value) const;
};

# endif