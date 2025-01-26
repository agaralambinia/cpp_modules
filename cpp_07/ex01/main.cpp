#include "iter.hpp"

#define BLUE	"\033[34;1m"
#define GREEN 	"\033[32m"
#define RESET	"\033[0m"

int main()
{
	std::cout << BLUE"Test int array"RESET << std::endl;
	const int intA[] = {0, 4, 8};
	iter(intA, 3, printValue<const int>);

	std::cout << std::endl << BLUE"Test string array"RESET << std::endl;
	std::string strA[] = {"Meow", "Meow", "Gav", "Gav"};
	iter(strA, 4, printValue<const std::string>);

	std::cout << std::endl << BLUE"Test bool array"RESET << std::endl;
	bool boolA[] = {true, false, false, false};
	iter(boolA, 4, printValue<const bool>);

	std::cout << std::endl;
	return 0;
}
