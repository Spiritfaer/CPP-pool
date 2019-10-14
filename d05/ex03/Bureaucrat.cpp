#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/*******************************************************/
/***         Constructor and Destructor              ***/
/*******************************************************/

Bureaucrat::Bureaucrat() : _name("Puppet"), _grade(150) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other) {
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::~Bureaucrat() {}

/*******************************************************/
/***               setter and getter                 ***/
/*******************************************************/

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::setGrade(int grade) {
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

/*******************************************************/
/***             Increment and Decrement             ***/
/*******************************************************/

Bureaucrat &Bureaucrat::operator++() {
	if (_grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	if (_grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	Bureaucrat tmp(*this);
	--_grade;
	return tmp;
}

Bureaucrat &Bureaucrat::operator--() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	Bureaucrat tmp(*this);
	++_grade;
	return tmp;
}

/*******************************************************/
/***                   iostream                      ***/
/*******************************************************/

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

/*******************************************************/
/***             GradeTooHighException               ***/
/*******************************************************/

Bureaucrat::GradeTooHighException::GradeTooHighException() : exception() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &) : exception() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade too high;";
}

/*******************************************************/
/***             GradeTooLowException                ***/
/*******************************************************/

Bureaucrat::GradeTooLowException::GradeTooLowException() : exception() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &) : exception() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade too low;";
}

/*******************************************************/
/***         signForm() and executeForm()            ***/
/*******************************************************/

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout
			<< getName()
			<< " signs "
			<< form.getName()
			<< std::endl;
	} catch (std::exception &ex) {
		std::cout
			<< getName()
			<< " cannot sign "
			<< form.getName()
			<< " because "
			<< ex.what()
			<< std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form) {
	try {
		form.execute(*this);
		std::cout
			<< getName()
			<< " executes "
			<< form.getName()
			<< std::endl;
	} catch(std::exception &ex) {
		std::cout
			<< getName()
			<< " cannot sign "
			<< form.getName()
			<< " because "
			<< ex.what()
			<< std::endl;
	}
}
