#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void) : exist(false), firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret(""){
    //std::cout << "Constructor called" << std::endl;
    return;
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) : firstName(fn), lastName(ln), nickname(nn), phoneNumber(pn), darkestSecret(ds){
    //std::cout << "Constructor called" << std::endl;
    this->exist = true;
    return;
}

Contact::~Contact(void)
{
    //std::cout << "Destructor called first name " << std::endl;
    return;
}

bool Contact::isExist(void)
{
    return (this->exist);
}
std::string Contact::getFirstName(void)
{
    return(this->firstName);
}

std::string Contact::getLastName(void)
{
    return(this->lastName);
}

std::string Contact::getNickname(void)
{
    return(this->nickname);
}

std::string Contact::getPhoneNumber(void)
{
    return(this->phoneNumber);
}