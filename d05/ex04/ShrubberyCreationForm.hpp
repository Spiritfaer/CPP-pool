#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	ShrubberyCreationForm(const std::string &name);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;

private:
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

	std::string initTree(void) const;
	void		newFile(Bureaucrat const &executor) const;

};


#endif
