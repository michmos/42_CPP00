
#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << BLUE << "New phone book created. Use one of the following cmds ADD SEARCH EXIT" << RESET << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "Phone book will be destroyed" << std::endl;
}

void	PhoneBook::add(void) {
	Contact newContact;

	newContact.setAll();
	_Contacts[_ContactsIdx] = newContact;
	_ContactsIdx = (_ContactsIdx + 1) % MAX_CONTACTS;
	if (_NumContacts < MAX_CONTACTS)
	{
		_NumContacts++;
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
	for (size_t i=0; i < _NumContacts; i++) {
		printRow(_Contacts[i], i);
		printSepeartor();
	}
	std::cout << std::flush;
}

static int	getContactIdx(int numContacts)
{
	bool		bad_input;
	std::string	userInput;
	u_int8_t	idx;

	while (true)
	{
		bad_input = false;
		userInput = getInput("Enter contact index or q to go back: ");
		if (userInput == "q") {
			return (-1);
		}

		try {
			idx = std::stoi(userInput);
			if (userInput.length() > 1 || idx > numContacts - 1) {
				bad_input = true;
			}
		} catch (...) {
			bad_input = true;
		}

		if (bad_input) {
			std::cerr << RED << "Invalid index. Please provide an index between 0 and " << numContacts - 1 << RESET << std::endl;
		} else {
			return (idx);
		}
	}

}

void	PhoneBook::search(void) const {
	int	idx;

	if (_NumContacts == 0) {
		std::cerr << RED << "No contacts added so far. Please add a contact before using SEARCH" << RESET << std::endl;
		return ;
	}
	printPhoneBook();
	idx = getContactIdx(_NumContacts);
	// search can be quit with q, resulting in -1
	if (idx == -1)
		return ;
	std::cout << "\n";
	_Contacts[idx].printContact();
}

