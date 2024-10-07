
#include "../inc/PhoneBook.hpp"

void	PhoneBook::add(void)
{
	Contact newContact;

	newContact.setAll();
	mContacts[mContactsIdx] = newContact;
	mContactsIdx = (mContactsIdx + 1) % 8;
	if (mNumContacts < MAX_CONTACTS)
	{
		mNumContacts++;
	}
}

PhoneBook::PhoneBook() {
	std::cout << "New Phone Book Created\n\n";
}

PhoneBook::~PhoneBook() {
	std::cout << "Phone book will be destroyed" << std::endl;
}

static void	printSepeartor()
{
	std::cout << "+----------+----------+----------+----------+\n";
}

static void	printCellText(const std::string &str)
{
	if (str.length() > TABLE_CELL_WIDTH)
	{
		std::cout << str.substr(0, TABLE_CELL_WIDTH - 1) << '.';
	}
	else
	{
		std::cout << std::setw(TABLE_CELL_WIDTH) << str;
	}
}

static void	printRow(Contact &contact, size_t idx)
{
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


void	PhoneBook::printPhoneBook()
{
	// print header
	SET_COLOR2BLUE;
	printSepeartor();
	std::cout << "|" << std::setw(10) << "Idx" << '|';
	std::cout << std::setw(10) << "First" << '|';
	std::cout << std::setw(10) << "Last" << '|';
	std::cout << std::setw(10) << "Nick" << "|\n";
	printSepeartor();
	RESET_COLOR;
	// print contacts
	for (int i=0; i < mNumContacts; i++) {
		printRow(mContacts[i], i);
		printSepeartor();
	}
	std::cout << std::flush;
}

void	PhoneBook::search(void)
{
	std::string	inputStr;
	u_int8_t	idx;

	printPhoneBook();
	while (true)
	{
		inputStr = getInput("Enter contact index: ");
		idx = inputStr[0] - '0';
		if (inputStr.length() > 1 || idx < 0 || idx > 9 || idx > mNumContacts - 1)
		{
			std::cout << "\033[31mUnvalid index. Please provide an existing index\033[0m" << std::endl;
		}
		else
		{
			break ;
		}
	}
	mContacts[idx].printContact();
}

void	PhoneBook::exit(void)
{
	::exit(0);
}

