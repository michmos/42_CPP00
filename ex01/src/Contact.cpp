
#include "../inc/Contact.hpp"

void	Contact::printContact() const
{
	std::cout << BLUE << "First Name: " << RESET << firstName << "\n";
	std::cout << BLUE << "Last Name: " << RESET << lastName << "\n";
	std::cout << BLUE << "Nick Name: " << RESET << nickName << "\n";
	std::cout << BLUE << "Phone Number: " << RESET << phoneNum << "\n";
	std::cout << BLUE << "Secret: " << RESET << secret << "\n";
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

