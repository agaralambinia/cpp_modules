#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	// std::cout << "TESTS FOR CREATING INSTANCES OF ScalarConverter" << std::endl;
	// std::cout << "All of them shall not compile." << std::endl;
	// ScalarConverter a;
	// const ScalarConverter* j = new ScalarConverter();

	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << "Wrong input. Shall be precisely 1 argument." << std::endl;
		return (1);
	}
	return (0);
/*
	TESTS argc:
		- input: ./convert
		- output: Wrong input. Shall be precisely 1 argument.

		- input: ./convert dd dd
		- output: Wrong input. Shall be precisely 1 argument.

	TESTS "special characters":
		- input: +inf
		- input: +inff
		- input: -inf
		- input: -inff
		- input: nan
		- input: nanf

	TESTS "int":
		* 42
		* -42
		* 0
		* 2147483647
		* -2147483648
		* 2147483648
		* -2147483649

	TESTS "float":
		* 42.1f
		* -42.1f
		* 0.1f

	TESTS "char":
		* f
		* ff
		* ffffff
		* ff ff
*/
}
