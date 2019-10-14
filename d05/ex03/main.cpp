#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat Asterix("Asterix", 2);

	try	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Asterix.signForm(*rrf);
		Asterix.executeForm(*rrf);
		delete rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Asterix.signForm(*rrf);
		Asterix.executeForm(*rrf);
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		Asterix.signForm(*rrf);
		Asterix.executeForm(*rrf);
		delete rrf;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
