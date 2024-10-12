
#include "../inc/Contact.hpp"

void	Contact::printContact() const
{
	std::cout << BLUE << "First Name: " << RESET << _firstName << "\n";
	std::cout << BLUE << "Last Name: " << RESET << _lastName << "\n";
	std::cout << BLUE << "Nick Name: " << RESET << _nickName << "\n";
	std::cout << BLUE << "Phone Number: " << RESET << _phoneNum << "\n";
	std::cout << BLUE << "Secret: " << RESET << _secret << "\n";
	std::cout << std::flush;
}

void	Contact::setFirst()
{
	_firstName = getInput("First Name: ");
}

void	Contact::setLast()
{
	_lastName = getInput("Last Name: ");
}

void	Contact::setNick()
{
	_nickName = getInput("Nick Name: ");
}

void	Contact::setNum()
{
	_phoneNum = getInput("Phone Number: ");
}

void	Contact::setSecret()
{
	_secret = getInput("Darkest Secret: ");
}

void	Contact::setAll()
{
	setFirst();
	setLast();
	setNick();
	setNum();
	setSecret();
}

std::string	Contact::getFirst() const
{
	return(_firstName);
}

std::string	Contact::getLast() const
{
	return(_lastName);
}

std::string	Contact::getNick() const
{
	return(_nickName);
}

std::string	Contact::getNum() const
{
	return(_phoneNum);
}

std::string	Contact::getSecret() const
{
	return(_secret);
}

