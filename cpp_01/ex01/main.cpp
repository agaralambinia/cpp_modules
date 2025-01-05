#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 100;
	
	horde = zombieHorde(N, "horde");
 	for (int i = 0; i < N; i++)
	{
       std::cout << "Number " << i << ": ";
	   horde[i].announce();
    }

	delete[] horde;
	return (0);
}
