#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << std::endl << "***** TESTS FROM EX00 *****" << std::endl;
	std::cout << std::endl << "*** Constructors ***" << std::endl;
	ClapTrap noname;
	ClapTrap clap("Clap");
	ClapTrap clap_two(clap);
	ClapTrap trap;
	trap = clap;


	std::cout << std::endl << "*** Tests for funcs ***" << std::endl;
	std::cout << ">> clap hp " << clap.getHitPoints() << " clap energy " << clap.getEnergyPoints() << std::endl;
	std::cout << ">> clap_two hp " << clap_two.getHitPoints() << " clap_two energy " << clap_two.getEnergyPoints() << std::endl;
	clap.attack("TARGET");
	clap.takeDamage(2);
	std::cout << ">> clap hp " << clap.getHitPoints() << " clap energy " << clap.getEnergyPoints() << std::endl;
	std::cout << ">> clap_two hp " << clap_two.getHitPoints() << " clap_two energy " << clap_two.getEnergyPoints() << std::endl;
	clap_two = clap;
	std::cout << ">> clap_two hp " << clap_two.getHitPoints() << " clap_two energy " << clap_two.getEnergyPoints() << std::endl;
	clap_two.beRepaired(42);
	std::cout << ">> clap_two hp " << clap_two.getHitPoints() << " clap_two energy " << clap_two.getEnergyPoints() << std::endl;
	std::cout << ">> trap hp " << trap.getHitPoints() << " trap energy " << trap.getEnergyPoints() << std::endl;
	trap.takeDamage(100);
	std::cout << ">> trap hp " << trap.getHitPoints() << " trap energy " << trap.getEnergyPoints() << std::endl;
	trap.attack("TARGET");
	trap.takeDamage(42);
	trap.beRepaired(42);

	std::cout << std::endl << "*** Destructors ***" << std::endl;

	return (0);
}
