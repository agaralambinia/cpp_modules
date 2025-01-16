#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void showClapStats(ClapTrap &clap)
{
	std::cout << ">> Stats of ClapTrap " << clap.getName() << " hp: " << clap.getHitPoints() << " energy: " << clap.getEnergyPoints() << std::endl;
}

void showScavStats(ScavTrap &clap)
{
	std::cout << ">> Stats of ScavTrap " << clap.getName() << " hp: " << clap.getHitPoints() << " energy: " << clap.getEnergyPoints() << std::endl;
}

void showFragStats(FragTrap &clap)
{
	std::cout << ">> Stats of FragTrap " << clap.getName() << " hp: " << clap.getHitPoints() << " energy: " << clap.getEnergyPoints() << std::endl;
}

int main(void)
{
	std::cout << std::endl << "***** TESTS FOR CLAPTRAP *****" << std::endl;

	std::cout << std::endl << "*** Constructors ***" << std::endl;

	ClapTrap noname;
	ClapTrap clap("Clap");
	ClapTrap clap_two(clap);
	ClapTrap trap;
	trap = clap_two;

	std::cout << std::endl << "*** Tests for funcs ***" << std::endl;

	showClapStats(clap);
	showClapStats(clap_two);
	showClapStats(noname);
	clap.attack("TARGET");
	clap.takeDamage(2);
	showClapStats(clap);
	clap_two = clap;
	showClapStats(clap_two);
	clap_two.beRepaired(42);
	showClapStats(clap_two);
	showClapStats(trap);
	trap.takeDamage(100);
	showClapStats(trap);
	trap.attack("TARGET");
	trap.takeDamage(42);
	trap.beRepaired(42);
	showClapStats(trap);

	std::cout << std::endl << "***** TESTS FOR SCAVTRAP *****" << std::endl;

	ScavTrap snoname;
	ScavTrap sclap("Scav");
	ScavTrap sclap_two(sclap);
	ScavTrap strap;
	strap = sclap_two;

	showScavStats(snoname);
	showScavStats(sclap);
	showScavStats(sclap_two);
	showScavStats(strap);

	sclap.attack("TARGET");
	showScavStats(sclap);

	showScavStats(strap);

	strap.guardGate();
	sclap.guardGate();

	std::cout << std::endl << "***** TESTS FOR FRAGTRAP *****" << std::endl;

	FragTrap fnoname;
	FragTrap fclap("frog");
	FragTrap fclap_two(fclap);
	FragTrap ftrap;
	ftrap = fclap_two;

	showFragStats(fnoname);
	showFragStats(fclap);
	showFragStats(fclap_two);
	showFragStats(ftrap);

	fclap.attack("TARGET");
	showFragStats(fclap);

	fclap.guardGate();
	ftrap.guardGate();

	fclap.highFivesGuys();
	fnoname.highFivesGuys();
	fclap_two.highFivesGuys();
	ftrap.highFivesGuys();

	std::cout << std::endl << "*** Destructors ***" << std::endl;

	return (0);
}
