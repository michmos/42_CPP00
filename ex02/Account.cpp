
#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

static void	putIdxAmntMsg(int idx, int amount, std::string msg)
{
	std::cout << "index:" << idx << ";";
	std::cout << "amount:" << amount << ";";
	std::cout << msg << std::endl;
}

Account::Account(int inititial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = inititial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;

	// log message
	_displayTimestamp();
	putIdxAmntMsg(_accountIndex, _amount, "created");
}

Account::~Account() {
	// log message
	_displayTimestamp();
	putIdxAmntMsg(_accountIndex, _amount, "closed");
}

int	Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return(Account::_totalAmount);
}

int	Account::getNbDeposits() {
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return(Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;

	Account::_totalAmount += deposit;
	_amount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;

	// log message
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";

	if (_amount < withdrawal) {
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	Account::_totalAmount -= withdrawal;
	_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	_nbWithdrawals++;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int	Account::checkAmount () const {
	return(_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	std::tm *localtime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localtime);
	std::cout << buffer << " ";
}

