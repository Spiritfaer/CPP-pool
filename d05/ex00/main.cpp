#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

	try {
		Bureaucrat Gena("Gena", 100);
		std::cout << "\nTest increment and decrement Bureaucrat" << std::endl;
		std::cout << Gena << std::endl;
		Gena++;
		std::cout << Gena << std::endl;
		Gena.setGrade(44);
		std::cout << Gena << std::endl;
		Gena--;
		std::cout << Gena << std::endl;
		std::cout << "\nTest set to 0 grade Bureaucrat" << std::endl;
		Gena.setGrade(0);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << "\nTry to create Bureaucrat with 151 grade" << std::endl;
		Bureaucrat Dima("Dima", 151);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << "\nTest increment above 1 grade" << std::endl;
		Bureaucrat Igor("Igor", 1);
		std::cout << Igor << std::endl;
		Igor++;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}


	try {
		std::cout << "\nTest decrement above 150 grade" << std::endl;
		Bureaucrat Asterix("Asterix", 150);
		std::cout << Asterix << std::endl;
		Asterix--;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
