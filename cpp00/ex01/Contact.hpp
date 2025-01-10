#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {

public:
    Contact(void);
    Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
    ~Contact(void);

    bool isExist(void);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getPhoneNumber(void);

private:
    bool exist;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

#endif
