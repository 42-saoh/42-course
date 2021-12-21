#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;

int	Account::getNbAccounts(void)
{

    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
    return (_amount);
}

void Account::_displayTimestamp(void)
{
    time_t time_now;
    struct tm *tm;

    time(&time_now);
    tm = localtime(&time_now);
    std::cout << "[" << tm->tm_year+1900 << tm->tm_mon+1 \
    << tm->tm_mday << "_" << tm->tm_hour << tm->tm_min \
    << tm->tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" \
    << _amount << ";created" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" \
    << getTotalAmount() << ";deposits:" << getNbDeposits() \
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" \
    << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" \
    << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    int p_amount = checkAmount();
    _amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" \
    << p_amount << ";deposit:" << deposit << ";amount:" \
    << _amount << ";nb_deposits:" << ++_nbDeposits << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    int p_amount = checkAmount();
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" \
    << p_amount;
    if (p_amount >= withdrawal)
    {
        _amount -= withdrawal;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" \
        << _amount << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    std::cout << ";withdrawal:refused" << std::endl;
    return (false);
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" \
    << _amount << ";closed" << std::endl;
}