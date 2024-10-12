#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"
# include <iomanip>

# define MAX_CONTACTS 8
# define TABLE_CELL_WIDTH 10


class	PhoneBook {

private:
	Contact	_Contacts[MAX_CONTACTS];
	size_t	_ContactsIdx = 0;
	size_t	_NumContacts = 0;

public:
	PhoneBook();
	~PhoneBook();

	void	add();
	void	search() const;

	void	printPhoneBook() const;
};

#endif
