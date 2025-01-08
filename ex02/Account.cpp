#include <ctime>
#include "Account.hpp"

Account::Account(int initial_deposit): _amount(initial_deposit){
    return;
};

Account::~Account(void){
    return;
};

void Account::displayAccountsInfos(void)
{
    this->_displayTimestamp();
    this->getNbAccounts();
    this->getTotalAmount();
    this->getNbDeposits();
    this->getNBWithdrawals();
};