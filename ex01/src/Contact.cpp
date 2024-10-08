
#include "../inc/Contact.hpp"

void	Contact::printContact()
{
	std::cout << "First Name: " << firstName << "\n";
	std::cout << "Last Name: " << lastName << "\n";
	std::cout << "Nick Name: " << nickName << "\n";
	std::cout << "Phone Number: " << phoneNum << "\n";
	std::cout << "Secret: " << secret << "\n";
	std::cout << std::flush;
}

void	Contact::setFirst()
{
	firstName = getInput("First Name: ");
}

void	Contact::setLast()
{
	lastName = getInput("Last Name: ");
}

void	Contact::setNick()
{
	nickName = getInput("Nick Name: ");
}

void	Contact::setNum()
{
	phoneNum = getInput("Phone Number: ");
}

void	Contact::setSecret()
{
	secret = getInput("Darkest Secret: ");
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
	return(firstName);
}

std::string	Contact::getLast() const
{
	return(lastName);
}

std::string	Contact::getNick() const
{
	return(nickName);
}

std::string	Contact::getNum() const
{
	return(phoneNum);
}

std::string	Contact::getSecret() const
{
	return(secret);
}

