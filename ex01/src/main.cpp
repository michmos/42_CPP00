#include "../inc/PhoneBook.hpp"

// TODO: handle search without contacts

int	main(int argc, char *argv[]) {
	std::string	inputStr;
	PhoneBook	newBook;

	while (true) {
		std::cout << std::endl;
		inputStr = getInput("> ");
		if (inputStr == "ADD") {
			newBook.add();
		} else if (inputStr == "SEARCH") {
			newBook.search();
		} else if (inputStr == "EXIT") {
			newBook.exit();
		} else {
			std::cerr << RED << "Invalid input. Expected one of the following: ADD SEARCH EXIT" << RESET << std::endl;
		}
	}
	return 0;
}
