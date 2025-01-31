#include "iter.hpp"

#define BLUE	"\033[34;1m"
#define GREEN 	"\033[32m"
#define RESET	"\033[0m"

template <typename T>
void printVal(const T& value) {
    std::cout << value << " ";
}

int main()
{
	std::cout << BLUE"Test int array"RESET << std::endl;
	int intA[] = {0, 4, 8};
	iter(intA, 3, printVal);
	std::cout << std::endl;
	iter(intA, 3, printVal<const int>);

	std::cout << std::endl << BLUE"Test const int array"RESET << std::endl;
	const int cIntA[] = {0, 4, 8};
	iter(cIntA, 3, printVal);

	std::cout << std::endl << BLUE"Test string array"RESET << std::endl;
	std::string strA[] = {"Meow", "Meow", "Gav", "Gav"};
	iter(strA, 4, printVal);

	std::cout << std::endl << BLUE"Test bool array"RESET << std::endl;
	bool boolA[] = {true, false, false, false};
	iter(boolA, 4, printVal);

	std::cout << std::endl;
	return 0;
}
