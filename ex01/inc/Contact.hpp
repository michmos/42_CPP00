
#include <string>

class	Contact {

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNum;
	std::string	secret;

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

	void	printContact();
	
};
