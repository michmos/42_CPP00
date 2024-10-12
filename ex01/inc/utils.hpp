
#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
#include <cstddef>
#include <limits>

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define BOLD 		"\033[1m"

std::string	getInput(const std::string &prompt);

#endif
