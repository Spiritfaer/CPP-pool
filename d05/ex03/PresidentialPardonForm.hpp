#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm(std::string const &);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
private:
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);
};

#endif
