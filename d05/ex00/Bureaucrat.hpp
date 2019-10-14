#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
#include <ostream>

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

	Bureaucrat &operator++();
	Bureaucrat operator++(int);
	Bureaucrat &operator--();
	Bureaucrat operator--(int);

	class GradeTooHighException : public std::exception
	{
	private:
		GradeTooHighException &operator=(GradeTooHighException const &);
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &);
		~GradeTooHighException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception
	{
	private:
		GradeTooLowException &operator=(GradeTooLowException const &);
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const&);
		~GradeTooLowException() _NOEXCEPT;
		const char* what() const _NOEXCEPT;
	};


private:
	std::string const	_name;
	int					_grade;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
