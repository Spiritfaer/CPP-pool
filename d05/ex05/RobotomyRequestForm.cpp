#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robot", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : Form(name, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	std::srand(unsigned(std::time(nullptr)));
	static size_t cof = 1;
	if (!this->isSign())
		throw Form::NoSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException();
	if ((std::rand() % ++cof) % 2)
		std::cout
			<< "* Zzzzz bz... Zzzzz! Bip bip bip * "
			<< executor.getName()
			<< " has been robotomized successfully 50% of the time."
			<< std::endl;
	else {
		std::cout
			<< "* Zzzzz bz... Bzzzzz Zbzbbbb... "
			<< executor.getName()
			<< " has been robotomized a failure."
			<< std::endl;
	}
}
