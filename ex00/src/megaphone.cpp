
#include <iostream>

void	printWordInCap(const std::string& word) {
	size_t	i = 0;

	while (word[i]) {
		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(word[i])));
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for ( int i=1; i < argc; i++ ) {
			printWordInCap(argv[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}
