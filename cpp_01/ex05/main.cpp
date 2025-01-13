#include "Harl.hpp"

int main (void)
{
	Harl harl;

	std::cout << ">> Testing comment: Test of DEBUG Level" << std::endl;
	harl.complain("DEBUG");
	std::cout << ">> Testing comment: Test of INFO Level" << std::endl;
	harl.complain("INFO");
	std::cout << ">> Testing comment: Test of WARNING Level" << std::endl;
	harl.complain("WARNING");
	std::cout << ">> Testing comment: Test of ERROR Level" << std::endl;
	harl.complain("ERROR");
	std::cout << ">> Testing comment: Test of some unreal Level" << std::endl;
	harl.complain("AAAAAAAAAAA");
	return (0);
}
