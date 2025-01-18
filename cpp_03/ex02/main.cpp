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

	sclap.takeDamage(1);
	showScavStats(sclap);
	sclap.attack("TARGET");
	showScavStats(sclap);
	sclap.takeDamage(0);
	showScavStats(sclap);
	sclap.takeDamage(11);
	showScavStats(sclap);
	sclap.beRepaired(42);
	showScavStats(sclap);
	sclap.takeDamage(110);
	showScavStats(sclap);
	sclap.beRepaired(42);
	showScavStats(sclap);
	strap.takeDamage(99);
	showScavStats(strap);

	strap.guardGate();
	sclap.guardGate();

	std::cout << std::endl << "***** TESTS FOR FRAGTRAP *****" << std::endl;

	FragTrap fnoname;
	FragTrap fclap("frog");

	showFragStats(fnoname);
	showFragStats(fclap);

	fclap.takeDamage(1);
	showFragStats(fclap);
	fclap.attack("TARGET");
	showFragStats(fclap);
	fclap.takeDamage(0);
	showFragStats(fclap);
	fclap.takeDamage(11);
	showFragStats(fclap);
	fclap.beRepaired(42);
	showFragStats(fclap);
	fclap.takeDamage(110);
	showFragStats(fclap);
	fclap.beRepaired(42);
	showFragStats(fclap);
	fclap.attack("TARGET");
	showFragStats(fclap);
	fnoname.takeDamage(99);
	showFragStats(fnoname);
	fnoname.attack("TARGET");
	showFragStats(fnoname);

	fclap.highFivesGuys();
	fnoname.highFivesGuys();

	std::cout << std::endl << "*** Destructors ***" << std::endl;

	return (0);
}
