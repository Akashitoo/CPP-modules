#include <ctime>
#include "Account.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit){
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount <<";created\n";
    return;
};

Account::~Account(void){
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount <<";closed\n";
    return;
};


void Account::_displayTimestamp(void)
{
    char buffer[18];
    std::time_t timestamp = time(NULL);
    struct std::tm * timeinfo;

    timeinfo = localtime(&timestamp);
    std::strftime(buffer,18,"[%G%m%d_%H%M%S]", timeinfo);
    std::cout << buffer;
}

int Account::getNbAccounts(void)
{
    return(_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account ::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:"<< getNbAccounts() <<";total:"<< getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
};

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (withdrawal > _amount){
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
        return (false);
    }
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    return (true);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:"<< _accountIndex <<";amount:"<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}