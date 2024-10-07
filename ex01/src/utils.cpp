
#include "../inc/PhoneBook.hpp"

std::string	getInput(const std::string prompt, const std::string errMsg)
{
	std::string	input;
	
	while(true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\033[31m" << errMsg << "\033[0m" << std::endl;
		} else {
			return (input);
		}
	}
}
