#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string fileName) {
	this->fileName = fileName;
	start();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	this->rate = copy.rate;
	this->lineVector = copy.lineVector;
	return (*this);
}

void BitcoinExchange::getDataLines(std::ifstream &file) {
	std::string line;
	while (std::getline(file, line)) {
		this->lineVector.push_back(line);
	}
}

void BitcoinExchange::getInputLines(std::ifstream &file) {
	std::string line;
	while (std::getline(file, line)) {
		this->lineVector.push_back(line);
	}
}

bool BitcoinExchange::checkFile() {
	std::ifstream fileData(fileName);
	std::ifstream fileInput(fileName);

	if (!fileData.is_open()) {
		return false;
	}
	if (!fileInput.is_open()) {
		return false;
	}
	getDataLines(fileData);
	getInputLines(fileInput);
	fileData.close();
	fileInput.close();
	return true;
}

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

bool isDigit(char c) {
    return std::isdigit(c);
}

std::string trim(const std::string& str) {
    size_t start = 0;
    size_t end = str.length();

    while (start < end && std::isspace(str[start])) {
        ++start;
    }
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    return str.substr(start, end - start);
}

void BitcoinExchange::checkDateValue() {
	for (int i = 0; i < lineVector.size(); i++) {
		std::vector<std::string> elements = split(lineVector[i], ',');
		if (i == 0) {
			if ((elements.size() == 2)) {
				if (trim(elements[0]) == "date" && (trim(elements[1]) == "exchange_rate" || trim(elements[1]) == "value")) {
					std::cout << "Başarılı!";
				} else {
					throw BadFormat();
				}
			} else {
				throw BadFormat();
			}
		}
	}
}

void BitcoinExchange::start() {
	if (checkFile() == true) {
		if (lineVector.size() != 0)
			checkDateValue();
		else
			throw TheFileEmpty();
	} else
		throw CouldNotOpen();
}