#include <iostream>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	++_nbAccounts;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	++_nbAccounts;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void
Account::_displayTimestamp() {
	char buff[20];
	std::chrono::time_point<std::chrono::system_clock> now;
	now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", std::localtime(&now_c));
	std::cout << buff << " ";
}

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }


void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << ";"
		<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	_totalAmount += deposit;
	++_totalNbDeposits;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "deposits:" << deposit << ";"
		<< "amount:" << (_amount + deposit) << ";"
		<< "nb_deposits:" << ++_nbDeposits << ";"
		<< std::endl;
	_amount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal
		<< ";amount:" << _amount << ";"
		<< "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	++_totalNbWithdrawals;

	return true;
}
int		Account::checkAmount( void ) const {
	static size_t counter = 0;
	return counter++;
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << ";"
		<< std::endl;
}
