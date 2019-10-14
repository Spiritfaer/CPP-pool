#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <string>

class Intern;
class Bureaucrat;
class Form;

class OfficeBlock {

public:
	OfficeBlock();
	OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);

	~OfficeBlock();

	Intern		*getIntern();
	Bureaucrat	*getSigner();
	Bureaucrat	*getExecutor();

	void setIntern(Intern &);
	void setSigner(Bureaucrat &);
	void setExecutor(Bureaucrat &);

	void doBureaucracy(std::string const &target, std::string const &name);

	class InternIsAbsentException : public std::exception
	{
	public:
		InternIsAbsentException();
		InternIsAbsentException(InternIsAbsentException const &);
		~InternIsAbsentException() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		InternIsAbsentException &operator=(InternIsAbsentException const &);
	};

	class SignerIsAbsentException : public std::exception
	{
	public:
		SignerIsAbsentException();
		SignerIsAbsentException(SignerIsAbsentException const &);
		~SignerIsAbsentException() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		SignerIsAbsentException &operator=(SignerIsAbsentException const &);
	};

	class ExecutorIsAbsentException : public std::exception
	{
	public:
		ExecutorIsAbsentException();
		ExecutorIsAbsentException(ExecutorIsAbsentException const &);
		~ExecutorIsAbsentException() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		ExecutorIsAbsentException &operator=(ExecutorIsAbsentException const &);
	};

	class UnknownBlankException : public std::exception
	{
	public:
		UnknownBlankException();
		UnknownBlankException(Form *ptf);
		UnknownBlankException(UnknownBlankException const &);
		~UnknownBlankException() _NOEXCEPT;
		const char *what() const _NOEXCEPT;
	private:
		UnknownBlankException &operator=(UnknownBlankException const &);
	};



private:
	OfficeBlock(OfficeBlock const &);
	OfficeBlock &operator=(OfficeBlock const &);

	Intern		*_intern;
	Bureaucrat	*_signer;
	Bureaucrat	*_executor;
};


#endif
