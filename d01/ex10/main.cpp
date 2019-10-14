#include <iostream>
#include <fstream>

#define MY_ERROR "* THIS FILE NOT FOUND *"

int		main(int argc, char **argv)
{
	std::fstream fs;
	std::string	buff;

	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			fs.open(argv[i]);
			if (fs.is_open()) {
				while (std::getline(fs, buff)) {
					std::cout <<  buff << std::endl;
				}
			} else {
				std::cout << MY_ERROR << std::endl;
			}
			fs.close();
		}
		return 0;
	}

	while (!std::cin.eof()) {
		std::getline(std::cin, buff);
		std::cout <<  buff << std::endl;
	}
	return 0;
}
