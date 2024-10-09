
#include "../inc/PhoneBook.hpp"
#include <cstddef>

PhoneBook::PhoneBook() {
	std::cout << "New Phone Book Created" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "Phone book will be destroyed" << std::endl;
}

void	PhoneBook::add(void) {
	Contact newContact;

	newContact.setAll();
	mContacts[mContactsIdx] = newContact;
	// update idx
	mContactsIdx = (mContactsIdx + 1) % MAX_CONTACTS;
	if (mNumContacts < MAX_CONTACTS)
	{
		mNumContacts++;
	}
}

static void	printSepeartor() {
	std::cout << "+----------+----------+----------+----------+\n";
}

static void	printCellText(const std::string &str) {
	if (str.length() > TABLE_CELL_WIDTH) {
		std::cout << str.substr(0, TABLE_CELL_WIDTH - 1) << '.';
	} else {
		std::cout << std::setw(TABLE_CELL_WIDTH) << str;
	}
}

static void	printRow(const Contact &contact, size_t idx) {
	std::cout << "|";
	std::cout << std::setw(TABLE_CELL_WIDTH) << idx;
	std::cout << "|";
	printCellText(contact.getFirst());
	std::cout << "|";
	printCellText(contact.getLast());
	std::cout << "|";
	printCellText(contact.getNick());
	std::cout << "|\n";
}


void	PhoneBook::printPhoneBook() const {
	// print header
	std::cout << BLUE << BOLD;
	printSepeartor();
	std::cout << "|" << std::setw(TABLE_CELL_WIDTH) << "Idx" << '|';
	std::cout << std::setw(TABLE_CELL_WIDTH) << "First" << '|';
	std::cout << std::setw(TABLE_CELL_WIDTH) << "Last" << '|';
	std::cout << std::setw(TABLE_CELL_WIDTH) << "Nick" << "|\n";
	printSepeartor();
	std::cout << RESET;
	// print contacts
	for (size_t i=0; i < mNumContacts; i++) {
		printRow(mContacts[i], i);
		printSepeartor();
	}
	std::cout << std::flush;
}

void	PhoneBook::search(void) const {
	std::string	userInput;
	u_int8_t	idx;

	if (mNumContacts == 0) {
		std::cerr << RED << "No contacts added so far. Please add a contact before using SEARCH" << RESET << std::endl;
		return ;
	}
	printPhoneBook();
	while (true)
	{
		userInput = getInput("Enter contact index or q to go back: ");
		if (userInput == "q") {
			return ;
		}
		idx = std::stoi(userInput);
		if (userInput.length() > 1 || idx < 0 || idx > mNumContacts - 1) {
			std::cerr << RED << "Invalid index. Please provide an index between 0 and " << mNumContacts - 1 << RESET << std::endl;
		} else {
			break ;
		}
	}
	std::cout << "\n";
	mContacts[idx].printContact();
}

