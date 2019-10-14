#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &);
	Bureaucrat&operator=(Bureaucrat const&);
	Bureaucrat(std::string const &name, int grade);
	virtual ~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	void setGrade(int grade);

	void signForm(Form &);
	void executeForm(Form const & form);

	Bureaucrat &operator++();
	Bureaucrat operator++(int);
	Bureaucrat &operator--();
	Bureaucrat operator--(int);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &);
		~GradeTooHighException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	private:
		GradeTooHighException &operator=(GradeTooHighException const &);
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const&);
		~GradeTooLowException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	private:
		GradeTooLowException &operator=(GradeTooLowException const &);
	};


private:
	std::string const	_name;
	int					_grade;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
