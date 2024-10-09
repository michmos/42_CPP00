#include "../inc/PhoneBook.hpp"
#include <cstdlib>
#include <ios>

int	main() {
	std::string	inputStr;
	PhoneBook	newBook;

	while (true) {
		std::cout << std::endl;
		try {
			inputStr = getInput("> ");
			if (inputStr == "ADD") {
				newBook.add();
			} else if (inputStr == "SEARCH") {
				newBook.search();
			} else if (inputStr == "EXIT") {
				return 0;
			} else {
				std::cerr << RED << "Invalid input. Expected one of the following: ADD SEARCH EXIT" << RESET << std::endl;
			}
		} catch(std::ios_base::failure& e) {
			std::cerr << RED << e.what() << RESET << std::endl;
			return (EXIT_FAILURE);
		}
	}
	return 0;
}
