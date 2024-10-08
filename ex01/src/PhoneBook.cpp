
#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "New Phone Book Created\n";
}

PhoneBook::~PhoneBook() {
	std::cout << "Phone book will be destroyed" << std::endl;
}

void	PhoneBook::add(void) {
	Contact newContact;

	newContact.setAll();
	mContacts[mContactsIdx] = newContact;
	mContactsIdx = (mContactsIdx + 1) % 8;
	if (mNumContacts < MAX_CONTACTS)
	{
		mNumContacts++;
	}
}

static void	printSepeartor() {
	std::cout << "+----------+----------+----------+----------+\n";
}

static void	printCellText(const std::string &str) {
	if (str.length() > TABLE_CELL_WIDTH)
	{
		std::cout << str.substr(0, TABLE_CELL_WIDTH - 1) << '.';
	}
	else
	{
		std::cout << std::setw(TABLE_CELL_WIDTH) << str;
	}
}

static void	printRow(Contact &contact, size_t idx) {
	std::cout << "|";
	std::cout << std::setw(10) << idx;
	std::cout << "|";
	printCellText(contact.getFirst());
	std::cout << "|";
	printCellText(contact.getLast());
	std::cout << "|";
	printCellText(contact.getNick());
	std::cout << "|\n";
}


void	PhoneBook::printPhoneBook() {
	// print header
	std::cout << BLUE << BOLD;
	printSepeartor();
	std::cout << "|" << std::setw(10) << "Idx" << '|';
	std::cout << std::setw(10) << "First" << '|';
	std::cout << std::setw(10) << "Last" << '|';
	std::cout << std::setw(10) << "Nick" << "|\n";
	printSepeartor();
	std::cout << RESET;
	// print contacts
	for (int i=0; i < mNumContacts; i++) {
		printRow(mContacts[i], i);
		printSepeartor();
	}
	std::cout << std::flush;
}

void	PhoneBook::search(void) {
	std::string	inputStr;
	u_int8_t	idx;

	if (mNumContacts == 0)
	{
		std::cerr << RED << "No contacts added so far. Please add a contact before using SEARCH" << RESET << std::endl;
		return ;
	}
	printPhoneBook();
	while (true)
	{
		inputStr = getInput("Enter contact index: ");
		idx = inputStr[0] - '0';
		if (inputStr.length() > 1 || idx < 0 || idx > 9 || idx > mNumContacts - 1) {
			std::cerr << RED << "Invalid index. Please provide an index between 0 and " << mContactsIdx - 1 << RESET << std::endl;
		} else {
			break ;
		}
	}
	std::cout << "\n";
	mContacts[idx].printContact();
}

void	PhoneBook::exit(void) {
	::exit(0);
}

