
#include "../inc/utils.hpp"

std::string	getInput(const std::string prompt)
{
	std::string	input;
	
	while(true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cerr << RED << "Input required. Field cannot be empty" << RESET << std::endl;
		} else {
			return (input);
		}
	}
}
