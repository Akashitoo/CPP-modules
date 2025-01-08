#include <iostream>
#include <string>
#include <cstdlib>
#include "Phonebook.hpp"
#include "Contact.hpp"

bool isFullSpace(std::string str)
{
    for(int i=0; i < (int)str.length(); i++)
    {
        if (str[i] != ' ')
            return (false);
    }
    return (true);
}

Phonebook::Phonebook(void) : contacts(){
    this->index = 0;
    return;
}

Phonebook::~Phonebook(void){
    return;
}

void Phonebook::printTrunc(std::string str){

    if (str.length() < 10){
        std::cout << str;
        for (int i=0; i < 10-(int)str.length(); i++)
        {
            std::cout << " ";
        }
    }
    else {
        for (int i=0; i < 9; i++)
        {
            std::cout << str[i];
        }
        std::cout << ".";
    }
    std::cout << "|";
}

int Phonebook::getIndex(std::string str)
{
    if (str.length() > 1)
        return (-1);
    if (str[0] >= '0' && str[0] <= '7')
        return (str[0] - '0');
    else
        return (-1);
}
bool Phonebook::checkAdd(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret){

        if (firstName == "" || isFullSpace(firstName))
            return (false);
        if (lastName == "" || isFullSpace(lastName))
            return (false);
        if (nickname == "" || isFullSpace(nickname))
            return (false);
        if (phoneNumber == "" || isFullSpace(phoneNumber))
            return (false);
        if (darkestSecret == "" || isFullSpace(darkestSecret))
            return (false);
        return (true);    
}   
void Phonebook::add(void){
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Adding new contact\n\nfirst name :";
    std::getline(std::cin, first_name);
    std::cout << "last name :";
    std::getline(std::cin, last_name);
    std::cout << "nickname :";
    std::getline(std::cin, nickname);
    std::cout << "phone number :";
    std::getline(std::cin, phone_number);
    std::cout << "darkest secret :";
    std::getline(std::cin, darkest_secret);
    if (!this->checkAdd(first_name, last_name, nickname, phone_number, darkest_secret))
    {
        std::cout << "Input incorrect -> can't be empty !\n";
        return;
    }
    Contact newContact(first_name,last_name,nickname,phone_number,darkest_secret);
    this->contacts[this->index%8] = newContact;
    this->index = (this->index + 1) % 8;
}

void Phonebook::search(void){
    
    std::string user_input;
    int index;

    std::cout << "index     |first name|last name |nickname  |\n";
    for (int i=0; i < 8; i++)
    {
        std::cout << i << "         |";
        this->printTrunc(this->contacts[i].getFirstName());
        this->printTrunc(this->contacts[i].getLastName());
        this->printTrunc(this->contacts[i].getNickname());
        std::cout << "\n";
    }
    std::cout << "Entrez l'index du contact a afficher :";
    std::getline(std::cin, user_input);
    index = this->getIndex(user_input);
    if (index != -1){
        if (!this->contacts[index].isExist()){
            std::cout << "Contact inexistant\n";
            return;
        } 
        std::cout << "first name : " << this->contacts[index].getFirstName() << "\n";
        std::cout << "last name : " << this->contacts[index].getLastName() << "\n";
        std::cout << "nickname : " << this->contacts[index].getNickname() << "\n";
        std::cout << "phone number: " << this->contacts[index].getPhoneNumber() << "\n";
    }
    else
    {
        std::cout << "Index incorrect\n";
    }
}