#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"

# define MAX_CONTACTS 8
# define TABLE_CELL_WIDTH 10


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
