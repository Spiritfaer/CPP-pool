#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class Form;

class Intern {
public:
	Intern();
	~Intern();

	Form *makeForm(std::string const &, std::string const &);

private:
	Intern(Intern const&);
	Intern &operator=(Intern const &);
	void error(std::string const &) const;
	void success(std::string const &form) const;
};


#endif
