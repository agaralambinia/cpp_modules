#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombie1;
	Zombie *Zombie2;
	
	Zombie1 = newZombie("Zombie1");
	Zombie1->announce();
	randomChump("Zombie2");
	randomChump("Zombie3");
	randomChump("Zombie4");
	randomChump("Zombie5");
	randomChump("Zombie2");
	randomChump("Zombie2");
	randomChump("");
	Zombie2 = newZombie("Zombie22");
	Zombie2->announce();
	delete Zombie1;
	delete Zombie2;
	return (0);
}
