#include "BitcoinExchange.hpp"

int checkExtension(const std::string& s, const std::string& suffix)
{
	if (s.length() >= suffix.length())
	{
		std::string sSuffix = s.substr(s.length() - suffix.length());
		if (sSuffix.compare(suffix) == 0)
			return (0);
	}
	return (1);
}

int main(int argc, char** argv)
{
	if ((argc != 2) || (checkExtension(argv[1], ".txt")))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange	exchange("data.csv");
	std::string		line;

	std::getline(inputFile, line);

	while (std::getline(inputFile, line))
	{
		std::istringstream	ss_line(line);
		std::string			ss_date;
		float				ss_value;

		if (std::getline(ss_line, ss_date, '|') && (ss_line >> ss_value))
		{
			size_t first = ss_date.find_first_not_of(" \t\n\r\f\v");
			size_t last = ss_date.find_last_not_of(" \t\n\r\f\v");
			ss_date = ss_date.substr(first, (last - first) + 1);

			try
			{
				float exchangeRate = exchange.getExchangeRate(ss_date, ss_value);
				float result = ss_value * exchangeRate;
				std::cout << ss_date << " => " << ss_value << " = " << result << std::endl;
			}
			catch (const std::exception& error)
			{
				std::cerr << error.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	return 0;
}