#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


OfficeBlock::OfficeBlock() : _intern(nullptr), _signer(nullptr), _executor(nullptr) {}
OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) :
	_intern(intern), _signer(signer), _executor(executor) {}
OfficeBlock::~OfficeBlock() {}

void OfficeBlock::setIntern(Intern &ref) {
	_intern = &ref;
}
void OfficeBlock::setSigner(Bureaucrat &ref) {
	_signer = &ref;
}
void OfficeBlock::setExecutor(Bureaucrat &ref) {
	_executor = &ref;
}

void OfficeBlock::doBureaucracy(std::string const &target, std::string const &name) {
	if (!_intern)
		throw OfficeBlock::InternIsAbsentException();
	if (!_signer)
		throw OfficeBlock::SignerIsAbsentException();
	if (!_executor)
		throw OfficeBlock::ExecutorIsAbsentException();

	Form *ptf = _intern->makeForm(target, name);
	if (!ptf)
		throw OfficeBlock::UnknownBlankException();

	_signer->signForm(*ptf);
	_executor->executeForm(*ptf);
	delete ptf;
}

OfficeBlock::InternIsAbsentException::InternIsAbsentException() : exception() {}
OfficeBlock::InternIsAbsentException::InternIsAbsentException(InternIsAbsentException const &) : exception() {}
OfficeBlock::InternIsAbsentException::~InternIsAbsentException() _NOEXCEPT {}
const char* OfficeBlock::InternIsAbsentException::what() const _NOEXCEPT {
	return "You should find at list ONE INTERN!";
}

OfficeBlock::SignerIsAbsentException::SignerIsAbsentException() : exception() {}
OfficeBlock::SignerIsAbsentException::SignerIsAbsentException(SignerIsAbsentException const &) : exception() {}
OfficeBlock::SignerIsAbsentException::~SignerIsAbsentException() _NOEXCEPT {}
const char* OfficeBlock::SignerIsAbsentException::what() const _NOEXCEPT {
	return "Your form is unsigned... Why? Because we haven't signer!";
}

OfficeBlock::ExecutorIsAbsentException::ExecutorIsAbsentException() : exception() {}
OfficeBlock::ExecutorIsAbsentException::ExecutorIsAbsentException(ExecutorIsAbsentException const &) : exception() {}
OfficeBlock::ExecutorIsAbsentException::~ExecutorIsAbsentException() _NOEXCEPT {}
const char* OfficeBlock::ExecutorIsAbsentException::what() const _NOEXCEPT {
	return "Your form can't be executed, why?! We told you before! We haven't executor.";
}

OfficeBlock::UnknownBlankException::UnknownBlankException() : exception() {}
OfficeBlock::UnknownBlankException::UnknownBlankException(UnknownBlankException const &) : exception() {}
OfficeBlock::UnknownBlankException::~UnknownBlankException() _NOEXCEPT {}
const char* OfficeBlock::UnknownBlankException::what() const _NOEXCEPT {
	return "If you want to submit this form, then you need to agree on form 25В/46 in office 84с";
}
