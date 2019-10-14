#include "Form.hpp"
#include "Bureaucrat.hpp"

/*******************************************************/
/***         Constructor and Destructor              ***/
/*******************************************************/

Form::Form() :
		_name("Test blank"),
		_sign(false),
		_signGrade(100),
		_executeGrade(100) {}
Form::Form(const std::string &name, int signGrade, int executeGrade) :
		_name(name),
		_sign(false),
		_signGrade(signGrade),
		_executeGrade(executeGrade) {
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
}
Form::Form(Form const &other) :
		_name(other._name),
		_sign(other._sign),
		_signGrade(other._signGrade),
		_executeGrade(other._executeGrade) {}
Form::~Form() {}
Form& Form::operator=(Form const &other) {
	_sign = other._sign;
	return *this;
}

/*******************************************************/
/***               setter and getter                 ***/
/*******************************************************/

const std::string &Form::getName() const { return _name; }
bool Form::isSign() const { return _sign; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }


/*******************************************************/
/***             GradeTooHighException               ***/
/*******************************************************/

Form::GradeTooHighException::GradeTooHighException() : exception() {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &) : exception() {}
Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}
const char* Form::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade too high";
}

/*******************************************************/
/***             GradeTooLowException                ***/
/*******************************************************/

Form::GradeTooLowException::GradeTooLowException() : exception() {}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const&) : exception() {}
Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}
const char* Form::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade too low";
}

/*******************************************************/
/***               NoSignedException                 ***/
/*******************************************************/

Form::NoSignedException::NoSignedException() : exception() {}
Form::NoSignedException::NoSignedException(NoSignedException const &) : exception() {}
Form::NoSignedException::~NoSignedException() _NOEXCEPT {}
const char* Form::NoSignedException::what() const _NOEXCEPT {
	return "This form is unsigned!";
}

/*******************************************************/
/***                    FOO()                        ***/
/*******************************************************/

void Form::beSigned(Bureaucrat const &puppet) {
	if (puppet.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	this->_sign = true;
}
