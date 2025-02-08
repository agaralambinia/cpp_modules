#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <limits>
#include <cstdlib>
#include <exception>

class BitcoinExchange {
private:
	std::map<std::string, double> _exchangeRates;

	std::string	trim(const std::string& str);
	bool 		isValidDate(const std::string& date);
	bool		isValidValue(const std::string& valueStr, double& value);
	std::string findClosestDate(const std::string& inputDate);
	void 		loadExchangeRates();
	void 		processInputFile(const std::string& filename);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

	void exchange(int argc, char* argv[]);

	class WrongProgramCall : public std::exception {
        public:
            const char* what() const throw();
    };

	class NoDataCsvException : public std::exception {
        public:
            const char* what() const throw();
    };

	class OpenInputFileException : public std::exception {
        public:
            const char* what() const throw();
    };

	class IncorrectInputFileFormat : public std::exception {
        public:
            const char* what() const throw();
    };
};

#endif
