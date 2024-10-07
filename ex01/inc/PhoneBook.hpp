#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>

# define MAX_CONTACTS 8
# define TABLE_CELL_WIDTH 10
# define SET_COLOR2BLUE std::cout << "\033[34m"
# define RESET_COLOR std::cout << "\033[0m"


class	PhoneBook {

private:
	Contact	mContacts[MAX_CONTACTS];
	size_t	mContactsIdx = 0;
	size_t	mNumContacts = 0;

public:
	PhoneBook();
	~PhoneBook();

	void	add();
	void	search();
	void	exit();

	void	printPhoneBook();
};

#endif
