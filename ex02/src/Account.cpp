
#include "../Account.hpp"
#include <iostream>
#include <ctime>



// TODO: I NEED TO PROTECT ALL CLASS HPP FILES AS WELL

static void	putIdxAmntMsg(int idx, int amount, std::string msg)
{
	std::cout << "index:" << idx << ";";
	std::cout << "amount:" << amount << ";";
	std::cout << "created:" << std::endl;
}

Account::Account(int inititial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = inititial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	putIdxAmntMsg(_accountIndex, _amount, "created");
}

Account::~Account() {
	_displayTimestamp();
	putIdxAmntMsg(_accountIndex, _amount, "closed");
}

int	Account::getNbAccounts() {
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return(_totalAmount);
}

int	Account::getNbDeposits() {
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawal:" << getNbWithdrawals() << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;

	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount < withdrawal) {
		return (false);
	}

	int	p_amount = _amount;

	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount () const {
	return(_amount);
}


void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}

void Account::_displayTimestamp() {

	std::time_t now = std::time(nullptr);
	std::tm *localtime = std::localtime(&now);
	char buffer[16];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime);
	std::cout << "[" << buffer << "] ";
}

