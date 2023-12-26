#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <vector>
# include <string>
# include <cstdlib>
# include <cmath>
# include <cfloat>
# include <limits>
# include <stdexcept>
# include <algorithm>
# include <iostream>
# include <fstream>
# include <sstream>

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

#endif