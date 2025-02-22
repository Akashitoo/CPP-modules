#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void) : _name("")
{
	return;
}
Zombie::Zombie(std::string name) : _name(name){
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is destroyed \n";
	return;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}