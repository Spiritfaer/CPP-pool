#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

Bureaucrat *getRandomBureaucrat() {
	static size_t cof = 1;
	std::string name[] = { "Arran Mckenzie", "Josiah Estes", "Ronnie Russell",
						"Danny Leonard", "Steven Andrews", "Verity Benson",
						"Maya Hull", "Tobias Peters", "Layton Ruiz", "Ioan Gibbons",
						"Leon Cohen", "Robert Petersen", "Dale Dunlap", "Mitchell Sampson",
						"Allen Carson", "Harry Whitaker", "Oscar Hunter", "Lukas Doyle" };
	Bureaucrat *puppet = new Bureaucrat(
			name[(std::rand() * cof) % 17],
			(std::rand() * cof) % 100 + 1
			);
	++cof;
	return puppet;
}

int main()
{
	std::srand(unsigned(std::time(nullptr)));
	CentralBureaucracy centr;
	for (int i = 0; i < OFFICES; ++i) {
		centr.hireNewBureaucrat(getRandomBureaucrat());
	}
	centr.feed();
	centr.queueUp("Make me beer");
	centr.doBureaucracy();

	return 0;
}
