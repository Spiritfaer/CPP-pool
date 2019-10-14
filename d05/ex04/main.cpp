#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 55);

	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("robotomy request", "Pigley");
	}
	catch (OfficeBlock::InternIsAbsentException &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (OfficeBlock::SignerIsAbsentException &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (OfficeBlock::ExecutorIsAbsentException &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (OfficeBlock::UnknownBlankException &ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
