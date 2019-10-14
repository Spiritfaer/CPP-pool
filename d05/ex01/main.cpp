#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "**   BUREAUCRAT TESTING   **" << std::endl;
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

	std::cout << "\n**   FORM TESTING   **" << std::endl;

	try {
		std::cout << "\nTest created form with 150 grade" << std::endl;
		Form b12("B12-65Y/12", 151, 151);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << "\nTest created form with 0 grade" << std::endl;
		Form b12("B12-65Y/12", 0, 0);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << "\nTest sign TRUE" << std::endl;

		Bureaucrat cezar("Cezar", 100);
		Form b12("B12-65Y/12", 100, 100);
		std::cout << "Status b12 - "<< (b12.getSign() ? "true" : "false") << std::endl;
		cezar.signForm(b12);
		std::cout << "Status b12 - "<< (b12.getSign() ? "true" : "false") << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try {
		std::cout << "\nTest sign FALSE" << std::endl;

		Bureaucrat cezar("Cezar", 120);
		Form b12("B12-65Y/12", 100, 100);
		std::cout << "Status b12 - "<< (b12.getSign() ? "true" : "false") << std::endl;
		cezar.signForm(b12);
		std::cout << "Status b12 - "<< (b12.getSign() ? "true" : "false") << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
