#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str) {
	std::string::size_type first = str.find_first_not_of(" \t");
	std::string::size_type last = str.find_last_not_of(" \t");

	if (first == std::string::npos || last == std::string::npos)
		return "";

	return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1) return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[2] = 29;

	return day <= daysInMonth[month];
}

std::string BitcoinExchange::findClosestDate(const std::string& inputDate) {
	std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(inputDate);

	if (it != _exchangeRates.end() && it->first == inputDate)
		return inputDate;

	if (it != _exchangeRates.begin())
		--it;

	return it->first;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) {
	char* endptr;

	try {
		value = std::strtod(valueStr.c_str(), &endptr);
	}
	catch(const std::exception& e) {
		std::cout << "Error: could not convert number." << std::endl;
		return false;
	}

	if (*endptr != '\0') {
		std::cout << "Error: could not convert number." << std::endl;
		return false;
	}

	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw BitcoinExchange::OpenInputFileException();
	}

	std::string line;
	std::getline(file, line);
	if (line.compare("date | value") != 0) {
		throw BitcoinExchange::IncorrectInputFileFormat();
	}

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string dateStr, valueStr;

		if (!(std::getline(ss, dateStr, '|') && std::getline(ss, valueStr))) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		dateStr = trim(dateStr);
		valueStr = trim(valueStr);

		if (!isValidDate(dateStr)) {
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value)) {
			continue;
		}

		std::string closestDate = findClosestDate(dateStr);
		double exchangeRate = _exchangeRates[closestDate];
		double result = value * exchangeRate;
		if (result == -0)
			result = 0;

		std::cout << dateStr << " => " << value << " = " << result << std::endl;
	}
}

void BitcoinExchange::loadExchangeRates() {
	const std::string& filename = "data.csv";

	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw BitcoinExchange::NoDataCsvException();
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date, rateStr;

		std::getline(ss, date, ',');
		std::getline(ss, rateStr);

		double rate = std::atof(rateStr.c_str());
		_exchangeRates[date] = rate;
	}
}

void BitcoinExchange::exchange(int argc, char* argv[]) {
	if (argc != 2) {
		throw BitcoinExchange::WrongProgramCall();
	}

	loadExchangeRates();
	processInputFile(argv[1]);
}

const char *BitcoinExchange::WrongProgramCall::what(void) const throw() {
	return ("Exception: wrong btc program call.");
}

const char *BitcoinExchange::NoDataCsvException::what(void) const throw() {
	return ("Exception: could not load exchange rates database.");
}

const char *BitcoinExchange::OpenInputFileException::what(void) const throw() {
	return ("Exception: could not open input file.");
}

const char *BitcoinExchange::IncorrectInputFileFormat::what(void) const throw() {
	return ("Exception: input file must have header 'date | value'");
}
