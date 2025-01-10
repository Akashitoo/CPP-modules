#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>

int main()
{
    Phonebook repertoire;
    std::string user_input;

    while(true)
    {
        std::cout << "Entrez une commande parmi ADD | SEARCH | EXIT :\n";
        std::getline(std::cin, user_input);
        if (!user_input.compare("EXIT") || std::cin.eof())
            break;
        else if (!user_input.compare("SEARCH"))
            repertoire.search();
        else if (!user_input.compare("ADD"))
            repertoire.add();
        else
            std::cout << "Commande non reconnu !\n";
    }
    return 0;
}
