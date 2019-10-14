#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Form* Intern::makeForm(std::string const &form, std::string const &name) {
	Form *newForm = nullptr;

	if (form == "robotomy request")
		newForm = new RobotomyRequestForm(name);
	else if (form == "presidential pardon")
		newForm = new PresidentialPardonForm(name);
	else if (form == "shrubbery creation")
		newForm = new ShrubberyCreationForm(name);

	if (newForm)
		success(form);
	else
		error(form);

	return newForm;
}

void Intern::success(std::string const &form) const {
	std::cout << "Inter successfully created "<< form << std::endl;
}

void Intern::error(std::string const &form) const {
	std::cout << "Inter can't create "<< form << std::endl;
}