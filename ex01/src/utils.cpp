
#include "../inc/utils.hpp"

std::string	getInput(const std::string &prompt)
{
	std::string	input;
	
	while(true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			// clear error state
			std::cin.clear();
			// clear input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw std::ios_base::failure("\nStd input error");
		} else if (input.empty()) {
			std::cerr << RED << "Input required. Field cannot be empty" << RESET << std::endl;
		} else {
			return (input);
		}
	}
}
