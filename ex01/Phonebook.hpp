
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class Contact;

class Phonebook {

public:
    
    Phonebook(void);
    ~Phonebook(void);

    Contact contacts[8];
    int     index;
  
    void add(void);
    void search(void);

private:
    void printTrunc(std::string);
    int getIndex(std::string);
    bool checkAdd(std::string, std::string, std::string, std::string, std::string);
};

#endif