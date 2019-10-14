#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {

		std::cout << "**   TEST PresidentialPardonForm   **" << std::endl;

		Bureaucrat Asterix("Asterix", 100);
		PresidentialPardonForm ppForm("TR-Q758/1b");
		RobotomyRequestForm rrForm("RR-3PO");
		ShrubberyCreationForm scForm("TAB-57-24/f");

		std::cout << Asterix << std::endl;
		Asterix.signForm(ppForm);
		Asterix.executeForm(ppForm);
		Asterix.setGrade(5);
		std::cout << Asterix << std::endl;
		Asterix.signForm(ppForm);
		Asterix.executeForm(ppForm);

		std::cout << "\n**   TEST RobotomyRequestForm   **" << std::endl;
		Asterix.setGrade(100);
		std::cout << Asterix << std::endl;
		Asterix.signForm(rrForm);
		Asterix.setGrade(5);
		std::cout << Asterix << std::endl;
		Asterix.executeForm(rrForm);
		Asterix.signForm(rrForm);
		Asterix.executeForm(rrForm);
		Asterix.executeForm(rrForm);
		Asterix.executeForm(rrForm);
		Asterix.executeForm(rrForm);
		Asterix.executeForm(rrForm);

		std::cout << "\n**   TEST ShrubberyCreationForm   **" << std::endl;
		Asterix.setGrade(149);
		std::cout << Asterix << std::endl;
		Asterix.signForm(scForm);
		Asterix.executeForm(scForm);
		Asterix.setGrade(100);
		std::cout << Asterix << std::endl;
		Asterix.signForm(scForm);
		Asterix.executeForm(scForm);
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
