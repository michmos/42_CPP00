
#include <iostream>

void	printWordInCap(const std::string& word) {
	size_t	i = 0;
	char	c;

	while (word[i]) {
		c = std::toupper(static_cast<unsigned char>(word[i]));
		std::cout << c;
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
