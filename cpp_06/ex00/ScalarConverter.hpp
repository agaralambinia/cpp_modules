#ifndef SCALARCONVERTER
# define SCALARCONVERTER

#include <iostream>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(std::string input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		ScalarConverter &operator=(const ScalarConverter &a);
		~ScalarConverter();
};
#endif
