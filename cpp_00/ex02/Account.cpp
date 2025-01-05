#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    char timestamp[20];
    std::time_t now;
	
	std::time(&now);
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout
		<< "["
		<< timestamp
		<< "] ";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts+=1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";created"
		<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";closed"
		<< std::endl;
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< "accounts:"
		<< _nbAccounts
		<< ";total:"
		<< getTotalAmount()
		<< ";deposits:"
		<< _totalNbDeposits
		<< ";withdrawals:"
		<< _totalNbWithdrawals
		<< std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";deposit:"
		<< deposit
		<< ";amount:"
		<< _amount + deposit
		<< ";nb_deposits:"
		<< _nbDeposits
		<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout
			<< "index:"
			<< _accountIndex
			<< ";p_amount:"
			<< _amount
			<< ";withdrawal:refused" 
			<< std::endl;
		return (false);
	}
	else
	{
		_displayTimestamp();
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout
			<< "index:"
			<< _accountIndex
			<< ";p_amount:"
			<< _amount
			<< ";withdrawal:"
			<< withdrawal
			<< ";amount:"
			<< _amount - withdrawal
			<< ";nb_withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
}

int Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";deposits:" 
		<< _nbDeposits
		<< ";withdrawals:"
		<< _nbWithdrawals
		<< std::endl;
}
