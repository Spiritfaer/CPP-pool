#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Pardon", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string const &other) : Form(other, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->isSign())
		throw Form::NoSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw  Form::GradeTooLowException();
	std::cout
		<< "Tells us "
	 	<< executor.getName()
	 	<< " has been pardoned by Zaphod Beeblebrox."
	 	<< std::endl;
}
