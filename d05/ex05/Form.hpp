#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include <string>

class Form {
public:
	Form();
	Form(const std::string &name, int signGrade, int executeGrade);
	Form(Form const &);
	Form &operator=(Form const&);
	virtual ~Form();


	void beSigned(Bureaucrat const &);
	virtual void execute(Bureaucrat const & executor) const = 0;

	bool isSign() const;
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const&);
		~GradeTooHighException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	private:
		GradeTooHighException &operator=(GradeTooHighException const &);
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &);
		~GradeTooLowException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	private:
		GradeTooLowException &operator=(GradeTooLowException const&);
	};

	class NoSignedException : public std::exception
	{
	public:
		NoSignedException();
		NoSignedException(NoSignedException const&);
		~NoSignedException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	private:
		NoSignedException &operator=(NoSignedException const &);
	};

private:
	std::string const	_name;
	bool				_sign;
	int const			_signGrade;
	int const			_executeGrade;
};

#endif
