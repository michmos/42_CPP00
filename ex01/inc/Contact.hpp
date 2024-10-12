
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "utils.hpp"

class	Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNum;
	std::string	_secret;

public:
	void	setAll();
	void	setFirst();
	void	setLast();
	void	setNick();
	void	setNum();
	void	setSecret();

	std::string	getFirst() const;
	std::string	getLast() const;
	std::string	getNick() const;
	std::string	getNum() const;
	std::string	getSecret() const;

	void	printContact() const;
};

#endif
