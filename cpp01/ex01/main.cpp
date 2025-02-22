
#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	Zombie *newZomb;

	newZomb = newZombie("zbi");
	newZomb->announce();
	randomChump("randomChump");
	delete newZomb;
}